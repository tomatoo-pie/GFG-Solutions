class Solution {
  public:

      bool dfs(int i, int parent, vector<vector<int>>& adjList, vector<int>& States) {
          States[i] = 1;
          
          for(auto it : adjList[i]){
              if(States[it] == 0){
                  if(dfs(it,i,adjList,States)) return true;
              }else if(parent != it){
                  return true;
              }
          }

          return false;
      }


      bool isCycle(int V, vector<vector<int>>& edges) {

          vector<vector<int>> adjList(V);

          // Build adjacency list
          for (auto& p : edges) {

              int u = p[0];
              int v = p[1];

              adjList[u].push_back(v);
              adjList[v].push_back(u);
          }

          vector<int> States(V, 0);

          // Check every connected component
          for (int i = 0; i < V; i++) {

              if (States[i] == 0) {

                  if (dfs(i,-1, adjList, States))
                      return true;
              }
          }

          return false;
      }
  };