#include <stdio.h>

int sort[10] = {29, 0, 6, 28, 18, 7, 14, 25, 19, 3};

void print(int *arr, int n)
{
	for(int i=0; i<n; i++)
	{
		printf("%-3d", arr[i]);
	}
	printf("\n");

}

int part(int to_sort[], int start, int end)
{
	int left = start - 1;
	int swap;
	
	for(int i=start; i<end; i++)
	{
		if(to_sort[i] >= to_sort[end])
		{
			left++;

			swap = to_sort[left];
			to_sort[left] = to_sort[i];
			to_sort[i] = swap;
		}	
	}

	swap = to_sort[left+1];
	to_sort[left+1] = to_sort[end];
	to_sort[end] = swap;

	return left+1;
}


void quick_sort(int to_sort[], int start, int end)
{
	if(start < end)
	{
		int q = part(to_sort, start, end);
		quick_sort(to_sort, start, q-1);
		quick_sort(to_sort, q+1, end);
	}
}

int main()
{
	print(sort, 10);
	quick_sort(sort, 0, 9);
	print(sort, 10);

	return 0;
}
