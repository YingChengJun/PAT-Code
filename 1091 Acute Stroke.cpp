#include <cstdio>
#include <queue>
using namespace std;

int slice, m, n, T;
int pixel[1286][128][60];
int dx[6] = {0, 0, 0, 0, 1, -1};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {1, -1, 0, 0, 0, 0};
bool visited[1286][128][60] = {0};
struct Point {
    int px;
    int py;
    int pz;
    Point(int pxx, int pyy, int pzz) {
        px = pxx;
        py = pyy;
        pz = pzz;
    }
};

int bfs(int px, int py, int pz) {
    int ans = 0;
    Point start(px, py, pz);
    queue<Point> q;
    q.push(start);
    visited[px][py][pz] = true;
    while (!q.empty()) {
        Point f = q.front();
        q.pop();
        ans++;
        for (int i = 0; i < 6; i++) {
            int nx = f.px + dx[i];
            int ny = f.py + dy[i];
            int nz = f.pz + dz[i];
            if (nx >= 0 && ny >= 0 && nz >= 0
                    && nx < m && ny < n && nz < slice
                    && !visited[nx][ny][nz] && pixel[nx][ny][nz]) {
                Point np(nx, ny, nz);
                q.push(np);
                visited[nx][ny][nz] = true;
            }
        }
    }
    if (ans >= T) return ans;
    else return 0;
}

int main() {
    int x, y, z;
    int ans = 0;
    scanf("%d %d %d %d", &m, &n, &slice, &T);
    for (z = 0; z < slice; z++)
        for (x = 0; x < m; x++)
            for (y = 0; y < n; y++)
                scanf("%d", &pixel[x][y][z]);
    for (z = 0; z < slice; z++)
        for (x = 0; x < m; x++)
            for (y = 0; y < n; y++) {
                if (pixel[x][y][z] && !visited[x][y][z]) {
                    ans += bfs(x, y, z);
                }
            }
    printf("%d", ans);
    return 0;
}
