/*
 ******************************************************
 Create a function ft_div_mod with the following prototype:
 void ft_div_mod(int a, int b, int *div, int *mod);
 This function divides 'a' by 'b' and stores the result in the integer pointed to by
 'div'. It also stores the remainder of the division of 'a' by 'b' in the integer pointed
 to by 'mod'
 ******************************************************
 * to compile it : gcc ft_div_mod.c
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
 * ft_div_mod - Performs division and modulo operations with pointer results
 * 
 * Description:
 * This function takes two integers and performs both division and modulo
 * operations on them. The results are stored in memory locations pointed
 * to by the provided pointers. This demonstrates returning multiple values
 * from a function using pointer parameters.
 * 
 * Algorithm:
 * 1. Perform integer division of a by b using / operator
 * 2. Store the division result in the memory location pointed to by div
 * 3. Perform modulo operation of a by b using % operator
 * 4. Store the remainder result in the memory location pointed to by mod
 * 
 * Parameters:
 * @a: The dividend (number to be divided)
 * @b: The divisor (number to divide by)
 * @div: Pointer to store the division result (a / b)
 * @mod: Pointer to store the remainder result (a % b)
 * 
 * Return:
 * void - No return value (results stored through pointers)
 * 
 * Examples:
 * int result, remainder; ft_div_mod(17, 5, &result, &remainder);
 * // result = 3, remainder = 2
 * ft_div_mod(20, 4, &result, &remainder); // result = 5, remainder = 0
 **********************/
void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;				/* Perform integer division and store result in div pointer */
	*mod = a % b;				/* Perform modulo operation and store remainder in mod pointer */
}

/**********************
 * main - Entry point for division and modulo demonstration program
 * 
 * Description:
 * This program demonstrates the ft_div_mod function by testing it with
 * various pairs of integer values. It shows how the function performs
 * both division and modulo operations simultaneously and returns the
 * results through pointer parameters.
 * 
 * Algorithm:
 * 1. Create variables to hold division and modulo results
 * 2. Test with various dividend and divisor combinations
 * 3. Display the original operands and the computed results
 * 4. Verify that division and modulo operations are correct
 * 
 * Parameters:
 * None
 * 
 * Return:
 * 0 on successful execution
 * 
 * Examples:
 * ./ft_div_mod outputs division and modulo results for various test cases
 **********************/
int main(void)
{
	int division_result;		/* Variable to store division result */
	int modulo_result;			/* Variable to store modulo result */
	
	write(1, "Testing ft_div_mod function:\n\n", 30);		/* Display program header */
	
	/* Test case 1: 17 divided by 5 */
	ft_div_mod(17, 5, &division_result, &modulo_result);	/* Call function with test values */
	write(1, "17 / 5 = ", 9);								/* Display operation */
	ft_putnbr(division_result);								/* Display division result */
	write(1, ", 17 % 5 = ", 11);							/* Display separator and modulo operation */
	ft_putnbr(modulo_result);								/* Display modulo result */
	write(1, "\n", 1);										/* Write newline */
	
	/* Test case 2: 20 divided by 4 */
	ft_div_mod(20, 4, &division_result, &modulo_result);	/* Call function with test values */
	write(1, "20 / 4 = ", 9);								/* Display operation */
	ft_putnbr(division_result);								/* Display division result */
	write(1, ", 20 % 4 = ", 11);							/* Display separator and modulo operation */
	ft_putnbr(modulo_result);								/* Display modulo result */
	write(1, "\n", 1);										/* Write newline */
	
	/* Test case 3: 100 divided by 7 */
	ft_div_mod(100, 7, &division_result, &modulo_result);	/* Call function with test values */
	write(1, "100 / 7 = ", 10);							/* Display operation */
	ft_putnbr(division_result);								/* Display division result */
	write(1, ", 100 % 7 = ", 12);							/* Display separator and modulo operation */
	ft_putnbr(modulo_result);								/* Display modulo result */
	write(1, "\n", 1);										/* Write newline */
	
	/* Test case 4: 42 divided by 6 */
	ft_div_mod(42, 6, &division_result, &modulo_result);	/* Call function with test values */
	write(1, "42 / 6 = ", 9);								/* Display operation */
	ft_putnbr(division_result);								/* Display division result */
	write(1, ", 42 % 6 = ", 11);							/* Display separator and modulo operation */
	ft_putnbr(modulo_result);								/* Display modulo result */
	write(1, "\n", 1);										/* Write newline */
	
	return (0);					/* Return success status to the operating system */
}