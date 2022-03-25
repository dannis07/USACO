#include <iostream>
#include <vector>
using namespace std;
int N;
int arr[1000100];
int dp[1000100];
int a;
void bin(int start, int end) {
	if (end < start + 3) {
		for (int i = start; i <= end; i++) {
			if (dp[i] >= a) {
				dp[i] = a;
				return;
			}
		}
	}
	int mid = (start + end) / 2;
	if (dp[mid] < a) {
		bin(mid+1, end);
	}        
	if (dp[mid] >= a) {
		bin(start, mid);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int ans =0;
	cin >> N;
	int count = 0;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	dp[0] = arr[0];
	for (int i = 1; i < N; i++) {
		a = arr[i];
		if (dp[ans] < arr[i]) {
			ans += 1;
			dp[ans] = arr[i];
		}
		else {
			bin(0, ans);
		}
	}

	cout << ans + 1;
}