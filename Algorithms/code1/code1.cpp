//
// Created by 李洪斌 on 2019-04-17.
//
#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        struct stInfo{
            int index;
            int value;
        };
        vector<int> returnVector;
        map<int,int> subMap;
        for(vector<int>::iterator iter = nums.begin();iter!= nums.end();++iter){

            int sub = target - *iter;
            if(subMap.end() != subMap.find(sub)){
                returnVector.push_back(subMap[sub]);
                returnVector.push_back(iter-nums.begin());
                return returnVector;
            }
            /*struct stInfo info;
            info.index = iter - nums.begin();
            info.value = *iter;*/
            subMap[*iter] = iter - nums.begin();
        }

        return returnVector;

    }
};

int main(){
    vector<int> inputVector{2,7,11,15};
    Solution solution;
    vector<int> resultVector = solution.twoSum(inputVector,9);
    for(auto result : resultVector){
        std::cout<<result<<std::endl;
    }
}


