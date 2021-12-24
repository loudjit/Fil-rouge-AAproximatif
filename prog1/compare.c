#include <stdio.h>
#include <string.h>
int compare(const char * restrict une, const char * restrict deux);

int main(int argc, char const *argv[])
{
    compare(argv[1], argv[2]);
    return 0;
}

int compare(const char * restrict une, const char * restrict deux)
{
    /* stocker les résultats */
    int result;

    /* tableaux pour les données */
    char ex1[50];
    char ex2[50];

    /* on met les str dans les tab */
    strcpy(ex1, une);
    strcpy(ex2, deux);

    /* on compare*/
    result = strcmp(ex1, ex2);

    /* cas identique (osef ça arrivera jamais) */
    if (result == 0) printf("%s = %s\n", deux, une);

    /* la première dans l'ordre alphabétique est la plus petite */
    
    if (result > 0) printf("%s < %s\n", deux, une);

    if (result < 0) printf("%s < %s\n", une, deux);

    return 0;
}