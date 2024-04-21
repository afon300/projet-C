#ifndef COLUMN_H
#define COLUMN_H

typedef struct {
    char *title;
    int *data;
    int physical_size;
    int logical_size;
} Column;

typedef struct {
    Column *columns;
    int num_columns;
} CDataframe;

void free_column(Column *col);
void init_cdataframe(CDataframe *df, int num_columns);
void free_cdataframe(CDataframe *df);
void init_column(Column *col, const char *title);

#endif