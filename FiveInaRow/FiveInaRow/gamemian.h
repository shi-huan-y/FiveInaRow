#pragma once
// 判断胜负
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
                        clearStartButton1();
                        settextcolor(BLACK);
                        outtextxy(675, 500, _T("轮到白棋"));
                    }
                    else {
                        setfillcolor(WHITE);
                        solidcircle(40 * MapX, 40 * MapY, 18);
                        ChessBox[MapX - 1][MapY - 1] = 2;
                        clearStartButton1();
                        settextcolor(BLACK);
                        outtextxy(675, 500, _T("轮到黑棋"));
                    }
                    flag++;

                    // 判断胜利
                    if (judge(MapX, MapY)) {
                        if (flag % 2 == 1) {
                            clearStartButton();
                            outtextxy(640, 300, _T("玩家1黑棋胜利"));
                        }
                        else {
                            clearStartButton();
                            outtextxy(640, 300, _T("玩家2白棋胜利"));
                        }
                        break;  // 结束游戏
                    }
                }
                else {
                    clearStartButton1();
                    settextcolor(BLACK);
                    outtextxy(675, 500, _T("违规操作"));
                }
            }
        }
    }
}
//人机对战，简单模式，但AI可以走到20步
void PlayGamerj1B() {
    MOUSEMSG Msg;
    int ChessX = 0, ChessY = 0;
    int MapX = 0, MapY = 0;
    int judgee = 0;
    int over = 0;
    while (1) {
        Msg = GetMouseMsg();
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
                    else {
                        clearStartButton1();
                        settextcolor(BLACK);
                        outtextxy(675, 500, _T("违规操作"));
                    }
                }

            }judgee = 1;
        }


        while (flag % 2 && over == 0 && judgee == 0) {
            setfillcolor(WHITE);
            calculateScore();
            C = getBestMove();

            MapX = ChessX = C.x, MapY = ChessY = C.y;
            solidcircle(ChessX * 40, ChessY * 40, 18);
            //printf("%d %d", MapX, MapY);
            ChessBox[MapX - 1][MapY - 1] = 2;
            flag++;
            judgee = 1;
            clearStartButton1();
            settextcolor(BLACK);
            outtextxy(675, 500, _T("轮到玩家"));
        }

        // 判断胜利
        while (judgee) {
            judgee = 0;
            if (judge(MapX, MapY)) {
                if (flag % 2 == 1) {
                    clearStartButton();
                    outtextxy(675, 300, _T("玩家胜利"));
                }
                else {
                    clearStartButton();
                    outtextxy(675, 300, _T("入机胜利"));
                }
                over = 1;
                break;  // 结束游戏
            }
        }

    }
}
void PlayGamerj1W() {
    MOUSEMSG Msg;
    int ChessX = 0, ChessY = 0;
    int MapX = 0, MapY = 0;
    int judgee = 0;
    int over = 0;
    while (1) {
        Msg = GetMouseMsg();
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

                        setfillcolor(WHITE);
                        solidcircle(40 * MapX, 40 * MapY, 18);
                        ChessBox[MapX - 1][MapY - 1] = 1;
                        flag++;
                    }
                    else {
                        clearStartButton1();
                        settextcolor(BLACK);
                        outtextxy(675, 500, _T("违规操作"));
                    }
                }

            }judgee = 1;
        }


        while (flag % 2 && over == 0 && judgee == 0) {
            setfillcolor(BLACK);
            calculateScore();
            C = getBestMove();

            MapX = ChessX = C.x, MapY = ChessY = C.y;
            solidcircle(ChessX * 40, ChessY * 40, 18);
            //printf("%d %d", MapX, MapY);
            ChessBox[MapX - 1][MapY - 1] = 2;
            flag++;
            judgee = 1;
            clearStartButton1();
            settextcolor(BLACK);
            outtextxy(675, 500, _T("轮到玩家"));
        }

        // 判断胜利
        while (judgee) {
            judgee = 0;
            if (judge(MapX, MapY)) {
                if (flag % 2 == 1) {
                    clearStartButton();
                    outtextxy(675, 300, _T("玩家胜利"));
                }
                else {
                    clearStartButton();
                    outtextxy(675, 300, _T("入机胜利"));
                }
                over = 1;
                break;  // 结束游戏
            }
        }

    }
}