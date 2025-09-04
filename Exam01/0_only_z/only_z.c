// Assignment name  : only_z
// Expected files   : only_z.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that displays a 'z' character on the standard output.

#include <unistd.h>

/**********************
 * main - Displays a single 'z' character
 * 
 * Description:
 * This program writes the character 'z' to standard output
 * using the write system call. It's the simplest possible
 * program demonstrating basic output in C.
 * 
 * Technical details:
 * - Uses write() with file descriptor 1 (stdout)
 * - Writes exactly 1 byte (the character 'z')
 * - No newline is added after the character
 * 
 * Return:
 * 0 on successful execution
 **********************/
int main(void)
{
	write(1, "z", 1);  /* Write the character 'z' to stdout (file descriptor 1), 1 byte */
	return (0);         /* Return 0 to indicate successful program execution */
}