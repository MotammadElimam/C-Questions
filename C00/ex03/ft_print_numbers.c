/*
 ******************************************************
 Create a function that displays all digits on a single line, in ascending order.
 The function should be prototyped as follows:
 void ft_print_numbers(void);
 
 ******************************************************
 * to compile it : gcc ft_print_numbers.c
 * to run it : ./a.out
 ******************************************************
 */

#include <unistd.h>

/**********************
 * ft_print_numbers - Displays all single digits in ascending order
 * 
 * Description:
 * This function prints all 10 single digits from 0 to 9
 * on a single line in ascending order. Each digit is displayed
 * consecutively without any separators between them, creating
 * a continuous sequence of numeric characters.
 * 
 * Algorithm:
 * 1. Initialize a character variable with '0'
 * 2. Use a while loop to iterate through all digits
 * 3. For each iteration:
 *    - Write the current digit character to standard output
 *    - Increment to the next digit
 * 4. Continue until '9' is reached and printed
 * 
 * Parameters:
 * None
 * 
 * Return:
 * void - No return value (output is written directly)
 * 
 * Examples:
 * ft_print_numbers() outputs "0123456789"
 **********************/
void	ft_print_numbers(void)
{
	char c = '0';				/* Initialize character variable with first digit '0' */
	
	while (c <= '9')			/* Continue loop while character is within digit range */
	{
		write(1, &c, 1);		/* Write current digit character to standard output */
		c++;					/* Increment to next digit character */
	}
}

/**********************
 * main - Entry point for numbers display program
 * 
 * Description:
 * This program demonstrates the ft_print_numbers function by
 * displaying all single digits from 0 to 9. It serves as a
 * test program to verify that all digits are printed correctly
 * in ascending numerical order.
 * 
 * Algorithm:
 * 1. Call ft_print_numbers to display all digits
 * 2. Print a newline character for better output formatting
 * 3. Return success status
 * 
 * Parameters:
 * None
 * 
 * Return:
 * 0 on successful execution
 * 
 * Examples:
 * ./ft_print_numbers outputs "0123456789\n"
 **********************/
int main(void)
{
	ft_print_numbers();			/* Call function to display all single digits */
	write(1, "\n", 1);			/* Write newline character for better output formatting */
	return (0);					/* Return success status to the operating system */
}