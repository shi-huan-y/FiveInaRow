#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <graphics.h>
#include <string.h>
typedef struct {
    int x;
    int y;
} Move;
//全局变量s
Move C;
int flag = 0; // 记录黑白出手
int ChessBox[15][15] = { 0 }; // 记录当前棋盘
int gameStarted = 0;  // 用来标记游戏是否已经开始
int grade[15][15] = { 0 };//记录该点分数
int directs[4][2] = { {1,0}, {1,1}, {0,1}, {-1,1 } };
int blocked[15][15] = { 0 }; // 标记已堵住的位置，0表示未堵住，1表示已堵住
// 初始化游戏
void initGame() {
    // 创建界面
    initgraph(900, 700, SHOWCONSOLE);
    // 加载背景图片
    IMAGE img;
    loadimage(&img, "bk.jpg");
    putimage(0, 0, &img);
    // 划线
    setlinestyle(PS_SOLID, 1);
    setlinecolor(BLACK);
    for (int i = 1; i < 16; i++) {
        line(40, i * 40, 600, i * 40);
        line(i * 40, 40, i * 40, 600);
    }

    // 插入文字
    setbkmode(0);
    settextstyle(30, 0, _T("楷体"));
    settextcolor(BLACK);
    outtextxy(650, 200, _T("玩家1：黑棋"));
    outtextxy(680, 300, _T("VS启动"));  // 显示启动按钮文字
    outtextxy(650, 400, _T("玩家2：白棋"));
    outtextxy(680, 500, _T("AI启动"));
}
void initGame1() {
    // 创建界面
    initgraph(900, 700, SHOWCONSOLE);
    // 加载背景图片
    IMAGE img;
    loadimage(&img, "bk.jpg");
    putimage(0, 0, &img);
    // 划线
    setlinestyle(PS_SOLID, 1);
    setlinecolor(BLACK);
    for (int i = 1; i < 16; i++) {
        line(40, i * 40, 600, i * 40);
        line(i * 40, 40, i * 40, 600);
    }

    // 插入文字
    setbkmode(0);
    settextstyle(30, 0, _T("楷体"));
    settextcolor(BLACK);
    outtextxy(650, 200, _T("玩家1：黑棋"));
    outtextxy(660, 300, _T("对局已开始"));  // 显示启动按钮文字
    outtextxy(650, 400, _T("玩家2：白棋"));
}
void initGame2() {
    // 创建界面
    initgraph(900, 700, SHOWCONSOLE);
    // 加载背景图片
    IMAGE img;
    loadimage(&img, "bk.jpg");
    putimage(0, 0, &img);
    // 划线
    setlinestyle(PS_SOLID, 1);
    setlinecolor(BLACK);
    for (int i = 1; i < 16; i++) {
        line(40, i * 40, 600, i * 40);
        line(i * 40, 40, i * 40, 600);
    }

    // 插入文字
    setbkmode(0);
    settextstyle(30, 0, _T("楷体"));
    settextcolor(BLACK);
    outtextxy(655, 200, _T("玩家：黑棋"));
    outtextxy(660, 300, _T("对局已开始"));
    outtextxy(655, 400, _T("入机：白棋"));

}
// 输赢判断
int judge(int MapX, int MapY) {
    int temp = 2 - flag % 2;  // 判断当前玩家
    // 方向：竖、横、对角线、反对角线
    int directions[4][2] = { {1, 0}, {0, 1}, {1, 1}, {1, -1} };

    for (int dir = 0; dir < 4; dir++) {
        int dx = directions[dir][0], dy = directions[dir][1];
        int count = 1;  // 统计当前棋子

        // 检查正方向
        for (int i = 1; i <= 4; i++) {
            int nx = MapX + i * dx, ny = MapY + i * dy;
            if (nx >= 1 && nx <= 15 && ny >= 1 && ny <= 15 && ChessBox[nx - 1][ny - 1] == temp)
                count++;
            else
                break;
        }

        // 检查反方向
        for (int i = 1; i <= 4; i++) {
            int nx = MapX - i * dx, ny = MapY - i * dy;
            if (nx >= 1 && nx <= 15 && ny >= 1 && ny <= 15 && ChessBox[nx - 1][ny - 1] == temp)
                count++;
            else
                break;
        }

        // 如果有5个连成一线，则返回胜利
        if (count >= 5) {
            return 1;  // 胜利
        }
    }
    return 0;  // 没有胜利
}
// 人人对战
void PlayGamerr() {
    MOUSEMSG Msg;
    int ChessX = 0, ChessY = 0;
    int MapX = 0, MapY = 0;

    while (1) {
        Msg = GetMouseMsg(); // 获取鼠标信息
        if (Msg.uMsg == WM_LBUTTONDOWN) {
            // 检查是否点击了“VS启动”按钮区域
            if (Msg.x >= 650 && Msg.x <= 750 && Msg.y >= 280 && Msg.y <= 320 && !gameStarted) {
                // 点击了“VS启动”按钮，开始游戏
                gameStarted = 1;
                cleardevice();
                initGame1();
                continue;
                // 点击后继续等待棋盘点击
            }



            if (gameStarted) {
                // 优化鼠标信息，定位在格子上
                for (int i = 1; i <= 15; i++) { // 优化鼠标信息，定位在格子上
                    for (int j = 1; j <= 15; j++) {
                        if (abs(Msg.x - j * 40) < 20 && abs(Msg.y - i * 40) < 20) {
                            ChessX = j * 40;
                            ChessY = i * 40;
                            MapX = j;
                            MapY = i;
                        }
                    }
                }

                // 确保点击的格子为空
                if (MapX >= 1 && MapX <= 15 && MapY >= 1 && MapY <= 15 && ChessBox[MapX - 1][MapY - 1] == 0) {
                    // 画棋子
                    if (flag % 2 == 0) {
                        setfillcolor(BLACK);
                        solidcircle(40 * MapX, 40 * MapY, 18);
                        ChessBox[MapX - 1][MapY - 1] = 1;
                    }
                    else {
                        setfillcolor(WHITE);
                        solidcircle(40 * MapX, 40 * MapY, 18);
                        ChessBox[MapX - 1][MapY - 1] = 2;
                    }
                    flag++;

                    // 判断胜利
                    if (judge(MapX, MapY)) {
                        if (flag % 2 == 1) {
                            MessageBox(NULL, "玩家1黑棋胜利", "游戏结束", MB_OK);
                        }
                        else {
                            MessageBox(NULL, "玩家2白棋胜利", "游戏结束", MB_OK);
                        }
                        break;  // 结束游戏
                    }
                }
            }
        }
    }
}
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
//人机对战，简单模式，但AI可以走到20步
void PlayGamerj1() {
    MOUSEMSG Msg;
    int ChessX = 0, ChessY = 0;
    //int qiX = 0, qiY = 0;
    int MapX = 0, MapY = 0;
    int judgee = 0;
    int over = 0;
    while (1) {
        Msg = GetMouseMsg();
        if (Msg.uMsg == WM_LBUTTONDOWN) {
            if (Msg.x >= 650 && Msg.x <= 750 && Msg.y >= 480 && Msg.y <= 520 && !gameStarted) {
                // 点击了“AI启动”按钮，开始游戏
                gameStarted = 1;
                cleardevice();
                initGame2();
                continue;
                // 点击后继续等待棋盘点击
            }
        }
        while (flag % 2 == 0 && over == 0 && judgee == 0) {
            if (Msg.uMsg == WM_LBUTTONDOWN) {
                // 检查是否点击了“VS启动”按钮区域

                if (gameStarted) {
                    // 优化鼠标信息，定位在格子上
                    for (int i = 1; i <= 15; i++) { // 优化鼠标信息，定位在格子上
                        for (int j = 1; j <= 15; j++) {
                            if (abs(Msg.x - j * 40) < 20 && abs(Msg.y - i * 40) < 20) {
                                ChessX = j * 40;
                                ChessY = i * 40;
                                MapX = j;
                                MapY = i;
                            }
                        }
                    }
                    // 确保点击的格子为空
                    if (MapX >= 1 && MapX <= 15 && MapY >= 1 && MapY <= 15 && ChessBox[MapX - 1][MapY - 1] == 0) {
                        // 画棋子

                        setfillcolor(BLACK);
                        solidcircle(40 * MapX, 40 * MapY, 18);
                        ChessBox[MapX - 1][MapY - 1] = 1;
                        flag++;
                    }
                }

            }judgee = 1;
        }


        while (flag % 2 && over == 0 && judgee == 0) {
            setfillcolor(WHITE);
            calculateScore();
            C=getBestMove();

            MapX = ChessX=C.x, MapY = ChessY=C.y;
            solidcircle( ChessX*40,  ChessY*40, 18);
            //printf("%d %d", MapX, MapY);
            ChessBox[MapX-1][MapY-1] = 2;
            flag++;
            judgee = 1;
        }

        // 判断胜利
        while (judgee) {
            judgee = 0;
            if (judge(MapX, MapY)) {
                if (flag % 2 == 1) {
                    MessageBox(NULL, "玩家黑棋胜利", "游戏结束", MB_OK);
                }
                else {
                    MessageBox(NULL, "入机白棋胜利", "游戏结束", MB_OK);
                }
                over = 1;
                break;  // 结束游戏
            }
        }

    }
}
int main() {
    initGame();
   // PlayGamerr();目前没有选择，所以注释掉了
    PlayGamerj1();
    return 0;
}
