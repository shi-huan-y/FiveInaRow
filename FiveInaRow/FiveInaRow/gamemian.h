#pragma once
// �ж�ʤ��
int judge(int MapX, int MapY) {
    int temp = 2 - flag % 2;  // �жϵ�ǰ���
    // ���������ᡢ�Խ��ߡ����Խ���
    int directions[4][2] = { {1, 0}, {0, 1}, {1, 1}, {1, -1} };

    for (int dir = 0; dir < 4; dir++) {
        int dx = directions[dir][0], dy = directions[dir][1];
        int count = 1;  // ͳ�Ƶ�ǰ����

        // ���������
        for (int i = 1; i <= 4; i++) {
            int nx = MapX + i * dx, ny = MapY + i * dy;
            if (nx >= 1 && nx <= 15 && ny >= 1 && ny <= 15 && ChessBox[nx - 1][ny - 1] == temp)
                count++;
            else
                break;
        }

        // ��鷴����
        for (int i = 1; i <= 4; i++) {
            int nx = MapX - i * dx, ny = MapY - i * dy;
            if (nx >= 1 && nx <= 15 && ny >= 1 && ny <= 15 && ChessBox[nx - 1][ny - 1] == temp)
                count++;
            else
                break;
        }

        // �����5������һ�ߣ��򷵻�ʤ��
        if (count >= 5) {
            return 1;  // ʤ��
        }
    }
    return 0;  // û��ʤ��
}
// ���˶�ս
void PlayGamerr() {
    MOUSEMSG Msg;
    int ChessX = 0, ChessY = 0;
    int MapX = 0, MapY = 0;

    while (1) {
        Msg = GetMouseMsg(); // ��ȡ�����Ϣ
        if (Msg.uMsg == WM_LBUTTONDOWN) {
            if (gameStarted) {
                // �Ż������Ϣ����λ�ڸ�����
                for (int i = 1; i <= 15; i++) { // �Ż������Ϣ����λ�ڸ�����
                    for (int j = 1; j <= 15; j++) {
                        if (abs(Msg.x - j * 40) < 20 && abs(Msg.y - i * 40) < 20) {
                            ChessX = j * 40;
                            ChessY = i * 40;
                            MapX = j;
                            MapY = i;
                        }
                    }
                }

                // ȷ������ĸ���Ϊ��
                if (MapX >= 1 && MapX <= 15 && MapY >= 1 && MapY <= 15 && ChessBox[MapX - 1][MapY - 1] == 0) {
                    // ������
                    if (flag % 2 == 0) {
                        setfillcolor(BLACK);
                        solidcircle(40 * MapX, 40 * MapY, 18);
                        ChessBox[MapX - 1][MapY - 1] = 1;
                        clearStartButton1();
                        settextcolor(BLACK);
                        outtextxy(675, 500, _T("�ֵ�����"));
                    }
                    else {
                        setfillcolor(WHITE);
                        solidcircle(40 * MapX, 40 * MapY, 18);
                        ChessBox[MapX - 1][MapY - 1] = 2;
                        clearStartButton1();
                        settextcolor(BLACK);
                        outtextxy(675, 500, _T("�ֵ�����"));
                    }
                    flag++;

                    // �ж�ʤ��
                    if (judge(MapX, MapY)) {
                        if (flag % 2 == 1) {
                            clearStartButton();
                            outtextxy(640, 300, _T("���1����ʤ��"));
                        }
                        else {
                            clearStartButton();
                            outtextxy(640, 300, _T("���2����ʤ��"));
                        }
                        break;  // ������Ϸ
                    }
                }
                else {
                    clearStartButton1();
                    settextcolor(BLACK);
                    outtextxy(675, 500, _T("Υ�����"));
                }
            }
        }
    }
}
//�˻���ս����ģʽ����AI�����ߵ�20��
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
                // ����Ƿ����ˡ�VS��������ť����

                if (gameStarted) {
                    // �Ż������Ϣ����λ�ڸ�����
                    for (int i = 1; i <= 15; i++) { // �Ż������Ϣ����λ�ڸ�����
                        for (int j = 1; j <= 15; j++) {
                            if (abs(Msg.x - j * 40) < 20 && abs(Msg.y - i * 40) < 20) {
                                ChessX = j * 40;
                                ChessY = i * 40;
                                MapX = j;
                                MapY = i;
                            }
                        }
                    }
                    // ȷ������ĸ���Ϊ��
                    if (MapX >= 1 && MapX <= 15 && MapY >= 1 && MapY <= 15 && ChessBox[MapX - 1][MapY - 1] == 0) {
                        // ������

                        setfillcolor(BLACK);
                        solidcircle(40 * MapX, 40 * MapY, 18);
                        ChessBox[MapX - 1][MapY - 1] = 1;
                        flag++;
                    }
                    else {
                        clearStartButton1();
                        settextcolor(BLACK);
                        outtextxy(675, 500, _T("Υ�����"));
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
            outtextxy(675, 500, _T("�ֵ����"));
        }

        // �ж�ʤ��
        while (judgee) {
            judgee = 0;
            if (judge(MapX, MapY)) {
                if (flag % 2 == 1) {
                    clearStartButton();
                    outtextxy(675, 300, _T("���ʤ��"));
                }
                else {
                    clearStartButton();
                    outtextxy(675, 300, _T("���ʤ��"));
                }
                over = 1;
                break;  // ������Ϸ
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
                // ����Ƿ����ˡ�VS��������ť����

                if (gameStarted) {
                    // �Ż������Ϣ����λ�ڸ�����
                    for (int i = 1; i <= 15; i++) { // �Ż������Ϣ����λ�ڸ�����
                        for (int j = 1; j <= 15; j++) {
                            if (abs(Msg.x - j * 40) < 20 && abs(Msg.y - i * 40) < 20) {
                                ChessX = j * 40;
                                ChessY = i * 40;
                                MapX = j;
                                MapY = i;
                            }
                        }
                    }
                    // ȷ������ĸ���Ϊ��
                    if (MapX >= 1 && MapX <= 15 && MapY >= 1 && MapY <= 15 && ChessBox[MapX - 1][MapY - 1] == 0) {
                        // ������

                        setfillcolor(WHITE);
                        solidcircle(40 * MapX, 40 * MapY, 18);
                        ChessBox[MapX - 1][MapY - 1] = 1;
                        flag++;
                    }
                    else {
                        clearStartButton1();
                        settextcolor(BLACK);
                        outtextxy(675, 500, _T("Υ�����"));
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
            outtextxy(675, 500, _T("�ֵ����"));
        }

        // �ж�ʤ��
        while (judgee) {
            judgee = 0;
            if (judge(MapX, MapY)) {
                if (flag % 2 == 1) {
                    clearStartButton();
                    outtextxy(675, 300, _T("���ʤ��"));
                }
                else {
                    clearStartButton();
                    outtextxy(675, 300, _T("���ʤ��"));
                }
                over = 1;
                break;  // ������Ϸ
            }
        }

    }
}