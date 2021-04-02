#include <stdio.h>

void readLine(char *string);

int main()
{
  puts("======== getLine.c =======");
  // Arbitrarily allocated space for 100 characters. Assuming the the user won't put in anything too long.
  char string[100];
  printf("Enter a string: ");
  readLine(string); // Note how we don't need to use the & to pass our array into  
                    // the function because the string variable secretly a pointer.

  printf("%s\n", string);

  return 0;
}

void readLine(char *string)
{
  char c; // This is where we're going to store each character read temporarily
  unsigned int i = 0; // This will keep track of where we're up to in writing our string. Unsigned because it will never be negative.
  while((c = getchar()) != '\n' && c != '\0' && i < 99) // Loop until we come across a new-line, a null-terminator or if our array is going to go out of bounds.
  {
    string[i++] = c;
  }
  string[i] = '\0'; // We need to manually add the null-terminator 
}
