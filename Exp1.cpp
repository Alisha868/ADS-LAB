#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

// ---------- STACK FOR INTEGER ----------
int stack[MAX];
int top = -1;

void push(int item) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = item;
    }
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

void display() {
    if (top == -1) {
        printf("Stack is Empty\n");
        return;
    }

    printf("Final Stack Contents:\n");
    for (int i = top; i >= 0; i--)
        printf("%d ", stack[i]);
    printf("\n");
}

// ---------- INFIX TO POSTFIX ----------
char opStack[MAX];
int opTop = -1;

void pushOp(char ch) {
    opStack[++opTop] = ch;
}

char popOp() {
    return opStack[opTop--];
}

char peek() {
    return opStack[opTop];
}

int precedence(char ch) {
    switch (ch) {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}

void infixToPostfix(char infix[], char postfix[]) {
    int i, j = 0;

    for (i = 0; infix[i] != '\0'; i++) {

        char ch = infix[i];

        if (isalnum(ch))
            postfix[j++] = ch;

        else if (ch == '(')
            pushOp(ch);

        else if (ch == ')') {
            while (opTop != -1 && peek() != '(')
                postfix[j++] = popOp();
            popOp(); // Remove '('
        }

        else {
            while (opTop != -1 &&
                   precedence(peek()) >= precedence(ch))
                postfix[j++] = popOp();

            pushOp(ch);
        }
    }

    while (opTop != -1)
        postfix[j++] = popOp();

    postfix[j] = '\0';
}

// ---------- POSTFIX EVALUATION ----------
int evalStack[MAX];
int evalTop = -1;

void evalPush(int x) {
    evalStack[++evalTop] = x;
}

int evalPop() {
    return evalStack[evalTop--];
}

int evaluatePostfix(char postfix[]) {

    for (int i = 0; postfix[i] != '\0'; i++) {

        char ch = postfix[i];

        if (isdigit(ch))
            evalPush(ch - '0');

        else {
            int b = evalPop();
            int a = evalPop();

            switch (ch) {
                case '+': evalPush(a + b); break;
                case '-': evalPush(a - b); break;
                case '*': evalPush(a * b); break;
                case '/': evalPush(a / b); break;
                case '^': {
                    int p = 1;
                    for (int k = 0; k < b; k++)
                        p *= a;
                    evalPush(p);
                    break;
                }
            }
        }
    }

    return evalPop();
}

// ---------- MAIN ----------
int main() {

    int n, choice, value;

    printf("Enter Stack Size (<=100): ");
    scanf("%d", &n);

    do {
        printf("\n1. PUSH\n2. POP\n3. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                if (top == n - 1)
                    printf("Stack Overflow\n");
                else {
                    printf("Enter Value: ");
                    scanf("%d", &value);
                    push(value);
                }
                break;

            case 2:
                if (top == -1)
                    printf("Stack Underflow\n");
                else
                    printf("Deleted Element = %d\n", pop());
                break;

            case 3:
                break;

            default:
                printf("Invalid Choice\n");
        }

    } while (choice != 3);

    display();

    char infix[MAX], postfix[MAX];

    printf("\nEnter Infix Expression: ");
    scanf("%s", infix);

    opTop = -1;
    infixToPostfix(infix, postfix);

    printf("Postfix Expression: %s\n", postfix);

    printf("Evaluated Result: %d\n", evaluatePostfix(postfix));

    return 0;
}