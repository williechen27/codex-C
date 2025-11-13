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
