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
	int index;
	while ((c = getopt(argc, argv, "p:v")) != -1) {
		switch(c) {
			case 'p': 
				percent = atoi(optarg);
				printf("%d \n", percent);
				break;
			case 'v': 
				verbose();
				break;
			case '?':
			
				//if (isprint (optopt))
				//	fprintf (stderr, "Unknown option `-%c'.\n", optopt);
				//numOfT = atoi(optarg);
				//printf("%d \n",numOfT);
				//if(optopt = 'p') {
				//	fprintf(stderr, "Option -%c needs argument\n", optopt);
				//} 
				//else {
				//	fprintf(stderr, "Unknow option -%c. \n", optopt);
				//}
				break;
			default:
				fprintf(stderr, "getopt");
		}
	}
	//for (index = optind; index < argc; index++)
	 //   printf ("Non-option argument %s\n", argv[index]);

	numOfT = atoi(argv[optind]);
	printf("The number of trails is %d \n",numOfT);

	return 0;
}

void verbose() {
printf("verbose mode on\n");
}
