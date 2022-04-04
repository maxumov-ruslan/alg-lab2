#pragma once
#include "knapsack.h"
class DynKnapsack:public Knapsack{
    std::vector<std::vector<double> > max_price;
    std::vector<std::vector<std::vector<int>>> max_count;
    void Ans(std::vector<int>& ans, int i, int j);
    double lazyAdd(int items,int weight,std::vector<int> &counts);
    void restoreAns(std::vector<int> &ans);
public:
    int K;
    DynKnapsack(const std::vector<Item>& v,int w,int k=1);
    static DynKnapsack readFile(const std::string& file_name);
    virtual void Add(int startIdx=0) override;
	virtual void Print() override;
    void lazyAdd();
    
};