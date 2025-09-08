/*
 ******************************************************
 Reproduce the behavior of the function strlcat (man strlcat).
 The function should be prototyped as follows:
 unsigned int ft_strlcat(char *dest, char *src, unsigned int size);
 ******************************************************
 * to compile it : gcc ft_strlcat.c
 * to run it : ./a.out
 ******************************************************
 */

#include <unistd.h>

/**********************
 * ft_putnbr - Displays an integer number to standard output
 * 
 * Description:
 * This function converts an integer to its string representation
 * and outputs it character by character using the write system call.
 * It handles all possible int values including negative numbers,
 * zero, and the special case of INT_MIN (-2147483648).
 * 
 * Algorithm:
 * 1. Handle INT_MIN special case directly (cannot be negated)
 * 2. If number is negative, print '-' and make number positive
 * 3. If number >= 10, recursively print higher digits first
 * 4. Convert last digit to character and print it
 * 
 * Parameters:
 * @nb: The integer number to be displayed
 * 
 * Return:
 * void - No return value (output is written directly)
 * 
 * Examples:
 * ft_putnbr(42) outputs "42"
 * ft_putnbr(-123) outputs "-123"
 **********************/
void	ft_putnbr(int nb)
{
	char c;						/* Character variable to hold digit for output */
	
	if (nb == -2147483648)		/* Handle INT_MIN edge case (cannot be negated) */
	{
		write(1, "-2147483648", 11);	/* Write the literal value directly */
		return;					/* Exit function early */
	}
	if (nb < 0)					/* Check if number is negative */
	{
		write(1, "-", 1);		/* Write minus sign for negative numbers */
		nb = -nb;				/* Make number positive for processing */
	}
	if (nb >= 10)				/* Check if number has more than one digit */
		ft_putnbr(nb / 10);		/* Recursively print higher digits first */
	c = nb % 10 + '0';			/* Convert last digit to character */
	write(1, &c, 1);			/* Write the digit character to output */
}

/**********************
 * ft_putstr - Displays a string to standard output
 * 
 * Description:
 * This function outputs a null-terminated string character by character
 * using the write system call. It iterates through the string until
 * reaching the null terminator and writes each character to stdout.
 * 
 * Algorithm:
 * 1. Initialize index to 0
 * 2. Loop through string until null terminator
 * 3. Write each character to standard output
 * 4. Increment index and continue
 * 
 * Parameters:
 * @str: The string to be displayed
 * 
 * Return:
 * void - No return value (output is written directly)
 * 
 * Examples:
 * ft_putstr("Hello") outputs "Hello"
 * ft_putstr("") outputs nothing
 **********************/
void	ft_putstr(char *str)
{
	int i;						/* Index for iterating through the string */
	
	i = 0;						/* Initialize index to start of string */
	while (str[i] != '\0')		/* Loop until null terminator */
	{
		write(1, &str[i], 1);	/* Write current character to stdout */
		i++;					/* Move to next character */
	}
}

/**********************
 * ft_strlen - Calculates the length of a string
 * 
 * Description:
 * This helper function calculates the length of a null-terminated
 * string by counting characters until reaching the null terminator.
 * 
 * Algorithm:
 * 1. Initialize counter to 0
 * 2. Iterate through string until null terminator
 * 3. Increment counter for each character
 * 4. Return final count
 * 
 * Parameters:
 * @str: The string to measure
 * 
 * Return:
 * The length of the string (number of characters)
 * 
 * Examples:
 * ft_strlen("Hello") returns 5
 * ft_strlen("") returns 0
 **********************/
unsigned int	ft_strlen(char *str)
{
	unsigned int len;			/* Length counter */
	
	len = 0;					/* Initialize length to 0 */
	while (str[len] != '\0')	/* Count characters until null terminator */
		len++;					/* Increment counter */
	return (len);				/* Return the length */
}

/**********************
 * ft_strlcat - Size-bounded string concatenation
 * 
 * Description:
 * This function reproduces the behavior of the standard strlcat function.
 * It appends the src string to dest, guaranteeing null-termination and
 * that no more than size - 1 characters will be written to dest. Unlike
 * strncat, strlcat takes the full size of the destination buffer and
 * guarantees null-termination if there is room.
 * 
 * Algorithm:
 * 1. Calculate the length of destination string
 * 2. Calculate the length of source string
 * 3. If dest length >= size, return size + src length
 * 4. Copy characters from src to dest up to size limit
 * 5. Null-terminate the result
 * 6. Return total length that would have been created
 * 
 * Parameters:
 * @dest: Destination buffer
 * @src: Source string to append
 * @size: Total size of the destination buffer
 * 
 * Return:
 * The total length of the string it tried to create
 * (initial length of dest + length of src)
 * 
 * Examples:
 * char dest[10] = "Hello";
 * ft_strlcat(dest, " World", 10) returns 11, dest becomes "Hello Wor"
 **********************/
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int dest_len;		/* Length of destination string */
	unsigned int src_len;		/* Length of source string */
	unsigned int i;				/* Index for copying */
	unsigned int j;				/* Index for source string */
	
	dest_len = ft_strlen(dest);	/* Get current destination length */
	src_len = ft_strlen(src);		/* Get source string length */
	
	if (size <= dest_len)		/* If size is too small */
		return (size + src_len);	/* Return size + source length */
	
	i = dest_len;				/* Start copying at end of dest */
	j = 0;						/* Start from beginning of src */
	while (src[j] != '\0' && i < size - 1)		/* Copy while room remains */
	{
		dest[i] = src[j];		/* Copy character */
		i++;					/* Move to next position */
		j++;					/* Move to next source character */
	}
	dest[i] = '\0';				/* Null-terminate the result */
	
	return (dest_len + src_len);	/* Return total length attempted */
}

/**********************
 * main - Entry point for size-bounded concatenation demonstration program
 * 
 * Description:
 * This program demonstrates the ft_strlcat function by testing it with
 * various buffer sizes and string combinations. It shows how the function
 * safely concatenates strings within buffer limits and returns the total
 * length that would have been created.
 * 
 * Algorithm:
 * 1. Create destination buffers of various sizes
 * 2. Test concatenation with different size limits
 * 3. Display results and return values
 * 4. Demonstrate buffer overflow protection
 * 5. Show edge cases with small and zero sizes
 * 
 * Parameters:
 * None
 * 
 * Return:
 * 0 on successful execution
 * 
 * Examples:
 * ./ft_strlcat outputs safe concatenation results with size limits
 **********************/
int main(void)
{
	char dest1[20] = "Hello";	/* Destination buffer with room */
	char dest2[10] = "Hi";		/* Smaller destination buffer */
	char dest3[5] = "AB";		/* Very small buffer */
	char dest4[30] = "";		/* Empty destination */
	char dest5[15] = "Test";	/* Buffer for size edge cases */
	unsigned int result;		/* Variable to store return value */
	
	/* Test 1: Normal concatenation with sufficient space */
	write(1, "Test 1 - Sufficient space (size=20):\n", 38);		/* Display test description */
	write(1, "Before: \"", 9);		/* Show label */
	ft_putstr(dest1);				/* Display original destination */
	write(1, "\"\n", 2);			/* Close quote and newline */
	result = ft_strlcat(dest1, " World!", 20);		/* Concatenate with size limit */
	write(1, "After:  \"", 9);		/* Show label */
	ft_putstr(dest1);				/* Display result */
	write(1, "\"\n", 2);			/* Close quote and newline */
	write(1, "Return value: ", 14);	/* Show return value label */
	ft_putnbr(result);				/* Display return value */
	write(1, "\n\n", 2);			/* Newlines for formatting */
	
	/* Test 2: Limited space (truncation) */
	write(1, "Test 2 - Limited space (size=10):\n", 35);		/* Display test description */
	write(1, "Before: \"", 9);		/* Show label */
	ft_putstr(dest2);				/* Display original destination */
	write(1, "\"\n", 2);			/* Close quote and newline */
	result = ft_strlcat(dest2, " there friend", 10);		/* Will be truncated */
	write(1, "After:  \"", 9);		/* Show label */
	ft_putstr(dest2);				/* Display truncated result */
	write(1, "\"\n", 2);			/* Close quote and newline */
	write(1, "Return value: ", 14);	/* Show return value label */
	ft_putnbr(result);				/* Display return value (total attempted) */
	write(1, "\n\n", 2);			/* Newlines for formatting */
	
	/* Test 3: Very small buffer */
	write(1, "Test 3 - Very small buffer (size=5):\n", 38);		/* Display test description */
	write(1, "Before: \"", 9);		/* Show label */
	ft_putstr(dest3);				/* Display original destination */
	write(1, "\"\n", 2);			/* Close quote and newline */
	result = ft_strlcat(dest3, "CDE", 5);		/* Very limited space */
	write(1, "After:  \"", 9);		/* Show label */
	ft_putstr(dest3);				/* Display result */
	write(1, "\"\n", 2);			/* Close quote and newline */
	write(1, "Return value: ", 14);	/* Show return value label */
	ft_putnbr(result);				/* Display return value */
	write(1, "\n\n", 2);			/* Newlines for formatting */
	
	/* Test 4: Empty destination */
	write(1, "Test 4 - Empty destination (size=30):\n", 39);		/* Display test description */
	write(1, "Before: \"", 9);		/* Show label */
	ft_putstr(dest4);				/* Display empty destination */
	write(1, "\"\n", 2);			/* Close quote and newline */
	result = ft_strlcat(dest4, "Starting fresh", 30);		/* Append to empty */
	write(1, "After:  \"", 9);		/* Show label */
	ft_putstr(dest4);				/* Display result */
	write(1, "\"\n", 2);			/* Close quote and newline */
	write(1, "Return value: ", 14);	/* Show return value label */
	ft_putnbr(result);				/* Display return value */
	write(1, "\n\n", 2);			/* Newlines for formatting */
	
	/* Test 5: Size smaller than dest length */
	write(1, "Test 5 - Size < dest length (size=2):\n", 39);		/* Display test description */
	write(1, "Before: \"", 9);		/* Show label */
	ft_putstr(dest5);				/* Display original destination */
	write(1, "\"\n", 2);			/* Close quote and newline */
	result = ft_strlcat(dest5, " more", 2);		/* Size too small */
	write(1, "After:  \"", 9);		/* Show label */
	ft_putstr(dest5);				/* Display unchanged result */
	write(1, "\"\n", 2);			/* Close quote and newline */
	write(1, "Return value: ", 14);	/* Show return value label */
	ft_putnbr(result);				/* Display return value (size + src_len) */
	write(1, "\n", 1);				/* Newline */
	
	return (0);					/* Return success status to the operating system */
}