#include <iostream>
#include <algorithm>
using namespace std;
int n;
int poster[2][10010];
int coor_comp[20010];
int pan[20010];
int pan1[20010];
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);
	int index = 0;
	cin >> n;
	int a, b;
	int max = 0;
	int count = 0;
	for (int i =0; i < n; i++) {
		cin >> a >> b;
		poster[0][i] = a;
		poster[1][i] = b;
		coor_comp[index] = a;
		index++;
		coor_comp[index] = b;
		index++;
	}
	sort(coor_comp, coor_comp+index);
	for (int i = 0; i < n; i++) {
		a = poster[0][i];
		b = poster[1][i];
		int x = lower_bound(coor_comp, coor_comp + index, a) - coor_comp;
		int y = lower_bound(coor_comp, coor_comp + index, b) - coor_comp;
		for (int j = x; j <= y; j++) {
			pan[j] = i;
		}
	}
	sort(pan, pan + index);
	count++;
	for  (int i = 1; i < index; i++) {
		if (pan[i] != pan[i - 1]) {
			count++;
		}
	}
	cout << count;
	return 0;
}