#include <bits/stdc++.h>
using namespace std;

#define INF 999999

// ---------------------- BFS ----------------------
void BFS(vector<vector<int>>& adj, int start, int n) {
    vector<int> visited(n, 0);
    queue<int> q;

    visited[start] = 1;
    q.push(start);

    cout << "BFS: ";

    while(!q.empty()) {
        int v = q.front();
        q.pop();
        cout << v << " ";

        for(int i = 0; i < n; i++) {
            if(adj[v][i] == 1 && !visited[i]) {
                visited[i] = 1;
                q.push(i);
            }
        }
    }
    cout << endl;
}

// ---------------------- DFS ----------------------
void DFSUtil(int v, vector<vector<int>>& adj, vector<int>& visited, int n) {
    visited[v] = 1;
    cout << v << " ";

    for(int i = 0; i < n; i++) {
        if(adj[v][i] == 1 && !visited[i]) {
            DFSUtil(i, adj, visited, n);
        }
    }
}

void DFS(vector<vector<int>>& adj, int start, int n) {
    vector<int> visited(n, 0);
    cout << "DFS: ";
    DFSUtil(start, adj, visited, n);
    cout << endl;
}

// ---------------------- KRUSKAL ----------------------
struct Edge {
    int u, v, w;
};

int findParent(int v, vector<int>& parent) {
    if(parent[v] == v) return v;
    return parent[v] = findParent(parent[v], parent);
}

void unionSet(int a, int b, vector<int>& parent) {
    a = findParent(a, parent);
    b = findParent(b, parent);
    parent[b] = a;
}

void Kruskal(vector<vector<int>>& adj, int n) {
    vector<Edge> edges;
    vector<int> parent(n);

    // Create edge list
    for(int i = 0; i < n; i++)
        for(int j = i+1; j < n; j++)
            if(adj[i][j] != 0)
                edges.push_back({i, j, adj[i][j]});

    // Sort edges
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.w < b.w;
    });

    for(int i = 0; i < n; i++) parent[i] = i;

    int cost = 0;
    cout << "Kruskal MST edges:\n";

    for(auto& e : edges) {
        int u = e.u, v = e.v, w = e.w;

        if(findParent(u, parent) != findParent(v, parent)) {
            cout << u << " - " << v << " = " << w << endl;
            cost += w;
            unionSet(u, v, parent);
        }
    }

    cout << "Minimum Cost = " << cost << endl;
}

// ---------------------- PRIM ----------------------
void Prim(vector<vector<int>>& adj, int n) {
    vector<int> key(n, INF);
    vector<int> parent(n, -1);
    vector<int> mstSet(n, 0);

    key[0] = 0;

    for(int count = 0; count < n - 1; count++) {
        int u = -1, minKey = INF;

        for(int i = 0; i < n; i++)
            if(!mstSet[i] && key[i] < minKey) {
                minKey = key[i];
                u = i;
            }

        mstSet[u] = 1;

        for(int v = 0; v < n; v++) {
            if(adj[u][v] && !mstSet[v] && adj[u][v] < key[v]) {
                key[v] = adj[u][v];
                parent[v] = u;
            }
        }
    }

    cout << "Prim MST edges:\n";
    int total = 0;

    for(int i = 1; i < n; i++) {
        cout << parent[i] << " - " << i << " = " << adj[i][parent[i]] << endl;
        total += adj[i][parent[i]];
    }

    cout << "Minimum Cost = " << total << endl;
}

// ---------------------- DIJKSTRA ----------------------
void Dijkstra(vector<vector<int>>& adj, int src, int n) {
    vector<int> dist(n, INF);
    vector<int> visited(n, 0);

    dist[src] = 0;

    for(int count = 0; count < n - 1; count++) {
        int u = -1, minDist = INF;

        for(int i = 0; i < n; i++)
            if(!visited[i] && dist[i] < minDist) {
                minDist = dist[i];
                u = i;
            }

        visited[u] = 1;

        for(int v = 0; v < n; v++) {
            if(adj[u][v] && dist[u] + adj[u][v] < dist[v]) {
                dist[v] = dist[u] + adj[u][v];
            }
        }
    }

    cout << "Dijkstra distances from " << src << ":\n";
    for(int i = 0; i < n; i++)
        cout << src << " -> " << i << " = " << dist[i] << endl;
}

// ---------------------- MAIN ----------------------
int main() {
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    vector<vector<int>> adj(n, vector<int>(n));

    cout << "Enter adjacency matrix:\n";
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> adj[i][j];

    while(true) {
        cout << "\nMenu:\n";
        cout << "1. BFS\n2. DFS\n3. Kruskal\n4. Prim\n5. Dijkstra\n6. Exit\n";
        cout << "Enter choice: ";

        int ch, start;
        cin >> ch;

        switch(ch) {
            case 1:
                cout << "Start vertex: ";
                cin >> start;
                BFS(adj, start, n);
                break;

            case 2:
                cout << "Start vertex: ";
                cin >> start;
                DFS(adj, start, n);
                break;

            case 3:
                Kruskal(adj, n);
                break;

            case 4:
                Prim(adj, n);
                break;

            case 5:
                cout << "Source vertex: ";
                cin >> start;
                Dijkstra(adj, start, n);
                break;

            case 6:
                return 0;

            default:
                cout << "Invalid choice\n";
        }
    }
}
