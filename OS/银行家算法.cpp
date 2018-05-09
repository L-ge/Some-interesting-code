#include <iostream>
#define process_number 5
#define resource_kind 3

void security();
using namespace std;

// 各个进程已分配资源的数目
int allocation[process_number][resource_kind] =
{
    {0, 1, 0},
    {2, 0, 0},
    {3, 0, 2},
    {2, 1, 1},
    {0, 0, 2}
};

// 各个进程还需要资源的数目
int need[process_number][resource_kind] =
{
    {7, 4, 3},
    {1, 2, 2},
    {6, 0, 0},
    {0, 1, 1},
    {4, 3, 1}
};

int available[resource_kind] = {3, 3, 2};;  // 当前可用资源的数目
int work[resource_kind]; // 系统可提供给进程继续运行所需的各类资源数目
bool finish[process_number]; // 表示系统是否有足够的资源分配给进程，使之运行完成

int main()
{
    int requesti;                  // 需要请求资源的进程号
    int request[requesti][resource_kind];      // 需要请求资源的进程需要的各类资源数
    cout << "几号进程请求资源？: ";
    cin >> requesti;
    cout << "分别输入需要各类资源的数目: ";
    for (int i = 0; i < resource_kind; ++i)
    {
        cin >> request[requesti][i];
    }
    bool flagn = false;
    for (int i = 0; i < resource_kind; ++i)
    {
        if (request[requesti][i] > need[requesti][i])
        {
            flagn = true;
        }
    }
    if (flagn)
    {
        cout << "该进程所需要的资源已超过它所宣布的最大值.\n";
    }
    else
    {
        bool flaga = false;
        for (int i = 0; i < resource_kind; ++i)
        {
            if (request[requesti][i] > available[i])
            {
                flaga = true;
            }
        }
        if (flaga)
        {
            cout << "尚无足够的资源！进程P" << requesti << " 需等待.\n";
        }
        else
        {
            for (int i = 0; i < resource_kind; ++i)
            {
                available[i] = available[i] - request[requesti][i];
                allocation[requesti][i] = allocation[requesti][i] + request[requesti][i];
                need[requesti][i] = need[requesti][i] - request[requesti][i];
                security();
            }
            bool flags = false;
            for (int i = 0; i < process_number; ++i)
            {
                if (finish[i] == false)
                {
                    flags = true;
                }
            }
            if (flags)
            {
                cout << "系统处于不安全状态.\n";
            }
            else
            {
                cout << "系统处于安全状态.\n";
            }
        }
    }
    return 0;
}

void security()
{
    for (int i = 0; i < resource_kind; ++i)
    {
        work[i] = available[i];
    }
    for (int i = 0; i < process_number; ++i)
    {
        finish[i] = false;
    }
    for (int i = 0; i < process_number; ++i)
    {
        bool flagw = false;
        for (int j = 0; j < resource_kind; ++j)
        {
            if (need[i][j] > work[j])
            {
                flagw = true;
            }
        }
        if (finish[i] == false && flagw == false)
        {
            for (int j = 0; j < resource_kind; ++j)
            {
                work[j] = work[j] + allocation[i][j];
                finish[i] = true;
            }
        }
    }
}
