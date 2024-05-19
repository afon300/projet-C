#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cdataframe.h"
#include "column.h"
#include "fonctions.h"

/*mtn il vas falloir rendre ce bout un peut plus esthétique mais ce seras pour plus tard car là il est un peu tard*/

int main() {
    //Exp d'ut avec des entiers
    printf("Exemple d'utilisation avec des entiers:\n");
    Column *mycol = create_column(INT, "colone de sortie d'entiers");

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

    insert_value(mycol, &Autriche);
    insert_value(mycol, &Bulgarie);
    insert_value(mycol, &Chine);
    insert_value(mycol, &Djibouti);
    insert_value(mycol, &Egypte);
    insert_value(mycol, &France);
    insert_value(mycol, &Grece);
    insert_value(mycol, &Hongrie);
    insert_value(mycol, &Inde);
    insert_value(mycol, &Japon);
    insert_value(mycol, &Kazakhstan);
    insert_value(mycol, &Laos);
    insert_value(mycol, &Madagascar);
    insert_value(mycol, &Norvege);
    insert_value(mycol, &Oman);

    print_col(mycol);
    sort(mycol, ASC);
    print_col_par_ordre(mycol);

    // Libérer la mémoire car sinon ça fais bcp là non ?
    delete_column(mycol);

    /* en théorie ça marche mais il reste un petit bug je réglerais ça tout à l'heure car il est un peu tard
    Column *decimal_col = create_column(FLOAT, "Decimal column");
    float x = 1.13;
    insert_value(decimal_col, &x);
    printf("Contenu de la colonne avant le tri :\n");
    print_col(decimal_col);
    sort(decimal_col, ASC);
    printf("Contenu de la colonne après le tri :\n");
    print_col(decimal_col);
    delete_column(decimal_col);  
    */


    // Exp d'util avec des chaînes de caractères ou cch pour les intimes ^^
    printf("\nExemple d'utilisation avec des chaînes de caractères:\n");
    mycol = create_column(STRING, "String column");
    insert_value(mycol, "Vienne");
    insert_value(mycol, "Sofia");   
    insert_value(mycol, "Pekin");    
    insert_value(mycol, "Djibouti");   
    insert_value(mycol, "Le Caire");
    insert_value(mycol, "Paris");
    insert_value(mycol, "Athenes");
    insert_value(mycol, "Budapest");
    insert_value(mycol, "New Delhi");
    insert_value(mycol, "Tokyo"); 
    insert_value(mycol, "Noursoultan");  
    insert_value(mycol, "Vientiane");
    insert_value(mycol, "Antananarivo");
    insert_value(mycol, "Oslo");
    insert_value(mycol, "Mascate");
    
    printf("Column content before sorting : \n");
    print_col(mycol);
    sort(mycol, ASC);
    printf("Column content after sorting : \n");
    print_col_par_ordre(mycol);

    // Libérer la mémoire pcq j'ai que 64MB de ram est c'est pas assez
    delete_column(mycol);

    return 0;
}