//******************************************************
// Assignment name  : aff_z
// Expected files   : aff_z.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that takes a string, and displays the first 'z'
// character it encounters in it, followed by a newline. If there are no
// 'z' characters in the string, the program writes 'z' followed
// by a newline. If the number of parameters is not 1, the program displays
// 'z' followed by a newline.

// Example:

// $> ./aff_z "abc" | cat -e
// z$
// $> ./aff_z "dubO a POIL" | cat -e
// z$
// $> ./aff_z "zaz sent le poney" | cat -e
// z$
// $> ./aff_z | cat -e
// z$

//******************************************************
// to compile it : gcc -Wall -Wextra -Werror aff_z.c -o aff_z
// to run it : ./aff_z "abc" | cat -e
// to run it : ./aff_z "dubO a POIL" | cat -e
// to run it : ./aff_z "zaz sent le poney" | cat -e
// to run it : ./aff_z | cat -e
//******************************************************

#include <unistd.h>

/**********************
 * aff_z - Searches for and displays 'z' in string
 * 
 * Description:
 * This function searches through a string character by character
 * looking for the first occurrence of the letter 'z'. When found,
 * it displays 'z' followed by a newline. If no 'z' is found,
 * it also displays 'z' followed by a newline.
 * 
 * Algorithm:
 * 1. Iterate through each character of the string
 * 2. Check if current character is 'z'
 * 3. If found, print 'z' and newline, then return 1
 * 4. If end of string reached, print 'z' and newline, return 0
 * 
 * Parameters:
 * @str: Pointer to the string to search
 * 
 * Return:
 * 1 if 'z' was found in the string
 * 0 if no 'z' was found in the string
 **********************/
int aff_z(char *str)
{
	int i;  /* Loop counter for iterating through the string */
	
	i = 0;  /* Initialize index to start of string */
	
	/* Iterate through each character of the string */
	while (str[i])
	{
		/* Check if current character is 'z' */
		if (str[i] == 'z')
		{
			write(1, "z", 1);  /* Write 'z' to stdout */
			write(1, "\n", 1); /* Write newline to stdout */
			return (1);        /* Return 1 to indicate 'z' was found */
		}
		i++;  /* Move to next character */
	}
	
	/* If no 'z' was found, still write 'z' followed by newline */
	write(1, "z\n", 2);  /* Write "z\n" in a single write call */
	return (0);          /* Return 0 to indicate no 'z' was found */
}

/**********************
 * main - Entry point for aff_z program
 * 
 * Description:
 * This program handles command line arguments and calls aff_z function
 * appropriately. It follows these rules:
 * - If exactly one argument: search for 'z' in that argument
 * - If not exactly one argument: display 'z' followed by newline
 * 
 * Technical details:
 * - argc == 2 means exactly one argument (program name + 1 argument)
 * - argc != 2 means wrong number of arguments
 * - In all cases, 'z' followed by newline is displayed
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
		/* Call aff_z function to search for 'z' in the argument */
		aff_z(argv[1]);
	}
	else
	{
		/* If argc != 2, write 'z' followed by newline */
		write(1, "z\n", 2);  /* Write "z\n" in a single write call */
	}
	
	return (0);  /* Return 0 to indicate successful execution */
}