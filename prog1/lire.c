#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>

/*  char adresse = argv[1];
int nb_lignes = argv[2];  */

char lire(char adresse, int nb_lignes);


int main(int argc, char const *argv[]) {
    char adresse = argv[1]; // arguments
    int nb_lignes = argv[2]; // <n>, qui va devenir un compteur
    int i = nb_lignes;

    char l = lire(adresse, nb_lignes);
    while (i!=0)
        printf(l[i]);
    return 0;
}


char lire(char adresse, int nb_lignes) {
    /*char adresse = argv[1]; // arguments
    int nb_lignes = argv[2]; // <n>, qui va devenir un compteur */
    
    
    char * tab;

    tab = malloc(nb_lignes * sizeof(adresse));

    if( tab == NULL ){
        printf(stderr,"Allocation impossible");
        exit(EXIT_FAILURE);
    }
    
    //char lignes[nb_lignes]; //tableau pour stocker les lignes
    int n = abs(nb_lignes); // valeur fixe de <n>

    const char* filename = adresse; //adresse = "../Prenoms_V2/Prenoms/PrenomsV2.txt"
    
    FILE* input_file = NULL;
    input_file = fopen(filename, "r");//ouverture fichier mode lecture
    if (input_file == NULL)
        exit(EXIT_FAILURE);

    char *contents = NULL;
    size_t len = 0;
    while ((getline(&contents, &len, input_file) != -1) && (nb_lignes != 0)){//lecture ligne par ligne
        printf("%s", contents);
        tab[n - nb_lignes] = contents;
        nb_lignes -= 1;
    }

    
    fclose(input_file);
    free(contents);

    return tab;

    exit(EXIT_SUCCESS);
}

