#include<iostream>
using namespace std;
#define MAX 10000

int arr[MAX+1];
int t, n, d;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> t;
	while (t--) {
		cin >> n >> d;
		for (int i = 0; i < n; i++) cin >> arr[i];
		d = d % n;
		d = n - d;
		for (int i = d; i < n; i++) cout << arr[i] << " ";
		for (int i = 0; i < d; i++) cout << arr[i] << " ";
		cout << "\n";
	}
}