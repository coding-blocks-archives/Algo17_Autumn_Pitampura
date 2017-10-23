// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com

#include <iostream>
#include <vector>
#include <queue>
#include <numeric>
#include <functional>
#include <algorithm>
using namespace std;

class Graph {
    vector<vector<int> > v;
    int nV;
    vector<int> topoSortAns;    //for topoSortDFS

    void dfs(int src, vector<bool>& visited) {
        visited[src] = true;
        // cout << src << " ";
        vector<int> & adjList = v[src];

        for (int i = 0; i < adjList.size(); ++i) {
            int curNeighbor = adjList[i];
            if (visited[curNeighbor] == false) {
                dfs(curNeighbor, visited);
            }
        }
        topoSortAns.push_back(src);
    }

public:
    Graph(int n) {
        nV = n;
        v.resize(nV, vector<int>());
    }

    void addEdge(int src, int dest, bool bidirectional = true) {
        v[src].push_back(dest);
        if (bidirectional) v[dest].push_back(src); //bidirectional
    }

    void dfs(int src) {
        vector<bool> visited(nV, false);
        dfs(src, visited);
    }

    void bfs(int src) {
        queue<int> q;
        vector<bool> visited(nV, false);

        q.push(src);
        visited[src] = true;

        while (!q.empty()) {
            int curVtx = q.front();
            cout << curVtx << " ";
            q.pop();

            vector<int>& adjList = v[curVtx];
            for (int i = 0; i < adjList.size(); ++i) {
                int ngbr = adjList[i];
                if (visited[ngbr] == false) {
                    q.push(ngbr);
                    visited[ngbr] = true;
                }
            }
        }
    }

    bool isConnected() {
        vector<bool> visited(nV, false);
        dfs(0, visited);
        bool ans = accumulate(visited.begin(), visited.end(), true, logical_and<bool>());
        return ans;
    }

    int connectedComponents() {
        vector<bool> visited(nV, false);
        int numCC = 0;

        for (int vtx = 0; vtx < nV; ++vtx) {
            if (visited[vtx] == false) {
                dfs(vtx, visited);
                cout << endl;
                ++numCC;
            }
        }
        return numCC;
    }

    int shortestDistance(int src, int dest) {
        vector<bool> visited(nV, false);
        vector<int> dist(nV, 0);
        vector<int> parent(nV, -1);

        queue<int> q;
        q.push(src);
        visited[src] = true;

        while (q.empty() == false) {
            int curVtx = q.front();
            q.pop();

            for (int i = 0;  i < v[curVtx].size(); ++i) {
                int curNeighbor = v[curVtx][i];
                if (visited[curNeighbor] == false) {
                    visited[curNeighbor] = true;
                    parent[curNeighbor] = curVtx;
                    dist[curNeighbor] = dist[curVtx] + 1;
                    q.push(curNeighbor);
                }
            }
        }

        if (visited[dest] == false) return 1000000000;  //inf

        int lastVtx = dest;
        while (lastVtx != -1) {
            cout << lastVtx << " ";
            lastVtx = parent[lastVtx];
        }
        return dist[dest];
    }

    vector<int> topologicalSortBFS() {
        vector<int> order;

        int * inDegree = new int[nV] {};
        for (int curVtx = 0; curVtx < nV; ++curVtx) {
            auto &adjList = v[curVtx];  //C++11 AUTOmatic type deduction
            for (int i = 0; i < adjList.size(); ++i) {
                int curNeighbor = adjList[i];
                ++inDegree[curNeighbor];
            }
        }

        queue<int> q;
        vector<bool> visited(nV, false);

        int src = *find(inDegree, inDegree + nV, 0);
        q.push(src);
        visited[src] = true;

        while (!q.empty()) {
            int curVtx = q.front();
            order.push_back(curVtx);
            q.pop();

            vector<int>& adjList = v[curVtx];
            for (int i = 0; i < adjList.size(); ++i) {
                int ngbr = adjList[i];
                --inDegree[ngbr];
                if (visited[ngbr] == false && inDegree[ngbr] == 0) {
                    q.push(ngbr);
                    visited[ngbr] = true;
                }
            }
        }

        delete inDegree;
        return order;
    }

    vector<int> topologicalSortDFS() {
        vector<bool> visited(nV, false);
        dfs(0, visited);
        reverse(topoSortAns.begin(), topoSortAns.end());
        return topoSortAns;
    }


};

void beautify() {
    cout << endl;
    cout << "==============";
    cout << endl;
}

int main() {
    // Graph G(5);
    // G.addEdge(0, 1);
    // G.addEdge(0, 2);
    // G.addEdge(1, 3);
    // G.addEdge(3, 4);
    // G.addEdge(2, 4);


    // G.dfs(0);
    // beautify();
    // G.bfs(0);

    // cout << G.isConnected();
    // cout << G.connectedComponents();

    // cout << G.shortestDistance(0, 3);

    // Graph G(6);
    // G.addEdge(0, 1, false);
    // G.addEdge(0, 5, false);
    // G.addEdge(1, 3, false);
    // G.addEdge(5, 3, false);
    // G.addEdge(3, 4, false);
    // G.addEdge(3, 2, false);

    // vector<int> v = G.topologicalSortBFS();
    // vector<int> v = G.topologicalSortDFS();
    // for(int i = 0; i < v.size(); ++i){
    //     cout << v[i] << " ";
    // }


    //SNAKE AND LADDER
    vector<int> snakeLadder(37, 0);
    snakeLadder[2] = 15;
    snakeLadder[5] = 7;
    snakeLadder[9] = 27;
    snakeLadder[17] = 4;
    snakeLadder[18] = 29;
    snakeLadder[20] = 6;
    snakeLadder[24] = 16;
    snakeLadder[25] = 35;
    snakeLadder[32] = 30;
    snakeLadder[34] = 12;

    Graph G(37);
    for(int box = 1; box < 36; ++box){
        for(int dice = 1; dice <= 6; ++dice){
            int move = box + dice;
            if (move <= 36 && snakeLadder[move] != 0) G.addEdge(box, snakeLadder[move], false);
            else if (move <= 36){
                G.addEdge(box, move, false);
            }
        }
    }

    G.shortestDistance(1, 36);

}