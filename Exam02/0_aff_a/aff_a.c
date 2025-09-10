//******************************************************
// Assignment name  : aff_a
// Expected files   : aff_a.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that takes a string, and displays the first 'a' character it
// encounters in it, followed by a newline. If there are no 'a' characters in the
// string, the program just writes a newline. If the number of parameters is not
// 1, the program displays 'a' followed by a newline.

// Example:

// $> ./aff_a "abc" | cat -e
// a$
// $> ./aff_a "dubO a POIL" | cat -e
// a$
// $> ./aff_a "zz sent le poney" | cat -e
// $
// $> ./aff_a | cat -e
// a$

//******************************************************
// to compile it : gcc -Wall -Wextra -Werror aff_a.c -o aff_a
// to run it : ./aff_a "abc" | cat -e
// to run it : ./aff_a "dubO a POIL" | cat -e
// to run it : ./aff_a "zz sent le poney" | cat -e
// to run it : ./aff_a "zz sent le poney" | cat -e
// to run it : ./aff_a | cat -e
//******************************************************

#include <unistd.h>

/**********************
 * aff_a - Searches for and displays first 'a' in string
 * 
 * Description:
 * This function searches through a string character by character
 * looking for the first occurrence of the letter 'a'. When found,
 * it displays 'a' followed by a newline. If no 'a' is found,
 * it displays only a newline.
 * 
 * Algorithm:
 * 1. Iterate through each character of the string
 * 2. Check if current character is 'a'
 * 3. If found, print 'a' and newline, then return 1
 * 4. If end of string reached, print only newline and return 0
 * 
 * Parameters:
 * @str: Pointer to the string to search
 * 
 * Return:
 * 1 if 'a' was found and displayed
 * 0 if no 'a' was found (only newline displayed)
 **********************/
int aff_a(char *str)
{
	int i;  /* Loop counter for iterating through the string */
	
	i = 0;  /* Initialize index to start of string */
	
	/* Iterate through each character of the string */
	while (str[i])
	{
		/* Check if current character is 'a' */
		if (str[i] == 'a')
		{
			write(1, "a", 1);  /* Write 'a' to stdout */
			write(1, "\n", 1); /* Write newline to stdout */
			return (1);        /* Return 1 to indicate 'a' was found */
		}
		i++;  /* Move to next character */
	}
	
	/* If no 'a' was found, write only a newline */
	write(1, "\n", 1);
	return (0);  /* Return 0 to indicate no 'a' was found */
}

/**********************
 * main - Entry point for aff_a program
 * 
 * Description:
 * This program handles command line arguments and calls aff_a function
 * appropriately. It follows these rules:
 * - If exactly one argument: search for 'a' in that argument
 * - If not exactly one argument: display 'a' followed by newline
 * 
 * Technical details:
 * - argc == 2 means exactly one argument (program name + 1 argument)
 * - argc != 2 means wrong number of arguments
 * 
 * Parameters:
 * @argc: Number of command line arguments
 * @argv: Array of command line argument strings
 * 
 * Return:
 * 0 on successful execution
 **********************/
int main(int argc, char **argv)
{
	/* Check if exactly one argument was provided (argc == 2) */
	if (argc == 2)
	{
		/* Call aff_a function to search for 'a' in the argument */
		aff_a(argv[1]);
	}
	else
	{
		/* If argc != 2, write 'a' followed by newline */
		write(1, "a\n", 2);  /* Write "a\n" in a single write call */
	}
	
	return (0);  /* Return 0 to indicate successful execution */
}