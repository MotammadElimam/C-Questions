/*
 ******************************************************
 Create a function that displays a memory area on screen.
 The display of this memory area should be divided into three "columns", separated by a space:
 The hexadecimal address of the first character in the line, followed by a ':'
 The content in hexadecimal, with a space every two characters, and padded with spaces if necessary (see the example below).
 The content in printable characters.
 If a character is non-printable, it should be replaced by a dot
 Each line should display sixteen characters.
 If size is equal to 0, nothing should be displayed
 Example:
 ./ft_print_memory
 000000010a161f40: 426f 6e6a 6f75 7220 6c65 7320 616d 696e Bonjour les amin
 000000010a161f50: 6368 6573 090a 0963 0720 6573 7420 666f ches...c. est fo
 000000010a161f60: 7509 746f 7574 0963 6520 7175 206f 6e20 u.tout.ce qu on
 000000010a161f70: 7065 7574 2066 6169 7265 2061 7665 6309 peut faire avec.
 000000010a161f80: 0a09 7072 696e 745f 6d65 6d6f 7279 0a0a ..print_memory..
 000000010a161f90: 0a09 6c6f 6c2e 6c6f 6c0a 2000 ..lol.lol. .
 $> ./ft_print_memory | cat -te
 0000000107ff9f40: 426f 6e6a 6f75 7220 6c65 7320 616d 696e Bonjour les amin$
 0000000107ff9f50: 6368 6573 090a 0963 0720 6573 7420 666f ches...c. est fo$
 0000000107ff9f60: 7509 746f 7574 0963 6520 7175 206f 6e20 u.tout.ce qu on $
 0000000107ff9f70: 7065 7574 2066 6169 7265 2061 7665 6309 peut faire avec.$
 0000000107ff9f80: 0a09 7072 696e 745f 6d65 6d6f 7279 0a0a ..print_memory..$
 0000000107ff9f90: 0a09 6c6f 6c2e 6c6f 6c0a 2000 ..lol.lol. .$
 $>
 Here is how it should be prototyped:
 void *ft_print_memory(void *addr, unsigned int size);
 It should return addr.
 ******************************************************
 * to compile it : gcc ft_print_memory.c
 * to run it : ./a.out
 ******************************************************
 */

#include <unistd.h>

/**********************
 * ft_puthex_char - Displays a byte as two-digit lowercase hex
 * 
 * Description:
 * This helper function converts a single byte to its two-digit
 * lowercase hexadecimal representation. Always outputs exactly
 * two characters, padding with leading zero if necessary.
 * 
 * Algorithm:
 * 1. Extract high nibble (upper 4 bits) and convert to hex char
 * 2. Extract low nibble (lower 4 bits) and convert to hex char
 * 3. Output both hex characters
 * 
 * Parameters:
 * @c: The byte to display as hex
 * 
 * Return:
 * void - No return value (output is written directly)
 * 
 * Examples:
 * ft_puthex_char(255) outputs "ff"
 * ft_puthex_char(10) outputs "0a"
 **********************/
void	ft_puthex_char(unsigned char c)
{
	char hex[] = "0123456789abcdef";		/* Hex digit lookup table */
	
	write(1, &hex[c / 16], 1);			/* Write high nibble */
	write(1, &hex[c % 16], 1);			/* Write low nibble */
}

/**********************
 * ft_print_address - Displays memory address in 16-digit hex format
 * 
 * Description:
 * This function displays a memory address as a 16-character lowercase
 * hexadecimal string followed by a colon and space. The address is
 * displayed with leading zeros to maintain consistent formatting.
 * 
 * Algorithm:
 * 1. Extract each nibble from the address (64-bit pointer)
 * 2. Convert each nibble to hex character and display
 * 3. Process from most significant to least significant nibble
 * 4. Add colon and space after address
 * 
 * Parameters:
 * @addr: The memory address to display
 * 
 * Return:
 * void - No return value (output is written directly)
 * 
 * Examples:
 * ft_print_address(0x10a161f40) outputs "000000010a161f40: "
 **********************/
void	ft_print_address(unsigned long addr)
{
	char hex[] = "0123456789abcdef";		/* Hex digit lookup table */
	int i;								/* Counter for hex digits */
	
	i = 15;								/* Start with most significant nibble */
	while (i >= 0)						/* Process all 16 nibbles */
	{
		write(1, &hex[(addr >> (i * 4)) & 0xf], 1);	/* Extract and write nibble */
		i--;							/* Move to next nibble */
	}
	write(1, ": ", 2);					/* Write colon and space separator */
}

/**********************
 * ft_print_memory - Displays memory content in hex dump format
 * 
 * Description:
 * This function displays a memory area in three-column hex dump format:
 * 1. Memory address (16-digit hex with colon)
 * 2. Hex content (space every 2 chars, padded if needed)
 * 3. Printable characters (dots for non-printable)
 * Each line shows 16 bytes. Returns the original address pointer.
 * 
 * Algorithm:
 * 1. Return immediately if size is 0
 * 2. Process memory in 16-byte chunks
 * 3. For each line:
 *    a. Print address in hex format
 *    b. Print hex content with proper spacing and padding
 *    c. Print printable representation
 *    d. Add newline
 * 4. Return original address
 * 
 * Parameters:
 * @addr: Pointer to memory area to display
 * @size: Number of bytes to display
 * 
 * Return:
 * void* - Returns the original addr parameter
 * 
 * Examples:
 * ft_print_memory("Hello", 5) displays hex dump of "Hello"
 **********************/
void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned char *ptr = (unsigned char *)addr;	/* Byte pointer for memory access */
	unsigned int i, j;							/* Loop counters */
	
	if (size == 0)								/* Handle zero size case */
		return (addr);							/* Return without printing */
	
	i = 0;										/* Initialize line counter */
	while (i < size)							/* Process all bytes */
	{
		ft_print_address((unsigned long)(ptr + i));	/* Print line address */
		
		/* Print hex content with spacing */
		j = 0;									/* Initialize byte counter for line */
		while (j < 16)							/* Process 16 bytes per line */
		{
			if (i + j < size)					/* Check if byte exists */
				ft_puthex_char(ptr[i + j]);		/* Print byte as hex */
			else
				write(1, "  ", 2);				/* Pad with spaces if needed */
			if (j % 2 == 1)						/* Add space every 2 hex chars */
				write(1, " ", 1);				/* Write space separator */
			j++;								/* Move to next byte */
		}
		
		/* Print printable representation */
		j = 0;									/* Reset byte counter */
		while (j < 16 && i + j < size)			/* Process bytes for ASCII column */
		{
			if (ptr[i + j] >= 32 && ptr[i + j] <= 126)	/* Check if printable */
				write(1, &ptr[i + j], 1);		/* Write printable character */
			else
				write(1, ".", 1);				/* Write dot for non-printable */
			j++;								/* Move to next byte */
		}
		
		write(1, "\n", 1);						/* End line with newline */
		i += 16;								/* Move to next 16-byte chunk */
	}
	
	return (addr);								/* Return original address */
}

/**********************
 * main - Entry point for memory display demonstration
 * 
 * Description:
 * This program demonstrates the ft_print_memory function by testing it
 * with various memory areas including strings with printable and
 * non-printable characters. It shows how the three-column hex dump
 * format displays memory addresses, hex content, and ASCII representation.
 * 
 * Algorithm:
 * 1. Test with a string similar to the example in the problem
 * 2. Test with various control characters and mixed content
 * 3. Test edge cases like small strings and empty memory
 * 4. Display clear labels for each test case
 * 
 * Parameters:
 * None
 * 
 * Return:
 * 0 on successful execution
 * 
 * Examples:
 * ./ft_print_memory shows various memory dump demonstrations
 **********************/
int main(void)
{
	write(1, "Testing ft_print_memory function:\n\n", 35);	/* Display program header */
	
	/* Test case 1: String similar to problem example */
	write(1, "Test 1 - String with mixed content:\n", 37);	/* Test description */
	{
		char test1[] = "Bonjour les amis\t\nches\t\nc est fou\ttout\tce qu on peut faire avec\t\n\tprint_memory\n\n\tlol.lol\n ";
		ft_print_memory(test1, sizeof(test1) - 1);		/* Print memory dump */
	}
	write(1, "\n", 1);									/* Spacing between tests */
	
	/* Test case 2: Short string */
	write(1, "Test 2 - Short string:\n", 24);			/* Test description */
	{
		char test2[] = "Hello!";
		ft_print_memory(test2, 6);						/* Print short string */
	}
	write(1, "\n", 1);									/* Spacing between tests */
	
	/* Test case 3: String with control characters */
	write(1, "Test 3 - Control characters:\n", 30);		/* Test description */
	{
		char test3[] = {'A', 'B', 'C', '\0', '\t', '\n', '\r', 1, 2, 3, 'X', 'Y', 'Z', '\0'};
		ft_print_memory(test3, 14);					/* Print control chars */
	}
	write(1, "\n", 1);									/* Spacing between tests */
	
	/* Test case 4: Exactly 16 bytes */
	write(1, "Test 4 - Exactly 16 bytes:\n", 29);		/* Test description */
	{
		char test4[] = "0123456789ABCDEF";
		ft_print_memory(test4, 16);					/* Print exactly 16 bytes */
	}
	write(1, "\n", 1);									/* Spacing between tests */
	
	/* Test case 5: More than 16 bytes */
	write(1, "Test 5 - Multiple lines:\n", 26);			/* Test description */
	{
		char test5[] = "This is a longer string that will span multiple lines in the hex dump display.";
		ft_print_memory(test5, sizeof(test5) - 1);		/* Print multi-line */
	}
	write(1, "\n", 1);									/* Spacing between tests */
	
	/* Test case 6: Zero size (should print nothing) */
	write(1, "Test 6 - Zero size (should print nothing):\n", 45);	/* Test description */
	ft_print_memory("Hello", 0);						/* Print zero bytes */
	write(1, "[End of zero size test]\n", 25);			/* Indicate end */
	
	return (0);										/* Return success status */
}