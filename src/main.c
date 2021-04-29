//
//  main.c
//  AlgorithmRepository
//
//  Created by 水小水 on 2021/4/23.
//

#include <stdio.h>

#include "tools.h"
#include "algorithm.h"

int main(int argc, const char * argv[]) {

	srand(time(NULL));
	char arr[50] = {0};
	int x = rand()%100;
	arr[0] = x;
	printf("%d ", x);
	BST *root = BST_create(x);

	for(int i=1; i<20; i++){
		arr[i] = rand()%100;
		BST_insert(root, arr[i]);
		printf("%d ", arr[i]);
	}
	printf("\n");

	x = rand()%20;

	BST_delete(root, arr[x]);

	BST_print(root);
	

	BFS_print();
	return 0;
}
