#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int m, n;
struct Point {
    int x;
    int y;
    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }
};
int X[] = {0, 0, 1, -1, 1, 1, -1, -1};
int Y[] = {1, -1, 0, 0, 1, -1, 1, -1};


void updateBoard(char board[][50], vector<int>& click) {
    Point p(click[0], click[1]);
    queue<Point> q;
    q.push(p);
    while (!q.empty()) {
        int count = 0;  //mine count
        Point cur = q.front();  //get the first element
        q.pop();
        //cout << "(" << cur.x << "," << cur.y << ")";
        if (board[cur.x][cur.y] == 'M') {  //game over
            board[cur.x][cur.y] = 'X';
            break;
        } else if (board[cur.x][cur.y] == 'E') {
            for (int i = 0; i < 8; i++) {  //calculate number of mine
                int newX = cur.x + X[i];
                int newY = cur.y + Y[i];
                if (newX >= 0 && newX < m && newY >= 0 && newY < n) {
                    if (board[newX][newY] == 'M')
                        count++;
                }
            }
            if (count == 0) {
                board[cur.x][cur.y] = 'B';
                for (int i = 0; i < 8; i++) {
                    int newX = cur.x + X[i];
                    int newY = cur.y + Y[i];
                    if (newX >= 0 && newX < m && newY >= 0 && newY < n) {
                        Point next(newX, newY);
                        q.push(next);
                    }
                }
            } else {
                board[cur.x][cur.y] = count + '0';
            }
            //cout << ":" << board[cur.x][cur.y] << endl;
        }
    }
}

int main() {
    int x, y;
    char board[50][50] = {0};
    vector<int> click;
    cin >> m >> n >> x >> y;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];
    click.push_back(x);
    click.push_back(y);
    updateBoard(board, click);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            cout << board[i][j];
        cout << endl;
    }
}
