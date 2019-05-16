#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define swap(x,y,z)((z)=(x),(x)=(y),(y)=(z))
int sort(char arr[], int len) {
	char temp;
	for (int i = 00; i < len - 1; i++) {
		for (int j = 0; j < len - i - 1; j++) {
			if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1], temp);
		}
	}
	/*for (int i = 0; i < len; i++)
		printf("%c ,", arr[i]);
	printf("#%d\n",len);*/
	for (int i = 0; i < len; i++) {
		if (arr[i] == arr[i + 1]) {
			for (int j = i+1; j < len - 1; j++)
				arr[j] = arr[j + 1];
			len--;
			i--;
		}
	}
	//printf("##%d\n", len);
	return len;
}
int main()
{
	char in1[1500], in2[1500],same[1500];
	while (gets_s(in1) != NULL) {
		gets_s(in2);
		int f = 0;
		for (int i = 0; i < strlen(in1); i++) {
			if (in1[i] == ' ') continue;
			for (int j = 0; j < strlen(in2); j++) {
				if (in1[i] == in2[j]) {
					same[f] = in1[i];
					f++;
				}
			}
		}
		f=sort(same, f);
		for (int i = 0; i < f + 1; i++) {
			int time,count1=0,count2=0;
			for (int j = 0; j < strlen(in1); j++)
				if (same[i] == in1[j]) count1++;
			for (int j = 0; j < strlen(in2); j++)
				if (same[i] == in2[j]) count2++;
			time = count1 < count2 ? count1 : count2;
			for(int j=0;j<time;j++)
				printf("%c", same[i]);
		}
		printf("\n");
	}
}