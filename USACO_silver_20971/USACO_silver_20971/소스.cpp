#include <iostream> 
using namespace std;
int N, Q;
string a;
string y="";
int b, c;
int x;
string cnt;
int d[100010];
int s[100010];
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int i, j, I;
	cin >> N >> Q>>a;
	for (i = a.size() - 1; i >= 0; i--) {
		y += a[i];
	}
	d[0] = 1;
	s[0] = 1;
	for (i = 1; i < a.size(); i++) {
		for (j = i-1; j >= 0; j--) {
			if (a[i] == a[j]) {
				break;
			}
		}
		bool sw = false;
		if (j == -1) sw = true;
		else {
			for (I = j + 1; I < i; I++) {
				if (a[i] > a[I]) sw = true;
			}
		}
		if (sw) d[i] = d[i - 1] + 1;
		else d[i] = d[i - 1];
	}
	for (i = 1; i < y.size(); i++) {
		for (j = i - 1; j >= 0; j--) {
			if (y[i] == y[j]) {
				break;
			}
		}
		bool sw = false;
		if (j == -1) sw = true;
		else {
			for (I = j + 1; I < i; I++) {
				if (y[i] > y[I]) sw = true;
			}
		}
		if (sw) s[i] = s[i - 1] + 1;
		else s[i] = s[i - 1];
	}

	for (int i = 0; i < Q; i++) {
		cin >> b >> c;
		if (b == 1 && c == a.size()) {
			cout << 0<<"\n";
		}
		else if (b == 1) {
			cout << s[a.size() - 1 - c]<<"\n";
		}
		else if (c == a.size()) {
			cout << d[b - 2]<<"\n";
		}
		else cout << d[b - 2] + s[a.size()-1- c] << "\n";
 	}


	return 0;
}