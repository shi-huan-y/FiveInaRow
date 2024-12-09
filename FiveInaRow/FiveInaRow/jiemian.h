#pragma once//覆盖
void clearStartButton() {
    setfillcolor(RGB(239, 228, 176));
    setlinecolor(RGB(239, 228, 176));
    fillrectangle(640, 270, 880, 350);
}
void clearStartButton1() {
    setfillcolor(RGB(239, 228, 176));
    setlinecolor(RGB(239, 228, 176));
    fillrectangle(660, 470, 820, 540);
}
// 初始化游戏
void initGame() {
    // 创建界面
    initgraph(900, 700);
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

    outtextxy(680, 200, _T("VS启动"));  // 显示启动按钮文字

    outtextxy(680, 400, _T("AI启动"));
}
void initGame1() {
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
    outtextxy(675, 500, _T("轮到黑棋"));
}
void initGame2() {
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
    outtextxy(660, 300, _T("请选择棋子"));
    outtextxy(675, 200, _T("选择黑棋"));
    outtextxy(675, 400, _T("选择白棋"));

}
void initGame3() {
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
    outtextxy(660, 300, _T("对局已开始"));  // 显示启动按钮文字
    outtextxy(655, 400, _T("入机：白棋"));
    outtextxy(675, 500, _T("轮到玩家"));
}
void initGame4() {
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
    outtextxy(655, 200, _T("玩家：白棋"));
    outtextxy(660, 300, _T("对局已开始"));  // 显示启动按钮文字
    outtextxy(655, 400, _T("入机：黑棋"));
    outtextxy(675, 500, _T("轮到玩家"));
}
void initGame5() {
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
    outtextxy(640, 300, _T("玩家黑棋胜利"));  // 显示启动按钮文字
    outtextxy(655, 400, _T("入机：白棋"));
}
void initGame6() {
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
    outtextxy(640, 300, _T("入机白棋胜利"));  // 显示启动按钮文字
    outtextxy(655, 400, _T("入机：白棋"));
}
