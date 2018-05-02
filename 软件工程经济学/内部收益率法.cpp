#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int year;
    cout << "请输入寿命期：";
    cin >> year;
    int Dn;
    cout << "请输入寿命期内第" << year << "期的残值：";
    cin >> Dn;
    float iD;
    cout << "请输入最低限度期望贴现率(%形式)：";
    cin >> iD;
    iD = iD / 100;
    float k[year+1];
    float bc[year+1];

    // 初始化
    for (int i = 0; i < year+1; ++i)
    {
        k[i] = 0.0;
        bc[i] = 0.0;
    }
    for (int i = 0; i < year+1; ++i)
    {
        cout << "输入在寿命期内" << i << "期的投资额：";
        cin >> k[i];
    }
    for (int i = 0; i < year+1; ++i)
    {
        cout << "输入寿命期内" << i << "期的收益减去支出的数值：";
        cin >> bc[i];
    }

    float a = 0, b = year;
    float i;
    do
    {
        i = a + (b-a) / 2;
        // 计算每一轮的NPV值
        float npv = 0.0;
        for (int j = 0; j < year+1; j++)
        {
            npv = npv + (bc[j] - k[j]) / pow(1+i, j);
        }
        if (npv > 0)
        {
            a = i;
        }
        else
        {
            b = i;
        }
    }while ((b-a) > 0 ? ((b-a) > 0.00001) : ((a-b) > 0.00001));
    float irr = (b + a) / 2;
    cout << "IRR is " << irr*100 << "%" << endl;

    if (irr > iD)
    {
        cout << irr*100 << "% > " << iD*100 << "%, 该项目可行！\n";
    }
    else
    {
        cout << irr*100 << "% <= " << iD*100 << "%, 该项目不可行！\n";
    }
    return 0;
}
