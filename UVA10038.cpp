#include <iostream>
#include<sstream>
#include<vector>
#include<string>
#include<cstdlib>
using namespace std;
bool lookup(vector <bool> & table, int val) {
	if (val == 0 || (val > int(table.size())) || table[val-1]) return true;
	table[val - 1] = true;
	return false;
}
int main() {
	string str, buffer;
	int n, nu1, nu2;
	bool f;
	vector <bool> record;
	while (cin) {
		f = 0;
		getline(cin, buffer);
		if (buffer.size() == 0) break;
		istringstream iss(buffer);
		iss >> n >> nu1;
		record.assign(n-1, false);
		while (iss) {
			iss >> nu2;
			if (iss.fail()) break;
			if (lookup(record, abs(nu1 - nu2))) {
				f = 1;
				break;
			}
			nu1 = nu2;
		}
		if (f)
			cout << "Not jolly\n";
		else
			cout << "Jolly\n";
	}
}