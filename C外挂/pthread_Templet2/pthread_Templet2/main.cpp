#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <Windows.h>
using namespace std;
// 互斥锁
std::mutex mtx;

// 全局变量表示任务队列
std::vector<int> taskQueue;

// 线程池中的线程数量
const int NUM_THREADS = 4;

// 任务处理函数
void ProcessTask(int threadId) {
    while (true) {
        int task;

        // 加锁
        std::unique_lock<std::mutex> lock(mtx);

        // 等待任务
        while (taskQueue.empty()) {
            // 释放锁并等待条件满足
            // 此时其他线程可以获得锁并向队列中添加任务
            lock.unlock();
            Sleep(100); // 模拟等待时间
            lock.lock();
        }

        // 获取任务
        task = taskQueue.back();
        taskQueue.pop_back();

        // 解锁
        lock.unlock();

        // 处理任务
        std::cout << "Thread " << threadId << " processing task: " << task << std::endl;
    }
}

int main() {
    // 创建线程池
    std::vector<std::thread> threads;
    for (int i = 0; i < NUM_THREADS; ++i) {
        threads.emplace_back(ProcessTask, i);
    }

    // 添加任务到队列
    for (int i = 0; i < 10; ++i) {
        // 加锁
        std::unique_lock<std::mutex> lock(mtx);
        taskQueue.push_back(i);
    }

    // 唤醒所有线程
    for (int i = 0; i < NUM_THREADS; ++i) {
        threads[i].join();
    }

    return 0;
}
