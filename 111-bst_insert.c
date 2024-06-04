#include <stdlib.h>
#include "binary_trees.h"

/**
 * bst_insert - Inserts a value into a Binary Search Tree (BST).
 * @tree: Double pointer to the root node of the BST.
 * @value: Value to store in the node to be inserted.
 *
 * Return: Pointer to the created node, or NULL on failure.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	if (!tree)
		return (NULL);

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	if (value < (*tree)->n)
		return (bst_insert(&((*tree)->left), value));
	else if (value > (*tree)->n)
		return (bst_insert(&((*tree)->right), value));

	return (NULL);
}
