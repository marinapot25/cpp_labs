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

int forward_step(int *arr, int begin_idx, int end_idx)
{
    int swapcount = 0;
    for(int i = begin_idx; i < end_idx - 1; ++i)
    {
        if(arr[i] > arr[i + 1])
        {
            std::swap(arr[i], arr[i + 1]);
            ++swapcount;
        }
    }
    return swapcount;
}

int backward_step(int *arr, int begin_idx, int end_idx)
{
    int swapcount = 0;
    for(int i = end_idx; i > begin_idx + 1; --i)
    {
        if(arr[i] < arr[i - 1])
        {
            std::swap(arr[i], arr[i - 1]);
            ++swapcount;
        }
    }
    return swapcount;
}

int shaker_sort(int *arr, int begin_idx, int end_idx)
{
    int swapcount = 0;
    while(begin_idx < end_idx)
    {
        swapcount += forward_step(arr, begin_idx, end_idx);
        --end_idx;
        swapcount += backward_step(arr, begin_idx, end_idx);
        ++begin_idx;
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
    for(int N = 100; N <= 90100; N += 1000)
    {
        int *arr = new int[N];
        gen(arr, N);

        auto begin = std::chrono::steady_clock::now();
        swapcount = shaker_sort(arr, 0, N - 1);
        auto end = std::chrono::steady_clock::now();

        if(check(arr, N) == false)
        {
            delete[] arr;
            break;
        }
        
        auto time_span = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
        std::cout << N << " " << time_span.count() << " " << swapcount << std::endl;

        delete[] arr;
    }
    return 0;
}