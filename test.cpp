#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "knapsack.h"
#include "dynamic_knapsack.hpp"
#include <vector>


TEST_CASE("Check vector elements", "[vector]") {
	std::vector<std::vector<int>> v;
	v.push_back({ 1,2,3 });
	v.push_back(v[0]);
	

	
	const std::vector<int> vec = { 1, 2, 3 };
	REQUIRE(v[1] == vec);

	//v[0][1] = 0;
	REQUIRE(v[0] == vec);


	REQUIRE(v.size() == 2);

	v.resize(3);
	v[2].resize(3);
	std::fill(v[2].begin(), v[2].end(), 7);

	const std::vector<int> vec2 = { 7, 7, 7 };
	REQUIRE(v[2] == vec2);
	
	REQUIRE(*std::find(v[1].cbegin(), v[1].cend(), 2) == 2);
	REQUIRE( std::find(v[1].cbegin(), v[1].cend(), 27) == v[1].cend());


}
TEST_CASE("Check brute force", "[knapsack]") {
	Knapsack k = Knapsack::readFile("input.txt");
	k.Add();
	std::vector<std::pair<int,Item>> items;
	auto max_price = k.getResult(items);
	int weight = 0;
	for(const auto& p : items){
		weight+= p.first*p.second.weight;
		assert(p.first>=0 && p.first<=1);
	}
	assert(max_price == 530);
	assert(weight<=20);
}
TEST_CASE("Check DP", "[knapsack]") {
	DynKnapsack k = DynKnapsack::readFile("input.txt");
	k.K = 5;
	k.Add();
	std::vector<std::pair<int,Item>> items;
	auto max_price = k.getResult(items);
	int weight = 0;
	for(const auto& p : items){
		weight+= p.first*p.second.weight;
		assert(p.first>=0 && p.first<=5);
	}
	assert(max_price == 1136);
	assert(weight<=20);
}
TEST_CASE("Check LazyDP", "[knapsack]") {
	DynKnapsack k = DynKnapsack::readFile("input.txt");
	k.K = 5;
	k.lazyAdd();
	std::vector<std::pair<int,Item>> items;
	auto max_price = k.getResult(items);
	int weight = 0;
	for(const auto& p : items){
		weight+= p.first*p.second.weight;
		assert(p.first>=0 && p.first<=5);
	}
	assert(max_price == 1136);
	assert(weight<=20);
}