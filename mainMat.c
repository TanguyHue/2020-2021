#include "headers/SMatrix.h"

int main(int argc, char* argv){
    SMatrix* mat = MatrixFileInit("links.txt");
    MatrixPrint(mat);
}