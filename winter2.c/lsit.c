#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

/*void TowerOfHanoi(int n, int frompeg, int topeg, int auxpeg) {
	if (n == 1) {
		printf("원반 1을 막대 %d로 부터 막대 %d로 옮긴다\n", frompeg, topeg);
		return;
	}
	else {
		TowerOfHanoi(n - 1, frompeg, auxpeg, topeg);
		printf("원반 %d를 막대 %d로부터 %d로옮긴다\n", n, frompeg, topeg);
		TowerOfHanoi(n - 1, auxpeg, topeg, frompeg);
	}
}

int main() {
	TowerOfHanoi(3, 1, 2, 3);
}*/
struct ListNode {
	int data;
	struct ListNode* next;
};
/*
int ListLength(struct ListNode* h) {
	struct ListNode* current = h;
	int count = 0;
	while (current != NULL) {
		count++;
		current = current->next;
	}
	return count;
}
int main() {
	ListLength()
}*/

void InserInLinkedList(struct ListNode** h, int data, int position) {
	int k = 0;
	struct ListNode* p, * q, * newNode;
	newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
	if (!newNode) {
		printf("Memory Error");
		return;
	}
	newNode->data = data;
	p = *h;
	if (position == 1 || *h == NULL) {
		newNode->next = p;
		*h = newNode;
	}
	else {
		while ((p != NULL) && (k < position)) {
			k++;
			q = p;
			p = p->next;
		}
		if (p == NULL) {
			q->next = newNode;
			newNode->next = NULL;
		}
		else {
			newNode->next = p;
			q->next = newNode;
		}
	}
}
void printlist(struct ListNode** h) {
	if (*h == NULL) {
		printf("리스트가 비어있음");
	}
	else {
		printf("%d");
	}
}

int main() {


}

