#include<iostream>
#include<algorithm>
#include <vector>
using namespace std;
int N;
vector<int> flower[100010];
int a, b, c, d;
int check[2] = { 3, 1 };
bool valid = false;
int arr[2]={3, 1};	
int main() {
	int count = 0;
	int count1 = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a >> b >> c >> d;
		flower[i].push_back(a);
		flower[i].push_back(b);
		flower[i].push_back(c);
		flower[i].push_back(d);
	}
	sort(flower, flower + N);
	int i = 0;
	while (arr[0] < 12) {
		valid = false;
		for (; i < N; i++) {
			if (flower[i].at(0) > check[0] || (flower[i].at(0) == check[0] && flower[i].at(1) > check[1])) {
				check[0] = arr[0];
				check[1] = arr[1];
				break;
			}
			else if (flower[i].at(2) > arr[0] || (flower[i].at(2) == arr[0] && flower[i].at(3) > arr[1])) {
				arr[0] = flower[i].at(2);
				arr[1] = flower[i].at(3);
				valid = true;
			}
		}
		if (valid == true) {
			count++;
		}
		if (valid == false) {
			count = 0;
			break;
		}
	}
	cout << count;
	return 0;
}