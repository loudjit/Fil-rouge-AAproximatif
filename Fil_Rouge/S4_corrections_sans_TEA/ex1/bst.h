#include "elt.h" // T_elt 

#ifndef _BST_H_
#define _BST_H_

typedef struct tNode{
	T_elt val;			// élément contenu dans le noeud 
	struct tNode *l;	// pointeur vers sous-arbre gauche
	struct tNode *r;	// pointeur vers sous-arbre droit
} T_bstNode, *T_bst;

extern char * outputPath;

T_bst insertBST(T_bst root, T_elt e);
T_bstNode * searchBST_rec(T_bst root, T_elt e);
T_bstNode * searchBST_it(T_bst root, T_elt e);
int heightBST(T_bst);
int nbNodesBST(T_bst);
int nbLeavesBST(T_bst);
T_bstNode * minBST(T_bst);
T_bstNode * maxBST(T_bst);

void printBST(T_bst root, int indent); 
void printInOrderBST(T_bst);
void printPostOrderBST(T_bst);
void printPreOrderBST(T_bst);

int areEqualsBST(T_bst, T_bst);
int areIsomorphicBST(T_bst ,T_bst);
T_bst copyBST(T_bst);

void createDotBST(const T_bst root, const char *basename); 


#endif 


