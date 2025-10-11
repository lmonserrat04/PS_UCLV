#include "vectors.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

Vector *new_vector(int size) {
    if (size <= 0) printf("El tamaño del vector debe ser mayor que 0");
    Vector *vector = (Vector *)malloc(sizeof(Vector));
    if (vector == NULL){
        printf("No se pudo reservar memoria para el vector");
        return NULL;
    }
    vector->values = (double *)malloc(size * sizeof(double));
    if (vector->values == NULL){
        printf("No se pudo reservar memoria para el vector");
        free(vector);
        return NULL;
    }

    vector->size = size;
    return vector;
}

Vector *new_rvector(int size) {
    Vector *vector = new_vector(size);
    if (vector == NULL) {
        printf("No se pudo reservar memoria para el vector");
        return NULL;
    }
    for (int i = 0; i < size; i++) {
        vector->values[i] = (double)rand() / RAND_MAX * 100;
    }
    return vector;
}

Vector *new_svector(int size , double value) {
    Vector *vector = new_vector(size);
    if (vector == NULL) {
        printf("No se pudo reservar memoria para el vector");
        return NULL;
    }
    for (int i = 0; i < size; i++) {
        vector->values[i] = value;
    }
    return vector;
}

double get_value(Vector *v , int index) {
    return v->values[index];
}

Vector *sum_vectors(Vector *v1 , Vector *v2) {
    if (v1->size != v2->size) printf("Los vectores no tienen el mismo tamaño");
    Vector *result = new_vector(v1->size);
    for (int i = 0; i < v1->size; i++) {
        result->values[i] = v1->values[i] + v2->values[i];
    }
    return result;
}

Vector *sub_vectors(Vector *v1 , Vector *v2) {
    if (v1->size != v2->size) printf("Los vectores no tienen el mismo tamaño");
    Vector *result = new_vector(v1->size);
    for (int i = 0; i < v1->size; i++) {
        result->values[i] = v1->values[i] - v2->values[i];
    }
    return result;
}

double norm_vector(Vector *v) {
    int sum = 0;
    for (int i = 0; i < v->size; i++) {
        sum += v->values[i] * v->values[i];
    }
    return sqrt(sum);
}

double ave_vector(Vector *v) {
    double sum = 0;
    for (int i = 0; i < v->size; i++) {
        sum += v->values[i];
    }
    return sum / v->size;
}

void print_vector(Vector *v) {
    for (int i = 0; i < v->size; i++) {
        printf("%f ", v->values[i]);
    }
    printf("\n");
}

void free_vector(Vector *v) {
    if (v->values != NULL){
        free(v->values);
    }
    free(v);
}
