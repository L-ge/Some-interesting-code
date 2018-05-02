#include <iostream>
using namespace std;

void f();
int main()
{
    f();
    return 0;
}

void f()
{
    int methodnumber;   // 方案个数
    int targetnumber;   // 指标个数
    cout << "请输入方案个数: ";
    cin >> methodnumber;
    cout << "请输入指标个数: ";
    cin >> targetnumber;
    int E[targetnumber][targetnumber];

    // 输入重要程度比较表
    for (int i = 0; i < targetnumber; i++)
    {
        for (int j = i + 1; j < targetnumber; j++)
        {
            // 输入重要程度比较表
            int t;
            cout << "第 " << i+1 << " 个指标比第 " << j+1 << " 重要吗？（重要或同等重要输入1,不重要输入0）: ";
            cin >> t;
            if (t == 1)
            {
                E[i][j] = 1;
                E[j][i] = 0;
            }
            if (t == 0)
            {
                E[i][j] = 0;
                E[j][i] = 1;
            }
        }
        E[i][i] = 1;
    }

    // 求F[i]、W[i]
    int F[targetnumber];
    float W[targetnumber];
    int total = 0;
    for (int i = 0; i < targetnumber; i++)
    {
        int sum = 0;
        for (int j = 0; j < targetnumber; j++)
        {
            sum = sum + E[i][j];
        }
        F[i] = sum;
        total = total + sum;
    }
    for (int i = 0; i < targetnumber; i++)
    {
        W[i] = (float)F[i] / total;
    }

    // 输入U[i][j]
    float U[methodnumber][targetnumber];
    float V[methodnumber];
    for (int i = 0; i < methodnumber; i++)
    {
        float t = 0;
        for (int j = 0; j < targetnumber; j++)
        {
            cout << "请输入方案" << i+1 << "关于指标" << j+1 << "的价值量：";
            cin >> U[i][j];
            t = t + U[i][j] * W[j];
        }
        V[i] = t;
    }

    // 将V[i]从大到小排序输出
    cout << endl;
    for (int i = 0; i < methodnumber; i++)
    {
        int maxindex = i;
        float t = V[i];
        for (int j = 0; j < methodnumber; j++)
        {
            if (t < V[j])
            {
                t = V[j];
                maxindex = j;
            }
        }
        V[maxindex] = 0.0;
        if (i == methodnumber - 1)
        {
            cout << "第" << maxindex + 1 << "个方案。";
        }
        else
        {
            cout << "第" << maxindex + 1 << "个方案 > ";
        }
    }
}
