#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <graphics.h>
#include <string.h>
typedef struct {
    int x;
    int y;
} Move;
//ȫ�ֱ���s
Move C;
int flag = 0; // ��¼�ڰ׳���
int ChessBox[15][15] = { 0 }; // ��¼��ǰ����
int gameStarted = 0;  // ���������Ϸ�Ƿ��Ѿ���ʼ
int grade[15][15] = { 0 };//��¼�õ����
int directs[4][2] = { {1,0}, {1,1}, {0,1}, {-1,1 } };
int blocked[15][15] = { 0 }; // ����Ѷ�ס��λ�ã�0��ʾδ��ס��1��ʾ�Ѷ�ס
// ��ʼ����Ϸ
void initGame() {
    // ��������
    initgraph(900, 700, SHOWCONSOLE);
    // ���ر���ͼƬ
    IMAGE img;
    loadimage(&img, "bk.jpg");
    putimage(0, 0, &img);
    // ����
    setlinestyle(PS_SOLID, 1);
    setlinecolor(BLACK);
    for (int i = 1; i < 16; i++) {
        line(40, i * 40, 600, i * 40);
        line(i * 40, 40, i * 40, 600);
    }

    // ��������
    setbkmode(0);
    settextstyle(30, 0, _T("����"));
    settextcolor(BLACK);
    outtextxy(650, 200, _T("���1������"));
    outtextxy(680, 300, _T("VS����"));  // ��ʾ������ť����
    outtextxy(650, 400, _T("���2������"));
    outtextxy(680, 500, _T("AI����"));
}
void initGame1() {
    // ��������
    initgraph(900, 700, SHOWCONSOLE);
    // ���ر���ͼƬ
    IMAGE img;
    loadimage(&img, "bk.jpg");
    putimage(0, 0, &img);
    // ����
    setlinestyle(PS_SOLID, 1);
    setlinecolor(BLACK);
    for (int i = 1; i < 16; i++) {
        line(40, i * 40, 600, i * 40);
        line(i * 40, 40, i * 40, 600);
    }

    // ��������
    setbkmode(0);
    settextstyle(30, 0, _T("����"));
    settextcolor(BLACK);
    outtextxy(650, 200, _T("���1������"));
    outtextxy(660, 300, _T("�Ծ��ѿ�ʼ"));  // ��ʾ������ť����
    outtextxy(650, 400, _T("���2������"));
}
void initGame2() {
    // ��������
    initgraph(900, 700, SHOWCONSOLE);
    // ���ر���ͼƬ
    IMAGE img;
    loadimage(&img, "bk.jpg");
    putimage(0, 0, &img);
    // ����
    setlinestyle(PS_SOLID, 1);
    setlinecolor(BLACK);
    for (int i = 1; i < 16; i++) {
        line(40, i * 40, 600, i * 40);
        line(i * 40, 40, i * 40, 600);
    }

    // ��������
    setbkmode(0);
    settextstyle(30, 0, _T("����"));
    settextcolor(BLACK);
    outtextxy(655, 200, _T("��ң�����"));
    outtextxy(660, 300, _T("�Ծ��ѿ�ʼ"));
    outtextxy(655, 400, _T("���������"));

}
// ��Ӯ�ж�
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
            // ����Ƿ����ˡ�VS��������ť����
            if (Msg.x >= 650 && Msg.x <= 750 && Msg.y >= 280 && Msg.y <= 320 && !gameStarted) {
                // ����ˡ�VS��������ť����ʼ��Ϸ
                gameStarted = 1;
                cleardevice();
                initGame1();
                continue;
                // ���������ȴ����̵��
            }



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
                    }
                    else {
                        setfillcolor(WHITE);
                        solidcircle(40 * MapX, 40 * MapY, 18);
                        ChessBox[MapX - 1][MapY - 1] = 2;
                    }
                    flag++;

                    // �ж�ʤ��
                    if (judge(MapX, MapY)) {
                        if (flag % 2 == 1) {
                            MessageBox(NULL, "���1����ʤ��", "��Ϸ����", MB_OK);
                        }
                        else {
                            MessageBox(NULL, "���2����ʤ��", "��Ϸ����", MB_OK);
                        }
                        break;  // ������Ϸ
                    }
                }
            }
        }
    }
}
//������AI,��ģʽ
    // �ж��Ƿ���Ҫ��ֹ�Է�����
int isBlockingMove(int x, int y) {
    int opponent = (flag % 2 == 0) ? -1 : 1; // �Է��������� 1 �� -1
    int directions[4][2] = { {1, 0}, {0, 1}, {1, 1}, {1, -1} };

    for (int d = 0; d < 4; d++) {
        int dx = directions[d][0];
        int dy = directions[d][1];
        int count = 1;

        // �������
        for (int i = 1; i <= 4; i++) {
            int nx = x + i * dy;
            int ny = y + i * dx;
            if (nx >= 1 && nx <= 15 && ny >= 1 && ny <= 15 && ChessBox[nx - 1][ny - 1] == opponent) {
                count++;
            }
            else if (nx >= 1 && nx <= 15 && ny >= 1 && ny <= 15 && ChessBox[nx - 1][ny - 1] == 0) {
                break; // ֻ�����λ���ߵз�����
            }
            else {
                break;
            }
        }

        // ��鷴��
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
            return 1; // ��Ҫ��ס
        }
    }

    return 0;
}
   // ��ģʽ���ֺ���
void calculateScore() {
    int personNum = 0; // ��������ӵĸ���
    int botNum = 0; // AI�����ӵĸ���
    int emptyNum = 0; // ������հ�λ�ĸ���

    // �����������
    memset(grade, 0, sizeof(grade));

    // ���������ϵ�ÿ���հ�λ��
    for (int i = 1; i <= 15; i++) { 
        for (int j = 1; j <= 15; j++) { 
            // ������հ׵�
            if (ChessBox[i - 1][j - 1] == 0) { // ��������� 0 ��ʼ�����̵������ 1 ��ʼ������Ҫ������
                // �����ĸ����򣺺ᡢ����б����б
                for (int k = 0; k < 4; k++) {
                    int x = directs[k][0];
                    int y = directs[k][1];

                    // ���ü���
                    personNum = 0;
                    botNum = 0;
                    emptyNum = 0;

                    // ����ң����壩����
                    for (int n = 1; n <= 4; n++) {
                        int nx = i + n * y;
                        int ny = j + n * x;
                        if (nx >= 1 && nx <= 15 && ny >= 1 && ny <= 15) {
                            if (ChessBox[nx - 1][ny - 1] == 1) personNum++; // �������
                            else if (ChessBox[nx - 1][ny - 1] == 0) emptyNum++; // ��λ
                            else break;
                        }
                        else break;
                    }

                    // ��������
                    for (int n = 1; n <= 4; n++) {
                        int nx = i - n * y;
                        int ny = j - n * x;
                        if (nx >= 1 && nx <= 15 && ny >= 1 && ny <= 15) {
                            if (ChessBox[nx - 1][ny - 1] == 1) personNum++; // �������
                            else if (ChessBox[nx - 1][ny - 1] == 0) emptyNum++; // ��λ
                            else break;
                        }
                        else break;
                    }

                    // �������ӵĸ�����������
                    if (personNum == 1) grade[i - 1][j - 1] += 10;
                    else if (personNum == 2) grade[i - 1][j - 1] += (emptyNum == 1 ? 30 : 40);
                    else if (personNum == 3) grade[i - 1][j - 1] += (emptyNum == 1 ? 60 : 200);
                    else if (personNum == 4) grade[i - 1][j - 1] += 20000;

                    // ���ü���
                    personNum = 0;
                    botNum = 0;
                    emptyNum = 0;

                    // ��AI�����壩����
                    for (int n = 1; n <= 4; n++) {
                        int nx = i + n * y;
                        int ny = j + n * x;
                        if (nx >= 1 && nx <= 15 && ny >= 1 && ny <= 15) {
                            if (ChessBox[nx - 1][ny - 1] == -1) botNum++; // AI����
                            else if (ChessBox[nx - 1][ny - 1] == 0) emptyNum++; // ��λ
                            else break;
                        }
                        else break;
                    }

                    // ��������
                    for (int n = 1; n <= 4; n++) {
                        int nx = i - n * y;
                        int ny = j - n * x;
                        if (nx >= 1 && nx <= 15 && ny >= 1 && ny <= 15) {
                            if (ChessBox[nx - 1][ny - 1] == -1) botNum++; // AI����
                            else if (ChessBox[nx - 1][ny - 1] == 0) emptyNum++; // ��λ
                            else break;
                        }
                        else break;
                    }

                    // �������ӵĸ�����������
                    if (botNum == 0) grade[i - 1][j - 1] += 5;
                    else if (botNum == 1) grade[i - 1][j - 1] += 10;
                    else if (botNum == 2) grade[i - 1][j - 1] += (emptyNum == 1 ? 25 : 50);
                    else if (botNum == 3) grade[i - 1][j - 1] += (emptyNum == 1 ? 55 : 300);
                    else if (botNum >= 4) grade[i - 1][j - 1] += 30000;
                }
            }
        }
    }

    // �Ż����֣���������λ�õ�����
    for (int i = 1; i <= 15; i++) {
        for (int j = 1; j <= 15; j++) {
            // ������������΢�ӷ֣���� AI ������λ�õ�ƫ��
            if (i >= 7 && i <= 9 && j >= 7 && j <= 9) {
                grade[i - 1][j - 1] += 50; // ���ĵ�ӷ�
            }
        }
    }

    // �Ż����֣���ֹ�Է�����
    for (int i = 1; i <= 15; i++) {
        for (int j = 1; j <= 15; j++) {
            if (ChessBox[i - 1][j - 1] == 0) {
                // ���� AI �ķ�������
                if (isBlockingMove(i, j) && blocked[i - 1][j - 1] == 0) { // ֻ�е�û�б����Ϊ�Ѷ�סʱ�żӷ�
                    grade[i - 1][j - 1] += 100; // �������ֹ�Է��Ĺؼ�λ�ã��Ӵ����
                    blocked[i - 1][j - 1] = 1; // ����λ�ñ��Ϊ�Ѷ�ס
                }
            }
        }
    }
}
// AI���Ի� ȡ������ߵĵ�
Move getBestMove() {
    int maxScore = -1; // ��ʼ����Ϊ��ֵ��ȷ���ҵ�һ�����ߵķ���
    Move bestMove = { -1, -1 }; // ��ʼ������ƶ�λ��

    // ������������
    for (int i = 1; i <= 15; i++) {
        for (int j = 1; j <= 15; j++) {
            // �����ǿհ׵�
            if (ChessBox[i - 1][j - 1] == 0) {
                // �����ǰ������ָ��ߣ�����������������λ��
                if (grade[i - 1][j - 1] > maxScore) {
                    maxScore = grade[i - 1][j - 1];
                    bestMove.x = i; // ��¼������
                    bestMove.y = j; // ��¼������
                }
            }
        }
    }
    return bestMove; // ��������ƶ�λ��
}
//�˻���ս����ģʽ����AI�����ߵ�20��
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
                // ����ˡ�AI��������ť����ʼ��Ϸ
                gameStarted = 1;
                cleardevice();
                initGame2();
                continue;
                // ���������ȴ����̵��
            }
        }
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

        // �ж�ʤ��
        while (judgee) {
            judgee = 0;
            if (judge(MapX, MapY)) {
                if (flag % 2 == 1) {
                    MessageBox(NULL, "��Һ���ʤ��", "��Ϸ����", MB_OK);
                }
                else {
                    MessageBox(NULL, "�������ʤ��", "��Ϸ����", MB_OK);
                }
                over = 1;
                break;  // ������Ϸ
            }
        }

    }
}
int main() {
    initGame();
   // PlayGamerr();Ŀǰû��ѡ������ע�͵���
    PlayGamerj1();
    return 0;
}
