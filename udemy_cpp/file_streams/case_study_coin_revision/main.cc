#include <iostream>
#include <vector>
#include "coin.h"

int check_input() {
	int input{0};
	do {
		std::cout << "Please enter the amount of change (between 1 and 499), or -1 to exit: ";
		std::cin >> input;
	} while (input < -1 || input == 0 || input > 499);
	return input;
}

std::vector<coin> populate_coins() {
	std::vector<coin> coins;
	coin dollar{ "dollar", "dollars", 100 };                 // Create dollar instance
	coins.push_back(dollar);                               // Append it to the vector
	coin half{ "half", "halves", 50 };
	coins.push_back(half);
	coin quarter{ "quarter", "quarters", 25 };
	coins.push_back(quarter);
	coin dime{ "dime", "dimes", 10 };
	coins.push_back(dime);
    coin nickel{ "nickel", "nickels", 5 };
	coins.push_back(nickel);
	coin penny{ "penny", "pennies", 1 };
	coins.push_back(penny);
	return coins;
}

int main() {
	std::vector<coin> coins;
	coins = populate_coins();
	 
	int input{0};
	while (input != -1) {
		input = check_input();

		int change{input};
		for (auto c : coins) {
			change = c.do_coin(change);
		}
	}
}