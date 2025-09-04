//******************************************************

// Assignment name  : rev_print
// Expected files   : rev_print.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a function that takes a string and displays the string in reverse
// order followed by the newline.
// Its prototype is constructed like this : 
//   char *ft_rev_print (char *str)
// It must return its argument

// Examples:

// $> ./rev_print "zaz" | cat -e
// zaz$
// $> ./rev_print "dub0 a POIL" | cat -e
// LIOP a 0bud$
// $> ./rev_print | cat -e
// $

//******************************************************
// to compile it : gcc -Wall -Wextra -Werror rev_print.c -o rev_print
// to run it : ./rev_print "zaz"
// to run it : ./rev_print "dub0 a POIL"
// to run it : ./rev_print
//******************************************************
// The flags mean:
//******************************************************
//   - -Wall: Enable all common warnings
//   - -Wextra: Enable extra warning flags
//   - -Werror: Treat warnings as errors
//   - -o rev_print: Name the output executable "rev_print"
//******************************************************

#include <unistd.h>

/**********************
 * ft_rev_print - Displays a string in reverse order
 * 
 * Description:
 * This function takes a string and prints it backwards character
 * by character, followed by a newline. The original string is not
 * modified. It returns the original string pointer for potential
 * chaining.
 * 
 * Algorithm:
 * 1. Find the length of the string
 * 2. Start from the last character (length - 1)
 * 3. Print each character moving backwards
 * 4. Add a newline at the end
 * 
 * Parameters:
 * @str: The string to print in reverse
 * 
 * Return:
 * Pointer to the original string (unchanged)
 * 
 * Example:
 * ft_rev_print("Hello") prints "olleH\n"
 * ft_rev_print("42") prints "24\n"
 **********************/
char *ft_rev_print(char *str)
{
	int i = 0;                      /* Counter for string position */
	
	while (str[i])                  /* Loop to find string length */
		i++;                    /* Move to next character */
	while (i > 0)                   /* Loop backwards through string */
	{
		i--;                    /* Move to previous character */
		write(1, &str[i], 1);   /* Print current character */
	}
	write(1, "\n", 1);             /* Print newline at end */
	return (str);                   /* Return original string pointer */
}

/**********************
 * main - Program that reverses command line argument
 * 
 * Description:
 * This program takes a string as command line argument and
 * prints it in reverse order using ft_rev_print. If no argument
 * or multiple arguments are provided, it just prints a newline.
 * 
 * Usage:
 * ./rev_print "string_to_reverse"
 * 
 * Parameters:
 * @argc: Argument count (should be 2 for proper execution)
 * @argv: Argument vector containing program name and string
 * 
 * Return:
 * 0 on successful execution
 * 
 * Examples:
 * ./rev_print "Hello" -> outputs "olleH\n"
 * ./rev_print -> outputs "\n"
 **********************/
int main(int argc, char **argv)
{
	if (argc == 2)                     /* Check if exactly one argument provided */
		ft_rev_print(argv[1]);      /* Print the argument in reverse */
	else                                /* If wrong number of arguments */
		write(1, "\n", 1);         /* Just print newline */
	return (0);                         /* Return success */
}