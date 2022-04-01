#include <iostream>
#include "knapsack.h"
#include "dynamic_knapsack.hpp"
#include <fstream>
using namespace std;

int main() {
	setlocale(LC_ALL, "ru_RU.UTF8");
	DynKnapsack k = DynKnapsack::readFile("input.txt");
	k.print_flag = true;
	k.Add();
	std::cout << "Best: ";
	k.Print();

	return 0;
}