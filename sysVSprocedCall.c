#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int procCall()
{
	return 30;
}

int main(int argc, char** argv)
{

	struct timespec t1, t2;
	int j;	

	clock_gettime(CLOCK_REALTIME, &t1);
	j = getpid();
	clock_gettime(CLOCK_REALTIME, &t2);
	printf("Nanosec time sys call: %ld\n", t2.tv_nsec - t1.tv_nsec);

	clock_gettime(CLOCK_REALTIME, &t1);
	j = procCall();
	clock_gettime(CLOCK_REALTIME, &t2);
	printf("Nanosec time proc call: %ld\n", t2.tv_nsec - t1.tv_nsec);

	


	return 0;

}
