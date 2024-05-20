#ifndef COLUMN_H
#define COLUMN_H

#define ASC 0
#define DESC 1

typedef enum {
    UNIT,
    INT,
    CHAR,
    FLOAT,
    DOUBLE,
    STRING,
    STRUCTURE
} DataType;

typedef struct {
    char *title;
    void *data;
    DataType type;
    int physical_size;
    int logical_size;
    int valid_index;
    void (*print_func)(void*);
    int (*compare_func)(void*, void*);
} Column;

Column* create_column(DataType type, const char *title);
int insert_value(Column *col, void* value);
void print_col(Column* col);
void print_col_par_ordre(Column* col);
void sort(Column* col, int sort_dir);
void delete_column(Column *col);

void quicksort(Column* col, int left, int right, int sort_dir);
void insertion_sort(Column* col, int sort_dir);
int partition(Column* col, int left, int right, int sort_dir);

#endif
