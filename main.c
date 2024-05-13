#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cdataframe.h"
#include "column.h"

void print_int(void* value) {
    printf("%d\n", *(int*)value);
}

int compare_int(void* a, void* b) {
    return *(int*)a - *(int*)b;
}

void print_string(void* value) {
    printf("%s\n", (char*)value);
}

int compare_string(void* a, void* b) {
    return strcmp((char*)a, (char*)b);
}


/*mtn il vas falloir rendre ce bout un peut plus esthétique mais ce seras pour plus tard car là il est un peu tard*/
int main() {
    int stop;
    CDataframe df;
    int num_columns = 3;
    init_cdataframe(&df, num_columns);

    init_column(&df.columns[0], "Date de", print_int, compare_int);
    init_column(&df.columns[1], "Number", print_int, compare_int);
    init_column(&df.columns[2], "Name", print_string, compare_string);

    int* age = malloc(sizeof(int));
    *age = 23;
    insert_value(&df.columns[0], age);
    int* number = malloc(sizeof(int));
    *number = 2023646;
    insert_value(&df.columns[1], number);
    char* note = strdup("Foufoune");
    insert_value(&df.columns[2], note);

    print_col(&df.columns[0]); // |
    print_col(&df.columns[1]); // |--> affichage des colones 0, 1 et 2
    print_col(&df.columns[2]); // |

    free_cdataframe(&df);
    scanf("%d", &stop); // pour le prog.exe

    return 0;
}
