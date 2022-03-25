#include <iostream>

using namespace std;
int arr[50100];
int n;
bool check(int a) {
	for (int i = 0; i * i <= n; i++) {
		if (i * i == a) {
			return true;
		}
	}
	return false;
}
int main() {
	cin >> n;
	arr[1] = 1;
	arr[2] = 2;
	for (int i = 3; i <= n; i++) {
		int min = 500100;
			for (int j = 0; j * j <= n; j++) {
				if (i <= j * j) {
					break;
				}
				if (1 + arr[i - j * j] < min) {
					min = 1 + arr[i - j * j];
				}
			}
			arr[i] = min;
	}
	cout << arr[n];
	return 0;
}
