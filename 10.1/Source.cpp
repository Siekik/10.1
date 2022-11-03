#include <iostream>
#include <string>
using namespace std;

bool isCardValid(int digits[], int size);
int stringtonumb(string indi);
int main() {
	int again = 1;
	int size = 16;
	string number;
	while (again == 1) {
		cout << "Enter 16-digit credit card # or Q to quit: ";
		
		int digits[16];
		
		cin >> number;

		if (number == "q" || number == "Q") {
			return 1;
		}
		else {
				for (int i = 0; i <= 15; i++) {
					string indi = number.substr(i);
					digits[i] = stringtonumb(indi);
				}

				isCardValid(digits, size);
				if (isCardValid(digits, size) == true) {
					cout << "Card is valid.\n";
				}
				else if (isCardValid(digits, size) == false) {
					cout << "Card is not valid\n";
				}
			}
	}
}
int stringtonumb(string indi) {
	if (indi == "0")return 0;
	else if (indi == "1")return 1;
	else if (indi == "2")return 2;
	else if (indi == "3")return 3;
	else if (indi == "4")return 4;
	else if (indi == "5")return 5;
	else if (indi == "6") return 6;
	else if (indi == "7") return 7;
	else if (indi == "8")return 8;
	else return 9;
}
bool isCardValid(int digits[], int size) {
	int group_b = 0;
	int group_a = 0;

	for (int i = 1; i <= 16; i = i + 2) {
		group_b = group_b + digits[i];
	}
	for (int i = 16; i >= 1; i = i - 2) {
		group_a = group_a + ((digits[i] * 2) / 10) + ((digits[i] * 2) % 10);
	}
	
	int total = group_a + group_b;
	if (total % 10 == 0) {
		return true;
	}
	else return false;
	}