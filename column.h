#ifndef COLUMN_H
#define COLUMN_H

typedef struct {
    char *title;
    void *data;
    int physical_size;
    int logical_size;
    void (*print_func)(void*);
    int (*compare_func)(void*, void*);
} Column;

void init_column(Column *col, const char *title, void (*print_func)(void*), int (*compare_func)(void*, void*));
int insert_value(Column *col, void* value);

void print_col(Column* col);
void delete_column(Column *col);

#endif