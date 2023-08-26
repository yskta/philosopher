//volatile修飾子とは、変数の値が変化する可能性があることを示す修飾子
//volatile修飾子をつけることで、コンパイラが最適化を行わないようにすることができる
void wait_while_0(volatile int *p) {
    while (*p == 0) {}
}