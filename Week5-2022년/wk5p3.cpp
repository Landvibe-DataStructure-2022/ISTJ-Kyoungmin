//
//  wk5p3.cpp
//  BOJ
//
//  Created by on 2022/04/05.
//

#include<iostream>
#include<string>
using namespace std;

int n,k;
string cmd;

class Node {
public:
    int x;
    Node* prev;
    Node* next;
    Node() { prev=next=NULL; }
    Node(int x) {
        prev=next=NULL;
        this->x = x;
    }
};

class DLL {
public:
    Node* header;
    Node* trailer;
    Node* p;
    int size;
    
    DLL() {
        header = new Node();
        trailer = new Node();
        header->next = trailer;
        trailer->prev = header;
        p=NULL;
        begin();
        size=0;
    }
    
    void begin() {
        p=header->next;
    }
    
    void end() {
        p=trailer;
    }
    
    bool empty() { return size == 0; }
    
    void insert(int e) {
        Node* tmp = new Node(e);
        Node* now = p;
        now->prev->next = tmp;
        tmp->prev = now->prev;
        now->prev = tmp;
        tmp->next = now;
        ++size;
    }
    
    void erase() {
        Node* tmp=p;
        if(empty()) { cout<<"Empty\n"; return; }
        if(p==trailer) { return; }
        tmp->prev->next = tmp->next;
        tmp->next->prev = tmp->prev;
        delete tmp;
        begin();
        --size;
    }
    
    void nextP() {
        if (p->next!=NULL) p=p->next;
    }

    void prevP() {
        if (p!=header->next) p=p->prev;
    }
    
    void print() {
        if(empty()) { cout<<"Empty\n"; return; }
        Node* tmp = header->next;
        while(tmp!=trailer) {
            cout<<tmp->x<<" ";
            tmp = tmp->next;
        }
        cout<<"\n";
    }
    
    void upper(int e) {
        string answer = "";
        Node* tmp = header->next;
        int index = 0;
        while(tmp!=trailer) {
            if(tmp->x > e){
                answer+=to_string(index);
                answer+=" ";
            }
            tmp = tmp->next;
            ++index;
        }
        (answer=="") ? cout<<"-1\n" : cout<<answer<<"\n";
    }
};

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    cin>>n;
    DLL list;
    
    while(n--){
        cin>>cmd;
        if(cmd=="begin"){
            list.begin();
        }
        else if(cmd=="end"){
            list.end();
        }
        else if(cmd=="insert"){
            cin>>k;
            list.insert(k);
        }
        else if(cmd=="erase"){
            list.erase();
        }
        else if(cmd=="nextP"){
            list.nextP();
        }
        else if(cmd=="prevP"){
            list.prevP();
        }
        else if(cmd=="print"){
            list.print();
        }
        else if(cmd=="upper"){
            cin>>k;
            list.upper(k);
        }
    }
}
