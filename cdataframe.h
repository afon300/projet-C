#ifndef CDATAFRAME_H
#define CDATAFRAME_H

#include "column.h"

int insert_value(Column *col, int value);
void print_col(Column* col);


/********************** Fonctions de la 1.5 **********************/

int count_occurrences(const int* data, int logical_size, int value);
int find_value(const int* data, int logical_size, int position);
int count_greater_than(const int* data, int logical_size, int value);
int count_less_than(const int* data, int logical_size, int value);
int count_equal_to(const int* data, int logical_size, int value);

#endif