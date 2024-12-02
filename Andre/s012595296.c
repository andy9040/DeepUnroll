#include <stdio.h>
#include <stdlib.h>

#define N 200

typedef struct stack{
    int top;
    int data[N];
} Stack;

void initialize(Stack*);
void push(Stack*, int);
int pop(Stack*);
int is_empty(Stack*);

int main(){
    int in;
    Stack *stack;

    initialize(stack);

    while(scanf("%d", &in) != EOF){
        if(in == 0){
            printf("%d\n", pop(stack));
        }else{
            push(stack, in);
        }
    }

    free(stack);

    return 0;
}

void initialize(Stack *stack){
    stack = malloc(sizeof(struct stack));
    stack->top = 0;
}

void push(Stack *stack, int e){
    stack->data[stack->top++] = e;
}

int pop(Stack *stack){
    if(is_empty(stack)){
        printf("Error: stack is empty.");
        return -1;
    }else{
        return stack->data[--stack->top];
    }
}

int is_empty(Stack* stack){
    return stack->top == 0;
}