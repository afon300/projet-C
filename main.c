#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cdataframe.h"
#include "column.h"
#include "fonctions.h"

/*mtn il vas falloir rendre ce bout un peut plus esthétique mais ce seras pour plus tard car là il est un peu tard*/

int main() {
    int stop = 0;

/*********************** Exp d'ut avec des entiers *********************/

    printf("Exemple d'utilisation avec des entiers:\n");
    Column *int_col = create_column(INT, "colone de sortie d'entiers");

    int Autriche = 30;       //|
    int Bulgarie = 72;       //|
    int Chine = 2;           //|
    int Djibouti = 174;      //|
    int Egypte = 35;         //|
    int France = 7;          //|
    int Grece = 52;          //|
    int Hongrie = 56;        //|------> Classement par La Banque mondiale
    int Inde = 5;            //|
    int Japon = 4;           //|
    int Kazakhstan = 55;     //|
    int Laos = 120;          //|
    int Madagascar = 133;    //|
    int Norvege = 29;        //|
    int Oman = 69;           //|

    insert_value(int_col, &Autriche);
    insert_value(int_col, &Bulgarie);
    insert_value(int_col, &Chine);
    insert_value(int_col, &Djibouti);
    insert_value(int_col, &Egypte);
    insert_value(int_col, &France);
    insert_value(int_col, &Grece);
    insert_value(int_col, &Hongrie);
    insert_value(int_col, &Inde);
    insert_value(int_col, &Japon);
    insert_value(int_col, &Kazakhstan);
    insert_value(int_col, &Laos);
    insert_value(int_col, &Madagascar);
    insert_value(int_col, &Norvege);
    insert_value(int_col, &Oman);

    printf("Column content before sorting : \n");
    print_col(int_col);
    sort(int_col, ASC);
    printf("Column content after sorting : \n");
    print_col_par_ordre(int_col);
    
    delete_column(int_col); // Libérer la mémoire pcq j'ai que 64MB de ram est c'est pas assez


/********* Exp d'util avec des chaînes de caractères ou STRING pour en anglais ^^ *********/

    Column *str_col = create_column(INT, "colone de sortie d'entiers");
    printf("\nExemple d'utilisation avec des chaines de caracteres:\n");
    str_col = create_column(STRING, "String column");
    insert_value(str_col, "Vienne");
    insert_value(str_col, "Sofia");   
    insert_value(str_col, "Pekin");    
    insert_value(str_col, "Djibouti");   
    insert_value(str_col, "Le Caire");
    insert_value(str_col, "Paris");
    insert_value(str_col, "Athenes");
    insert_value(str_col, "Budapest");
    insert_value(str_col, "New Delhi");
    insert_value(str_col, "Tokyo"); 
    insert_value(str_col, "Noursoultan");  
    insert_value(str_col, "Vientiane");
    insert_value(str_col, "Antananarivo");
    insert_value(str_col, "Oslo");
    insert_value(str_col, "Mascate");

    print_col(str_col);
    sort(str_col, ASC);
    print_col_par_ordre(str_col);

    save_into_csv(str_col, "output.csv");

    delete_column(str_col); // Libérer la mémoire car sinon ça fais bcp là non ?

/********************************* Pour les float ça rime avc boat c'est drôle ^^ *********************************/

    Column *boat_col = create_column(FLOAT, "Decimal column");
    float hdi_moyen = 0.515; // argent total dans le monde 0.515 biliards de dollard soit 515 000 milliards
    insert_value(boat_col, &hdi_moyen);
    printf("Contenu de la colonne avant le tri :\n");
    print_col(boat_col);
    sort(boat_col, ASC);
    delete_column(boat_col);  

/************************************************* Pour les double **************************************************/

    Column *double_col = create_column(DOUBLE, "Decimal_v2 column");
    double pib_usa = 22.675; // en billions de dollards (un billion == 1 000 milliards)
    insert_value(double_col, &pib_usa);
    printf("Contenu de la colonne avant le tri :\n");
    print_col(double_col);
    sort(double_col, ASC);
    delete_column(double_col);  

/************************************************* Pour les double **************************************************/

    Column *char_col = create_column(CHAR, "cara-column");
    char yemen = 'Y'; // qui est le seul pays à avoir Y en initiale
    insert_value(char_col, &yemen);
    printf("Contenu de la colonne avant le tri :\n");
    print_col(char_col);
    sort(char_col, ASC);
    delete_column(char_col);  

    //scanf("%d", &stop); // pour le prog.exe
    return 0;
}