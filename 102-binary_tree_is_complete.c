#include "binary_trees.h"

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	const binary_tree_t *queue[1000];
	int front = 0, rear = 0;
	int null_node_encountered = 0;

	queue[rear++] = tree;

	while (front < rear)
	{
		const binary_tree_t *current = queue[front++];

		if (current == NULL)
			null_node_encountered = 1;
		else
		{
			if (null_node_encountered)
				return (0);

			queue[rear++] = current->left;
			queue[rear++] = current->right;
		}
	}

	return (1);
}
