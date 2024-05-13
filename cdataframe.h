#ifndef CDATAFRAME_H
#define CDATAFRAME_H

typedef struct {
    char *title;
    void *data;
    int physical_size;
    int logical_size;
    void (*print_func)(void*);
    int (*compare_func)(void*, void*);
} Column;

typedef struct {
    Column *columns;
    int num_columns;
} CDataframe;

void free_column(Column *col);
void init_cdataframe(CDataframe *df, int num_columns);
void free_cdataframe(CDataframe *df);
void init_column(Column *col, const char *title, void (*print_func)(void*), int (*compare_func)(void*, void*));

int insert_value(Column *col, void* value);
void print_col(Column* col);

/********************** Fonctions de la 1.5 **********************/

int count_occurrences(Column* col, void* value);
void* find_value(Column* col, int position);
int count_greater_than(Column* col, void* value);
int count_less_than(Column* col, void* value);
int count_equal_to(Column* col, void* value);

#endif
