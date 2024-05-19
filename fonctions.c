#include <stdio.h>
#include <string.h>

void print_int(void* value) {
    printf("%d\n", *(int*)value);
}

void print_string(void* value) {
    printf("%s\n", (char*)value);
}

int compare_int(void* a, void* b) {
    return *(int*)a - *(int*)b;
}

int compare_string(void* a, void* b) {
    return strcmp((char*)a, (char*)b);
}