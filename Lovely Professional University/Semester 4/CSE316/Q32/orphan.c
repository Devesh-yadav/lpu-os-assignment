//
// Created by root on 14/4/18.
//

#include "incall.h"

int main() {
    pid_t p[2];
    int i;

    for (i = 0; i < 2; ++i) {
        p[i] = fork();

        if (p[i] < 0)
        {
            perror("Fork failed!\n");
            exit(EXIT_FAILURE);
        }
        else if (p[i] == 0)
        {
            // Child process.

            printf("Child process having PID %d.\n", getpid());
            sleep(30); // Let the child process sleep for 30 seconds.
            exit(EXIT_SUCCESS);
        }
    }

    exit(EXIT_SUCCESS); // Let the parent process exit.

    return 0;
}