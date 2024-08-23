#include <stdio.h>
#include <stdlib.h>

// Node structure
struct QueueNode {
    int value;
    struct QueueNode* nextNode;
};

// Queue structure
struct Queue {
    struct QueueNode* head;
    struct QueueNode* tail;
};

// Function to create a new node
struct QueueNode* createQueueNode(int value) {
    struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    newNode->value = value;
    newNode->nextNode = NULL;
    return newNode;
}

// Function to create an empty queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->head = queue->tail = NULL;
    return queue;
}

// Function to add an element to the queue (enqueue)
void enqueue(struct Queue* queue, int value) {
    struct QueueNode* newNode = createQueueNode(value);
    if (queue->tail == NULL) {
        queue->head = queue->tail = newNode;
        return;
    }
    queue->tail->nextNode = newNode;
    queue->tail = newNode;
}

// Function to remove an element from the queue (dequeue)
int dequeue(struct Queue* queue) {
    if (queue->head == NULL) {
        printf("Queue is empty\n");
        return -1;
    }
    struct QueueNode* current = queue->head;
    int value = current->value;
    queue->head = queue->head->nextNode;

    if (queue->head == NULL) {
        queue->tail = NULL;
    }

    free(current);
    return value;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return queue->head == NULL;
}

// Function to get the front element of the queue
int peek(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    return queue->head->value;
}

// Function to display the queue elements
void displayQueue(struct Queue* queue) {
    struct QueueNode* current = queue->head;
    while (current != NULL) {
        printf("%d -> ", current->value);
        current = current->nextNode;
    }
    printf("NULL\n");
}

int main() {
    struct Queue* queue = createQueue();
    
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    
    printf("Queue: ");
    displayQueue(queue);

    printf("Dequeued: %d\n", dequeue(queue));
    printf("Queue after dequeue: ");
    displayQueue(queue);

    printf("Peek: %d\n", peek(queue));
    printf("Queue after peek: ");
    displayQueue(queue);

    return 0;
}

