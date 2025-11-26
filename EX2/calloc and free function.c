#include <stdio.h>
#include <stdlib.h>

/* 用 calloc 配出一份拷貝；全程用指標運算 */
int* clone_array(const int *src, size_t n) {
    int *dst = calloc(n, sizeof *dst);   // 內容自動清 0
    if (!dst) return NULL;
    for (size_t i = 0; i < n; ++i)
        *(dst + i) = *(src + i);         // 指標運算拷貝
    return dst;                          // 交給呼叫端 free
}

/* 用指標走訪列印成 0, 1, 2, 3, 4 */
void print_array(const int *arr, size_t n) {
    const int *p = arr;
    const int *end = arr + n;
    while (p < end) {
        printf("%d", *p);
        if (p + 1 < end) printf(", ");
        ++p;                             // 指標前進一格
    }
    printf("\n");
}

int main(void) {
    int src[] = {0, 1, 2, 3, 4};
    size_t n = sizeof src / sizeof src[0];

    int *dup = clone_array(src, n);
    if (!dup) return 1;

    print_array(dup, n);                 // output: 0, 1, 2, 3, 4

    free(dup);                           // 釋放並歸零指標(好習慣)
    dup = NULL;
    return 0;
}
