#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include<stdio.h>
#include<stdlib.h>

typedef int ElementType;

typedef struct tagNode{
	ElementType data;
	struct tagNode* nextData;
}Node;

// 함수 원형 선언
Node* SLL_CreateNode(ElementType newData);
void SLL_DestroyNode(Node* node);
void SLL_AppendNode(Node** head, Node* newNode);
void SLL_InsertAfter(Node* current, Node* newNode);
void SLL_InsertNewHead(Node** head, Node* newHead);
void SLL_RemoveNode(Node** head, Node* remove);
Node* SLL_GetNodeAt(Node* head, int Location);
int SLL_GetNodeCount(Node* head);
void SLL_InsertBefore(Node** head, Node* current, Node* newHead);
void SLL_DestroyAllNodes(Node** List); 


#endif


