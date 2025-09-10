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
 * ft_union - Prints union of two strings without duplicates
 * 
 * Description:
 * This function uses a simple array to track which characters
 * have already been printed. The array has 256 positions (one
 * for each possible ASCII character). When we print a character,
 * we mark it as printed in the array.
 * 
 * Simple algorithm:
 * 1. Create an array to track printed characters (all zeros initially)
 * 2. Go through first string - print and mark each new character
 * 3. Go through second string - print and mark each new character
 * 
 * Parameters:
 * @str1: First string
 * @str2: Second string
 * 
 * Return:
 * void - No return value
 **********************/
void ft_union(char *str1, char *str2)
{
	char printed[256] = {0};  /* Array to track which characters were printed */
	int i;  /* Index for going through strings */
	
	/* Process first string */
	i = 0;  /* Start at beginning of first string */
	while (str1[i])  /* Go through each character in first string */
	{
		/* Check if this character was not printed yet */
		if (!printed[(unsigned char)str1[i]])  /* Character is new */
		{
			write(1, &str1[i], 1);  /* Print the character */
			printed[(unsigned char)str1[i]] = 1;  /* Mark as printed */
		}
		i++;  /* Move to next character */
	}
	
	/* Process second string */
	i = 0;  /* Start at beginning of second string */
	while (str2[i])  /* Go through each character in second string */
	{
		/* Check if this character was not printed yet */
		if (!printed[(unsigned char)str2[i]])  /* Character is new */
		{
			write(1, &str2[i], 1);  /* Print the character */
			printed[(unsigned char)str2[i]] = 1;  /* Mark as printed */
		}
		i++;  /* Move to next character */
	}
}

/**********************
 * main - Entry point for union program
 * 
 * Description:
 * Takes two strings as arguments and prints their union
 * (all unique characters from both strings in order).
 * If wrong number of arguments, just prints newline.
 * 
 * Parameters:
 * @argc: Number of arguments
 * @argv: Array of argument strings
 * 
 * Return:
 * 0 on success
 **********************/
int main(int argc, char **argv)
{
	/* Check if we have exactly 2 arguments (plus program name = 3 total) */
	if (argc == 3)  /* Correct number of arguments */
	{
		ft_union(argv[1], argv[2]);  /* Print union of the two strings */
	}
	
	write(1, "\n", 1);  /* Always print newline at the end */
	return (0);  /* Return success */
}