//
// Created by Faisal Alam on 24-03-2018.
//

/**
 * Creation of Zombie Process.
 *
 * A zombie process that has completed execution via the exit system call, but still has an entry in the process table.
 * In other words, a zombie process is a child process whose parent has died before the child finishes its execution.
 * So, we create two child processes and makes the parent sleep for 30 seconds (and not wait for the child).
 * Thus the child process becomes a zombie process.
 */

#include "incall.h"

int main() {
    pid_t p[2];
    int i;

    for (i = 0; i < 2; ++i) {
        p[i] = fork(); // Create two processes.

        if (p[i] == 0)
        {
            printf("Child process having PID %d.\n", getpid());
            exit(EXIT_SUCCESS); // Let the child process exit quickly.
        }
        else if (p[i] > 0)
        {
            printf("Parent process having PID: %d.\n", getpid());
        }
        else
        {
            perror("Fork failed!\n");
            exit(EXIT_FAILURE);
        }
    }

    sleep(30); // Let parent sleep for 30 seconds and exit.

    return 0;
}
