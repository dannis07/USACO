#include <iostream>
#include <algorithm>
using namespace std;
long long N, M;  
long long arr[1000100];
long long c;
long long cut(long long b)
{
	long long a = 0;
	for (int i = 1; i <= N; i++) {
		if (arr[i] - b > 0) {
			a += arr[i] - b;
		}
	}
	return a;
}
void check(long long x, long long y) {
	if (x + 3 >= y) {
		// x~y사이에 답이 있다.
		for (long long k = y; k >= x; k--)
		{
			if (cut(k) >= M)
			{
				c = k; break;
			}
		}
		return;
	}
	long long a = 0;
	long long b = (x + y) / 2;
	a = cut(b);
	
	if (a < M) {
		check(x, b - 1);
	}
	if (a >= M) {
		check(b, y);
	}
}
int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	sort(arr + 1, arr + N + 1);
	check(0, arr[N]);
	cout << c;
}