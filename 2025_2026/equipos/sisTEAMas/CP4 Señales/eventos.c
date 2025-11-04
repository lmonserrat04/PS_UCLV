#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

volatile sig_atomic_t tiempo = 0;  // variable global segura para señales

// Manejador único para todas las señales
void manejador(int sig) {
    if (sig == SIGALRM) {
        tiempo++;
        alarm(1);  // reprogramar la alarma para dentro de 1 segundo
    } 
    else if (sig == SIGUSR1) {
        tiempo = 0;
        printf("\n[Señal SIGUSR1 recibida] Contador reiniciado a 0\n");
    } 
    else if (sig == SIGUSR2) {
        printf("\n[Señal SIGUSR2 recibida] Tiempo actual: %d segundos\n", tiempo);
    }
}

int main() {
    // Asignar el mismo manejador a todas las señales usadas
    signal(SIGALRM, manejador);
    signal(SIGUSR1, manejador);
    signal(SIGUSR2, manejador);

    alarm(1);  // activar la primera alarma

    printf("PID del proceso: %d\n", getpid());
    printf("Envía señales con:\n");
    printf("  kill -USR1 %d  -> Reiniciar contador\n", getpid());
    printf("  kill -USR2 %d  -> Mostrar contador\n\n", getpid());

    // Bucle infinito
    while (1) {
        pause(); // Esperar señales
    }

    return 0;
}
