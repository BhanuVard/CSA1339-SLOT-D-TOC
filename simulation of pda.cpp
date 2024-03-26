#include<stdio.h>
#include<string.h>

char stack[20];
int top;

void push(char symbol) {
    top++;
    stack[top] = symbol;
}

int pop() {
    if (top == -1)
        return 0;
    top--;
    return 1;
}

int main() {
    int m, i, j, k, l, a, len;
    char input[20], rem_input[20];
    
    printf("Simulation of Pushdown Automata for 0^n1^n\n");
    printf("Enter a string : ");
    scanf("%s", input);
    
    l = strlen(input);
    j = 0;
    top = -1;
    stack[0] = 'Z';

    printf("Stack\tInput\n");
    printf("%s\t%s\n", stack, input);
    
    while (1) {
        len = strlen(input);
        while (len > 0) {
            if (input[0] == '0') {
                push(input[0]);
                for (k = 0; k < len - 1; k++)
                    input[k] = input[k + 1];
                input[k] = '\0';
                printf("%s\t%s\n", stack, input);
            }
            else if (input[0] == '1') {
                a = pop();
                if (a == 0) {
                    printf("String not accepted");
                    goto b;
                }
                for (k = 0; k < len - 1; k++)
                    input[k] = input[k + 1];
                input[k] = '\0';
                printf("%s\t%s\n", stack, input);
            }
            len = strlen(input);
        }
        j++;
        if (j == l)
            break;
    }
    
    if (top >= 0)
        printf("String not accepted");
    else
        printf("String accepted");

b:
    printf("\n.............");
    return 0;
}

