#include<stdio.h>
#define swap(x,y,z) ((z)=(x),(x)=(y),(y)=(z))
void sort(int arr[],int size) {
	int temp;
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1], temp);
		}
	}
}
int main()
{
	int nums[10010], quer, q, n, casen=0;
	while (scanf("%d %d", &n, &q) != EOF && n) {
		printf("CASE# %d:\n",++casen);
		for (int i = 0; i < n; i++)
			scanf("%d", &nums[i]);
		sort(nums,n);
		for (int i = 0; i < q; i++) {
			scanf("%d", &quer);
			int f = 1;
			for (int j = 0; j < n && quer >= nums[j]; j++) {
				if (quer == nums[j]) {
					printf("%d found at %d\n", quer, j + 1);
					f = 0;
					break;
				}
			}
			if (f) printf("%d not found\n", quer);
		}
	}
}