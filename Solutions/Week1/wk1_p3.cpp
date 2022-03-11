#include<iostream>
#include<string>
using namespace std;
#define MAX 10000

int n, t;
int arr[MAX];

void at(int index) {
	cout << arr[index] << "\n";
}

void add(int index, int value) {
	for (int i = n - 2; i >= index; i--) {
		arr[i + 1] = arr[i];
	}
	arr[index] = value;
}

void remove(int index) {
	for (int i = index; i < n - 1; i++) {
		arr[i] = arr[i + 1];
	}
	arr[n - 1] = 0;
}

void set(int index, int value) {
	arr[index] = value;
	cout << value << "\n";
}

void print() {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << "\n";
}

void find_min() {
	int min = MAX + 1;
	for (int i = 0; i < n; i++) {
		if (min > arr[i]) min = arr[i];
	}
	cout << min << "\n";
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> t;
	string cmd;
	int index, value;

	while (t--) {
		cin >> cmd;
		if (cmd == "at") {
			cin >> index;
			at(index);
		}
		else if (cmd == "add") {
			cin >> index >> value;
			add(index, value);
		}
		else if (cmd == "remove") {
			cin >> index;
			remove(index);
		}
		else if (cmd == "set") {
			cin >> index >> value;
			set(index, value);
		}
		else if (cmd == "print") {
			print();
		}
		else if (cmd == "find_min") {
			find_min();
		}
	}
}