![Logo](https://imgur.com/lcSk5CF.png)

# Arrays and Strings - Strings
Much like arrays, strings are not first-class citizens in C. In fact, they inherit most of the issues that come  from using arrays because... they're just arrays.
That's not entirely true though. **There are actually two types of strings in C.**

## 1. Array Strings
In a lot of ways strings and char arrays are synonymous. The main differentiating feature of a string is that it contains a null-terminator.

![null_terminator](https://imgur.com/ZYhhjR6.png)
A null-terminator is usually represented by an escaped 0: `\0`
The null-terminator is what let's us know where the end of a string is. Without the null terminator, functions such as `printf()`, `puts()`, `strcmp()`, etc. wouldn't know when to stop reading the character array because we don't have to provide a length to any of those functions. This is a nice convenience because we don't need to know how long a string is all the time, otherwise we might as well just use a char array.
>There are some inherent risks when using strings because of the null-terminator though, and functions such as `gets()` have been removed from newer versions of C because it was easy to manipulate the method by not providing a null terminator and potentionally overwriting memory past the bounds of the char array.

### In Action
Head over to [readLine.c]() to see how we could make our own scanf()-like function to read the user input into a string.

### String.h
The C standard library comes with a string library with some handy functions such as `strcmp()`, and `strlen()`. Many of the functions found in this file are relatively simple to implement on your own without the need of the string.h header and sometimes it may be a better idea to create your own version of some of these functions, but otherwise they can be handy to have.

## Good Practices
- Make sure your string arrays are at least one element larger than the string you're expecting because of the null terminator.
- Sometimes it might be better to use regular char arrays rather than strings. They each have uses so it's worth thinking about how you're going to use the arrays in your program.

## 2. String Literals
String literals are probably easier to understand that string arrays. A string literal is created pretty much anytime you use the quotation marks. e.g.
```
printf("This is string literal");
char string[100] = "This is also a string literal";
```
String literals are handy because they are **automatically null-terminated** and they are reserved in a special portion of memory apart from everything else in the program.
