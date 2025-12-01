class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target){

        sort(nums.begin(), nums.end());
        int n = nums.size();

        int s = 0;
        int e = n-1;
        
        int ans = -1;
        while(s<=e){
            int mid = s + (e-s)/2;

            if(nums[mid]==target){
                ans = nums[mid];
                break;
            }
            else if(nums[mid] < target){
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
        }
        
        vector<int> res;
        for(int i=0; i<n; i++){
            if(nums[i]==ans){
                res.push_back(i);
            }
        }
        return res;
    }
};
