class Solution {
public:
    int minOperations(vector<int>& nums, int k){

        int totXor = 0;

        for(int &num: nums){
            totXor = totXor^num;
        }

        int diff = totXor^k;
        return __builtin_popcount(diff);
    }
};
