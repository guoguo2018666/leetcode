#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int max = 0;
        if(s.empty()){
            return 0;
        }

        for(string::iterator iter = s.begin();iter!= s.end();++iter){
            int maxTemp = 0;
            unordered_set<char> unorderedSet;
            for(string::iterator iterBegin = s.begin()+(iter - s.begin());iterBegin != s.end();++iterBegin){

                if( unorderedSet.find(*iterBegin) != unorderedSet.end()){
                    break;
                }else{
                    ++maxTemp;
                    unorderedSet.insert(*iterBegin);
                }
            }
            if(maxTemp > max){
                max = maxTemp;
            }

        }

        return max;
    }
};

int main(){
    string str1{"abcabcbb"};
    string str2{"pwwkew"};
    string str3{"bbbbb"};
    string str4{" "};
    Solution solution;
    int sum = solution.lengthOfLongestSubstring(str4);
    std::cout<<sum<<std::endl;
}

