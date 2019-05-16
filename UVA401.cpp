#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int palj(char[]);
void change(char[]);
int main()
{
	char in[100],in1[100];
	while (gets_s(in,100) != NULL) {
		int pal = 0, mir = 0,p=strlen(in)-1,pm;
		pal = palj(in);
		strcpy(in1,in);
		change(in1);
		mir = palj(in1);
		pm = pal * 10 + mir;
		switch (pm)
		{
		case 00: printf("%s -- is not a palindrome.\n\n",in);
			break;
		case 10: printf("%s -- is a regular palindrome.\n\n", in);
			break;
		case 01: printf("%s  -- is a mirrored string.\n\n", in);
			break;
		case 11: printf("%s  -- is a mirrored palindrome.\n\n", in);
			break;
		}
	}
}
int palj(char test[]) {
	int h = strlen(test) - 1, low = 0,notpal=0;
	while (low < h) {
		if (test[h] != test[low]) {
			notpal = 1;
			break;
		}
		low++;
		h--;
	}
	if (notpal)
		return 0;
	else
		return 1;
}
void change(char test[]) {
	int i = 0,l=strlen(test)/2;
	while (i<l) {
		switch (test[i]) {
		case 'E': test[i] = '3';
			break;
		case 'J': test[i] = 'L';
			break;
		case 'L': test[i] = 'J';
			break;
		case 'S': test[i] = '2';
			break;
		case 'Z': test[i] = '5';
			break;
		case '2': test[i] = 'S';
			break;
		case '3': test[i] = 'E';
			break;
		case '5': test[i] = 'Z';
			break;
		}
		i++;
	}
}