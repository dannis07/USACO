#include <iostream>
using namespace std;
string ans[3];
string gue[3];
string a, b;
int green = 0;
int yellow = 0;
int final;
string a_1;
int main() {
	for (int i = 0; i < 3; i++) {
		cin >> ans[i];
	}
	for (int i = 0; i < 3; i++) {
		cin >> gue[i];
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			a = ans[i];
			b = gue[i];
			if (a[j] == b[j]) {
				a[j] = '0';
				b[j] = '0';
				ans[i] = a;
				gue[i] = b;
			}
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int n = 0; n < 3; n++) {
				for (int m = 0; m < 3; m++) {
					a = ans[i];
					a_1 = gue[n];
					if (a[j] != '0') {
						if (a[j] == a_1[m]) {
							a_1[m] = '1';
							gue[n] = a_1;
							a[j] = '1';
							ans[i] = a;
						}
					}
				}
			}
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			a = gue[i];
			if (a[j] == '0') {
				green++;
			}
			if (a[j] == '1') {
				yellow++;
			}
		}
	}
	cout << green << "\n" << yellow;

	return 0;
}