#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	char in0[110], in1[110];
	while (gets_s(in0, 110) != NULL) {
		gets_s(in1, 110);
		int m = (strlen(in0) > strlen(in1)) ? strlen(in0) : strlen(in1);
		for (int i = 0; i < m; i++) {
			if (i<strlen(in1))
				printf("%c", in1[i]);
			if (i<strlen(in0))
				printf("%c", in0[i]);
			printf("\n");
		}
	}
}