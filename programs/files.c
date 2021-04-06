#include <stdio.h>

int main(void) {
    puts("===== Reading a file ======");
    puts("---- Opening Notes/1_Structs.md ----");

    FILE* file = fopen("Notes/1_Structs.md", "r"); // Open the file and store the result in the variable 'file' (This can be called anything)

    if (file) { // Check if we successfully opened the file.
        char file_string[101]; // This is were we'll store the data that we want to use in our program later. 101 is an arbitrary length.
        
        puts("---- Reading the first 100 characters of the file ----");
        int i;
        for (i = 0; i < 100; i++) {
        file_string[i] = fgetc(file); // read the characters one at a time
        }
        file_string[100] = '\0'; // add the null terminator because we're treating it as a string.


        puts("---- printing the file to the console ----");
        printf("%s\n", file_string); // print to the stdout (console)

        puts("---- closing the file ----");
        fclose(file);
    }
    else {
        puts("File Failed to open"); // error message in case the file doesn't open.
    }
    return 0;
}