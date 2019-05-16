#include<stdio.h>
int main()
{
	int s, n, m, temp;
	while (scanf("%d", &s) != EOF) {
		while (s--) {
			scanf("%d %d", &n, &m);
			temp = 0;
			while (n > m) {
				temp += n / m;
				n = (n / m) + (n%m);
			}
			if (n == m) printf("%d\n", temp+1);
			else printf("cannot do this\n");
		}
	}
}