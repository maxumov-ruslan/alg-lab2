#include <iostream>
#include "knapsack.h"
#include "dynamic_knapsack.hpp"
#include <fstream>
#include <ctime>
using namespace std;

int main() {
	setlocale(LC_ALL, "ru_RU");
	auto k = Knapsack::readFile("input.txt");
	k.print_flag = true;
	//k.Add();
	//std::cout << "Best: ";
	//k.Print();
	auto start_dk = std::clock();
	auto dk = DynKnapsack::readFile("input.txt");
	dk.K=5;
	dk.print_flag = true;
	//for (int i = 0; i < 1000; i++) {
		//dk = DynKnapsack::readFile("input.txt");
		dk.K = 5;
		dk.Add();
	//}
	auto stop_dk = std::clock();
	std::cout << "Best: ";
	dk.Print();
	std::cout <<"Time: "<< (stop_dk-start_dk)/(double)(CLOCKS_PER_SEC/1000) <<" ms"<<std::endl;
	auto start_lk = std::clock();
	auto lk = DynKnapsack::readFile("input.txt");
	lk.K=5;
	for (int i = 0; i < 1000; i++) {
		lk = DynKnapsack::readFile("input.txt");
		lk.K = 5;
		lk.lazyAdd();
	}
	auto stop_lk = std::clock();
	std::cout << "Best: ";
	lk.Print();
	std::cout <<"Time: "<< (stop_lk-start_lk)/(double)(CLOCKS_PER_SEC/1000) <<" ms"<<std::endl;

	
	return 0;
}