#pragma once
typedef struct {
    int x;
    int y;
} Move;
//ȫ�ֱ���s
Move C;
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
