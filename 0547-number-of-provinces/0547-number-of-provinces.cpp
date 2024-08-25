class Solution {
public:

    void provinces_using_bfs(int vertex, vector<bool>& visited, vector<int> adjList[]){
        
        queue<int> q;
        
        visited[vertex] = 1;
        q.push(vertex);

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(int i = 0; i < adjList[node].size(); i++){

                int adjacencyNode = adjList[node][i];
                if(!visited[adjacencyNode]){
                    visited[adjacencyNode] = 1;
                    q.push(adjacencyNode);
                } 
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        // convert adjacency matrix to adjacency list
        int V = isConnected.size();
        vector<int> adjList[V];

        for(int i = 0; i < V; i++){
            for(int j = 0; j < V; j++){
                if(isConnected[i][j] == 1 && i != j){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }

        vector<bool> visited(V, 0);

        int count = 0;
        for(int i = 0; i < V; i++){
            if(visited[i] == 0){
                count++;
                provinces_using_bfs(i, visited, adjList);
            }
        }
        return count;
    }
};