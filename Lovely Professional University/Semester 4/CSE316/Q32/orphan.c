//
// Created by root on 14/4/18.
//

#include "incall.h"

int main() {
    pid_t p;
    int i;

    for (i = 0; i < 2; ++i) {
        p = fork();

        if (p < 0)
        {
            perror("Fork failed!\n");
            exit(EXIT_FAILURE);
        }
        else if (p == 0)
        {
            // Child process.

            printf("Child process having PID %d.\n", getpid());
            sleep(30); // Let the child process sleep for 30 seconds.
            exit(EXIT_SUCCESS); // Let the child exit.
        }
    }

    /**
     * The parent process will exit immediately.
     */
    exit(EXIT_SUCCESS);
}
