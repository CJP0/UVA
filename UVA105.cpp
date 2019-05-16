#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int in[3], len = 0, graph[20000] = { 0 },c=0;
	char s[100],*ptr;
	while (1) {
		gets_s(s);
		if (strlen(s) == 0)
			break;
		int p = 0;
		ptr = strtok(s, " ");
		while (ptr != NULL) {
			sscanf(ptr, "%d", &in[p]);
			p ++ ;
			ptr = strtok(NULL, " ");
		}
		if (in[2] > len)
			len = in[2];
		for (int i = in[0]; i < in[2]; i++)
			if (in[1] > graph[i])
				graph[i] = in[1];
		if (c < 50000)
			c++;
		else
			break;
	}
	int n = graph[1]+1,f=0;
	for (int i = 1; i <= len; i++) {
		if (n != graph[i]) {
			f ? printf(" ") : f = 1;
			printf("%d %d", i, graph[i]);
			n = graph[i];
		}
	}
	printf("\n");
	system("PAUSE");
}