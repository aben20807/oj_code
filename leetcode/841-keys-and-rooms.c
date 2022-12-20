/* 2022/12/20
跟昨天的類似
所以今天用並查集 (Disjoint Set Union-find algorithm (DSU)) 解看看
make_union 回傳 true 代表 set 少一個
set 數量變成一代表每個點都聯通
用 rank 來最佳化 (讓 tree 不要一直線，盡量平衡)
結果不行! 遇到 [[1],[],[0,3],[1]] 就錯 QQ

改回用 DFS
*/

void dfs(int room, int** rooms, int* roomsColSize, int* is_visit) {
    if (is_visit[room]) {
        return;
    }
    is_visit[room] = 1;
    printf("%d\n", room);
    for (int j = 0; j < roomsColSize[room]; j++) {
        dfs(rooms[room][j], rooms, roomsColSize, is_visit);
    }
}

bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize){
    int is_visit[roomsSize];
    for (int i = 0; i < roomsSize; i++) {
        is_visit[i] = 0;
    }
    dfs(0, rooms, roomsColSize, is_visit);

    for (int i = 0; i < roomsSize; i++) {
        if (!is_visit[i]) {
            return false;
        }
    }
    return true;
}
