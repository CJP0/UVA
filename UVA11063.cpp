#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int n, nums[200],count=0;
	while (scanf("%d", &n) != EOF) {
		count++;
		int record[10050] = { 0 },f=0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &nums[i]);
			if (i > 0 && nums[i] <= nums[i - 1]) f++;
			for (int j = 0; j <= i; j++) {
				if (record[nums[i] + nums[j]]) f++;
				else record[nums[i] + nums[j]]++;
			}	
		}
		if (f) printf("Case #%d: It is not a B2-Sequence.\n\n", count);
		else printf("Case #%d: It is a B2-Sequence.\n\n", count);
	}
}