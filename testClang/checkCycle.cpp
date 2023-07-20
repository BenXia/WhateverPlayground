#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector< pair<int, int> > g;
vector< int > father;

int findFather(int x) {
    int a = x;
    while (x != father[x]) {
        x = father[x];
    }
    while (a != father[a]) {
        int z = a;
        a = father[a];
        father[z] = x;
    }
    return x;
}

//void Union(int a, int b) {
//    int fa = findFather(a);
//    int fb = findFather(b);
//    father[a] = father[b] = min(fa, fb);
//}

void Union(int a, int b) {
    int fa = findFather(a);
    int fb = findFather(b);
    father[fa] = father[fb] = min(fa, fb);
}

bool isCyclicUnirectedGraph() {
    for (int i = 0; i < g.size(); i++) {
        int u = g[i].first;
        int v = g[i].second;
        if (father[u] == father[v]) {
            return true;
        }
        Union(u, v);
        //Union(father[u], father[v]); // 或者修改上面的 Union 方法
    }
    return false;
}

bool isCyclicDirectedGraph() {
    for (int i = 0; i < g.size(); i++) {
        int u = g[i].first;
        int v = g[i].second;
        if (father[u] == v) {
            return true;
        }
        father[v] = findFather(u);
    }
    return false;
}

int main() {
//    // Undirected acyclic graph
//    //   0
//    //  / \
//    // 1   2
//    g.push_back(make_pair(0, 1));
//    g.push_back(make_pair(0, 2));
//    for (int i = 0; i < 3; i++) {
//        father.push_back(i);
//    }
//    cout << isCyclicUnirectedGraph() << endl;   //0，无环
//    // Undirected cyclic graph
//    //   0
//    //  / \
//    // 1———2
//    g.pop_back();
//    g.push_back(make_pair(2, 3));
//    g.push_back(make_pair(1, 3));
//    g.push_back(make_pair(0, 2));
//    vector<int>().swap(father);
//    for (int i = 0; i <= 3; i++) {
//        father.push_back(i);
//    }
//    cout << isCyclicUnirectedGraph() << endl;   //1，有环


    // Directed acyclic graph
    //   0
    //  / \
    // v   v
    // 1——>2
    vector< pair<int, int> >().swap(g);
    g.push_back(make_pair(0, 1));
    g.push_back(make_pair(1, 2));
    g.push_back(make_pair(0, 2));
    vector<int>().swap(father);
    for (int i = 0; i < 3; i++) {
        father.push_back(i);
    }
    cout << isCyclicDirectedGraph() << endl;    //0，无环
    // Directed cyclic graph
    //   0
    //  / ^
    // v   \
    // 1——>2
    g.pop_back();
    g.push_back(make_pair(2, 0));
    vector<int>().swap(father);
    for (int i = 0; i < 3; i++) {
        father.push_back(i);
    }
    cout << isCyclicDirectedGraph() << endl;    //1，有环
    // Directed cyclic graph
    //   0
    //  /
    // v
    // 1——>2
    //  <——
    g.pop_back();
    g.push_back(make_pair(2, 1));
    vector<int>().swap(father);
    for (int i = 0; i < 3; i++) {
        father.push_back(i);
    }
    cout << isCyclicDirectedGraph() << endl;    //1，有环

    return 0;
}






