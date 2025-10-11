#include "vectors.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    size_t n = 5;
    srand(time(NULL));  // Inicializar semilla para números aleatorios

    // Inicializar vectores
    Vector *v1 = new_rvector(n);
    Vector *v2 = new_svector(n, 3.0);
    Vector *v3 = new_vector(n);

    // Mostrar vectores
    printf("Vector 1 (aleatorio): ");
    print_vector(v1);

    printf("Vector 2 (constante 3.0): ");
    print_vector(v2);

    // Sumar vectores
    v3 = (Vector *)sum_vectors(v1, v2);
    printf("Suma (v1 + v2): ");
    print_vector(v3);

    // Restar vectores
    v3 = (Vector *)sub_vectors(v1, v2);
    printf("Resta (v1 - v2): ");
    print_vector(v3);

    // Norma y media de v1
    printf("Norma de v1: %.2f\n", norm_vector(v1));
    printf("Media de v1: %.2f\n", ave_vector(v1));

    // Liberar memoria
    free_vector(v1);
    free_vector(v2);
    free_vector(v3);

    return 0;
}