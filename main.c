#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

typedef int  elemType;
typedef struct LNode{
	elemType data;
	struct LNode *next;
}LNode;
LNode *createList(elemType arr[],int n){
	LNode *L,*r,*s;
	L = (LNode *)malloc(sizeof(LNode));
	if(L == NULL){
		printf("ø’º‰∑÷≈‰ ß∞‹.\n");
		exit(0);
	}
	r = L;
	for(int i = 0;i < n;i++){
		s = (LNode *)malloc(sizeof(LNode));
		if(s == NULL){
			printf("ø’º‰∑÷≈‰ ß∞‹.\n");
			exit(0);
		}
		s->data = arr[i];
		r->next = s;
		r = s;
	}
	r->next = NULL;
	return L;
}
void printList(LNode *L){
	LNode *p;
	p = L->next;
	while(p != NULL){
		printf("%d->",p->data);
		p = p->next;
	}
	printf("\n");
}
void list_del_rep(LNode **L){
	LNode *p,*q,*pre;
	p = (*L)->next;
	pre = (*L)->next;
	while(p != NULL){
		while(pre->next != NULL){
			if(pre->next->data == p->data){
				q = pre->next;
				pre->next = q->next;
				free(q);
			}
			else
				pre = pre->next;
		}
		p = p->next;
		pre = p;
	}
}
int main(){
	elemType a[] = {15,2,12,8,5,12,2,12,5,16,5,16,16,16,16,16};
	int len = sizeof(a)/sizeof(a[0]);
	LNode *L;
	L = createList(a,len);
	printList(L);
	list_del_rep(&L);
	printf("After delete:\n");
	printList(L);

	return 0;
}
