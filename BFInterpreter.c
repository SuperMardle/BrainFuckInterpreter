#include <stdio.h>
#include <stdlib.h>

#define LEN 10000
 
int main(int argc, char **argv)
{
    FILE *input = fopen(argv[1], "r");
    char runtime[LEN] = {0};
    char *sptr;
    char *wptr;     // 循环时的指针
    int pos = 0;
    int wflag = 0;  // 循环标记
    int row = 1, col = 0;
    int wrow, wcol;    // 循环时保存的临时行号，列好
    while (wflag || fscanf(input, "%c", sptr) != EOF)
    {
        if (!wflag) //不在循环中
            ++col;
        else
            ++wcol;
        switch (*sptr)
        {
            case '>' :
                ++pos;
                break;
            case '<' :
                if (--pos <0)
                {
                    printf("%d : %d : ERROR: Illegal pointer value\n", row, col);
                    return 1;
                }
                break;
            case '+' :
                ++runtime[pos];
                if (runtime[pos] < 0 || runtime[pos] > 255)
                {
                    if (!wflag)
                        printf("%d : %d : ERROR: Illegal value\n", row, col);
                    else
                        printf("%d : %d : ERROR: Illegal value\n", wrow, wcol);
                    return 1;
                }
                break;
            case '-' :
                --runtime[pos];
                if (runtime[pos] < 0 || runtime[pos] > 255)
                {
                    if (!wflag)
                        printf("%d : %d : ERROR: Illegal value\n", row, col);
                    else
                        printf("%d : %d : ERROR: Illegal value\n", wrow, wcol);
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
                if (runtime[pos])
                    wptr = sptr-1;  // 因为最后会++sptr;
                else                // runtime[pos] == 0 时候，跳出循环
                    wflag = 0;
                wrow = row;
                wcol = col;
                break;
            case ']' :
                sptr = wptr;
                wflag = 1;          
                row = wrow;
                col = wcol;
                break;
            case '\n' :
                if (!wflag)
                {
                    ++row;
                    col = 0;
                }
                else
                {
                    ++wrow;
                    wcol = 0;
                }
                break;
        }
        ++sptr;
    }
    fclose(input);
    return 0;
}