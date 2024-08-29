class Solution {
public:
    bool DFS(int node, int currcolor, vector<int>& color, vector<vector<int>>& graph){
        color[node] = currcolor;

        for(auto adjNode : graph[node]){
            if(color[adjNode] == -1){
                if(DFS(adjNode, !currcolor, color, graph) == false){
                    return false;
                }
            }
            if(color[adjNode] == currcolor){
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> color(V, -1);

        for(int i = 0; i < V; i++){
            if(color[i] == -1){
                if(DFS(i, 0, color, graph) == false){
                    return false;
                }
            }
        }
        return true;
    }
};