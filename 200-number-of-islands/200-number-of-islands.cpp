class Solution {
public: 
    int numIslands(vector<vector<char>>& grid) {  
        int output = 0; 
        int m = grid.size();
        int n = grid[0].size();
        int dv[4][2] = {{1, 0},{-1, 0},{0, 1},{0, -1} };
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == '1'){
                    // run bfs
                    queue<pair<int, int>> q; 
                    pair<int,int> curr;
                    q.push({i,j});
                    while(!q.empty()){
                        int x = q.front().first;
                        int y = q.front().second;
                        grid[x][y] = '0';
                        for(int k = 0; k<4; k++){
                            if(x + dv[k][0] >= 0 && x + dv[k][0] < m 
                              && y + dv[k][1] >= 0 && y + dv[k][1] < n)
                            {
                                if(grid[x + dv[k][0]][y + dv[k][1]] == '1'){
                                    grid[x + dv[k][0]][y + dv[k][1]] = '0';
                                    q.push({x + dv[k][0], y + dv[k][1]});
                                }
                            }
                        }    
                        q.pop();
                    }
    
                    output++; 
                }
            } 
        }
        return output;
    }  
};