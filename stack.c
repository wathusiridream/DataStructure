#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>

void InfixtoPostfix(char source[], char target[]);
int getPriority(char);
char pop(char[]);
void push(char[], char);

int revert(char source[]);
int pop2();
void push2(int);

int top = -1;
#define MAX 100
char st[MAX];

int stk[10];

int main()
{
    char infix[100], postfix[100],prefix[100];
    // clrscr();
    printf("\n Enter any infix expression : ");
    gets(infix);
    revert(infix);
    InfixtoPostfix(infix, postfix);
    printf("\n The corresponding postfix expression is : ");
    puts(postfix);
    revert(postfix);
    printf("\n The corresponding prefix expression is : ");
    getch();
    return 0;
}
void InfixtoPostfix(char source[], char target[])
{
    int i = 0, j = 0;
    char temp;
    strcpy(target, "");
    while (source[i] != '\0')
    {
        if (source[i] == '(')
        {
            push(st, source[i]);
            i++;
        }
        else if (source[i] == ')')
        {
            while ((top != -1) && (st[top] != '('))
            {
                target[j] = pop(st);
                j++;
            }
            if (top == -1)
            {
                printf("\n INCORRECT EXPRESSION");
                exit(1);
            }
            temp = pop(st); // remove left parenthesis
            i++;
        }
        else if (isdigit(source[i]) || isalpha(source[i]))
        {
            target[j] = source[i];
            j++;
            i++;
        }
        else if (source[i] == '+' || source[i] == '-' || source[i] == '*' || source[i] == '/' || source[i] == '%')
        {
            while ((top != -1) && (st[top] != '(') && (getPriority(st[top]) >= getPriority(source[i])))
            {
                target[j] = pop(st);
                j++;
            }
            push(st, source[i]);
            i++;
        }
        else
        {
            printf("\n INCORRECT ELEMENT IN EXPRESSION");
            exit(1);
        }
    }
    while ((top != -1) && (st[top] != '('))
    {
        target[j] = pop(st);
        j++;
    }
    target[j] = '\0';
}
int getPriority(char op)
{
    if (op == '/' || op == '*' || op == '%')
        return 1;
    else if (op == '+' || op == '-')
        return 0;
}
void push(char st[], char val)
{
    if (top == MAX - 1)
        printf("\n STACK OVERFLOW");
    else
    {
        top++;
        st[top] = val;
    }
}
char pop(char st[])
{
    char val = ' ';
    if (top == -1)
        printf("\n STACK UNDERFLOW");
    else
    {
        val = st[top];
        top--;
    }
    return val;
}
int revert(char target[])
{
    int val, n, i, arr[10];

    printf("\n Enter the number of elements in the array : ");
    scanf("%d", &n);
    printf("\n Enter the elements of the array : ");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    for (i = 0; i < n; i++)
        push2(arr[i]);
    printf("\n -- The array is : -- \n");
    for (i = 0; i < n; i++)
    {
        printf("| %d |\n", arr[i]);
    }
    for (i = 0; i < n; i++)
    {
        val = pop2();
        arr[i] = val;
    }
    printf("\n -- The reversed array is : -- \n");
    for (i = 0; i < n; i++)
        printf("| %d |\n", arr[i]);
    getche();
    return 0;
}
void push2(int val)
{
    stk[++top] = val;
}
int pop2()
{
    return (stk[top--]);
}
