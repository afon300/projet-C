#ifndef CDATAFRAME_H
#define CDATAFRAME_H

#include "column.h"

typedef struct {
    Column *columns;
    int num_columns;
} CDataframe;

void init_cdataframe(CDataframe *df, int num_columns);
void free_cdataframe(CDataframe *df);
void add_column(CDataframe *df, Column new_col);
void remove_column(CDataframe *df, int col_index);
void rename_column(CDataframe *df, int col_index, const char* new_name);
void print_dataframe(CDataframe *df);

int count_occurrences(Column* col, void* value);
void* find_value(Column* col, int position);
int count_greater_than(Column* col, void* value);
int count_less_than(Column* col, void* value);
int count_equal_to(Column* col, void* value);

#endif