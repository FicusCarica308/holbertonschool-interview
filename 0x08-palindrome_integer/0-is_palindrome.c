#include "palindrome.h"

/**
 * Pow - helper function that calculate the power of a number
 * @num: the base number
 * @expo: the number's exponent
 * Return: the calculated number of y^x
 */
int Pow(int num, int expo)
{
	int iter = 0;
	int out = num;

	for (iter = 1; iter < expo; iter++)
		out = out * num;
	return (out);
}

/**
 * is_palindrome - checks if a given unsinged int is a palindrome
 * @n: unsinged integer to be checked
 * Return: 0 if not palindrome 1 if is palindrome
 */
int is_palindrome(unsigned long n)
{
	int iter = 0, int_count = 0, div = 0, mod = 0, power = 0;
	int iter2 = 0;
	int num_hold = n;

	if (n < 10)
		return (1);
	/*returns not a palidrome if number is negative*/
	/* negative numbers passed to unsigned int are greater than UINT_MAX */
	if (n > 4294967295)
		return (0);
	for (int_count = 0; num_hold != 0; int_count++)
		num_hold = num_hold / 10;
	num_hold = n;
	for (iter = int_count - 1; iter >= 0 && num_hold > 0; iter--)
	{
		if (iter == int_count - 1)
			power = Pow(10, iter);
		else
			power = Pow(10, iter - iter2);
		iter2++;
		mod = num_hold % 10;
		if (num_hold > 9)
			div = num_hold / power;
		else
			div = num_hold / 1;
		if (div != mod)
			return (0);
		num_hold = num_hold - power * div;
		num_hold = num_hold / 10;
	}
	return (1);
}
