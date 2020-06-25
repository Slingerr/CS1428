//Ian Eslinger
#include <iostream>
#include <stdio.h>
#include <pthread.h>
#include <math.h>
#include <unistd.h>

using namespace std;


void *millionLoop(pthread_t *tid);

pthread_mutex_t mutex;
pthread_t tidA, tidB, tidC;


int main()
{
  // allow 3 threads to work at the same time
  pthread_setconcurrency(3);

  // create three threads
  pthread_create(&tidA, NULL, (void*(*)(void*))millionLoop, &tidA); // thread A
  pthread_create(&tidB, NULL, (void*(*)(void*))millionLoop, &tidB); // thread B
  pthread_create(&tidC, NULL, (void*(*)(void*))millionLoop, &tidC); // thread C

  // don't remove this
  pthread_exit(0);

  return 0;
}

  void *millionLoop(pthread_t *tid)
{
    int x = 0;

    while( x < 1000000)
  {
    // mutex lock
    pthread_mutex_lock(&mutex);

    //add 100,000 with thread A
    if(pthread_equal(*tid, tidA))
        {
        x += 100000;
        cout << "Thanks to Thread A the value is now " << x << endl;
        }
    //add 100,000 with thread B
    if(pthread_equal(*tid, tidB))
       {
        x += 100000;
        cout << "Thanks to Thread B the value is now " << x << endl;
       }
    //add 100,000 with thread C
    if(pthread_equal(*tid, tidC))
        {
        x += 100000;
        cout << "Thanks to Thread C the value is now " << x << endl;
        }
    // mutex unlock
    pthread_mutex_unlock(&mutex);
  }
  //when X is equal to 1,000,000 notify the user
  if(x == 1000000)
  {
      cout << "X has achieved the value of 1,000,000" << endl;
  }
}
