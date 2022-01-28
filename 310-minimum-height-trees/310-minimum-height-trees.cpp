class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        // Topology Sort
        
        // Corner Case
        if(n == 1) return {0};
        if(n == 2) return {0,1};
        
        vector<vector<int>> graph(n, vector<int>());
        vector<int> linkCt(n, 0);
        for(vector<int> &link : edges){
            graph[link[0]].push_back(link[1]);
            graph[link[1]].push_back(link[0]);
            // no repeated edges
            linkCt[link[0]]++;
            linkCt[link[1]]++;
        }
        queue<int> q; // queue of leaf nodes, (link = 1)
        for(int i = 0 ; i < n ; i++){
            if(linkCt[i] == 1){
                q.push(i);
            }
        }
        
        int count = 0;
        while(!q.empty()){
            // layer by layer
            int len = q.size();
            
            while(len > 0){
                int temp = q.front();
                q.pop();
                // remove this node
                linkCt[temp]--;
                for(int elem:graph[temp]){
                    linkCt[elem]--;
                    if(linkCt[elem] == 1){
                        q.push(elem);
                    }
                }
                graph[temp].clear();
                count++;
                len--;
            }
        
            if(count == n-1 || count == n-2) break;
        }

        vector<int> output;
        while(!q.empty()){
            output.push_back(q.front());
            q.pop();
        }

        return output;
     }
};