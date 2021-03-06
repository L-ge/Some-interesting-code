#include <iostream>
#define process_number 5
#define resource_kind 4

void security();
void find_success(int t);
void showresult();

using namespace std;

// 各个进程已分配资源的数目
int allocation[process_number][resource_kind] =
{
    { 0, 0, 3, 2 },
    { 1, 0, 0, 0 },
    { 1, 3, 5, 4 },
    { 0, 3, 3, 2 },
    { 0, 0, 1, 4 }
};

// 各个进程还需要资源的数目
int need[process_number][resource_kind] =
{
    { 0, 0, 1, 2 },
    { 1, 7, 5, 0 },
    { 2, 3, 5, 6 },
    { 0, 6, 5, 2 },
    { 0, 6, 5, 6 }
};

int available[resource_kind] = { 1, 6, 2, 2 };  // 当前可用资源的数目
int work[resource_kind];                        // 系统可提供给进程继续运行所需的各类资源数目
bool finish[process_number];                    // 表示系统是否有足够的资源分配给进程，使之运行完成
int process_queue[process_number] = { -1, -1, -1, -1, -1 };  // 记录是否安全的进程序列
int process_number_index = 0;

int main()
{
    int requesti = 2;                  // 需要请求资源的进程号
    cout << "几号进程请求资源？: ";
    cin >> requesti;
    int request[resource_kind];        // 需要请求资源的进程需要的各类资源数
    cout << "分别输入需要各类资源的数目: ";
    for (int i = 0; i < resource_kind; ++i)
    {
        cin >> request[i];
    }
    bool flagn = false;
    for (int i = 0; i < resource_kind; ++i)
    {
        if (request[i] > need[requesti][i])
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
            if (request[i] > available[i])
            {
                flaga = true;
            }
        }
        if (flaga)
        {
            cout << "尚无足够的资源！进程P" << requesti << "需等待.\n";
        }
        else
        {
            for (int i = 0; i < resource_kind; ++i)
            {
                available[i] = available[i] - request[i];
                allocation[requesti][i] = allocation[requesti][i] + request[i];
                need[requesti][i] = need[requesti][i] - request[i];
            }
            security();
            showresult();
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

    for (int i = 0; i < process_number; i++)
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
            find_success(i);
            i = -1;
        }
    }
}

void find_success(int t)
{
    for (int k = 0; k < resource_kind; ++k)
    {
        work[k] = work[k] + allocation[t][k];
    }
    finish[t] = true;
    process_queue[process_number_index] = t;
    process_number_index = process_number_index + 1;
}

void showresult()
{
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
        for (int i = 0; i < process_number; ++i)
        {
            cout << "P" << process_queue[i] << " ";
        }
        cout << "系统处于安全状态.\n";
    }
}
