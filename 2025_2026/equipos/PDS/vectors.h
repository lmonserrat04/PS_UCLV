#ifndef VECTORES_H
#define VECTORES_H

typedef struct {
    double *values;
    int size;
} Vector;

Vector *new_vector(int size);
Vector *new_rvector(int size);
Vector *new_svector(int size , double value);
double get_value(Vector *v , int index);
Vector *sum_vectors(Vector *v1 , Vector *v2);
Vector *sub_vectors(Vector *v1 , Vector *v2);
double norm_vector(Vector *v);
double ave_vector(Vector *v);
void print_vector(Vector *v);
void free_vector(Vector *v);

#endif

