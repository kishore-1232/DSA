#include <stdio.h>
#include <stdlib.h>

#define MAX 100  

int queue[MAX];
int front = -1, rear = -1;

int isFull() {
    return rear == MAX - 1;
}


int isEmpty() {
    return (front == -1 || front > rear);
}


void enqueue(int value) {
    if (isFull()) {
        printf("Queue Overflow! Cannot insert %d.\n", value);
        return;
    }

    if (front == -1)
        front = 0; 

    queue[++rear] = value;
    printf("%d enqueued to queue.\n", value);
}


void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow! No elements to dequeue.\n");
        return;
    }

    printf("Dequeued element: %d\n", queue[front]);
    front++;

    
    if (front > rear)
        front = rear = -1;
}


void peek() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Front element: %d\n", queue[front]);
}


void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Queue Operations Menu ---\n");
        printf("1. Enqueue (Insert)\n");
        printf("2. Dequeue (Delete)\n");
        printf("3. Peek (Front Element)\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
