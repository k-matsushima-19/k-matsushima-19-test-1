#include "matrix.h"

Matrix::Matrix(int nrow, int ncol){
    this->nrow = nrow;
    this->ncol = ncol;

    this->array = new double[nrow*ncol];
}