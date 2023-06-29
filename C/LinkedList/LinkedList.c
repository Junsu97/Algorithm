#include "LinkedList.h"

// 노드생성
Node* SLL_CreateNode(ElementType newData){
    Node* newNode = (Node*)malloc(sizeof(Node));

    newNode->data = newData; // 데이터 저장
    newNode->nextData = NULL; // 다음 노드에 대한 포인터는Null로 초기화

    return newNode; // 노드 주소 반환
}

// 노드 소멸
void SLL_DestroyNode(Node* node){
    free(node);
}

void SLL_DestroyAllNodes(Node** list){
    int i;
    int count;
    Node* current = NULL;

    count = SLL_GetNodeCount((*list));
    for( i = 0; i< count; i++){
        current = SLL_GetNodeAt((*list),0);
        if(current != NULL){
            printf("Destorying %d\n",current->data);
            SLL_RemoveNode(list,current);
            SLL_DestroyNode(current);
        }
    }
}

// 노드추가
void SLL_AppendNode(Node** head, Node* newNode){
    // 헤드 노드가 NULL이라면 새로운 노드가 head
    if ( (*head) == NULL){
        *head = newNode;
    }else{
        // 테일을 찾아 NewNode 연결
        Node* tail = (*head);
        while (tail -> nextData != NULL)
        {
            tail = tail -> nextData;
        }
        tail->nextData=newNode;
    }
}

// 노드 삽입
void SLL_InsertAfter(Node* current, Node* newNode){
    newNode->nextData = current->nextData;
    current->nextData = newNode;
}

void SLL_InsertNewHead(Node** head, Node* newHead){
    if(*head == NULL){
        (*head) = newHead;
    }else{
        newHead->nextData = (*head);
        (*head) = newHead;
    }
}

void SLL_InsertBefore(Node** head, Node* current, Node *newHead){
    if((*head)==current){
        SLL_InsertNewHead(head,newHead);
    }else{
        Node* before = (*head);
        while(before->nextData != current){
            before = before ->nextData;
        }
        SLL_InsertAfter(before,newHead);
    }
}


// 노드제거
void SLL_RemoveNode(Node** head, Node* remove){
    if( *head == remove){
        *head = remove -> nextData;
    }else{
        Node* current = *head;
        while (current != NULL && current->nextData != remove){
            current = current->nextData;
        }
        if( current != NULL){
            current->nextData =remove->nextData;
        }
    }
}

Node* SLL_GetNodeAt(Node* head, int location){
    Node* current = head;

    while (current != NULL && (--location) >= 0)
    {
        current = current->nextData;
    }
    return current;
}

// 노드 수 세기
int SLL_GetNodeCount(Node* head){
    int count = 0;
    Node* current = head;

    while (current != NULL)
    {
        current = current->nextData;
        count++;
    }
    return count;
}