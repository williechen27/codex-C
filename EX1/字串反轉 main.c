#include <stdio.h>
#include <string.h>

int main() {
    char a[100];  // 假設輸入字串長度不超過 100
    if (scanf("%99s", a) != 1) {
        return 0;
    }

    size_t len = strlen(a);
    for (size_t i = 0; i < len / 2; ++i) {
        char tmp = a[i];
        a[i] = a[len - 1 - i];
        a[len - 1 - i] = tmp;
    }

    printf("%s\n", a);
    return 0;
}
/* 中文字串反轉 */
#include <stdio.h>
#include <string.h>

static size_t utf8_char_len(unsigned char c) {
    if ((c & 0x80) == 0x00) return 1;         // 0xxxxxxx ASCII
    if ((c & 0xE0) == 0xC0) return 2;         // 110xxxxx
    if ((c & 0xF0) == 0xE0) return 3;         // 1110xxxx
    if ((c & 0xF8) == 0xF0) return 4;         // 11110xxx
    return 1; // 碰到不合法的就當作 1 byte 處理，避免 crash
}

int main(void) {
    unsigned char buf[1024];

    // 讀一整行（可含中文、空白），假設輸入是 UTF-8
    if (!fgets((char*)buf, sizeof(buf), stdin))
        return 0;

    // 去掉結尾換行
    size_t len = strlen((char*)buf);
    if (len > 0 && (buf[len-1] == '\n' || buf[len-1] == '\r')) {
        buf[--len] = '\0';
    }

    // 記錄每個 UTF-8 字元（code point）的起始 index
    size_t indices[1024];
    size_t count = 0;

    for (size_t i = 0; i < len; ) {
        if (count >= sizeof(indices)/sizeof(indices[0])) break; // 簡單防護

        indices[count++] = i;
        size_t clen = utf8_char_len(buf[i]);
        if (i + clen > len) { // 不完整編碼，直接當作 1 byte
            clen = 1;
        }
        i += clen;
    }

    // 從後往前把每個 UTF-8 字元複製到新的 buffer
    unsigned char out[1024];
    size_t pos = 0;

    for (size_t k = 0; k < count; k++) {
        size_t start = indices[count - 1 - k];
        size_t clen = utf8_char_len(buf[start]);
        if (start + clen > len) {
            clen = 1;
        }
        memcpy(out + pos, buf + start, clen);
        pos += clen;
    }

    out[pos] = '\0';

    printf("%s\n", out);
    return 0;
}
