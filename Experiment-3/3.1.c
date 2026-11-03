#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

struct Stack {
    int data[MAX_SIZE];
    int top;
};

struct MyQueue {
    struct Stack input;
    struct Stack output;
};

void initializeStack(struct Stack* stack) {
    stack->top = -1;
}

bool isStackEmpty(const struct Stack* stack) {
    return stack->top == -1;
}

bool isStackFull(const struct Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

void pushStack(struct Stack* stack, int value) {
    if (isStackFull(stack)) {
        return;
    }

    stack->data[++stack->top] = value;
}

int popStack(struct Stack* stack) {
    if (isStackEmpty(stack)) {
        return -1;
    }

    return stack->data[stack->top--];
}

void initializeQueue(struct MyQueue* queue) {
    initializeStack(&queue->input);
    initializeStack(&queue->output);
}

void transferElements(struct MyQueue* queue) {
    while (!isStackEmpty(&queue->input)) {
        pushStack(
            &queue->output,
            popStack(&queue->input)
        );
    }
}

void push(struct MyQueue* queue, int value) {
    pushStack(&queue->input, value);
}

int pop(struct MyQueue* queue) {
    if (isStackEmpty(&queue->output)) {
        transferElements(queue);
    }

    return popStack(&queue->output);
}

int peek(struct MyQueue* queue) {
    if (isStackEmpty(&queue->output)) {
        transferElements(queue);
    }

    if (isStackEmpty(&queue->output)) {
        return -1;
    }

    return queue->output.data[queue->output.top];
}

bool empty(const struct MyQueue* queue) {
    return isStackEmpty(&queue->input) &&
           isStackEmpty(&queue->output);
}

int main(void) {
    struct MyQueue queue;
    initializeQueue(&queue);

    push(&queue, 1);
    push(&queue, 2);
    push(&queue, 3);

    printf("Front: %d\n", peek(&queue));
    printf("Popped: %d\n", pop(&queue));

    printf("Front: %d\n", peek(&queue));
    printf("Popped: %d\n", pop(&queue));

    printf("Queue Empty: %s\n", empty(&queue) ? "true" : "false");

    return 0;
}
