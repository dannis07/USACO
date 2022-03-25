#include <iostream>
#include <algorithm>
using namespace std;
int N, M;
int arr[100100];
int a;
int b;
void bin(int x, int y) {
	if (x == y) {
		if (a == arr[x]) {
			b = 1;
		}
		else {
			b = 0;
		}
		return;
	}
	if (a <= arr[(x+y) / 2]) {
		bin(x, (x+y) / 2);
	}
	if (a > arr[(x + y) / 2]) {
		bin((x + y) / 2 + 1, y);
	}
	
}
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	sort(arr + 1, arr + N + 1);
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> a;
		bin(1, N);
		cout << b << "\n";
	}
	return 0;
}