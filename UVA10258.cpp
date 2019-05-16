
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define swap(x,y,z) ((z)=(x), (x)=(y), (y)=(z))
typedef struct contestant {
	int num, time, prob, record[10];
}contestant;
void sort(contestant in[], int len) {
	contestant temp;
	for (int i = 0; i<len - 1; i++) {
		for (int j = 0; j<len - 1 - i; j++) {
			if (in[j].prob<in[j + 1].prob) swap(in[j], in[j + 1], temp);
			else if (in[j].prob == in[j + 1].prob && in[j].time>in[j + 1].time) swap(in[j], in[j + 1], temp);
			else if (in[j].prob == in[j + 1].prob && in[j].time == in[j + 1].time && in[j].num>in[j + 1].num) swap(in[j], in[j + 1], temp);
		}
	}
}
int main() {
	int n, c[100] = { -1 }, time, num, prob, temp;
	char buffer[20], q;
	contestant list[100];
	scanf("%d", &n);
	getchar();
	getchar();

	while (n--) {
		int f = 0;
		for (int i = 0; i<100; i++) {
			list[i].time = 0;
			list[i].prob = 0;
			c[i] = -1;
			for (int j = 0; j<10; j++) list[i].record[j] = 0;
		}
		int count = 0;
		while (1) {
			count++;
			fgets(buffer, sizeof(buffer), stdin);
			if (buffer[0] == '\n' || strlen(buffer)<3 || count>10) break;
			sscanf(buffer, "%d %d %d %c", &num, &prob, &time, &q);
			//printf("=======%d %d %d %c\n",num,prob,time,q);
			if (c[num] == -1) { c[num] = f; list[f].num = num; f++; }
			temp = c[num];
			if (q == 'C') {
				list[temp].prob++;
				list[temp].time += time + (list[temp].record[prob] * 20);
			}
			else if (q == 'I') list[temp].record[prob]++;
			for (int i = 0; i<20; i++) buffer[i] = '\0';
		}
		sort(list, f);
		for (int i = 0; i<f; i++)
			printf("%d %d %d\n", list[i].num, list[i].prob, list[i].time);
		if (n) puts("");
	}
}
