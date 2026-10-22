#include<bits/stdc++.h>
using namespace std;
//最短路径用BFS实现
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
class Pos{
public:
    int first;
    int second;
    Pos(int x, int y) {
        this -> first = x;
        this -> second = y;
    }
}; 

int getTime(const vector<vector<int>>& myMap, vector<vector<bool>>& visited, const Pos& point) {
    int time = 0;
    int n = myMap.size();
    if(n == 0 || myMap[0].empty()) return 0;
    int m = myMap[0].size();
    if(point.first < 0 || point.first >= n || point.second < 0 || point.second >= m) return 0;
    //队列，记住队列处理的核心就是入队之前就处理每个元素
    queue<Pos> que;
    //起点入队
    visited[point.first][point.second] = true;
    que.push(point);
    while(!que.empty()) {
        //同一层的格子与起点距离相同，处理完一整层后距离才加一
        int levelSize = que.size();
        for(int j = 0; j < levelSize; j++) {
            Pos pos = que.front();
            que.pop();
            //四个方向
            for(int i = 0; i < 4; i++) {
                int xx = pos.first + dx[i];
                int yy = pos.second + dy[i];
                //先检查边界，再访问数组；合法列下标是0到m-1
                if(xx < 0 || xx >= n || yy < 0 || yy >= m || myMap[xx][yy] == 1 || visited[xx][yy]) continue;
                visited[xx][yy] = true;
                if(myMap[xx][yy] == 4) return time + 1;
                que.push({xx, yy});
            }
        }
        time++;
    }
    return 0;
}
int main() {
    int n, m;
    while(cin >> n >> m) {
        vector<vector<int>> myMap(n, vector<int>(m));
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        Pos pos = {-1, -1};
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> myMap[i][j];
                //得到初始坐标
                if(myMap[i][j] == 3) pos = {i, j};
            }
        }
        //完整读入地图之后再搜索，每组数据只输出一次
        int distance = getTime(myMap, visited, pos);
        if(distance != 0) cout << distance << '\n';
        else cout << "unreachable\n";
    }
    return 0;
}
