#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
#include <time.h>
int main()
{
    srand(time(NULL));
    pid_t pid = fork();

    if (pid < 0)
    {
        perror("fork");
        return 1;
    }
    if (pid == 0)
    {
        //dormir tiempo aleatorio entre 1 y 8 para ver ambos comportamientos
        sleep(rand()%8+1);
    }
    else
    {
        int status;
        int a;
        sleep(4);
        a = waitpid(pid, &status, WNOHANG);
        if (a == 0) // si a es 0 el hijo no ha terminado
        {
            printf("TE MATO POR LENTO\n");
            kill(pid, SIGKILL);
            waitpid(pid, &status, 0);
        }
        else
        {
            printf("ANDAS RAPIDO , MENOS MAL\n");
        }
    }
    return 0;
}