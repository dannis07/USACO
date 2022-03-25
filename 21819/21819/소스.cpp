#include <iostream>
#include <algorithm>
using namespace std;
long long N, K, L;
long long arr[100100];
long long answer;
bool is_ans(int mid)
{
	long long count = 0; bool valid = true;
	for (long long i = N; i > N - mid; i--) {
		if (arr[i] < mid) {
			count += mid - arr[i];
		}
		if (mid - arr[i] > K) {
			valid = false;
		}
	}
	if (count > L * K || valid == false) return false;
	return true;
}
void bin(long long start, long long end) {
	if (end < start + 3) {
		for (long long i = end; i >= start; i--) {
			if (is_ans(i) == true)
			{
				answer = i;
				return;
			}
		}
	}
	int mid = (start + end) / 2;
	if (is_ans(mid) == false) {
		bin(start, mid);
	}
	else  {
		bin(mid, end);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> K >> L;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	sort(arr + 1, arr + N + 1);
	bin(0, N);
	cout << answer;
}