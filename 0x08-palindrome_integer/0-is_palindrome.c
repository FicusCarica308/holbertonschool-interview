#include "palindrome.h"
/**
 * is_palindrome - checks if a given unsinged int is a palindrome
 * @n: unsinged integer to be checked
 * Return: 0 if not palindrome 1 if is palindrome
 */
int is_palindrome(unsigned long n)
{
	unsigned long int hold_n = n;
	unsigned long int reversed = 0;

  	while (n != 0)
  	{
    		reversed = reversed * 10;
    		reversed = reversed + n % 10;
    		n = n / 10;
  	}
	if (hold_n == reversed)
		return (1);
	return (0);
}
