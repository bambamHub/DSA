class Solution {
public:
    int longestBalanced(vector<int>& nums){

        int n = nums.size();

        int maxLen = 0;

        for(int i=0; i<n; i++){
            unordered_map<int, int> mp;
            int evenCnt = 0;
            int oddCnt = 0;
            for(int j=i; j<n; j++){
                if(mp.find(nums[j])==mp.end()){
                    if(nums[j]%2==0){
                        evenCnt++;
                    }
                    else{
                        oddCnt++;
                    }
                }
                mp[nums[j]]++;
                if(evenCnt==oddCnt){
                    maxLen = max(maxLen, j-i+1);
                }
            }
        }
        return maxLen;
    }
};
