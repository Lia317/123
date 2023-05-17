#include <stdio.h>
#include <pthread.h>
#include <inttypes.h>
#include <errno.h>
#include <sys/neutrino.h>
#include <time.h>

#define SEC_NSEC 1000000000LL

void * long_thread(void *notused)
{

    printf("potok time>10 cek \n");
    sleep(20);
}

int main(void)
{
	printf("Harina Natalia I993\n");
    time_t now;
    char buf[27];

    uint64_t timeout;
    struct sigevent event;
    int rval;
    pthread_t thread_id;
    time(&now);
    printf("prog timer: %s", ctime_r(&now, buf));
    event.sigev_notify = SIGEV_UNBLOCK;
 
    pthread_create(&thread_id, NULL, long_thread, NULL);

    timeout = 10LL*SEC_NSEC;
    TimerTimeout(CLOCK_REALTIME, _NTO_TIMEOUT_JOIN, &event, &timeout, NULL);

    rval = pthread_join(thread_id, NULL);
    if (rval == ETIMEDOUT)
    {
        time(&now);
        printf("istekli 10 sekynd, potok %d vipolniaetsia! %s", thread_id, ctime_r(&now, buf));
    }
    sleep(5);

    TimerTimeout(CLOCK_REALTIME, _NTO_TIMEOUT_JOIN, &event, &timeout, NULL);
    rval = pthread_join(thread_id, NULL);
    if (rval == ETIMEDOUT)
    {
        time(&now);
        printf("potok %d>25 cek! %s", thread_id, ctime_r(&now, buf));
    }
    else
    {
        time(&now);
        printf("potok %d end %s", thread_id, ctime_r(&now, buf));
    }
    return(1);
}




