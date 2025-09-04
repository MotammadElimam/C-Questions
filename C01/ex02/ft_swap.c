/*
 ******************************************************
 Create a function that swaps the values of two integers using their addresses received
 as parameters.
 The function should be prototyped as follows:
 void ft_swap(int *a, int *b);
 ******************************************************
 * to compile it : gcc ft_swap.c
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
 * ft_swap - Swaps the values of two integers using pointers
 * 
 * Description:
 * This function takes two pointers to integers and swaps the values
 * stored at those memory locations. It uses a temporary variable
 * to safely exchange the values without data loss. This demonstrates
 * fundamental pointer manipulation for value swapping.
 * 
 * Algorithm:
 * 1. Create a temporary variable to store the first value
 * 2. Dereference the first pointer and copy its value to temp
 * 3. Dereference the first pointer and assign the second value to it
 * 4. Dereference the second pointer and assign the temp value to it
 * 
 * Parameters:
 * @a: Pointer to the first integer to be swapped
 * @b: Pointer to the second integer to be swapped
 * 
 * Return:
 * void - No return value (modifies values through pointers)
 * 
 * Examples:
 * int x = 5, y = 10; ft_swap(&x, &y); // x is now 10, y is now 5
 * int p = -3, q = 7; ft_swap(&p, &q); // p is now 7, q is now -3
 **********************/
void	ft_swap(int *a, int *b)
{
	int temp;					/* Temporary variable to hold value during swap */
	
	temp = *a;					/* Store the value pointed to by a in temp */
	*a = *b;					/* Copy the value pointed to by b into location of a */
	*b = temp;					/* Copy the temp value (original a) into location of b */
}

/**********************
 * main - Entry point for integer swapping demonstration program
 * 
 * Description:
 * This program demonstrates the ft_swap function by testing it with
 * various pairs of integer values. It shows how the function exchanges
 * the values of two variables through pointer manipulation, proving
 * that the original variables' values are correctly swapped.
 * 
 * Algorithm:
 * 1. Create pairs of test variables with different initial values
 * 2. Display original values before function call
 * 3. Call ft_swap with addresses of the variables
 * 4. Display swapped values after function call
 * 5. Verify that values have been properly exchanged
 * 
 * Parameters:
 * None
 * 
 * Return:
 * 0 on successful execution
 * 
 * Examples:
 * ./ft_swap outputs before/after values showing successful swapping
 **********************/
int main(void)
{
	int x = 42;					/* Initialize first test variable */
	int y = 24;					/* Initialize second test variable */
	int p = -100;				/* Initialize third test variable with negative value */
	int q = 0;					/* Initialize fourth test variable with zero */
	
	write(1, "Before ft_swap:\n", 16);		/* Display header for original values */
	write(1, "x = ", 4);					/* Display label for variable x */
	ft_putnbr(x);							/* Display original value of x */
	write(1, ", y = ", 6);					/* Display separator and label for y */
	ft_putnbr(y);							/* Display original value of y */
	write(1, "\n", 1);						/* Write newline */
	write(1, "p = ", 4);					/* Display label for variable p */
	ft_putnbr(p);							/* Display original value of p */
	write(1, ", q = ", 6);					/* Display separator and label for q */
	ft_putnbr(q);							/* Display original value of q */
	write(1, "\n\n", 2);					/* Write double newline for spacing */
	
	ft_swap(&x, &y);			/* Call ft_swap with addresses of x and y */
	ft_swap(&p, &q);			/* Call ft_swap with addresses of p and q */
	
	write(1, "After ft_swap:\n", 15);		/* Display header for swapped values */
	write(1, "x = ", 4);					/* Display label for variable x */
	ft_putnbr(x);							/* Display swapped value of x (should be 24) */
	write(1, ", y = ", 6);					/* Display separator and label for y */
	ft_putnbr(y);							/* Display swapped value of y (should be 42) */
	write(1, "\n", 1);						/* Write newline */
	write(1, "p = ", 4);					/* Display label for variable p */
	ft_putnbr(p);							/* Display swapped value of p (should be 0) */
	write(1, ", q = ", 6);					/* Display separator and label for q */
	ft_putnbr(q);							/* Display swapped value of q (should be -100) */
	write(1, "\n", 1);						/* Write newline */
	
	return (0);					/* Return success status to the operating system */
}