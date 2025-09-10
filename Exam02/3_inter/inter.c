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
// to run it : ./inter "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
// to run it : ./inter ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
// to run it : ./inter "rien" "cette phrase ne cache rien" | cat -e
// to run it : ./inter | cat -e
//******************************************************

#include <unistd.h>

/**********************
 * char_in_string - Checks if a character exists in a string
 * 
 * Description:
 * This helper function searches through a string to determine
 * if a specific character exists within it. It performs a
 * linear search through the string until the character is
 * found or the end of string is reached.
 * 
 * Algorithm:
 * 1. Iterate through each character in the string
 * 2. Compare each character with the target character
 * 3. Return 1 if character is found, 0 if not found
 * 
 * Parameters:
 * @str: The string to search in
 * @c: The character to search for
 * 
 * Return:
 * 1 if character is found in string, 0 otherwise
 * 
 * Examples:
 * char_in_string("hello", 'e') returns 1
 * char_in_string("hello", 'x') returns 0
 **********************/
int		char_in_string(char *str, char c)
{
	int i = 0;							/* Index to traverse the string */
	
	while (str[i])						/* Search through the string */
	{
		if (str[i] == c)				/* Check if current character matches target */
			return (1);					/* Character found - return 1 */
		i++;							/* Move to next character */
	}
	return (0);							/* Character not found - return 0 */
}

/**********************
 * char_already_printed - Checks if character was already processed
 * 
 * Description:
 * This helper function checks if a character has already been
 * processed in the first string by looking at characters before
 * the current position. This prevents duplicate characters
 * from being printed in the output.
 * 
 * Algorithm:
 * 1. Iterate through string from start to current position (exclusive)
 * 2. Compare each character with the target character
 * 3. Return 1 if character was found earlier, 0 otherwise
 * 
 * Parameters:
 * @str: The string being processed
 * @pos: Current position in the string
 * @c: The character to check for duplicates
 * 
 * Return:
 * 1 if character appeared earlier in string, 0 otherwise
 * 
 * Examples:
 * char_already_printed("hello", 3, 'l') returns 1 (l at pos 2)
 * char_already_printed("hello", 1, 'e') returns 0 (e first occurrence)
 **********************/
int		char_already_printed(char *str, int pos, char c)
{
	int i = 0;							/* Index to check previous positions */
	
	while (i < pos)						/* Check all positions before current */
	{
		if (str[i] == c)				/* Check if character appeared earlier */
			return (1);					/* Character was already seen - return 1 */
		i++;							/* Move to next position */
	}
	return (0);							/* Character not seen before - return 0 */
}

/**********************
 * ft_inter - Finds and prints intersection of two strings
 * 
 * Description:
 * This function finds characters that appear in both strings
 * and prints them without duplicates, in the order they appear
 * in the first string. It uses helper functions to check for
 * character existence and prevent duplicate output.
 * 
 * Algorithm:
 * 1. Iterate through each character in the first string
 * 2. Check if current character exists in the second string
 * 3. Check if current character hasn't been printed already
 * 4. If both conditions are met, print the character
 * 5. Continue until end of first string
 * 
 * Parameters:
 * @str1: The first string (order reference)
 * @str2: The second string (intersection reference)
 * 
 * Return:
 * void - No return value (output is written directly)
 * 
 * Examples:
 * ft_inter("abc", "bcd") outputs "bc"
 * ft_inter("hello", "world") outputs "llo"
 **********************/
void	ft_inter(char *str1, char *str2)
{
	int i = 0;							/* Index to traverse first string */
	
	while (str1[i])						/* Process each character in first string */
	{
		/* Check if char is in second string AND not already printed */
		if (char_in_string(str2, str1[i]) && !char_already_printed(str1, i, str1[i]))
		{
			write(1, &str1[i], 1);		/* Write the intersection character */
		}
		i++;							/* Move to next character */
	}
}

/**********************
 * main - Entry point for string intersection program
 * 
 * Description:
 * This program takes two strings as command line arguments and
 * displays characters that appear in both strings, without
 * duplicates, in the order they appear in the first string.
 * If incorrect number of arguments provided, it only prints
 * a newline.
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
 * ./inter "hello" "world" -> outputs "llo\n"
 * ./inter "abc" "def" -> outputs "\n"
 **********************/
int main(int argc, char **argv)
{
	if (argc == 3)						/* Check if exactly two arguments provided */
		ft_inter(argv[1], argv[2]);		/* Call function to find intersection */
	write(1, "\n", 1);					/* Always write a newline at the end */
	return (0);							/* Return success */
}