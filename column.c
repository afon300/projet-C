#include "cdataframe.h"
#include "column.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INIT_SIZE 255
#define REALLOC_SIZE 255

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

void print_col(Column* col) {
    if (col == NULL || col->data == NULL) {
        printf("NULL\n");
        return;
    }

    printf("Column \"%s\" content:\n", col->title);
    for (int i = 0; i < col->logical_size; ++i) {
        if (col->data == NULL) {
            printf("NULL\n");
        } else {
            col->print_func(((char**)col->data)[i]);
        }
    }
}

void delete_column(Column *col) {
    free((col)->title);
    free((col)->data);
    free(col);
    col = NULL;
}