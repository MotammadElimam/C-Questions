//******************************************************
// Assignment name  : union
// Expected files   : union.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that takes two strings and displays, without doubles, the
// characters that appear in either one of the strings.

// The display will be in the order characters appear in the command line, and
// will be followed by a \n.

// If the number of arguments is not 2, the program displays \n.

// Example:

// $>./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
// zpadintoqefwjy$
// $>./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
// df6vewg4thras$
// $>./union "rien" "cette phrase ne cache rien" | cat -e
// rienct phas$
// $>./union | cat -e
// $
// $>
// $>./union "rien" | cat -e
// $
// $>
//******************************************************
// to compile it : gcc -Wall -Wextra -Werror union.c -o union
// to run it : ./union "zpadinton" "paqefwtdjetyiytjneytjoeyjnejeyj"
// to run it : ./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd
// to run it : ./union "rien" "cette phrase ne cache rien"
// to run it : ./union
// to run it : ./union "rien"
//******************************************************

#include <unistd.h>

/**********************
 * ft_union - Displays union of characters from two strings
 * 
 * Description:
 * This function displays all unique characters that appear in
 * either of the two input strings, without duplicates, in the
 * order they appear across both strings. The first string is
 * processed entirely, then the second string, but only characters
 * not already seen are printed.
 * 
 * Algorithm:
 * 1. Initialize a boolean array to track printed characters
 * 2. For each character in the first string:
 *    - If not previously printed, print it and mark as printed
 * 3. For each character in the second string:
 *    - If not previously printed, print it and mark as printed
 * 
 * Parameters:
 * @str1: First string to process
 * @str2: Second string to process
 * 
 * Return:
 * void - No return value (output is written directly)
 * 
 * Examples:
 * ft_union("abc", "bcd") outputs "abcd"
 * ft_union("hello", "world") outputs "helowrd"
 **********************/
void	ft_union(char *str1, char *str2)
{
	int i = 0;							/* Index for string iteration */
	char printed[256] = {0};			/* Array to track which characters have been printed */
	
	while (str1[i])						/* Iterate through each character in first string */
	{
		if (!printed[(unsigned char)str1[i]])		/* Check if character hasn't been printed */
		{
			write(1, &str1[i], 1);					/* Write the character to stdout */
			printed[(unsigned char)str1[i]] = 1;	/* Mark character as printed */
		}
		i++;							/* Move to next character */
	}
	i = 0;								/* Reset index for second string */
	while (str2[i])						/* Iterate through each character in second string */
	{
		if (!printed[(unsigned char)str2[i]])		/* Check if character hasn't been printed */
		{
			write(1, &str2[i], 1);					/* Write the character to stdout */
			printed[(unsigned char)str2[i]] = 1;	/* Mark character as printed */
		}
		i++;							/* Move to next character */
	}
}

/**********************
 * main - Entry point for string union program
 * 
 * Description:
 * This program takes two strings as command line arguments and
 * displays all unique characters from both strings using the
 * ft_union function. If incorrect number of arguments provided,
 * it only prints a newline.
 * 
 * Usage:
 * ./union "string1" "string2"
 * 
 * Parameters:
 * @argc: Number of command line arguments
 * @argv: Array of command line argument strings
 * 
 * Return:
 * 0 on successful execution
 * 
 * Examples:
 * ./union "abc" "def" -> outputs "abcdef\n"
 * ./union "hello" "hello" -> outputs "helo\n"
 **********************/
int main(int argc, char **argv)
{
	if (argc == 3)						/* Check if exactly two arguments provided */
		ft_union(argv[1], argv[2]);	/* Call union function with both strings */
	write(1, "\n", 1);					/* Always write a newline at the end */
	return (0);							/* Return success */
}