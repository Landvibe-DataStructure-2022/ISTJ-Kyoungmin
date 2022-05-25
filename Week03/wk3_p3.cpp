#include<iostream>
#include<string>
using namespace std;
#define MAX 10000

int n, x;
string cmd;

class Node {
public:
	int element;
	Node* next;
	Node(int element) {
		this->element = element;
		this->next = NULL;
	}
};

class Stack {
public:
	Node* head;
	Node* tail;

	Stack() {
		head = tail = NULL;
	}

	bool empty() { return head == NULL; }
	void top() {
		empty() ? cout << "-1\n" : cout << head->element << "\n";
	}
	void push(int x) {
		Node* tmp = new Node(x);
		tmp->next = head;
		head = tmp;
	}
	void pop() {
		if (empty()) cout << "-1\n";
		else {
			Node* tmp = head;
			cout << tmp->element << "\n";
			head = head->next;
			delete tmp;
		}
	}
};

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	Stack st;

	cin >> n;
	while (n--) {
		cin >> cmd;
		if (cmd == "empty") { cout << st.empty() << "\n"; }
		else if (cmd == "top") { st.top(); }
		else if (cmd == "push") {
			cin >> x;
			st.push(x);
		}
		else if (cmd == "pop") { st.pop(); }
	}
}