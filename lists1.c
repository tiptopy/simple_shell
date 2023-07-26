#include "shell.h"

/**
 * list_to_strings - convert linked list to array of strings
 * @head: pointer to first node
 *
 * Return: array of strings
 */
char **list_to_strings(list_t *head)
{
	list_t *node = head;
	size_t i, j;
	char **strs;
	char *str;

	/* Get the length of the list */
	for (i = 0; node; node = node->next, i++)
		;

	/* Allocate memory for the array of strings */
	strs = malloc(sizeof(char *) * (i + 1));
	if (!strs)
		return (NULL);

	/* Copy strings into the array */
	for (node = head, i = 0; node; node = node->next, i++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (j = 0; j < i; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}
		str = _strcpy(str, node->str);
		strs[i] = str;
	}

	strs[i] = NULL;
	return (strs);
}

/**
 * list_len - get the length of linked list
 * @h: pointer to first node
 *
 * Return: size of list
 */
size_t list_len(const list_t *h)
{
	size_t i;

	/* Iterate through the list to count its elements */
	for (i = 0; h; h = h->next, i++)
		;

	return (i);
}

/**
 * print_list - print all elements of a list_t linked list
 * @h: pointer to first node
 *
 * Return: size of list
 */
size_t print_list(const list_t *h)
{
	size_t i;

	/* Iterate through the list and print each node's information */
	for (i = 0; h; h = h->next, i++)
	{
		_puts(convert_number(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
	}

	return (i);
}

/**
 * node_starts_with - find node whose string starts with prefix
 * @node: pointer to list head
 * @prefix: string to match
 * @c: next character after prefix to match
 *
 * Return: matching node or null
 */
list_t *node_starts_with(list_t *node, char *prefix, char c)
{
	char *p;

	/* Iterate through the list and check for a matching prefix */
	while (node)
	{
		p = starts_with(node->str, prefix);
		if (p && ((c == -1) || (*p == c)))
			return (node);
		node = node->next;
	}

	return (NULL);
}

/**
 * get_node_index - get the index of a node
 * @head: pointer to list head
 * @node: pointer to the node
 *
 * Return: index of node or -1
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t i;

	/* Iterate through the list to find the index of the given node */
	for (i = 0; head; head = head->next, i++)
	{
		if (head == node)
			return (i);
	}

	/* Node not found in the list */
	return (-1);
}
