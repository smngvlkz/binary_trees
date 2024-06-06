#include "binary_trees.h"

/**
 * avl_insert - Inserts a value in an AVL Tree
 * @tree: Double pointer to the root node of the
 * AVL tree for inserting the value
 * @value: The value to store in the node to be inserted
 *
 * Return: Pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	if (!tree)
		return (NULL);

	if (!*tree)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	return (insert_avl(tree, NULL, value));
}

/**
 * insert_avl - Recursive helper function to insert
 * a value in an AVL tree
 * @tree: Double pointer to the root node of the
 * AVL tree for inserting the value
 * @parent: Pointer to the parent node
 * @value: The value to store in the node to be inserted
 *
 * Return: Pointer to the created node, or NULL on failure
 */
avl_t *insert_avl(avl_t **tree, avl_t *parent, int value)
{
	avl_t *node = NULL;

	if (!*tree)
	{
		*tree = binary_tree_node(parent, value);
		return (*tree);
	}

	if (value < (*tree)->n)
		node = insert_avl(&((*tree)->left), *tree, value);
	else if (value > (*tree)->n)
		node = insert_avl(&((*tree)->right), *tree, value);
	else
		return (NULL);

	*tree = balance_tree(*tree, value);

	return (node);
}

/**
 * balance_tree - Balances the AVL tree if unbalanced
 * @tree: Pointer to the root node of the tree to balance
 * @value: The value that was inserted
 *
 * Return: Pointer to the balanced tree
 */
avl_t *balance_tree(avl_t *tree, int value)
{
	int balance = binary_tree_balance(tree);

	if (balance > 1 && value < tree->left->n)
		return (binary_tree_rotate_right(tree));

	if (balance < -1 && value > tree->right->n)
		return (binary_tree_rotate_left(tree));

	if (balance > 1 && value > tree->left->n)
	{
		tree->left = binary_tree_rotate_left(tree->left);
		return (binary_tree_rotate_right(tree));
	}

	if (balance < -1 && value < tree->right->n)
	{
		tree->right = binary_tree_rotate_right(tree->right);
		return (binary_tree_rotate_left(tree));
	}

	return (tree);
}

/**
 * height - Computes the height of a node
 * @node: The node to compute the height of
 *
 * Return: The height of the node
 */
int height(const binary_tree_t *node)
{
	if (!node)
		return (0);
	return (1 + max(height(node->left), height(node->right)));
}

/**
 * max - Returns the maximum of two integers
 * @a: First integer
 * @b: Second integer
 *
 * Return: The maximum of the two integers
 */
int max(int a, int b)
{
	return ((a > b) ? a : b);
}
