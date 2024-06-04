#include <stdlib.h>
#include "binary_trees.h"

/**
 * find_min - Finds the minimum value node in a BST.
 * @node: Pointer to the root node of the tree.
 *
 * Return: Pointer to the minimum value node.
 */
bst_t *find_min(bst_t *node)
{
	while (node->left)
		node = node->left;
	return (node);
}

/**
 * bst_remove - Removes a node from a Binary Search Tree (BST).
 * @root: Pointer to the root node of the tree.
 * @value: Value to remove from the tree.
 *
 * Return: Pointer to the new root node after removing the value.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	if (!root)
		return (NULL);

	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (!root->left)
		{
			bst_t *temp = root->right;

			free(root);
			return (temp);
		}
		else if (!root->right)
		{
			bst_t *temp = root->left;

			free(root);
			return (temp);
		}

		bst_t *temp = find_min(root->right);

		root->n = temp->n;
		root->right = bst_remove(root->right, temp->n);
	}

	return (root);
}
