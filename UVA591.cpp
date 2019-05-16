#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int n, inarray[999], count = 1;
	while (scanf("%d", &n) != EOF && n) {
		int sun = 0, average, mov = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &inarray[i]);
			sun += inarray[i];
		}
		for (int i = 0; i < n; i++) {
			if (inarray[i] >(sun / n))
				mov += inarray[i] - (sun / n);
		}
		printf("Set #%d\n", count);
		printf("The minimum number of moves is %d.\n\n", mov);
		count++;
	}
}