# BrainFuckInterpreter
A lightweight interpreter of brainfuck written in C

- Brainfuck Language Introduction:  [https://zh.wikipedia.org/wiki/Brainfuck](https://zh.wikipedia.org/wiki/Brainfuck)
- An online brainfuck editor & optimizing interpreter, written in Javascript: [http://copy.sh/brainfuck/](http://copy.sh/brainfuck/)
- 知乎优质回答教你BrainFuck [https://www.zhihu.com/question/20002558](https://www.zhihu.com/question/20002558)


|BF  |C                 |
|:--:|:--               |
|>   |++ptr             |
|<   |--ptr             |
|+   |++*ptr            |
|-   |--*ptr            |
|.   |putchar(*ptr)     |
|,   |*ptr =getchar();  |
|[   | while (*ptr) {   |
|]   |}                 |
