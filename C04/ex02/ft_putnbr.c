/*
 ******************************************************
 Create a function that displays the number passed as a parameter. The function
 must be able to handle all possible values of the int type.
 The function should be prototyped as follows:
 void ft_putnbr(int nb);
 ******************************************************
 * to compile it : gcc ft_putnbr.c
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
 * main - Entry point for integer display demonstration program
 * 
 * Description:
 * This program demonstrates the ft_putnbr function by testing it with
 * various integer values including positive numbers, negative numbers,
 * zero, and edge cases like INT_MIN and INT_MAX. It verifies that
 * the function correctly handles all possible int values.
 * 
 * Algorithm:
 * 1. Create test integers with different values and edge cases
 * 2. Call ft_putnbr for each test number
 * 3. Add labels and formatting for clear output
 * 4. Test edge cases like INT_MIN and large numbers
 * 5. Verify all numbers are displayed correctly
 * 
 * Parameters:
 * None
 * 
 * Return:
 * 0 on successful execution
 * 
 * Examples:
 * ./ft_putnbr outputs various integers with proper formatting
 **********************/
int main(void)
{
	int num1 = 42;				/* Positive number test */
	int num2 = -123;			/* Negative number test */
	int num3 = 0;				/* Zero test case */
	int num4 = -2147483648;		/* INT_MIN edge case */
	int num5 = 2147483647;		/* INT_MAX edge case */
	int num6 = -1;				/* Negative single digit */
	int num7 = 9;				/* Positive single digit */
	
	write(1, "Testing ft_putnbr:\n", 19);		/* Display program header */
	
	write(1, "Positive number: ", 17);			/* Test positive number */
	ft_putnbr(num1);
	write(1, "\n", 1);
	
	write(1, "Negative number: ", 17);			/* Test negative number */
	ft_putnbr(num2);
	write(1, "\n", 1);
	
	write(1, "Zero: ", 6);						/* Test zero */
	ft_putnbr(num3);
	write(1, "\n", 1);
	
	write(1, "INT_MIN: ", 9);					/* Test INT_MIN edge case */
	ft_putnbr(num4);
	write(1, "\n", 1);
	
	write(1, "INT_MAX: ", 9);					/* Test INT_MAX edge case */
	ft_putnbr(num5);
	write(1, "\n", 1);
	
	write(1, "Negative single digit: ", 23);	/* Test negative single digit */
	ft_putnbr(num6);
	write(1, "\n", 1);
	
	write(1, "Positive single digit: ", 23);	/* Test positive single digit */
	ft_putnbr(num7);
	write(1, "\n", 1);
	
	return (0);					/* Return success status to the operating system */
}