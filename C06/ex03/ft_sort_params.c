/*
 ******************************************************
 // • Since this is a program, your .c file must contain a main function.
 // • Write a program that displays its given arguments sorted in ASCII order.
 // • The program should display all arguments except argv[0].
 // • Each argument should be printed on a new line.
 ******************************************************
 * to compile it : gcc ft_sort_params.c
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
 * ft_putstr("test1") outputs "test1"
 * ft_putstr("apple") outputs "apple"
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
 * ft_strcmp - Compares two strings lexicographically
 * 
 * Description:
 * This function compares two null-terminated strings character by
 * character using their ASCII values. It returns the difference
 * between the first non-matching characters or 0 if the strings
 * are identical. Used for sorting arguments in ASCII order.
 * 
 * Algorithm:
 * 1. Initialize index to 0
 * 2. Loop while both strings have matching characters
 * 3. If characters differ or end of string reached, stop
 * 4. Return difference between current characters
 * 5. If strings are equal, return 0
 * 
 * Parameters:
 * @s1: First string to compare
 * @s2: Second string to compare
 * 
 * Return:
 * Negative value if s1 < s2 (in ASCII order)
 * 0 if s1 == s2
 * Positive value if s1 > s2 (in ASCII order)
 * 
 * Examples:
 * ft_strcmp("abc", "abd") returns negative (c < d)
 * ft_strcmp("test", "test") returns 0 (equal)
 * ft_strcmp("xyz", "abc") returns positive (x > a)
 **********************/
int	ft_strcmp(char *s1, char *s2)
{
	int	i = 0;						/* Index for string traversal */
	while (s1[i] && s2[i] && s1[i] == s2[i])	/* Continue while chars match */
	{
		i++;					/* Move to next character */
	}
	return (s1[i] - s2[i]);		/* Return difference between current characters */
}


/**********************
 * ft_sort_args - Sorts command-line arguments in ASCII order
 * 
 * Description:
 * This function sorts the command-line arguments in ascending
 * ASCII order using bubble sort algorithm. It modifies the
 * argv array in place, excluding argv[0] (program name).
 * 
 * Algorithm:
 * 1. Use nested loops for bubble sort
 * 2. Compare adjacent arguments using ft_strcmp
 * 3. Swap arguments if they're out of order
 * 4. Continue until no more swaps are needed
 * 
 * Parameters:
 * @argc: Number of arguments including program name
 * @argv: Array of string pointers to sort
 * 
 * Return:
 * void - Modifies argv array in place
 * 
 * Examples:
 * Before: ["prog", "zoo", "apple"]
 * After:  ["prog", "apple", "zoo"]
 **********************/
void	ft_sort_args(int argc, char **argv)
{
	int		i;					/* Outer loop counter */
	int		j;					/* Inner loop counter */
	char	*temp;				/* Temporary storage for swapping */

	i = 1;						/* Start from first argument */
	while (i < argc - 1)		/* Bubble sort passes */
	{
		j = 1;					/* Reset for each pass */
		while (j < argc - 1)	/* Compare adjacent elements */
		{
			if (ft_strcmp(argv[j], argv[j + 1]) > 0)	/* If out of order */
			{
				temp = argv[j];			/* Swap the pointers */
				argv[j] = argv[j + 1];
				argv[j + 1] = temp;
			}
			j++;				/* Next pair */
		}
		i++;					/* Next pass */
	}
}

/**********************
 * main - Entry point for sorted parameter display program
 * 
 * Description:
 * This program displays all command-line arguments passed to it
 * in ascending ASCII order, excluding the program name (argv[0]).
 * Each argument is printed on a separate line.
 * 
 * Algorithm:
 * 1. Call ft_sort_args to sort arguments
 * 2. Loop through sorted arguments
 * 3. Display each argument with a newline
 * 4. Return 0 for success
 * 
 * Parameters:
 * @argc: Number of command-line arguments
 * @argv: Array of argument strings
 * 
 * Return:
 * 0 on successful execution
 * 
 * Examples:
 * ./a.out zoo apple outputs "apple\nzoo\n"
 * ./a.out 3 1 2 outputs "1\n2\n3\n"
 **********************/
int	main(int argc, char **argv)
{
	int	i;						/* Counter for displaying arguments */

	ft_sort_args(argc, argv);	/* Sort the arguments */
	i = 1;						/* Start from argv[1] */
	while (i < argc)			/* Display all arguments */
	{
		ft_putstr(argv[i]);		/* Print argument */
		write(1, "\n", 1);		/* Add newline */
		i++;					/* Next argument */
	}
	return (0);					/* Return success */
}