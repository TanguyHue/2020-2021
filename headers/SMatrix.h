struct SMatrix;
typedef struct SMatrix SMatrix;

SMatrix* MatrixFileInit(char*);
void MatrixPrint(SMatrix*);
void MatrixFileUninit(SMatrix*);