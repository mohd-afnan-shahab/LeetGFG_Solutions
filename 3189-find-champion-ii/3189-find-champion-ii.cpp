class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n, 0);

        for(vector<int>& edge : edges){
            int u = edge[0];
            int v = edge[1];

            indegree[v]++;
        }

        int champion = -1, cnt = 0;
        for(int i = 0; i < n; i++){                 // iterating in indegree
            if(indegree[i] == 0){
                champion = i;
                cnt++;

                if(cnt > 1){
                    return -1;
                }
            }
        }

        return champion;
    }
};