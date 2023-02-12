//일반 스택

/*#include <stdlib.h>
#include <stdio.h>
#define MAXSIZE 1000

typedef struct {
    int top;
    int capacity;
    int* array;
}stack;

stack* CreateStack() {
    stack* S = (stack*)malloc(sizeof(stack));
    if (!S) return NULL;
    S->capacity = MAXSIZE;
    S->top = -1;
    S->array = (int*)malloc(S->capacity * sizeof(int));
    if (!S->array) {
        return NULL;
    }
    return S;
}
int IsEmptyStack(stack* S) {
    return(S->top == -1);
}
int IsFullStack(stack* S) {
    return(S->top == S->capacity - 1);
}
void Push(stack* S, int data) {
    if (IsFullStack(S)) {
        printf("Stack Overflow");
    }
    else {
        S->top = S->top + 1;
        S->array[S->top] = data;
    }
}
int Pop(stack* S) {
    if (IsEmptyStack(S)) {
        printf("Stack is Empty");
        return INT_MIN;
    }
    else {
        return(S->array[(S->top)--]);
    }
}
void DeleteStack(stack* S) {
    if (S) {
        if (S->array)
            free(S->array);
        free(S);
    }
}
void PrintStack(stack* S) {
    if (IsEmptyStack(S)) {
        printf("Stack is Empty");
    }
    else {
        printf("{ ");
        for (int i = 0; i <= S->top; i++) {
            printf("%d ", S->array[i]);
        }
        printf("}");
    }
    printf("\n");
}
int main() {
    stack* S = CreateStack();
    PrintStack(S);
    Push(S, 1);
    PrintStack(S);
    Push(S, 3);
    Push(S, 4);
    PrintStack(S);
    Pop(S);
    PrintStack(S);
    Pop(S);
    PrintStack(S);
    Pop(S);
    PrintStack(S);
}*/


//동적스택
/*struct DynArrayStack {
    int top;
    int capacity;
    int* array;
};
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

int main() {
    DynArrayStack* S = CreateStack(3);
    PrintStack(S);
    Push(S, 1);
    PrintStack(S);
    Push(S, 3);
    Push(S, 4);
    PrintStack(S);
    Pop(S);
    PrintStack(S);
    Pop(S);
    PrintStack(S);
    Pop(S);
    PrintStack(S);
}*/

//스택+리스트
//struct ListNode {
//    int data;
//    struct ListNode* next;
//};
//
//struct Stack {
//    struct ListNode* top;
//};
//
//struct Stack* CreateStack() {
//    struct Stack* stk;
//    stk = (struct Stack*)malloc(sizeof(struct Stack));
//    stk->top = NULL;
//    return stk;
//}
//
//void Push(struct Stack* stk, int data) {
//    struct ListNode* temp;
//    temp = (struct LlistNode*)malloc(sizeof(struct ListNode));
//    if (!temp)
//        return;
//    temp->data = data;
//    temp->next = stk->top;
//    stk->top = temp;
//}
//
//int isEmptyStack(struct Stack* stk) {
//    return (stk->top == NULL);
//}
//
//int Pop(struct Stack* stk) {
//    int data;
//    struct ListNode* temp;
//    if (isemptyStack(stk))
//        return INT_MIN;
//    temp = stk->top;
//    stk->top = stk->top->next;
//    data = temp->data;
//    free(temp);
//    return data;
//}
//
//int Top(struct Stack* stk) {
//    if (isEmptyStack(stk))
//        return INT_MIN;
//    return stk->top->data;
//}
//
//void DeleteStack(struct Stack* stk) {
//    struct ListNode* temp, * p;
//    p = stk->top;
//    while (p) {
//        temp = p->next;
//        free(p);
//        p = temp;
//    }
//    free(stk);
//}

