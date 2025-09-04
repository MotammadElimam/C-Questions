/*
 ******************************************************
 Create a function that displays all unique combinations of three distinct digits,
 with both the digits within each combination and the combinations themselves in
 ascending order.
 Expected output:
 $>./a.out | cat -e
 012, 013, 014, 015, 016, 017, 018, 019, 023, ..., 789$> 
 987 is not included because 789 already covers that combination.
 999 is not included because the digit 9 appears more than once.
    
 The function should be prototyped as follows:
 void ft_print_comb(void);
 
 ******************************************************
 * to compile it : gcc ft_print_comb.c
 * to run it : ./a.out | cat -e
 ******************************************************
 */

#include <unistd.h>

/**********************
 * ft_print_comb - Displays all unique combinations of three distinct digits
 * 
 * Description:
 * This function prints all possible combinations of three distinct digits
 * in ascending order. Each combination consists of three different digits
 * arranged in ascending order within the combination. The combinations
 * themselves are also displayed in ascending order, separated by ", ".
 * 
 * Algorithm:
 * 1. Use three nested loops for digits a, b, c
 * 2. Ensure a < b < c to maintain ascending order and uniqueness
 * 3. For each valid combination:
 *    - Write the three digits as characters
 *    - Add ", " separator except for the last combination (789)
 * 4. Continue until all 120 combinations are printed
 * 
 * Parameters:
 * None
 * 
 * Return:
 * void - No return value (output is written directly)
 * 
 * Examples:
 * ft_print_comb() outputs "012, 013, 014, ..., 789"
 **********************/
void	ft_print_comb(void)
{
	char a, b, c;				/* Character variables for the three digits */
	
	a = '0';					/* Initialize first digit to '0' */
	while (a <= '7')			/* First digit can be at most '7' (to allow space for b and c) */
	{
		b = a + 1;				/* Second digit starts from next digit after a */
		while (b <= '8')		/* Second digit can be at most '8' (to allow space for c) */
		{
			c = b + 1;			/* Third digit starts from next digit after b */
			while (c <= '9')	/* Third digit can be at most '9' */
			{
				write(1, &a, 1);			/* Write first digit */
				write(1, &b, 1);			/* Write second digit */
				write(1, &c, 1);			/* Write third digit */
				if (!(a == '7' && b == '8' && c == '9'))	/* Check if not the last combination */
					write(1, ", ", 2);		/* Write separator ", " between combinations */
				c++;						/* Move to next third digit */
			}
			b++;							/* Move to next second digit */
		}
		a++;								/* Move to next first digit */
	}
}

/**********************
 * main - Entry point for three-digit combination display program
 * 
 * Description:
 * This program demonstrates the ft_print_comb function by
 * displaying all unique combinations of three distinct digits
 * in ascending order. It serves as a comprehensive test to
 * verify that all 120 valid combinations are generated correctly.
 * 
 * Algorithm:
 * 1. Call ft_print_comb to display all combinations
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
 * ./ft_print_comb outputs "012, 013, 014, ..., 789\n"
 **********************/
int main(void)
{
	ft_print_comb();			/* Call function to display all three-digit combinations */
	write(1, "\n", 1);			/* Write newline character for better output formatting */
	return (0);					/* Return success status to the operating system */
}