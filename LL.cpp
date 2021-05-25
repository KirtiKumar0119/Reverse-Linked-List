#include<iostream>
using namespace std;

class Node
{
    public:
    int value;
    Node *next;
};

Node *start=NULL;

Node *newNode(int value)
{
    Node *node=new Node;
    node->value=value;
    node->next=NULL;
    return node;
}

Node* insert(int value)
{
    if(start==NULL)
        return newNode(value);
    
    Node *current = start;
    while(current->next != NULL)
    {
        current=current->next;
    }
    current->next = newNode(value);
    return current->next;
}

void reverse(int num)     
{
    Node* current=start;
    while(current->value!=num)
    {
        current=current->next;
    }

    if(current==NULL)
    {
        cout<<"Not found ";
        return;
    }

    Node* prvptr= NULL;
    Node* currptr;
    Node* nextptr=current->next;

    while(nextptr!=NULL)
    {
        prvptr=currptr;
        currptr=nextptr;
        nextptr=nextptr->next;
        
        currptr->next=prvptr; 
    }
    current->next=currptr; // reversed linked's last node
}


void printValue()
{
    Node *current= start;
    while(current!=NULL)
    {
        cout<<current->value<<endl;
        current=current->next;
    }
}

int main()
{
    start=insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);
    insert(60);  
    
    reverse(20);
    printValue(); 
    return 0;
}