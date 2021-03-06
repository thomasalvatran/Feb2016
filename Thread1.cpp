//Passing data to thread. p. 88 Linux advanced
//http://www.tutorialspoint.com/cplusplus/cpp_multithreading.htm
//home/tovantran/Ctest/k_r/thread/Thread1.cpp --> 2015-11-02 by ./.tv  owner: tovantran

#include <iostream>
#include <pthread.h>
#include <string.h>
#include <stdio.h>
#include <cstdlib>
#include <unistd.h>  //sleep(1)

using namespace std;

#define NUM_THREADS     5

struct thread_data{
   int  thread_id;
   char *message;
//   char message[];
};

void *PrintHello(void *threadarg)
{
   struct thread_data *my_data;

   my_data = (struct thread_data *) threadarg;

   cout << "Thread ID : " << my_data->thread_id ;
   cout << " has Message : " << my_data->message << " - this thread now exit!" << endl;
	 for(int i = 0; i < 5; i++)
	 {
   sleep(1);
   printf("In PrintHello\n");
   }
	 pthread_exit(NULL);
}

char *appendCharToArray(char *array, int a)
{
//   char *ret = (char *)malloc(sizeof(array) + 1 + 1);
//   strcpy(ret, array);
//   ret[strlen(ret)] = a;
//   ret[sizeof(ret)] = '\0';
//   printf("new string = %s\n", ret);
//   return ret;
//		 printf("new string = %s\n", array);
//     char *ret = new char(strlen(array) + 1 + 1); // 1 char + 1 char for NULL
	   int len = strlen(array);
	   char *ret = new char[len + 2];
     strcpy(ret, array);
//     sprintf(ret+len, "%d", a);
     sprintf(&ret[len], "%d", a);    //sprint (char *str, const char *format, argument)
//     ret[len] = itoa(a);
     ret[len + 1] = '\0';
//     printf("new string1 = %s\n", ret);
     return ret;
}

int main ()
{
   pthread_t threads[NUM_THREADS];
   struct thread_data td[NUM_THREADS];
   int rc;
   int i;

   for( i=0; i < NUM_THREADS; i++ ){
      cout <<"main() : creating thread, " << i << endl;
      td[i].thread_id = i;
      td[i].message = (char *)" This is message from thread "; //warning: deprecated conversion from string constant to ‘char*’ [-Wwrite-strings]
      td[i].message = const_cast<char*>(" This is a message from thread "); //Preferred
      // char *message = (char *) "string"
	    td[i].message = appendCharToArray(td[i].message, i);
      rc = pthread_create(&threads[i], NULL,
                          PrintHello, (void *)&td[i]);
//      for (int i = 0; i < 10000000; i++)
   		//wait to thread completed before exit
      if (rc){
         cout << "Error:unable to create thread," << rc << endl;
         //exit(-1);
         break;
      }
   }
    for (int i = 0; i < 10000000; i++)
   		//wait to thread completed before exit
   pthread_exit(NULL);
}
