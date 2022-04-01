#include "knapsack.h"
#include <fstream>
#include <iostream>
#include <exception>


Knapsack::Knapsack(const std::vector<Item>& v, int w) {
	W = w;
	items = v;
	counts.resize(items.size(), 0);

}
Knapsack Knapsack::readFile(const std::string& name) {
	std::ifstream input(name);
	if (!input.is_open()) {
		std::cerr << "U Wot M8?\n";
		exit(EXIT_FAILURE);
	}
	int N,W;
	input >> N >> W;
	std::vector<Item> items(N);
	for (int i = 0; i < N; i++) {
		input >> items[i].name >> items[i].weight >> items[i].price;

	}
	return Knapsack(items, W);
}
void Knapsack::Print() {
	for (int i = 0; i < items.size(); i++) {
		int cnt = max_cnt[i];
		Item& item = items[i];
		if (cnt && print_flag) {
			std::cout << item.name << ' ';
		}
	}
	std::cout << max_w <<' ' << max_p << std::endl;

}
void Knapsack::Add(int idx) {
	if (idx == items.size()) {
		for (int i = 0; i < items.size(); i++) {
			int cnt = counts[i];
			Item &item = items[i];
			if (cnt&&print_flag) {
				std::cout << item.name <<' ';
			} 
		}
		if(print_flag)
				std::cout<<w_cur<<' '<<p_cur << '\n';
		if (p_cur > max_p) {
			max_p = p_cur;
			max_cnt = std::vector<int>(counts);
			max_w = w_cur;
		}
		return;
	}
	if (items[idx].weight + w_cur <= W) {
		w_cur += items[idx].weight;
		p_cur += items[idx].price;
		counts[idx]++;
		Add(idx + 1);
		counts[idx]--;
		p_cur -= items[idx].price;
		w_cur -= items[idx].weight;
	}
	Add(idx + 1);

}