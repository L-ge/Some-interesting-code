#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int year;
    cout << "�����������ڣ�";
    cin >> year;
    int Dn;
    cout << "�������������ڵ�" << year << "�ڵĲ�ֵ��";
    cin >> Dn;
    float iD;
    cout << "����������޶�����������(%��ʽ)��";
    cin >> iD;
    iD = iD / 100;
    float k[year+1];
    float bc[year+1];

    // ��ʼ��
    for (int i = 0; i < year+1; ++i)
    {
        k[i] = 0.0;
        bc[i] = 0.0;
    }
    for (int i = 0; i < year+1; ++i)
    {
        cout << "��������������" << i << "�ڵ�Ͷ�ʶ";
        cin >> k[i];
    }
    for (int i = 0; i < year+1; ++i)
    {
        cout << "������������" << i << "�ڵ������ȥ֧������ֵ��";
        cin >> bc[i];
    }

    float a = 0, b = year;
    float i;
    do
    {
        i = a + (b-a) / 2;
        // ����ÿһ�ֵ�NPVֵ
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
        cout << irr*100 << "% > " << iD*100 << "%, ����Ŀ���У�\n";
    }
    else
    {
        cout << irr*100 << "% <= " << iD*100 << "%, ����Ŀ�����У�\n";
    }
    return 0;
}
