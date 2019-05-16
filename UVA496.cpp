#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int div(char in[],int f);
int inan[99999], inbn[99999];
char ina[99999], inb[99999], *ptr;
int main()
{
	int lena, lenb,max,mini;
	char maxc, minic;
	while (gets_s(ina, 999) != NULL) {
		gets_s(inb, 999);
		lena = div(ina, 0);
		lenb = div(inb, 1);
		if (lena > lenb)
			max = lena, mini = lenb,maxc='A',minic='B';
		else if (lena < lenb)
			max = lenb, mini = lena, maxc = 'B', minic = 'A';
		else
			max = lena, mini = lena;
		int total = 0;
		for (int i = 0; i < lena; i++)
			for (int j = 0; j < lenb; j++)
				if (inan[i] == inbn[j])
					total++;
		if (max == total && mini == total)
			printf("A equals B\n");
		else if (total == 0)
			printf("A and B are disjoint\n");
		else if (mini > total)
			printf("I'm confused!\n");
		else
			printf("%c is a proper subset of %c\n", minic, maxc);
	}
}
int div(char in[],int f) {
	int count = 0;
	ptr = strtok(in, " ");
	while (ptr != NULL) {
		if (f)
			sscanf(ptr, "%d", &inbn[count]);
		else
			sscanf(ptr, "%d", &inan[count]);
		count++;
		ptr = strtok(NULL, " ");
	}
	return count;
}