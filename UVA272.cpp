#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	int count = 0;
	char in[200];
	while (gets_s(in, 200) != NULL) {
		for (int i = 0; i < strlen(in); i++) {
			if (in[i] == '"') {
				if (count % 2)
					printf("''");
				else
					printf("``");
				count++;
			}
			else
				printf("%c", in[i]);
		}
		printf("\n");
	}
}