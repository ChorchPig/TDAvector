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
    }
    return Matrix;
}

void eliminarMatriz(matrix* Matrix){
    free(Matrix->arreglo);
    free(Matrix);
}

int getMatrizRows(matrix* Matrix){
    return Matrix->rows;
}

int getMatrizColumns(matrix* Matrix){
    return Matrix->columns;
}

MATRIX_ELEMENT getValueIn(matrix* Matrix, int row, int column){
    return Matrix->arreglo[row*getMatrizRows(Matrix)+column];
}

void setValueInMatrix(matrix* Matrix, int row, int column, MATRIX_ELEMENT value){
    if(!matrixLlena(Matrix))Matrix->arreglo[row*getMatrizRows(Matrix)+getMatrizColumns(Matrix)]=value;
}

int matrixLlena(matrix *Matrix){
    if(Matrix->arreglo[getMatrizRows(Matrix)+getMatrizColumns(Matrix)])return 1;
    return 0;
}

void imprimirMatriz(matrix* m, void prt(void*)){
    /*** COMPLETAR ***/
}

matrix* sumarDosMatrices(matrix *Matrix1, matrix *Matrix2){
    //verificar que las dimensiones en las raíces sean iguales
    int filas=getMatrizRows(Matrix1), columnas=getMatrizColumns(Matrix1);
    matrix *resultado=crearMatriz(filas, columnas);
    for(int i=0; i<filas; i++){
        for(int j=0; j<columnas; j++){
            resultado->arreglo[i*filas+j]=sumarDosElementos(getValueIn(Matrix1,i,j), getValueIn(Matrix2,i,j));
        }
    }
    return resultado;
}

MATRIX_ELEMENT sumarDosElementos(MATRIX_ELEMENT elemento1, MATRIX_ELEMENT elemento2){
    return elemento1+elemento2;
}
