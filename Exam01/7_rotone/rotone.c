//******************************************************
// Assignment name  : rotone
// Expected files   : rotone.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that takes a string and displays it, replacing each of its
// letters by the next one in alphabetical order.

// 'z' becomes 'a' and 'Z' becomes 'A'. Case remains unaffected.

// The output will be followed by a \n.

// If the number of arguments is not 1, the program displays \n.

// Example:

// $>./rotone "abc"
// bcd
// $>./rotone "Les stagiaires du staff ne sentent pas toujours tres bon." | cat -e
// Mft tubhjbjsft ev tubgg of tfoufou qbt upvkpvst usft cpo.$
// $>./rotone "AkjhZ zLKIJz , 23y " | cat -e
// BlkiA aMLJKa , 23z $
// $>./rotone | cat -e
// $
// $>
// $>./rotone "" | cat -e
// $
// $>
//******************************************************
// to compile it : gcc -Wall -Wextra -Werror rotone.c -o rotone
// to run it : ./rotone "abc"
// to run it : ./rotone "Les stagiaires du staff ne sentent pas toujours tres bon."
// to run it : ./rotone "AkjhZ zLKIJz , 23y "
// to run it : ./rotone
// to run it : ./rotone ""
//******************************************************

#include <unistd.h>

/**********************
 * ft_rotone - Rotates each letter by one position in the alphabet
 * 
 * Description:
 * This function implements a Caesar cipher with a shift of 1.
 * Each alphabetic character is replaced with the next letter
 * in the alphabet. The transformation wraps around, so 'z'
 * becomes 'a' and 'Z' becomes 'A'. Non-alphabetic characters
 * remain unchanged and case is preserved.
 * 
 * Algorithm:
 * 1. Iterate through each character of the string
 * 2. For each character:
 *    - If it's a-y or A-Y: increment by 1
 *    - If it's 'z': change to 'a'
 *    - If it's 'Z': change to 'A'
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
 * ft_rotone("abc") outputs "bcd"
 * ft_rotone("xyz") outputs "yza"
 * ft_rotone("Hello") outputs "Ifmmp"
 **********************/
void	ft_rotone(char *str)
{
	int i = 0;						/* Index for string traversal */
	char c;							/* Current character being processed */
	
	while (str[i])					/* Loop through each character until null terminator */
	{
		c = str[i];					/* Get current character */
		if ((c >= 'a' && c <= 'y') || (c >= 'A' && c <= 'Y'))		/* Letters a-y or A-Y */
			c += 1;					/* Move to next letter in alphabet */
		else if (c == 'z')			/* Lowercase z */
			c = 'a';				/* Wrap around to a */
		else if (c == 'Z')			/* Uppercase Z */
			c = 'A';				/* Wrap around to A */
		write(1, &c, 1);			/* Write transformed character to stdout */
		i++;						/* Move to next character */
	}
}

/**********************
 * main - Entry point for rotone cipher program
 * 
 * Description:
 * This program takes a string as command line argument and applies
 * the rotone transformation (rotate by one) using the ft_rotone
 * function. If no argument or multiple arguments are provided,
 * it only prints a newline.
 * 
 * Usage:
 * ./rotone "text to encode"
 * 
 * Parameters:
 * @argc: Number of command line arguments
 * @argv: Array of command line argument strings
 * 
 * Return:
 * 0 on successful execution
 * 
 * Examples:
 * ./rotone "abc" -> outputs "bcd\n"
 * ./rotone "xyz" -> outputs "yza\n"
 * ./rotone -> outputs "\n"
 **********************/
int main(int argc, char **argv)
{
	if (argc == 2)					/* Check if exactly one argument provided */
		ft_rotone(argv[1]);		/* Apply rotone transformation to input string */
	write(1, "\n", 1);				/* Always print newline at end */
	return (0);						/* Return success */
}