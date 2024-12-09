#pragma once
typedef struct {
    int x;
    int y;
} Move;
//全局变量s
Move C;
//防守型AI,简单模式
    // 判断是否需要阻止对方连子
int isBlockingMove(int x, int y) {
    int opponent = (flag % 2 == 0) ? -1 : 1; // 对方的棋子是 1 或 -1
    int directions[4][2] = { {1, 0}, {0, 1}, {1, 1}, {1, -1} };

    for (int d = 0; d < 4; d++) {
        int dx = directions[d][0];
        int dy = directions[d][1];
        int count = 1;

        // 检查正向
        for (int i = 1; i <= 4; i++) {
            int nx = x + i * dy;
            int ny = y + i * dx;
            if (nx >= 1 && nx <= 15 && ny >= 1 && ny <= 15 && ChessBox[nx - 1][ny - 1] == opponent) {
                count++;
            }
            else if (nx >= 1 && nx <= 15 && ny >= 1 && ny <= 15 && ChessBox[nx - 1][ny - 1] == 0) {
                break; // 只允许空位或者敌方棋子
            }
            else {
                break;
            }
        }

        // 检查反向
        for (int i = 1; i <= 4; i++) {
            int nx = x - i * dy;
            int ny = y - i * dx;
            if (nx >= 1 && nx <= 15 && ny >= 1 && ny <= 15 && ChessBox[nx - 1][ny - 1] == opponent) {
                count++;
            }
            else if (nx >= 1 && nx <= 15 && ny >= 1 && ny <= 15 && ChessBox[nx - 1][ny - 1] == 0) {
                break;
            }
            else {
                break;
            }
        }

        if (count >= 4) {
            return 1; // 需要堵住
        }
    }

    return 0;
}
// 简单模式评分函数
void calculateScore() {
    int personNum = 0; // 玩家连成子的个数
    int botNum = 0; // AI连成子的个数
    int emptyNum = 0; // 各方向空白位的个数

    // 清空评分数组
    memset(grade, 0, sizeof(grade));

    // 遍历棋盘上的每个空白位置
    for (int i = 1; i <= 15; i++) {
        for (int j = 1; j <= 15; j++) {
            // 仅计算空白点
            if (ChessBox[i - 1][j - 1] == 0) { // 由于数组从 0 开始，棋盘的坐标从 1 开始，所以要做减法
                // 遍历四个方向：横、竖、斜、反斜
                for (int k = 0; k < 4; k++) {
                    int x = directs[k][0];
                    int y = directs[k][1];

                    // 重置计数
                    personNum = 0;
                    botNum = 0;
                    emptyNum = 0;

                    // 对玩家（黑棋）评分
                    for (int n = 1; n <= 4; n++) {
                        int nx = i + n * y;
                        int ny = j + n * x;
                        if (nx >= 1 && nx <= 15 && ny >= 1 && ny <= 15) {
                            if (ChessBox[nx - 1][ny - 1] == 1) personNum++; // 玩家棋子
                            else if (ChessBox[nx - 1][ny - 1] == 0) emptyNum++; // 空位
                            else break;
                        }
                        else break;
                    }

                    // 反向评分
                    for (int n = 1; n <= 4; n++) {
                        int nx = i - n * y;
                        int ny = j - n * x;
                        if (nx >= 1 && nx <= 15 && ny >= 1 && ny <= 15) {
                            if (ChessBox[nx - 1][ny - 1] == 1) personNum++; // 玩家棋子
                            else if (ChessBox[nx - 1][ny - 1] == 0) emptyNum++; // 空位
                            else break;
                        }
                        else break;
                    }

                    // 根据连子的个数进行评分
                    if (personNum == 1) grade[i - 1][j - 1] += 10;
                    else if (personNum == 2) grade[i - 1][j - 1] += (emptyNum == 1 ? 30 : 40);
                    else if (personNum == 3) grade[i - 1][j - 1] += (emptyNum == 1 ? 60 : 200);
                    else if (personNum == 4) grade[i - 1][j - 1] += 20000;

                    // 重置计数
                    personNum = 0;
                    botNum = 0;
                    emptyNum = 0;

                    // 对AI（白棋）评分
                    for (int n = 1; n <= 4; n++) {
                        int nx = i + n * y;
                        int ny = j + n * x;
                        if (nx >= 1 && nx <= 15 && ny >= 1 && ny <= 15) {
                            if (ChessBox[nx - 1][ny - 1] == -1) botNum++; // AI棋子
                            else if (ChessBox[nx - 1][ny - 1] == 0) emptyNum++; // 空位
                            else break;
                        }
                        else break;
                    }

                    // 反向评分
                    for (int n = 1; n <= 4; n++) {
                        int nx = i - n * y;
                        int ny = j - n * x;
                        if (nx >= 1 && nx <= 15 && ny >= 1 && ny <= 15) {
                            if (ChessBox[nx - 1][ny - 1] == -1) botNum++; // AI棋子
                            else if (ChessBox[nx - 1][ny - 1] == 0) emptyNum++; // 空位
                            else break;
                        }
                        else break;
                    }

                    // 根据连子的个数进行评分
                    if (botNum == 0) grade[i - 1][j - 1] += 5;
                    else if (botNum == 1) grade[i - 1][j - 1] += 10;
                    else if (botNum == 2) grade[i - 1][j - 1] += (emptyNum == 1 ? 25 : 50);
                    else if (botNum == 3) grade[i - 1][j - 1] += (emptyNum == 1 ? 55 : 300);
                    else if (botNum >= 4) grade[i - 1][j - 1] += 30000;
                }
            }
        }
    }

    // 优化评分：考虑中央位置的评分
    for (int i = 1; i <= 15; i++) {
        for (int j = 1; j <= 15; j++) {
            // 给中心区域稍微加分，提高 AI 对中心位置的偏好
            if (i >= 7 && i <= 9 && j >= 7 && j <= 9) {
                grade[i - 1][j - 1] += 50; // 中心点加分
            }
        }
    }

    // 优化评分：阻止对方连子
    for (int i = 1; i <= 15; i++) {
        for (int j = 1; j <= 15; j++) {
            if (ChessBox[i - 1][j - 1] == 0) {
                // 计算 AI 的反向评分
                if (isBlockingMove(i, j) && blocked[i - 1][j - 1] == 0) { // 只有当没有被标记为已堵住时才加分
                    grade[i - 1][j - 1] += 100; // 如果是阻止对方的关键位置，加大分数
                    blocked[i - 1][j - 1] = 1; // 将该位置标记为已堵住
                }
            }
        }
    }
}
// AI策略获 取评分最高的点
Move getBestMove() {
    int maxScore = -1; // 初始分数为负值，确保找到一个更高的分数
    Move bestMove = { -1, -1 }; // 初始化最佳移动位置

    // 遍历整个棋盘
    for (int i = 1; i <= 15; i++) {
        for (int j = 1; j <= 15; j++) {
            // 仅考虑空白点
            if (ChessBox[i - 1][j - 1] == 0) {
                // 如果当前点的评分更高，更新最大分数和最优位置
                if (grade[i - 1][j - 1] > maxScore) {
                    maxScore = grade[i - 1][j - 1];
                    bestMove.x = i; // 记录最优行
                    bestMove.y = j; // 记录最优列
                }
            }
        }
    }
    return bestMove; // 返回最佳移动位置
}
