#include <stdbool.h>

//排他実行されない例

bool lock = false;

void some_func(){
    retry:
    if (lock == false){
        lock = true;
    }
    else{
        goto retry;
    }
    lock = false;
}