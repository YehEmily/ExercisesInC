## Homework 5

### C Exercises

Modify the link below so it points to the `ex05` directory in your
student repository.

[Here is a link to the ex05 directory in my repository](https://github.com/yehemily/ExercisesInC/tree/master/exercises/ex05)

### Think OS Chapter 5 reading questions

**Bits and bytes**

1) Suppose you have the value 128 stored as an unsigned 8-bit number.  What happens if you convert 
it to a 16-bit number and accidentally apply sign extension?

`128` as an unsigned 8-bit number is `1000000`. Converting this number to a 16-bit number might accidentally result in `1111111111000000`, which is incorrect because this integer is supposed to be unsigned, whereas this result is negative.

2) Write a C expression that computes the two's complement of 12 using the XOR bitwise operator. 
Try it out and confirm that the result is interpreted as -12.

```
  00001100
^ 11111000
-------
  11110100
```

So `12 ^ -1` produces the two's complement of 12, which is interpreted as -12.

3) Can you guess why IEEE floating-point uses biased integers to represent the exponent rather than a
sign bit or two's complement?

```
Biasing is done because exponents have to be signed values in order to be able to represent both tiny and huge values, but two's complement, the usual representation for signed values, would make comparison harder.

To solve this problem the exponent is stored as an unsigned value suitable for comparison, and when being interpreted it is converted into an exponent within a signed range by subtracting the bias.
```

I got this off of Wikipedia, but this was what I was guessing - that biased integers are used because they need to be able to represent both positive and negative exponents in an easy-to-use way. I also think that a sign bit would not work because... it's just one bit?

4) Following the example in Section 5.3, write the 32-bit binary representation of -13 in single precision IEEE floating-point.  What would you get if you accidentally interpreted this value as an integer?

The sign is 1, since -13 is negative. 13 in binary is `b1101`, which is `1.101 * 2^3`, so the exponent is 3, or 130 with the bias. Finally, the coefficient is 101 followed by 20 zeros. The 32-bit binary representation of -13, then, is `11000001010100000000000000000000`. This is approximately `1.1 * 10^31` as an integer.

5) Write a function that takes a string and converts from lower-case to upper-case by flipping the sixth bit. As a challenge, you can make a faster version by reading the string 32 or 64 bits at a time, rather than one character at a time.  This optimization is made easier if the length of the string is a multiple of 4 or 8 bytes.

```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void converter(char * string) {
	char * res = malloc(sizeof(char) * strlen(string));
	for (int i = 0; i < strlen(string); i++) {
		res[i] = string[i] ^ 0b00100000;
		printf("%c", res[i]);
	}
	printf("\n");
}

int main () {
	char string[] = "abcdefg";
	converter(string);
}
```

