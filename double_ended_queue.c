#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};
//Ability to insert node at beginning
struct Node* insertAtBeginning(struct Node* head, int value)
{
    struct Node* toAdd=(struct Node*)malloc(sizeof(struct Node));
    toAdd->data=value;
    toAdd->next=head;
    return toAdd;
}
//Ability to insert node at end
struct Node* insertAtEnd(struct Node* head, int value)
{
    if(head==NULL)
    {
        return insertAtBeginning(head,value);
    }
    struct Node* toAdd=(struct Node*)malloc(sizeof(struct Node));
    toAdd->data=value;
    toAdd->next=NULL;
    struct Node* ptr=head;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=toAdd;
    return head;
}
//Ability to delete from beginning
struct Node* deleteAtBeginning(struct Node* head)
{
    if(head==NULL)
    {
        printf("The queue is empty, hence cannot perform delete operation.\n");
        return head;
    }
    struct Node* p=head;
    head=head->next;
    free(p);
    return head;
}
//Ability to delete from the end
struct Node* deleteFromEnd(struct Node* head)
{
    if(head == NULL)
    {
        printf("The queue is empty, hence cannot perform the delete operation.\n");
        return head;
    }
    if(head->next == NULL) // Case with only one node
    {
        free(head);
        return NULL;
    }
    struct Node* p = head;
    struct Node* q = head->next;
    while(q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}

//Ability to compute the length of the queue
int computeLengthOfTheQueue(struct Node* head)
{
    if(head==0)
    {
        return 0;
    }
    int l=0;
    struct Node* p=head;
    while(p->next!=NULL)
    {
        l++;
        p=p->next;
    }
    return (l+1);
}
//Ability to peek the element from the beginning
void peekFromBeginning(struct Node* head)
{
    if(head==NULL)
    {
        printf("The queue is empty.\n");
        return;
    }
    struct Node* p=head;
    int dataAtBeginning=p->data;
    printf("Current element eligible to be removed from the front: %d\n",dataAtBeginning);
    return;
}
//Ability to peek the element from the end
void peekFromEnd(struct Node* head)
{
    if(head==NULL)
    {
        printf("The queue is empty.\n");
        return;
    }
    struct Node* p=head;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    int dataAtEnd=p->data;
    printf("Current element eligible to be removed from the end: %d\n",dataAtEnd);
    return;
}
//Ability to check the queue is empty or not
void isEmpty(struct Node* head)
{
    if(head==NULL)
    {
        printf("The queue is empty.\n");
    }
    else
    {
        printf("The queue is not empty.\n");
    }
    return;
}
//Ability to free the queue once all the operations are completed.
struct Node* freeQueue(struct Node* head)
{
    struct Node* temp;
    while(head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
    return NULL;
}
//Traverse the elements of the queue
void traverseElements(struct Node* head)
{
    if(head==NULL)
    {
        printf("The queue is empty.\n");
        return;
    }
    struct Node* ptr=head;
    printf("Current elements: ");
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
    return;
}
int main()
{
    struct Node* head=NULL;
    int data,choice,lengthOfQueue;
    while(1)
    {
        printf("Menu operations for a doubly ended queue\n");
        printf("1.Insert element at the beginning push_front()\n");
        printf("2.Insert element at the end push_back()\n");
        printf("3.Delete element from the beginning pop_front()\n");
        printf("4.Delete element from the end pop_back()\n");
        printf("5.Peek from first\n");
        printf("6.Peek from end\n");
        printf("7.Compute the length of the queue\n");
        printf("8.Queue is empty\n");
        printf("9.Traverse the elements of the queue\n");
        printf("10.Exit program\n");
        printf("Enter your choice from the above given options\n");
        printf("Enter the choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter the data which needs to be added at the beginning: ");
                    scanf("%d",&data);
                    head=insertAtBeginning(head,data);
                    break;
            case 2: printf("Enter the data which needs to be added at the end: ");
                    scanf("%d",&data);
                    head=insertAtEnd(head,data);
                    break;
            case 3: head=deleteAtBeginning(head);
                    break;
            case 4: head=deleteFromEnd(head);
                    break;
            case 5: peekFromBeginning(head);
                    break;
            case 6: peekFromEnd(head);
                    break;
            case 7: lengthOfQueue=computeLengthOfTheQueue(head);
                    printf("Current length: %d\n",lengthOfQueue);
                    break;
            case 8: isEmpty(head);
                    break;
            case 9: traverseElements(head);
                    break;
            case 10: head = freeQueue(head);
                    exit(1);
                    break;
            default: printf("Please enter the valid choice from the above given options.\n");
        }
    }
    return 0;
}
