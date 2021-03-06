#include <stdlib.h>
#include <stdio.h>

/* struct */
typedef struct IntArray {
    int capacity;     // total capacity of the array
    int length;       // current number of elements in the array
    int *data;        // pointer for our array
} IntArray;

/* Function delcarations */
IntArray CreateArray();
void Append(IntArray *arr, int n);
void PrintArray(IntArray arr);
void FreeArray(IntArray *arr);

int main()
{
    IntArray arr = CreateArray();

    printf("Capacity before adding elements: %d\n", arr.capacity); // This should be 10 after we first created the IntArray.

    int i;
    for (i = 1; i <= 15; i++)
    {
        Append(&arr, i);
    }

    printf("Capacity after adding elements: %d\n", arr.capacity); // This should be 20 because we reached capacity and needed to resize the array.

    PrintArray(arr);

    //FreeArray(&arr);


    return 0;
}

/* Function definitions */
IntArray CreateArray()
{
    IntArray arr;                      // Create our Array struct
    arr.capacity = 10;                 // Arbitrarily set the capacity to 10. This could be anything we'd like
    arr.length = 0;                    // There are no elements yet so length is 0.

    arr.data = (int *) malloc(arr.capacity * sizeof(int));  // For an int it will be (10 * 4): 40 bytes allocated on the heap.
    
    return arr; // returning the address of the 
}

void Append(IntArray *arr, int n)
{
    if (arr->data == NULL) { return; }
    if (arr->length >= arr->capacity)   // If we've reached the capacity of our previously allocated array
    {
        IntArray newArr; // This is a temporary variable the check if realloc is successful.
        newArr.capacity = arr->capacity * 2; // Double the capacity for our newly allocated array.
        newArr.data = (int *) realloc(arr->data, newArr.capacity * sizeof(int)); // Realloc returns a pointer to a new block of heap memory or NULL if it fails.
                                                                                   // If it fails, the old block of memory is not freed and we want our arr pointer to still point
                                                                                   // to that block of memory. This is why we create the temporary newArr, in case realloc returns NULL.

        if (newArr.data) // If realloc was successful we will change our initial array data to point to our newly allocated memory.
                          // Realloc will have freed the old block of memory for us and we can safetly take ownership of the new block
        {
            arr->data = newArr.data;
            arr->capacity = newArr.capacity;
        }
        else // If realloc fails to allocate new memory for us then the old block is not freed automatically. In this case we are keeping the old block in case
             // we want to continue using it, however, you may want to free the old block at this point.
        {
            fputs("Error Reallocating Memory.\n", stderr);
            return;
        }
    }
    arr->data[arr->length] = n;
    arr->length++;
}

void PrintArray(IntArray arr)
{
    putchar('[');
    if (arr.length == 0)
    {
        putchar(']');
        putchar('\n');
        return;
    }

    int i;
    for (i = 0; i < arr.length; i++)
    {
        if (i == arr.length - 1)
        {
            printf("%d]\n", arr.data[i]);
        }
        else
        {
            printf("%d, ", arr.data[i]);
        }
    }
}

void FreeArray(IntArray *arr)
{
    free(arr->data);  // Frees the data previously allocated
}