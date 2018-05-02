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
    cout << "请输入模块的个数：";
    int modelnumber;    // 模块个数
    cin >> modelnumber;
    // step:阶段个数（分成需求分析、系统设计、编码、测试四个阶段）
    int step = 4;

    cout << "请输入各个模块的成本利用率（" << modelnumber << "个数据）：";
    float Co[modelnumber];
    for (int i = 0; i < modelnumber; i++)
        cin >> Co[i];

    cout << "请输入各个模块的劳动生产率（" << modelnumber << "个数据）：";
    float Eo[modelnumber];
    for (int i = 0; i < modelnumber; i++)
        cin >> Eo[i];

    cout << "请输入由专家及经验给出的个模块的最小可能值（" << modelnumber << "个数据）：";
    float a[modelnumber];
    for (int i = 0; i < modelnumber; i++)
        cin >> a[i];

    cout << "请输入由专家及经验给出的个模块的最大可能值（" << modelnumber << "个数据）：";
    float b[modelnumber];
    for (int i = 0; i < modelnumber; i++)
        cin >> b[i];

    cout << "请输入由专家及经验给出的个模块的最可能值（" << modelnumber << "个数据）：";
    float m[modelnumber];
    for (int i = 0; i < modelnumber; i++)
        cin >> m[i];

    cout << "------------------------------" << endl;
    // 计算E[j]、C[j]、M[j]
    float E[modelnumber];  // 各模块平均工作量
    float C[modelnumber];  // 各模块成本
    float M[modelnumber];  // 各模块以人月为单位的工作量
    for (int j = 0; j < modelnumber; j++)
    {
        E[j] = (a[j] + 4 * m[j] + b[j]) / 6;
        C[j] = Co[j] * E[j];
        M[j] = E[j] / Eo[j];
    }

    // 最后汇总
    float Csum = 0, Esum = 0, Msum = 0;
    for (int j = 0; j < modelnumber; j++)
    {
        Csum = Csum + C[j];
        Esum = Esum + E[j];
        Msum = Msum + M[j];
    }

    // 以上是仅通过功能这一个维度分解而完成的汇总计算的结果
    cout << "请输入各个阶段的工时费用率（4个数据）：";
    int ax[4];
    for (int i = 0; i < 4; i++)
        cin >> ax[i];

    // 二维下输入工作量
    float M2[modelnumber][step];
    for (int i = 0; i < step; i++)
    {
        cout << "请输入第 " << i + 1 << " 阶段的工作量（" << modelnumber << "个数据）：";
        for (int j = 0; j < modelnumber; j++)
        {
            cin >> M2[j][i];
        }
    }

    // 计算二维下的各阶段工作量总和
    float Msumstep[step];
    for (int i = 0; i < step; i++)
    {
        Msumstep[i] = 0;
        for (int j = 0; j < modelnumber; j++)
        {
            Msumstep[i] = Msumstep[i] + M2[j][i];

        }
    }

    // 计算二维下的各功能工作量总和
    float Msummodel[modelnumber];
    for (int i = 0; i < modelnumber; i++)
    {
        Msummodel[i] = 0;
        for (int j = 0; j < step; j++)
        {
            Msummodel[i] = Msummodel[i] + M2[i][j];

        }
    }

    // 计算系统各阶段成本（利用工时费用率ax[]）
    float C2[step];
    for (int i = 0; i < step; i++)
    {
        C2[i] = Msumstep[i] * ax[i];
    }

    // 计算系统总成本
    float C2sum = 0;
    for (int i = 0; i < step; i++)
    {
        C2sum += C2[i];
    }

    // 计算系统总工作量
    float M2sum = 0;
    for (int i = 0; i < step; i++)
    {
        M2sum += Msumstep[i];
    }

    // 结果输出
    cout << "\n\n------------------\n";
    cout << "Cs is " << Csum << endl;
    cout << "Ms is " << Msum << endl;
    cout << "Cs' is " << C2sum << endl;
    cout << "Ms' is " << M2sum << endl;
}
