#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;
template <typename T>

class graph
{
    public:
    unordered_map<T, list<T>> adj;

    void addEdge(T u, T v, bool direction)
    {
        // 0 means undirected graph
        // 1 means directed graph

        adj[u].push_back(v);

        if (direction == 0)
        {
            adj[v].push_back(u);
        }
    }

    void print()
    {
        for (auto i : adj)
        {
            cout << i.first << "-> ";

            for (auto j : i.second)
            {
                cout << j << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    int m, n, u, v;

    cout << "Enter the no. of vertices: ";
    cin >> m;

    cout << "Enter the no. of edges: ";
    cin >> n;

    graph<int> g;

    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        g.addEdge(u, v, 0);
    }

    g.print();

    return 0;
}