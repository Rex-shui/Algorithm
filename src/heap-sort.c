#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct HEAP {
	int *data;
	int len;
	int size;
};


//假定子树都是最大堆，迭代
void MAX_HEAPIFY(struct HEAP *A, int i)
{
	int l = 2*i + 1;	//左孩子节点
	int r = 2*i + 2;	//右
	
	int largest;
	int swap;
	//与子结点中最大的一个交换
	if( l < A->size && A->data[l] > A->data[i] )
		largest = l;
	else largest = i;
	if( r < A->size && A->data[r] > A->data[largest] )
		largest = r;

	
	if( largest != i )
	{
		swap = A->data[i];
		A->data[i] = A->data[largest];
		A->data[largest] = swap;
	
		MAX_HEAPIFY(A, largest);
	}
}


void BUILD_MAX_HEAP(struct HEAP *A)
{
	for(int i = A->len/2; i>=0; i--)
		MAX_HEAPIFY(A, i);
}

//交换根节点与末位值，堆长度减一、迭代
void HEAP_SORT(struct HEAP *A)
{
	int swap;
	for(int i=A->len-1; i>0; i--)
	{
		swap = A->data[i];
		A->data[i] = A->data[0];
		A->data[0] = swap;
		A->size -= 1;
		MAX_HEAPIFY(A, 0);
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
	int arr[10] = {0};
	struct HEAP A;

	srand(time(NULL));
	for(int i=0; i<10; i++)
	{
		arr[i] = rand()%30;
	}
	print(arr, 10);
	
	A.data = arr;
	A.len = 10;
	A.size = 10;

	BUILD_MAX_HEAP(&A);
	print(arr, 10);

	HEAP_SORT(&A);
	print(arr, 10);
	
	return 0;
}
