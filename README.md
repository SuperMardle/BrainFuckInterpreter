# BrainFuckInterpreter
A lightweight interpreter of brainfuck written by C

- Brainfuck Language Introduction:  [https://zh.wikipedia.org/wiki/Brainfuck](https://zh.wikipedia.org/wiki/Brainfuck)
- A brainfuck editor & optimizing interpreter, written in Javascript: [http://copy.sh/brainfuck/](http://copy.sh/brainfuck/)


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