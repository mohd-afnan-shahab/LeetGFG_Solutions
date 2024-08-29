class Solution {
public:
    bool check(int start, vector<vector<int>>& graph, vector<int>& color){

        int V = graph.size();
        queue<int> q;
        q.push(start);

        // initially give color 1 to node 0
        color[start] = 1;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(const auto& adjNode : graph[node]){
                // if adj Node is not coloured
                if(color[adjNode] == -1){
                    color[adjNode] = !color[node];      // Assign the opp color
                    q.push(adjNode);
                }

                // if adjNode color comes out to be same of node color
                if(color[adjNode] == color[node]){
                    return false;
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();

        // track the color of every node (-1 means no color)
        vector<int> color(V, -1);

        for(int i = 0; i < V; i++){
            if(color[i] == -1){
                if(check(i, graph, color) == false){
                    return false;
                }
            }
        }
        return true;
    }
};