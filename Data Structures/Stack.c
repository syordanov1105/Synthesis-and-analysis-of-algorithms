#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{

    int *collection;
    int capacity;
    int size;

}Stack;

Stack *create_stack(int capacity);
void destroy_stack(Stack *stack);
bool is_full(Stack *stack);
bool is_empty(Stack *stack);
bool pop(Stack *stack, int *item);
bool push(Stack *stack, int item);
bool peek(Stack *stack, int *item);

int main()
{

    Stack *stack = create_stack(5);

    if (stack == NULL){
        printf("Error creating stack.\n");
        return 1;
    }

    if (is_empty(stack)) printf("Stack is empty!\n");

    push(stack, 5);
    printf("Stack size: %d\n", stack->size);

    push(stack, 6);
    push(stack, 9);
    push(stack, 3);
    push(stack, 1);

    if(is_full(stack)) printf("Stack is full!\n");
    printf("Stack size: %d\n", stack->size);

    bool try_push = push(stack , 2);
    if(!try_push) printf("Push failed!\n");

    int peek_val;
    peek(stack, &peek_val);
    printf("Peek val: %d\n", peek_val);

    destroy_stack(stack);


    return 0;
}

Stack *create_stack(int capacity){

    if( capacity <= 0) return NULL;

    Stack *stack = malloc(sizeof(Stack));
    if( stack == NULL ) return NULL;

    stack->collection = malloc(sizeof(int) * capacity);
    if ( stack->collection == NULL ){

        free(stack);
        return NULL;
    }

    stack->capacity = capacity;
    stack->size = 0;

    return stack;
}

void destroy_stack(Stack *stack){

    free(stack->collection);
    free(stack);
}

bool is_full(Stack *stack){

    return (stack->capacity == stack->size);
}

bool is_empty(Stack *stack){

    return (stack->size == 0);
}

bool push(Stack *stack, int item){

    if (is_full(stack)) return false;

    stack->collection[stack->size++] = item;

    return true;
}

bool peek(Stack *stack, int *item){

    if(is_empty(stack)) return false;

    *item = stack->collection[stack->size - 1];

    return true;
}

bool pop(Stack *stack, int *item){

    if(is_empty(stack)) return false;

    stack->size--;
    *item = stack->collection[stack->size];

    return true;
}

