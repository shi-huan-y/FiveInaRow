#pragma once
MOUSEMSG Choose;
int flag = 0; // ��¼�ڰ׳���
int ChessBox[15][15] = { 0 }; // ��¼��ǰ����
int gameStarted = 0;  // ���������Ϸ�Ƿ��Ѿ���ʼ
int grade[15][15] = { 0 };//��¼�õ����
int directs[4][2] = { {1,0}, {1,1}, {0,1}, {-1,1 } };
int blocked[15][15] = { 0 }; // ����Ѷ�ס��λ�ã�0��ʾδ��ס��1��ʾ�Ѷ�ס   