#include <iostream>
#include <algorithm>
using namespace std;
int N;
string arr[51];
bool compare(string a, string b) {
	if (a.length() != b.length()) {
		return a.length() < b.length();
	}
	int sum_a = 0;
	int sum_b = 0;
	for (int i = 0; i < a.length(); i++) {
		if ('0' <= a.at(i) && a.at(i) <= '9') {
			sum_a += a.at(i) - '0';
		}
		if ('0' <= b.at(i) && b.at(i) <= '9') {
			sum_b += b.at(i) - '0';
		}
	}
	if (sum_a != sum_b) {
		return sum_a < sum_b;
	}
	return a < b;
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N, compare);
	for (int i = 0; i < N; i++) {
		cout << arr[i] << "\n";
	}
}