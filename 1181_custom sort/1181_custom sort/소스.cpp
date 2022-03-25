#include <iostream>
#include <algorithm>
using namespace std;
int N;
string arr[20010];
bool compare(string a, string b) {
	if (a.length() != b.length()) {
		return a.length() < b.length();
	}
	for (int i = 0; i<a.length(); i++) {
		if (a.at(i) != b.at(i)) {
			return a.at(i) < b.at(i);
		}
	}
	return false;
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N, compare);
	cout << arr[0] << "\n";
	for (int i = 1; i < N; i++) {
		if (arr[i - 1] != arr[i]) {
			cout << arr[i] << "\n";
		}
	}
}