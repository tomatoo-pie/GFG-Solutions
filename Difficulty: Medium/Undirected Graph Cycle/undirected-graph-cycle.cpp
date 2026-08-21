class Solution {
  public:

      bool bfs(int i, vector<vector<int>>& adjList, vector<int>& States) {

          States[i] = 1;

          queue<pair<int, int>> q;
          q.push({i, -1});

          while (!q.empty()) {

              int node = q.front().first;
              int parent = q.front().second;
              q.pop();

              for (auto adj : adjList[node]) {

                  // Unvisited node
                  if (States[adj] == 0) {
                      States[adj] = 1;
                      q.push({adj, node});
                  }

                  // Already visited and not parent
                  else if (parent != adj) {
                      return true;
                  }
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

                  if (bfs(i, adjList, States))
                      return true;
              }
          }

          return false;
      }
  };