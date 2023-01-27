#include <iostream>
#include <vector>
using namespace std;

const int N = 100;
int parent[N], weight[N];

int find(int x) {
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}

void unionSets(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX != rootY)
        parent[rootX] = rootY;
}

void initialize(int n) {
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
}

int maxEvenSubtreeSize(vector<vector<int>>& tree, int n) {
    int maxSize = 0;
    initialize(n);

    for (int i = 1; i <= n; i++) {
        if (weight[i] % 2 == 0) {
            for (int j = 0; j < tree[i].size(); j++) {
                int neighbor = tree[i][j];
                if (weight[neighbor] % 2 == 0) {
                    unionSets(i, neighbor);
                }
            }
        }
    }

    vector<int> setSizes(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        if (weight[i] % 2 == 0) {
            int root = find(i);
            setSizes[root]++;
            maxSize = max(maxSize, setSizes[root]);
        }
    }

    return maxSize;
}
