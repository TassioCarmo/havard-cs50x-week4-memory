# Introduction to Memory

## What did i learn

Arrays, which were just chunks of memory back to back to back

## RGB

white, with R: 255, G: 255, and B: 255, and #FFFFFF
red, with R: 255, G: 0, and B: 0, and #FF0000
green, with R: 0, G: 255, and B: 0, and #00FF00
blue, with R: 0, G: 0, and B: 255, and #0000FF

## Hexadecimal

- decimal: 10^n
- Binary: 2^n
- Hexadecimal: 16^n

count from 0 to F

0 1 2 3 4 5 6 7 8 9 A B C D E F

F = 16

F     F = 255 

1111 1111 

```
16^1  16^0
#    #

A    9

16*10 + 1*9 = 169

```

hexadecimal is very useful when you want to treat data in units of four
in the world of memory, programming, people tend to count memory bytes using hexadecimal. Partly just by convention, but also partly because it's a little more succinct 

ny time you see 0x and then a number, that's by convention  signaling to the reader that this is in fact a hexadecimal number. So if it's 0x10, that is not the number 10, that is the hexadecimal number one zero. 


## Addresses, pointers

pointer is a variable that stores an address in memory, where some other variable might be stored.

<img src= "https://cs50.harvard.edu/x/2022/notes/4/addresses.png">

In C

& operator can be used to get the address of some variable, as with &n. And the * operator declares a variable as a pointer, as with int *p, indicating that we have a variable called p that points to an int. So, to store the address of a variable n into a pointer p, we would write:

<code>int *p = &n;</code>

```
#include <stdio.h>

int main(void)
{
    int n = 50;
    int *p = &n;
    printf("%p\n", p);
}

```

 * operator is also the dereference operator, which goes to an address to get the value stored there

```
int main(void)
{
    int n = 50;
    int *p = &n;
    printf("%p\n", p);
    printf("%i\n", *p);
}
```
p takes up 8 bytes, since in modern computer systems, 64 bits are used in order to address the billions of bytes of memory available. With 32 bits, we can only count up to about 4 billion bytes

<img src ="https://cs50.harvard.edu/x/2022/notes/4/p.png">

think of p as pointing at some value in memory:

<img src ="https://cs50.harvard.edu/x/2022/notes/4/pointing.png">

Think as memory as mailboxes in an appartament where each one of the have an address

## Strings

string s is equal to char* s

s is a variable of type string, is just a pointer to a character.

<img src ="https://cs50.harvard.edu/x/2022/notes/4/s_pointer.png">




