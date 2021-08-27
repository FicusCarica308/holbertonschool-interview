if (list_lgt % 2 != 0)
	{
		is_odd++;
	}
	list_lgt = list_lgt / 2;

	flipped_values = (int *)malloc(sizeof(int) * list_lgt + 1);

	while (temp_head2 != NULL)
	{
		if (list_lgt > 0 && made_it == 0)
		{
			flipped_values[list_lgt - 1] = temp_head2->n;
			list_lgt -= 1;
			temp_head2 = temp_head2->next;
		}
		else
		{
			if (is_odd == 1)
			{
				temp_head2 = temp_head2->next;
				is_odd = 0;
			}
			made_it = 1;
			printf("flipped_values: %d, n-> values: %d\n", flipped_values[list_lgt], temp_head2->n);
			if (temp_head2->n != flipped_values[list_lgt])
			{
				free(flipped_values);
				return (0);
			}
			list_lgt++;
			temp_head2 = temp_head2->next;
		}
	}
	free(flipped_values);
	return 1;
}
