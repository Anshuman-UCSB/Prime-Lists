#include <iostream>
#include <string>

using namespace std;

struct node{
    int data;
    node* next;
};

node* nextNode(node* head){
    return head->next;
}

string stringNode(node* head){
    return to_string(head->data);
}

node* makeHead(int val){
    node* n = new node;
    n->data=val;
    n->next=0;
    //cout<<"Node head created, address "<<n<<endl;
    return n;
}

void addNode(node* prior, int val){
    node* n = new node;
    n->data=val;
    n->next=prior->next;
    prior->next=n;
}

void removeNode(node* prior){
    node* pop = prior->next;
    prior->next=pop->next;
    delete pop;
}

void printNode(node* head){
    cout<<"("<<head->data<<", "<<head->next<<")"<<endl;
}

void printList(node* head){
    cout<<"["<<endl;
    node* p;
    for(p = head; p!= 0; p = p->next){
        cout<<"    ";
        printNode(p);
    }
    cout<<"]"<<endl;
}


int main(){
    cout<<"---DEBUG MAIN---"<<endl;

    node* head;
    head = makeHead(2);
    addNode(head,3);
    printList(head);

    cout<<"---DEBUG MAIN FINISHED---"<<endl;
}