#include "dynamic_knapsack.hpp"
#include <iostream>
DynKnapsack::DynKnapsack(const std::vector<Item>& v,int w,int k):Knapsack(v,w){
    max_price.resize(v.size()+1,std::vector<double>(w+1,-1.0));
    max_count.resize(v.size()+1,std::vector<std::vector<int>>(w+1,std::vector<int>(v.size(),0)));
    K = k;
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
            double maxp = max_price[i-1][j];
            std::vector<int> maxc = max_count[i-1][j];
            for(int k = 1;k<=std::min(K,j/it.weight);k++){
                auto new_price = max_price[i-1][j-it.weight*k]+it.price*k;
                //std::cout << new_price<<std::endl;
                if(new_price>maxp){
                    maxp = new_price;
                    maxc = max_count[i-1][j-it.weight*k];
                    maxc[i-1] = k;
                }
            }
            max_price[i][j] = maxp;
            max_count[i][j] = maxc;
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
    restoreAns(max_cnt);
    max_p = 0;
    max_w = 0;
    for(int i=0;i<max_cnt.size();i++){
        max_w += max_cnt[i] * items[i].weight;
        max_p += max_cnt[i] * items[i].price;

    }
}
void DynKnapsack::Print(){
    Knapsack::Print();
}
DynKnapsack DynKnapsack::readFile(const std::string &file_name){
    auto knap = Knapsack::readFile(file_name);
    return DynKnapsack(knap.items,knap.W,1);
}
void DynKnapsack::lazyAdd (){
    std::vector<int> cnt(max_cnt.size(),0);
    double price = lazyAdd(items.size(),W,cnt);
    max_p = price;
    max_cnt = cnt;
    max_w = 0;
    for(int i=0;i<max_cnt.size();i++){
        max_w += max_cnt[i]*items[i].weight;
    }
    if(print_flag){
        for(int i=0;i<max_price.size();i++){
            for(int j=0;j<max_price[i].size();j++){
                std::cout << max_price[i][j] <<" ";
            }
             std::cout << std::endl;
        }
    }
    return;
}

double DynKnapsack::lazyAdd (int itemcount,int weight,std::vector<int> &counts){

    if(itemcount <= 0 || weight <= 0){
        counts = std::vector<int>(items.size(),0);
        return 0.0;
    }
    if(max_price[itemcount][weight]>=0){
        counts = max_count[itemcount][weight];
        return max_price[itemcount][weight];
    }
    auto tcount = counts;
    double tp = lazyAdd(itemcount-1,weight,tcount);
    double p = tp;
    Item &it = items[itemcount-1];
    auto bcount=counts;
    for(int k=1;k<=std::min(K,weight/it.weight);k++){
        
        auto next_price = lazyAdd(itemcount-1,weight - it.weight*k,bcount)+it.price*k;
        bcount[itemcount-1]= k;
        if(next_price > p){
            p = next_price;
            counts = bcount; 

            //std::cout << k << ':'<<p<<std::endl;

        }
    }
    if(p==tp){
        counts = tcount;
    }
    
    
    //std::cout<<std::endl;
    max_count[itemcount][weight] = counts;
    max_price[itemcount][weight] = p;
    return p;
}
void DynKnapsack::Ans(std::vector<int> &ans,int i, int j) {
    if (max_price[i+1][j] <= 0.0)
        return;
    if (max_price[i+1][j] == max_price[i][j]) {
        Ans(ans, i-1, j);
        ans[i] = 0;
    }else {
        int k = (max_price[i+1][j] - max_price[i][j]) / items[i].price;
        ans[i] = k;
        Ans(ans, i - 1, j - items[i].weight*k);
        
    }
}
void DynKnapsack::restoreAns(std::vector<int> &ans)
{
    ans.clear();
    ans.resize(items.size(), 0);
    Ans(ans, items.size()-1, W);
    
}
