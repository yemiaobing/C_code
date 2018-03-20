#include "sort.h"
#include <stdio.h>

/* print sort */
void printf_sort_array(int array[], int array_length)
{
	for (int i = 0; i < array_length; i++)
	{
		printf("%d ", array[i]);
	}

	printf("\n");
}


/* bubble sort */
void bubble_sort(int array[], int array_length)
{
	int i = 0;
	int j = 0;

	for (i = 0; i < array_length; i++)
	{
		for (j = 0; j < (array_length - i - 1); j++)
		{
			if (array[j] > array[j + 1])
			{
				array[j] = array[j] + array[j + 1];
				array[j + 1] = array[j] - array[j + 1];
				array[j] = array[j] - array[j + 1];
			}
		}

		printf_sort_array(array, array_length);
	}
}

/* ²åÈëÅÅĞò */
void insert_sort(int array[], int array_length)
{
	int i = 0;
	int j = 0;
	int temp = 0;

	for (i = 1; i < array_length; i++)
	{
		temp = array[i];

#if 1
		for (j = i; j > 0; j--)
		{
			if (array[j] < array[j - 1])
			{
				array[j] = array[j - 1];		
				array[j-1] = temp;
			}
			else
			{
				break;
			}
		}		
#else
		for (j = i; j > 0; j--)
		{
			if (temp < array[j - 1])
			{
				array[j] = array[j - 1];
			}
			else
			{
				break;
			}
		}

		array[j] = temp;
#endif
		printf_sort_array(array, array_length);
	}
}

/* Ï£¶ûÅÅĞò */
void shell_sort(int array[], int array_length)
{
	int increment = 0;
	int i = 0;
	int j = 0;
	int temp = 0;

	for (increment = array_length / 2; increment >= 1; increment /= 2)
	{
		for (i = increment; i < array_length; i++)
		{
			temp = array[i];

			for (j = i; j > 0; j -= increment)
			{
				if (array[j] < array[j - increment])
				{
					array[j] = array[j - increment];
					array[j - increment] = temp;
				}
				else
				{
					break;
				}
			}
			printf_sort_array(array, array_length);
		}

		printf_sort_array(array, array_length);
	}
}

/* Ñ¡ÔñÅÅĞò */
void select_sort(int array[], int array_length)
{
	int i = 0;
	int j = 0;
	int min_index = 0;

	for (i = 0; i < array_length-1; i++)
	{
		min_index = i;

		for (j = i + 1; j < array_length; j++)
		{
			if (array[j] < array[min_index])
			{
				min_index = j;
			}
		}

		if (min_index > i)
		{
			array[i] = array[i] + array[min_index];
			array[min_index] = array[i] - array[min_index];
			array[i] = array[i] - array[min_index];
		}

		printf_sort_array(array, array_length);
	}
}
