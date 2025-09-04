/*
 ******************************************************
Create a function that displays the alphabet in lowercase, on a single line, in descending order, starting from the letter 'z'.
The function should be prototyped as follows:
void ft_print_reverse_alphabet(void);
 
 ******************************************************
 * to compile it : gcc ft_print_reverse_alphabet.c
 * to run it : ./a.out
 ******************************************************
 */

#include <unistd.h>

/**********************
 * ft_print_reverse_alphabet - Displays the lowercase alphabet in descending order
 * 
 * Description:
 * This function prints all 26 letters of the English alphabet
 * in lowercase, from 'z' to 'a', on a single line in descending
 * order. Each letter is displayed consecutively without any
 * separators between them.
 * 
 * Algorithm:
 * 1. Initialize a character variable with 'z'
 * 2. Use a while loop to iterate through all letters in reverse
 * 3. For each iteration:
 *    - Write the current character to standard output
 *    - Decrement to the previous letter
 * 4. Continue until 'a' is reached and printed
 * 
 * Parameters:
 * None
 * 
 * Return:
 * void - No return value (output is written directly)
 * 
 * Examples:
 * ft_print_reverse_alphabet() outputs "zyxwvutsrqponmlkjihgfedcba"
 **********************/
void	ft_print_reverse_alphabet(void)
{
	char c = 'z';				/* Initialize character variable with last letter 'z' */
	
	while (c >= 'a')			/* Continue loop while character is within alphabet range */
	{
		write(1, &c, 1);		/* Write current character to standard output */
		c--;					/* Decrement to previous letter in alphabet */
	}
}

/**********************
 * main - Entry point for reverse alphabet display program
 * 
 * Description:
 * This program demonstrates the ft_print_reverse_alphabet function by
 * displaying the complete lowercase alphabet in reverse order. It serves
 * as a test program to verify that all letters are printed correctly
 * in descending sequence from z to a.
 * 
 * Algorithm:
 * 1. Call ft_print_reverse_alphabet to display the reverse alphabet
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
 * ./ft_print_reverse_alphabet outputs "zyxwvutsrqponmlkjihgfedcba\n"
 **********************/
int main(void)
{
	ft_print_reverse_alphabet();	/* Call function to display the reverse lowercase alphabet */
	write(1, "\n", 1);				/* Write newline character for better output formatting */
	return (0);						/* Return success status to the operating system */
}