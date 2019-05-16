#include<stdio.h>

int main()
{
	int N1, N2;
	int dataset = 1;
	while (scanf("%d%d", &N1, &N2) != EOF && N1 != 0 && N2 != 0)
	{
		int stone1[105] = { 0 }, stone2[105] = { 0 };
		int i, j;
		for (i = 1; i <= N1; i++)
			scanf("%d", &stone1[i]);
		for (i = 1; i <= N2; i++)
			scanf("%d", &stone2[i]);

		int LCS[105][105] = { 0 };
		for (i = 1; i <= N1; i++)
			for (j = 1; j <= N2; j++)
				if (stone1[i] == stone2[j])
					LCS[i][j] = LCS[i - 1][j - 1] + 1;
				else
					LCS[i][j] = (LCS[i - 1][j] > LCS[i][j - 1]) ? LCS[i - 1][j] : LCS[i][j - 1];
		printf("Twin Towers #%d\n", dataset++);
		printf("Number of Tiles : %d\n\n", LCS[N1][N2]);
	}
	return 0;