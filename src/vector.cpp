#include "vector.h"

Vector::Vector(int n, double* array){
    this->n = n;
    this->array = new double[this->n];

    for(int i=0; i<this->n; i++){
        this->array[i] = array[i];
    }
}