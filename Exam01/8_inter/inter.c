//******************************************************
// Assignment name  : inter
// Expected files   : inter.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that takes two strings and displays, without doubles, the
// characters that appear in both strings, in the order they appear in the first
// one.

// The display will be followed by a \n.

// If the number of arguments is not 2, the program displays \n.

// Examples:

// $>./inter "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
// padinto$
// $>./inter ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
// df6ewg4$
// $>./inter "rien" "cette phrase ne cache rien" | cat -e
// rien$
// $>./inter | cat -e
// $
//******************************************************
// to compile it : gcc -Wall -Wextra -Werror inter.c -o inter
// to run it : ./inter "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj"
// to run it : ./inter ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd
// to run it : ./inter "rien" "cette phrase ne cache rien"
// to run it : ./inter
//******************************************************

#include <unistd.h>

/**********************
 * ft_inter - Finds and displays intersection of two strings
 * 
 * Description:
 * This function displays characters that appear in both input strings,
 * without duplicates, in the order they appear in the first string.
 * It uses a boolean array to track already printed characters to avoid
 * duplicate output.
 * 
 * Algorithm:
 * 1. Initialize a boolean array to track printed characters
 * 2. For each character in the first string:
 *    - Search for the character in the second string
 *    - If found and not previously printed:
 *      a. Print the character
 *      b. Mark it as printed in the tracking array
 *      c. Break from inner loop
 * 
 * Parameters:
 * @str1: First string (determines order of output)
 * @str2: Second string to check against
 * 
 * Return:
 * void - No return value (output is written directly)
 * 
 * Examples:
 * ft_inter("padinton", "paqefwtdjetyiytjneytjoeyjnejeyj") outputs "padinto"
 * ft_inter("hello", "world") outputs "lo"
 **********************/
void	ft_inter(char *str1, char *str2)
{
	int i = 0;							/* Index for first string iteration */
	int j;								/* Index for second string iteration */
	char printed[256] = {0};			/* Array to track which characters have been printed */
	
	while (str1[i])						/* Iterate through each character in the first string */
	{
		j = 0;							/* Reset second string index for each first string character */
		while (str2[j])					/* Iterate through each character in the second string */
		{
			if (str1[i] == str2[j] && !printed[(unsigned char)str1[i]])	/* Check if characters match and haven't been printed */
			{
				write(1, &str1[i], 1);								/* Write the matching character to stdout */
				printed[(unsigned char)str1[i]] = 1;				/* Mark this character as printed to avoid duplicates */
				break;												/* Exit inner loop since match was found */
			}
			j++;						/* Move to next character in second string */
		}
		i++;							/* Move to next character in first string */
	}
}

/**********************
 * main - Entry point for string intersection program
 * 
 * Description:
 * This program takes two strings as command line arguments and
 * displays characters that appear in both strings using the
 * ft_inter function. If incorrect number of arguments provided,
 * it only prints a newline.
 * 
 * Usage:
 * ./inter "string1" "string2"
 * 
 * Parameters:
 * @argc: Number of command line arguments
 * @argv: Array of command line argument strings
 * 
 * Return:
 * 0 on successful execution
 * 
 * Examples:
 * ./inter "abc" "bcd" -> outputs "bc\n"
 * ./inter "hello" "world" -> outputs "lo\n"
 **********************/
int main(int argc, char **argv)
{
	if (argc == 3)						/* Check if exactly two arguments are provided */
		ft_inter(argv[1], argv[2]);	/* Call intersection function with both strings */
	write(1, "\n", 1);					/* Always write a newline at the end */
	return (0);							/* Return success */
}