#pragma once
MOUSEMSG Choose;
int flag = 0; // 记录黑白出手
int ChessBox[15][15] = { 0 }; // 记录当前棋盘
int gameStarted = 0;  // 用来标记游戏是否已经开始
int grade[15][15] = { 0 };//记录该点分数
int directs[4][2] = { {1,0}, {1,1}, {0,1}, {-1,1 } };
int blocked[15][15] = { 0 }; // 标记已堵住的位置，0表示未堵住，1表示已堵住   