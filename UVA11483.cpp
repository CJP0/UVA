#include<iostream>
#include<string>
using namespace std;
string format(string & str) {
	int n = str.size();
	string temp = "";
	for (int i = 0; i < n; ++i) {
		switch (str[i]) {
			case '\\':
			case '\'':
			case '"':
				temp+='\\';
		}
		temp += str[i];
	}
	return temp;
}
int main() {
	int n, counter = 0;
	string buffer;
	while (cin >> n) {
		if (n == 0) break;
		cin.ignore(100, '\n');
		cout << "Case " << ++counter << ':' << endl;
		cout << "#include<string.h>\n#include<stdio.h>\nint main()\n{\n";
		while (n--) {
			getline(cin, buffer);
			cout << "printf(\"" << format(buffer) << "\\n\");" << endl;
		}
		cout << "printf(\"\\n\");\nreturn 0;\n}\n";
	}
}