#include <stdio.h>

#define MAX 1001
#define ASCII 128

int main()
{
	int i, j;
	char str1[MAX], str2[MAX];

	while (gets_s(str1) && gets_s(str2))
	{
		int table[ASCII] = { 0 }; /* To store the number of occurrence of every letter. */

		for (i = 0; str1[i]; i++)
			for (j = 0; str2[j]; j++)
				if (str1[i] == str2[j])
				{
					table[str2[j]]++;
					str2[j] = '0'; /* Avoid double counting.*/ /* mark */
					break;
				}
		for (i = 'A'; i <= 'z'; i++) /* Alphabetically output. */
			for (; table[i]; table[i]--) /* Print according to value. */
				printf("%c", i);
		printf("\n");
	}
	return 0;
}