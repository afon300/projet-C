#ifndef FONCTIONS_H
#define FONCTIONS_H

#include "cdataframe.h"

void print_int(void* value);
void print_char(void* value);
void print_float(void* value);
void print_double(void* value);
void print_string(void* value);

int compare_int(void* a, void* b);
int compare_char(void* a, void* b);
int compare_float(void* a, void* b);
int compare_double(void* a, void* b);
int compare_string(void* a, void* b);

void save_into_csv(Column *cdf, char *file_name);
void test_brut();

#endif