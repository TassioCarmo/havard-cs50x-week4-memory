# Introduction to Memory

## What did i learn

Arrays, which were just chunks of memory back to back to back

## RGB

white, with R: 255, G: 255, and B: 255, and #FFFFFF
red, with R: 255, G: 0, and B: 0, and #FF0000
green, with R: 0, G: 255, and B: 0, and #00FF00
blue, with R: 0, G: 0, and B: 255, and #0000FF

## Hexadecimal

 base-16, where there are 16 digits which
 
count from 0 to F

0 1 2 3 4 5 6 7 8 9 A B C D E F


- decimal: 10^n
- Binary: 2^n
- Hexadecimal: 16^n
- The values in a computer’s memory are still stored as binary, but this way of representation helps us humans represent larger numeric values with fewer digits needed.
- With 8 bits in binary, the highest value we can count to is also 255, with 11111111. So two digits in hexadecimal can conveniently represent the value of a byte in binary. (Each digit in hexadecimal, with 16 values, maps to four bits in binary.)

F = 16

8 bits with each digit representing 4 bits
```
F      F = 255 

1111 1111 
```
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

<code>&</code> operator can be used to get the address of some variable, as with &n. And the * operator declares a variable as a pointer, as with int *p, indicating that we have a variable called p that points to an int. So, to store the address of a variable n into a pointer p, we would write:

<code>int *p = &n;</code>

we can actually see the address with the & operator, which means “get the address of this variable”: 

```
#include <stdio.h>

int main(void)
{
    int n = 50;
    int *p = &n;
    printf("%p\n", p);
}

```

 <code>*</code> operator is also the dereference operator, which goes to an address to get the value stored there

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

**Segmentation faults**, where we’ve tried to read or write to memory we don’t have permission to.

## Strings

string s is nothing more than <code>char* s</code>

s is a variable of type string, is just a pointer to a character.

and can be adress as ![image](https://user-images.githubusercontent.com/31789624/201547400-32c455e5-4b93-4efa-89ff-f5855de77421.png)


<img src ="https://cs50.harvard.edu/x/2022/notes/4/s_pointer.png">

And s is just the address of the first character of an string, what brings string into existency in C typedef char *string;

printf was designed by some human years ago to go to the address that's being passed in-- for instance, s-- and print out character after character after character until it sees the null character backslash zero, and then stop printing it. So that's-- you're getting a lot of functionality for free from %s


## Pointer arithmetic

 is the process of applying mathematical operations to pointers, using them just like numbers (which they are
 
 ```
 // these are equals because *s is point to the FIRST position
int main(void)
{
    char *s = "HI!";
    printf("%c\n", *s); 
    printf("%c\n", *(s + 1));
    printf("%c\n", *(s + 2));
}

#include <stdio.h>

int main(void)
{
    char *s = "HI!";
    printf("%c\n", s[0]);
    printf("%c\n", s[1]);
    printf("%c\n", s[2]);
}


 ```


The compiler is smart enough to know that if you add 1 to a pointer, that is the same as saying go one more piece of data-- not just one byte-- so if it's an int, move four. If it's a second int, move eight. If it's a third int, move 12. Pointer arithmetic handles that annoying arithmetic for you so you can just think of this as a number after a number after a number that are back to back to back but not one byte apart, but four bytes apart. 

an array really can be treated as the address of the first element in that array. The difference is that there's no secret backslash zero anywhere.

### Compare and copy

Strings  as mentioned before are just addresses of the first chars of an string so when you compare:

```
int main(void)
{
    int i = get_int("i: ");
    int j = get_int("j: ");

    if (i == j)
    {
        printf("Same\n");
    }
    else
    {
        printf("Different\n");
    }
}
```

you are comparing different things

<img src="https://cs50.harvard.edu/x/2022/notes/4/s_t.png">

### Comparison

```
int main(void)
{
    string s = get_string("s: ");

    string t = s;

    t[0] = toupper(t[0]);

    printf("s: %s\n", s);
    printf("t: %s\n", t);
}
```

<img src="https://cs50.harvard.edu/x/2022/notes/4/s_t_pointing.png">

So when you change one both will be changed, because they represent the same address


## Memory allocation

**malloc**, to allocate some number of bytes in memory. And we’ll use **free** to mark memory as usable when we’re done with it, so the operating system can do something else with it.

when you allocate memory you must **ALWAYS FREE IT LATER**

```
int main(void)
{
    char *s = get_string("s: ");

    char *t = malloc(strlen(s) + 1);

    strcpy(t, s);

    t[0] = toupper(t[0]);

    printf("s: %s\n", s);
    printf("t: %s\n", t);

    free(t);
}
```
## Garbage values

When you, the programmer, do not initialize your codes variables to have values, sometimes, who knows what's going to be there. The computer's been doing some other things, there's a bit of work that happens even before your code runs in the computer, so there might be remnants of past ints, chars, strings, floats-- anything else in there and what you're seeing is those garbage values, which is to say you should never forget, as I just did, to initialize the value of some variable. 

 malloc, and dereferencing. The code from the video might look like this in one program:
 
```
int main(void)
{   
    int *x;  
    int *y; 

    x = malloc(sizeof(int));                    

    *x = 42;
    *y = 13;    

    y = x;        

    *y = 13;   
}
```
In the first two lines, we declare two pointers. Then, we allocate memory for x, but not y, so we can assign a value to the memory x is pointing to with *x = 42;. But *y = 13; is problematic, since we haven’t allocated any memory for y, and the garbage value there points to some area in memory we likely don’t have access to.
    We can write y = x; so that y points to the same allocated memory as x, and use *y = 13; to set the value there.
    
### SWap

```

void swap(int a, int b);

int main(void)
{
    int x = 1;
    int y = 2;

    printf("x is %i, y is %i\n", x, y);
    swap(x, y);
    printf("x is %i, y is %i\n", x, y);
}

void swap(int a, int b)
{
    printf("a is %i, b is %i\n", a, b);
    int tmp = a;
    a = b;
    b = tmp;
    printf("a is %i, b is %i\n", a, b);
}
```
It turns out that the swap function gets passed in copies of variables, a and b, which are local variables that only the surrounding function can access. Changing those values won’t change x and y in the main function: 

## Memory Layout

<img src="https://cs50.harvard.edu/x/2022/notes/4/memory_layout.png">

- The machine code section is our compiled program’s binary code. When we run our program, that code is loaded into memory.
- Just below, or in the next part of memory, are global variables we declared in our program.
- The heap section is an empty area from where malloc can get free memory for our program to use. As we call malloc, we start allocating memory from the top down.
-The stack section is used by functions and local variables in our program as they are called, and grows upwards.

If we call malloc for too much memory, we will have a heap overflow, since we end up going past our heap. Or, if we call too many functions without returning from them, we will have a stack overflow, where our stack has too much memory allocated as well.

The "right way" of swapping in C

```
void swap(int *a, int *b);

int main(void)
{
    int x = 1;
    int y = 2;

    printf("x is %i, y is %i\n", x, y);
    swap(&x, &y);
    printf("x is %i, y is %i\n", x, y);
}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}


```

in C because , functions are isolated from each other. You can pass in values but you get copies of those values. 

### Algorthms

**JPEG**

Let’s look at a program that opens a file and tells us if it’s a JPEG file, a particular format for image files, with jpeg.c:
```
    // Detects if a file is a JPEG
      
    #include <stdint.h>
    #include <stdio.h>
      
    typedef uint8_t BYTE;
      
    int main(int argc, char *argv[])
    {
        // Check usage
        if (argc != 2)
        {
            return 1;
        }
      
        // Open file
        FILE *file = fopen(argv[1], "r");
        if (!file)
        {
            return 1;
        }
      
        // Read first three bytes
        BYTE bytes[3];
        fread(bytes, sizeof(BYTE), 3, file);
      
        // Check first three bytes
        if (bytes[0] == 0xff && bytes[1] == 0xd8 && bytes[2] == 0xff)
        {
            printf("Yes, possibly\n");
        }
        else
        {
            printf("No\n");
        }
      
        // Close file
        fclose(file);
    }

```

**Files**

    With the ability to use pointers, we can also open files, like a digital phone book in phonebook.c:
```
    // Saves names and numbers to a CSV file
      
    #include <cs50.h>
    #include <stdio.h>
    #include <string.h>
      
    int main(void)
    {
        // Open CSV file
        FILE *file = fopen("phonebook.csv", "a");
        if (!file)
        {
            return 1;
        }
      
        // Get name and number
        string name = get_string("Name: ");
        string number = get_string("Number: ");
      
        // Print to file
        fprintf(file, "%s,%s\n", name, number);
      
        // Close file
        fclose(file);
    }

```


## Others

When we pass a variable to a function, we're not actually passing the variable to the function, We're passing a copy of that data to the function. The function does something, and maybe we use that value when it gives it back. 

Malloc finds a chunk of memory of the size you asked for and returns a pointer
Using pointers instead of using variables, or instead of using the variables themselves or copies of the variables, we can now pass the variables around between functions in a different way. This means that if we make a change in one function, that change will actually take effect in a different function


Memory/RAM is basically a huge array of -bits wide bytes

A pointer is nothing more than an address
Always set the value of a pointer to null if you are not going to use it imediantly because it's better to have your program to crash than have something you didn't intended 

dynamically allocated memory comes from the heap and static come from the stack

always check for null after malloc because it can give you a null if it doesn't find it 

three golden rules
- Everyblock allocated to malloc must be freed
- Only free things you "malloced"
- Never free things more than once
