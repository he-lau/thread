#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *thread_1(void *arg) {
  printf("Nous sommes dans le thread.\n");
  pthread_exit(NULL);
}

int main(void) {

  pthread_t thread1;

  printf("Avant la création du thread.\n");

  // return 0 si true, autre chiffre sinon
  if (pthread_create(&thread1, NULL, thread_1, NULL) == -1) {
    perror("pthread_create");
    return EXIT_FAILURE;
  }

  printf("Après la création du thread.\n");
  return EXIT_SUCCESS;

  return 0;
}
