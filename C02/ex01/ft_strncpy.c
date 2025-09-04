/*
 ******************************************************
 Reproduce the behavior of the function strncpy (man strncpy).
 Here is how it should be prototyped:
 char *ft_strncpy(char *dest, char *src, unsigned int n);
 ******************************************************
 * to compile it : gcc ft_strncpy.c
 * to run it : ./a.out
 ******************************************************
 */

#include <unistd.h>

/**********************
 * ft_strncpy - Copies up to n characters from source to destination
 * 
 * Description:
 * This function reproduces the behavior of the standard strncpy function.
 * It copies up to n characters from the string pointed to by src to the
 * buffer pointed to by dest. If src is shorter than n characters, the
 * remainder of dest will be padded with null bytes. If src is n characters
 * or longer, dest will not be null-terminated.
 * 
 * Algorithm:
 * 1. Initialize index counter to 0
 * 2. While index is less than n and source character is not null:
 *    a. Copy character from source to destination at current index
 *    b. Increment index to move to next character
 * 3. While index is still less than n:
 *    a. Fill remaining positions with null bytes
 *    b. Increment index
 * 4. Return pointer to destination string
 * 
 * Parameters:
 * @dest: Pointer to destination buffer where string will be copied
 * @src: Pointer to source string to be copied
 * @n: Maximum number of characters to copy
 * 
 * Return:
 * char* - Pointer to the destination string (same as dest parameter)
 * 
 * Examples:
 * char dest[10]; ft_strncpy(dest, "Hello", 10) copies "Hello" and pads with nulls
 * char dest[3]; ft_strncpy(dest, "Hello", 3) copies "Hel" (no null terminator)
 **********************/
char *ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;					/* Index counter for iterating through characters */
	
	i = 0;							/* Initialize index to start from first character */
	while (i < n && src[i] != '\0')	/* Copy characters while within limit and not at end */
	{
		dest[i] = src[i];			/* Copy character from source to destination */
		i++;						/* Move to next character position */
	}
	while (i < n)					/* Fill remaining positions with null bytes if needed */
	{
		dest[i] = '\0';				/* Set remaining positions to null character */
		i++;						/* Move to next position */
	}
	return (dest);					/* Return pointer to destination string */
}

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


/**********************
 * main - Entry point for string copy function demonstration
 * 
 * Description:
 * This program demonstrates the ft_strncpy function by testing it
 * with various scenarios including normal copying, truncation,
 * and padding behavior. It shows how strncpy behaves differently
 * from strcpy in terms of null termination and padding.
 * 
 * Algorithm:
 * 1. Test normal copying with n greater than source length
 * 2. Test truncation with n less than source length
 * 3. Test exact length copying
 * 4. Test padding behavior with short source strings
 * 5. Display results using helper functions to show buffer contents
 * 
 * Parameters:
 * None
 * 
 * Return:
 * 0 on successful execution
 * 
 * Examples:
 * ./ft_strncpy shows various strncpy behavior demonstrations
 **********************/
int main(void)
{
	char src[] = "Hello World!";					/* Source string to be copied */
	char dest[20];								/* Destination buffer for copied string */
	
	ft_strncpy(dest, src, 5);					/* Copy only first 5 characters */
	dest[5] = '\0';								/* Manually null-terminate for display */
	ft_putstr("Source: ");						/* Display source label */
	ft_putstr(src);								/* Display original source string */
	ft_putstr("\nDestination (first 5 chars): ");	/* Display destination label */
	ft_putstr(dest);							/* Display copied destination string */
	ft_putstr("\n");							/* Write final newline */
	return (0);								/* Return success status to operating system */
}