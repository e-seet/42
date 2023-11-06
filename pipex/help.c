
//read
// const char *filename = "example.txt";
// int file_descriptor;
// Open the file for reading (O_RDONLY) - returns a file descriptor
// file_descriptor = open(filename, O_RDONLY);

//strerror
//Simulate an error by trying to open a non-existent file
// #include <stdio.h>
// #include <string.h>
// #include <errno.h>
// int main() {
//     // Simulate an error by trying to open a non-existent file
//     FILE *file = fopen("nonexistent_file.txt", "r");
//     if (file == NULL) {
//         // Print the error message using strerror
//         printf("Error code: %d\n", errno);
//         printf("Error message: %s\n", strerror(errno));
//     } else {
//         fclose(file);
//     }
//     return 0;
// }

//access
// int access(const char *pathname, int mode);
#include <stdio.h>
#include <unistd.h>
#include <errno.h>

// F_OK: Checks if the file exists.
// R_OK: Checks if the file is readable.
// W_OK: Checks if the file is writable.
// X_OK: Checks if the file is executable (for directories, it checks if it can be searched).
// int main() {
//     const char *filename = "example.txt";

//     if (access(filename, F_OK) == 0) {
//         printf("%s exists.\n", filename);

//         if (access(filename, R_OK) == 0) {
//             printf("%s is readable.\n", filename);
//         } else {
//             perror("Error: Cannot read the file");
//         }
//     } else {
//         perror("Error: File does not exist");
//     }
//     return 0;
// }

//dup
// int dup(int oldfd);
// #include <stdio.h>
// #include <unistd.h>
// #include <fcntl.h>
// #include <errno.h>

// int main() {
//     int file_descriptor = open("example.txt", O_RDONLY);
//     if (file_descriptor == -1) {
//         perror("Error opening file");
//         return 1; // Handle the error appropriately
//     }
//     // Duplicate the file descriptor **
//     int duplicate_fd = dup(file_descriptor);
//     if (duplicate_fd == -1) {
//         perror("Error duplicating file descriptor");
//         close(file_descriptor);
//         return 1; // Handle the error appropriately
//     }
//     // Close the original file descriptor
//     // close(file_descriptor);
//     // Close the duplicated file descriptor when done
//     // close(duplicate_fd);
//     return 0;
// }

// int dup2(int oldfd, int newfd);
// #include <stdio.h>
// #include <unistd.h>
// #include <fcntl.h>
// #include <errno.h>
// int main() {
//     int file_descriptor = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
//     if (file_descriptor == -1) {
//         perror("Error opening file");
//         return 1; // Handle the error appropriately
//     }
//     // Use dup2 to redirect standard output (STDOUT_FILENO) to the file descriptor
//     if (dup2(file_descriptor, STDOUT_FILENO) == -1) {
//         perror("Error redirecting standard output");
//         close(file_descriptor);
//         return 1; // Handle the error appropriately
//     }333
//     // Now, anything written to stdout will be redirected to "output.txt"
//     // Example output
//     printf("This will be written to output.txt\n");
//     // Close the redirected file descriptor
//     close(file_descriptor);
//     return 0;
// }

// execve
// int execve(const char *pathname, char *const argv[], char *const envp[]);

// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>
// #include <sys/types.h>
// #include <sys/wait.h>

// int main() {
//     char *const argv[] = {"ls", "-l", NULL};  // Command-line arguments
//     char *const envp[] = {NULL};              // Environment variables

//     // Attempt to execute the "ls" command with the given arguments
//     if (execve("/bin/ls", argv, envp) == -1) {
//         perror("execve");
//         return 1; // Handle the error appropriately
//     }

//     // This code will not be reached if execve is successful

//     return 0;
// }

// //fork
// #include <unistd.h>
// pid_t fork(void);
// #include <stdio.h>
// #include <unistd.h>

// int main() {
//     pid_t child_pid = fork();

//     if (child_pid == -1) {
//         perror("fork");
//         return 1;
//     }

//     if (child_pid == 0) {
//         // This code is executed by the child process
//         printf("Child process (PID %d)\n", getpid());
//     } else {
//         // This code is executed by the parent process
//         printf("Parent process (PID %d) created child process (PID %d)\n", getpid(), child_pid);
//     }

//     return 0;
// }

// //pipe 
// #include <unistd.h>

// int pipe(int pipefd[2]);
// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>

// int main() {
//     int pipefd[2];
//     pid_t child_pid;
//     if (pipe(pipefd) == -1) {
//         perror("pipe");
//         return 1;
//     }
//     child_pid = fork();

//     if (child_pid == -1) {
//         perror("fork");
//         return 1;
//     }
//     if (child_pid == 0) {
//         // Child process writes to the pipe
//         close(pipefd[0]); // Close the read end of the pipe in the child
//         write(pipefd[1], "Hello from child!", 18);
//         close(pipefd[1]);
//     } else {
//         // Parent process reads from the pipe
//         close(pipefd[1]); // Close the write end of the pipe in the parent
//         char buffer[50];
//         read(pipefd[0], buffer, sizeof(buffer));
//         close(pipefd[0]);
//         printf("Parent received: %s\n", buffer);
//     }
//     return 0;
// }

//unlink
// #include <unistd.h>
// int unlink(const char *pathname);

// #include <stdio.h>
// #include <unistd.h>
// #include <errno.h>

// int main() {
//     const char *filename = "example.txt";
//     // Attempt to unlink (delete) the file
//     if (unlink(filename) == -1) {
//         perror("Error unlinking file");
//         return 1; // Handle the error appropriately
//     } else {
//         printf("File '%s' successfully unlinked.\n", filename);
//     }
//     return 0;
// }

//wait
// #include <stdio.h>
// #include <sys/types.h>
// #include <sys/wait.h>
// #include <unistd.h>

// int main() {
//     pid_t child_pid, terminated_child_pid;
//     int status;

//     child_pid = fork();
//     if (child_pid == -1) {
//         perror("fork");
//         return 1;
//     }

//     if (child_pid == 0) {
//         // This code is executed by the child process
//         printf("Child process (PID %d) is running.\n", getpid());
//         sleep(2);  // Simulate some work in the child process
//         return 42; // Child process exits with status 42
//     } else {
//         // This code is executed by the parent process
//         printf("Parent process (PID %d) waiting for child (PID %d) to terminate.\n", getpid(), child_pid);
//         terminated_child_pid = wait(&status);

//         if (terminated_child_pid == -1) {
//             perror("wait");
//             return 1;
//         }

//         printf("Child process (PID %d) has terminated with status %d.\n", terminated_child_pid, WEXITSTATUS(status));
//     }

//     return 0;
// }


//waitpid
// #include <stdio.h>
// #include <stdlib.h>
// #include <sys/types.h>
// #include <sys/wait.h>
// #include <unistd.h>

// int main() {
//     pid_t child_pid, wpid;
//     int status;

//     // Fork a child process
//     child_pid = fork();

//     if (child_pid == -1) {
//         perror("Fork failed");
//         exit(1);
//     }

//     if (child_pid == 0) {
//         // This code runs in the child process
//         printf("Child process is running\n");
//         sleep(2); // Simulate some work in the child process
//         printf("Child process is done\n");
//         exit(0);
//     } else {
//         // This code runs in the parent process
//         printf("Parent process is waiting for the child to finish...\n");

//         // Use waitpid to wait for the specific child process
//         wpid = waitpid(child_pid, &status, 0);

//         if (wpid == -1) {
//             perror("Waitpid failed");
//             exit(1);
//         }

//         if (WIFEXITED(status)) {
//             int exit_status = WEXITSTATUS(status);
//             printf("Child process with PID %d exited with status %d\n", (int)wpid, exit_status);
//         } else {
//             printf("Child process with PID %d did not exit normally\n", (int)wpid);
//         }

//         printf("Parent process is done\n");
//     }

//     return 0;
// }



//nede to fork process
// child process will be replaced by the succesfully invoked command
#include <errno.h>

int main(void)
{
	int p1 = getpid();
	// printf("p1:%d\n", p1);
	int id = fork();

	if (id == 0)
	{
		printf("child id:%d, pid:%d\n", id, getpid());

	}
	else
	{
		printf("parent pid:%d\n ", getpid());
	}

	getpid();
	getppid();

	return 0;
}

//zombie process: when parent get terminated before child

//wait(NULL): will make parent wait for 1 child.
// int id = fork();
// if (id ==0)
// 	sleep(1);
// if (wait(null) == -1) 
// 	printf("no children to wait for")
//else
	// printf("finished execution")


// while (wait(NULL) != -1 || errno != ECHILD)
	// printf("wait for child to finish")


// pipe between process
//https://www.youtube.com/watch?v=Mqb2dVRe0uo&list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY&index=6

int main(void)
{
	int fd[2];
	//fd[0] - read
	//fd[1] - write
	if(pipe(fd) == -1)
		return 1;
	//fork after creating pipe
	int id = fork();
	if (id == -1)
	{
		printf("error in fork\n");
		return 4;
	}

	if (id == 0)
	{
		close(fd[0]); //cause we not using the read of the process.
		//child process
		int x;
		printf("input num");
		scanf("%d", &x);
		if( write(fd[1], &x, sizeof(int)) == -1)
		{
			printf("error writing to pipe\n");
			return 2;
		}
		close(fd[1]);
	}
	else
	{
		close(fd[1]);
		int y;
		if (read(fd[0], &y, sizeof(int)) == -1)
		{
			printf("error reading from pipe\n");
			return 3;
		}
		y = y*3;
		close(fd[0]);
	}
}

int main2(void)
{
	int arr[] = {1,2,3,4,1,2,7};
	int arrSize = sizeof(arr) / sizeof(int);
	int start, end;
	int fd[2];

 	if(pipe(fd)== -1)
	{
		return 1;
	}

	int id = fork();
	if(id == -1)
	{
		return 2;
	}

	if(id == 0)
	{
		start = 0;
		end =  arrSize/2; //first 3. Summed by child
	}
	else
	{
		start = arrSize / 2; //last 4. Summed by parent
		end = arrSize;
	}

	int sum = 0;
	int i;
	for(i = start; i < end; i++)
	{
		sum += arr[i];
	}

	printf("Calculated partial sum:%d\n", sum);
	if (id ==0)
	{
		close(fd[0]);
		write(fd[1], &sum, sizeof(int));
		close(fd[1]);
	}
	else
	{
		int sumFromChild;
		close(fd[1]);
		read(fd[0], &sumFromChild, sizeof(sumFromChild));
		close(fd[0]);

		int totalSum = sum + sumFromChild;
		printf("Total sum is %d\n", totalSum);
		wait(NULL);
	}

}


	// dup2(pipex.tube[1], 1); //change stdout to write end
	// // so instead of stdout, it will write to pipe

	// close(pipex.tube[0]); //close the read end of pipe. Make sure does not read
	
	// dup2(pipex.infile, 0); //redirect stdin to fd to infile
	// // so instead of stdin, it will read from infile
