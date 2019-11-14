#include <iostream>
#include <string>
#include <cmath>

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

void appendNode(node* any, int val){
    while(any->next!=0){
        any = nextNode(any);
    }
    node* n = new node;
    n->data = val;
    n->next = 0;
    
    any->next=n;
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

void printPretty(node* head){
    cout<<head->data;
    head = nextNode(head);
    for(node* p = head;p!=0;p=nextNode(p)){
        cout<<", "<<p->data;
    }
    cout<<endl;
}

int sizeList(node* head){
    node* p = head;
    int i;
    for(i = 0;p!=0;i++){
        p=nextNode(p);
    }
    return i;
}

int main(){
    cout<<"---DEBUG MAIN---"<<endl;

    node* head;
    head = makeHead(2);

    int sizePrimes = 1000;
    cout<<"Up to what number to test for primes: ";
    cin>>sizePrimes;

    bool prime;
    node* last;
    
    for(int i = 3;i<sizePrimes;i++){
        if(i%6!=1 && i%6!=5){
            continue;
        }
        prime = true;
        last = head;

        while(last->data<=pow(i,0.5)){
            if(i%last->data==0){
                prime = false;
                break;
            }
            if(last->next==0){
                break;
            }
            last = nextNode(last);
        }
        if(prime){
            appendNode(last, i);
        }
    }
    printPretty(head);
    cout<<"Solved for "<<sizeList(head)<<" primes."<<endl;
    cout<<"---DEBUG MAIN FINISHED---"<<endl;
}