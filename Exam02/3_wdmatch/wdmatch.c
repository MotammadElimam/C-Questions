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
// to run it : ./wdmatch "faya" "fgvvfdxcacpolhyghbreda" | cat -e
// to run it : ./wdmatch "faya" "fgvvfdxcacpolhyghbred" | cat -e
// to run it : ./wdmatch "quarante deux" "qfqfsudf arzgsayns tsregfdgs sjytdekuoixq " | cat -e
// to run it : ./wdmatch "error" rrerrrfiiljdfxjyuifrrvcoojh | cat -e
// to run it : ./wdmatch | cat -e
//******************************************************

#include <unistd.h>

/**********************
 * ft_strlen - Calculates the length of a string
 * 
 * Description:
 * This helper function counts the number of characters
 * in a string until the null terminator is reached.
 * Used to determine if all characters from the first
 * string were successfully matched.
 * 
 * Parameters:
 * @str: The string to measure
 * 
 * Return:
 * The length of the string (number of characters)
 * 
 * Examples:
 * ft_strlen("hello") returns 5
 * ft_strlen("") returns 0
 **********************/
int	ft_strlen(char *str)
{
	int len = 0;						/* Length counter */
	
	while (str[len])					/* Count characters until null terminator */
		len++;							/* Increment length counter */
	
	return (len);						/* Return total length */
}

/**********************
 * ft_wdmatch - Checks if first string can be formed from second string
 * 
 * Description:
 * This function checks whether it's possible to write the first
 * string using characters from the second string while respecting
 * the order in which characters appear in the second string.
 * It uses a two-pointer approach to match characters sequentially.
 * 
 * Algorithm:
 * 1. Initialize pointers for both strings
 * 2. Iterate through second string looking for matches
 * 3. When match found, advance first string pointer
 * 4. Check if all characters from first string were matched
 * 5. Print first string if complete match found
 * 
 * Parameters:
 * @str1: The string to match (target)
 * @str2: The string to search in (source)
 * 
 * Return:
 * void - No return value (output written directly)
 * 
 * Examples:
 * ft_wdmatch("abc", "aabbcc") outputs "abc" (match found)
 * ft_wdmatch("abc", "acb") outputs nothing (order not preserved)
 **********************/
void	ft_wdmatch(char *str1, char *str2)
{
	int i = 0;							/* Index for first string (target) */
	int j = 0;							/* Index for second string (source) */
	int str1_len = ft_strlen(str1);		/* Length of target string */
	
	while (str2[j] && i < str1_len)		/* Search through source string */
	{
		if (str1[i] == str2[j])			/* Character match found */
			i++;						/* Move to next character in target */
		j++;							/* Always move to next character in source */
	}
	
	if (i == str1_len)					/* Check if all target characters matched */
	{
		i = 0;							/* Reset index to print the string */
		while (str1[i])					/* Print the matched string */
		{
			write(1, &str1[i], 1);		/* Write current character */
			i++;						/* Move to next character */
		}
	}
}

/**********************
 * main - Entry point for word match program
 * 
 * Description:
 * This program takes two strings as command line arguments and
 * checks if the first string can be formed using characters from
 * the second string in order. If possible, it prints the first
 * string, otherwise just prints a newline.
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
 * ./wdmatch "abc" "aabbcc" -> outputs "abc\n"
 * ./wdmatch "abc" "acb" -> outputs "\n"
 **********************/
int main(int argc, char **argv)
{
	if (argc == 3)						/* Check if exactly two arguments provided */
		ft_wdmatch(argv[1], argv[2]);	/* Call function to check word match */
	write(1, "\n", 1);					/* Always write newline at end */
	return (0);							/* Return success */
}