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


int main(){
    cout<<"---DEBUG MAIN---"<<endl;

    node* head;
    head = makeHead(2);

    printList(head);

    int sizePrimes = 21;


    bool prime;
    node* last;
    
    for(int i = 3;i<sizePrimes;i++){

        if(i%6!=1 && i%6!=5){
            continue;
        }

        prime = true;
        last = head;

        cout<<"i: "<<i<<" - ";

        while(last->data<=pow(i,0.5)){
            

            if(i%last->data==0){
                cout<<"Not prime, "<<i<<" is divisible by "<<last->data<<"."<<endl;
                prime = false;
                break;
            }
            if(last->next==0){
                break;
            }

            last = nextNode(last);
        }
        if(prime){
            cout<<"Prime, "<<i<<" is not divisible by any prior prime.\n";
            appendNode(last, i);
        }
    }

    printPretty(head);

    cout<<"---DEBUG MAIN FINISHED---"<<endl;
}