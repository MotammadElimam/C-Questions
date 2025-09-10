//******************************************************
// Assignment name  : last_word
// Expected files   : last_word.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that takes a string and displays its last word followed by a \n.

// A word is a section of string delimited by spaces/tabs or by the start/end of
// the string.

// If the number of parameters is not 1, or there are no words, display a newline.

// Example:

// $> ./last_word "FOR PONY" | cat -e
// PONY$
// $> ./last_word "this        ...       is sparta, then again, maybe    not" | cat -e
// not$
// $> ./last_word "   " | cat -e
// $
// $> ./last_word "a" "b" | cat -e
// $
// $> ./last_word "  lorem,ipsum  " | cat -e
// lorem,ipsum$
// $>

//******************************************************
// to compile it : gcc -Wall -Wextra -Werror last_word.c -o last_word
// to run it : ./last_word "FOR PONY" | cat -e
// to run it : ./last_word "this        ...       is sparta, then again, maybe    not" | cat -e
// to run it : ./last_word "   " | cat -e
// to run it : ./last_word "  lorem,ipsum  " | cat -e
//******************************************************

#include <unistd.h>

/**********************
 * ft_last_word - Extracts and prints the last word from a string
 * 
 * Description:
 * This function finds and displays the last word in a string.
 * A word is defined as a sequence of characters delimited by
 * spaces or tabs. The function handles trailing whitespace by
 * skipping it to find the actual last word.
 * 
 * Algorithm:
 * 1. Find the end of the input string
 * 2. Move backwards to skip trailing whitespace
 * 3. Save the position of the last character of the last word
 * 4. Continue moving backwards to find the start of the last word
 * 5. Print characters from start to end of the last word
 * 
 * Parameters:
 * @str: The input string to extract the last word from
 * 
 * Return:
 * void - No return value (output is written directly)
 * 
 * Examples:
 * ft_last_word("FOR PONY") outputs "PONY"
 * ft_last_word("  hello world  ") outputs "world"
 * ft_last_word("   ") outputs nothing
 **********************/
void	ft_last_word(char *str)
{
	int i = 0;							/* Index to find end of string */
	int j;								/* Variable to mark end of last word */
	
	while (str[i])						/* Find the end of the string */
		i++;							/* Move index to the end */
	i--;								/* Move back to last actual character */
	while (i >= 0 && (str[i] == ' ' || str[i] == '\t'))	/* Skip trailing whitespace */
		i--;							/* Move backwards past spaces and tabs */
	j = i;								/* Save position of last character of last word */
	while (i >= 0 && str[i] != ' ' && str[i] != '\t')		/* Find beginning of last word */
		i--;							/* Move backwards until whitespace or start */
	i++;								/* Move forward to first character of last word */
	while (i <= j)						/* Print the last word from start to end */
	{
		write(1, &str[i], 1);			/* Write current character to stdout */
		i++;							/* Move to next character */
	}
}

/**********************
 * main - Entry point for last word extraction program
 * 
 * Description:
 * This program takes a string as command line argument and
 * displays its last word using the ft_last_word function.
 * If incorrect number of arguments provided, it only prints
 * a newline.
 * 
 * Usage:
 * ./last_word "string with words"
 * 
 * Parameters:
 * @argc: Number of command line arguments
 * @argv: Array of command line argument strings
 * 
 * Return:
 * 0 on successful execution
 * 
 * Examples:
 * ./last_word "Hello World" -> outputs "World\n"
 * ./last_word "test" -> outputs "test\n"
 **********************/
int main(int argc, char **argv)
{
	if (argc == 2)						/* Check if exactly one argument provided */
		ft_last_word(argv[1]);			/* Call function to print last word */
	write(1, "\n", 1);					/* Always write a newline at the end */
	return (0);							/* Return success */
}