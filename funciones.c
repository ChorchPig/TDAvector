#include <stdio.h>
#include <stdlib.h>
#include "prototipos.h"

matrix* crearMatriz(int filas, int columnas){
    matrix *Matrix=(matrix*)malloc(sizeof(matrix));
    if(!Matrix)return Matrix;
    if(filas==0||columnas==0)return Matrix;
    Matrix->arreglo=(MATRIX_ELEMENT *)malloc(sizeof(MATRIX_ELEMENT *)*filas*columnas);
    if(Matrix->arreglo){
        Matrix->rows=filas;
        Matrix->columns=columnas;
        Matrix->AmountOfElements=0;
    }
    return Matrix;
}

void eliminarMatriz(matrix* Matrix){
    free(Matrix->arreglo);
    free(Matrix);
}

int getMatrixRows(matrix* Matrix){
    return Matrix->rows;
}

int getMatrixColumns(matrix* Matrix){
    return Matrix->columns;
}

int getAmountOfElements(matrix *Matrix){
    return Matrix->AmountOfElements;
}

MATRIX_ELEMENT getValueIn(matrix* Matrix, int row, int column){
    return Matrix->arreglo[row*getMatrixRows(Matrix)+column];
}

void setValueInMatrix(matrix* Matrix, MATRIX_ELEMENT value){
    if(!matrixFull(Matrix)){
        Matrix->arreglo[getAmountOfElements(Matrix)]=value;
        Matrix->AmountOfElements++;
    }
}

int matrixFull(matrix *Matrix){
    if(getMatrixColumns(Matrix)*getMatrixRows(Matrix)==getAmountOfElements(Matrix))return 1;
    return 0;
}

void imprimirMatriz(matrix* Matrix){//void prt(void*), imprime una matriz 3*3 incluso si no hay valores asignados
    int columnas=getMatrixColumns(Matrix), filas=getMatrixRows(Matrix);
    for(int i=0; i<filas; i++){
        for(int j=0; j<columnas; j++)printf("%d ", getValueIn(Matrix, i, j));
        printf("\n");
    }
}

void reemplazarFila(matrix *Matrix, Vector *vector, int fila){//verificar que fila exista dentro de Matrix
    int vectorSize=getCurrentSize(vector);
    if(vectorSize>getMatrixColumns(Matrix))return;
    for(int i=0; i<vectorSize; i++)Matrix->arreglo[fila*getMatrixRows(Matrix)+i]=vector->arreglo[i];
}

void reemplazarColumna(matrix *Matrix, Vector *vector, int columna){//verificar que columna exista dentro de Matrix
    int vectorSize=getCurrentSize(vector);
    if(vectorSize>getMatrixRows(Matrix))return;
    for(int i=0; i<vectorSize; i++)Matrix->arreglo[i*getMatrixRows(Matrix)+columna]=vector->arreglo[i];
}

matrix* sumarDosMatrices(matrix *Matrix1, matrix *Matrix2){//verificar que las dimensiones en las matrices sean iguales
    int filas=getMatrixRows(Matrix1), columnas=getMatrixColumns(Matrix1);
    matrix *resultado=crearMatriz(filas, columnas);
    for(int i=0; i<filas; i++){
        for(int j=0; j<columnas; j++){
            resultado->arreglo[i*filas+j]=sumarDosElementos(getValueIn(Matrix1,i,j), getValueIn(Matrix2,i,j));
        }
    }
    return resultado;
}

void sumarVectorAFilaMatriz(matrix *Matrix, Vector *vector, int fila){//verificar que fila exista dentro de Matrix
    int vectorSize=getCurrentSize(vector);
    if(vectorSize>getMatrixColumns(Matrix))return;
    for(int i=0; i<vectorSize; i++)Matrix->arreglo[fila*getMatrixRows(Matrix)+i]+=vector->arreglo[i];
}

MATRIX_ELEMENT sumarDosElementos(MATRIX_ELEMENT elemento1, MATRIX_ELEMENT elemento2){
    return elemento1+elemento2;
}
