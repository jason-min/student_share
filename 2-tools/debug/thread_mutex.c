#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <pthread.h>
#include <string.h>

int value1, value2;
pthread_mutex_t mutex1, mutex2;

void * thread_routine1(void *arg)
{
	pthread_mutex_lock(&mutex1);
	printf("pthread_rountine1: after request mutex1! \n");
	sleep(5);
	pthread_mutex_lock(&mutex2);
	printf("pthread_rountine1: after request mutex2! \n");
	pthread_mutex_unlock(&mutex2);
	pthread_mutex_unlock(&mutex1);
}

void * thread_routine2(void *arg)
{ pthread_mutex_lock(&mutex2);
	printf("pthread_rountine2: after request mutex2! \n");
	sleep(2);
	pthread_mutex_lock(&mutex1);
	printf("pthread_rountine2: after request mutex2! \n");
	pthread_mutex_unlock(&mutex1);
	pthread_mutex_unlock(&mutex2);
}

int main()
{
	pthread_t thread1, thread2;
//	void *thread_result;
	
	if (pthread_mutex_init(&mutex1, NULL)) {
		perror("mutex_init");
		exit(-1);
	}

	if (pthread_mutex_init(&mutex2, NULL)) {
		perror("mutex_init");
		exit(-1);
	}
	if (pthread_create(&thread1, NULL, thread_routine1, NULL) != 0) {
		fprintf(stderr, "pthread_create %s\n", strerror(errno));
		exit(-1);
	}

	if (pthread_create(&thread2, NULL, thread_routine2, NULL) != 0) {
		fprintf(stderr, "pthread_create %s\n", strerror(errno));
		exit(-1);
	}

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	return 0;
}
