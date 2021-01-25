// Program to convert infix expression to postfix and prefix using stacks

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

char *getPostfix(char *exp)
{
    char token, stack_ele;
    char *postfix = (char *) malloc(sizeof(char) * (strlen(exp) + 1));
    int i = 0;

    while(*exp)
    {
        if(isOperand(*exp))
        {
            postfix[i++] = *exp;
        }

        else if(*exp == ')')
        {
            while((token = pop()) != '(')
                postfix[i++] = token;
        }

        else
        {
            stack_ele = top ? top->data : '~';
            while(!canPush(*exp, stack_ele))
            {
                token = pop();
                postfix[i++] = token;
                stack_ele = top ? top->data : '~';
            }
            push(*exp);
        }
 
        exp++;
    }

    while(top)
    {
        token = pop();
        postfix[i++] = token;
    }
    postfix[i] = '\0';

    return postfix;
}

char *reverse(char *exp)
{
    int i,j;
    i = 0;
    j = strlen(exp) - 1;
    char temp;

    while(i < j)
    {
         
        temp = exp[i];
        exp[i] = exp[j];
        exp[j] = temp;

        i++;
        j--;
    }

    return exp;
}

char *getPrefix(char *exp)
{
    char *intermediate = (char *) malloc(sizeof(char) * (strlen(exp) + 1));
    char *prefix;
    int i = 0;

    // Get infix into proper form 
    intermediate = reverse(exp);
    while(intermediate[i])
    {
        if(intermediate[i] == '(')
            intermediate[i] = ')';

        else if(intermediate[i] == ')')
            intermediate[i] = '(';

        i++;
    }

    prefix = reverse(getPostfix(intermediate));

    return prefix;
}

int main()
{
    char *prefix, *postfix;

    printf("\n\t\tFix Converter\n\n");
    printf("Enter infix expression -> ");
    char *exp = getUserInput();

    postfix = getPostfix(exp);
    prefix = getPrefix(exp);
    
    printf("Postfix -> %s\n", postfix);
    printf("Prefix -> %s\n\n", prefix);

    return(0);
}
