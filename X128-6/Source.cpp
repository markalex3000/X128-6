// Guess user number between 1 and 100

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

inline void keep_window_open() { char ch; cin >> ch; }

inline void simple_error(string s)	// write ``error: s and exit program
{
	cerr << "error: " << s << '\n';
	keep_window_open();		// for some Windows environments
	exit(1);
}

int main() {
	bool found_it = false;
	char tester{ 0 };
	int digit{ -1 };
	string number{ "empty" };
	vector<string> number_strings = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

	while (true) {
		cout << "Enter a number string or digit: ";
		cin >> tester;
		found_it = false;
		if (cin.fail()) simple_error("Operation cin has failed in some fashion\n");
		else {
			if (tester >= '0' && tester <= '9') {
				cin.putback(tester);
				cin >> digit;
				if (digit >= 0 && digit <= 9) {
					cout << "The sting version is: " << number_strings[digit] << "\n";
					found_it = true;
					continue;
				}
				else {
					simple_error("That number is too big!");
				}
			}
			else cin.putback(tester);
		}
		cin >> number;
		for (int i = 0; i <= 9; i++) {
			if (number == number_strings[i]) {
				cout << "The string you entered ( " << number << " ) is " << i << "\n";;
				found_it = true;
				break;
			}
		}
		if (!found_it) {
			cout << "string: " << number << "\n";
			simple_error("\nThe string you entered is unrecognized! \n");
			}
	}
	keep_window_open();
}


