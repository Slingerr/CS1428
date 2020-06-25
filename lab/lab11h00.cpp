//Ian Eslinger
#include <iostream>
#include <stdio.h>
#include <pthread.h>
#include <math.h>
#include <unistd.h>
#define RESOURCE 4000;
#define STARTINGTOTAL 0;

using namespace std;

void *helloWorld(pthread_t *tid);

pthread_mutex_t mutex;
int resource = RESOURCE;
int total_used = STARTINGTOTAL;
int result_printed = STARTINGTOTAL;
pthread_t tidA, tidB, tidC;

int main()
{
  // allow 3 threads to work at the same time
  pthread_setconcurrency(3);

  // create three threads
  pthread_create(&tidA, NULL, (void*(*)(void*))helloWorld, &tidA); // thread A
  pthread_create(&tidB, NULL, (void*(*)(void*))helloWorld, &tidB); // thread B
  pthread_create(&tidC, NULL, (void*(*)(void*))helloWorld, &tidC); // thread C

  // don't remove this
  pthread_exit(0);

  return 0;

}

void *helloWorld(pthread_t *tid)
{
    // mutex lock
    pthread_mutex_lock(&mutex);
    //display hello world using thread A
    if(pthread_equal(*tid, tidA))
        cout << "Hello from thread A!"<< endl;
    //display hello world using thread B
    if(pthread_equal(*tid, tidB))
        cout << "Hello from thread B! " << endl;
    //display hello world using thread C
    if(pthread_equal(*tid, tidC))
        cout << "Hello from thread C!" << endl;
    // mutex unlock
    pthread_mutex_unlock(&mutex);
  }


