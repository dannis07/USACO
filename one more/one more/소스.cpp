#include <iostream>
using namespace std;
int arr[4];
int arr1[4];
int arr2[4];
char a, b, c;
void check_3() {
	int count1 = 0;
	int count2 = 0;
	int count3 = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (arr[i] > arr1[j]) {
				count1++;
			}
			else if (arr[i] < arr1[i]) {
				count2++;
			}
		}
	}
	if (count1 > count2) {
		a = 'a';
	}
	if (count2 > count1) {
		a = 'b';
	}
	count1 = 0;
	count2 = 0;
	count3 = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (arr2[i] > arr1[j]) {
				count3++;
			}
			else if (arr2[i] < arr1[i]) {
				count2++;
			}
		}
	}
	if (count3 > count2) {
		b = 'c';
	}
	if (count2 > count3) {
		b = 'b';
	}
	count1 = 0;
	count2 = 0;
	count3 = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (arr[i] > arr2[j]) {
				count1++;
			}
			else if (arr[i] < arr2[i]) {
				count3++;
			}
		}
	}
	if (count1 > count3) {
		c = 'a';
	}
	if (count3 > count1) {
		c = 'c';
	}
	count1 = 0;
	count2 = 0;
	count3 = 0;
}
void check_2() {
	for (int i1 = 1; i1 <= 10; i1++) {
		for (int i2 = 1; i2 <= 10; i2++) {
			for (int i3 = 1; i3 <= 10; i3++) {
				for (int i4 = 1; i4 <= 10; i4++) {
					arr2[0]=i1;
					arr2[1]=i2;
					arr2[2]=i3;
					arr2[3] = i4;
					check_3();
				}
			}
		}
	}
}
void check_1() {
	for (int i1 = 1; i1 <= 10; i1++) {
		for (int i2 = 1; i2 <= 10; i2++) {
			for (int i3 = 1; i3 <= 10; i3++) {
				for (int i4 = 1; i4 <= 10; i4++) {
					arr1[0] = i1;
					arr1[1] = i2;
					arr1[2] = i3;
					arr1[3] = i4;
					check_2();
				}
			}
		}
	}
}

int main() {
	for (int i1 = 1; i1 <= 10; i1++) {
		for (int i2 = 1; i2 <= 10; i2++) {
			for (int i3 = 1; i3 <= 10; i3++) {
				for (int i4 = 1; i4 <= 10; i4++) {
					arr[0] = i1;
					arr[1] = i2;
					arr[2] = i3;
					arr[3] = i4;
					check_1();
					if (a == 'b' && b == 'c' && c == 'a') {
						cout << arr[0] << " " << arr[1] << " " << arr[2] << " " << arr[3]<<"\n";
						cout << arr1[0] << " " << arr1[1] << " " << arr1[2] << " " << arr1[3] << "\n";
						cout << arr2[0] << " " << arr2[1] << " " << arr2[2] << " " << arr2[3] << "\n";
					}
					else if (a == 'a' && b == 'b' && c == 'c') {
						cout << arr[0] << " " << arr[1] << " " << arr[2] << " " << arr[3] << "\n";
						cout << arr1[0] << " " << arr1[1] << " " << arr1[2] << " " << arr1[3] << "\n";
						cout << arr2[0] << " " << arr2[1] << " " << arr2[2] << " " << arr2[3] << "\n";
					}
				}
			}
		}
	}
	return 0;
}