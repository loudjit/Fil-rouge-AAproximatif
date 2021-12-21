#include <stdio.h>
#include <assert.h>

//#define CLEAR2CONTINUE
#include "../include/traces.h" 

// C'est dans le fichier elt.h qu'on doit choisir l'implémentation des T_elt
#include "elt.h"
#include "bst.h"

int main(int argc, char ** argv) {
	T_bst root = NULL; 
	T_bst root2 = NULL; 
	T_bstNode * pAux = NULL;

	T_elt srch; 

	CLRSCR();
	WHOAMI(); 

	/////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////

	// Création d'un ABR
	// 8, 11, 16, 5, 7, 14, 6, 1, 3, 10, 12,16
	root = insertBST(root, 8);
	root = insertBST(root, 11);
	root = insertBST(root, 16);
	root = insertBST(root, 5);
	root = insertBST(root, 7);
	root = insertBST(root, 14);
	root = insertBST(root, 6);
	root = insertBST(root, 1);
	root = insertBST(root, 3);
	root = insertBST(root, 10);
	root = insertBST(root, 12);
	root = insertBST(root, 16);


	// Affichage pseudo-graphique
	printBST(root, 0); 



	// Recherches dans un ABR 
	srch = 16;
	pAux = searchBST_it(root,srch); 
	printf("trouvé : %s\n",toString(pAux->val));
	pAux = searchBST_rec(root,srch); 
	printf("trouvé : %s\n",toString(pAux->val));


/*
	// Tester chaque type de T_elt 
	root = NULL;  
	root = insertBST(root, genElt());
	root = insertBST(root, genElt());
	srch = genElt();
	root = insertBST(root, srch);
	root = insertBST(root, genElt());
	root = insertBST(root, genElt());
	printBST(root, 0); 

	pAux = searchBST_it(root,srch); 
	printf("trouvé : %s\n",toString(pAux->val));
	pAux = searchBST_rec(root,srch); 
	printf("trouvé : %s\n",toString(pAux->val));
*/

	
	// Propriété des ABR
	printf("hauteur : %d\n",heightBST(root));
	printf("nb noeuds : %d\n",nbNodesBST(root));
	printf("nb feuilles : %d\n",nbLeavesBST(root));
	printf("min : %d\n",minBST(root)->val);
	printf("max : %d\n",maxBST(root)->val);



	// copie, isomorphes, égaux
	root2 = copyBST(root);
	printf("root2 : \n"); 
	printBST(root2, 0); 
	if (areEqualsBST(root,root2)) printf("les ABR sont égaux\n");
	if (areIsomorphicBST(root,root2)) printf("les ABR sont isomorphes\n");

	root2->val = 5;
	printf("root2 : \n");
	printBST(root2, 0);  
	if (areEqualsBST(root,root2)) printf("les ABR sont égaux\n");
	if (areIsomorphicBST(root,root2)) printf("les ABR sont isomorphes\n");



	// parcours
	printf("infixe : "); printInOrderBST(root); printf("\n");
	printf("postfixe : ");printPostOrderBST(root); printf("\n");
	printf("préfixe : ");printPreOrderBST(root); printf("\n");



	// affichage graphique
	outputPath = "ex1/output";
	createDotBST(root, "root");


	return 0;
}







