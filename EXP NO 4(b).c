#include <stdio.h>
#include <ctype.h> 
#include <math.h>    
#include <stdlib.h>  

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow!\n");
        exit(1);
    }
    stack[++top] = value;
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow!\n");
        exit(1);
    }
    return stack[top--];
}

int evaluatePostfix(char *exp) {
    int i;
    int op1, op2, result;

    for (i = 0; exp[i] != '\0'; i++) {
        char ch = exp[i];

        if (isdigit(ch)) {
            push(ch - '0');
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
            op2 = pop();
            op1 = pop();

            switch (ch) {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': result = op1 / op2; break;
                case '^': result = pow(op1, op2); break;
            }

            push(result);
        }
        else if (ch == ' ' || ch == '\t') {
            continue;
        }
        else {
            printf("Invalid character in expression: %c\n", ch);
            exit(1);
        }
    }

    return pop();
}

int main() {
    char postfix[MAX];
    int result;

    printf("Enter a postfix expression (single-digit operands): ");
    scanf("%s", postfix);

    result = evaluatePostfix(postfix);

    printf("Result of postfix evaluation: %d\n", result);

    return 0;
}
