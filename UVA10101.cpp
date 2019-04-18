#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
char ban[4][10] = { " shata", " hajar", " lakh", " kuti" };
int bann[] = { 100, 10, 100, 100 };
void print(long long a, int b) {
	if (a == 0) return;
	print(a / bann[b % 4], b + 1);
	if ((a % bann[b % 4]) != 0)
		cout << ' ' << a % bann[b % 4];
	if (b && ((a % bann[b % 4]) != 0 || b == 4))
		cout << ban[(b - 1) % 4];
}
int main() {
	long long s;
	int counter = 1;
	while (cin >> s) {
		printf("%4d.", counter++);
		if (s)
			print(s, 0);
		else
			cout << ' ' << 0;
		cout << endl;
	}
}