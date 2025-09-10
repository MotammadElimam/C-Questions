//******************************************************
// Assignment name  : ft_itoa
// Expected files   : ft_itoa.c
// Allowed functions: malloc
// --------------------------------------------------------------------------------

// Write a function that takes an int and converts it to a null-terminated string.
// The function returns the result in a char array that you must allocate.

// Your function must be declared as follows:

// char	*ft_itoa(int nbr);

//******************************************************
// to compile it : gcc ft_itoa.c
// to run it : ./a.out
//******************************************************

#include <stdlib.h>
#include <unistd.h>

/**********************
 * ft_numlen - Calculates number of digits in an integer
 * 
 * Description:
 * This helper function counts the number of digits required
 * to represent an integer, including the sign for negative
 * numbers. This is used to determine the size of memory
 * to allocate for the string representation.
 * 
 * Algorithm:
 * 1. Handle special case of 0
 * 2. Count sign if number is negative
 * 3. Count digits by repeatedly dividing by 10
 * 4. Return total length needed
 * 
 * Parameters:
 * @nbr: The integer to count digits for
 * 
 * Return:
 * Number of characters needed to represent the number
 * 
 * Examples:
 * ft_numlen(123) returns 3
 * ft_numlen(-456) returns 4 (includes minus sign)
 * ft_numlen(0) returns 1
 **********************/
int	ft_numlen(int nbr)
{
	int len = 0;						/* Length counter */
	
	if (nbr == 0)						/* Special case for zero */
		return (1);						/* Zero requires 1 character */
	
	if (nbr < 0)						/* Handle negative numbers */
	{
		len++;							/* Count the minus sign */
		nbr = -nbr;						/* Make number positive for counting */
	}
	
	while (nbr > 0)						/* Count digits */
	{
		len++;							/* Increment length for each digit */
		nbr /= 10;						/* Remove rightmost digit */
	}
	
	return (len);						/* Return total length needed */
}

/**********************
 * ft_itoa - Converts an integer to a string
 * 
 * Description:
 * This function converts an integer to its string representation
 * by allocating memory and filling it with the appropriate digits
 * and sign. It handles negative numbers, zero, and positive numbers.
 * The conversion works by extracting digits from right to left.
 * 
 * Algorithm:
 * 1. Calculate length needed for the string
 * 2. Allocate memory for the result string
 * 3. Handle special case of zero
 * 4. Handle negative numbers by setting sign and making positive
 * 5. Extract digits from right to left using modulo and division
 * 6. Add minus sign if needed
 * 7. Null-terminate and return the string
 * 
 * Parameters:
 * @nbr: The integer to convert to string
 * 
 * Return:
 * Pointer to allocated string containing number, or NULL on malloc failure
 * 
 * Examples:
 * ft_itoa(123) returns "123"
 * ft_itoa(-456) returns "-456"
 * ft_itoa(0) returns "0"
 **********************/
char	*ft_itoa(int nbr)
{
	int len = ft_numlen(nbr);			/* Calculate required string length */
	char *result;						/* Pointer to result string */
	int is_negative = 0;				/* Flag for negative numbers */
	int i;								/* Index for string construction */
	
	result = (char *)malloc(sizeof(char) * (len + 1));	/* Allocate memory (+1 for null) */
	if (!result)						/* Check if malloc failed */
		return (NULL);					/* Return NULL on allocation failure */
	
	result[len] = '\0';					/* Null-terminate the string */
	
	if (nbr == 0)						/* Handle special case of zero */
	{
		result[0] = '0';					/* Set first character to '0' */
		return (result);				/* Return the result */
	}
	
	if (nbr < 0)						/* Handle negative numbers */
	{
		is_negative = 1;				/* Set negative flag */
		nbr = -nbr;						/* Make number positive for processing */
	}
	
	i = len - 1;						/* Start from the end of string */
	while (nbr > 0)						/* Extract digits from right to left */
	{
		result[i] = (nbr % 10) + '0';	/* Convert digit to character */
		nbr /= 10;						/* Remove rightmost digit */
		i--;							/* Move to previous position */
	}
	
	if (is_negative)					/* Add minus sign if needed */
		result[0] = '-';				/* Set first character to minus */
	
	return (result);					/* Return completed string */
}

/**********************
 * ft_putstr - Writes a string to standard output
 * 
 * Description:
 * This helper function writes a string to standard output using
 * the write system call. It calculates the string length and
 * outputs the entire string at once.
 * 
 * Parameters:
 * @str: The string to write to stdout
 * 
 * Return:
 * void - No return value
 * 
 * Examples:
 * ft_putstr("Hello"); // Outputs "Hello" to stdout
 * ft_putstr("World\n"); // Outputs "World" followed by newline
 **********************/
void	ft_putstr(char *str)
{
	int len = 0;							/* Length counter for string */
	
	if (!str)								/* Handle NULL pointer */
		return;									/* Exit if string is NULL */
	
	while (str[len])						/* Calculate string length */
		len++;									/* Increment length counter */
	
	write(1, str, len);						/* Write string to stdout */
}

/**********************
 * main - Entry point for ft_itoa testing program
 * 
 * Description:
 * This program tests the ft_itoa function with various
 * integer values including positive, negative, zero, and
 * edge cases to demonstrate proper string conversion.
 * 
 * Parameters:
 * None
 * 
 * Return:
 * 0 on successful execution
 * 
 * Test Cases:
 * - Zero (0)
 * - Positive number (123)
 * - Negative number (-456)
 * - Large positive number (2147483647)
 * - Large negative number (-2147483648)
 **********************/
int main(void)
{
	char *result;						/* Pointer to result string */
	
	/* Test case 1: Zero */
	result = ft_itoa(0);				/* Convert 0 to string */
	ft_putstr("ft_itoa(0) = \"");			/* Print label */
	ft_putstr(result);						/* Print result */
	ft_putstr("\"\n");						/* Print closing quote and newline */
	free(result);						/* Free allocated memory */
	
	/* Test case 2: Positive number */
	result = ft_itoa(123);				/* Convert 123 to string */
	ft_putstr("ft_itoa(123) = \"");			/* Print label */
	ft_putstr(result);						/* Print result */
	ft_putstr("\"\n");						/* Print closing quote and newline */
	free(result);						/* Free allocated memory */
	
	/* Test case 3: Negative number */
	result = ft_itoa(-456);				/* Convert -456 to string */
	ft_putstr("ft_itoa(-456) = \"");		/* Print label */
	ft_putstr(result);						/* Print result */
	ft_putstr("\"\n");						/* Print closing quote and newline */
	free(result);						/* Free allocated memory */
	
	/* Test case 4: Large positive */
	result = ft_itoa(2147483647);		/* Convert INT_MAX to string */
	ft_putstr("ft_itoa(2147483647) = \"");	/* Print label */
	ft_putstr(result);						/* Print result */
	ft_putstr("\"\n");						/* Print closing quote and newline */
	free(result);						/* Free allocated memory */
	
	/* Test case 5: Large negative */
	result = ft_itoa(-2147483648);		/* Convert INT_MIN to string */
	ft_putstr("ft_itoa(-2147483648) = \"");	/* Print label */
	ft_putstr(result);						/* Print result */
	ft_putstr("\"\n");						/* Print closing quote and newline */
	free(result);						/* Free allocated memory */
	
	return (0);							/* Return success */
}