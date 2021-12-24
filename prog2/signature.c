#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(int argc, char const *argv[])
{
    


    return 0;
}


char* signature(char* input){
    int i;
    char freq[26];
    int l = strlen(input);
    char signature[l];

    for (i = 0; i < l; i++)
        freq[input[i] - 'A'] += 1;
    for (i = 0; i < 26; i++)
        

}