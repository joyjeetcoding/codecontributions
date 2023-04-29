#include<iostream>
#include<vector>

int bellmanFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {

  vector<int> dist(n + 1, 1e9); // started from 1 and we will
  //  put the biggest number in it.

  dist[src] = 0;

  // n-1 times
  for (int i = 1; i < n; i++) {
    // traverse on edge list
    for (int j = 0; j < m; j++) {
      int u = edges[j][0];
      int v = edges[j][1];
      int wt = edges[j][2];

      if (dist[u] != 1e9 && ((dist[u] + wt) < dist[v])) {
        dist[v] = dist[u] + wt;
      }
    }
  }

  // check for -ve cycle
  bool flag = 0;
  for (int j = 0; j < m; j++) {
    int u = edges[j][0];
    int v = edges[j][1];
    int wt = edges[j][2];

    if (dist[u] != 1e9 && ((dist[u] + wt) < dist[v])) {
      flag = 1;
    }
  }

    if(flag == 0)
    {
        return dist[dest];
    }
    return -1;
  // return dist[dest];

}

int main()
{
  int n, m, src, dest, temp;
  vector<int> edges;
  cout << "Enter the no. of vertices: ";
  cin >> n;
  cout << "Enter the no. of edges: ";
  cin >> m;
  cout << "Enter the source node: ";
  cin >> src;
  cout << "Enter the destination node: ";
  cin >> dest; 
  cout <<  "Enter the edge list " << endl;
  for(int i = 0; i < n; i++)
  {
    vector<int> t;
    for(int j = 0 ; j < m; j++)
    {
      cin >> temp;
      t.push_back(temp);
    }
    edges.push_back(t);
  }
  int n = bellmanFord(n, m, src, dest, edges);

  if(n == -1)
  {
    cout << "-ve cycle is present";
  }
  else
  {
    cout << "The shortest dist from "<< src << "to "<< dest << "is " << n;
  }

  return 0;
}