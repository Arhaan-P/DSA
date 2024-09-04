// #include <stdio.h>
// #include <ctype.h>
// #include <stdbool.h>
// #include <string.h>
// #include <stdlib.h>

// struct Stack {
//     char stack[100];
//     int top;
//     int maxSize;
// } s;

// bool isFull(struct Stack* s) {
//     return s->top == s->maxSize - 1;
// }

// bool isEmpty(struct Stack* s) {
//     return s->top == -1;
// }

// void push(struct Stack* s, char x) {
//     if (!isFull(s)) {
//         s->stack[++s->top] = x;
//     }
// }

// char pop(struct Stack* s) {
//     if (!isEmpty(s)) {
//         return s->stack[s->top--];
//     }
// }

// int isOperator(char ch) {
//     return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
// }

// int precedence(char op) {
//     switch (op) {
//         case '+':
//         case '-':
//             return 1;
//         case '*':
//         case '/':
//             return 2;
//         case '^':
//             return 3;
//     }
//     return 0;
// }

// char* infixPostfix(char* input) {
//     char* postfix = (char*)malloc((strlen(input) + 1) * sizeof(char ));
//     struct Stack s;
//     s.top = -1;
//     s.maxSize = 100;
    
//     int k = 0;
    
//     for(int i = 0; input[i] != '\0'; i++) {
//         char c = input[i];
//         if(isspace(c)) {
//             continue;
//         }
//         if (isdigit(c)) {
//            postfix[k++] = c;
//         }
//         if (c == '(') {
//             push(&s, c);
//         }
        
//         else if (c == ')') {
//             while (!isEmpty(&s) && s.stack[s.top] != '(') {
//                 postfix[k++] = pop(&s);
//             }
//             pop(&s);
//         }
//         else if (isOperator(c)) {
//             while (!isEmpty(&s) && precedence(s.stack[s.top]) >= precedence(c)) {
//                 postfix[k++] = pop(&s);
//             }
//             push(&s, c);
//         }
//     }
//     while (!isEmpty(&s)) {
//         postfix[k++] = pop(&s);
//     }
//     postfix[k] = '\0';
//     return postfix;
// }

// int main() {
//     char input[100];
//     fgets(input, sizeof(input), stdin);
//     int n = strlen(input);

//     for (int i = 0; i < n / 2; i++) {
//         char temp = input[i];
//         input[i] = input[n - i - 1];
//         input[n - i - 1] = temp;
//     }
//     printf("%s", input);
//     char* postfix = infixPostfix(input);
//     int l = strlen(postfix);

//     for (int i = 0; i < l / 2; i++) {
//         char temp = postfix[i];
//         postfix[i] = postfix[l - i - 1];
//         postfix[l - i - 1] = temp;
//     }
    
//     printf("%s\n", postfix);
//     free(postfix);
    
//     return 0;
// }

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

struct Stack {
    char stack[100];
    int top;
    int maxSize;
};

bool isFull(struct Stack* s) {
    return s->top == s->maxSize - 1;
}

bool isEmpty(struct Stack* s) {
    return s->top == -1;
}

void push(struct Stack* s, char x) {
    if (!isFull(s)) {
        s->stack[++s->top] = x;
    }
}

char pop(struct Stack* s) {
    if (!isEmpty(s)) {
        return s->stack[s->top--];
    }
    return '\0';  // Return null character if stack is empty
}

int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return 0;
}

char* infixToPostfix(char* input) {
    char* postfix = (char*)malloc((strlen(input) + 1) * sizeof(char));
    struct Stack s;
    s.top = -1;
    s.maxSize = 100;
    
    int k = 0;
    
    for(int i = 0; input[i] != '\0'; i++) {
        char c = input[i];
        if(isspace(c)) {
            continue;
        }
        if (isalnum(c)) {
           postfix[k++] = c;
        }
        else if (c == '(') {
            push(&s, c);
        }
        
        else if (c == ')') {
            while (!isEmpty(&s) && s.stack[s.top] != '(') {
                postfix[k++] = pop(&s);
            }
            pop(&s);  // pop '(' from stack
        }
        else if (isOperator(c)) {
            while (!isEmpty(&s) && precedence(s.stack[s.top]) >= precedence(c)) {
                postfix[k++] = pop(&s);
            }
            push(&s, c);
        }
    }
    while (!isEmpty(&s)) {
        postfix[k++] = pop(&s);
    }
    postfix[k] = '\0';
    return postfix;
}

void reverse(char* str) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

void swapParentheses(char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '(') {
            str[i] = ')';
        } else if (str[i] == ')') {
            str[i] = '(';
        }
    }
}

char* infixToPrefix(char* input) {
    reverse(input);
    swapParentheses(input);
    
    char* postfix = infixToPostfix(input);
    reverse(postfix);
    
    return postfix;
}

int main() {
    char input[100];
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';  // Remove the newline character
    
    char* prefix = infixToPrefix(input);
    printf("%s\n", prefix);
    free(prefix);
    
    return 0;
}