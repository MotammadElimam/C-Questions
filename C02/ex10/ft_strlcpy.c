/*
 ******************************************************
 Reproduce the behavior of the function strlcpy (man strlcpy).
 Here is how it should be prototyped:
 unsigned int ft_strlcpy(char *dest, char *src, unsigned int size);
 ******************************************************
 * to compile it : gcc ft_strlcpy.c
 * to run it : ./a.out
 ******************************************************
 */

#include <unistd.h>

/**********************
 * ft_strlen - Calculates the length of a string
 * 
 * Description:
 * This helper function calculates the length of a null-terminated string
 * by counting characters until the null terminator is encountered.
 * This is needed for strlcpy to return the length of the source string.
 * 
 * Algorithm:
 * 1. Initialize counter to 0
 * 2. Iterate through string until null terminator is found
 * 3. Count each character
 * 4. Return total count
 * 
 * Parameters:
 * @str: Pointer to null-terminated string
 * 
 * Return:
 * unsigned int - Length of the string (excluding null terminator)
 * 
 * Examples:
 * ft_strlen("Hello") returns 5
 * ft_strlen("") returns 0
 **********************/
unsigned int	ft_strlen(char *str)
{
	unsigned int len = 0;			/* Length counter */
	
	while (str[len])				/* Count characters until null terminator */
		len++;					/* Increment counter */
	return (len);					/* Return string length */
}

/**********************
 * ft_strlcpy - Copies string with size limit and returns source length
 * 
 * Description:
 * This function reproduces the behavior of the standard strlcpy function.
 * It copies up to (size - 1) characters from src to dest, always null-
 * terminates the result (unless size is 0), and returns the length of
 * the source string. This function is safer than strcpy and strncpy
 * because it guarantees null termination and provides buffer overflow
 * protection.
 * 
 * Algorithm:
 * 1. Calculate the length of the source string
 * 2. If size is 0, return source length without copying
 * 3. Copy characters from src to dest, up to (size - 1) characters
 * 4. Always null-terminate the destination (unless size is 0)
 * 5. Return the length of the source string
 * 
 * Parameters:
 * @dest: Pointer to destination buffer
 * @src: Pointer to source string to be copied
 * @size: Size of destination buffer (including space for null terminator)
 * 
 * Return:
 * unsigned int - Length of the source string (what would be copied if size were unlimited)
 * 
 * Examples:
 * ft_strlcpy(dest, "Hello", 10) copies "Hello" and returns 5
 * ft_strlcpy(dest, "Hello", 3) copies "He" and returns 5
 **********************/
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int src_len;			/* Length of source string */
	unsigned int i;					/* Index counter for copying */
	
	src_len = ft_strlen(src);		/* Calculate source string length */
	
	if (size == 0)					/* If destination size is 0 */
		return (src_len);			/* Return source length without copying */
	
	i = 0;							/* Initialize copy index */
	while (i < size - 1 && src[i] != '\0')	/* Copy characters with size limit */
	{
		dest[i] = src[i];			/* Copy character from source to destination */
		i++;						/* Move to next character */
	}
	dest[i] = '\0';					/* Always null-terminate destination */
	
	return (src_len);				/* Return source string length */
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
 * ft_putnbr - Displays an unsigned integer to standard output
 * 
 * Description:
 * This function converts an unsigned integer to its string representation
 * and outputs it character by character using the write system call.
 * It handles all possible unsigned int values by using recursion to
 * print digits in the correct order.
 * 
 * Algorithm:
 * 1. If number >= 10, recursively print higher digits first
 * 2. Convert last digit to character and print it
 * 
 * Parameters:
 * @nb: The unsigned integer to be displayed
 * 
 * Return:
 * void - No return value (output is written directly)
 * 
 * Examples:
 * ft_putnbr(42) outputs "42"
 * ft_putnbr(0) outputs "0"
 **********************/
void	ft_putnbr(unsigned int nb)
{
	char c;						/* Character variable to hold digit for output */
	
	if (nb >= 10)				/* Check if number has more than one digit */
		ft_putnbr(nb / 10);		/* Recursively print higher digits first */
	c = nb % 10 + '0';			/* Convert last digit to character */
	write(1, &c, 1);			/* Write the digit character to output */
}

/**********************
 * main - Entry point for strlcpy function demonstration
 * 
 * Description:
 * This program demonstrates the ft_strlcpy function by testing it
 * with various scenarios including normal copying, truncation,
 * and edge cases. It shows the source string, destination buffer
 * size, copied result, and return value to verify the function
 * works correctly according to strlcpy specifications.
 * 
 * Algorithm:
 * 1. Test normal copying with sufficient buffer size
 * 2. Test truncation with small buffer size
 * 3. Test zero-size buffer edge case
 * 4. Display source, destination, and return value for each test
 * 
 * Parameters:
 * None
 * 
 * Return:
 * 0 on successful execution
 * 
 * Examples:
 * ./ft_strlcpy shows various strlcpy behavior demonstrations
 **********************/
int main(void)
{
	char dest1[20];								/* Large destination buffer */
	char dest2[5];								/* Small destination buffer */
	char dest3[1];								/* Minimal destination buffer */
	unsigned int result;						/* Return value from ft_strlcpy */
	
	ft_putstr("Testing ft_strlcpy function:\n\n");	/* Display program header */
	
	/* Test case 1: Normal copy with sufficient space */
	ft_putstr("Test 1 - Source: \"Hello World!\", Buffer size: 20\n");	/* Test description */
	result = ft_strlcpy(dest1, "Hello World!", 20);					/* Copy with large buffer */
	ft_putstr("Destination: \"");									/* Display result label */
	ft_putstr(dest1);												/* Display copied string */
	ft_putstr("\"\nReturn value: ");								/* Return value label */
	ft_putnbr(result);												/* Display return value */
	ft_putstr("\n\n");												/* Spacing between tests */
	
	/* Test case 2: Truncation with small buffer */
	ft_putstr("Test 2 - Source: \"Hello World!\", Buffer size: 5\n");	/* Test description */
	result = ft_strlcpy(dest2, "Hello World!", 5);					/* Copy with small buffer */
	ft_putstr("Destination: \"");									/* Display result label */
	ft_putstr(dest2);												/* Display truncated string */
	ft_putstr("\"\nReturn value: ");								/* Return value label */
	ft_putnbr(result);												/* Display return value */
	ft_putstr("\n\n");												/* Spacing between tests */
	
	/* Test case 3: Zero size buffer (no copying) */
	ft_putstr("Test 3 - Source: \"Hello World!\", Buffer size: 0\n");	/* Test description */
	result = ft_strlcpy(dest3, "Hello World!", 0);					/* Copy with zero buffer */
	ft_putstr("Destination: [unchanged]\n");						/* Explain no copy occurred */
	ft_putstr("Return value: ");									/* Return value label */
	ft_putnbr(result);												/* Display return value */
	ft_putstr("\n\n");												/* Spacing between tests */
	
	/* Test case 4: Empty source string */
	ft_putstr("Test 4 - Source: \"\", Buffer size: 10\n");			/* Test description */
	result = ft_strlcpy(dest1, "", 10);							/* Copy empty string */
	ft_putstr("Destination: \"");									/* Display result label */
	ft_putstr(dest1);												/* Display copied string */
	ft_putstr("\"\nReturn value: ");								/* Return value label */
	ft_putnbr(result);												/* Display return value */
	ft_putstr("\n");												/* Final newline */
	
	return (0);													/* Return success status */
}