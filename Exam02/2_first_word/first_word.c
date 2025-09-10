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
// to run it : ./first_word "FOR PONY" | cat -e
// to run it : ./first_word "this        ...       is sparta, then again, maybe    not" | cat -e
// to run it : ./first_word "   " | cat -e
// to run it : ./first_word "a" "b" | cat -e
// to run it : ./first_word "  lorem,ipsum  " | cat -e
//******************************************************

#include <unistd.h>

/**********************
 * ft_first_word - Extracts and prints the first word from a string
 * 
 * Description:
 * This function finds and displays the first word in a string.
 * A word is defined as a sequence of characters delimited by
 * spaces or tabs. The function handles leading whitespace by
 * skipping it to find the actual first word.
 * 
 * Algorithm:
 * 1. Skip leading whitespace (spaces and tabs)
 * 2. Print characters until whitespace is encountered or end of string
 * 3. Stop when first whitespace after word is found
 * 
 * Parameters:
 * @str: The input string to extract the first word from
 * 
 * Return:
 * void - No return value (output is written directly)
 * 
 * Examples:
 * ft_first_word("hello world") outputs "hello"
 * ft_first_word("  test  ") outputs "test"
 * ft_first_word("   ") outputs nothing
 **********************/
void	ft_first_word(char *str)
{
	int i = 0;							/* Index to traverse the string */
	
	while (str[i] == ' ' || str[i] == '\t')	/* Skip leading whitespace */
		i++;							/* Move past spaces and tabs */
	
	while (str[i] && str[i] != ' ' && str[i] != '\t')	/* Print first word */
	{
		write(1, &str[i], 1);			/* Write current character to stdout */
		i++;							/* Move to next character */
	}
}

/**********************
 * main - Entry point for first word extraction program
 * 
 * Description:
 * This program takes a string as command line argument and
 * displays its first word using the ft_first_word function.
 * If incorrect number of arguments provided, it only prints
 * a newline.
 * 
 * Usage:
 * ./first_word "string with words"
 * 
 * Parameters:
 * @argc: Number of command line arguments
 * @argv: Array of command line argument strings
 * 
 * Return:
 * 0 on successful execution
 * 
 * Examples:
 * ./first_word "Hello World" -> outputs "Hello\n"
 * ./first_word "  test  " -> outputs "test\n"
 **********************/
int main(int argc, char **argv)
{
	if (argc == 2)						/* Check if exactly one argument provided */
		ft_first_word(argv[1]);			/* Call function to print first word */
	write(1, "\n", 1);					/* Always write a newline at the end */
	return (0);							/* Return success */
}