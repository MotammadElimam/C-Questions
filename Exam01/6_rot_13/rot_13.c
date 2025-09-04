//******************************************************
// Assignment name  : rot_13
// Expected files   : rot_13.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that takes a string and displays it, replacing each of its
// letters by the letter 13 spaces ahead in alphabetical order.

// 'z' becomes 'm' and 'Z' becomes 'M'. Case remains unaffected.

// The output will be followed by a newline.

// If the number of arguments is not 1, the program displays a newline.

// Example:

// $>./rot_13 "abc"
// nop
// $>./rot_13 "My horse is Amazing." | cat -e
// Zl ubefr vf Nznmvat.$
// $>./rot_13 "AkjhZ zLKIJz , 23y " | cat -e
// NxwuM mYXVWm , 23l $
// $>./rot_13 | cat -e
// $
// $>
// $>./rot_13 "" | cat -e
// $
// $>
//******************************************************
// to compile it : gcc -Wall -Wextra -Werror rot_13.c -o rot_13
// to run it : ./rot_13 "abc"
// to run it : ./rot_13 "My horse is Amazing."
// to run it : ./rot_13 "AkjhZ zLKIJz , 23y "
// to run it : ./rot_13
// to run it : ./rot_13 ""
//******************************************************

#include <unistd.h>

/**********************
 * ft_rot13 - Applies ROT13 cipher transformation to a string
 * 
 * Description:
 * This function implements the ROT13 substitution cipher algorithm.
 * Each letter in the input string is replaced with the letter 13
 * positions ahead in the alphabet. The transformation wraps around,
 * so 'z' becomes 'm' and 'Z' becomes 'M'. Non-alphabetic characters
 * remain unchanged.
 * 
 * Algorithm:
 * 1. Iterate through each character of the string
 * 2. For each character:
 *    - If it's in first half of alphabet (a-m or A-M): add 13
 *    - If it's in second half of alphabet (n-z or N-Z): subtract 13
 *    - If it's not a letter: leave unchanged
 * 3. Write each transformed character directly to stdout
 * 
 * Parameters:
 * @str: Pointer to the string to be transformed
 * 
 * Return:
 * void - No return value (output is written directly)
 * 
 * Examples:
 * ft_rot13("abc") outputs "nop"
 * ft_rot13("Hello") outputs "Uryyb"
 **********************/
void	ft_rot13(char *str)
{
	int i = 0;						/* Index for string traversal */
	char c;							/* Current character being processed */
	
	while (str[i])					/* Loop through each character until null terminator */
	{
		c = str[i];					/* Get current character */
		if ((c >= 'a' && c <= 'm') || (c >= 'A' && c <= 'M'))		/* First half of alphabet */
			c += 13;				/* Rotate forward by 13 positions */
		else if ((c >= 'n' && c <= 'z') || (c >= 'N' && c <= 'Z'))	/* Second half of alphabet */
			c -= 13;				/* Rotate backward by 13 positions */
		write(1, &c, 1);			/* Write transformed character to stdout */
		i++;						/* Move to next character */
	}
}

/**********************
 * main - Entry point for ROT13 cipher program
 * 
 * Description:
 * This program takes a string as command line argument and applies
 * the ROT13 transformation using the ft_rot13 function. If no argument
 * or multiple arguments are provided, it only prints a newline.
 * 
 * Usage:
 * ./rot_13 "text to encode"
 * 
 * Parameters:
 * @argc: Number of command line arguments
 * @argv: Array of command line argument strings
 * 
 * Return:
 * 0 on successful execution
 * 
 * Examples:
 * ./rot_13 "abc" -> outputs "nop\n"
 * ./rot_13 "My horse" -> outputs "Zl ubefr\n"
 * ./rot_13 -> outputs "\n"
 **********************/
int main(int argc, char **argv)
{
	if (argc == 2)					/* Check if exactly one argument provided */
		ft_rot13(argv[1]);			/* Apply ROT13 transformation to input string */
	write(1, "\n", 1);				/* Always print newline at end */
	return (0);						/* Return success */
}