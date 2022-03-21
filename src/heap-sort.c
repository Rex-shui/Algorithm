#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int sort[10] = {29, 0, 6, 28, 18, 7, 14, 25, 19, 3};

//假定子树都是最大堆，迭代
void MAX_HEAPIFY(int to_sort[], int size, int pos)
{
	int l = 2*pos + 1;	//左孩子节点
	int r = 2*pos + 2;	//右
	
	int largest;
	int swap;
	//与子结点中最大的一个交换
	if( l < size && to_sort[l] > to_sort[pos] )
		largest = l;
	else largest = pos;
	if( r < size && to_sort[r] > to_sort[largest] )
		largest = r;

	
	if( largest != pos )
	{
		swap = to_sort[pos];
		to_sort[pos] = to_sort[largest];
		to_sort[largest] = swap;
	
		MAX_HEAPIFY(to_sort, size, largest);
	}
}


void BUILD_MAX_HEAP(int to_sort[], int size)
{
	for(int i = size/2; i>=0; i--)
		MAX_HEAPIFY(to_sort, size, i);
}

//交换根节点与末位值，堆长度减一、迭代
void HEAP_SORT(int to_sort[], int size)
{
	int swap;
	for(int i=size-1; i>0; i--)
	{
		swap = to_sort[i];
		to_sort[i] = to_sort[0];
		to_sort[0] = swap;
		
		size--;
		MAX_HEAPIFY(to_sort, size, 0);
	} 
}

void print(int *arr, int n)
{
	for(int i=0; i<n; i++)
	{
		printf("%-3d", arr[i]);
	}
	printf("\n");

}

int main()
{
	print(sort, 10);
	

	BUILD_MAX_HEAP(sort, 10);
	print(sort, 10);

	HEAP_SORT(sort, 10);
	print(sort, 10);
	
	return 0;
}
