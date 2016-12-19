// input a single digit or a number word and output the other

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
	string s_buffer{};
	vector<string> number_strings = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

	while (true) {
		cout << "Enter a number string or digit: ";
		found_it = false;

		cin >> s_buffer;

		// test length of s_buffer.  if 1 might have a single digit, else might have a valid number string

		if (s_buffer.length() == 1) {   // check to see if a valid digit
			if (s_buffer[0] >= '0' && s_buffer[0] <= '9') {
				cout << "The sting version is: " << number_strings[s_buffer[0] - 48] << "\n";
				found_it = true;
				continue;
			}
			else { //we have a bad digit - that is not a number
				cout << "\" " << s_buffer << " \" is not an acceptable digit! \n\n";
				found_it = false;
				continue;
			}
		}
		else { // we might have a valid number string
			for (int i = 0; i <= 9; i++) {
				if (s_buffer == number_strings[i]) {  // we have a match
					cout << "The string you entered ( " << s_buffer << " ) is " << i << "\n";;
					found_it = true;
					break;
				}
			}
			if (!found_it) {  // we checked and we don't have a match
				cout << "string: " << s_buffer << " - ";
				simple_error("\nThe string you entered is unrecognized! \n\n");
			}
		}
	}
	keep_window_open();
}


