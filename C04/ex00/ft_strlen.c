/*
 ******************************************************
 Create a function that counts and returns the number of characters in a string.
 The function should be prototyped as follows:
 int ft_strlen(char *str);
 ******************************************************
 * to compile it : gcc ft_strlen.c
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
 * ft_strlen - Calculates and returns the length of a string
 * 
 * Description:
 * This function counts the number of characters in a null-terminated
 * string by iterating through each character until it encounters
 * the null terminator ('\0'). It returns the total count as an integer.
 * The function handles empty strings and normal strings correctly.
 * 
 * Algorithm:
 * 1. Initialize a counter variable to 0
 * 2. Iterate through the string character by character
 * 3. Increment counter for each non-null character
 * 4. Stop when null terminator is encountered
 * 5. Return the final count
 * 
 * Parameters:
 * @str: Pointer to the null-terminated string to measure
 * 
 * Return:
 * int - The number of characters in the string (excluding null terminator)
 * 
 * Examples:
 * ft_strlen("Hello") returns 5
 * ft_strlen("") returns 0
 * ft_strlen("42") returns 2
 **********************/
int	ft_strlen(char *str)
{
	int len;					/* Counter variable to track string length */
	
	len = 0;					/* Initialize length counter to zero */
	while (str[len] != '\0')	/* Loop until null terminator is found */
	{
		len++;					/* Increment counter for each character */
	}
	return (len);				/* Return the total character count */
}

/**********************
 * main - Entry point for string length calculation demonstration program
 * 
 * Description:
 * This program demonstrates the ft_strlen function by testing it with
 * various string inputs including empty strings, single characters,
 * and longer strings. It displays each string's length to verify
 * the function works correctly in different scenarios.
 * 
 * Algorithm:
 * 1. Create test strings with different lengths
 * 2. Call ft_strlen for each test string
 * 3. Display the string and its calculated length
 * 4. Test edge cases like empty strings
 * 5. Verify results are as expected
 * 
 * Parameters:
 * None
 * 
 * Return:
 * 0 on successful execution
 * 
 * Examples:
 * ./ft_strlen outputs various strings and their lengths
 **********************/
int main(void)
{
	char *str1 = "Hello World";	/* Test string with spaces and letters */
	char *str2 = "";			/* Empty string test case */
	char *str3 = "42";			/* Short string test case */
	char *str4 = "This is a longer test string with numbers 123";	/* Long string test */
	
	write(1, "String: \"Hello World\" - Length: ", 33);	/* Display first test string */
	ft_putnbr(ft_strlen(str1));							/* Calculate and display length */
	write(1, "\n", 1);									/* Write newline */
	
	write(1, "String: \"\" - Length: ", 21);				/* Display empty string test */
	ft_putnbr(ft_strlen(str2));							/* Calculate and display length */
	write(1, "\n", 1);									/* Write newline */
	
	write(1, "String: \"42\" - Length: ", 23);			/* Display short string test */
	ft_putnbr(ft_strlen(str3));							/* Calculate and display length */
	write(1, "\n", 1);									/* Write newline */
	
	write(1, "String: \"This is a longer...\" - Length: ", 41);	/* Display long string test */
	ft_putnbr(ft_strlen(str4));								/* Calculate and display length */
	write(1, "\n", 1);										/* Write newline */
	
	return (0);					/* Return success status to the operating system */
}