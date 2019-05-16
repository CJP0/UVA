#include<stdio.h>
#include<stdlib.h>
int *r = (int*)malloc(sizeof(int) * 2);
int *remain(int in,int borrow) {
	int count = in;
	count += in / 3;
	in = in / 3 + in % 3 + borrow;
	while (in / 3) {
		count += in / 3;
		in = in / 3 + in % 3;
	}
	r[0] = in, r[1] = count;
	return r;
}
int main()
{
	int borrow, in, count;
	int *temp;
	while (scanf("%d", &in) != EOF) {
		temp = remain(in,0);
		if (temp[0]) borrow = 3 - temp[0];
		else { printf("%d\n", temp[1]); continue; }
		temp = remain(in, borrow);
		if (temp[0] != borrow) {
			temp = remain(in, 0);
			printf("%d\n", temp[1]);
		}
		else printf("%d\n", temp[1]);
	}
}