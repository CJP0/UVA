#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
typedef struct {
	int x, y, degree;
}coordinate;
int main()
{
	int maxx, maxy,rf=0;
	coordinate current, recode[100];
	char direct,str[200];
	scanf("%d %d", &maxx, &maxy);
	while (scanf("%d %d %c", &current.x, &current.y, &direct) != EOF) {
		getchar();
		fgets(str, sizeof(str), stdin);
		switch (direct) {
		case 'N': current.degree = 90; break;
		case 'S': current.degree = 270; break;
		case 'E': current.degree = 0; break;
		default: current.degree = 180;
		}
		int f = 0, out = 0;
		do {
			if (str[f] == 'R') current.degree -= 90;
			else if (str[f] == 'L') current.degree += 90;
			else {
				int t = 1;
				for (int i = 0; i < rf; i++) {
					if (current.x == recode[i].x && current.y == recode[i].y && current.degree == recode[i].degree) 
						{ t = 0; break; }
				}
				if (t) {
					if (current.degree == 0 && (current.x + 1) <= maxx) current.x += 1;
					else if (current.degree == 90 && (current.y + 1) <= maxy) current.y += 1;
					else if (current.degree == 180 && (current.x - 1) >= 0) current.x -= 1;
					else if (current.degree == 270 && (current.y - 1) >= 0) current.y -= 1;
					else { out = 1; break; }
				}
			}
			if (current.degree < 0) current.degree += 360;
			if (current.degree >= 360) current.degree -= 360;
		}while (isupper(str[++f]));
		printf("%d %d ", current.x, current.y);
		switch (current.degree) {
		case 0: printf("E"); break;
		case 90: printf("N"); break;
		case 180: printf("W"); break;
		default: printf("S"); break;
		}
		if (out) { printf(" LOST"); recode[rf++] = current; }
		printf("\n");
	}
}