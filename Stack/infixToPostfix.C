#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
    char data;
    struct stack *next;
} node;

node *top = NULL;

void push(char ele)
{
    node *ptr;

    if(ptr == NULL)
    {
        printf("Memory error!\n");
        return;
    }

    ptr = (node*)malloc(sizeof(node));
    ptr->data = ele;

    ptr->next = top;
    top = ptr;

}

char pop()
{
    node *temp;
    char token;

    if(top == NULL)
        return '\0';

    temp = top;
    top = temp->next;
    token = temp->data;
    free(temp);

    return token;
}

char* getUserInput()
{
    int MAX = 100, count = 0;
    char ch;
    char *exp = (char *) malloc(MAX*sizeof(char));

    while((ch = getchar()) != '\n')
    {
        if(count == MAX)
        {
            MAX += 100;
            exp = (char*) realloc(exp, MAX);
        }

        exp[count++] = ch;
    }
    exp[count] = '\0';
    return exp;
}

int precedence(char ch)
{
    int prec; 
    char token;

    if(ch == '^')
        prec = 3;

    else if(ch == '*' || ch == '/')
        prec = 2;

    else if(ch == '+' || ch == '-')
        prec = 1;

    else
        prec = -1;

    return prec;
}

int canPush(char ele, char stackTop)
{
    if( (stackTop == '(') || (ele == '(') || (precedence(ele) >= precedence(stackTop)) )
        return 1;

    return 0;
}


int isOperand(char ch)
{
    return (ch >= 'a' && ch <='z') || (ch >= 'A' && ch <='Z') || (ch == ' ') || (ch == '\t');
}


int main()
{
    printf("Enter infix expression -> ");
    char *exp = getUserInput();
    char token, stack_ele;
    node *temp;

    printf("Postfix -> ");
    while(*exp)
    {
        if(isOperand(*exp))
        {
            printf("%c", *exp);
        }

        else if(*exp == ')')
        {
            while((token = pop()) != '(')
                printf("%c", token);
        }

        else
        {
            stack_ele = top ? top->data : '~';
            while(!canPush(*exp, stack_ele))
            {
                token = pop();
                printf("%c",token);
                stack_ele = top ? top->data : '~';
            }
            push(*exp);
        }
 
        exp++;
    }

    while(top)
    {
        token = pop();
        printf("%c", token);
    }
    printf("\n");
    return(0);
}
