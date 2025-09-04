/*
 ******************************************************
 Create a function that takes a pointer to a pointer to a pointer to a pointer to a
 pointer to a pointer to a pointer to a pointer to a pointer to an int as a parameter
 and sets the value of that int to "42".
 The function should be prototyped as follows:
 void ft_ultimate_ft(int *********nbr);
 ******************************************************
 * to compile it : gcc ft_ultimate_ft.c
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
 * ft_ultimate_ft - Sets value through nine levels of pointer indirection
 * 
 * Description:
 * This function takes a pointer to a pointer to a pointer... (9 levels deep)
 * to an integer and dereferences it through all nine levels to set the final
 * value to 42. It demonstrates advanced pointer manipulation and multiple
 * levels of indirection in C programming.
 * 
 * Algorithm:
 * 1. Apply nine dereference operations (*********) to traverse all pointer levels
 * 2. Assign the value 42 to the final memory location
 * 3. The original variable (at the end of the pointer chain) now contains 42
 * 
 * Parameters:
 * @nbr: Pointer to pointer to pointer... (9 levels) to an integer
 * 
 * Return:
 * void - No return value (modifies value through pointer chain)
 * 
 * Examples:
 * int x = 10; 
 * int *p1 = &x; int **p2 = &p1; ... int *********p9 = &p8;
 * ft_ultimate_ft(p9); // x is now 42
 **********************/
void	ft_ultimate_ft(int *********nbr)
{
	*********nbr = 42;			/* Dereference through 9 levels and assign value 42 */
}

/**********************
 * main - Entry point for ultimate pointer manipulation demonstration
 * 
 * Description:
 * This program demonstrates the ft_ultimate_ft function by creating
 * a chain of nine pointers, each pointing to the next level, with
 * the final pointer pointing to an integer. It shows how the function
 * can modify a value through nine levels of pointer indirection.
 * 
 * Algorithm:
 * 1. Create an integer variable and 9 levels of pointers
 * 2. Set up the pointer chain where each pointer points to the next
 * 3. Display the original value
 * 4. Call ft_ultimate_ft with the 9th level pointer
 * 5. Display the modified value to verify it changed to 42
 * 
 * Parameters:
 * None
 * 
 * Return:
 * 0 on successful execution
 * 
 * Examples:
 * ./ft_ultimate_ft shows before/after values through 9 pointer levels
 **********************/
int main(void)
{
	int value = 10;				/* Initialize the target integer variable */
	int *ptr1 = &value;			/* First level pointer points to value */
	int **ptr2 = &ptr1;			/* Second level pointer points to ptr1 */
	int ***ptr3 = &ptr2;		/* Third level pointer points to ptr2 */
	int ****ptr4 = &ptr3;		/* Fourth level pointer points to ptr3 */
	int *****ptr5 = &ptr4;		/* Fifth level pointer points to ptr4 */
	int ******ptr6 = &ptr5;		/* Sixth level pointer points to ptr5 */
	int *******ptr7 = &ptr6;	/* Seventh level pointer points to ptr6 */
	int ********ptr8 = &ptr7;	/* Eighth level pointer points to ptr7 */
	int *********ptr9 = &ptr8;	/* Ninth level pointer points to ptr8 */
	
	write(1, "Before ft_ultimate_ft: value = ", 32);	/* Display header */
	ft_putnbr(value);								/* Display original value */
	write(1, "\n", 1);								/* Write newline */
	
	ft_ultimate_ft(ptr9);		/* Call function with 9th level pointer */
	
	write(1, "After ft_ultimate_ft: value = ", 31);	/* Display header */
	ft_putnbr(value);								/* Display modified value (should be 42) */
	write(1, "\n", 1);								/* Write newline */
	
	return (0);					/* Return success status to the operating system */
}