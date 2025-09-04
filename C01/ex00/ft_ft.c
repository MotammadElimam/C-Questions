/*
 ******************************************************
 Create a function that takes a pointer to an int as a parameter and sets the value
 of that int to "42".
 The function should be prototyped as follows:
 void ft_ft(int *nbr);
 ******************************************************
 * to compile it : gcc ft_ft.c
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
 * ft_ft - Sets the value pointed to by a pointer to 42
 * 
 * Description:
 * This function takes a pointer to an integer and dereferences it
 * to set the value at that memory location to 42. It demonstrates
 * basic pointer manipulation and indirect assignment through
 * pointer dereferencing.
 * 
 * Algorithm:
 * 1. Dereference the pointer to access the memory location it points to
 * 2. Assign the value 42 to that memory location
 * 3. The original variable (pointed to by nbr) now contains 42
 * 
 * Parameters:
 * @nbr: Pointer to an integer whose value will be set to 42
 * 
 * Return:
 * void - No return value (modifies value through pointer)
 * 
 * Examples:
 * int x = 10; ft_ft(&x); // x is now 42
 * int y = -5; ft_ft(&y); // y is now 42
 **********************/
void	ft_ft(int *nbr)
{
	*nbr = 42;					/* Dereference pointer and assign value 42 to the memory location */
}

/**********************
 * main - Entry point for pointer manipulation demonstration program
 * 
 * Description:
 * This program demonstrates the ft_ft function by testing it with
 * various integer values. It shows how the function modifies the
 * original variable's value through pointer dereferencing, proving
 * that the function correctly sets any integer to 42.
 * 
 * Algorithm:
 * 1. Create test variables with different initial values
 * 2. Display original values before function call
 * 3. Call ft_ft with addresses of the variables
 * 4. Display modified values after function call
 * 5. Verify all values have been changed to 42
 * 
 * Parameters:
 * None
 * 
 * Return:
 * 0 on successful execution
 * 
 * Examples:
 * ./ft_ft outputs before/after values showing transformation to 42
 **********************/
int main(void)
{
	int a = 10;					/* Initialize first test variable with value 10 */
	int b = -25;				/* Initialize second test variable with negative value */
	int c = 0;					/* Initialize third test variable with zero */
		
	ft_ft(&a);					/* Call ft_ft with address of variable a */
	ft_ft(&b);					/* Call ft_ft with address of variable b */
	ft_ft(&c);					/* Call ft_ft with address of variable c */
	
	write(1, "After ft_ft:\n", 13);		/* Display header for modified values */
	write(1, "a = ", 4);					/* Display label for variable a */
	ft_putnbr(a);							/* Display modified value of a (should be 42) */
	write(1, "\n", 1);						/* Write newline */
	write(1, "b = ", 4);					/* Display label for variable b */
	ft_putnbr(b);							/* Display modified value of b (should be 42) */
	write(1, "\n", 1);						/* Write newline */
	write(1, "c = ", 4);					/* Display label for variable c */
	ft_putnbr(c);							/* Display modified value of c (should be 42) */
	write(1, "\n", 1);						/* Write newline */
	
	return (0);					/* Return success status to the operating system */
}