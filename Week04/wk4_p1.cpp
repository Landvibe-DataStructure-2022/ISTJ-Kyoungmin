#include<iostream>
#include<string>
using namespace std;
#define MAX 10000

int t, value;
string cmd;

class Node {
public:
	int x;
	Node* next;
	Node(int x) {
		this->x = x;
	}
};

class Queue {
public:
	Node* head;
	Node* tail;
	int queueSize;

	Queue() {
		head = tail = NULL;
		queueSize = 0;
	}

	bool empty() { return queueSize == 0; }

	void enqueue(int value) {
		Node* tmp = new Node(value);
		if (empty()) {
			head = tail = tmp;
			head->next = tail;
		}
		else {
			tail->next = tmp;
			tail = tmp;
		}
		++queueSize;
	}

	void dequeue() {
		if (empty()) cout << "Empty\n";
		else {
			cout << head->x << "\n";
			Node* tmp = head;
			head = head->next;
			--queueSize;
			delete tmp;
		}
	}

	void isEmpty() { empty() ? cout << "True\n" : cout << "False\n"; }
	void size() { cout << queueSize << "\n"; }
	void front() { empty() ? cout<<"Empty\n" : cout << head->x << "\n"; }
	void rear() { empty() ? cout<<"Empty\n" : cout << tail->x << "\n"; }
};


int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> t;
	Queue q;

	while (t--) {
		cin >> cmd;
		if (cmd == "enqueue") {
			cin >> value;
			q.enqueue(value);
		}
		else if (cmd == "dequeue") q.dequeue();
		else if (cmd == "isEmpty") q.isEmpty();
		else if (cmd == "size") q.size();
		else if (cmd == "front") q.front();
		else if (cmd == "rear") q.rear();
	}
}