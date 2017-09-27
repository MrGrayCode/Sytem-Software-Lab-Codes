#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>

#define n 5

/*
*	0 -> Thinking
*	1 -> Hungry
*	2 -> Eating
*/


sem_t S[n];
sem_t mutex;
int state[n];

void printState()
{
	for(int i=0;i<n;i++)
	{
		if(state[i] == 0)
		{
			printf("| Philosopher %d is Thinking |",i+1);
		}
		else if(state[i] == 1)
		{
			printf("| Philosopher %d is Hungry |",i+1);
		}
		else if(state[i] == 2)
		{
			printf("| Philosopher %d is Eating |",i+1);
		}
		else
		{
			printf("EE");
		}
	}
	printf("\n");
}

void test(int pno)
{
	int left = (pno+n-1)%n;
	int right = (pno+1)%n;
	if(state[left]!= 2 && state[pno]==1 && state[right]!=2)
	{
		state[pno] = 2;
		//printf("| Philosopher %d is Eating |",(pno+1));
		printState();
		//sem_post(&S[pno]);
	}
}

void pickup(int pno)
{
	sem_wait(&mutex);
	state[pno] = 1;
	//printf("| Philosopher %d is Hungry |",(pno+1));
	printState();
	test(pno);
	sem_post(&mutex);
	/*if(state[pno]!=2)
	{
		sem_wait(&S[pno]);
	}*/
}

void putdown(int pno)
{
	sem_wait(&mutex);
	state[pno] = 0;
	//printf("| Philosopher %d is Thinking |",(pno+1));
	printState();
	int left = (pno + n-1)%n;
	int right = (pno + 1)%n;
	test(left);
	test(right);
	sem_post(&mutex);
}


void* philospher(void *pno)
{
		int *i = pno;
		//sleep(1);
		pickup(*i);
		//sleep(2);
		putdown(*i);
}

int main()
{
	printf("n = %d\n",n);
	
	int pnum[n];
	for(int i=0;i<n;i++)
	{
		pnum[i] = i;
	}
	
	//thread array for each philosopher
	pthread_t threads[n];
	
	// create a mutex lock
	sem_init(&mutex,0,1);
	
	// create semaphore for each process
	sem_t S[n];
	for(int i=0;i<n;i++)
	{
		sem_init(&S[i],0,0);
	}
	
	// start threads for each philosopher
	for(int i=0;i<n;i++)
    {
        pthread_create(&threads[i],NULL,philospher,&pnum[i]);
    }
    
    // join the threads together
    for(int i=0;i<n;i++)
    {
    	pthread_join(threads[i],NULL);
    }
	
	return 0;
}
