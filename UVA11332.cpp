#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int sum, temp;
	char in[20];
	while (scanf("%s", in) != EOF) {
		sum = 0;
		for (int i = 0; i < strlen(in); i++)
			sum += in[i] - '0';
		if (sum == 0)break;
		while (sum / 10) {
			temp = sum;
			sum = 0;
			while (temp) {
				sum += temp % 10;
				temp /= 10;
			}
		}
		printf("%d\n", sum);
	}
}