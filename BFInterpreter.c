#include <stdio.h>
#include <stdlib.h>

#define LEN 10000
 
int main() {
    // source 定义了BF的Hello World!代码
    char source[] = {"++++++++++[>+++++++>++++++++++>+++>+<<<<-]>++.>+.+++++++..+++.>++.<<+++++++++++++++.>.+++.------.--------.>+.>."};
    char runtime[LEN] = {0};
    char *ptr = source;
    int pos = 0;
    int row = 1, col = 0;

    while(*ptr != '\0') {
        ++col;
        switch (*ptr) {
            case '>' :
                ++pos;
                break;
            case '<' :
                if (--pos < 0) {
                    printf("%d : %d : ERROR: Illegal pointer value\n", row, col);
                    return 0;
                }
                break;
            case '+' :
                ++runtime[pos];
                if (runtime[pos] < 0 || runtime[pos] > 255) {
                    printf("%d : %d : ERROR: Illegal value\n", row, col);
                    return 0;
                }
                break;
            case '-' :
                --runtime[pos];
                if (runtime[pos] < 0 || runtime[pos] > 255) {
                    printf("%d : %d : ERROR: Illegal value\n", row, col);
                    return 0;
                }
                break;
            case '.' :
                putchar(runtime[pos]);
                break;
            case ',' :
                runtime[pos]=getchar();
                break;
            case '[' :
				if(runtime[pos] == 0) {
					while(*ptr != ']') {
						++col;
						++ptr;
					}
				}	
                break;
            case ']' :
				if(runtime[pos] != 0) {
					while(*ptr != '[') {
						--col;
						--ptr;
					}
					--col;
					--ptr;
				}
                break;
            case '\n' :
                ++row;
                col = 0;
                break;
        }
        ++ptr;
    }
    return 0;
}
