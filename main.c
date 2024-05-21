#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cdataframe.h"
#include "column.h"
#include "fonctions.h"

int main() {
    int stop = 0;
    CDataframe df;
    init_cdataframe(&df, 0);

    int int_value;
    char char_value;
    float float_value;
    double double_value;
    char string_value[128];


    char new_name[32];
    char file_name[32];
    int choice, choice_2;
    Column *col;
    int index;

    do {
        printf("\nMenu:\n");
        printf("1. Ajouter une colonne\n");
        printf("2. Renommer une colonne\n");
        printf("3. Exemple en dur\n");
        printf("4. Imprimer le cdataframe\n");
        printf("5. Sauvegarder une colonne dans un fichier CSV\n");
        printf("6. Supprimer une colonne\n");
        printf("7. Autres fonctions\n");
        printf("8. Quitter\n");
        printf("Choisissez une option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nQuel type voulez-vous choisir\n");
                printf("1. INT\n");
                printf("2. CHAR\n");
                printf("3. FLOAT\n");
                printf("4. DOUBLE\n");
                printf("5. STRING\n");
                scanf("%d", &choice_2);

                switch (choice_2) {
                    case 1:
                        col = create_column(INT, "colonne de sortie d'entiers");
                        printf("Entrez un entier: ");
                        scanf("%d", &int_value);
                        insert_value(col, &int_value);
                        add_column(&df, *col);
                        break;
                    case 2:
                        col = create_column(CHAR, "colonne de sortie de caractères");
                        printf("Entrez un caractère: ");
                        scanf(" %c", &char_value);
                        insert_value(col, &char_value);
                        add_column(&df, *col);
                        break;
                    case 3:
                        col = create_column(FLOAT, "colonne de sortie de floats");
                        printf("Entrez un float: ");
                        scanf("%f", &float_value);
                        insert_value(col, &float_value);
                        add_column(&df, *col);
                        break;
                    case 4:
                        col = create_column(DOUBLE, "colonne de sortie de doubles");
                        printf("Entrez un double: ");
                        scanf("%lf", &double_value);
                        insert_value(col, &double_value);
                        add_column(&df, *col);
                        break;
                    case 5:
                        col = create_column(STRING, "colonne de sortie de strings");
                        printf("Entrez une chaîne: ");
                        scanf("%s", string_value);
                        insert_value(col, string_value);
                        add_column(&df, *col);
                        break;
                    default:
                        printf("Choix invalide.\n");
                        break;
                }
                break;
            case 2:
                    printf("Entrez l'index de la colonne à renommer: ");
                    scanf("%d", &index);
                    printf("Entrez le nouveau nom pour la colonne: ");
                    scanf("%s", new_name);
                    rename_column(&df, index, new_name);
                    printf("Colonne renommée.\n");
                    break;
            case 3:
                test_brut();
                break;
            case 4:
                printf("Imprimer le cdataframe :\n");
                print_dataframe(&df);
                break;
            case 5:
                    printf("Entrez le nom du fichier CSV pour sauvegarder la colonne: ");
                    scanf("%s", file_name);
                    save_into_csv(&df.columns[0], file_name);
                    printf("Colonne sauvegardée dans le fichier CSV.\n");
                break;
            case 6:
                printf("Entrez l'index de la colonne à supprimer: ");
                scanf("%d", &index);
                remove_column(&df, index);
                printf("Colonne supprimée.\n");
                break;
            case 7:
                printf("Autres fonctions :\n");
                printf("1. Compter les occurrences d'une valeur\n");
                printf("2. Trouver une valeur\n");
                printf("3. Compter les valeurs supérieures à une valeur\n");
                printf("4. Compter les valeurs inférieures à une valeur\n");
                printf("5. Compter les valeurs égales à une valeur\n");
                printf("Choisissez une option: ");
                scanf("%d", &choice_2);

                switch (choice_2) {
                    case 1: {
                        printf("Entrez la valeur à rechercher : ");
                        int value;
                        scanf("%d", &value);
                        int occurrences = count_occurrences(&df.columns[0], &value);
                        printf("Occurrences : %d\n", occurrences);
                        break;
                    }
                    case 2: {
                        printf("Entrez la position de la valeur à trouver : ");
                        int position;
                        scanf("%d", &position);
                        void *found_value = find_value(&df.columns[0], position);
                        printf("Valeur à la position %d : %d\n", position, *(int*)found_value);
                        break;
                    }
                    case 3: {
                        printf("Entrez la valeur de référence : ");
                        int value;
                        scanf("%d", &value);
                        int count_greater = count_greater_than(&df.columns[0], &value);
                        printf("Nombre de valeurs supérieures à %d : %d\n", value, count_greater);
                        break;
                    }
                    case 4: {
                        printf("Entrez la valeur de référence : ");
                        int value;
                        scanf("%d", &value);
                        int count_less = count_less_than(&df.columns[0], &value);
                        printf("Nombre de valeurs inférieures à %d : %d\n", value, count_less);
                        break;
                    }
                    case 5: {
                        printf("Entrez la valeur a rechercher : ");
                        int value;
                        scanf("%d", &value);
                        int count_equal = count_equal_to(&df.columns[0], &value);
                        printf("Nombre de valeurs égales à %d : %d\n", value, count_equal);
                        break;
                    }
                    default:
                        printf("Option invalide. Veuillez réessayer.\n");
                        break;
                }
                break;
            case 8:
                printf("Quitter le programme.\n");
                break;
            default:
                printf("Option invalide. Veuillez réessayer.\n");
                break;
        }
    } while (choice != 7);

    free_cdataframe(&df);  

    scanf("%d", &stop); // pour le prog.exe
    return 0;
}
