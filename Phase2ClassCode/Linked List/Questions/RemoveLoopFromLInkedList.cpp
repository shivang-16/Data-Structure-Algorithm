#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;

    node(int data){
        this -> data =data;
        this-> next =NULL;
    }
};
//Inserting node at tail(singly linked list)
void InsertAtTail(node* & tail, int d){
    node* temp= new node(d);
    tail->next = temp;
    tail = tail->next;
}
//traversing a linked list
void print(node* &head){
    node* temp= head;
    while( temp != NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
//FLOYD'S LOOP DETECTION ALGORITHM
node* floydDetect(node* head){
    if(head==NULL)
    return NULL;

    node* slow=head;
    node* fast=head;
    while( slow != NULL && fast != NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
        }
        slow = slow->next;

        if(slow == fast){
        return slow;
    }
    }
    return NULL;
}

//STARTING NOOD
node* getStartingNode(node* head){
    if(head== NULL)
    return NULL;

    node* POI = floydDetect(head);

    node* slow = head;
    node* fast = POI;

    while( slow != fast){
        slow= slow->next;
        fast = fast->next;
    }
    return slow;
}

/********************************************************************************************************************/
//REMOVING THE LOOP FORM A LINKED LIST
void RemoveLoop(node* head){
    if(head ==NULL)
    return;

    node* startNode = getStartingNode(head);
    node* temp = startNode;

    while(temp->next != startNode){
       temp = temp -> next;
     }

     temp->next = NULL;

     /*
     //MY CODE -> NOT 100% SURE THIS IS VALID FOR ALL CASES OR NOT

     node *startLoop=getStartingNode(head);
     tail->next= startLoop; //(pass the node* tail in above function)
     //breaking the loop
     tail->next= NULL;   
     */
}
/********************************************************************************************************************/

int main(){
    node* node1= new node(10);
    node* head = node1;
    node* tail = node1;
    print(head);
    InsertAtTail(tail, 20);
    print(head);
    InsertAtTail(tail, 30);
    print(head);
    InsertAtTail(tail, 40);
    print(head);

    //creating a loop
    tail->next = head->next->next;
     
   //calling floyd function
    if(floydDetect(head))
    cout<<"Loop is present"<<endl;
    else
    cout<<"Loop not present"<<endl;

    //Removing Loop
    RemoveLoop(head);
    cout<<"Loop Removed"<<endl;
    print(head);
    
   //calling floyd function
    if(floydDetect(head))
    cout<<"Loop is present"<<endl;
    else
    cout<<"Loop not present"<<endl;

    return 0;
}