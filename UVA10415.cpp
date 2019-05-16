#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int n, finger[14][10] = { { 0,1,1,1,0,0,1,1,1,1 },{ 0,1,1,1,0,0,1,1,1,0 },{ 0,1,1,1,0,0,1,1,0,0 },{ 0,1,1,1,0,0,1,0,0,0 },{ 0,1,1,1,0,0,0,0,0,0 },{ 0,1,1,0,0,0,0,0,0,0 },{ 0,1,0,0,0,0,0,0,0,0 },{ 0,0,1,0,0,0,0,0,0,0 },{ 1,1,1,1,0,0,1,1,1,0 },{ 1,1,1,1,0,0,1,1,0,0 },{ 1,1,1,1,0,0,1,0,0,0 },{ 1,1,1,1,0,0,0,0,0,0 },{ 1,1,1,0,0,0,0,0,0,0 },{ 1,1,0,0,0,0,0,0,0,0 } };
	char octave[] = { 'c','d','e','f','g','a','b','C','D','E','F','G','A','B' };
	scanf("%d", &n);
	getchar();
	while (n--) {
		int count[10][2] = { 0 };
		char in[2000];
		gets_s(in);
		for (int i = 0; i < strlen(in); i++) {
			for (int j = 0; j < 14; j++) {
				if (in[i] == octave[j]) {
					for (int z = 0; z<10; z++) {
						if (finger[j][z]) {
							if (count[z][1] == 0) {
								count[z][1] = 1;
								count[z][0]++;
							}
						}
						else {
							if (count[z][1])
								count[z][1] = 0;
						}
					}
					break;
				}
			}
		}
		for (int i = 0; i < 9; i++)
			printf("%d ", count[i][0]);
		printf("%d\n", count[9][0]);
	}
}