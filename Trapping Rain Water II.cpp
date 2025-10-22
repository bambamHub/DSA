class Solution {
public:
    typedef pair<int, pair<int,int>> PP;
    int trapRainWater(vector<vector<int>>& heightMap) {

        int n = heightMap.size();
        int m = heightMap[0].size();

        priority_queue<PP, vector<PP>, greater<PP>> pq;

        vector<vector<int>> vis(n, vector<int>(m, false));

        for(int row=0; row<n; row++){
            for(int col : {0, m-1}){
                pq.push({heightMap[row][col], {row, col}});
                vis[row][col] = true;
            }
        }

        for(int col=0; col<m; col++){
            for(int row : {0, n-1}){
                pq.push({heightMap[row][col], {row, col}});
                vis[row][col] = true;
            }
        }

        int dr[] = {-1, 0, +1, 0};
        int dc[] = {0, +1, 0, -1};
        
        int water = 0;
        while(!pq.empty()){
            PP p = pq.top();
            pq.pop();
            int height = p.first;
            int row = p.second.first;
            int col = p.second.second;

            for(int i=0; i<4; i++){
                int newr = row + dr[i];
                int newc = col + dc[i];

                if(newr>=0 && newr<n && newc>=0 && newc<m && !vis[newr][newc]){

                    water += max(height - heightMap[newr][newc], 0);

                    pq.push({max(height, heightMap[newr][newc]), {newr, newc}});
                    vis[newr][newc] = true;
                }
            }
        }
        return water;
    }
};
