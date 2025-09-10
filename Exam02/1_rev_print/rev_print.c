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
// to run it : ./rev_print "zaz" | cat -e
// to run it : ./rev_print "dub0 a POIL" | cat -e
// to run it : ./rev_print | cat -e
//******************************************************

#include <unistd.h>

/**********************
 * ft_rev_print - Prints a string in reverse order
 * 
 * Description:
 * This function takes a string and displays it in reverse order
 * character by character using the write system call. It first
 * calculates the length of the string, then prints characters
 * from the last position to the first position.
 * 
 * Algorithm:
 * 1. Handle null pointer case by returning NULL
 * 2. Find the length of the string by traversing to the end
 * 3. Move back one position to point to the last actual character
 * 4. Print characters from the end to the beginning using write
 * 5. Return the original string pointer as required
 * 
 * Parameters:
 * @str: The input string to print in reverse
 * 
 * Return:
 * char* - Returns the original string pointer (as specified)
 * 
 * Examples:
 * ft_rev_print("hello") outputs "olleh" and returns "hello"
 * ft_rev_print("abc") outputs "cba" and returns "abc"
 * ft_rev_print(NULL) returns NULL
 **********************/
char	*ft_rev_print(char *str)
{
	int i = 0;							/* Index to find string length */
	
	if (!str)							/* Handle null pointer case */
		return (NULL);					/* Return NULL for safety */
	
	while (str[i])						/* Find the length of the string */
		i++;							/* Increment index until null terminator */
	i--;								/* Move back to last actual character */
	
	while (i >= 0)						/* Print characters in reverse order */
	{
		write(1, &str[i], 1);			/* Write current character to stdout */
		i--;							/* Move to previous character */
	}
	
	return (str);						/* Return original string pointer as required */
}

/**********************
 * main - Entry point for reverse print program
 * 
 * Description:
 * This program takes a string as command line argument and
 * displays it in reverse order using the ft_rev_print function.
 * It always prints a newline at the end. If no arguments are
 * provided, it only prints the newline.
 * 
 * Usage:
 * ./rev_print "string to reverse"
 * 
 * Parameters:
 * @argc: Number of command line arguments
 * @argv: Array of command line argument strings
 * 
 * Return:
 * 0 on successful execution
 * 
 * Examples:
 * ./rev_print "hello" -> outputs "olleh\n"
 * ./rev_print -> outputs "\n"
 **********************/
int main(int argc, char **argv)
{
	if (argc == 2)						/* Check if exactly one argument provided */
		ft_rev_print(argv[1]);			/* Call function to print string in reverse */
	write(1, "\n", 1);					/* Always write a newline at the end */
	return (0);							/* Return success */
}