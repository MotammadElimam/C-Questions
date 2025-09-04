/*
 ******************************************************
 Create a function that displays all different combinations of two distinct two-digits
 numbers (XX XX) between 00 and 99, listed in ascending order.
 Expected output:
 $>./a.out | cat -e
 00 01, 00 02, 00 03, 00 04, 00 05, ..., 00 99, 01 02, ..., 97 99, 98 99$>
 The function should be prototyped as follows:
 void ft_print_comb2(void);
 
 ******************************************************
 * to compile it : gcc ft_print_comb2.c
 * to run it : ./a.out | cat -e
 ******************************************************
 */

#include <unistd.h>

/**********************
 * ft_print_comb2 - Displays all combinations of two distinct two-digit numbers
 * 
 * Description:
 * This function prints all possible combinations of two distinct two-digit
 * numbers from 00 to 99 in ascending order. Each combination consists of
 * two different two-digit numbers where the first number is always smaller
 * than the second number. The combinations are separated by ", ".
 * 
 * Algorithm:
 * 1. Use two nested loops for numbers a (00-98) and b (a+1 to 99)
 * 2. Ensure a < b to maintain ascending order and avoid duplicates
 * 3. For each valid combination:
 *    - Convert numbers to two-digit format and write them
 *    - Add " " between the two numbers and ", " between combinations
 * 4. Continue until all 4950 combinations are printed (from 00 01 to 98 99)
 * 
 * Parameters:
 * None
 * 
 * Return:
 * void - No return value (output is written directly)
 * 
 * Examples:
 * ft_print_comb2() outputs "00 01, 00 02, 00 03, ..., 98 99"
 **********************/
void	ft_print_comb2(void)
{
	int a, b;					/* Integer variables for the two numbers */
	char first_digit, second_digit;	/* Character variables for digit conversion */
	
	a = 0;						/* Initialize first number to 0 */
	while (a <= 98)				/* First number can be at most 98 (to allow space for b) */
	{
		b = a + 1;				/* Second number starts from next number after a */
		while (b <= 99)			/* Second number can be at most 99 */
		{
			first_digit = (a / 10) + '0';		/* Convert tens digit of first number to character */
			second_digit = (a % 10) + '0';		/* Convert units digit of first number to character */
			write(1, &first_digit, 1);			/* Write tens digit of first number */
			write(1, &second_digit, 1);		/* Write units digit of first number */
			write(1, " ", 1);					/* Write space separator between the two numbers */
			first_digit = (b / 10) + '0';		/* Convert tens digit of second number to character */
			second_digit = (b % 10) + '0';		/* Convert units digit of second number to character */
			write(1, &first_digit, 1);			/* Write tens digit of second number */
			write(1, &second_digit, 1);		/* Write units digit of second number */
			if (!(a == 98 && b == 99))			/* Check if not the last combination */
				write(1, ", ", 2);				/* Write separator ", " between combinations */
			b++;								/* Move to next second number */
		}
		a++;									/* Move to next first number */
	}
}

/**********************
 * main - Entry point for two-digit combination display program
 * 
 * Description:
 * This program demonstrates the ft_print_comb2 function by
 * displaying all unique combinations of two distinct two-digit
 * numbers in ascending order. It serves as a comprehensive test
 * to verify that all 4950 valid combinations are generated correctly.
 * 
 * Algorithm:
 * 1. Call ft_print_comb2 to display all combinations
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
 * ./ft_print_comb2 outputs "00 01, 00 02, ..., 98 99\n"
 **********************/
int main(void)
{
	ft_print_comb2();			/* Call function to display all two-digit combinations */
	write(1, "\n", 1);			/* Write newline character for better output formatting */
	return (0);					/* Return success status to the operating system */
}