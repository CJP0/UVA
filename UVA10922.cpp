#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int dete(int subsum, int counter);
int main()
{
	char in[2000];
	while (gets_s(in) != NULL) {
		int sum = 0;
		for (int i=0; i < strlen(in); i++)
			sum += in[i] - '0';
		if (sum == 0)
			break;
		if (dete(sum, 0))
			printf("%s is a multiple of 9 and has 9-degree %d.\n", in, dete(sum, 0));
		else
			printf("%s is not a multiple of 9.\n", in);
	}
}
int dete(int subsum, int counter) {
	counter ++ ;
	if (subsum > 9) {
		int sum = 0;
		do {
			sum += subsum % 10;
			subsum /= 10;
		} while (subsum);
		return dete(sum, counter);
	}
	else if (subsum == 9)
		return counter;
	else
		return 0;
}