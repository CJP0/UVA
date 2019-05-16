#include<stdio.h>
#include<stdlib.h>
#include<string.h>
double mul(int* nums, int star, int end) {
	double a = 1;
	for (int i = star; i < end; i++) {
		a *= nums[i];
	}
	return a;
}
double maxProduct(int* nums, int numsSize) {
	double max = nums[0];
	for (int i = 0; i<numsSize; i++) {
		for (int j = 0; numsSize - j > i; j++) {
			double temp = mul(nums, i, numsSize - j);
			if (max < temp) max = temp;
		}
	}
	return max;
}
int main()
{
	int n,count=0;
	int* nums = (int*)malloc(sizeof(int) * 30);
	while (scanf("%d", &n) != EOF) {
		count++;
		for (int i = 0; i < n; i++)
			scanf("%d", &nums[i]);
		double m = maxProduct(nums, n);
		printf("Case #%d: The maximum product is %.0lf.\n\n", count, m < 0 ? 0 : m);
	}
}