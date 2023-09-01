//条件変数の使用例
//条件変数とは、スレッド間で特定の条件が成立したかどうかを通知するための変数。いわば、信号のようなもの
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER; //ミューテックスの初期化
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;  //条件変数の初期化

volatile bool ready = false; // <3>
char buf[256]; // スレッド間でデータを受け渡すためのバッファ

//データ生成用のスレッド
void *producer(void *arg){
    printf("producer:");
    fgets(buf, sizeof(buf), stdin); // データを入力
    
    if (pthread_mutex_lock(&mut) != 0){ //ミューテックスのロック
        perror("pthread_mutex_lock");
        exit(EXIT_FAILURE);
    }
    ready = true; // データが入力されたことを通知

    if (pthread_cond_boroadcast(&cond) != 0){ // 条件変数のブロードキャスト。全体に通知
        perror("pthread_cond_broadcast");
        exit(EXIT_FAILURE);
    }

    if (pthread_mutex_unlock(&mut) != 0){ //ミューテックスのアンロック
        perror("pthread_mutex_unlock");
        exit(EXIT_FAILURE);
    }
}

void* consumer(void *arg) { // データ消費スレッド <7>
    pthread_mutex_lock(&mut);

    while (!ready) { // ready変数の値がfalseの場合に待機
        // ロック解放と待機を同時に実行
        if (pthread_cond_wait(&cond, &mut) != 0) { // <8>
            perror("pthread_cond_wait"); exit(-1);
        }
    }

    pthread_mutex_unlock(&mut);
    printf("consumer: %s\n", buf);
    return NULL;
}

int main(int argc, char *argv[]) {
    // スレッド生成
    pthread_t pr, cn;
    pthread_create(&pr, NULL, producer, NULL);
    pthread_create(&cn, NULL, consumer, NULL);

    // スレッドの終了を待機
    pthread_join(pr, NULL);
    pthread_join(cn, NULL);

    // ミューテックスオブジェクトを解放
    pthread_mutex_destroy(&mut);

    // 条件変数オブジェクトを解放 <9>
    if (pthread_cond_destroy(&cond) != 0) {
        perror("pthread_cond_destroy"); return -1;
    }

    return 0;
}
