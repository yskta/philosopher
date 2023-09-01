#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER; //ミューテックスの初期化
//※ミューテックスの初期化は、pthread_mutex_init関数を用いて行うこともできる

//スレッド用の関数
void *some_func(void *arg){
    if (pthread_mutex_lock(&mut) != 0){ //ミューテックスのロック
        perror("pthread_mutex_lock");
        exit(EXIT_FAILURE);
    }

    //クリティカルセクション

    if (pthread_mutex_unlock(&mut) != 0){ //ミューテックスのアンロック
        perror("pthread_mutex_unlock");
        exit(EXIT_FAILURE);
    }
    return NULL;
}

int main(int argc, char *argv[]){
    //スレッドの生成
    pthread_t th1, th2;
    if (pthread_create(&th1, NULL, some_func, NULL) != 0){
        perror("pthread_create");
        exit(EXIT_FAILURE);
    }
    if (pthread_create(&th2, NULL, some_func, NULL) != 0){
        perror("pthread_create");
        exit(EXIT_FAILURE);
    }

    //スレッドの終了待ち
    if (pthread_join(th1, NULL) != 0){
        perror("pthread_join");
        exit(EXIT_FAILURE);
    }
    if (pthread_join(th2, NULL) != 0){
        perror("pthread_join");
        exit(EXIT_FAILURE);
    }

    //ミューテックスの破棄
    if (pthread_mutex_destroy(&mut) != 0){
        perror("pthread_mutex_destroy");
        exit(EXIT_FAILURE);
    }
    return 0;
}
