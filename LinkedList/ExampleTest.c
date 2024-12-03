#include <stdio.h>
#include <stdlib.h>

typedef struct TagNode {
    int Data;
    struct TagNode * NextNode;
} Node;

Node* SLL_CreateNode(int NewData){
    Node* NewNode = (Node*)malloc(sizeof(Node));
    NewNode->Data = NewData;
    NewNode->NextNode = NULL;

    return NewNode;
}

void SLL_AppendNode(Node **Head, Node *NewNode){
    if ((*Head == NULL)){
        *Head = NewNode;
    } else {
        Node * Tail = *Head;
        while(Tail->NextNode != NULL){
            Tail = Tail->NextNode;
        }
        Tail->NextNode = NewNode;
    }
}

void SLL_InsertNewHead(Node **Head,Node *NewHead){
    if((*Head)==NULL){
        (*Head) = NewHead;
    } else {
        NewHead->NextNode = (*Head);
        (*Head) = NewHead;
    }
}

int SLL_GetNodeCount(Node *Head){
    int Count = 0;
    Node * Current = Head;
    while(Current != NULL){
        Count++;
        Current = Current->NextNode;
    }
    return Count;
}

Node * SLL_GetNodeAt(Node *Head, int Location){
    Node * Current = Head;
    while(Current != NULL && (--Location)>=0){
        Current = Current->NextNode;
    }
    return Current;
}

void SLL_InsertAfter(Node *Current, Node * NewNode){
    NewNode->NextNode = Current->NextNode;
    Current->NextNode = NewNode;
}

void SLL_RemoveNode(Node** Head, Node * Remove){
    if((*Head == Remove)){
        (*Head) = Remove->NextNode;
    } else {
        Node * Current = *Head;
        while(Current != NULL && Current->NextNode != Remove){
            Current = Current->NextNode;
        }

        if(Current != NULL){
            Current->NextNode = Remove->NextNode;
        }
    }
}

void SLL_DestroyNode(Node * Current){
    free(Current);
}


int main (){
    Node * List = NULL;
    Node * NewNode = NULL;
    Node * Current = NULL;

    for (int i=0; i<5; i++){
        NewNode = SLL_CreateNode(i);
        SLL_AppendNode(&List, NewNode);
    }

    NewNode = SLL_CreateNode(-1);
    SLL_InsertNewHead(&List, NewNode);

    NewNode = SLL_CreateNode(-2);
    SLL_InsertNewHead(&List, NewNode);

    int Count = 0;
    Count = SLL_GetNodeCount(List);
    for(int i = 0; i<Count; i++ ){
        Current = SLL_GetNodeAt(List, i);
        printf("Node[%d]=%d\n", i, Current->Data);
    }
    
    printf("\nInserting 3000 After [2]...\n\n");

    Current = SLL_GetNodeAt(List, 2);
    NewNode = SLL_CreateNode(3000);
    SLL_InsertAfter(Current, NewNode);

    Count = SLL_GetNodeCount(List);
    for (int i=0; i<Count; i++)
    {
        Current = SLL_GetNodeAt(List, i);
        printf("List[%d]: %d\n", i, Current->Data);
    }

    printf("\nDestroying List...\n");

    Count = SLL_GetNodeCount(List);
    for (int i = 0; i<Count; i++ ){
        Current = SLL_GetNodeAt(List, i);
        if(Current != NULL){
            SLL_RemoveNode(&List, Current);
            SLL_DestroyNode(Current);    
        }
    }



    printf("NewNode Data:%d\n", List->Data);
    printf("List Next Node:%8x\n", List->NextNode);
    printf("List Next Next Node:%8x\n", ((List->NextNode)->NextNode)->NextNode);


    printf("End\n");

    return 0;
}