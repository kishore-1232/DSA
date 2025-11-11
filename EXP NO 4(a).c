#include <stdio.h>
#include <ctype.h>  
#include <string.h>  

#define MAX 100

char stack[MAX];
int top = -1;

void push(char);
char pop();
int precedence(char);
int isOperator(char);
void infixToPostfix(char infix[], char postfix[]);

void push(char c) {
    if (top == MAX - 1)
        printf("Stack Overflow!\n");
    else
        stack[++top] = c;
}

char pop() {
    if (top == -1)
        return -1; 
    else
        return stack[top--];
}

int precedence(char symbol) {
    switch (symbol) {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}

int isOperator(char symbol) {
    return (symbol == '+' || symbol == '-' || symbol == '*' || 
            symbol == '/' || symbol == '^');
}

void infixToPostfix(char infix[], char postfix[]) {
    int i, j = 0;
    char item, x;

    for (i = 0; i < strlen(infix); i++) {
        item = infix[i];

        if (isalnum(item)) 
            postfix[j++] = item;
        else if (item == '(')
            push(item);
        else if (item == ')') {
            while ((x = pop()) != '(')
                postfix[j++] = x;
        } else if (isOperator(item)) {
            while (top != -1 && precedence(stack[top]) >= precedence(item))
                postfix[j++] = pop();
            push(item);
        }
    }

    while (top != -1)
        postfix[j++] = pop();

    postfix[j] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
