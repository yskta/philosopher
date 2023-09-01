#include <stdbool.h>

bool lock = false; // 共有変数

bool test_and_set(volatile bool *p){
    //pがtrueの場合
    if (*p){
        return true;
    }
    //pがfalseの場合
    else{
        *p = true;
        return false;
    }
}

void some_func() {
retry:
    //!test_and_set(&lock)という条件式は、test_and_set(&lock)がfalseを返すときにtrueを返す
    if (!test_and_set(&lock)) { // 検査とロック獲得
        //この条件に入るのは、lockがfalseの場合のみ
        //クリティカルセクション
    } else {
        //この条件に入るのは、lockがtrueの場合のみ
        goto retry;
    }
    tas_release(&lock); // ロック解放
}
//scapbox参照