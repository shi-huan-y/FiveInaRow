#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <graphics.h>
#include <string.h>
#include <iostream>
#include "quanju.h"
#include "jiemian.h"
#include "ailaw.h"
#include "gamemian.h"       
int main() {
    //��ʼ����Ϸ
    initGame();
    //ѡ����Ϸģʽ
    while (gameStarted==0) {
        Choose = GetMouseMsg();
        int xuanze = 0;
        if (Choose.uMsg == WM_LBUTTONDOWN) {
            if (Choose.x >= 650 && Choose.x <= 750 && Choose.y >= 180 && Choose.y <= 220 && !gameStarted) {
                // ����ˡ�VS��������ť����ʼ��Ϸ
                gameStarted = 1;
                cleardevice();
                initGame1();
                PlayGamerr();
            }
            if (Choose.x >= 650 && Choose.x <= 750 && Choose.y >= 380 && Choose.y <= 420 && !gameStarted) {
                // ����ˡ�AI��������ť����ʼ��Ϸ
                gameStarted = 1;
                cleardevice();
                initGame2();
                while (xuanze == 0) {
                    MOUSEMSG Color;
                    Color = GetMouseMsg();
                    Color = GetMouseMsg();
                    if (Color.uMsg == WM_LBUTTONDOWN) {
                        if (Color.x >= 650 && Color.x <= 750 && Color.y >= 180 && Color.y <= 220) {
                            xuanze = 1;
                            cleardevice();
                            initGame3();
                            PlayGamerj1B();
                        }
                        if (Color.x >= 650 && Color.x <= 750 && Color.y >= 380 && Color.y <= 430) {
                            xuanze = 1;
                            cleardevice();
                            initGame4();
                            flag = 1;
                            PlayGamerj1W();
                        }
                    }
                }
            }
        }
    }
    getchar();
    return 0;
}
