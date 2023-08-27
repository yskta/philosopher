//定義 アトミック処理の性質
//ある処理がアトミックである→その処理は途中で割り込まれることがない、かつシステム的に観測することができず、もしその処理が失敗した場合は完全に処理前の状態に戻る

//Compare and Swap(CAS)は同期処理機構の1つであるセマフォや、ロックフリー、ウェイトフリーなデータ構造を実装するために用いられる

#include <stdint.h>
#include <stdbool.h>

bool compare_and_swap(uint64_t *p, uint64_t val, uint64_t newval)
{
    if (*p != val) { //*pの値がvalと異なる場合はfalseを返す
        return false;
    }
    *p = newval; //*pの値がvalと同じ場合は*pにnewvalを代入してtrueを返す
    return true;
}

//