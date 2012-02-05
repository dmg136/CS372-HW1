#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <assert.h>

//function that thread 1 runs
void *thread1(void *number)
{
	int t1;
	int* assignedNum1 = (int*)number;
	for (t1 = 1; t1 <= 10; t1++)
		printf("%d: %d\n", *assignedNum1, t1);

	return NULL;  

}

//function that thread 2 runs
void *thread2(void *number)
{
	int t2;
	int* assignedNum2 = (int*)number;

	for (t2 = 1; t2 <= 10; t2++)
		printf("%d: %d\n", *assignedNum2, t2);
}

//function that thread 3 runs
void *thread3(void *number)
{
	int t3;
	int* assignedNum3 = (int*)number;
	for (t3 = 1; t3 <= 10; t3++)
		printf("%d: %d\n", *assignedNum3, t3);
}

int main()
{
	int ret;
	int num1 = 1;
	int num2 = 2;
	int num3 = 3;

	//create threads and run them
	pthread_t pt1, pt2, pt3;
	ret = pthread_create(&pt1, NULL, thread1, &num1);
	assert(ret == 0); 
	ret = pthread_create(&pt2, NULL, thread2, &num2);
	assert(ret == 0);
	ret = pthread_create(&pt3, NULL, thread3, &num3);
	assert(ret == 0);

	//wait for all threads to finish
	if (pthread_join(pt1, NULL))
	{
		printf("Couldn't create thread 1");
		return 1;
	}

	if (pthread_join(pt2, NULL))
	{
		printf("Couldn't create thread 2");
		return 2;
	}

	if (pthread_join(pt3, NULL))
	{
		printf("Couldn't create thread 3");
		return 3;
	}
}
