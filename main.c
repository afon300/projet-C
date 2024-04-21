#include <stdio.h>
#include "cdataframe.h"
#include "column.h"

int main() {
    int stop;
    CDataframe df;
    int num_columns = 3;
    init_cdataframe(&df, num_columns);

/********* Se sont des exemples avec l'age le numéro étudiant et les notes *********/

    init_column(&df.columns[0], "Age");
    init_column(&df.columns[1], "Number");
    init_column(&df.columns[2], "Notes");

    insert_value(&df.columns[0], 18);
    insert_value(&df.columns[1], 2023646);
    insert_value(&df.columns[2], 16);

/*    for (int i = 0; i < num_columns; ++i) {
        printf("%s: ", df.columns[i].title);
        for (int j = 0; j < df.columns[i].logical_size; ++j) {
            printf("%d ", df.columns[i].data[j]);
        }
        printf("\n");
    }

    int val = 5;
    if (insert_value(&df.columns[0], val))
        printf("Valeu added successfully to Age column\n");
    else
        printf("Fatal Error");

*/

    print_col(&df.columns[0]); // |
    print_col(&df.columns[1]); // |--> affichage des colones 0, 1 et 2
    print_col(&df.columns[2]); // |

    free_cdataframe(&df);
    scanf("%d", &stop); // pour le prog.exe



    return 0;
}

/*** pour compiler sur visual studio code ***/
/* commandes :
    - gcc -o prog *.c
    - ./prog
*/

