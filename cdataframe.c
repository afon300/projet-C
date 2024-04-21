#include "cdataframe.h"
#include "column.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INIT_SIZE 256
#define REALLOC_SIZE 256

void init_column(Column *col, const char *title) {
    col->title = strdup(title);
    col->data = (int *)malloc(INIT_SIZE * sizeof(int));
    col->physical_size = INIT_SIZE;
    col->logical_size = 0;
}

int insert_value(Column *col, int value) { // le return désigne si la fonction a été un échec ou une réussite
    if (col == NULL || col->data == NULL) {
        return 0; //False
    }
    
    if (col->physical_size == 0 || col->logical_size == col->physical_size) {
        int new_physical_size = col->physical_size + REALLOC_SIZE;
        int* new_data = (int*)realloc(col->data, new_physical_size * sizeof(int));
        if (new_data == NULL) {
            return 0;//False
        }
        
        col->data = new_data;
        col->physical_size = new_physical_size;
    }
    
    col->data[col->logical_size++] = value;
    
    return 1;//True
}

void print_col(Column* col) {
    if (col == NULL || col->data == NULL) {
        printf("Column is empty\n");
        return;
    }
    
    printf("Column \"%s\" content:\n", col->title);
    for (int i = 0; i < col->logical_size; ++i) {
        printf("[%d] %d\n", i, col->data[i]);
    }
}

void free_column(Column *col) {
    free(col->title);
    free(col->data);
}

void init_cdataframe(CDataframe *df, int num_columns) {
    df->columns = (Column *)malloc(num_columns * sizeof(Column));
    df->num_columns = num_columns;
}

void free_cdataframe(CDataframe *df) {
    for (int i = 0; i < df->num_columns; ++i) {
        free_column(&df->columns[i]);
    }
    free(df->columns);
}


/************************** Fonctions de la 1.5 **************************/

int count_occurrences(const int* data, int logical_size, int value) {
    int count = 0;
    for (int i = 0; i < logical_size; ++i) {
        if (data[i] == value) {
            count++;
        }
    }
    return count;
}

int find_value(const int* data, int logical_size, int position) {
    if (position < 0 || position >= logical_size) {
        return -1; // Valeur invalide
    }
    return data[position];
}

int count_greater_than(const int* data, int logical_size, int value) {
    int count = 0;
    for (int i = 0; i < logical_size; ++i) {
        if (data[i] > value) {
            count++;
        }
    }
    return count;
}

int count_less_than(const int* data, int logical_size, int value) {
    int count = 0;
    for (int i = 0; i < logical_size; ++i) {
        if (data[i] < value) {
            count++;
        }
    }
    return count;
}

int count_equal_to(const int* data, int logical_size, int value) {
    int count = 0;
    for (int i = 0; i < logical_size; ++i) {
        if (data[i] == value) {
            count++;
        }
    }
    return count;
}