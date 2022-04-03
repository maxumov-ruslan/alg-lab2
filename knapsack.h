#pragma once
#include <vector>
#include <string>
struct Item {
	std::string name;
	double price=0;
	int weight=0;
};
class Knapsack {
	protected:
	
	std::vector<int> max_cnt;
	double max_p = 0.0;
	int max_w = 0;
	std::vector<int> counts;
	
	int w_cur = 0;
	double p_cur = 0.0;


public:
	int W = 0;
	std::vector<Item> items;
	bool print_flag = false; 
	Knapsack(const std::vector<Item>& v,int w);
	static Knapsack readFile(const std::string& file_name);
	virtual void Add(int startIdx=0);
	virtual void Print();
	double getResult(std::vector<std::pair<int,Item>> &counts);
};
