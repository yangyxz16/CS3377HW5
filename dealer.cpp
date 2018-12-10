#include <stdio.h>
//#include <unistd.h>
#include <getopt.h>
#include <stdlib.h>
//#include <iostream>

void verbose();

int main(int argc, char **argv)
{
	int c;
	int percent;
	int numOfT;	// Number of trails.
	
	while ((c = getopt(argc, argv, "p:v:")) != -1) {
		switch(c) {
			case 'p': 
				percent = atoi(optarg);
				break;
			case 'v': 
				verbose();
				break;
			case '?':
				numOfT = atoi(optarg);
				if(optopt = 'p') {
					fprintf(stderr, "Option -%c needs argument\n", optopt);
				} 
				else {
					fprintf(stderr, "Option -%c needs argument\n", optopt);
				}
			default:
				printf("Error");
		}
	}



	//cout << percent << "\n" << numOfT << endl;
	//printf(percent, "\n", numOfT);


	return 0;
}

void verbose() {
}
