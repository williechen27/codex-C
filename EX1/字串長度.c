#include <stdio.h>

size_t my_strlen(const char *p) {
    if (*p == '\0') {
        return 0;
    }
    // 否則：1個字元 + 「後面那段字串的長度」
    // 此時並不知道「後面那段字串的長度」的長度是多少
    // 因此需一層一層算下去，等全部都算完後
    // 再一路往上加回來，才得到 1 + 12 = 13
    // 「後面那段字串的長度」相當於「還沒算完的數學式子」
    return 1 + my_strlen(p+1);
}
int main() {
    const char str[] = "IU is a girl!";
    
    size_t len = my_strlen(str);
    printf("( %s ) len = %zu\n", str, len); 
    // 以「無號十進位整數」的方式印出來
    // %: 格式的開頭
    // z: 長度修飾子 (length modifier)，代表「對應的參數是 size_t 型別」
    // u: 以 unsigned 十進位整數（無符號整數）來輸出
    return 0;
}
