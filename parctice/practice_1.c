#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
void * main_thread(void *arg);
static int data;

int main() {
        pthread_t tid;
        
        pthread_create(&tid, NULL, main_thread, NULL);
        printf("main:%d\n", data);
        pthread_join(tid, NULL);
        printf("main end:%d\n", data);
        return 0;
}

void * main_thread(void *arg) {
        sleep(1);
        data=10;
        pthread_exit(NULL);
        return NULL;
}


