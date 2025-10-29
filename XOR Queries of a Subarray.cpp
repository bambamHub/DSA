class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries){

        int n = arr.size();

        vector<int> prefArr(n);
        prefArr[0] = arr[0];


        for(int i=1; i<n; i++){
            prefArr[i] = prefArr[i-1]^arr[i];
        }
        
        vector<int> res;
        for(int i=0; i<queries.size(); i++){
            int start = queries[i][0];
            int end = queries[i][1];

            int xorVal = prefArr[end] ^ (start==0 ? 0 : prefArr[start-1]);
            res.push_back(xorVal);
        }
        return res;
    }
};
