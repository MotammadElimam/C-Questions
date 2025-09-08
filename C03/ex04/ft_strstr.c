/*
 ******************************************************
 Reproduce the behavior of the function strstr (man strstr).
 The function should be prototyped as follows:
 char *ft_strstr(char *str, char *to_find);
 ******************************************************
 * to compile it : gcc ft_strstr.c
 * to run it : ./a.out
 ******************************************************
 */

#include <unistd.h>

/**********************
 * ft_putstr - Displays a string to standard output
 * 
 * Description:
 * This function outputs a null-terminated string character by character
 * using the write system call. It iterates through the string until
 * reaching the null terminator and writes each character to stdout.
 * 
 * Algorithm:
 * 1. Initialize index to 0
 * 2. Loop through string until null terminator
 * 3. Write each character to standard output
 * 4. Increment index and continue
 * 
 * Parameters:
 * @str: The string to be displayed
 * 
 * Return:
 * void - No return value (output is written directly)
 * 
 * Examples:
 * ft_putstr("Hello") outputs "Hello"
 * ft_putstr("") outputs nothing
 **********************/
void	ft_putstr(char *str)
{
	int i;						/* Index for iterating through the string */
	
	i = 0;						/* Initialize index to start of string */
	while (str[i] != '\0')		/* Loop until null terminator */
	{
		write(1, &str[i], 1);	/* Write current character to stdout */
		i++;					/* Move to next character */
	}
}

/**********************
 * ft_strstr - Locates a substring within a string
 * 
 * Description:
 * This function reproduces the behavior of the standard strstr function.
 * It locates the first occurrence of the substring to_find in the string
 * str. The terminating null characters are not compared. If to_find is
 * an empty string, the function returns str.
 * 
 * Algorithm:
 * 1. Check if to_find is empty, return str if true
 * 2. Iterate through str
 * 3. For each position, check if substring matches
 * 4. If match found, return pointer to beginning of match
 * 5. If no match found, return NULL
 * 
 * Parameters:
 * @str: The string to search in (haystack)
 * @to_find: The substring to search for (needle)
 * 
 * Return:
 * Pointer to the first occurrence of to_find in str
 * NULL if to_find is not found
 * str if to_find is empty
 * 
 * Examples:
 * ft_strstr("Hello World", "World") returns pointer to "World"
 * ft_strstr("Hello World", "abc") returns NULL
 * ft_strstr("Hello World", "") returns "Hello World"
 **********************/
char	*ft_strstr(char *str, char *to_find)
{
	int i;						/* Index for main string */
	int j;						/* Index for substring */
	
	if (to_find[0] == '\0')		/* If to_find is empty string */
		return (str);			/* Return the original string */
	
	i = 0;						/* Initialize main string index */
	while (str[i] != '\0')		/* Iterate through main string */
	{
		j = 0;					/* Reset substring index */
		while (str[i + j] == to_find[j] && to_find[j] != '\0')	/* Check for match */
			j++;				/* Move to next character in substring */
		
		if (to_find[j] == '\0')	/* If entire substring matched */
			return (&str[i]);	/* Return pointer to start of match */
		
		i++;					/* Move to next position in main string */
	}
	return (0);					/* Return NULL if no match found */
}

/**********************
 * main - Entry point for substring search demonstration program
 * 
 * Description:
 * This program demonstrates the ft_strstr function by testing it with
 * various string and substring combinations including normal searches,
 * empty needle searches, non-existent substrings, and multiple occurrences.
 * It shows how the function locates substrings within strings.
 * 
 * Algorithm:
 * 1. Create test strings and substrings
 * 2. Perform various substring searches
 * 3. Display search results
 * 4. Show found substring or indicate not found
 * 5. Demonstrate edge cases with empty strings
 * 
 * Parameters:
 * None
 * 
 * Return:
 * 0 on successful execution
 * 
 * Examples:
 * ./ft_strstr outputs substring search results for various test cases
 **********************/
int main(void)
{
	char *str1 = "Hello World, this is a test string";	/* Main test string */
	char *str2 = "The quick brown fox jumps over the lazy dog";	/* Another test string */
	char *needle1 = "World";	/* Substring to find */
	char *needle2 = "test";	/* Another substring */
	char *needle3 = "xyz";		/* Non-existent substring */
	char *needle4 = "";			/* Empty substring */
	char *needle5 = "fox";		/* Substring in middle */
	char *result;				/* Pointer to store search result */
	
	/* Test 1: Normal search - find "World" */
	write(1, "Test 1 - Find \"World\":\n", 24);		/* Display test description */
	write(1, "String: \"", 9);		/* Show label */
	ft_putstr(str1);				/* Display main string */
	write(1, "\"\n", 2);			/* Close quote and newline */
	result = ft_strstr(str1, needle1);		/* Search for substring */
	if (result)					/* If substring found */
	{
		write(1, "Found: \"", 8);	/* Show found label */
		ft_putstr(result);			/* Display from found position */
		write(1, "\"\n\n", 3);		/* Close quote and newlines */
	}
	else
		write(1, "Not found\n\n", 12);		/* Indicate not found */
	
	/* Test 2: Find "test" in the string */
	write(1, "Test 2 - Find \"test\":\n", 22);		/* Display test description */
	write(1, "String: \"", 9);		/* Show label */
	ft_putstr(str1);				/* Display main string */
	write(1, "\"\n", 2);			/* Close quote and newline */
	result = ft_strstr(str1, needle2);		/* Search for substring */
	if (result)					/* If substring found */
	{
		write(1, "Found: \"", 8);	/* Show found label */
		ft_putstr(result);			/* Display from found position */
		write(1, "\"\n\n", 3);		/* Close quote and newlines */
	}
	else
		write(1, "Not found\n\n", 12);		/* Indicate not found */
	
	/* Test 3: Search for non-existent substring */
	write(1, "Test 3 - Find \"xyz\" (not present):\n", 36);		/* Display test description */
	write(1, "String: \"", 9);		/* Show label */
	ft_putstr(str1);				/* Display main string */
	write(1, "\"\n", 2);			/* Close quote and newline */
	result = ft_strstr(str1, needle3);		/* Search for non-existent substring */
	if (result)					/* If substring found */
	{
		write(1, "Found: \"", 8);	/* Show found label */
		ft_putstr(result);			/* Display from found position */
		write(1, "\"\n\n", 3);		/* Close quote and newlines */
	}
	else
		write(1, "Not found\n\n", 12);		/* Indicate not found */
	
	/* Test 4: Empty needle (should return original string) */
	write(1, "Test 4 - Empty needle:\n", 23);		/* Display test description */
	write(1, "String: \"", 9);		/* Show label */
	ft_putstr(str1);				/* Display main string */
	write(1, "\"\n", 2);			/* Close quote and newline */
	result = ft_strstr(str1, needle4);		/* Search with empty needle */
	if (result)					/* Should always be true for empty needle */
	{
		write(1, "Found: \"", 8);	/* Show found label */
		ft_putstr(result);			/* Display from found position (entire string) */
		write(1, "\"\n\n", 3);		/* Close quote and newlines */
	}
	else
		write(1, "Not found\n\n", 12);		/* Should not happen */
	
	/* Test 5: Find "fox" in different string */
	write(1, "Test 5 - Find \"fox\":\n", 21);		/* Display test description */
	write(1, "String: \"", 9);		/* Show label */
	ft_putstr(str2);				/* Display second test string */
	write(1, "\"\n", 2);			/* Close quote and newline */
	result = ft_strstr(str2, needle5);		/* Search for "fox" */
	if (result)					/* If substring found */
	{
		write(1, "Found: \"", 8);	/* Show found label */
		ft_putstr(result);			/* Display from found position */
		write(1, "\"\n", 2);		/* Close quote and newline */
	}
	else
		write(1, "Not found\n", 11);		/* Indicate not found */
	
	return (0);					/* Return success status to the operating system */
}