#include<iostream>
#include<cstring>
using namespace std;
int main() {
	int caseN, day, p, temp, temp2, count;
	bool record[4000] = { 0 };
	cin >> caseN;
	while (caseN--) {
		count = 0;
		cin >> day >> p;
		while (p--) {
			cin >> temp;
			temp2 = temp;
			while (temp <= day) {
				if (!record[temp] && (temp % 7) && (temp % 7) != 6) {
					count++;
					record[temp] = 1;
				}
				temp += temp2;
			}
		}
		cout << count << endl;
		memset(record, 0, sizeof(record));
	}
}