#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <pthread.h>
#include <string.h>

int value1, value2;
pthread_mutex_t mutex;

void * f(void *arg)
{
	while (1)
	{
#ifdef _LOCK_
		pthread_mutex_lock(&mutex);
#endif
		if (value1 != value2)
			printf("%d %d\n", value1, value2);
#ifdef _LOCK_
		pthread_mutex_unlock(&mutex);
#endif
	}
}

int main()
{
	pthread_t thread;
	void *thread_result;
	int count = 0;
	
	if (pthread_mutex_init(&mutex, NULL))
	{
		perror("mutex_init");
		exit(-1);
	}

	if (pthread_create(&thread, NULL, f, NULL) != 0)
	{
		fprintf(stderr, "pthread_create %s\n", strerror(errno));
		exit(-1);
	}

	while (1)
	{
		count++;
#ifdef _LOCK_
		pthread_mutex_lock(&mutex);
#endif
		value1 = count;
		value2 = count;
#ifdef _LOCK_
		pthread_mutex_unlock(&mutex);
#endif
	}


	return 0;
}
