/***********************************************************
*
* keyin: g++ cpp_test3_multithreading.cpp -o test3 -lpthread
*
*PS. Since pthread.h is not Linux default library, 
     we need to connect one by using -lpthread.
************************************************************/

#include<iostream>
#include<pthread.h>
#include<cstdlib>
#include<string>
using namespace std;

#define NUM_THREADS 5

struct thread_data {
	int thread_id;
	string message;
};
void *PrintHello(void *threadarg)
{
	struct thread_data *myData;
	myData = (struct thread_data *) threadarg;
	cout << "Thread ID:"<< myData->thread_id;
	cout << ", Message:"<< myData->message << endl;
//	pthread_exit(NULL);
}

int main()
{
	pthread_t threads[NUM_THREADS];
	struct thread_data td[NUM_THREADS];
	int i;
	
	for(i=0; i<NUM_THREADS; i++){
		cout << "main():creating thread,"<< i << endl;
		td[i].thread_id=i;
		td[i].message = "This is message";
		pthread_create(&threads[i],NULL,PrintHello,(void *)&td[i]);
	}
	pthread_exit(NULL);
	return 0;
}
