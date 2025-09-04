/*
 ******************************************************
 Reproduce the behavior of the function strcpy (man strcpy).
 Here is how it should be prototyped:
 char *ft_strcpy(char *dest, char *src);
 ******************************************************
 * to compile it : gcc ft_strcpy.c
 * to run it : ./a.out
 ******************************************************
 */

#include <unistd.h>

/**********************
 * ft_strcpy - Copies a string from source to destination
 * 
 * Description:
 * This function reproduces the behavior of the standard strcpy function.
 * It copies the string pointed to by src (including the terminating null
 * character) to the buffer pointed to by dest. The destination buffer
 * must be large enough to hold the copied string.
 * 
 * Algorithm:
 * 1. Initialize index counter to 0
 * 2. Iterate through source string character by character
 * 3. Copy each character from source to destination at same index
 * 4. Continue until null terminator is encountered in source
 * 5. Copy the null terminator to destination
 * 6. Return pointer to destination string
 * 
 * Parameters:
 * @dest: Pointer to destination buffer where string will be copied
 * @src: Pointer to source string to be copied
 * 
 * Return:
 * char* - Pointer to the destination string (same as dest parameter)
 * 
 * Examples:
 * char dest[20]; ft_strcpy(dest, "Hello") copies "Hello" to dest
 * char dest[10]; ft_strcpy(dest, "World") copies "World" to dest
 **********************/
char *ft_strcpy(char *dest, char *src)
{
	int i;						/* Index counter for iterating through characters */
	
	i = 0;						/* Initialize index to start from first character */
	while (src[i] != '\0')		/* Continue until null terminator is found in source */
	{
		dest[i] = src[i];		/* Copy character from source to destination */
		i++;					/* Move to next character position */
	}
	dest[i] = '\0';				/* Copy the null terminator to destination */
	return (dest);				/* Return pointer to destination string */
}

/**********************
 * main - Entry point for string copy function demonstration
 * 
 * Description:
 * This program demonstrates the ft_strcpy function by testing it
 * with a sample string. It shows the source and destination strings
 * to verify that the copying operation works correctly.
 * 
 * Algorithm:
 * 1. Create a source string with test data
 * 2. Create a destination buffer large enough to hold the copy
 * 3. Call ft_strcpy to copy from source to destination
 * 4. Display both source and destination strings for verification
 * 
 * Parameters:
 * None
 * 
 * Return:
 * 0 on successful execution
 * 
 * Examples:
 * ./ft_strcpy shows the string copying demonstration
 **********************/
/**********************
 * ft_putstr - Writes a string to standard output
 * 
 * Description:
 * This function outputs a null-terminated string to standard output
 * using the write system call. It calculates the string length by
 * iterating through characters until the null terminator is found.
 * 
 * Algorithm:
 * 1. Initialize length counter to 0
 * 2. Iterate through string until null terminator is found
 * 3. Count each character to determine total string length
 * 4. Use write system call to output the entire string at once
 * 
 * Parameters:
 * @str: Pointer to null-terminated string to be written
 * 
 * Return:
 * void - No return value (output is written directly)
 * 
 * Examples:
 * ft_putstr("Hello") outputs "Hello"
 * ft_putstr("World\n") outputs "World" followed by newline
 **********************/
void	ft_putstr(char *str)
{
	int len = 0;					/* Length counter for string measurement */
	
	while (str[len])				/* Count characters until null terminator */
		len++;					/* Increment length for each character */
	write(1, str, len);			/* Write entire string to standard output */
}

int main(void)
{
	char src[] = "Hello World!";			/* Source string to be copied */
	char dest[20];						/* Destination buffer for copied string */
	
	ft_strcpy(dest, src);				/* Copy string from source to destination */
	ft_putstr("Source: ");				/* Display source label */
	ft_putstr(src);					/* Display original source string */
	ft_putstr("\nDestination: ");		/* Display destination label with newline */
	ft_putstr(dest);					/* Display copied destination string */
	ft_putstr("\n");					/* Write final newline */
	return (0);						/* Return success status to operating system */
}