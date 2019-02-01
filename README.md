# CS3377UNIX-fork-wait-exec

Creating two programs, Dealer and Hand

-Hand takes a percentage p from the command line, and returns success or failure based on that percentage. If the percentage passed to it is 70, then Hand has a 70% chance of returning success; if it is 20, then Hand has a 20% chance of returning success.

-Dealer takes up to 3 parameters, the same percentage p that will be passed to Hand,
number_of_trials, and an optional -v (verbose). 
Dealer then creates number_of_trials child processes (1 at a time ), 
records the result from each of the children, and prints out the final percentages. 
If verbose mode is selected, it also prints the PID of each of the children as well as the result.

Functions:

1. Dealer uses getopt() to parse up to 3 parameters. <-p percentage>,
<number_of_trials>, and an optional -v flag (for verbose) mode. The -p and –v options will always come before the last value (number_of_trials). The -p option and
number_of_trials are required, the -v option is optional.
(ex. ./dealer -p 70 -v 1000)
(ex. ./dealer -p 20 1000)

2. Dealer will then spawn number_of_trials children and each child will exec Hand, making the argument list passed to Dealer available to Hand. It can spawn no more than 1 processes at a time so that system performance is not degraded.

3. Dealer will wait() on a child to terminate, record the result, print the child’s PID and result if -v is specified, and continue spawning children until it has done the number of trials specified on the command line.

4. Hand uses getopt() to parse the command line options to get percentage and generate a success or failure return code based on percentage passed to it from Dealer.

5. Hand uses a random number generator routine to generate the correct percentage of success and failure return codes. For the RNG, use gsl_rng_mt19937 from the GSL.
