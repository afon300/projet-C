#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "column.h"
#include "fonctions.h"

#define INIT_SIZE 255
#define REALLOC_SIZE 255

Column* create_column(DataType type, const char *title) { //permet de créer une colonne
    Column *col = malloc(sizeof(Column));
    col->title = strdup(title);
    col->data = malloc(INIT_SIZE * sizeof(void*));
    col->type = type;
    col->physical_size = INIT_SIZE;
    col->logical_size = 0;
    col->index = 0;

    switch (type) {
        case INT:
            col->print_func = print_int;
            col->compare_func = compare_int;
            break;
        case STRING:
            col->print_func = print_string;
            col->compare_func = compare_string;
            break;
    }
    
    return col;
}

void sort(Column* col, int sort_dir) { //permet de choisir de trier sa colonne avec quicksort ou partition 
    if (col == NULL || col->data == NULL) return;
    
    if (col->index == 0) {
        quicksort(col, 0, col->logical_size - 1, sort_dir);
    } else if (col->index == -1) {
        insertion_sort(col, sort_dir);
    }
}

void quicksort(Column* col, int left, int right, int sort_dir) { // fonction se servant de partition pour trié rapidement une colonne de la dataframe
    if (left < right) {
        int pi = partition(col, left, right, sort_dir);
        quicksort(col, left, pi - 1, sort_dir);
        quicksort(col, pi + 1, right, sort_dir);
    }
}

int partition(Column* col, int left, int right, int sort_dir) { //fonction qui sert dans quicksort
    void* pivot = ((void**)col->data)[right];
    int i = left - 1;
    for (int j = left; j < right; j++) {
        int comparison = col->compare_func(((void**)col->data)[j], pivot);
        if ((sort_dir == ASC && comparison <= 0) || (sort_dir == DESC && comparison >= 0)) {
            i++;
            void* temp = ((void**)col->data)[i];
            ((void**)col->data)[i] = ((void**)col->data)[j];
            ((void**)col->data)[j] = temp;
        }
    }
    void* temp = ((void**)col->data)[i + 1];
    ((void**)col->data)[i + 1] = ((void**)col->data)[right];
    ((void**)col->data)[right] = temp;
    return i + 1;
}

void insertion_sort(Column* col, int sort_dir) { //trie une colonne dans l'ordre croissant ou decroissant
    for (int i = 1; i < col->logical_size; i++) {
        void* key = ((void**)col->data)[i];
        int j = i - 1;
        int comparison = col->compare_func(((void**)col->data)[j], key);
        while (j >= 0 && ((sort_dir == ASC && comparison > 0) || (sort_dir == DESC && comparison < 0))) {
            ((void**)col->data)[j + 1] = ((void**)col->data)[j];
            j--;
            if (j >= 0) {
                comparison = col->compare_func(((void**)col->data)[j], key);
            }
        }
        ((void**)col->data)[j + 1] = key;
    }
}

void print_col_par_ordre(Column* col) { //imprime une colonne
    if (col == NULL || col->data == NULL) {
        printf("NULL\n");
        return;
    }

    printf("Voici la colonne dans l'ordre \n");
    for (int i = 0; i < col->logical_size; ++i) {
        printf("[%d] ", i);
        col->print_func(((void**)col->data)[i]);
    }
}

void init_column(Column *col, const char *title, void (*print_func)(void*), int (*compare_func)(void*, void*)) { //créer une colonne
    col->title = strdup(title);
    col->data = malloc(INIT_SIZE * sizeof(void*));
    col->physical_size = INIT_SIZE;
    col->logical_size = 0;
    col->index = 0;
    col->print_func = print_func;
    col->compare_func = compare_func;
}

int insert_value(Column *col, void* value) { //permet d'insérer une valeur dans la colonne
    if (col == NULL || col->data == NULL) {
        return 0;
    }

    if (col->physical_size == 0 || col->logical_size == col->physical_size) {
        int new_physical_size = col->physical_size + REALLOC_SIZE;
        void** new_data = realloc(col->data, new_physical_size * sizeof(void*));
        if (new_data == NULL) {
            return 0;
        }

        col->data = new_data;
        col->physical_size = new_physical_size;
    }

    ((void**)col->data)[col->logical_size++] = value;

    return 1;
}

void print_col(Column* col) { //permet d'afficher une colonne
    if (col == NULL || col->data == NULL) {
        printf("NULL\n");
        return;
    }

    printf("Voici la colonne avant rangement \n");
    for (int i = 0; i < col->logical_size; ++i) {
        col->print_func(((void**)col->data)[i]);
    }
}

void delete_column(Column *col) { //permet de supprimer une colonne
    free(col->title);
    free(col->data);
    free(col);
}

int check_index(Column *col) {
    if (col == NULL) {
        return -1;
    }
    
    if (col->index == NULL) {
        return 0;
    }
    
    if (col->index) {
        return 1;
    }
    
    return -1;
}


void erase_index(Column *col) {
    if (col == NULL) {
        return;
    }
    
    if (col->index != NULL) {
        free(col->index);
        col->index = NULL;
    }
    
    col->index = 0;
}

