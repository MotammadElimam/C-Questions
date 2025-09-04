/*
 ******************************************************
 Create a function that displays all unique combinations of n distinct digits in ascending order, without repetition.
 The value of n will be such that: 0 < n < 10
 Example output for n = 2:
 $>./a.out | cat -e
 01, 02, 03, ..., 09, 12, ..., 79, 89$>
 The function should be prototyped as follows:
 void ft_print_combn(int n);
 
 ******************************************************
 * to compile it : gcc ft_print_combn.c
 * to run it : ./a.out | cat -e
 ******************************************************
 */

#include <unistd.h>

/**********************
 * ft_print_recursive - Recursive helper function to generate combinations
 * 
 * Description:
 * This helper function recursively generates all combinations of n digits
 * starting from a given digit. It uses backtracking to build combinations
 * and prints them when the desired length is reached. Each combination
 * maintains ascending order of digits.
 * 
 * Algorithm:
 * 1. Base case: if position equals n, print current combination
 * 2. Otherwise, try each digit from start to (9 - remaining positions)
 * 3. Add digit to current combination and recurse
 * 4. Backtrack by removing the digit and trying the next one
 * 
 * Parameters:
 * @combo: Array to store current combination being built
 * @pos: Current position in the combination (0-based)
 * @start: Starting digit for this position (ensures ascending order)
 * @n: Total length of combination desired
 * 
 * Return:
 * void - No return value (output is written directly)
 **********************/
void	ft_print_recursive(char *combo, int pos, int start, int n)
{
	int i;						/* Loop counter for trying different digits */
	
	if (pos == n)				/* Base case: combination is complete */
	{
		write(1, combo, n);		/* Write the complete combination */
		/* Check if this is the last combination (digits should be 10-n, 10-n+1, ..., 9) */
		int is_last = 1;		/* Assume it's the last combination */
		int j = 0;				/* Index for checking digits */
		while (j < n)			/* Check all positions in combination */
		{
			if (combo[j] != ('9' - n + 1 + j))	/* If digit doesn't match expected last combination pattern */
			{
				is_last = 0;	/* Not the last combination */
				break;			/* Stop checking */
			}
			j++;				/* Move to next position */
		}
		if (!is_last)			/* If not the last combination */
			write(1, ", ", 2);	/* Write separator ", " between combinations */
		return;					/* Return from recursion */
	}
	i = start;					/* Initialize loop counter with starting digit */
	while (i <= 9 - (n - pos - 1))	/* Loop while there are enough remaining digits */
	{
		combo[pos] = i + '0';	/* Convert digit to character and store in combination */
		ft_print_recursive(combo, pos + 1, i + 1, n);	/* Recurse to next position with incremented start */
		i++;					/* Try next digit */
	}
}

/**********************
 * ft_print_combn - Displays all unique combinations of n distinct digits
 * 
 * Description:
 * This function generates and displays all possible combinations of n
 * distinct digits (0-9) in ascending order. Each combination contains
 * n different digits arranged in ascending order, and all combinations
 * are displayed in lexicographic order separated by ", ".
 * 
 * Algorithm:
 * 1. Validate input (n must be between 1 and 9)
 * 2. Create array to store current combination
 * 3. Call recursive helper function to generate all combinations
 * 4. Helper function uses backtracking to build combinations
 * 
 * Parameters:
 * @n: Number of digits in each combination (1 <= n <= 9)
 * 
 * Return:
 * void - No return value (output is written directly)
 * 
 * Examples:
 * ft_print_combn(2) outputs "01, 02, 03, ..., 89"
 * ft_print_combn(3) outputs "012, 013, 014, ..., 789"
 **********************/
void	ft_print_combn(int n)
{
	char combo[10];				/* Array to store current combination (max 9 digits) */
	
	if (n <= 0 || n >= 10)		/* Validate input range */
		return;					/* Return early if invalid input */
	ft_print_recursive(combo, 0, 0, n);	/* Start recursive generation from position 0, digit 0 */
}

/**********************
 * main - Entry point for n-digit combination display program
 * 
 * Description:
 * This program demonstrates the ft_print_combn function by testing
 * it with various values of n. It shows how the function generates
 * different numbers of combinations based on the input parameter,
 * from simple 2-digit pairs to complex 9-digit combinations.
 * 
 * Algorithm:
 * 1. Test with n=2 (generates 2-digit combinations)
 * 2. Test with n=3 (generates 3-digit combinations)
 * 3. Print newlines for better formatting between tests
 * 4. Return success status
 * 
 * Parameters:
 * None
 * 
 * Return:
 * 0 on successful execution
 * 
 * Examples:
 * ./ft_print_combn outputs combinations for n=2 and n=3 with newlines
 **********************/
int main(void)
{
	ft_print_combn(2);			/* Test with 2-digit combinations */
	write(1, "\n", 1);			/* Write newline for better formatting */
	return (0);					/* Return success status to the operating system */
}