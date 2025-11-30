#include <stdio.h>

int main() {
    int arr[2][3] = {{1,2,3},{4,5,6}};
    int* ptr = (int*)arr + 3;
    // (int*)arr + 3 跟 
    // ptr + 2 是同一種「指標＋n(位址位移)」
    // *ptr + 2 是「把值拿出來再加 2」
    printf("%d", *ptr);
    // 另外，「*(指標 + n)」→ 先位移再取值
    // 例如：*(ptr + 2)、*((int*)arr + 3)
    return 0;
}

/* compare to (int*)arr + 3
#include <stdio.h>
int main() {
    int arr[] = {1,2,3,4};
    int* ptr = &arr[0];
    printf("%d", *(ptr + 2));
    return 0;
} */
