#include <iostream>
#include <algorithm>
using namespace std;
long long N;
long long k;
long long answer;
void bin(long long a, long long b) {
	long long x = (a + b) / 2, cnt = 0;
	if (b <= a + 3) {
		for (long long i = a; i <= b; i++) {
			cnt = 0;
			for (long long j = 1; j <= N; j++) {
				if (i / j > N) {
					cnt += N;
				}
				else
				{
					cnt += i / j;

				}
				
			}
			if (cnt >= k) {
				answer = i;
				break;
			}
		}
		return;
	}
	for (long long i = 1; i <= N; i++) {
		if (x / i > N) {
			cnt += N;
		}
		else
		{
			cnt += x / i;

		}
	}
	if (cnt >= k) {
		bin(a, x);
	}
	else {
		bin(x + 1, b);
	}

}
 int main() {
	cin >> N >> k;
	bin(1, N*N);
	cout << answer;
}