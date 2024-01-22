//This source code was edited from Thareja, Reema - Data structures using C (2014, Oxford University Press)
// by Boonchoo Jitnupong

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>

struct node
{
    int data;
    struct node *next;
};

struct node *start = NULL;
struct node *create_ll();
struct node *display();
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);

struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);

struct node *delete_list(struct node *);

struct node *find_data(struct node *);
struct node *find_max(struct node *);
struct node *find_min(struct node *);
struct node *find_avg(struct node *);

void main()
{
    int option;
    do
    {
        printf("\n\n * ****MAIN MENU * ****");
        printf("\n 1: Create a list");
        printf("\n 2: Display the list");
        printf("\n 3: Add a node at the beginning");
        printf("\n 4: Add a node at the end");

        printf("\n 7: Delete a node from the beginning");
        printf("\n 8: Delete a node from the end");
        printf("\n 9: Find data are you looking for");
        printf("\n 10: Find Maximum value");
        printf("\n 11: Find Minimum value");
        printf("\n 12: Find average value");

        printf("\nSelect your choice: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            start = create_ll(start);
            printf("\n LINKED LIST CREATED");
            break;
        case 2:
            start = display(start);
            break;
        case 3:
            start = insert_beg(start);
            break;
        case 4:
            start = insert_end(start);
            break;

        case 7:
            start = delete_beg(start);
            break;
        case 8:
            start = delete_end(start);
            break;
        case 9:
            start = find_data(start);
            break;
        case 10:
            start = find_max(start);
            break;
        case 11:
            start = find_min(start);
            break;
        case 12:
            start = find_avg(start);
            break;
        }
    } while (option != 5);
}

struct node *create_ll()
{
    struct node *new_node, *ptr;
    int num;
    printf("\n Enter - 1 to end");
    printf("\n Enter the data: ");
    scanf("%d", &num);
    while (num != -1)
    {
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = num;
        if (start == NULL)
        {
            new_node->next = NULL;
            start = new_node;
        }
        else
        {
            ptr = start;
            while (ptr->next != NULL)
                ptr = ptr->next;
            ptr->next = new_node;
            new_node->next = NULL;
        }
        printf("\n Enter the data: ");
        scanf("%d", &num);
    }
    return start;
}
struct node *display()
{
    struct node *ptr;
    ptr = start;
    while (ptr != NULL)
    {
        printf("\t %p", ptr->next);
        printf("\t %d", ptr->data);
        ptr = ptr->next;
    }
    return start;
}
struct node *insert_beg(struct node *start)
{
    struct node *new_node;
    int num;
    printf("\n Enter the data: ");
    scanf("%d", &num);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    new_node->next = start;
    start = new_node;
    return start;
}
struct node *insert_end(struct node *start)
{
    struct node *ptr, *new_node;
    int num;
    printf("\n Enter the data: ");
    scanf("%d", &num);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    new_node->next = NULL;
    ptr = start;
    while (ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = new_node;
    return start;
}

struct node *delete_beg(struct node *start)
{
    struct node *ptr;
    ptr = start;
    start = start->next;
    free(ptr);
    return start;
}
struct node *delete_end(struct node *start)
{
    struct node *ptr, *preptr;
    ptr = start;
    while (ptr->next != NULL)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = NULL;
    free(ptr);
    return start;
}
struct node *find_data(struct node *start)
{
	int node;
	struct node *ptr;
	ptr = start;
	printf("What node are you find? :\n");
	scanf("%d",&node);
	while (ptr != NULL)
	{
	if (ptr->data == node)
		printf("%d is node are you find on memory : %d\n",ptr->data,ptr->next);
	else printf("Data not found\n");
	ptr = ptr->next;
	}
}
struct node *find_max(struct node *start)
{
	int max = 0;
	struct node *ptr;
	ptr = start;
	while(ptr != NULL)
	{
		if(ptr->data > max)
		max = ptr->data;
		ptr = ptr->next;
	}
	printf("Max value is : %d\n ",ptr->data);
	
}
struct node *find_min(struct node *start)
{
	int min = 100;
	struct node *ptr;
	ptr = start;
	while(ptr != NULL)
	{
		if(ptr->data < min)
		min = ptr->data;
		ptr = ptr->next;
	}
	printf("Min value is : %d\n ",ptr->data);
	
}
struct node *find_avg(struct node *start)
{
	int count = 0;
	float sum , avg;
	struct node *ptr;
	ptr = start;
	while(ptr != NULL)
	{
		sum += ptr->data;
		count++;
		ptr = ptr->next;
	}
	avg = sum/count;
	printf("Average value is : %.2f\n ",avg);
}
