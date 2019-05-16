#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define swp(x,y,t) ((t)=(x),(x)=(y),(y)=(t))
void sort(int array[],int n,int f){
	int temp;
	for (int i = 0; i < n-1; i++) {
		for (int j = 1; j < n; j++) {
			if (f) {
				if (array[j] < array[j - 1])
					swp(array[j], array[j - 1], temp);
			}
			else {
				if (array[j] > array[j - 1])
					swp(array[j], array[j - 1], temp);
			}
		}
	}
}
int main()
{
	int n, d, r,morn[150],afternoon[150];
	while (scanf("%d %d %d", &n, &d, &r) != EOF && n) {
		getchar();
		for (int i = 0; i < n; i++)
			scanf("%d", &morn[i]);
		getchar();
		for (int i = 0; i < n; i++)
			scanf("%d", &afternoon[i]);
		getchar();
		sort(morn, n, 1);
		sort(afternoon, n, 0);
		int mini = 0;
		for (int i = 0; i < n; i++) {
			if (morn[i] + afternoon[i] > d)
				mini += (morn[i] + afternoon[i] - d)*r;
		}
		printf("%d\n", mini);
	}
}