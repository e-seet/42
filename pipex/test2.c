
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
// #include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    pid_t child_pid, wpid;
    int status;

    // Create a child process
    child_pid = fork();

    if (child_pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (child_pid == 0) {
        // This is the child process
        printf("Child process (PID %d) is running.\n", getpid());
        sleep(2); // Simulate some work
        exit(EXIT_SUCCESS);
    } else {
        // This is the parent process
        printf("Parent process (PID %d) waiting for child (PID %d) to finish...\n", getpid(), child_pid);

        // Wait for the child process to finish
        // wpid = waitpid(child_pid, &status, 0);
        // wpid = waitpid(child_pid);


        if (wpid == -1) {
            perror("waitpid");
            exit(EXIT_FAILURE);
        }

        if (WIFEXITED(status)) {
			printf("the status in int:%d\n\n",status);
            printf("Child process (PID %d) exited with status %d\n", wpid, WEXITSTATUS(status));
        } else if (WIFSIGNALED(status)) {
			printf("the status in int:%d",status);
            printf("Child process (PID %d) terminated by signal %d\n", wpid, WTERMSIG(status));
        }
    }

    return 0;
}
