#include <iostream>
using namespace std;
int N;
long long arr[110000];
long long count1=0;
bool check(int a, int b) {
	int x;
	if (arr[a] > arr[b]) {
		 x = arr[b];
	}
	else {
		 x = arr[a];
	}
	for (int i = a+1; i < b; i++) {
		if (arr[i] > x) {
			return false;
		}
	}
	return true;
}
int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i <= N; i++) {
		for (int j = i + 1; j <= N; j++) {
			if (check(i, j) == true) {
				count1 += j - i+1;
			}
		}
	}
	cout << count1;
}