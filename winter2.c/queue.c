#include <stdlib.h>
#include <stdio.h>

//큐

//typedef struct ArrayQueue {
//    int front, rear;
//    int capcity;
//    int size;
//    int* array;
//}queue;
//
//struct ArrayQueue* CreateQueue(int cap) {
//    struct ArrayQueue* Q = (queue*)malloc(sizeof(struct ArrayQueue));
//    if (!Q)
//        return NULL;
//    Q->capcity = cap;
//    Q->size = 0;
//    Q->front = Q->rear = -1;
//    Q->array = (int*)malloc(Q->capcity * sizeof(int));
//    if (!Q->array)
//        return NULL;
//    return Q;
//}
//
//int IsEmptyQueue(struct ArrayQueue* Q) {
//    return ((Q->size) == 0);
//}
//int IsFullQueue(struct ArrayQueue* Q) {
//    return (Q->size == Q->capcity);
//}
//
//int QueueSize(struct ArrayQueue* Q) {
//    return (Q->size);
//}
//
//void EnQueue(struct ArrayQueue* Q, int data) {
//    if (IsFullQueue(Q))
//        printf("Queue Overflow\n");
//    else {
//        Q->rear = (Q->rear + 1) % Q->capcity;
//        Q->array[Q->rear] = data;
//        if (Q->front == -1)
//            Q->front = Q->rear;
//        Q->size += 1;
//    }
//}
//
//int DeQueue(queue* Q) {
//    int data;
//    if (IsEmptyQueue(Q)) {
//        printf("queue is Empty\n");
//        return INT_MIN;
//    }
//    else {
//        data = Q->array[Q->front];
//        Q->size -= 1;
//        if (Q->front == Q->rear)
//            Q->front = Q->rear = -1;
//        else
//            Q->front = (Q->front + 1) % Q->capcity;
//    }
//    return data;
//}
//
//void DeleteQueue(queue*Q) {
//    if (Q) {
//        if (Q->array) free(Q->array);
//        free(Q);
//    }
//}
//void printQueue(queue* Q) {
//    int tmp = Q->front;
//    printf("{ ");
//    while (tmp != Q->rear) {
//        printf("%d ", Q->array[tmp]);
//        tmp = (tmp + 1) % Q->capcity;
//    }
//    printf("%d }", Q->array[Q->rear]);
//}
//
//int main() {
//    queue* Q= CreateQueue(4);
//    EnQueue(Q, 10);
//    EnQueue(Q, 11);
//    EnQueue(Q, 12);
//    EnQueue(Q, 13);
//    DeQueue(Q);
//    printQueue(Q);

//}

//큐와 리스트
typedef struct ListNode {
    int data;
    struct ListNode* next;
}node;

typedef struct Queue {
    struct ListNode* front;
    struct ListNode* rear;
    int size;
}queue;

struct Queue* CreateQueue() {
    struct Queue* Q;
    Q = (struct Queue*)malloc(sizeof(struct Queue));
    if (!Q) {
        return NULL;
    }
    Q->front = Q->rear = NULL;
    Q->size = 0;
    return Q;
}

int IsEmptyQueue(struct Queue* Q) {
    return (Q->front == NULL);
}

int QueueSize(struct Queue* Q) {
    return (Q->size);
}

void EnQueue(struct Queue* Q, int data) {
    struct ListNode* newNode;
    newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    if (!newNode)
        return;
    newNode->data = data;
    newNode->next = NULL;
    Q->size += 1;
    if (Q->front == NULL) {
        Q->front = newNode;
        Q->rear = newNode;
    }
    else {
        Q->rear->next = newNode;
        Q->rear = newNode;
    }
    printf("Queue에 %d 를 넣었습니다\n\n", data);
    
}
int DeQueue(struct Queue* Q) {
    int data = INT_MIN;
    struct ListNode* temp;
    if (IsEmptyQueue(Q)) {
        printf("queue is empty");
        return data;
    }
    else {
        Q->size -= 1;
        temp = Q->front;
        data = Q->front->data;
        Q->front = Q->front->next;
        if (Q->front == NULL) Q->rear = NULL;
        free(temp);
       printf("Queue에서 %d를 뺐습니다\n\n", data);

    }
    return data;
}

void DeleteQueue(struct Queue* Q) {
    struct ListNode* temp;
    while (Q->front) {
        temp = Q->front;
        Q->front = Q->front->next;
        free(temp);
    }
    free(Q);
}

void printQueue(queue* Q) {
    struct ListNode* temp;
    temp = Q->front;
    printf("Queue : {");
    while (temp) {
        printf(" %d ", temp->data);
        temp = temp->next;
    }
    printf("}\n\n");

}

int main() {
    queue* Q = CreateQueue();
    EnQueue(Q, 5);
    printQueue(Q);
    EnQueue(Q, 6);
    printQueue(Q);
    EnQueue(Q, 7);
    printQueue(Q);
    EnQueue(Q, 8);
    printQueue(Q);
    DeQueue(Q);
    printQueue(Q);
    EnQueue(Q, 9);
    printQueue(Q);
}
