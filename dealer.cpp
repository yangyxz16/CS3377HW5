#include <stdio.h>
//#include <unistd.h>
#include <getopt.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
//#include <iostream>

void verbose();

int main(int argc, char **argv)
{
	int c;		// Used for getopt().
	int percent;
	int numOfT;	// Number of trails.
	bool verbose = false;

	while ((c = getopt(argc, argv, "p:v")) != -1) {
		switch(c) {
			case 'p': 
				percent = atoi(optarg);
				break;
			case 'v': 
				verbose = true;
				break;
			default:
				fprintf(stderr, "getopt");
		}
	}


	numOfT = atoi(argv[optind]);

	if (percent > 100) {
		fprintf(stderr, "The percentage cannot be larger than 100!\n");
	}
	else {
		printf("%d \n", percent);
	}

	if (numOfT == 0) {
		fprintf(stderr, "The number of trails is invaild!\n");
		exit(-1);
	}
	
	//int n1 = fork();
	//int n2 = fork();
	
	//if(n1 > 0 && n2 > 0) {
		//printf("PID %d\n", getpid());
	


	//pid_t pid;
	//int x = 0;
	//for (int i = 0; i < numOfT; i++) {
	//	pid = fork();
	//	if (pid == 0) {
	//		printf("PID %d\n", getpid());
	//		exit(0);
	//	}
	//	else {
	//		printf("PID %d\n", getpid());
	//		exit(0);
	//	}
	//}

	//printf("Child: x = %d\n", x);
	//printf("Parent: y = %d\n", y);

	int i, stat;
	pid_t pid[numOfT]; 
	for (i=0; i<numOfT; i++) { 
		if ((pid[i] = fork()) == 0) {	// Child process.
			//sleep(1);
			execl("/bin/echo", "echo", "hello!", 0);
			perror("execl() failure!\n");

			exit(100 + i);
		}
		else {				// Parent process.
			wait(&stat);
			printf("PID %d\n", pid[i]);
		}
	} 
									
	if (verbose) {			
	 	for (i=0; i<numOfT; i++) { 
	 		pid_t cpid = waitpid(pid[i], &stat, 0);
			if (WIFEXITED(stat)) {
				printf("PID %d\n", cpid); 
			}
		} 
	}








	return 0;
}

void verbose() {
printf("verbose mode on\n");
}
