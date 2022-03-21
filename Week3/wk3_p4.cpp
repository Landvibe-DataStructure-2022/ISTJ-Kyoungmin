#include<iostream>
#include<string>
using namespace std;

int t, x;
string cmd;

class Stack {
public:
	int stack[100];
	int index;

	Stack() { index = 0; }

	bool empty() { return index == 0; }
	int top() { return stack[index - 1]; }
	void push(int x) { stack[index++] = x; }
	int pop() { return stack[--index];}
};

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	Stack st;

	cin >> t;
	while (t--) {
		cin >> cmd;
		for (int i = 0; i < cmd.length(); i++) {
			if (cmd[i] - '0' >= 0 && cmd[i] - '0' < 10) st.push(cmd[i] - '0');
			else {
				if (cmd[i] == '+') { x = st.pop() + st.pop(); }
				else if(cmd[i]=='-') { x = (st.pop() - st.pop())*-1; }
				else if (cmd[i] == '*') { x = st.pop() * st.pop(); }
				st.push(x);
			}
		}
		cout << st.pop() << "\n";
	}
}