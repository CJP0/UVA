#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int prime(int a);
int main()
{
	int in,next,last;
	while (scanf("%d", &in) != EOF && in) {
		if (prime(in)) {
			printf("0\n");
		}
		else {
			int n = 2;
			while (n--){
				for (int i = in; 1; ) {
					if (n) {
						i--;
						if (prime(i)) {
							last = i;
							break;
						}
					}
					else {
						i++;
						if (prime(i)) {
							next = i;
							break;
						}
					}
				}
			}
			printf("%d\n", next - last);
		}
	}
}
int prime(int a) {
	int r = 1;
	for (int i = 2; i < a; i++) {
		if ((a%i)==0) {
			r = 0;
			break;
		}
	}
	return r;
}