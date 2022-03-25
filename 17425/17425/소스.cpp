#include <iostream>

using namespace std;
int N, M;
long long arr[1000010];
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	for (int i = 1; i * i <= 1000000; i++) {
		for (int j = i; i * j <= 1000000; j++) {
			if (i == j) {
				arr[i * j] += i;
			}
			else {
				arr[i * j] += i + j;
			}
		}
	}
	for (int i = 2; i <= 1000000; i++) {
		arr[i] = arr[i - 1] + arr[i];
	}
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> M;
		cout << arr[M] << "\n";
	}
	return 0;
}