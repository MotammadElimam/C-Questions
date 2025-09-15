/*
 ******************************************************
 • Since this is a program, your .c file must contain a main function.
 • Write a program that displays its given arguments.
 • Each argument should be printed on a new line, in the reverse order from the command line.
 • The program should display all arguments except argv[0].
 ******************************************************
 * to compile it : gcc ft_rev_params.c
 * to run it : ./a.out
 ******************************************************
 */

#include <unistd.h>

/**********************
 * ft_putstr - Displays a string to standard output
 * 
 * Description:
 * This function outputs a null-terminated string to the standard
 * output by writing each character directly. It iterates
 * through the string until it reaches the null terminator.
 * 
 * Algorithm:
 * 1. Initialize index counter to 0
 * 2. Loop while current character is not null terminator
 * 3. Write each character directly using write system call
 * 4. Increment index to move to next character
 * 5. Stop when null terminator is reached
 * 
 * Parameters:
 * @str: Pointer to the null-terminated string to display
 * 
 * Return:
 * void - No return value (output is written directly)
 * 
 * Examples:
 * ft_putstr("test3") outputs "test3"
 * ft_putstr("world") outputs "world"
 * ft_putstr("") outputs nothing (empty string)
 **********************/
void	ft_putstr(char *str)
{
	int	i;						/* Index for string traversal */

	i = 0;						/* Initialize index to start of string */
	while (str[i] != '\0')		/* Continue until null terminator */
	{
		write(1, &str[i], 1);	/* Write current character to stdout */
		i++;					/* Move to next character */
	}
}

/**********************
 * main - Entry point for reverse parameter display program
 * 
 * Description:
 * This program displays all command-line arguments passed to it
 * in reverse order, excluding the program name (argv[0]). Each
 * argument is printed on a separate line. The last argument
 * provided is displayed first, and the first argument (after
 * the program name) is displayed last.
 * 
 * Algorithm:
 * 1. Initialize counter to argc - 1 (last argument)
 * 2. Loop backwards through arguments from argv[argc-1] to argv[1]
 * 3. For each argument, call ft_putstr to display it
 * 4. Add a newline after each argument
 * 5. Decrement counter to move to previous argument
 * 6. Stop when counter reaches 0 (argv[0] is program name)
 * 7. Return 0 to indicate successful execution
 * 
 * Parameters:
 * @argc: Number of command-line arguments including program name
 * @argv: Array of strings containing the arguments
 *        argv[0] is the program name (skipped)
 *        argv[1] through argv[argc-1] are the actual arguments
 * 
 * Return:
 * 0 on successful execution
 * 
 * Examples:
 * ./a.out test1 test2 test3 outputs "test3\ntest2\ntest1\n"
 * ./a.out A B C D outputs "D\nC\nB\nA\n"
 * ./a.out hello outputs "hello\n"
 * ./a.out outputs nothing (no arguments to display)
 **********************/
int	main(int argc, char **argv)
{
	int	i;						/* Counter for iterating through arguments in reverse */

	i = argc - 1;				/* Start from last argument */
	while (i > 0)				/* Loop until reaching argv[0] (program name) */
	{
		ft_putstr(argv[i]);		/* Display current argument */
		write(1, "\n", 1);		/* Add newline after each argument */
		i--;					/* Move to previous argument */
	}
	return (0);					/* Return success status */
}