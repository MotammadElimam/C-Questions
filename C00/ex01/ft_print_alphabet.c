/*
 ******************************************************
 Create a function that displays the alphabet in lowercase, on a single line, in ascending order, starting from the letter 'a'.
 The function should be prototyped as follows:
 void ft_print_alphabet(void);
 
 ******************************************************
 * to compile it : gcc ft_print_alphabet.c
 * to run it : ./a.out
 ******************************************************
 */

#include <unistd.h>

/**********************
 * ft_print_alphabet - Displays the lowercase alphabet in ascending order
 * 
 * Description:
 * This function prints all 26 letters of the English alphabet
 * in lowercase, from 'a' to 'z', on a single line in ascending
 * order. Each letter is displayed consecutively without any
 * separators between them.
 * 
 * Algorithm:
 * 1. Initialize a character variable with 'a'
 * 2. Use a while loop to iterate through all letters
 * 3. For each iteration:
 *    - Write the current character to standard output
 *    - Increment to the next letter
 * 4. Continue until 'z' is reached and printed
 * 
 * Parameters:
 * None
 * 
 * Return:
 * void - No return value (output is written directly)
 * 
 * Examples:
 * ft_print_alphabet() outputs "abcdefghijklmnopqrstuvwxyz"
 **********************/
void	ft_print_alphabet(void)
{
	char c = 'a';				/* Initialize character variable with first letter 'a' */
	
	while (c <= 'z')			/* Continue loop while character is within alphabet range */
	{
		write(1, &c, 1);		/* Write current character to standard output */
		c++;					/* Increment to next letter in alphabet */
	}
}

/**********************
 * main - Entry point for alphabet display program
 * 
 * Description:
 * This program demonstrates the ft_print_alphabet function by
 * displaying the complete lowercase alphabet. It serves as a
 * test program to verify that all letters are printed correctly
 * in the proper sequence.
 * 
 * Algorithm:
 * 1. Call ft_print_alphabet to display the alphabet
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
 * ./ft_print_alphabet outputs "abcdefghijklmnopqrstuvwxyz\n"
 **********************/
int main(void)
{
	ft_print_alphabet();		/* Call function to display the lowercase alphabet */
	write(1, "\n", 1);			/* Write newline character for better output formatting */
	return (0);					/* Return success status to the operating system */
}