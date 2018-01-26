## Homework 1

### C Exercises

[Here is a link to the ex01 directory in my repository](https://github.com/YehEmily/ExercisesInC/tree/master/exercises/ex01)

### Think OS Chapter 1 reading questions

1) Give an example of a feature common in interpreted languages that is rare in compiled languages.

Dynamic types (the types of variables that can change while a program is running); for example, I don't have to define what type a variable called `x` is in Python, but in a compiled language like Java, I have to specify whether `x` is an integer, a string, a character, etc.

2) Name two advantages of static typing over dynamic typing.

With static types, you can always tell what types variables are (integer, string, character, etc.). Also, this means that errors can be found more quickly because since functions must declare the types of arguments that are provided and the type of result that the functions return, the compiler can check whether the arguments provided are the right type and whether the return value is used correctly.

3) Give an example of a static semantic error.

```
int thisIsWrong() {
    char wrongType = 'R';
    return wrongType;
}
```

4) What are two reasons you might want to turn off code optimization?

If there are subtle bugs in the code, optimization might make the bug appear or (much worse) disappear. Additionally, the higher the optimization level used, the longer compilation might take (I assume, since -O5 takes longer to compile than -O1).

5) When you run `gcc` with `-S`, why might the results look different on different computers?

`gcc` generates code for the machine that it is run on, like x86 assembly language for processors from Intel. So, different computers might have different assembly languages.

6) If you spell a variable name wrong, or if you spell a function name wrong, the error messages 
you get might look very different.  Why?

I'm guessing the process for checking whether a variable name is correct (or at least already defined) is different from the process for checking whether a function name is correct (or at least refers to a function that already exists). Checking whether a variable name is correct probably (always???) means checking within the file that is being executed, while checking whether a function name is correct probably means checking within the file, then in any external libraries that are used within the file.

7) What is a segmentation fault?

A segmentation fault occurs when you try to read or write an incorrect location in memory.
