#pragma once//����
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
// ��ʼ����Ϸ
void initGame() {
    // ��������
    initgraph(900, 700);
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

    outtextxy(680, 200, _T("VS����"));  // ��ʾ������ť����

    outtextxy(680, 400, _T("AI����"));
}
void initGame1() {
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
    outtextxy(675, 500, _T("�ֵ�����"));
}
void initGame2() {
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
    outtextxy(660, 300, _T("��ѡ������"));
    outtextxy(675, 200, _T("ѡ�����"));
    outtextxy(675, 400, _T("ѡ�����"));

}
void initGame3() {
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
    outtextxy(660, 300, _T("�Ծ��ѿ�ʼ"));  // ��ʾ������ť����
    outtextxy(655, 400, _T("���������"));
    outtextxy(675, 500, _T("�ֵ����"));
}
void initGame4() {
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
    outtextxy(660, 300, _T("�Ծ��ѿ�ʼ"));  // ��ʾ������ť����
    outtextxy(655, 400, _T("���������"));
    outtextxy(675, 500, _T("�ֵ����"));
}
void initGame5() {
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
    outtextxy(640, 300, _T("��Һ���ʤ��"));  // ��ʾ������ť����
    outtextxy(655, 400, _T("���������"));
}
void initGame6() {
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
    outtextxy(640, 300, _T("�������ʤ��"));  // ��ʾ������ť����
    outtextxy(655, 400, _T("���������"));
}
