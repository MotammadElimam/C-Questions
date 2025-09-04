//******************************************************
// Assignment name  : first_word
// Expected files   : first_word.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that takes a string and displays its first word, followed by a
// newline.

// A word is a section of string delimited by spaces/tabs or by the start/end of
// the string.

// If the number of parameters is not 1, or if there are no words, simply display
// a newline.

// Examples:

// $> ./first_word "FOR PONY" | cat -e
// FOR$
// $> ./first_word "this        ...       is sparta, then again, maybe    not" | cat -e
// this$
// $> ./first_word "   " | cat -e
// $
// $> ./first_word "a" "b" | cat -e
// $
// $> ./first_word "  lorem,ipsum  " | cat -e
// lorem,ipsum$
// $>

//******************************************************
// to compile it : gcc -Wall -Wextra -Werror first_word.c -o first_word
// to run it : ./first_word "FOR PONY"
// to run it : ./first_word "this        ...       is sparta, then again, maybe    not"
// to run it : ./first_word "   "
// to run it : ./first_word "a" "b"
// to run it : ./first_word "  lorem,ipsum  "
//******************************************************
// The flags mean:
//******************************************************
//   - -Wall: Enable all common warnings
//   - -Wextra: Enable extra warning flags
//   - -Werror: Treat warnings as errors
//   - -o first_word: Name the output executable "first_word"
//******************************************************

#include <unistd.h>

/**********************
 * ft_first_word - Extracts and prints the first word from a string
 * 
 * Description:
 * This function identifies and prints the first word found in a string.
 * A word is defined as a sequence of characters delimited by spaces,
 * tabs, or the beginning/end of the string. Leading whitespace is
 * automatically skipped.
 * 
 * Algorithm:
 * 1. Skip all leading spaces and tabs
 * 2. Print characters until a space, tab, or end of string
 * 3. Stop after the first word is complete
 * 
 * Parameters:
 * @str: The input string containing words
 * 
 * Return:
 * void - No return value
 * 
 * Example:
 * ft_first_word("  Hello World") prints "Hello"
 * ft_first_word("\ttest") prints "test"
 **********************/
void	ft_first_word(char *str)
{
	int i = 0;                                              /* Index for string traversal */
	
	while (str[i] == ' ' || str[i] == '\t')                /* Skip leading spaces and tabs */
		i++;                                            /* Move to next character */
	while (str[i] && str[i] != ' ' && str[i] != '\t')      /* While still in word */
	{
		write(1, &str[i], 1);                           /* Print current character */
		i++;                                            /* Move to next character */
	}
}

/**********************
 * main - Program that displays the first word of input
 * 
 * Description:
 * This program extracts and prints the first word from a string
 * provided as command line argument. Words are delimited by spaces
 * or tabs. If incorrect number of arguments, prints only newline.
 * 
 * Usage:
 * ./first_word "string with words"
 * 
 * Parameters:
 * @argc: Argument count (must be 2 for proper output)
 * @argv: Argument vector containing the input string
 * 
 * Return:
 * 0 on successful execution
 * 
 * Examples:
 * ./first_word "FOR PONY" -> outputs "FOR\n"
 * ./first_word "   spaces   test" -> outputs "spaces\n"
 **********************/
int main(int argc, char **argv)
{
	if (argc == 2)                                         /* Check if exactly one argument provided */
		ft_first_word(argv[1]);                        /* Call function to print first word */
	write(1, "\n", 1);                                     /* Always print newline at end */
	return (0);                                             /* Return success */
}