#include <iostream>
#include <algorithm>
using namespace std;
int t;
int n;
string arr[10010];
bool z;
bool ans(string a, string b) {
	for (int i = 0; ; i++) {
		if (i == a.length()) {
			return false;
		}
		if (a.at(i) != b.at(i)) {
			return true;
		}
	}
	return false;
}
int main() {
	cin >> t;
	for (int x = 0; x < t; x++) {
		cin >> n;
		 z=false;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		sort(arr, arr + n);
		for (int i = 1; i < n; i++) {
			if (ans(arr[i - 1], arr[i]) == false) {
				z = true;
			}
		}
		if (z == true) {
			cout << "NO"<<"\n";
		}
		else {
			cout << "YES \n";
		}
	}
}