#include<iostream>
#include<string>
using namespace std;
#define MAX 10000

int n, t, x;
string cmd;

class Queue {
public:
	int queue[MAX + 1];
	int queueSize;
	int frontIndex;
	int backIndex;
	Queue() { queueSize = frontIndex = backIndex = 0; }

	bool empty() { return queueSize == 0; }
	void isEmpty() { empty() ? cout << "True\n" : cout << "False\n"; }
	void size() { cout << queueSize << "\n"; }
	void front() { empty() ? cout << "Empty\n" : cout << queue[frontIndex] << "\n"; }
	void rear() { empty() ? cout << "Empty\n" : cout << queue[backIndex-1] << "\n"; }

	void enqueue(int value) {
		if (queueSize == n) cout << "Full\n";
		else {
			queue[backIndex] = value;
			++queueSize;
			++backIndex;
			backIndex %= n;
		}
	}

	void dequeue() {
		if (empty()) cout << "Empty\n";
		else {
			cout << queue[frontIndex] << "\n";
			--queueSize;
			++frontIndex;
			frontIndex %= n;
		}
	}
};

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> t;
	Queue q;
	
	while (t--) {
		cin >> cmd;
		if (cmd == "enqueue") {
			cin >> x;
			q.enqueue(x);
		}
		else if (cmd == "dequeue") q.dequeue();
		else if (cmd == "isEmpty") q.isEmpty();
		else if (cmd == "size") q.size();
		else if (cmd == "front") q.front();
		else if (cmd == "rear") q.rear();
	}
}