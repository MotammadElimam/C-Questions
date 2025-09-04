// Assignment name  : ft_strlen
// Expected files   : ft_strlen.c
// Allowed functions: 
// --------------------------------------------------------------------------------

// Write a function that returns the length of a string.

// Your function must be declared as follows:

// int	ft_strlen(char *str);

#include <unistd.h>

/**********************
 * ft_strlen - Calculates the length of a string
 * 
 * Description:
 * This function counts the number of characters in a string
 * by iterating through it until the null terminator is found.
 * It does not count the null terminator itself.
 * 
 * Algorithm:
 * 1. Initialize counter to 0
 * 2. Loop through string until '\0' is found
 * 3. Increment counter for each character
 * 4. Return final count
 * 
 * Parameters:
 * @str: Pointer to the string to measure
 * 
 * Return:
 * The number of characters in the string (excluding '\0')
 * 
 * Example:
 * ft_strlen("Hello") returns 5
 * ft_strlen("") returns 0
 **********************/
int	ft_strlen(char *str)
{
	int i = 0;          /* Initialize counter to 0 */
	while (str[i])      /* Loop until null terminator '\0' is found */
		i++;            /* Increment counter for each character */
	return (i);         /* Return the total count (length of string) */
}

/**********************
 * ft_putnbr - Prints an integer to standard output
 * 
 * Description:
 * This function converts an integer to its string representation
 * and prints it character by character using write(). It handles
 * negative numbers and the special case of INT_MIN.
 * 
 * Algorithm:
 * 1. Handle INT_MIN special case (cannot be negated)
 * 2. Print minus sign for negative numbers
 * 3. Convert to positive for processing
 * 4. Recursively print digits from left to right
 * 5. Convert each digit to ASCII character
 * 
 * Special cases:
 * - INT_MIN (-2147483648): Printed directly as string
 * - Negative numbers: Minus sign printed first
 * - Single digit: Direct conversion to character
 * 
 * Parameters:
 * @n: The integer to print
 * 
 * Return:
 * void - No return value
 **********************/
void	ft_putnbr(int n)
{
	char c;                                    /* Character to hold single digit */
	
	if (n == -2147483648)                     /* Special case for INT_MIN */
	{
		write(1, "-2147483648", 11);      /* Write the string directly */
		return;                            /* Exit function */
	}
	if (n < 0)                                 /* If number is negative */
	{
		write(1, "-", 1);                 /* Print minus sign */
		n = -n;                            /* Make number positive */
	}
	if (n >= 10)                               /* If number has more than one digit */
		ft_putnbr(n / 10);                 /* Recursively print all digits except last */
	c = n % 10 + '0';                          /* Convert last digit to character */
	write(1, &c, 1);                           /* Print the digit */
}

/**********************
 * main - Test program for ft_strlen function
 * 
 * Description:
 * This program demonstrates the ft_strlen function with various
 * test cases including normal strings, strings with punctuation,
 * and empty strings. Results are displayed using ft_putnbr.
 * 
 * Test cases:
 * - "Hello": Standard 5-character string
 * - "World!": String with punctuation (6 characters)
 * - "": Empty string (0 characters)
 * 
 * Output format:
 * Each test prints a label followed by the calculated length
 * 
 * Return:
 * 0 on successful execution
 **********************/
int main(void)
{
	char *str1 = "Hello";                      /* Test string 1 */
	char *str2 = "World!";                     /* Test string 2 with punctuation */
	char *str3 = "";                           /* Empty string test case */
	
	write(1, "Length of 'Hello': ", 19);       /* Print label */
	ft_putnbr(ft_strlen(str1));                /* Calculate and print length of str1 */
	write(1, "\n", 1);                         /* Print newline */
	
	write(1, "Length of 'World!': ", 20);      /* Print label */
	ft_putnbr(ft_strlen(str2));                /* Calculate and print length of str2 */
	write(1, "\n", 1);                         /* Print newline */
	
	write(1, "Length of empty string: ", 24);  /* Print label */
	ft_putnbr(ft_strlen(str3));                /* Calculate and print length of empty string */
	write(1, "\n", 1);                         /* Print newline */
	
	return (0);                                 /* Return success */
}