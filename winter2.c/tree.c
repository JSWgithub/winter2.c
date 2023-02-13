#include <stdlib.h>
#include <stdio.h>

typedef struct DynArrayStack {
    int top;
    int capacity;
    int* array;
}DAS;

struct DynArrayStack* CreateStack(int cap) {
    struct DynArrayStack* S = (struct DynArrayStack*)malloc(sizeof(struct DynArrayStack));
    if (!S) return NULL;
    S->capacity = cap;
    S->top = -1;
    S->array = (int*)malloc(S->capacity * sizeof(int));
    if (!S->array) {
        return NULL;
    }
    return S;
}
int isFullStack(struct DynArrayStack* S) {
    return(S->top == S->capacity - 1);
}
void DoubleStack(struct DynArrayStack* S) {
    S->capacity *= 2;
    S->array = (int*)realloc(S->array, S->capacity * sizeof(int));
}
void Push(struct DynArrayStack* S, int x) {
    if (isFullStack(S))
        DoubleStack(S);
    S->array[++S->top] = x;
}
int isEmptyStack(struct DynArrayStack* S) {
    return(S->top == -1);
}

int Top(struct DynArrayStack* S) {
    if (isEmptyStack(S))
        return INT_MIN;
    return S->array[S->top];
}
int Pop(struct DynArrayStack* S) {
    if (isEmptyStack(S))
        return INT_MIN;
    return S->array[S->top--];
}
void DeleteStack(struct DynArrayStack* S) {
    if (S) {
        if (S->array)
            free(S->array);
        free(S);
    }
}


typedef struct {
    int front, rear;
    int capacity;   // 최대 용량
    int size;      // 현재 데이터 수
    int* array;
} queue;


queue* CreateQueue(int cap) {
    queue* Q = (queue*)malloc(sizeof(queue));
    if (!Q)
        return NULL;
    Q->capacity = cap;
    Q->size = 0;
    Q->front = Q->rear = -1;
    Q->array = (int*)malloc(Q->capacity * sizeof(int));
    if (!Q->array)
        return NULL;
    return Q;
}

int IsEmptyQueue(queue* Q) {
    return (Q->size == 0);
}

int IsFullEmpty(queue* Q) {
    return (Q->size == Q->capacity);
}

int IsQueueSize(queue* Q) {
    return (Q->size);
}

void EnQueue(queue* Q, int data) {
    if (IsFullEmpty(Q))
        printf("Queue Overflow\n");
    else {
        Q->rear = (Q->rear + 1) % Q->capacity;
        Q->array[Q->rear] = data;
        if (Q->front == -1)
            Q->front = Q->rear;
        Q->size += 1;
    }
}

int DeQueue(queue* Q) {
    int data;
    if (IsEmptyQueue(Q)) {
        printf("Queue is Empty\n");
        return INT_MIN;
    }
    else {
        data = Q->array[Q->front];
        Q->size -= 1;
        if (Q->front == Q->rear)
            Q->front = Q->rear = -1;
        else
            Q->front = (Q->front + 1) % Q->capacity;
    }
    return data;
}

void DeleteQueue(queue* Q) {
    if (Q) {
        if (Q->array) free(Q->array);
        free(Q);
    }
}

void PrintQueue(queue* Q) {
    printf("[Queue : ");
    if (Q->front == Q->rear) {
        printf("Empty!]\n");
    }
    else if (Q->front < Q->rear) {
        for (int i = 0; i < Q->capacity; i++) {
            if (i < Q->front)
                printf("x");
            else if ((Q->front <= i) && (i <= Q->rear))
                printf("%d", Q->array[i]);
            else
                printf("x");

            if (i < Q->capacity - 1)
                printf("-");
        }
        printf("]\n");
    }
    else {
        for (int i = 0; i < Q->capacity; i++) {
            if (i <= Q->rear)
                printf("%d", Q->array[i]);
            else if (Q->front <= i)
                printf("%d", Q->array[i]);
            else
                printf("x");

            if (i < Q->capacity - 1)
                printf("-");
        }
        printf("]\n");
    }

    printf("[Queue : ");
    for (int i = 0; i < Q->size; i++) {
        if ((Q->front + i) < Q->capacity)
            printf("%d", Q->array[Q->front + i]);
        else
            printf("%d", Q->array[Q->front + i - Q->capacity]);

        if (i < Q->size - 1)
            printf("-");
    }
    printf("]\n");
}

typedef struct BinaryTreeNode {
    int data;
    struct BinaryTreeNode* left;
    struct BinaryTreeNode* right;
}BTN;

void PreOrder(BTN* node) {
    if (node) {
        printf(" %d ", node->data);
        PreOrder(node->left);
        PreOrder(node->right);
    }
}

void PreOrderIterative(BTN* node) {
    DAS* S = CreateStack(5);
    while (1) {
        while (node) {
            printf(" %d ", node->data);
            Push(S, node);
            node = node->left;
        }
        if (isEmptyStack(S))
            break;
        node = Pop(S);
        node = node->right;
    }
    DeleteStack(S);
}

void InOrder(BTN* node) {
    if (node) {
        InOrder(node->left);
        printf(" %d ", node->data);
        InOrder(node->right);
    }
}

void InOrderIterative(BTN* node) {
    DAS* S = CreateStack(5);
    while (1) {
        while (node) {
            Push(S, node);
            node = node->left;
        }
        if (isEmptyStack(S)) break;
        node = Pop(S);
        printf(" %d ", node->data);
        node = node->right;
    }
    DeleteStack(S);
}

void PostOrder(BTN* node) {
    if (node) {
        PostOrder(node->left);
        PostOrder(node->right);
        printf("%d", node->data);
    }
}

void LevelOrder(BTN* node) {
    BTN* temp;
    queue* Q = CreateQueue(5);
    if (!node)
        return;
    EnQueue(Q, node);
    while (!IsEmptyQueue(Q)) {
        temp = DeQueue(Q);
        printf("%d", temp->data);
        if (temp->left)
            EnQueue(Q, temp->left);
        if (temp->right)
            EnQueue(Q, temp->right);
    }
    DeleteQueue(Q);
}

BTN* CreteBinaryTreeNode(int dt) {
    BTN* S = (BTN*)malloc(sizeof(BTN));
    S->data = dt;
    S->left = NULL;
    S->right = NULL;
    return S;
}
int main() {
    BTN* S[7];
    for (int i = 0; i < 7; i++) {
        S[i] = CreteBinaryTreeNode(i + 1);
    }
    S[0]->left = S[1];
    S[0]->right = S[2];
    S[1]->left = S[3];
    S[1]->right = S[4];
    S[2]->left = S[5];
    S[2]->right = S[6];

    InOrder(S[0]);

}