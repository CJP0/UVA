#include<stdio.h>
int main()
{
	int n;
	while (scanf("%d", &n) != EOF && n) {
		int deck[1000] = { 0 };
		for (int i = 0; i <= n; i++)
			deck[i] = i;
		printf("Discarded cards:");
		int f = 0;
		for (int i = 1; deck[i + 2]; i += 2) {
			if (f) printf(", %d", deck[i]);
			else {
				printf(" %d", deck[i]); f = 1;
			}
			if (deck[i + 1]) deck[++n] = deck[i + 1];
		}
		if (f) printf(",");
		if(deck[n-1]) printf(" %d", deck[n - 1]);
		printf("\nRemaining card: %d\n", deck[n]);
	}
}