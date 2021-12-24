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
    T_elt prénoms [] = lire(argc, argv);

//	T_elt srch;

	CLRSCR();
	WHOAMI(); 

	outputPath = "Programme_1/output";
	
	//on insère les <n> premiers prénoms de la liste.
    int i;
    for(i=0, i<= argv[3], i++) {
        insertAVL(&root, prénoms[i]);


/*srch = 16;
	pAux = searchAVL_it(root,srch); 
	printf("trouvé : %s\n",toString(pAux->val));
	pAux = searchAVL_rec(root,srch); 
	printf("trouvé : %s\n",toString(pAux->val));
	
	if (root==NULL) printf("null");
	printf("hauteur : %d\n",heightAVL(root));
	printf("nb noeuds : %d\n",nbNodesAVL(root));
*/
    createDotAVL(root, "root");

	return 0;
}







