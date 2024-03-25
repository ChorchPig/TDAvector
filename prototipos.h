#ifndef PROTOTIPOS_H_INCLUDED
#define PROTOTIPOS_H_INCLUDED
#define MATRIX_ELEMENT int
#define VECTOR_ELEMENT int

typedef struct{
   MATRIX_ELEMENT* arreglo;
   int rows;
   int columns;
} matrix;

typedef struct{
    VECTOR_ELEMENT *arreglo;
    int maxSize, currentSize;
}Vector;

matrix* crearMatriz(int,int);
void eliminarMatriz(matrix*);
int getMatrizRows(matrix*);
int getMatrizColumns(matrix*);
MATRIX_ELEMENT getValueIn(matrix*,int,int);
void setValueInMatrix(matrix*,int,int,MATRIX_ELEMENT);
void imprimirMatriz(matrix*,void prt(void*));
int matrixLlena(matrix*);

void reemplazarFila(matrix*, Vector*, int fila);
void reemplazarColumna(matrix*, Vector*, int columna);

matrix* sumarDosMatrices(matrix*, matrix*);
MATRIX_ELEMENT sumarDosElementos(MATRIX_ELEMENT, MATRIX_ELEMENT);
void multiplicarDosMatrices(matrix*, matrix*);
void sumarVectorAFilasMatriz(matrix*, Vector*);
void calcularDeterminante(matrix*);
Vector* resolverSistemaEcuaciones(matrix*);

#endif // PROTOTIPOS_H_INCLUDED
