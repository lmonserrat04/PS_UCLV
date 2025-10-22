#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

volatile sig_atomic_t error_coma_flotante = 0;

void manejar_error(int senal) {
    error_coma_flotante = 1;
}

int main() {
    double x1, y1, x2, y2;
    double pendiente;
    struct sigaction trat;

    trat.sa_handler = manejar_error;
    trat.sa_flags = 0;
    sigemptyset(&trat.sa_mask);
    sigaction(SIGFPE, &trat, NULL);

    while(1) {
        printf("Ingrese x1 y1 x2 y2: ");
        scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);

        error_coma_flotante = 0;
        pendiente = (y2 - y1) / (x2 - x1);

        if(error_coma_flotante) {
            pendiente = (double)rand() / RAND_MAX * 100.0;
            printf("Pendiente aleatoria generada: %.2f\n", pendiente);
        } else {
            printf("Pendiente calculada: %.2f\n", pendiente);
        }
    }

    return 0;
}