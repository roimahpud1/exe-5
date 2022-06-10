#include <stdio.h>
#include <stdlib.h>
#include "BST.h"
#include "TreePrintLibrary.h"

int main()
{
	BST bst;
	BST* pbst=&bst;
	int N = 3;
	initBST(&bst);
	insertBST(&bst, 5);
	insertBST(&bst, 2);
	insertBST(&bst, 1);
	insertBST(&bst, 1);
	insertBST(&bst, 4);
	print_ascii_tree(pbst->root);
	printf("\n");
	printf("print tree inorder:\n");
	printTreeInorder(&bst);
	printf("\n");
	int elementnode = findIndexNFromLast(&bst, N);
	printf("The element %d is %d elements from the high element\n",elementnode , N);
	int sameLevel = sameHeightLeaves(&bst);
	if (sameLevel == 0) {
		printf("the level of leaves is different");
	}
	else
	{
		printf("the level of leaves is same");
	}
	printf("\n");
	destroyBST(&bst);
	return 0;
}