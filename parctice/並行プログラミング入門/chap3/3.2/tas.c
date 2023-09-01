//TAS=test and set
//TASもCASと同様にアトミック処理の性質を持つ

#include <stdbool.h>

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