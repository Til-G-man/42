#include <stdio.h>
#include <stdlib.h>
typedef struct list
{
    struct list *before;
    int x;
    int y;
    int z;
    int colour;
    struct list *next;
} list;
list    *init_list(int x, int y, int z, int colour)
{
    printf("init\n");
    list *new_node;

    new_node = (list *)malloc(sizeof(list));
    if (new_node == NULL)
        return (NULL);
    new_node->before = NULL;
    new_node->x = x;
    new_node->y = y;
    new_node->z = z;
    new_node->colour = colour;
    new_node->next = NULL;
    return (new_node);
}
list *append(list *listelement, int x, int y, int z, int colour) {
    printf("append\n");
    list *new_node;

    if (listelement == NULL)
        return init_list(x, y, z, colour);
    while (listelement->next != NULL)
        listelement = listelement->next;

    new_node = (list *)malloc(sizeof(list));
    if (new_node == NULL)
        return NULL;
    new_node->before = listelement;
    new_node->x = x;
    new_node->y = y;
    new_node->z = z;
    new_node->colour = colour;
    new_node->next = NULL;
    listelement->next = new_node;

    return new_node;
}

int	delete_node(list *node)
{
	printf("start deleting node\n");
    if (node == NULL)
        return (0);
    if (node->before != NULL)
		node->before->next = node->next;
    if (node->next!= NULL)
		node->next->before = node->before;
	if (node)
	{
		free(node);
		printf("free node\n");
	}
    return (0);
}

void	delete_list(list *listelement)
{
	list *next_element;

	if (listelement == NULL)
		return;
	printf("start deleting list\n");
    while (listelement->before != NULL)
	{
        listelement = listelement->before;
	}
	while (listelement->next != NULL)
	{
		next_element = listelement->next;
		delete_node(listelement);
		listelement = next_element;
	}
	if (listelement != NULL)
		delete_node(listelement);
	if (next_element != NULL)
		delete_node(next_element);
	printf("List deleted\n");

}

int    print_listelement(list *element)
{
    printf("Start printing element\n");
    if (element!= NULL)
    {
        printf("x: %d\ny: %d\nz: %d\ncolour: %d\nbefore: %p\nnext: %p\n_____________\n", element->x, element->y, element->z, element->colour, element->before, element->next);
    }
    return 0;
}
int    print_list(list *element)
{
    printf("start printig list\n");
    while (element->before != NULL)
        element = element->before;
    while (element->next != NULL)
    {
        print_listelement(element);
        element = element->next;
    }
    print_listelement(element);
    return (0);
}

int	count_list(list *list)
{
	int count = 0;

	if (list == NULL)
		return (0);
	while (list->before != NULL)
	    list = list->before;
	while (list->next != NULL)
	{
        count++;
        list = list->next;
    }
	if (list != NULL)
		count++;

	return (count);
}

int main() {

    list new_list;

    new_list = *init_list(1, 2, 3, 0xFFFFFF);
    append(&new_list, 5, 6, 7, 0x10FA75);
    append(&new_list, 9, 16, 17, 0x8FFDC0);
    printf("count: %i\n", count_list(&new_list));
	printf("list ready\n");
	print_list(&new_list);
	delete_list(&new_list);
    printf("count: %i\n", count_list(&new_list));
    return 0;
}