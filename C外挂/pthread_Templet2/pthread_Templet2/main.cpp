#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <Windows.h>
using namespace std;
// ������
std::mutex mtx;

// ȫ�ֱ�����ʾ�������
std::vector<int> taskQueue;

// �̳߳��е��߳�����
const int NUM_THREADS = 4;

// ��������
void ProcessTask(int threadId) {
    while (true) {
        int task;

        // ����
        std::unique_lock<std::mutex> lock(mtx);

        // �ȴ�����
        while (taskQueue.empty()) {
            // �ͷ������ȴ���������
            // ��ʱ�����߳̿��Ի��������������������
            lock.unlock();
            Sleep(100); // ģ��ȴ�ʱ��
            lock.lock();
        }

        // ��ȡ����
        task = taskQueue.back();
        taskQueue.pop_back();

        // ����
        lock.unlock();

        // ��������
        std::cout << "Thread " << threadId << " processing task: " << task << std::endl;
    }
}

int main() {
    // �����̳߳�
    std::vector<std::thread> threads;
    for (int i = 0; i < NUM_THREADS; ++i) {
        threads.emplace_back(ProcessTask, i);
    }

    // ������񵽶���
    for (int i = 0; i < 10; ++i) {
        // ����
        std::unique_lock<std::mutex> lock(mtx);
        taskQueue.push_back(i);
    }

    // ���������߳�
    for (int i = 0; i < NUM_THREADS; ++i) {
        threads[i].join();
    }

    return 0;
}
