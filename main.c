#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid = fork(); // Creamos un proceso hijo

    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    } else if (pid == 0) {
        // Este es el proceso hijo
        printf("Soy el proceso hijo (PID: %d)\n", getpid());

        // Inicializar un comando en el proceso hijo
        char *args[] = {"ls", "-l", NULL}; // Comando y argumentos
        execvp("ls", args);

        // En caso de que execvp falle
        perror("execvp failed");
        exit(1);
    } else {
        // Este es el proceso padre
        printf("Finalizo el proceso padre (PID: %d)\n", getpid());

        // Esperamos a que el proceso hijo termine
        int status;
    }

    return 0;
}