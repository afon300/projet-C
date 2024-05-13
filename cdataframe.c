#include "cdataframe.h"
#include "column.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INIT_SIZE 256
#define REALLOC_SIZE 256

void init_column(Column *col, const char *title, void (*print_func)(void*), int (*compare_func)(void*, void*)) { //pour créer une colone
    col->title = strdup(title);
    col->data = malloc(INIT_SIZE * sizeof(void*));
    col->physical_size = INIT_SIZE;
    col->logical_size = 0;
    col->print_func = print_func;
    col->compare_func = compare_func;
}

int insert_value(Column *col, void* value) { //pour insérer des vals
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

void print_col(Column* col) { //pour afficher une colone
    if (col == NULL || ((void**)col->data) == NULL) {
        printf("Column is empty\n");
        return;
    }
    
    printf("Column \"%s\" content:\n", col->title);
    for (int i = 0; i < col->logical_size; ++i) {
        col->print_func(((void**)col->data)[i]);
    }
}


void free_column(Column *col) { //libérer une colone
    free(col->title);
    free(col->data);
}

void init_cdataframe(CDataframe *df, int num_columns) {//initialiser le cdataframe à partir d'une colone
    df->columns = malloc(num_columns * sizeof(Column));
    df->num_columns = num_columns;
}

void free_cdataframe(CDataframe *df) { //libérer le dataframe
    for (int i = 0; i < df->num_columns; ++i) {
        free_column(&df->columns[i]);
    }
    free(df->columns);
}

/************************** Fonctions de la 1.5 **************************/

int count_occurrences(Column* col, void* value) {//nb occurence
    int count = 0;
    for (int i = 0; i < col->logical_size; ++i) {
        if (col->compare_func(((void**)col->data)[i], value) == 0) {
            count++;
        }
    }
    return count;
}

void* find_value(Column* col, int position) {//trouver une valeur dans une colone
    if (position < 0 || position >= col->logical_size) {
        return NULL;
    }
    return ((void**)col->data)[position];
}

int count_greater_than(Column* col, void* value) { //plus grand que
    int count = 0;
    for (int i = 0; i < col->logical_size; ++i) {
        if (col->compare_func(((void**)col->data)[i], value) > 0) {
            count++;
        }
    }
    return count;
}

int count_less_than(Column* col, void* value) { //plus petit que
    int count = 0;
    for (int i = 0; i < col->logical_size; ++i) {
        if (col->compare_func(((void**)col->data)[i], value) < 0) {
            count++;
        }
    }
    return count;
}

int count_equal_to(Column* col, void* value) { //égale à
    int count = 0;
    for (int i = 0; i < col->logical_size; ++i) {
        if (col->compare_func(((void**)col->data)[i], value) == 0) {
            count++;
        }
    }
    return count;
}
