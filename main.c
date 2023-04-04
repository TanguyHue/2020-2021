#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void conjugue(char*);
char* concat(char*, char*);
void trim(char*);
int exists(char*, char*);

int main(int argc, char* argv[]){
    conjugue("jouer");
    printf("%s\n", concat("Salut tu vas", "bien ?"));
    char c[20];
    strcpy(c, "    saluut   \0");
    trim(c);
    printf("%s\n", c);
    printf("%d\n", exists("Chaine dans le texte", "dans"));
    return EXIT_SUCCESS;
}

void conjugue(char* verbe){
    if(verbe[strlen(verbe)-2] == 'e' && verbe[strlen(verbe)-1] == 'r'){
        int taille = strlen(verbe);
        char conj[taille+1];
        strcpy(conj, verbe);

        // 1ere personne du singulier
        conj[taille-1] = '\0';
        printf("Je %s\n", conj);

        // 2e personne du singulier
        conj[taille-1] = 's';
        printf("Tu %s\n", conj);

        // 3e personne du singulier
        conj[taille-1] = '\0';
        printf("Il, elle, on %s\n", conj);

        // 1e du pluriel
        conj[taille-2] = 'o';
        conj[taille-1] = 'n';
        conj[taille] = 's';
        printf("Nous %s\n", conj);

        // 2e du pluriel
        conj[taille-2] = 'e';
        conj[taille-1] = 'z';
        conj[taille] = '\0';
        printf("Vous %s\n", conj);

        // 3e du pluriel
        conj[taille-2] = 'e';
        conj[taille-1] = 'n';
        conj[taille] = 't';
        printf("Ils, elles %s\n", conj);

    } else {
        printf("Le verbe n'est pas du premier groupe\n");
    }
}

char* concat(char* c1, char* c2){
    char* retour = (char *)malloc(sizeof(char) * 
        (strlen(c1) / 2 + strlen(c2) / 2 + 1));

    for(int i = 0; i < strlen(c1) / 2; i++){
        retour[i] = c1[i];
    }

    for(int i = 0; i < strlen(c2) / 2; i++){
        retour[i + strlen(c1) / 2] = c2[strlen(c2) / 2 + i];
    }

    retour[strlen(c1) / 2 + strlen(c2) / 2 + 1] = '\0';

    return retour;
}

void trim(char* c){
    int n = 0;
    char copie[strlen(c)];
    for(int i = 0; i < strlen(c); i++){
        if(c[i] == ' ' || c[i] == '\n'){
            n++;
        } else {
            i = strlen(c);
        }
    }

    int m = strlen(c);
    for(int i = strlen(c); i > 0; i--){
        if(c[i-1] == ' ' || c[i-1] == '\n'){
            m--;
        } else {
            i = 0;
        }
    }

    
    strncpy(copie, c + n * sizeof(char), m - n);
    strcpy(c, copie);
}

int exists(char* c1, char* c2){
    int i = 0;
    int j = 0;
    int k = 0;
    int retour = -1;

    while(c1[i] != '\0'){
        if(c1[i] == c2[j]){
            k = i;
            while (c1[k] == c2[j])
            {
                if(c2[j+1] == '\0'){
                    retour = i;
                    break;
                } else if (c1[k+1] == '\0'){
                    break;
                }
                k++;
                j++;
            }
            j = 0;
        }
        i++; 
    }

    return retour;
}