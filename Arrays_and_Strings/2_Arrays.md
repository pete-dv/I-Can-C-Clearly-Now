![Logo](https://imgur.com/lcSk5CF.png)

# Arrays and Strings - Arrays

It's worth pointing out that in C arrays are not first-class citizens (such as char, int, pointers) like in many other programming languages. Arrays are just a layer of convenience for the programmer to work with lots of data quickly. In the Intro I talked a lot about memory and not much about arrays. That is because understanding how memory works is truly fundamental to understanding how C works, especially when we get to pointers.
Though, when we're using arrays we're actually secretly using pointers so it is equally as important to understand memory now.
If you read through [Intro]() you would be familiar with what our memory looks like when using a single variable such as an int. Let's have a quick look at what an **int array with 10 values set to 5** looks like. (**Click on the image to make it bigger.**)

![int_arr_5](https://imgur.com/QOUyXwI.png)
We can see starting at memory address 0x00CFF8E8 we have 10 lots of 4 bytes each containing the number 5. This is how arrays look in memory. Pretty neat!

## Zero to Hero
It's probably standard knowledge by now but arrays in C are 0-based which means their first element is represented by a 0.
**It's crucial to remember that when we declare an array of a size the last element is always size - 1**

![arr_diagram](https://imgur.com/WtigAgT.png)

## Passing by Reference
By default all of C's primitive types are passed into functions by value. That is, the value is copied into the new parameter variable that is declared in the function. This is great because we can mess around with the variables inside the function without worrying about what we might be changing outside the function.
**Arrays on the other hand are passed by reference.** Passing by reference means the the original array is accessible and modifyable within the function that is passed to. There's actually a few good reasons for this:
- Arrays can sometimes be very big and so it might be slow to copy all the values into a function.
- Like I mentioned earlier, arrays are secretly pointers (memory addresses).

That second point means that technically the memory address of the first element in our array is being copied into the function. Copying memory addresses is generally what we mean when we talk about passing references. Because we are working on the memory address of our array any changes we make within a function will be reflected in our original array.
> ## Equivalent Syntax
> ```
> func (int arr[])
> {
>   arr[5] = 12;
> }
> ```
> and 
> ```
> func (int *arr)
> {
>   arr[5] = 12;
> }
> ```
> are practically the same. One takes an array as it's argument and the other takes a pointer but as I mentioned that are effectively the same when we're using arrays so both are fine. The latter is more transparent with what is actually happening but the former makes it easier to see that we're working with an array. Both are fine.

Because Arrays are not first-class citizens we cannot return arrays from functions in C. There are two options available to us to basically do the same thing:
1. Pass the array into a function and modify the array.
2. Return a pointer to first element of our array.

## Good Practices
- Because arrays in C are glorified pointers the infomation they contain are the memory address of the  first element and the type of the array. The array has no idea how big it is so when we're passing an array into a function so it is often a good idea to **pass the size of the array** into a function along with the array.
- Use the `const` keyword (short of constant) to indicate that an array, or any variable for that matter, will not be changed. This is especially useful in functions when we don't what to accidently modify an array. It doesn't actually change anything but it helps the compiler catch our mistakes which is always handy!

> ## Going deeper
> What's actually happening when we access an element in an array?
> ```
> char chArray[10]; // 10 elements, 10 bytes
> int iArray[10]; // 10 elements, 40 byte
> //
> chArray[5] = 'a'; // Add 5 to the address of chArray and change the value to 'a'
> *(chArray + 5); = 'a' // Equivalent to the line above but uses pointer arithmetic
> iArray[5] = 12; // Add 20 to the address of iArray and change the value to 12
> *(iArray + 5) = 12; // Again, this is equivalent to the line above.
> ```
The char array arithmetic seems to make sense. Characters are 1 byte each, add 5 and we should have move 5 bytes, and this is true.
The int array arithmetic doesn't seem to add up. Integers are 4 bytes each, add 5 and you might think that we would move 5 bytes, when actually we have moved 20 bytes. This is because C is clever enough to keep track of how big a data type that is held in an array is and applies the multiplication for us so we don't have to do: `*(iArray + (5 * sizeof(int)))`.

[**Continue to Strings**]()
