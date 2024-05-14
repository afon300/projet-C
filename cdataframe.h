#ifndef CDATAFRAME_H
#define CDATAFRAME_H

#include "column.h"

typedef struct {
    Column *columns;
    int num_columns;
} CDataframe;


void init_cdataframe(CDataframe *df, int num_columns);
void free_cdataframe(CDataframe *df);


/********************** Fonctions de la 1.5 **********************/

int count_occurrences(Column* col, void* value);
void* find_value(Column* col, int position);
int count_greater_than(Column* col, void* value);
int count_less_than(Column* col, void* value);
int count_equal_to(Column* col, void* value);

#endif
