#include <stdio.h>

int main() {
    for(int i = 0; i < 81; i++) {
        int x = i / 9 + 1;
        int y = i % 9 + 1;
        printf("%d*%d=%d ", x, y, x*y);
        if(y==9) printf("\n");
    }
    return 0;
}
