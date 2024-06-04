#include "binary_trees.h"

/**
 * max - Returns the maximum of two integers.
 * @a: First integer.
 * @b: Second integer.
 *
 * Return: Maximum of a and b.
 */
int max(int a, int b)
{
	return ((a > b) ? a : b);
}

/**
 * height - Computes the height of a binary tree.
 * @tree: Pointer to the root node of the tree.
 *
 * Return: Height of the tree.
 */
int height(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (1 + max(height(tree->left), height(tree->right)));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid AVL Tree, 0 otherwise.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int left_height, right_height, balance_factor;

	if (!tree)
		return (1);

	left_height = height(tree->left);
	right_height = height(tree->right);
	balance_factor = abs(left_height - right_height);

	if (balance_factor > 1)
		return (0);

	return (binary_tree_is_avl(tree->left) && binary_tree_is_avl(tree->right));
}
