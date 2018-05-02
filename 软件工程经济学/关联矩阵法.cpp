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
    int methodnumber;   // ��������
    int targetnumber;   // ָ�����
    cout << "�����뷽������: ";
    cin >> methodnumber;
    cout << "������ָ�����: ";
    cin >> targetnumber;
    int E[targetnumber][targetnumber];

    // ������Ҫ�̶ȱȽϱ�
    for (int i = 0; i < targetnumber; i++)
    {
        for (int j = i + 1; j < targetnumber; j++)
        {
            // ������Ҫ�̶ȱȽϱ�
            int t;
            cout << "�� " << i+1 << " ��ָ��ȵ� " << j+1 << " ��Ҫ�𣿣���Ҫ��ͬ����Ҫ����1,����Ҫ����0��: ";
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

    // ��F[i]��W[i]
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

    // ����U[i][j]
    float U[methodnumber][targetnumber];
    float V[methodnumber];
    for (int i = 0; i < methodnumber; i++)
    {
        float t = 0;
        for (int j = 0; j < targetnumber; j++)
        {
            cout << "�����뷽��" << i+1 << "����ָ��" << j+1 << "�ļ�ֵ����";
            cin >> U[i][j];
            t = t + U[i][j] * W[j];
        }
        V[i] = t;
    }

    // ��V[i]�Ӵ�С�������
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
            cout << "��" << maxindex + 1 << "��������";
        }
        else
        {
            cout << "��" << maxindex + 1 << "������ > ";
        }
    }
}
