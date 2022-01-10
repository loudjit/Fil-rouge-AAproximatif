#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
//#define CLEAR2CONTINUE
#include "../include/traces.h"

// C'est dans le fichier elt.h qu'on doit choisir l'implémentation des T_elt
#include "elt.h"
#include "avl.h"
#include "list.h"
#define TAILLE_MAX 50

int main(int argc, char ** argv) {

    long clk_tck = CLOCKS_PER_SEC;
    clock_t t1, t2;
    t1 = clock();//initialisation timer

    CLRSCR();
    WHOAMI();

	T_avl root = NULL;
    T_avlNode * pAux1 = NULL;
    T_avlNode * pAux2 = NULL;
    char * buffer;
    buffer = (char*) malloc(sizeof(char)*TAILLE_MAX);


    //programmation défensive
    if (argc != 2) {
        printf("Deux arguments attendus pour exécuter le programme");
        return 0;
    }

    FILE* fichier = NULL;
    fichier = fopen(argv[1], "r");
    int longueurMot=strlen(fgets(buffer,TAILLE_MAX,fichier))-1;
    fseek(fichier, 0,0);//fgets a fait avancer le curseur, on revient au début du fichier
    int i=0;
    outputPath = "output";
    if (fichier != NULL)
    {
        while (feof(fichier)!=1)  {//tant que l'on ne se trouve pas à la fin du fichier
            fgets(buffer, TAILLE_MAX, fichier); // On lit maximum TAILLE_MAX caractères du fichier, on stocke le tout dans "buffer"
            char * mot_buffer = strdup(buffer);
            tri(buffer, 0, strlen(buffer)-1);
            printf("%s\n", buffer);
            pAux1 = searchAVL_rec(root, buffer);
            if (pAux1!=NULL) {
                (pAux1->val).Liste = addNode(mot_buffer, (pAux1->val).Liste);
            }
            else {
                T_elt * anagramme;
                anagramme = (T_elt*) malloc(sizeof(T_elt));
                anagramme ->Signature = buffer;
                anagramme -> Liste = addNode(mot_buffer, anagramme -> Liste);
                insertAVL(&root, *anagramme);//on insère les <n> premiers prénoms de la liste.
        i++;

        }
// createDotAVL(root, "root");
    }
    fclose(fichier);
    t2 = clock(); /* Recuperation du temps final en "clock ticks" */



    printf("Longueur des mots : %d\n",longueurMot);
    printf("Nombre de mots : %d\n", i);
    printf("Durée de construction : %lf \n",
                (double)(t2-t1)/(double)clk_tck *1000);
    printf("Nombre de noeuds : %d\n", nbNodesAVL(root));
    printf("Hauteur de l'arbre : %d\n", heightAVL(root));
    printf("Hauteur minimale d'un arbre contenant le même nombre de noeuds : %f.\n",floor(log(nbNodesAVL(root)+1))-1);


    //Le programme boucle en attendant que l'utilisateur entre un mot dans le shell
    long clk_tck2 = CLOCKS_PER_SEC;
    clock_t t3, t4;
    char * mot_user;
    mot_user = (char*) malloc(sizeof(char)*TAILLE_MAX);


    while (*mot_user != 0 ) {
        printf("Saisir un mot de %d lettres, saisir 0 pour quitter la boucle.\n", longueurMot);
        scanf("%s", &mot_user);
        t3 = clock();
        char * mot = strdup(mot_user);
        tri(mot, 0, strlen(buffer)-1);
        pAux2 = searchAVL_rec(root, mot);
        if (pAux2!=NULL) {
            showList((pAux2->val).Liste);
            //profondeur du noeud
            t4 = clock(); /* Recuperation du temps final en "clock ticks" */
            printf("Temps de recherche : %lf \n",(double)(t4-t3)/(double)clk_tck2 *1000);
        }
        else {
            printf("Le mot n'a pas été trouvé\n");
        }
    }
return 0;

}
}
