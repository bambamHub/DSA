class Solution {
public:
    long long countBadPairs(vector<int>& nums) {

        int n = nums.size();

        for(int i=0; i<n; i++){
            nums[i] = nums[i]-i;
        }

        unordered_map<int,int> mp;
        mp[nums[0]] = 1;

        long long result = 0;
        for(int j=1; j<n; j++){
            int countOfNumsj = mp[nums[j]];
            int totNumsBefj = j;

            int badPairs = totNumsBefj - countOfNumsj;
            result += badPairs;
            mp[nums[j]]++;
        }
        return result;
    }
};
