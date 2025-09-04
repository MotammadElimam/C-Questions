/*
 ******************************************************
 Create a function ft_ultimate_div_mod with the following prototype:
 void ft_ultimate_div_mod(int *a, int *b);
 This function divides the value pointed to by 'a' by the value pointed to by 'b'. The
 result of the division is stored in the integer pointed to by 'a', while the remainder
 is stored in the integer pointed to by 'b'.
 ******************************************************
 * to compile it : gcc ft_ultimate_div_mod.c
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
 * ft_ultimate_div_mod - Performs in-place division and modulo operations
 * 
 * Description:
 * This function takes two pointers to integers and performs division
 * and modulo operations on their values. The results overwrite the
 * original values: the division result replaces the dividend (a),
 * and the remainder replaces the divisor (b). This demonstrates
 * in-place modification of values through pointers.
 * 
 * Algorithm:
 * 1. Store the original values from both pointers in temporary variables
 * 2. Perform division of original_a by original_b
 * 3. Store the division result in the location pointed to by a
 * 4. Perform modulo of original_a by original_b
 * 5. Store the remainder result in the location pointed to by b
 * 
 * Parameters:
 * @a: Pointer to dividend (input) / division result (output)
 * @b: Pointer to divisor (input) / remainder result (output)
 * 
 * Return:
 * void - No return value (modifies values through pointers)
 * 
 * Examples:
 * int x = 17, y = 5; ft_ultimate_div_mod(&x, &y);
 * // x becomes 3 (17/5), y becomes 2 (17%5)
 * int p = 20, q = 4; ft_ultimate_div_mod(&p, &q);
 * // p becomes 5 (20/4), q becomes 0 (20%4)
 **********************/
void	ft_ultimate_div_mod(int *a, int *b)
{
	int original_a;				/* Store original value of a for calculations */
	int original_b;				/* Store original value of b for calculations */
	
	original_a = *a;			/* Save the dividend value before modification */
	original_b = *b;			/* Save the divisor value before modification */
	*a = original_a / original_b;	/* Store division result in location of a */
	*b = original_a % original_b;	/* Store remainder result in location of b */
}

/**********************
 * main - Entry point for ultimate division and modulo demonstration
 * 
 * Description:
 * This program demonstrates the ft_ultimate_div_mod function by testing
 * it with various pairs of integer values. It shows how the function
 * performs both division and modulo operations while overwriting the
 * original values with the results, demonstrating in-place operations.
 * 
 * Algorithm:
 * 1. Create pairs of test variables with different initial values
 * 2. Display original values before function call
 * 3. Call ft_ultimate_div_mod with addresses of the variables
 * 4. Display modified values after function call
 * 5. Verify that division and modulo results are correct
 * 
 * Parameters:
 * None
 * 
 * Return:
 * 0 on successful execution
 * 
 * Examples:
 * ./ft_ultimate_div_mod shows before/after values with in-place operations
 **********************/
int main(void)
{
	int a, b;					/* Variables for testing the function */
	
	write(1, "Testing ft_ultimate_div_mod function:\n\n", 39);	/* Display program header */
	
	/* Test case 1: 17 divided by 5 */
	a = 17;						/* Set dividend */
	b = 5;						/* Set divisor */
	write(1, "Before: a = ", 12);							/* Display original values header */
	ft_putnbr(a);											/* Display original a value */
	write(1, ", b = ", 6);									/* Display separator */
	ft_putnbr(b);											/* Display original b value */
	write(1, "\n", 1);										/* Write newline */
	ft_ultimate_div_mod(&a, &b);							/* Call function with addresses */
	write(1, "After:  a = ", 12);							/* Display results header */
	ft_putnbr(a);											/* Display division result (17/5 = 3) */
	write(1, ", b = ", 6);									/* Display separator */
	ft_putnbr(b);											/* Display modulo result (17%5 = 2) */
	write(1, "\n\n", 2);									/* Write double newline */
	
	/* Test case 2: 20 divided by 4 */
	a = 20;						/* Set dividend */
	b = 4;						/* Set divisor */
	write(1, "Before: a = ", 12);							/* Display original values header */
	ft_putnbr(a);											/* Display original a value */
	write(1, ", b = ", 6);									/* Display separator */
	ft_putnbr(b);											/* Display original b value */
	write(1, "\n", 1);										/* Write newline */
	ft_ultimate_div_mod(&a, &b);							/* Call function with addresses */
	write(1, "After:  a = ", 12);							/* Display results header */
	ft_putnbr(a);											/* Display division result (20/4 = 5) */
	write(1, ", b = ", 6);									/* Display separator */
	ft_putnbr(b);											/* Display modulo result (20%4 = 0) */
	write(1, "\n\n", 2);									/* Write double newline */
	
	/* Test case 3: 100 divided by 7 */
	a = 100;					/* Set dividend */
	b = 7;						/* Set divisor */
	write(1, "Before: a = ", 12);							/* Display original values header */
	ft_putnbr(a);											/* Display original a value */
	write(1, ", b = ", 6);									/* Display separator */
	ft_putnbr(b);											/* Display original b value */
	write(1, "\n", 1);										/* Write newline */
	ft_ultimate_div_mod(&a, &b);							/* Call function with addresses */
	write(1, "After:  a = ", 12);							/* Display results header */
	ft_putnbr(a);											/* Display division result (100/7 = 14) */
	write(1, ", b = ", 6);									/* Display separator */
	ft_putnbr(b);											/* Display modulo result (100%7 = 2) */
	write(1, "\n", 1);										/* Write newline */
	
	return (0);					/* Return success status to the operating system */
}