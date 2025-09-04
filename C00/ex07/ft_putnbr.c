/*
 ******************************************************
 Create a function that displays the number passed as a parameter. The function
 must be able to display all possible values of an int type variable.
 The function should be prototyped as follows:
 void ft_putnbr(int nb);
 Example:
 ft_putnbr(42); should display 42
 ******************************************************
 * to compile it : gcc ft_putnbr.c
 * to run it : ./a.out | cat -e
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
 * zero, and the special case of INT_MIN (-2147483648) which cannot
 * be negated without overflow.
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
 * ft_putnbr(0) outputs "0"
 * ft_putnbr(-2147483648) outputs "-2147483648"
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
 * main - Entry point for integer display program
 * 
 * Description:
 * This program demonstrates the ft_putnbr function by testing
 * it with various integer values including positive numbers,
 * negative numbers, zero, and edge cases like INT_MAX and INT_MIN.
 * It serves as a comprehensive test to verify correct number
 * display functionality.
 * 
 * Algorithm:
 * 1. Test with positive number (42)
 * 2. Test with negative number (-123)
 * 3. Test with zero (0)
 * 4. Test with INT_MAX (2147483647)
 * 5. Test with INT_MIN (-2147483648)
 * 6. Print newlines for better formatting
 * 
 * Parameters:
 * None
 * 
 * Return:
 * 0 on successful execution
 * 
 * Examples:
 * ./ft_putnbr outputs multiple test numbers with newlines
 **********************/
int main(void)
{
	ft_putnbr(42);				/* Test with positive number */
	write(1, "\n", 1);			/* Write newline for better formatting */
	ft_putnbr(-123);			/* Test with negative number */
	write(1, "\n", 1);			/* Write newline for better formatting */
	ft_putnbr(0);				/* Test with zero */
	write(1, "\n", 1);			/* Write newline for better formatting */
	ft_putnbr(2147483647);		/* Test with INT_MAX */
	write(1, "\n", 1);			/* Write newline for better formatting */
	ft_putnbr(-2147483648);		/* Test with INT_MIN (edge case) */
	write(1, "\n", 1);			/* Write newline for better formatting */
	return (0);					/* Return success status to the operating system */
}