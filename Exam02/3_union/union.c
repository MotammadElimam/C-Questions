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
// to run it : ./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
// to run it : ./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
// to run it : ./union "rien" "cette phrase ne cache rien" | cat -e
// to run it : ./union | cat -e
// to run it : ./union "rien" | cat -e
//******************************************************

#include <unistd.h>

/**********************
 * char_seen_before - Checks if character appeared earlier in output
 * 
 * Description:
 * This helper function checks if a character has already been
 * printed by looking through both strings up to current positions.
 * This prevents duplicate characters from appearing in the union.
 * 
 * Algorithm:
 * 1. Check first string from start to current position (exclusive)
 * 2. If not found and checking second string, check entire first string
 * 3. Check second string from start to current position (exclusive)
 * 4. Return 1 if character was seen before, 0 otherwise
 * 
 * Parameters:
 * @str1: First string to check
 * @str2: Second string to check
 * @pos1: Current position in first string (-1 if checking second string)
 * @pos2: Current position in second string (-1 if checking first string)
 * @c: Character to check for duplicates
 * 
 * Return:
 * 1 if character appeared earlier, 0 otherwise
 **********************/
int	char_seen_before(char *str1, char *str2, int pos1, int pos2, char c)
{
	int i = 0;							/* Index for iteration */
	
	/* Check first string up to current position */
	while (i < pos1)					/* Only check if pos1 is valid */
	{
		if (str1[i] == c)				/* Character found in first string */
			return (1);					/* Return 1 (already seen) */
		i++;							/* Move to next character */
	}
	
	/* If checking second string, check entire first string */
	if (pos1 == -1)						/* We're checking second string */
	{
		i = 0;							/* Reset index */
		while (str1[i])					/* Check entire first string */
		{
			if (str1[i] == c)			/* Character found in first string */
				return (1);				/* Return 1 (already seen) */
			i++;						/* Move to next character */
		}
	}
	
	/* Check second string up to current position */
	i = 0;								/* Reset index */
	while (i < pos2)					/* Only check if pos2 is valid */
	{
		if (str2[i] == c)				/* Character found in second string */
			return (1);					/* Return 1 (already seen) */
		i++;							/* Move to next character */
	}
	
	return (0);							/* Character not seen before */
}

/**********************
 * ft_union - Prints union of characters from two strings
 * 
 * Description:
 * This function creates a union of characters from two strings,
 * printing each unique character only once in the order they
 * first appear across both strings. It processes the first
 * string completely, then the second string.
 * 
 * Algorithm:
 * 1. Process each character in the first string
 * 2. Print character if not seen before in first string
 * 3. Process each character in the second string
 * 4. Print character if not seen before in either string
 * 
 * Parameters:
 * @str1: First string for union
 * @str2: Second string for union
 * 
 * Return:
 * void - No return value (output written directly)
 * 
 * Examples:
 * ft_union("abc", "bcd") outputs "abcd"
 * ft_union("hello", "world") outputs "helowrd"
 **********************/
void	ft_union(char *str1, char *str2)
{
	int i = 0;							/* Index for first string */
	
	/* Process first string */
	while (str1[i])						/* Iterate through first string */
	{
		if (!char_seen_before(str1, str2, i, -1, str1[i]))	/* Check if not seen */
			write(1, &str1[i], 1);		/* Write character if unique */
		i++;							/* Move to next character */
	}
	
	/* Process second string */
	i = 0;								/* Reset index for second string */
	while (str2[i])						/* Iterate through second string */
	{
		if (!char_seen_before(str1, str2, -1, i, str2[i]))	/* Check if not seen */
			write(1, &str2[i], 1);		/* Write character if unique */
		i++;							/* Move to next character */
	}
}

/**********************
 * main - Entry point for string union program
 * 
 * Description:
 * This program takes two strings as command line arguments and
 * displays the union of characters from both strings without
 * duplicates. Characters appear in the order they first occur
 * across both strings. If incorrect number of arguments provided,
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
 * ./union "hello" "world" -> outputs "helowrd\n"
 **********************/
int main(int argc, char **argv)
{
	if (argc == 3)						/* Check if exactly two arguments provided */
		ft_union(argv[1], argv[2]);		/* Call function to create union */
	write(1, "\n", 1);					/* Always write newline at end */
	return (0);							/* Return success */
}