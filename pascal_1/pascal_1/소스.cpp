#include <iostream>
using namespace std;
long long arr[1000000];
long long ans[1000000];
long long a = 1;
long long b = 1;
long long temp;
long long c;
long long row = 2;
long long N;
long long stan;
long long count1;
long long count_odd = 0;
long long count_even = 0;
long long max1 = 0;
void update_pascal(long long a) {
	ans[a] = arr[a - 1];
	if (a != 1) {
		long long val = 1;
		count1 += 1;
		for (long long j = 0; j <= count1; j++) {
			arr[j] = val;
			val = val * (count1 - 1 - j) / (j + 1);
		}
		update_pascal(a - 1);
	}
	else {
		return;
	}
}
void create_pascal() {
	for (long long i = 0; i < stan; i++) {
		long long val = 1;
		for (long long j = 0; j <= i; j++) {
			arr[j] = val;
			val = val * (i - j) / (j + 1);
		}
	}
}
void find_row() {
	for (long long i = 0; i < 10000; i++) {
		temp = b;
		b = a + b;
		a = temp;
		row++;
		if (b == N) {
			return;
		}

	}
}
int main() {
	cin >> N;
	if (N == 1) {
		cout << "1 0 1";
	}
	else {
		find_row();
		if (row % 2 == 1) {
			stan = (row + 1) / 2;
			count1 = stan;
			create_pascal();
			update_pascal(stan);
			for (long long i = 1; i <= stan; i++) {
				if (ans[i] % 2 == 0) {
					count_even++;
				}
				else if (ans[i] % 2 == 1) {
					count_odd++;
				}
				if (ans[i] > max1) {
					max1 = ans[i];
				}
			}
		}
		else {
			stan = (row + 2) / 2;
			count1 = stan;
			create_pascal();
			update_pascal(stan - 1);
			for (long long i = 1; i < stan; i++) {
				if (ans[i] % 2 == 0) {
					count_even++;
				}
				else if (ans[i] % 2 == 1) {
					count_odd++;
				}
				if (ans[i] > max1) {
					max1 = ans[i];
				}
			}
		}

		cout << count_odd << " " << count_even << " " << max1;
	}

}