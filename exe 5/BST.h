#ifndef _BST_ADT_H
#define _BST_ADT_H


typedef struct TreeNode TreeNode;

struct TreeNode
{
    TreeNode* left;
    TreeNode* right;
    int element;
};

typedef struct BST
{
    TreeNode* root;
}BST;

void initBST(BST* bst);
void insertBST(BST* bst, int value);
void insertBSTHelper(TreeNode** node, int value);
void printTreeInorder(BST* bst);
void printTreeInorderHelper(TreeNode* node);
void destroyBST(BST* bst);
void destroyBSTHelper(TreeNode* node);
int countNodes(TreeNode* node);
int findIndexNFromLast(BST* bst, int N);
int findSubIndexFromButtom(TreeNode* node, int N);
int sameHeightLeaves(BST* bst);
int isBalanceTree(TreeNode* root);
int countElements(TreeNode* root);
#endif // !_BST_ADT_H

