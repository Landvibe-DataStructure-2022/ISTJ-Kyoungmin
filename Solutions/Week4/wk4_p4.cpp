#include<iostream>
#include<string>
using namespace std;
#define MAX 10000

int t, n, value, compare;
int score[3];
int result[3];

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

	int dequeue() {
		if (empty()) return 0;
		else {
			int removed = head->x;
			Node* tmp = head;
			head = head->next;
			--queueSize;
			delete tmp;
			return removed;
		}
	}
};


int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	Queue p1, p2;

	cin >> t;

	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> value;
			p1.enqueue(value);
		}
		for (int i = 0; i < n; i++) {
			cin >> value;
			p2.enqueue(value);
		}
		while (n--) {
			compare = p1.dequeue() + score[1] - (p2.dequeue() + score[2]);
			if (compare > 0) {
				++result[1];
				score[1] = 0;
				score[2] = compare;
			}
			else if (compare < 0) {
				++result[2];
				score[1] = (compare * -1);
				score[2] = 0;
			}
			else {
				score[1] = score[2] = 0;
			}
		}
		result[1] >= result[2] ? cout << result[1] << "\n" : cout << result[2] << "\n";
		result[1] = result[2] = score[1] = score[2] = 0;
	}
}