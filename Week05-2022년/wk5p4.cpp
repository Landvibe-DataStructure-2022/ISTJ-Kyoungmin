//
//  wk5p4.cpp
//  BOJ
//
//  Created by 이경민 on 2022/04/04.
//

#include <iostream>
using namespace std;

int t,k,num;

int findMax(int a,int b) {
    return (a>b) ? a : b;
}

int findMin(int a,int b) {
    return (a<b) ? a : b;
}

class Node {
public:
    int x;
    Node* prev;
    Node* next;

    Node(int x){
        this->x = x;
        prev=next=NULL;
    }
};

class DLL {
private:
    Node* head;
    Node* tail;
    int size;

public:
    DLL() {
        head = tail = NULL;
        size = 0;
    }

    bool empty() {
        return size == 0;
    }

    void insert(int x) {
        Node* tmp = new Node(x);
        if(empty()) {
            head = tail = tmp;
        }
        else {
            tail->next = tmp;
            tmp->prev = tail;
            tail = tmp;
        }
        size++;
    }

    void print() {
        Node* tmp = head;
        while(tmp!=NULL){
            int max = -1;
            int min = 999;
            
            if(tmp->prev!=NULL){
                max = findMax(max, tmp->prev->x);
                min = findMin(min, tmp->prev->x);
            }
            if(tmp->next!=NULL){
                max = findMax(max, tmp->next->x);
                min = findMin(min, tmp->next->x);
            }
            max = findMax(max, tmp->x);
            min = findMin(min, tmp->x);
            cout<<max-min<<" ";
            tmp = tmp->next;
        }
        cout<<"\n";
    }
};

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    cin>>t;

    while(t--) {
        cin>>k;
        DLL list;
        while(k--){
            cin>>num;
            list.insert(num);
        }
        list.print();
    }
}
