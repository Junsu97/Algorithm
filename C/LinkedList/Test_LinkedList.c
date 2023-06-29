#include "LinkedList.h"


void main(){
    int i           = 0;
    int count       = 0;
    Node* list      = NULL;
    Node* current   = NULL;
    Node* newNode   = NULL;


    // 노드 5개 추가
    for(i = 0; i < 5; i++){
        newNode = SLL_CreateNode(i);
        SLL_AppendNode(&list,newNode);
    }

    newNode = SLL_CreateNode(-1);
    SLL_InsertNewHead(&list, newNode);

        newNode = SLL_CreateNode(-2);
    SLL_InsertNewHead(&list, newNode);

    //리스트 출력
    count = SLL_GetNodeCount(list);
    for( i = 0; i < count; i++){
        current = SLL_GetNodeAt(list,i);
        printf("List[%d] : %d\n", i, current->data);
    }

    //리스트의 세 번째 노드 뒤에 새 노드 삽입
    printf("\nInserting 3000 After [2]...\n\n");

    current = SLL_GetNodeAt(list,2);
    newNode = SLL_CreateNode(3000);

    SLL_InsertAfter(current, newNode);

    //리스트 출력
    count = SLL_GetNodeCount(list);
    for( i = 0; i < count; i++){
        current = SLL_GetNodeAt(list,i);
        printf("List[%d] : %d\n", i, current->data);
    }

    // 모든 노드를 메모리에서 삭제
    printf("\nDestroying List...\n");

    for(i = 0; i < count; i++){
        current = SLL_GetNodeAt(list,0);

        if(current != NULL){
            SLL_RemoveNode(&list, current);
            SLL_DestroyNode(current);
        }
    }
    
    // 리스트의 세번째 노드 앞에 새 노드 삽입
    printf("\nInserting -3000 After [2]...\n");

    current = SLL_GetNodeAt(list,2);
    newNode = SLL_CreateNode(-3000);

    SLL_InsertBefore(&list, current, newNode);

    //리스트 출력
    count = SLL_GetNodeCount(list);
    for( i = 0; i < count; i++){
        current = SLL_GetNodeAt(list,i);
        printf("List[%d] : %d\n",i,current->data);
    }

    printf("\nDestroying List...\n");
    SLL_DestroyAllNodes(&list);
}