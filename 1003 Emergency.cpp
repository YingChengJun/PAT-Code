#include <iostream>
using namespace std;

#define MAX_NODE 500
#define INT_MAX 1000000000

int a[MAX_NODE][MAX_NODE];
int rescue[MAX_NODE] = {0};
int n, m, c1, c2;
void dijkstra(int src, int des);

int main() {
    int i, j;
    int src, des, val;
    cin >> n >> m >> c1 >> c2;
    for (i = 0; i < MAX_NODE; i++)
        for (j = 0; j < MAX_NODE; j++)
            a[i][j] = INT_MAX;
    for (i = 0; i < n; i++)
        cin >> rescue[i];
    for (i = 0; i < m; i++) {
        cin >> src >> des >> val;
        a[src][des] = a[des][src] = val;
    }
    dijkstra(c1, c2);
    return 0;
}

void dijkstra(int src, int des) {
    int visited[MAX_NODE] = {0};
    int dist[MAX_NODE];
    int weight[MAX_NODE] = {0};  //the maximum number of rescue team
    int nums[MAX_NODE] = {0};  //the number of shortest path
    int i, j;

    //initialize dist, weight and nums
    for (int i = 0; i < n; i++) dist[i] = INT_MAX;
    dist[src] = 0;
    weight[src] = rescue[src];
    nums[src] = 1;

    for (i = 0; i < n; i++) {
        int min = INT_MAX;
        int u = -1;  //find the next node
        for (j = 0; j < n; j++) {
            if (!visited[j] && dist[j]< min) {
                u = j;
                min = dist[j];
            }
        }
        if (u == -1) return;  //not connected
        visited[u] = 1; //set visited flag

        //find adjacent node and update source
        for (int v = 0; v < n; v++) {
            //visited[v] == false: the node has not been collected
            //a[u][v] != INT_MAX: there exist a path from u to v
            //dist[u] + a[u][v] < dist[v]: can update the dist
            if (!visited[v] && a[u][v] != INT_MAX) {
                if (dist[u] + a[u][v] < dist[v]) {  //find a shorter path
                    dist[v] = dist[u] + a[u][v];  //replace dist[v]
                    weight[v] = weight[u] + rescue[v]; //replace rescue number
                    nums[v] = nums[u]; //replace the number of shortest path
                } else if (dist[u] + a[u][v] == dist[v]) { //find a same long path
                    if (weight[u] + rescue[v] > weight[v]) { //the path contains more rescue teams
                        weight[v] = weight[u] + rescue[v];
                    }
                    //the number of shortest path is not related to the weight
                    nums[v] += nums[u];
                }
            }
        }
    }

    cout << nums[des] << " " << weight[des];
}
