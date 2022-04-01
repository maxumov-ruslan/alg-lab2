#include "dynamic_knapsack.hpp"
#include <iostream>
DynKnapsack::DynKnapsack(const std::vector<Item>& v,int w):Knapsack(v,w){
    max_price.resize(v.size()+1,std::vector(w+1,0.0));
    max_count.resize(v.size()+1,std::vector(w+1,std::vector(v.size(),0)));
}
void DynKnapsack::Add(int startIdx){
    for(int i = 0;i<=items.size();i++){
        for(int j =0;j<=W;j++){
            if(i == 0 || j == 0){
                max_price[i][j] = 0.0;
                continue;
            }
            const auto &it = items[i-1];
            if (j<it.weight){
                max_price[i][j] = max_price[i-1][j];
                max_count[i][j] = max_count[i-1][j];
                continue;
            }
            auto ap = max_price[i-1][j-it.weight]+it.price;
            auto bp = max_price[i-1][j];
            auto ac = max_count[i-1][j-it.weight];
            ac[i-1] = 1;
            auto &bc =  max_count[i-1][j];
            if (ap>bp){
                max_price[i][j] = ap;
                max_count[i][j] = ac;
            }else{
                max_price[i][j] = bp;
                max_count[i][j] = bc;
            }
        }
    }
    if(print_flag){
        for(int i=0;i<max_price.size();i++){
            for(int j=0;j<max_price[i].size();j++){
                std::cout << max_price[i][j] <<" ";
            }
             std::cout << std::endl;
        }
    }
    max_p = max_price.back().back();
    max_cnt = max_count.back().back();
    max_w = 0;
    for(int i=0;i<max_cnt.size();i++){
        max_w += max_cnt[i]*items[i].weight;
    }
}
void DynKnapsack::Print(){
    Knapsack::Print();
}
DynKnapsack DynKnapsack::readFile(const std::string &file_name){
    auto knap = Knapsack::readFile(file_name);
    return DynKnapsack(knap.items,knap.W);
}