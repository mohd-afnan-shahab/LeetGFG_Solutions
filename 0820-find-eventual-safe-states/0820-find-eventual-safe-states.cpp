class Solution {
public:
    bool dfsCheck(int node, vector<bool>& path, vector<bool>& visited, vector<bool>& check, vector<vector<int>>& graph){

        visited[node] = 1;
        path[node] = 1;
        check[node] = 0;

        // check for adjacent nodes
        for(const auto& adjNode : graph[node]){
            // if adjNode is already in path
            if(path[adjNode]){
                check[node] = 0;
                return true;
            }

            // if adjNode is already visited the continue
            if(visited[adjNode]){
                continue;
            }

            // traverse further adjNode
            if(dfsCheck(adjNode, path, visited, check, graph) == true){
                check[node] = 0;
                return true;
            }
        }
        check[node] = 1;
        path[node] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();

        vector<bool> path(V, 0);
        vector<bool> visited(V, 0);
        vector<bool> check(V, 0);

        vector<int> safeNodes;

        for(int i = 0; i < V; i++){
            if(!visited[i]){
                dfsCheck(i, path, visited, check, graph);
            }
        }

        for(int i = 0; i < V; i++){
            if(check[i] == 1){
                safeNodes.push_back(i);
            }
        }
        return safeNodes;
    }
};