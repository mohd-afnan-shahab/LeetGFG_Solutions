class Solution {
public:

    void dfs(int node, vector<vector<int>>& adjList, vector<int>& visited){
        visited[node] = 1;
        
        for(auto& it : adjList[node]){
            if(!visited[it]){
                dfs(it, adjList, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {

        int V = isConnected.size();

        vector<vector<int>> adjList(V);

        // convert adjMatrix (isConnected) to adjList
        for(int i = 0; i < V; i++){
            for(int j = 0; j < V; j++){
                if(isConnected[i][j] == 1 && i != j){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }

        vector<int> visited(V, 0);

        int cnt = 0;
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                cnt++;
                dfs(i, adjList, visited);
            }
        }

        return cnt;
    }
};