#include <stdio.h>
#include <string.h>

int main() {
    const char *input_path = "main.c";
    const char *output_path = "main.txt";
    FILE *input = fopen(input_path, "r");
    FILE *output = fopen(output_path, "w");
    
    if(!output) {
        return 1;
    }
    
    int line_number = -1;
    
    if(input) {
        char buffer[1024];
        int current_line = 1;
        
        while(fgets(buffer, sizeof(buffer), input)) {
            if(strstr(buffer, "int main()")) {
                line_number = current_line;
                break;
            }
            current_line++;
        }
        
        fclose(input);
    }
    
    fprintf(output, "%d\n", line_number);
    fclose(output);
    
    return 0;
}

/* Enhanced version */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* 判斷一行是不是 main 函式的宣告 */
int is_main_declaration(const char *line) {
    const char *p = line;

    /* 跳過前面的空白字元 */
    while (*p == ' ' || *p == '\t') {
        p++;
    }

    /* 如果這行是註解開頭，直接略過 */
    if (p[0] == '/' && p[1] == '/') {
        return 0;
    }
    if (p[0] == '/' && p[1] == '*') {
        return 0;
    }

    /* 檢查是否以 int 開頭（當成一個完整的字） */
    if (strncmp(p, "int", 3) != 0 || isalnum((unsigned char)p[3]) || p[3] == '_') {
        return 0;
    }
    p += 3;

    /* 跳過空白 */
    while (*p == ' ' || *p == '\t') {
        p++;
    }

    /* 檢查 main（也是一個完整的字） */
    if (strncmp(p, "main", 4) != 0 || isalnum((unsigned char)p[4]) || p[4] == '_') {
        return 0;
    }
    p += 4;

    /* 跳過空白 */
    while (*p == ' ' || *p == '\t') {
        p++;
    }

    /* 接下來應該是 '('，代表函式 */
    if (*p != '(') {
        return 0;
    }

    return 1;
}

int main(void) {
    const char *input_path  = "main.c";
    const char *output_path = "main.txt";

    FILE *input  = fopen(input_path, "r");
    FILE *output = fopen(output_path, "w");

    if (!input || !output) {
        /* 檔案開啟失敗就收尾並結束 */
        if (input)  fclose(input);
        if (output) fclose(output);
        return 1;
    }

    char buffer[1024];
    int  current_line = 1;
    int  line_number  = -1;   /* 找不到 main 就維持 -1 */

    while (fgets(buffer, sizeof(buffer), input)) {
        if (is_main_declaration(buffer)) {
            line_number = current_line;
            break;
        }
        current_line++;
    }

    fprintf(output, "%d\n", line_number);

    fclose(input);
    fclose(output);

    return 0;
}
