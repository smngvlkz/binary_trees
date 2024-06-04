#include "binary_trees.h"
#include <limits.h>

/**
 * isBSTUtil - Recursive helper function to check
 * if a subtree is a valid BST
 * @node: Pointer to the current node
 * @min: Minimum allowed value for the node
 * @max: Maximum allowed value for the node
 * Return: 1 if the subtree is a valid BST, 0 otherwise
 */
int isBSTUtil(const binary_tree_t *node, int min, int max)
{
	if (node == NULL)
		return (1);

	if (node->n <= min || node->n >= max)
		return (0);

	return (isBSTUtil(node->left, min, node->n) &&
			isBSTUtil(node->right, node->n, max));
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a
 * valid Binary Search Tree
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if tree is a valid BST, 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (isBSTUtil(tree, INT_MIN, INT_MAX));
}
