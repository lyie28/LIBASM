# Libasm
A short collection of functions written in x64 Assembly language

To create library:

make

To run tester main.c with library:

make
make test

To create library with two bonus functions:

make bonus

To run tester for the bonus functions with library: (**for 42 students: Your push_front function should *malloc* and link in your data argument... I will update my function later as I only linked a pre-malloced argument in mine) 

make bonus
make test_bonus

Useful resources on x64 Assembly language:
YouTube series: https://www.youtube.com/watch?v=rxsBghsrvpI <- These videos are really good for understanding the context of Assembly language before diving into the code.
Calling convention: https://www.raywenderlich.com/615-assembly-register-calling-convention-tutorial
