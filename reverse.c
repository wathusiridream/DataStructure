#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int stk[10];
int top = -1;
int pop();
void push(int);
int main()
{
    int val, n, i, arr[10];

    printf("\n Enter the number of elements in the array : ");
    scanf("%d", &n);
    printf("\n Enter the elements of the array : ");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    for (i = 0; i < n; i++)
        push(arr[i]);
    
    printf("\n -- The array is : -- \n");
    for (i = 0; i < n; i++)
    {
        printf("| %d |\n", arr[i]);
    }
    for (i = 0; i < n; i++)
    {
        val = pop();
        arr[i] = val;
    }
    printf("\n -- The reversed array is : -- \n");
    for (i = 0; i < n; i++)
        printf("| %d |\n", arr[i]);
    getche();
    return 0;
}
void push(int val)
{
    stk[++top] = val;
}
int pop()
{
    return (stk[top--]);
}
