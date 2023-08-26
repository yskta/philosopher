#include <pthread.h> // <1>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_THREADS 10 // 生成するスレッドの数

// スレッド用関数
// pthreadsでは、スレッド用の関数の型は、void*型を引数に取り、void*型を返す関数でなければならない
//引数argは、スレッド生成時に渡される引数であり、void*型であるため、任意の型の値を渡すことができる

void *thread_func(void *arg) { // <2>
    int id = (int)arg; // <3>
    for (int i = 0; i < 5; i++) { // <4>
        printf("id = %d, i = %d\n", id, i);
        sleep(1);
    }
    //スレッドのエントリーポイントとして指定された関数が return 文を使用して正常に終了すると、そのスレッドも終了
    //pthread_exitを呼び出す必要はない
    return "finished!"; // 返り値
}

int main(int argc, char *argv[]) {
    // スレッドIDを格納する配列
    pthread_t v[NUM_THREADS]; // <5>
    // スレッド生成 <6>
    //NUM_THREADSの数だけスレッドを生成する
    for (int i = 0; i < NUM_THREADS; i++) {
        //pthread_createはスレッドを生成する関数
        if (pthread_create(&v[i], NULL, thread_func, (void *)i) != 0) {
            perror("pthread_create");
            return -1;
        }
    }
    // スレッドの終了を待機 <7>
    for (int i = 0; i < NUM_THREADS; i++) {
        char *ptr;
        //pthread_joinはスレッドの終了を待機する関数
        //pthread_joinを使わないと、メモリリークが発生するのでjoinは必須
        if (pthread_join(v[i], (void **)&ptr) == 0) {
            printf("msg = %s\n", ptr);
        } else {
            perror("pthread_join");
            return -1;
        }
    }
    return 0;
}