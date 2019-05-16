#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int combin[3], init;
	while (scanf("%d %d %d %d", &init, &combin[0], &combin[1], &combin[2]) != EOF) {
		if (init + combin[0] + combin[1] + combin[2] == 0) break;
		int counter = 120;
		if (init < combin[0]) counter += init + 40 - combin[0];
		else counter += init - combin[0];
		init = combin[0];
		//printf("1 %d\n", counter);
		if (init > combin[1]) counter += 40 - init + combin[1];
		else counter += combin[1] - init;
		init = combin[1];
		//printf("2 %d\n", counter);
		if (init < combin[2]) counter += init + 40 - combin[2];
		else counter += init - combin[2];
		//printf("3 %d\n", counter);
		printf("%d\n", counter * 9);
	}
}