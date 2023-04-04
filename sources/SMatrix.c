#include "../headers/SMatrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct SMatrix{
    char* nom;
    int taille;
    int** matrice;
};

SMatrix* MatrixFileInit(char* nom){
    SMatrix* mat = (SMatrix*)malloc(sizeof(SMatrix));
    mat->nom = (char*)malloc(sizeof(char) * strlen(nom));
    strcpy(mat->nom, nom);
    FILE* file;
    if((file = fopen(nom, "r")) == NULL){
        perror("Erreur d'ouverture de fichier\n");
    }

    char buffer[10];

    fgets(buffer, 10, file);
    mat->taille = atoi(buffer);
    char buf[3 * mat->taille + 2];
    int n = 0;
    mat->matrice = (int**)malloc(mat->taille * sizeof(int*));
    for(int i = 0; i < mat->taille; i++){
        mat->matrice[i] = (int*)malloc(mat->taille * sizeof(int*));
    }
    for(int i = 0; i < mat->taille; i++){
        fgets(buf, 3 * mat->taille, file);
    
        
        while(buf[n] != buf[n+1] && n < strlen(buf) - 2){
            mat->matrice[i][n/2] = buf[n] - '0';
            n += 2;
        }

        if(n != mat->taille * 2){
            perror("Manque de colonne\n");
        }
        n = 0;
        if(feof(file)){
            perror("Manque de ligne\n");
        }
    }

    return mat;
}

void MatrixPrint(SMatrix* mat){
    for(int i = 0; i < mat->taille; i++){
        for(int j = 0; j < mat->taille; j++){
            printf("%d ", mat->matrice[i][j]);
        }
        printf("\n");
    }
}

void MatrixFileUninit(SMatrix* mat){
    for(int i = 0; i < mat->taille; i++){
        free(mat->matrice[i]);
    }
    free(mat->matrice);
    free(mat->nom);
    free(mat);
}