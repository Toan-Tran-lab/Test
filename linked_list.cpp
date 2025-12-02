#include <iostream>
using namespace std;

struct Node {
    int data; 
    Node* pNext;
};

void Create_List(Node*& pHead);
void Print(const Node* p);
void Print_Reverse(const Node* p);
int Length(const Node* p);
void Insert_begin(Node*& pHead,int x);
void Insert_Nth(Node*& pHead,int x,int n);
void Insert_After_K(Node*& pHead,int x);
void Remove_Nth(Node*& pHead,int n);
void Remove_Dups(Node*& pHead);
void Reverse_Iterative(Node*& pHead);
void Reverse_Recursive(Node*& pHead,Node* prev, Node* curr);



int main() {
    Node* pHead = nullptr;
    cout << "Enter a number (non-num to quit): ";
    int x,n;
    while (cin >> x) {
        cout << "At which position: ";
        cin >> n;
        Insert_Nth(pHead,x,n);
        Print(pHead);
        cout << "Enter a number (non-num to quit): ";
    }
    Remove_Dups(pHead);
    Print(pHead);
    Print_Reverse(pHead);
    cout << "\nDone!!";
    Delete_List(pHead);
    return 0;
}



void Insert_begin(Node*& pHead,int x) {
    Node* temp = new Node();
    temp->data = x;
    temp->pNext = pHead;
    pHead = temp;
}

void Print(const Node* p) {
    cout << "List is: ";
    while (p) {
        cout << p->data << ' ';
        p = p->pNext;
    }
    cout << '\n';
}

void Print_Reverse(const Node* p) {
    if (!(p->pNext)) {
        cout << "Reversed list is: " << p->data << ' ';
        return;
    }
    Print_Reverse(p->pNext);
   
    cout << p->data << ' ';
}

int Length(const Node* p) {
    int n=0;
    while (p) {
        n++;
        p = p->pNext;
    }
    return n;
}

void Insert_Nth(Node*& pHead,int x,int n) {
    if (n<=0 || n>Length(pHead)+1) {
        cout << "Invalid position!!\n";
        return;
    }
    if (n==1) {
        Insert_begin(pHead,x);
        return;
    }   
    Node* temp = pHead;
    for (int i=0; i<n-2; ++i) temp = temp->pNext;
    Node* temp2 = new Node();
    temp2->data = x;
    temp2->pNext = temp->pNext;
    temp->pNext = temp2;
}

void Reverse_Iterative(Node*& pHead) {
    Node *curr=pHead,*prev=nullptr,*next;
    while (curr) {
        next = curr->pNext;
        curr->pNext = prev;
        prev = curr;
        curr = next;
    }
    pHead = prev;
}

void Reverse_Recursive(Node*& pHead,Node* prev, Node* curr) {
    if (!curr) {
        pHead = prev;
        return;
    }
    Reverse_Recursive(pHead,curr,curr->pNext);
    curr->pNext = prev;
}

void Remove_Nth(Node*& pHead,int n) {
    if (Length(pHead)==0) {
        cout << "The list is empty, no node to remove!!\n";
       return; 
    }
    if (n<=0 || n>Length(pHead)) {
        cout << "Invalid position!!\n";
        return;
    }
    Node* temp = pHead;
    if (n==1) {
        pHead = temp->pNext;
        delete temp;
        return;
    }
    for (int i=0; i<n-2; ++i) temp = temp->pNext;
    Node* temp2 = temp->pNext;
    temp->pNext = temp2->pNext;
    delete temp2;
}

void Remove_Dups(Node*& pHead) {
    Node* curr=pHead;
    while (curr) {
        Node* prev=curr;
        Node* run=curr->pNext;
        while (run) {
            if (run->data==curr->data) {
                prev->pNext=run->pNext;
                delete run;
                run=prev->pNext;
            }
            else {  
                prev=run;
                run=run->pNext;
            }
        }
        curr=curr->pNext;
    }
}

void Insert_After_K(Node*& pHead,int k,int x) {
    Node* curr = pHead;
    bool exist = false;
    while (curr) {
        if (curr->data==k) {
            exist = true;
            break;
        }
        curr = curr->pNext;
    }
    if (!exist) {
        cout << "The value doesnt exist in the list!!\n";
        return;
    }
    Node* temp = new Node();
    temp->data = x;
    temp->pNext = curr->pNext;
    curr->pNext = temp;
}

void Insert_Before_K(Node*& pHead,int k,int x) {
    Node* curr = pHead, *prev = nullptr;
    while (curr != nullptr && curr->data != k) {
        prev = curr;
        curr = curr->pNext;
    }
    if (curr==nullptr) return;
    if (curr==pHead) {
        Insert_begin(pHead,x);
        return;
    }
    Node* temp = new Node();
    temp->data = x;
    temp->pNext = curr;
    prev->pNext = temp;
}

void Create_List(Node*& pHead) {
    cout << "Please input an integer (non-num to quit): ";
    int x;
    while (cin >> x) {
        Node* temp2 = new Node();
        temp2->data = x;
        temp2->pNext = nullptr;
        if (pHead==nullptr) pHead = temp2;
        else {
            Node* temp = pHead;
            while (temp->pNext) temp = temp->pNext;
            temp->pNext = temp2;
        }
        cout << "Please input an integer (non-num to quit): ";
    }
}

void Remove_All_K(Node*& pHead,int k) {
    Node* curr=pHead, *prev=nullptr;
    while(curr) {
        if (curr->data==k) {
            if (curr==pHead) {
                Node* next = curr->pNext;
                pHead=curr->pNext;
                delete curr;
                curr=next;
            }
            else {
                Node* next = curr->pNext;
                delete curr;
                curr=next;
                prev->pNext=curr;
            }
        }
        else {
            prev=curr;
            curr = curr->pNext;
        }
    }
}

void Delete_List(Node*& pHead) {
    Node *curr=pHead;
    while (curr) {
        Node* temp=curr;
        curr=curr->pNext;
        delete temp;
    }
    pHead=nullptr;
}

void Insert_Before_K(Node*& pHead,int k,int x) {
    if (!pHead) return;
    if (pHead->data==k) {
        Insert_begin(pHead,x);
        return;
    }
    Node* prev = pHead;
    while (prev->pNext && prev->pNext->data != k) {
        prev = prev->pNext;
    }
    if (prev->pNext==nullptr) return;
    Node* temp = new Node();
    temp->data = x;
    temp->pNext = prev->pNext;
    prev->pNext = temp;
}