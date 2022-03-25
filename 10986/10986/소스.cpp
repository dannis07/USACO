#include <iostream>
using namespace std;
int N, M;
int arr;
int sum[1100000];
int rec[1100000];
int main() {
	int count=0;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> arr;
		sum[i] = (sum[i - 1] + arr) % M;
		if (sum[i] == 0) {
			count++;
		}
		rec[sum[i]] += 1;
	}
	for (int i = 0; i < M; i++) {
		count += rec[i] * (rec[i] - 1) / 2;
	}
	cout << count << "\n";
	return 0;
}