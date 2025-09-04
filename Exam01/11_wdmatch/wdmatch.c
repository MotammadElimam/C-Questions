//******************************************************
// Assignment name  : wdmatch
// Expected files   : wdmatch.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that takes two strings and checks whether it's possible to
// write the first string with characters from the second string, while respecting
// the order in which these characters appear in the second string.

// If it's possible, the program displays the string, followed by a \n, otherwise
// it simply displays a \n.

// If the number of arguments is not 2, the program displays a \n.

// Examples:

// $>./wdmatch "faya" "fgvvfdxcacpolhyghbreda" | cat -e
// faya$
// $>./wdmatch "faya" "fgvvfdxcacpolhyghbred" | cat -e
// $
// $>./wdmatch "quarante deux" "qfqfsudf arzgsayns tsregfdgs sjytdekuoixq " | cat -e
// quarante deux$
// $>./wdmatch "error" rrerrrfiiljdfxjyuifrrvcoojh | cat -e
// $
// $>./wdmatch | cat -e
// $
//******************************************************
// to compile it : gcc -Wall -Wextra -Werror wdmatch.c -o wdmatch
// to run it : ./wdmatch "faya" "fgvvfdxcacpolhyghbreda"
// to run it : ./wdmatch "faya" "fgvvfdxcacpolhyghbred"
// to run it : ./wdmatch "quarante deux" "qfqfsudf arzgsayns tsregfdgs sjytdekuoixq "
// to run it : ./wdmatch "error" rrerrrfiiljdfxjyuifrrvcoojh
// to run it : ./wdmatch
//******************************************************

#include <unistd.h>

/**********************
 * ft_wdmatch - Checks if word can be formed from source string
 * 
 * Description:
 * This function determines if the target word can be constructed
 * using characters from the source string, while maintaining the
 * order of characters as they appear in the source. If possible,
 * it prints the target word; otherwise prints nothing.
 * 
 * Algorithm:
 * 1. Use two pointers: one for target word, one for source string
 * 2. Iterate through source string:
 *    - If current source character matches current target character,
 *      advance target pointer
 *    - Always advance source pointer
 * 3. If target pointer reached end (all characters found), print target
 * 
 * Parameters:
 * @target: The word to be matched
 * @source: The string to search characters from
 * 
 * Return:
 * void - No return value (output is written directly)
 * 
 * Examples:
 * ft_wdmatch("faya", "fgvvfdxcacpolhyghbreda") outputs "faya"
 * ft_wdmatch("abc", "acb") outputs nothing (order not preserved)
 **********************/
void	ft_wdmatch(char *target, char *source)
{
	int i = 0;							/* Index for target word */
	int j = 0;							/* Index for source string */
	
	while (source[j] && target[i])		/* Continue while both strings have characters */
	{
		if (source[j] == target[i])	/* If characters match */
			i++;						/* Move to next character in target */
		j++;							/* Always move to next character in source */
	}
	if (target[i] == '\0')				/* If all target characters were found */
	{
		i = 0;							/* Reset index to print the target */
		while (target[i])				/* Iterate through target word */
		{
			write(1, &target[i], 1);	/* Write current character to stdout */
			i++;						/* Move to next character */
		}
	}
}

/**********************
 * main - Entry point for word matching program
 * 
 * Description:
 * This program takes two strings as command line arguments and
 * checks if the first string can be formed from characters in
 * the second string (in order) using the ft_wdmatch function.
 * If incorrect number of arguments provided, it only prints
 * a newline.
 * 
 * Usage:
 * ./wdmatch "target" "source"
 * 
 * Parameters:
 * @argc: Number of command line arguments
 * @argv: Array of command line argument strings
 * 
 * Return:
 * 0 on successful execution
 * 
 * Examples:
 * ./wdmatch "faya" "fgvvfdxcacpolhyghbreda" -> outputs "faya\n"
 * ./wdmatch "test" "txst" -> outputs "\n" (e missing)
 **********************/
int main(int argc, char **argv)
{
	if (argc == 3)						/* Check if exactly two arguments provided */
		ft_wdmatch(argv[1], argv[2]);	/* Call matching function */
	write(1, "\n", 1);					/* Always write a newline at the end */
	return (0);							/* Return success */
}