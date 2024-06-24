#include "utils.h"

// Handler function 1
// this does not exit minishell.
// just returns to minishell if pressed
// reset my linked list and node if required
void exit_currentprocess(int sig)
{

	printf("\n\nIn exit current process %d\n", sig);
	sigint_received = -1;
	printf("exit current process\n\n");
    // printf("Handler 1: Received SIGINT\n");
    // Handle signal 1
	// printf("sig:%d\n", sig);
	// printf("Does nothing except another line. Here you go!\n");
	
	// do i want this? idk
	sigint_received = 0;
}

void exit_heredoc(int sig)
{
	printf("\n\nsigint -1 in heredoc %d\n", sig);
	sigint_received = -1;
	// printf("exit heredoc signal\n\n");
	(void)sig;
	// return ;
	// rl_replace_line("", 0);
	rl_on_new_line();
	printf("press enter to continue\n");
	// rl_redisplay();
	return ;
}

// test setup
void setsignals(int sig)
{
	// Set up handler 1
	struct sigaction sa1;
	struct sigaction sa2;

	
	// setuo
	if (sig == 0)
	{
		sigint_received = 0;
		printf("set up mini\n");
		// printf("crtl c is clear line\n");
		// printf("crtl d is to core dump\n");

		sa1.sa_handler = exit_currentprocess;
		sigemptyset(&sa1.sa_mask);
		// this is the inital
		sigaction(SIGINT, &sa1, NULL);

		// to do something else
		// do core dump?
		// sa2.sa_handler = exit_currentprocess;
		// sigaction(SIGQUIT, &sa2, NULL);
	}

	// exit current process
	if (sig == 1)
	{
		sa1.sa_flags = 0;
		sa2.sa_flags = 0;
		printf("inside mini signal\n");
		// printf("crtl c is clear line\n");
		// printf("crtl d is to core dump\n");

		sa1.sa_handler = exit_currentprocess;
		sigemptyset(&sa1.sa_mask);
		// this is the inital
		sigaction(SIGINT, &sa1, NULL);

		// to do something else
		// do core dump?
		// sa2.sa_handler = exit_currentprocess;
		// sigaction(SIGQUIT, &sa2, NULL);
	}
	else if (sig == 2)
	{
		sa1.sa_flags = 0;
		sa2.sa_flags = 0;
		printf("inside heredoc signal");
		// printf("crtl c is exit heredoc and return to the process\n");
		// sigint_received = -1;
		// printf("crtl d is to core dump\n");


		sa1.sa_handler = exit_heredoc;
		sigemptyset(&sa1.sa_mask);
		// this is the inital
		sigaction(SIGINT, &sa1, NULL);


		// sigaction(SIGINT, &sa2, NULL);
		// sigaction(SIGQUIT, &sa2, NULL);
	}
	// else if (sig == 3)
	// {
	// 	printf("inside child proc");
	// 	// sigaction(SIGINT, &sa2, NULL);
	// 	// sigaction(SIGQUIT, &sa2, NULL);
	// }


	// older version. Dont use
	// signal(SIGINT, exit_currentprocess);
}

// Handler function 2
// this is to exit the heredoc process
// breaks from heredoc
// reset linked list and ast node
// void exit_heredoc(int sig)
// {
//     printf("Handler 2: Received SIGINT\n");
//     // Handle signal 2
// 	printf("sig:%d\n", sig);
// 	printf("to do\n");
// 	printf("1. Reset node and linked list\n");
	
// 	printf("exitted from heredoc\n");
// }

// Handler function 3
// this is to exit child process
// reset linked list and ast node
// void exit_childprocess(int sig, siginfo_t *info, void *context)
// {
//     printf("Handler 3: Received SIGINT\n");
//     // Handle signal 3
// 	printf("sig:%d\n", sig);
// 	printf("to do\n");
// 	printf("exitted from heredoc\n");
// }

// void setup_signal1()
// {
// 	struct sigaction sa1;
// 	// Set up handler 1
//     // sa1.sa_handler = exit_childprocess;
//     sa1.sa_handler = exit_currentprocess;
//     sa1.sa_flags = 0;
//     sigemptyset(&sa1.sa_mask);
// 	// this is the inital
//     sigaction(SIGINT, &sa1, NULL);
// }


// kill the current process
// kill(getpid(), SIGINT)

// int sighandler(const int signal, void *ptr)
// {
//   static my_struct saved = NULL;

//   if (saved == NULL)
//      saved = ptr;
// //   if (signal == signal)
  
//      // DO YOUR STUFF OR FREE YOUR PTR
//    return (0);
// }

// void setup_signal4()
// {
//     struct sigaction sa1;
// 	// Set up handler 1
//     sa1.sa_handler = exit_currentprocess;
//     sa1.sa_flags = 0;
//     sigemptyset(&sa1.sa_mask);

// 	// Enable passing additional info
// 	sa1.sa_flags = SA_SIGINFO;

// 	// this is the inital
//     // this is what switches it
// 	// sigaction(SIGINT, &sa1, NULL);
// 	signal(SIGINT, (void (*)(int))sighandler);

// }

// void setup_signal2()
// {
// 	struct sigaction sa2;
// 	// Set up handler 1
//     sa2.sa_handler = exit_heredoc;
//     sa2.sa_flags = 0;
//     sigemptyset(&sa2.sa_mask);
// 	// this is the inital
//     sigaction(SIGINT, &sa2, NULL);
// }

// void setup_signal3()
// {
// 	struct sigaction sa3;
// 	// Set up handler 1
//     sa3.sa_handler = exit_childprocess;
//     sa3.sa_flags = 0;
//     sigemptyset(&sa3.sa_mask);
// 	// this is the inital
//     sigaction(SIGINT, &sa3, NULL);
// }

// void setup_signal(
//     struct sigaction *sa1,
//     struct sigaction *sa2,
//     // struct sigaction *sa3
// )
// {
// 	// Set up handler 1
//     sa1->sa_handler = exit_currentprocess;
//     sa1->sa_flags = 0;
//     sigemptyset(&sa1->sa_mask);
// 	// this is the inital
//     // sigaction(SIGINT, &sa1, NULL);

//     // Set up handler 2
//     sa2->sa_handler = exit_heredoc;
//     sa2->sa_flags = 0;
//     sigemptyset(&sa2->sa_mask);

//     // Set up handler 3
//     // sa3->sa_handler = exit_childprocess;
//     // sa3->sa_flags = 0;
//     // sigemptyset(&sa3->sa_mask);
// }

// how to do signal?
// 1 either i have a flag to help manage
// 2 i have static varaible 
// 
