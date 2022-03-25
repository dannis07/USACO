#include <iostream>
#include <algorithm>
using namespace std;
int N;
pair<int,int> p[5010];
pair <int, int> p1;
pair <int, int> p2;

int main() {
	int i, j;
	int count = 0;
	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> p[i].first >> p[i].second;
	}
	sort(p, p + N);
	for (i = 0; i < N; i++) {
		for (j = i; j < N; j++) {
			if ((p[i].first < p[j].first) && p[i].second < p[j].second) {
				p1.first = p[i].first;
				p1.second = p[j].second;
				p2.first = p[j].first;
				p2.second = p[i].second;
				if ((upper_bound(p, p + N, p1) - p) != (lower_bound(p, p + N, p1) - p)) {
					if ((upper_bound(p, p + N, p2) - p) != (lower_bound(p, p + N, p2) - p)) {
						count++;
					}
				}

			}
		}
	}
	cout << count;
}