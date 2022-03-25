#include <iostream>
using namespace std;
long long A, B;
long long func(long long x) {
	if (x < 0) {
		return 0;
	}
	if (x == 0) {
		return 0;
	}
	if (x == 1) {
		return 1;
	}
	long long a = 1, n = 0;
	while (a <= x) {
		a *= 2;
		n++;
	}
	 return (n - 1) * a/4 + func(x - a / 2) + x - a / 2 + 1;

}
int main() {
	cin >> A >> B;
	cout << func(B) - func(A-1);
	return 0;
}