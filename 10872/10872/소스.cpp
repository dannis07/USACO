#include <iostream>

using namespace std;
int N;
int factorial(int a) {
	if (a == 1) {
		return 1;
	}
	return factorial(a-1)*a;
}
int main() {
	cin >> N;
	cout<<factorial(N);
	return 0;
}