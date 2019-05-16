#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	double v, v0;
	while (scanf("%lf %lf", &v, &v0) != EOF && v) {
		double longest = 0, n = 0, number, time=0, temp;
		while (v/(++n) > v0) {
			//printf("n = %.3lf\n", n);
			temp = sqrt(v / n - v0)*0.3*n;
			//printf("## %.3lf %lf %lf\n", n, temp, longest);
			if (temp == longest) { time++ ; continue; }
			if (temp > longest) { longest = temp, number = n, time = 0; }
		}
		//printf(" ## %.3lf\n", time);
		if (time == 0) printf("%.0lf\n", number);
		else printf("0\n");
	}
}