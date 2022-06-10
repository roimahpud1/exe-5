#include<stdio.h>
#include "BST.h"
#include "TreePrintLibrary.h"
#include <stdlib.h>
//MACRO
#define ALLOC(pointer, size) if (pointer==NULL) {pointer = malloc(size * sizeof *pointer);} if(pointer==NULL){printf("allocation error\n");exit(1);}


void initBST(BST* bst) {
	bst->root = NULL;
}

void insertBST(BST* bst, int value) {

	insertBSTHelper(&bst->root, value);
}


void insertBSTHelper(TreeNode** node, int value) {
	if (*node == NULL) {
		ALLOC(*node, 1);
		(*node)->element = value;
		(*node)->left = (*node)->right = NULL;
		return;
	}
	if (value <= (*node)->element) {
		insertBSTHelper(&(*node)->left, value);
	}
	else
	{
		insertBSTHelper(&(*node)->right, value);
	}

}

void printTreeInorder(BST* bst) {
	(!bst->root) ? printf("Empty Tree\n") : printTreeInorderHelper(bst->root);
}

void printTreeInorderHelper(TreeNode* node) {
	if (node == NULL) {
		return;
	}
	if (!node->right && !node->left)
	{
		printf("%d,", node->element);
		return;
	}
	printTreeInorderHelper(node->left);
	printf("%d,", node->element);
	printTreeInorderHelper(node->right);
}

void destroyBST(BST* bst)
{
	(!bst->root) ? printf("Empty Tree\n") : destroyBSTHelper(bst->root);

}
void destroyBSTHelper(TreeNode* node)
{
	if (node == NULL) {
		return;
	}
	if (!node->right && !node->left)
	{
		free(node);
		return;
	}
	destroyBSTHelper(node->left);
	destroyBSTHelper(node->right);
	free(node);
}


int countNodes(TreeNode* node) {
	return (node == NULL) ? 0 : (1 + countNodes(node->left) + countNodes(node->right));
}

int findIndexNFromLast(BST* bst, int N) {
	int nodesCount = countNodes(bst->root);
	return (nodesCount < N) ? -1 : findSubIndexFromButtom(bst->root, N);
}

int findSubIndexFromButtom(TreeNode* node, int N) {
	int right = countNodes(node->right);
	if (right == N - 1)
		return node->element;
	if (right < N - 1)
		return findSubIndexFromButtom(node->left, N - right - 1);

	return findSubIndexFromButtom(node->right, N);
}


int sameHeightLeaves(BST* bst)
{
	return isBalanceTree(bst->root);
}

int isBalanceTree(TreeNode* root)
{

	int lh, rh;

	if (root == NULL)
		return 1;
	lh = countElements(root->left);
	rh = countElements(root->right);

	if (abs(lh - rh) <= 1 && isBalanceTree(root->left) && isBalanceTree(root->right))
		return 1;
	return 0;
}

int countElements(TreeNode* root)
{
	if (root == NULL)
		return 0;
	return 1 + max(countElements(root->left), countElements(root->right));
}


