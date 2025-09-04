//******************************************************
// Assignment name  : ft_strrev
// Expected files   : ft_strrev.c
// Allowed functions: 
// --------------------------------------------------------------------------------

// Write a function that reverses (in-place) a string.

// It must return its parameter.

// Your function must be declared as follows:

// char    *ft_strrev(char *str);

//******************************************************
// to compile it : gcc -Wall -Wextra -Werror ft_strrev.c -o ft_strrev
// to run it : ./ft_strrev
// to run it : ./ft_strrev "Hello"
// to run it : ./ft_strrev "World!"
// to run it : ./ft_strrev "a"
// to run it : ./ft_strrev ""
//******************************************************
// The flags mean:
//******************************************************
//   - -Wall: Enable all common warnings
//   - -Wextra: Enable extra warning flags
//   - -Werror: Treat warnings as errors
//   - -o ft_strrev: Name the output executable "ft_strrev"
//******************************************************

#include <unistd.h>

/**********************
 * ft_strrev - Reverses a string in-place using two-pointer technique
 * 
 * Description:
 * This function takes a string and reverses it by swapping characters
 * from both ends moving towards the middle. It modifies the original
 * string directly (in-place) without using additional memory.
 * 
 * Algorithm:
 * 1. Calculate the length of the string
 * 2. Use two pointers: one at start (i) and one at end (len-1)
 * 3. Swap characters at these positions
 * 4. Move pointers towards center until they meet
 * 
 * Parameters:
 * @str: The string to be reversed (must be modifiable)
 * 
 * Return:
 * Returns a pointer to the reversed string (same as input pointer)
 * 
 * Example:
 * "Hello" becomes "olleH"
 * "42" becomes "24"
 **********************/
char *ft_strrev(char *str)
{
	int i = 0;                      /* Start index */
	int len = 0;                    /* String length counter */
	char tmp;                       /* Temporary variable for swapping */
	
	while (str[len])                /* Find string length */
		len++;                  /* Increment length counter */
	len--;                          /* Adjust to last character index */
	while (i < len)                 /* While pointers haven't met in middle */
	{
		tmp = str[i];           /* Save character at start */
		str[i] = str[len];      /* Copy end character to start */
		str[len] = tmp;         /* Copy saved character to end */
		i++;                    /* Move start pointer forward */
		len--;                  /* Move end pointer backward */
	}
	return (str);                   /* Return pointer to reversed string */
}


/**********************
 * ft_putstr - Outputs a string to standard output
 * 
 * Description:
 * This helper function prints a string character by character
 * using the write system call. It iterates through the string
 * until it reaches the null terminator.
 * 
 * Parameters:
 * @str: The string to be printed to stdout
 * 
 * Return:
 * void - No return value
 **********************/
void ft_putstr(char *str)
{
	int i = 0;                      /* Index for string traversal */
	while (str[i])                  /* Loop until null terminator */
	{
		write(1, &str[i], 1);   /* Write current character to stdout */
		i++;                    /* Move to next character */
	}
}

/**********************
 * main - Test program for ft_strrev function
 * 
 * Description:
 * This program demonstrates the ft_strrev function with various
 * test cases including normal strings, single character, and
 * empty string. It shows before and after results for each test.
 * 
 * Test cases:
 * - "Hello" -> "olleH" (normal string)
 * - "World!" -> "!dlroW" (string with punctuation)
 * - "a" -> "a" (single character - no change)
 * - "" -> "" (empty string - no change)
 * 
 * Return:
 * 0 on successful execution
 **********************/
int main(void)
{
	char str1[] = "Hello";              /* Test string 1 */
	char str2[] = "World!";             /* Test string 2 */
	char str3[] = "a";                  /* Single character test */
	char str4[] = "";                   /* Empty string test */
	
	write(1, "Original: ", 10);         /* Print label */
	ft_putstr(str1);                    /* Print original string */
	write(1, " -> Reversed: ", 14);     /* Print arrow label */
	ft_putstr(ft_strrev(str1));         /* Reverse and print string */
	write(1, "\n", 1);                  /* Print newline */
	
	write(1, "Original: ", 10);
	ft_putstr(str2);
	write(1, " -> Reversed: ", 14);
	ft_putstr(ft_strrev(str2));
	write(1, "\n", 1);
	
	write(1, "Original: ", 10);
	ft_putstr(str3);
	write(1, " -> Reversed: ", 14);
	ft_putstr(ft_strrev(str3));
	write(1, "\n", 1);
	
	write(1, "Original: ", 10);
	ft_putstr(str4);
	write(1, " -> Reversed: ", 14);
	ft_putstr(ft_strrev(str4));
	write(1, "\n", 1);
	
	return (0);
}