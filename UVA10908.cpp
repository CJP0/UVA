#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int dete(int post);
char in[110][110],center;
int r, c;
int main()
{
	int t,m,n,q;
	scanf("%d", &t);
	getchar();
	while (t--) {
		scanf("%d %d %d", &m, &n, &q);
		getchar();
		printf("%d %d %d\n", m, n, q);
		for (int i = 0; i < m;i++)
			gets_s(in[i]);
		while (q--) {
			scanf("%d %d", &r, &c);
			center = in[r][c];
			int p = 1, count = 1;
			while (dete(p)) {
				p++;
				count += 2;
			}
			printf("%d\n", count);
		}
	}
}
int dete(int post) {
	for (int i = r - post; i <= r + post; i++) {
		for (int j = c - post; j <= c + post; j++) {
			if (in[i][j] != center) {
				return 0;
			}
		}
	}
	return 1;
}