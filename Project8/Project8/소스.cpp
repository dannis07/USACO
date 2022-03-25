#include <iostream>
using namespace std;
int T;
long long N;
long long arr[101000];
long long a;
bool t;
long long count1;
long long count2;
bool define()  {
	for (int i = 0; i < N-1; i++) {
		if (arr[i] != arr[i + 1]) {
			return false;
		}
	}
	return true;
}
void check() {
	count1 = 0;
	t = true;
	if (N == 2) {
		if (arr[0] == arr[1]) {
			count1 = 0;
			return;
		}
		else {
			t = false;
			return;
		}
	}
	else {
		for (int j = 0; j < N-2; j++) {
			count2 = 0;
			for (int i = 0; i < N - 2; i++) {
				if (arr[i] > arr[i + 1]) {
					t = false;
					return;
				}
				else {
					a = arr[i + 1] - arr[i];
					if (a >= 0) {
						arr[i + 1] -= a;
						arr[i + 2] -= a;
						count1 += a;
					}
				}
				if (arr[i] == arr[i + 1]) {
					a = arr[i + 1] - arr[i + 2];
					if (a > 0) {
						arr[i + 1] -= a;
						arr[i] -= a;
						count1 += a;
					}
				}
				if (arr[i] < 0 || arr[i + 1] < 0 || arr[i + 2] < 0) {
					t = false;
					return;
				}
			}
			if (define() == true) {
				return;
			}
		}
		for (int i = 0; i < N - 1; i++) {
			if (arr[i] != arr[i + 1]) {
				t = false;
				count1 = 0;
				return;
			}
		}
	}
}
int main() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		for (int j = 0; j < N; j++) {
			cin >> arr[j];
		}
		check();
		if (t == true) {
			cout << count1 * 2 << "\n";
		}
		else {
			cout << "-1" << "\n";
		}
	}
	return 0;
}