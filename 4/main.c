#include <stdio.h>
#include <time.h>
#include <sync.h>
#include <sys/neutrino.h>

barrier_t barrier;

	void *thread1(void *not_used)
	{
    time_t now;
    char buf[27];
    time(&now);
    printf("Potok #1, start time %s \n", ctime_r(&now, buf));
printf("Harina Natalia \n");
    sleep(3);
	barrier_wait(&barrier);
	time(&now);
	printf("V potoke #1, time %s \n", ctime_r(&now, buf));
return NULL;
	}

	void *thread2(void *not_used)
	{
    time_t now;
    char buf[27];
    time(&now);
    printf("Potok #2, start time %s \n", ctime_r(&now, buf));
printf("I993\n"); 
   sleep(6);
	barrier_wait(&barrier);
	time(&now);
	printf("V potoke #2, time %s \n", ctime_r(&now, buf));
return NULL;
	}

	int main()
	{
	time_t now;
    char buf[27];
	barrier_init(&barrier, NULL, 3);
    printf("Start:\n");
    pthread_create(NULL, NULL, thread1, NULL);
    pthread_create(NULL, NULL, thread2, NULL);
    time(&now);
    printf("Main(): oshidanie y bariera, time %s \n", ctime_r(&now, buf));
	barrier_wait(&barrier);
	time(&now);
	printf("barier v main(), time %s \n", ctime_r(&now, buf));
    sleep(5);
return 0;
	}
