
#include <iostream>
#include <string>
#include <limits>
#include <climits>
#include <iomanip>

using namespace std;

constexpr long long MIN_INPUT = 0;
constexpr long long MAX_INPUT = LLONG_MAX;
constexpr long long TIER_PLATINUM = 1000000;
constexpr long long TIER_GOLD = 500000;
constexpr long long TIER_SILVER = 100000;
constexpr long long TIER_BRONZE = 50000;
constexpr double COMMISSION_RATE_PLATINUM = 0.01;
constexpr double COMMISSION_RATE_GOLD = 0.02;
constexpr double COMMISSION_RATE_SILVER = 0.03;
constexpr double COMMISSION_RATE_BRONZE = 0.05;

void printSeparator(char fillChar = '-', int length = 50) {

	cout << string(length, fillChar) << '\n';
}

void clearInputBuffer() {

	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

long long validateIntegerInRange(const string& prompt, long long minValue, long long maxValue) {

	long long number;

	while (true)
	{
		cout << prompt;

		if (!(cin >> number))
		{
			clearInputBuffer();

			cout << "Invalid input! Please enter a valid number.\n\n";
		}
		else if (number < minValue || number > maxValue)
		{
			clearInputBuffer();

			cout << "Invalid input! Number must be between " << minValue << " and " << maxValue << "\n\n";
		}
		else
		{
			clearInputBuffer();
			return number;
		}
	}
}

double calculateCommission(long long totalSales) {

	if (totalSales < 0) {
		return 0.0;
	}

	if (totalSales >= TIER_PLATINUM) {
		return totalSales * COMMISSION_RATE_PLATINUM;
	}
	else if (totalSales >= TIER_GOLD) {
		return totalSales * COMMISSION_RATE_GOLD;
	}
	else if (totalSales >= TIER_SILVER) {
		return totalSales * COMMISSION_RATE_SILVER;
	}
	else if (totalSales >= TIER_BRONZE) {
		return totalSales * COMMISSION_RATE_BRONZE;
	}
	else {
		return 0.0;
	}
}

int main()
{
	// Program to calculate sales commission based on total sales amount
	cout << "===== SALES COMMISSION CALCULATOR =====\n\n";

	long long totalSales = validateIntegerInRange("Enter total sales amount: ", MIN_INPUT, MAX_INPUT);

	printSeparator();

	cout << "Commission amount is : $" << fixed << setprecision(2) << calculateCommission(totalSales) << '\n';

	return 0;
}