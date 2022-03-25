#include <iostream>

using namespace std;
int N, a, b;
int count1;
void check(int x, int y) {
	int plus;
	int org;
	while (x != y) {
		int n, m;
		if(x>y) {
			if (x % 2 != 0) {
				x += 1;
				count1++;
			}
			if (y < x / 2) {
				plus = x + 2;
				org = x;
				int z = 0;
				int v = 0;
				while (plus > y) {
					if (plus % 2 != 0) {
						plus += 1;
						z++;
					}
					plus /= 2;
				}
				while (org > y) {
					org /= 2;
					if (org % 2 != 0) {
						org += 1;
						v++;
					}
				}
				if (plus == y) {
					x += 1;
					count1++;
				}
				else if (org == x) {
					x /= 2;
					count1++;
				}
				else if (plus * 2 - y+z > org * 2 - y+v) {
					x /= 2;
					count1++;
				}
				else if (plus*2-y+z < org*2 - y+v) {
					x += 1;
					count1++;
				}
				if (x / 2 == y) {
					x /= 2;
					count1++;
				}
			}
		}
		else if (y > x) {
			if (y < x * 2) {
				x = x += 1;
				count1++;
			}
			if (y > x * 2) {
				org = x;
				plus = x + 1;
				while (y > org) {
					org *= 2;
				}
				while (y > plus) {
					plus *= 2;
				}
				if (plus == y) {
					x += 1;
					count1++;
				}
				else if (org == y) {
					x *= 2;
					count1++;
				}
				else if (y - org / 2 > y - plus / 2) {
					x += 1;
					count1++;
				}
				else if (y - org / 2 < y - plus / 2) {
					x *= 2;
					count1++;
				}
			}
			if (x * 2 == y) {
				x *= 2;
				count1++;
			}
		}
		cout<<count1<<" "<<x<<endl;

	}
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		count1 = 0;
		check(a, b);
		cout << count1<<"\n";
	}
	
}