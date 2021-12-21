#include <assert.h>
#include <sys/stat.h>
#include <string.h>

//#define CLEAR2CONTINUE
#include "../include/traces.h" 

//#define DEBUG
#include "../include/check.h"

#include "elt.h" // T_elt 
#include "bst.h" // prototypes 

char * outputPath = "."; 

/*
typedef struct tNode{
	T_elt val;
	struct tNode *l;
	struct tNode *r;
} T_bstNode, *T_bst;
*/

static T_bstNode * newNodeBST(T_elt e) {
	// Créer une nouvelle cellule contenant l'élément e
	T_bstNode * pAux; 
	pAux = (T_bstNode *) malloc(sizeof (T_bstNode)); 
	CHECK_IF(pAux, NULL,"erreur malloc dans newNode");
	pAux->val = eltdup(e); 
	pAux->l = NULL; 
	pAux->r = NULL; 

	return pAux;
}

T_bst insertBST(T_bst root, T_elt e) {
	// ordre de récurrence : hauteur du sous-arbre enraciné sous root 
	// cas de base : arbre vide 
	if (root== NULL) return newNodeBST(e); 
	else {
		// On compare l'élément et la racine 
		if (eltcmp(e,root->val) <= 0) {
			// On insère dans le sous-arbre gauche
			root->l = insertBST(root->l, e); 
		} else {
			// On insère dans le sous-arbre droit
			root->r = insertBST(root->r, e); 
		}
		return root; 
	}
}

void printBST(T_bst root, int indent) {
	int i; 
	// ordre de la récurrence : hauteur de l'arbre 
	// Affiche la racine de l'arbre passé en paramètre avec un niveau d'indentation proportionnel à la profondeur du sous-arbre 

	// pas de cas de base... 
	if (root!=NULL) {
		// afficher le sous-arbre droit avec indentation+1
		printBST(root->r, indent+1);
		// afficher le noeud racine 
		for(i=0;i<indent;i++) printf("\t");
		printf("%s\n", toString(root->val));
		// afficher le sous-arbre gauche avec indentation+1
		printBST(root->l, indent+1);
	}
}

T_bstNode * searchBST_rec(T_bst root, T_elt e){
	// recherche récursive

	// ordre de récurrence : hauteur de l'arbre 	
	int test; 

	// base 
	if (root== NULL) return NULL; 
	else {
		test = eltcmp(e,root->val); 
		if (test == 0) return root; // trouvé ! 
		else if (test <= 0) return searchBST_rec(root->l,e);
		else return searchBST_rec(root->r,e);
	}
}

T_bstNode * searchBST_it(T_bst root, T_elt e){
	// recherche itérative

	int test;
	while(root!=NULL) {	
		test = eltcmp(e,root->val);
		if (test ==0) return root;
		else if  (test <= 0) root = root->l; 
		else root = root->r; 
	}

	// pas trouvé (ou vide)
	return NULL;  
}

int heightBST(T_bst root){
	// hauteur d'un arbre 
	int l,r; 
	if (root == NULL) return -1;
	l = heightBST(root->l);
	r = heightBST(root->r);
	return 1+ ((l >= r) ? l : r); 

}

int nbNodesBST(T_bst root){
	// nb de noeuds d'un arbre (y compris les feuilles) 
	if (root == NULL) 
		return 0;
	
	return 1+ nbNodesBST(root->l) + nbNodesBST(root->r);
}

int nbLeavesBST(T_bst root){
	// nb de feuilles 
	if (root == NULL) return 0;
	if ((root->l == NULL) && (root->r == NULL)) return 1;
	return nbLeavesBST(root->l) + nbLeavesBST(root->r);
}

T_bstNode * minBST(T_bst root){
	// recherche du minimum d'un arbre 
	assert(root != NULL); 
	if (root->l==NULL) return root; 
	else return minBST(root->l); 
}

T_bstNode * maxBST(T_bst root){
	// en itératif 
	T_bstNode * pAux = root;  
	assert(root != NULL);
	
	while(pAux->r != NULL) pAux = pAux->r; 

	return pAux; 
}

int areEqualsBST(T_bst root1, T_bst root2){
	// les arbres ont la même structure et les mêmes éléments dans chaque noeud 
	if (root1 == NULL) {
		if (root2 ==NULL) return 1; 
		else return 0; 
	} else {
		if (root2==NULL) return 0; 
		else {
			// ni l'un ni l'autre ne sont nuls... 
			// il faut qu'ils aient la même racine 
			if (eltcmp(root1->val,root2->val) != 0) return 0; 
			else {
				// il faut qu'ils aient aussi récursivement les mêmes sous-arbres 
				return (areEqualsBST(root1->l, root2->l) && areEqualsBST(root1->r, root2->r));
			}
		}
	}
}

int areIsomorphicBST(T_bst root1, T_bst root2){
	// les arbres ont la même structure
	if (root1 == NULL) {
		if (root2 ==NULL) return 1; 
		else return 0; 
	} else {
		if (root2==NULL) return 0; 
		else {
			// ni l'un ni l'autre ne sont nuls... 
			// il faut qu'ils aient aussi récursivement les mêmes sous-arbres 
			return (areIsomorphicBST(root1->l, root2->l) && areIsomorphicBST(root1->r, root2->r));
		}
	}
}

T_bst copyBST(T_bst root){
	T_bstNode * pAux; 
	if (root == NULL) return NULL; 
	else {
		pAux = newNodeBST(root->val);
		pAux->l = copyBST(root->l);
		pAux->r = copyBST(root->r);
		return pAux; 
	} 
}

void printPreOrderBST(T_bst root) {
	// LRN
	if (root== NULL) return;

	printPreOrderBST(root->l); 		 
	printPreOrderBST(root->r); 
	printf("%s ", toString(root->val));
	
}

#define DERECURSIVATION
#ifndef DERECURSIVATION
void printInOrderBST(T_bst root) {
	// LNR
	if (root== NULL) return; 

	printInOrderBST(root->l); 
	printf("%s ", toString(root->val)); 
	printInOrderBST(root->r); 
}

void printPostOrderBST(T_bst root) {
	// NLR
	if (root== NULL) return;

	printf("%s ", toString(root->val)); 
	printPostOrderBST(root->l);
	printPostOrderBST(root->r); 
}
#endif

#ifdef DERECURSIVATION
void printInOrderBST(T_bst root) {
	// LNR avec suppression de l'appel récursif terminal 
	if (root== NULL) return; 

	while (root!=NULL) {
		printInOrderBST(root->l); 
		printf("%s ", toString(root->val)); 
		root = root->r;
	} 
}

void printPostOrderBST(T_bst root) {
	// NLR
	if (root== NULL) return;

	while (root!=NULL) {
		printf("%s ", toString(root->val)); 
		printPostOrderBST(root->l);
		root = root->r; 
	}
}
#endif 

static void  genDotBST(T_bst root, FILE *fp) {
	// Attention : les fonction toString utilisent un buffer alloué comme une variable statique 
	// => elles renvoient toujours la même adresse 
	// => on ne peut pas faire deux appels à toString dans le même printf()

    fprintf(fp, "\t%s",toString(root->val)); 
    fprintf(fp, " [label = \"{<c> %s | { <g> | <d>}}\"];\n",toString(root->val));
    if (root->r == NULL && root->l == NULL) {
        fprintf(fp, "\t%s", toString(root->val)); 
		fprintf(fp, " [label = \"{<c> %s | { <g> NULL | <d> NULL}}\"];\n", toString(root->val));
	}
    else if (root->r == NULL) {
        fprintf(fp, "\t%s", toString(root->val));
		fprintf(fp, " [label = \"{<c> %s | { <g> | <d> NULL}}\"];\n", toString(root->val));
	}
	else if ( root->l == NULL) {
        fprintf(fp, "\t%s",toString(root->val));
		fprintf(fp, " [label = \"{<c> %s | { <g> NULL | <d> }}\"];\n", toString(root->val));
	}
	
    if (root->l) {
        fprintf(fp, "\t%s",toString(root->val));
		fprintf(fp, ":g -> %s;\n", toString(root->l->val));
        genDotBST(root->l, fp);
    }

    if (root->r) {
        fprintf(fp, "\t%s",toString(root->val));
		fprintf(fp,":d -> %s;\n", toString(root->r->val));
        genDotBST(root->r, fp);
    }
}


void createDotBST(const T_bst root, const char *basename) {
	static char oldBasename[FILENAME_MAX + 1] = "";
	static unsigned int noVersion = 0;

	char DOSSIER_DOT[FILENAME_MAX + 1]; 
	char DOSSIER_PNG[FILENAME_MAX + 1]; 

	char fnameDot [FILENAME_MAX + 1];
	char fnamePng [FILENAME_MAX + 1];
	char	cmdLine [2 * FILENAME_MAX + 20];
	FILE *fp;
	struct stat sb;
	

	// Au premier appel, création (si nécessaire) des répertoires
	// où seront rangés les fichiers .dot et .png générés par cette fonction	

	// il faut créer le répertoire outputPath s'il n'existe pas 
	if (stat(outputPath, &sb) == 0 && S_ISDIR(sb.st_mode)) {
    } else {
        printf("Création du répertoire %s\n", outputPath);
		mkdir(outputPath, 0777);
    }

	// il faut créer les répertoires outputPath/png et /dot 
	sprintf(DOSSIER_DOT, "%s/dot/",outputPath);
	sprintf(DOSSIER_PNG, "%s/png/",outputPath);

	if (oldBasename[0] == '\0') {
		mkdir(DOSSIER_DOT,	S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH);
		mkdir(DOSSIER_PNG,	S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH);
	}

	 // S'il y a changement de nom de base alors recommencer à zéro
	 // la numérotation des fichiers 

	if (strcmp(oldBasename, basename) != 0) {
		noVersion = 0;
		strcpy(oldBasename, basename); 
	}

	sprintf(fnameDot, "%s%s_v%02u.dot", DOSSIER_DOT, basename, noVersion);
	sprintf(fnamePng, "%s%s_v%02u.png", DOSSIER_PNG, basename, noVersion);

	CHECK_IF(fp = fopen(fnameDot, "w"), NULL, "erreur fopen dans saveDotBST"); 
	
	noVersion ++;
    fprintf(fp, "digraph %s {\n", basename);
 	fprintf(fp, 
		"\tnode [\n"
			"\t\tfontname  = \"Arial bold\" \n"
			"\t\tfontsize  = \"14\"\n"
			"\t\tfontcolor = \"red\"\n"
			"\t\tstyle     = \"rounded, filled\"\n"
			"\t\tshape     = \"record\"\n"
			"\t\tfillcolor = \"grey90\"\n"
			"\t\tcolor     = \"blue\"\n"
			"\t\twidth     = \"2\"\n"
			"\t]\n"
		"\n"
		"\tedge [\n"
			"\t\tcolor     = \"blue\"\n"
		"\t]\n\n"
	);

    if (root == NULL)
        fprintf(fp, "\n");
    else
        genDotBST(root, fp);

    fprintf(fp, "}\n");	
    fclose(fp);

    sprintf(cmdLine, "dot -Tpng  %s -o %s", fnameDot, fnamePng);
    system(cmdLine);

    printf("Creation de '%s' et '%s' ... effectuee\n", fnameDot, fnamePng);
}


