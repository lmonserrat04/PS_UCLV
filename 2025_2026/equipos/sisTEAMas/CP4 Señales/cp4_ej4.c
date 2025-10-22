int recibido = 0;
void trat_sigusr(int signum){
    recibido = 1;
}

main(int argc, char *argv[]) {
    int nhips, mipid;
    int ret, i;
    char buf[80];
    struct sigaction trat;

    trat.sa_handler = trat_sigusr;
    trat.sa_flags = 0;
    sigemptyset(&trat.sa_mask);
    sigaction(SIGUSR1, &trat, NULL);

    nhips = atoi(argv[1]);
    mipid = getpid();
    for (i=0; i<nhips; i++) {
        ret = fork();
        if (ret > 0){
            if (mipid != getpid()) {
                while(!recibido) ;
            }
            kill(ret, SIGUSR1);
            waitpid(-1, NULL, 0);
            sleep(3);  // Linea añadida espera 3 seg antes de crear el siguiente proceso
            sprintf(buf, "Soy el proceso %d y acabo la ejecución\n",getpid());
            write(1,buf,strlen(buf));
            exit(0);
        }
    }
    sprintf(buf, "Soy el proceso %d y acabo la ejecución\n",getpid());
    write(1,buf,strlen(buf));
}