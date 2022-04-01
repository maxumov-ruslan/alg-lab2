#pragma once
#include "knapsack.h"
class DynKnapsack:public Knapsack{
    std::vector<std::vector<double> > max_price;
    std::vector<std::vector<std::vector<int>>> max_count;
    public:
    DynKnapsack(const std::vector<Item>& v,int w);
    static DynKnapsack readFile(const std::string& file_name);
    virtual void Add(int startIdx=0) override;
	virtual void Print() override;
};