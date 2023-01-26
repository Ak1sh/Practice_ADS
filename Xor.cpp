#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* ptr;
};
node* Xor(node *a, node* b){
    return reinterpret_cast<node*>( reinterpret_cast<uintptr_t>(a) ^ reinterpret_cast<uintptr_t>(b));
}
void insertfrombegin(node **head_ref, int data)
{
    node* new_node= new node();
    new_node->data=data;
    new_node->ptr=*head_ref;
    
    if(*head_ref){
        (*head_ref)->ptr= Xor((*head_ref)->ptr,new_node);
    }
    *head_ref=new_node;
}
void insertatanypos(node**head_ref,int data,int pos)
{
    node *new_node=new node();
    new_node->data=data;
    new_node->ptr=*head_ref;
    
    if(*head_ref==NULL){
        *head_ref=new_node;
        return;
    }
    if(pos==0){
     (*head_ref)->ptr= Xor(new_node,(*head_ref)->ptr);
     *head_ref=new_node;
     return;
    }
    
    node *prev=NULL;
    node *curr=*head_ref;
    node *next;
    
    for(int i=1;i<pos&& curr!=NULL;i++){
        next=Xor(curr->ptr,prev);
        prev=curr;
        curr=next;
    }
    
    new_node->ptr=Xor(prev,curr);
    prev->ptr=Xor(new_node,Xor(curr,prev->ptr));
    curr->ptr=Xor(new_node,Xor(prev,curr->ptr));
    
}
void delatanypos(int pos,node *head){
    node*curr=head;
    node*prev=NULL;
    node*next;
    if(curr==NULL){
        cout<<"Empty list";
        return;
    }
    if(pos==0){
         (*head)->ptr = Xor(NULL, XOR(temp, (*head)->nxp));
        next=curr->ptr;
        delete *head;
        *head=next;
        return;
    }
}
void printfrombeginning(node *head){
    node *curr=head;
    node *prev=NULL;
    node *next;
    while(curr!=NULL){
        cout<<curr->data<<" ";
        next=Xor(prev,curr->ptr);
       
        prev=curr;
        curr=next;
    }
    
}
int main()
{
    node* head = NULL;
    insertfrombegin(&head,10);
    insertfrombegin(&head,100);
    insertfrombegin(&head,1000);
    insertfrombegin(&head,10000);
    insertfrombegin(&head,100000);
    insertatanypos(&head,55,3);
    printfrombeginning(head);
    
        return 0;
}
