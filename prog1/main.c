#include <stdio.h>
#include <assert.h>

//#define CLEAR2CONTINUE
#include "../include/traces.h" 

// C'est dans le fichier elt.h qu'on doit choisir l'implémentation des T_elt
#include "elt.h"
#include "avl.h"
#include "lire.h"
#include "compare.h"

int main(int argc, char ** argv) {
	T_avl root = NULL; 
	T_avlNode * pAux = NULL;
   	T_elt prénoms [] = lire(argc, argv);//Ce serait pratique si dans le code "lire", il créeait un tableau avec chaque ligne, au lieu de juste tout 
	//afficher (si j'ai bien compris le code)

//	T_elt srch;

	CLRSCR();
	WHOAMI(); 

	outputPath = "Programme_1/output";
	
	//on insère les <n> premiers prénoms de la liste
	int i;
    	for(i=0, i<= argv[3], i++) {
        insertAVL(&root, prénoms[i]);
	}

/*srch = 16;
	pAux = searchAVL_it(root,srch); 
	printf("trouvé : %s\n",toString(pAux->val));
	pAux = searchAVL_rec(root,srch); 
	printf("trouvé : %s\n",toString(pAux->val));
	
	if (root==NULL) printf("null");
	printf("hauteur : %d\n",heightAVL(root));
	printf("nb noeuds : %d\n",nbNodesAVL(root));
*/
    	createDotAVL(root, "root"); //Je comprends pas vraiment comment ça ça fonctionne, dans le programme de base ça met des erreurs donc bon...Si ça voulait bien afficher 
	//quelque chose je comprendrais mais c'est pas le cas

	return 0;
}







