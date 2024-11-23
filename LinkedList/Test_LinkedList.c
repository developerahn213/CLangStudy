#include "LinkedList.h"
#include "LinkedList.c"

int main(void)
{
    int i = 0;
    int Count =0;
    Node* List = NULL;
    Node* Current = NULL;
    Node* NewNode = NULL;

    for(i=0; i<5; i++)
    {
        NewNode = SLL_CreateNode(i);
        SLL_AppendNode(&List, NewNode);
    }
    /*
    NewNode = SLL_CreateNode(-1);
    SLL_InsertNewHead(&List, NewNode);

    NewNode = SLL_CreateNode(-2);
    SLL_InsertNewHead(&List, NewNode);
*/
    Count = SLL_GetNodeCount(List);
    for ( i=0; i<Count; i++)
    {
        Current = SLL_GetNodeAt(List, i);
        printf("List[%d] : %d\n", i, Current->Data);
    }
}