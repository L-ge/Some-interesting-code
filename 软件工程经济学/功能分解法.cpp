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
    cout << "������ģ��ĸ�����";
    int modelnumber;    // ģ�����
    cin >> modelnumber;
    // step:�׶θ������ֳ����������ϵͳ��ơ����롢�����ĸ��׶Σ�
    int step = 4;

    cout << "���������ģ��ĳɱ������ʣ�" << modelnumber << "�����ݣ���";
    float Co[modelnumber];
    for (int i = 0; i < modelnumber; i++)
        cin >> Co[i];

    cout << "���������ģ����Ͷ������ʣ�" << modelnumber << "�����ݣ���";
    float Eo[modelnumber];
    for (int i = 0; i < modelnumber; i++)
        cin >> Eo[i];

    cout << "��������ר�Ҽ���������ĸ�ģ�����С����ֵ��" << modelnumber << "�����ݣ���";
    float a[modelnumber];
    for (int i = 0; i < modelnumber; i++)
        cin >> a[i];

    cout << "��������ר�Ҽ���������ĸ�ģ���������ֵ��" << modelnumber << "�����ݣ���";
    float b[modelnumber];
    for (int i = 0; i < modelnumber; i++)
        cin >> b[i];

    cout << "��������ר�Ҽ���������ĸ�ģ��������ֵ��" << modelnumber << "�����ݣ���";
    float m[modelnumber];
    for (int i = 0; i < modelnumber; i++)
        cin >> m[i];

    cout << "------------------------------" << endl;
    // ����E[j]��C[j]��M[j]
    float E[modelnumber];  // ��ģ��ƽ��������
    float C[modelnumber];  // ��ģ��ɱ�
    float M[modelnumber];  // ��ģ��������Ϊ��λ�Ĺ�����
    for (int j = 0; j < modelnumber; j++)
    {
        E[j] = (a[j] + 4 * m[j] + b[j]) / 6;
        C[j] = Co[j] * E[j];
        M[j] = E[j] / Eo[j];
    }

    // ������
    float Csum = 0, Esum = 0, Msum = 0;
    for (int j = 0; j < modelnumber; j++)
    {
        Csum = Csum + C[j];
        Esum = Esum + E[j];
        Msum = Msum + M[j];
    }

    // �����ǽ�ͨ��������һ��ά�ȷֽ����ɵĻ��ܼ���Ľ��
    cout << "����������׶εĹ�ʱ�����ʣ�4�����ݣ���";
    int ax[4];
    for (int i = 0; i < 4; i++)
        cin >> ax[i];

    // ��ά�����빤����
    float M2[modelnumber][step];
    for (int i = 0; i < step; i++)
    {
        cout << "������� " << i + 1 << " �׶εĹ�������" << modelnumber << "�����ݣ���";
        for (int j = 0; j < modelnumber; j++)
        {
            cin >> M2[j][i];
        }
    }

    // �����ά�µĸ��׶ι������ܺ�
    float Msumstep[step];
    for (int i = 0; i < step; i++)
    {
        Msumstep[i] = 0;
        for (int j = 0; j < modelnumber; j++)
        {
            Msumstep[i] = Msumstep[i] + M2[j][i];

        }
    }

    // �����ά�µĸ����ܹ������ܺ�
    float Msummodel[modelnumber];
    for (int i = 0; i < modelnumber; i++)
    {
        Msummodel[i] = 0;
        for (int j = 0; j < step; j++)
        {
            Msummodel[i] = Msummodel[i] + M2[i][j];

        }
    }

    // ����ϵͳ���׶γɱ������ù�ʱ������ax[]��
    float C2[step];
    for (int i = 0; i < step; i++)
    {
        C2[i] = Msumstep[i] * ax[i];
    }

    // ����ϵͳ�ܳɱ�
    float C2sum = 0;
    for (int i = 0; i < step; i++)
    {
        C2sum += C2[i];
    }

    // ����ϵͳ�ܹ�����
    float M2sum = 0;
    for (int i = 0; i < step; i++)
    {
        M2sum += Msumstep[i];
    }

    // ������
    cout << "\n\n------------------\n";
    cout << "Cs is " << Csum << endl;
    cout << "Ms is " << Msum << endl;
    cout << "Cs' is " << C2sum << endl;
    cout << "Ms' is " << M2sum << endl;
}
