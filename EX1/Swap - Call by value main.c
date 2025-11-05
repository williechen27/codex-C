#include <stdio.h>

void swap(char a, char b) {
    char tmp;
    tmp=a;
    a=b;
    b=tmp;
    printf("a at %p, b at %p\n", &a, &b);
    return;
}

int main() {
    char a='a';
    char b='b';
    swap(a,b);
    printf("a = %c, b = %c\n", a, b);
    printf("a at %p, b at %p\n", &a, &b);
    return 0;
}
// 在 Swap func 裡操作的a和b，其實是和 main func 裡的a和b不一樣的

/* show the value in memory */
#include <stdio.h>

void func(int i, int j) {
    printf("in func, i = %d, j = %d\n", i, j);
    int t;
    t=j;
    j=i;
    i=t;
    printf("in func, i = %d, j = %d\n", i, j);
}

int main() {
    int i=10, j=100;
    func(i, j);
    printf("in main, i = %d, j = %d\n", i, j);
    return 0;
}
