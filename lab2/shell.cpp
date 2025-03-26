#include <iostream>
#include <random>
#include <chrono>

void gen(int *arr, int N)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(-10000, 10000);
    for(int i = 0; i < N; ++i) 
    {
        arr[i] = dist(gen);
    }
    return;
}

void classic(int *s, int *len, int N)
{
    int step = N;
    (*len) = 0;
    while(step > 0)
    {
        s[*len] = step;
        (*len)++;
        step = step / 2;
    }
    return;
}

void hibbard(int *s, int *len, int N)
{
    int i = 1;
    (*len) = 0;
    while(true)
    {
        int step = pow(2, i) - 1;
        if(step > N)
        {
            break;
        }
        s[*len] = step;
        (*len)++;
        i++;
    }
    for(int i = 0; i < (*len) / 2; ++i)
    {
        std::swap(s[i], s[(*len) - 1 - i]);
    }
    return;
}

void fibonacci(int *s, int *len, int N)
{
    int f1 = 1, f2 = 2;
    (*len) = 0;
    s[*len] = f1;
    (*len)++;
    while(f2 <= N)
    {
        s[*len] = f2;
        (*len)++;
        int temp = f2;
        f2 = f1 + f2;
        f1 = temp;
    }
    for(int i = 0; i < (*len) / 2; ++i)
    {
        std::swap(s[i], s[(*len) - 1 - i]);
    }
    return;
}

int shell_sort(int *arr, int N, int *s, int len)
{
    int swapcount = 0;
    for(int k = 0; k < len; ++k)
    {
        for(int i = s[k]; i < N; ++i)
        {
            for(int j = i; j >= s[k] && arr[j] < arr[j - s[k]]; j -= s[k])
            {
                std::swap(arr[j], arr[j - s[k]]);
                ++swapcount;
            }
        }
    }
    return swapcount;
}

bool check(int *arr, int N)
{
    for(int i = 0; i < N - 1; ++i)
    {
        if(arr[i] > arr[i + 1])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int swapcount;
    for(int N = 100; N <= 500100; N += 1000)
    {
        int *arr = new int[N];
        gen(arr, N);

        int *s = new int[N / 10];
        int len = 0;
        classic(s, &len, N);
        hibbard(s, &len, N);
        fibonacci(s, &len, N);
        
        auto begin = std::chrono::steady_clock::now();
        swapcount = shell_sort(arr, N, s, len);
        auto end = std::chrono::steady_clock::now();

        if(check(arr, N) == false)
        {
            delete[] s;
            delete[] arr;
            break;
        }
        
        auto time_span = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
        std::cout << N << " " << time_span.count() << " " << swapcount << std::endl;

        delete[] s;
        delete[] arr;
    }
    return 0;
}
