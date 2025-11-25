#include <stdio.h>
#include <string.h>

int main() {
    FILE *fp = fopen("hello.txt", "w");
    if (fp == NULL) {
        return 1;
    }
    
    fprintf(fp, "Hello, B1429059");
    fclose(fp);
    
    printf("hello.txt\n");
    return 0;
}
