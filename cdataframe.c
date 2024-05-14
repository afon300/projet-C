#include "cdataframe.h"
#include "column.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INIT_SIZE 256
#define REALLOC_SIZE 256

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
