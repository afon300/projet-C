#include <stdio.h>
#include <string.h>

#include "cdataframe.h"

void print_int(void* value) {
    printf("%d\n", *(int*)value);
}

void print_char(void* value) {
    printf("%c\n", *(char*)value);
}

void print_float(void* value) {
    printf("%f\n", *(float*)value);
}

void print_double(void* value) {
    printf("%lf\n", *(double*)value);
}

void print_string(void* value) {
    printf("%s\n", (char*)value);
}

int compare_int(void* a, void* b) {
    return *(int*)a - *(int*)b;
}

int compare_char(void* a, void* b) {
    return *(char*)a - *(char*)b;
}

int compare_float(void* a, void* b) {
    if (*(float*)a < *(float*)b) return -1;
    if (*(float*)a > *(float*)b) return 1;
    return 0;
}

int compare_double(void* a, void* b) {
    if (*(double*)a < *(double*)b) return -1;
    if (*(double*)a > *(double*)b) return 1;
    return 0;
}

int compare_string(void* a, void* b) {
    return strcmp((char*)a, (char*)b);
}

void save_into_csv(Column *col, char *file_name) {
    if (col == NULL || file_name == NULL) {
        printf("Erreur : données ou nom de fichier manquant.\n");
        return;
    }
    FILE *file = fopen(file_name, "w");
    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }

    if (col->type == STRING) {
        for (int i = 0; i < col->logical_size; i++) {
            fprintf(file, "%s\n", ((char**)col->data)[i]);
        }
    } else {
        printf("Erreur : type de colonne non pris en charge.\n");
    }
    
    fclose(file);
}
