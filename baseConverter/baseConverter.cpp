/*
Program Name: baseConverter.cpp
Description: This program uses a file ("numbers.txt") to read in a number
followed by the base to convert that number into. This program is solved recursively
within the ChangeBase function. This function assumes that the input base will not excede 16
or be less than 2.
Author: Alex Frazier
Due Date: 2/4/14
*/
#include <iostream>
#include <fstream>
#include <string_view>

/*
The function DisplayDigit displays each digit individually and was written to
eliminate redundant code. It takes into account digits that are greater than ten for
bases 11 - 16.
*/
void DisplayDigit(int dec_num, int base) {
	using namespace std::literals;
	// Output the appropriate letter character if the number is two digits
	static constexpr auto digits = "0123456789ABCDEF"sv;
	std::cout << digits.at(dec_num % base);
}

/*
ChangeBase is responsible for finding each character in the new base, and calls
DisplayDigit to output the next digit.
*/
void ChangeBase(int dec_num, int base) {
	//Anchor point
	//Recursion
	if (dec_num < base) {
		DisplayDigit(dec_num, base);
	} else {
		// Call the function again looking for dec_num / base (integer division)
		ChangeBase(dec_num / base, base);
		DisplayDigit(dec_num, base);
	}
}

void main() {
	std::ifstream fin{ "numbers.txt" };

	int decimal_number, base;

	// Read first number and base
	fin >> decimal_number >> base;

	// Continue looping until a negative number is read into decimal_number
	while (decimal_number > 0) {
		// Prevent overflow
		if (decimal_number > 1'000'000'000) {
			std::cout << "Decimal number is too large for this program ....\n";
		} else {
			std::cout << decimal_number << " in base " << base << " is ";

			// Begin Process to find the equivalent number in the new base
			ChangeBase(decimal_number, base);

			std::cout << '\n';
		}

		// Read next number and base
		fin >> decimal_number >> base;
	}
}