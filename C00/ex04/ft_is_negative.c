/*
 ******************************************************
 Create a function that displays 'N' or 'P' depending on the sign of the integer passed as a parameter.
 If n is negative, display 'N'.
 If n is positive, display 'P'.
 If n is zero, display 'Z'.
 The function should be prototyped as follows:
 void ft_is_negative(int n);
 
 ******************************************************
 * to compile it : gcc ft_is_negative.c
 * to run it : ./a.out
 ******************************************************
 */

#include <unistd.h>

/**********************
 * ft_is_negative - Displays the sign of an integer
 * 
 * Description:
 * This function examines the sign of the input integer and
 * displays a corresponding character: 'N' for negative numbers,
 * 'P' for positive numbers, and 'Z' for zero. It provides a
 * quick way to determine and display the sign classification
 * of any integer value.
 * 
 * Algorithm:
 * 1. Check if the input number is less than zero
 *    - If true, display 'N' for negative
 * 2. Check if the input number is greater than zero
 *    - If true, display 'P' for positive
 * 3. Otherwise (number equals zero)
 *    - Display 'Z' for zero
 * 
 * Parameters:
 * @n: The integer to check for sign
 * 
 * Return:
 * void - No return value (output is written directly)
 * 
 * Examples:
 * ft_is_negative(-42) outputs "N"
 * ft_is_negative(42) outputs "P"
 * ft_is_negative(0) outputs "Z"
 **********************/
void	ft_is_negative(int n)
{
	if (n < 0)					/* Check if number is negative (less than zero) */
		write(1, "N", 1);		/* Write 'N' for negative numbers */
	else if (n > 0)				/* Check if number is positive (greater than zero) */
		write(1, "P", 1);		/* Write 'P' for positive numbers */
	else						/* Number must be zero */
		write(1, "Z", 1);		/* Write 'Z' for zero */
}

/**********************
 * main - Entry point for number sign checking program
 * 
 * Description:
 * This program demonstrates the ft_is_negative function by
 * testing it with various integer values including negative,
 * positive, and zero. It serves as a comprehensive test to
 * verify correct sign detection and display functionality.
 * 
 * Algorithm:
 * 1. Test with a negative number (-42)
 * 2. Test with a positive number (42)
 * 3. Test with zero (0)
 * 4. Test with edge cases (INT_MAX, INT_MIN)
 * 5. Print newlines for better formatting
 * 
 * Parameters:
 * None
 * 
 * Return:
 * 0 on successful execution
 * 
 * Examples:
 * ./ft_is_negative outputs "N P Z P N\n"
 **********************/
int main(void)
{
	ft_is_negative(-42);		/* Test with negative number, should output 'N' */
	write(1, " ", 1);			/* Write space separator for readability */
	ft_is_negative(42);			/* Test with positive number, should output 'P' */
	write(1, " ", 1);			/* Write space separator for readability */
	ft_is_negative(0);			/* Test with zero, should output 'Z' */
	write(1, " ", 1);			/* Write space separator for readability */
	ft_is_negative(2147483647);	/* Test with INT_MAX, should output 'P' */
	write(1, " ", 1);			/* Write space separator for readability */
	ft_is_negative(-2147483648);/* Test with INT_MIN, should output 'N' */
	write(1, "\n", 1);			/* Write newline character for better output formatting */
	return (0);					/* Return success status to the operating system */
}