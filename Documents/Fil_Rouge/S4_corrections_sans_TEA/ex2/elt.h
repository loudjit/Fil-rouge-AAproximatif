#ifndef _ELT_H_
	#define _ELT_H_ // prévient les includes multiples

	/////////////////////////////////////////////////////////////////////////
	// CHOISIR ICI CE QUE REPRESENTE LE TYPE T_elt 
	//#define ELT_CHAR		// un caractère ?
	#define ELT_INT		// un entier (choix par défaut) ?
	//#define ELT_STRING		// une chaîne de caractères ?
	//#define ELT_STRUCT		// une structure plus complexe ? 
	/////////////////////////////////////////////////////////////////////////

	//https://stackoverflow.com/questions/2998864/how-to-add-a-or-condition-in-ifdef

	#if ! defined(ELT_CHAR) && ! defined(ELT_INT) && ! defined(ELT_STRING) && ! defined(ELT_STRUCT)
		#define ELT_INT
	#endif

	#ifdef ELT_CHAR
	typedef char T_elt;
	#endif

	#ifdef ELT_INT
	typedef int T_elt; 
	#endif

	#ifdef ELT_STRING
	typedef char * T_elt; 
	#endif

	#ifdef ELT_STRUCT
	typedef struct {
		int * t; 	// un tableau 
		int size; 	// la taille de ce tableau   	
	} T_elt; 
	#endif

	// valable pour tous les types de T_elt 
	char * toString(T_elt e); 
	T_elt genElt(void);
	T_elt eltdup(T_elt); 
	int eltcmp(T_elt, T_elt);  
#endif 

