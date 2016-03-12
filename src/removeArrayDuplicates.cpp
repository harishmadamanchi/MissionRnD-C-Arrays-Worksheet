/*
OVERVIEW:  given an array that has duplicate values remove all duplicate values.
E.g.: input: [1, 1, 2, 2, 3, 3], output [1, 2, 3]

Ex 2: [4,4,2,2,1,5] output : [4,2,1,5]

INPUTS: Integer array and length of the array .

OUTPUT: Update input array by removing duplicate values and return the final array length

ERROR CASES: Return -1 for invalid inputs.

NOTES: Don't create new array, try to change the input array.
*/

#include <stdio.h>

void quicksort(int *, int, int);

int removeArrayDuplicates(int *Arr, int len)
{
	int i, j;
	if (len <= 0 || Arr == NULL){
		return -1;
	}
	else{
		quicksort(Arr, 0, len);
		for (i = 0; i < len - 1; i++){
			if (Arr[i] == Arr[i + 1]){
				for (j = i + 1; j < len; j++){
					Arr[j - 1] = Arr[j];
				}
				len--;
			}
		}
		return len;
	}
}

void quicksort(int *Arr, int first, int last)
{
	int i, j, pivot, temp;
	if (first<last)
	{
		i = first;
		j = last - 1;
		pivot = first;
		while (i < j)
		{
			while (Arr[i] <= Arr[pivot] && i<last)
				i++;
			while (Arr[j]>Arr[pivot] && j>0)
				j--;
			if (i < j)
			{
				temp = Arr[i];
				Arr[i] = Arr[j];
				Arr[j] = temp;
			}
		}
		temp = Arr[pivot];
		Arr[pivot] = Arr[j];
		Arr[j] = temp;
		quicksort(Arr, 0, j - 1);
		quicksort(Arr, j + 1, last);
	}
}


