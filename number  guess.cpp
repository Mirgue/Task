#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int main()
{
    int bigNumber, num[3], g_num[3], j, i, A, B, win_num = 0, lose_num = 0;
    char YorN;
    while(true)
    {
        cout << "Want to play a game(Y/N)?";
        cin >> YorN; // 询问是否游戏
        if (YorN == 'N')
        {
            cout <<"Your play " << win_num+lose_num << " game(s), win " << win_num << " game(s), lose " << lose_num << " game(s)." << endl;
            break;
        }
        if (YorN == 'Y')
        {
            do
            {
                bigNumber = rand() * 900 / (RAND_MAX + 1) + 100;
                num[0] = bigNumber / 100;
                num[1] = (bigNumber % 100) / 10;
                num[2] = bigNumber % 10;
            } while (num[1] == num[2] || num[1] == num[0] || num[2] == num[0]); // 得到随机数
            cout << bigNumber << endl; // 玩的时候删去这一行！！！
            for (j=0; j<7; j++)
            {
                A = 0;
                B = 0;
                srand(time(NULL));
                cout << "TRY" << j+1 << ":Enter three numbers:" << endl;
                cin >> g_num[0] >> g_num[1] >> g_num[2]; // 输入三个数字
                for (i=0; i<=2; i++)
                {
                    if (num[i] == g_num[i]) A++;
                    if (num[i] == g_num[(i+1)%3] || num[i] == g_num[(i+2)%3]) B++;
                }
                cout << A << 'A' << B<< 'B' << endl; // 判断A和B的值
                if (A==3)
                {
                    cout << "WIN!" << endl;
                    win_num++;
                    break;
                } // 胜利条件
            }
            if (j==7)
            {
                cout << "LOSE! The number should be " << bigNumber << endl; // 失败条件
                lose_num++;
            }
        }
    }
    return 0;
}
