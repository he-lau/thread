
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>



void *print_message_function(void *ptr) {
  char *message;
  message = (char *) ptr;
  printf("%s\n", message);
  //pthread_exit(message);
  pthread_exit(0);
}

int main(){


  pthread_t thread1, thread2;
  char *message1 = "Thread1";
  char *message2 = "Thread2";
  int iret1, iret2;

  static pthread_mutex_t mutex_thread = PTHREAD_MUTEX_INITIALIZER;


for (int i  = 0;  i< 12; i++) {

  void *thread_result;

  printf("-------------------------------\n");

//  pthread_mutex_lock(&mutex_thread);
  iret1 = pthread_create(&thread1, NULL, print_message_function, (void *) message1);
  //printf("Thread1 : %s\n", (char *)thread_result);
//  pthread_mutex_unlock(&mutex_thread);

//  pthread_mutex_lock(&mutex_thread);
  iret2 = pthread_create(&thread2, NULL, print_message_function, (void *) message2);
  //printf("Thread2 : %s\n", (char *)thread_result);
//  pthread_mutex_unlock(&mutex_thread);

  pthread_join(thread1, &thread_result);
  pthread_join(thread2, &thread_result);




  printf("-------------------------------\n");

}
exit(0);


return 0;

}
