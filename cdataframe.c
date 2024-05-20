#include "cdataframe.h"
#include "column.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INIT_SIZE 256
#define REALLOC_SIZE 256

void init_cdataframe(CDataframe *df, int num_columns) { // permet d'initialiser une dataframe
    df->columns = malloc(num_columns * sizeof(Column));
    df->num_columns = num_columns;
}

void free_cdataframe(CDataframe *df) { //permet de libérer la dataframe
    for (int i = 0; i < df->num_columns; ++i) {
        delete_column(&df->columns[i]);
    }
    free(df->columns);
    df->columns = NULL;
    df->num_columns = 0;
}

void add_column(CDataframe *df, Column new_col) { //permet d'ajouter des colonnes
    df->columns = realloc(df->columns, (df->num_columns + 1) * sizeof(Column));
    df->columns[df->num_columns] = new_col;
    df->num_columns++;
}

void remove_column(CDataframe *df, int col_index) { //supprime une colonne de la dataframe
    if (col_index < 0 || col_index >= df->num_columns) return;

    delete_column(&df->columns[col_index]);

    for (int i = col_index; i < df->num_columns - 1; ++i) {
        df->columns[i] = df->columns[i + 1];
    }
    df->columns = realloc(df->columns, (df->num_columns - 1) * sizeof(Column));
    df->num_columns--;
}

void rename_column(CDataframe *df, int col_index, const char* new_name) {// permet de renommer une colonne
    if (col_index < 0 || col_index >= df->num_columns) return;

    free(df->columns[col_index].title);
    df->columns[col_index].title = strdup(new_name);
}

void print_dataframe(CDataframe *df) { //permet d'imprimer une dataframe
    for (int i = 0; i < df->num_columns; ++i) {
        print_col(&df->columns[i]);
    }
}

int count_occurrences(Column* col, void* value) { //permet de compter combien de valeur sont égale à la valeur donner 
    int count = 0;
    for (int i = 0; i < col->logical_size; ++i) {
        if (col->compare_func(((void**)col->data)[i], value) == 0) {
            count++;
        }
    }
    return count;
}

void* find_value(Column* col, int position) { // permet de trouver une valeur 
    if (position < 0 || position >= col->logical_size) {
        return NULL;
    }
    return ((void**)col->data)[position];
}

int count_greater_than(Column* col, void* value) { //permet de compter combien de valeur sont supérieur à la valeur donner
    int count = 0;
    for (int i = 0; i < col->logical_size; ++i) {
        if (col->compare_func(((void**)col->data)[i], value) > 0) {
            count++;
        }
    }
    return count;
}

int count_less_than(Column* col, void* value) { //permet de compter combien de valeur sont inférieur à la valeur donné
    int count = 0;
    for (int i = 0; i < col->logical_size; ++i) {
        if (col->compare_func(((void**)col->data)[i], value) < 0) {
            count++;
        }
    }
    return count;
}

int count_equal_to(Column* col, void* value) { //permet de compter combien de valeur sont égale à la valeur donner
    int count = 0;
    for (int i = 0; i < col->logical_size; ++i) {
        if (col->compare_func(((void**)col->data)[i], value) == 0) {
            count++;
        }
    }
    return count;
}

void remove_element(int** arr, int* size, int index) { //permet de supprimer un index et de mettre a jour la colonne
    if (index < 0 || index >= *size) {
        printf("Index hors limites\n");
        return;
    }
    for (int i = index; i < *size - 1; i++) {
        (*arr)[i] = (*arr)[i + 1];
    }
    *size -= 1;
    int* temp = realloc(*arr, *size * sizeof(int));
    if (temp != NULL) {
        *arr = temp;
    } else {
        printf("Échec de la réallocation de mémoire\n");
    }
}

}
