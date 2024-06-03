#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * print_t - Recursively stores each level in an array of strings
 * @tree: Pointer to the current node.
 * @is_left: Flag indicating if the current node is the left child
 * @offset: Current offset for indentation.
 * @depth: Current depth in the tree.
 * @s: Placeholder character for formatting
 *
 * Return: Width of the printed subtree
 */
int print_t(binary_tree_t *tree, int is_left, int offset, int depth, char s)
{
	char b[12];
	int width = 5;
	int left, right;
	int i;

	(void)is_left;
	
	if (!tree)
		return (0);
	
	sprintf(b, "(%03d)", tree->n);
	
	left = print_t(tree->left, 1, offset, depth + 1, ' ');
	right = print_t(tree->right, 0, offset + left + width, depth + 1, ' ');
	
	for (i = 0; i < offset; i++)
		printf(" ");
	printf("%s", b);
	
	if (depth && s == '-')
	{
		for (i = 0; i < width; i++)
			printf("-");
		printf(".");
	}
	printf("\n");
	
	return (left + width + right);
}

/**
 * binary_tree_print - Prints a binary tree
 * @tree: Pointer to the root of the binary tree
 */
void binary_tree_print(const binary_tree_t *tree)
{
	if (!tree)
		return;
	print_t((binary_tree_t *)tree, 0, 0, 0, '-');
}

