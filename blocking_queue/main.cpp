#include <iostream>
#include <boost/thread.hpp>
#include <boost/chrono.hpp>
#include "blocking_queue.hpp"

blocking_queue<int> bq;

void push_process(int start, int end) {
    for (int i=start; i<=end; ++i) {
        bq.push(i);
        std::cout << "+push " << i << std::endl;
        boost::this_thread::sleep_for(boost::chrono::milliseconds(100));
    }
}

void pop_process() {
    int retry = 0;
    while (retry++ < 10) {
        if (bq.empty()) {
            boost::this_thread::sleep_for(boost::chrono::milliseconds(50));
            continue;
        }
        std::cout << "-pop" << bq.front() << std::endl;
        bq.pop();
        std::cout << "-poll" << bq.poll() << std::endl;
        boost::this_thread::sleep_for(boost::chrono::milliseconds(10));
        retry = 0;
    }
}

int main() {
    boost::thread th1(push_process, 1, 10000);
    boost::thread th2(push_process, 10001, 20000);
    boost::thread th3(push_process, 20001, 30000);
    boost::thread th4(push_process, 30001, 40000);
    boost::thread th5(push_process, 40001, 50000);
    boost::thread th6(push_process, 50001, 60000);
    boost::thread th7(push_process, 60001, 70000);
    boost::thread th8(push_process, 70001, 80000);
    boost::thread th9(push_process, 80001, 90000);
    boost::thread th10(push_process, 90001, 100000);
    boost::thread th11(push_process, 100001, 110000);
    boost::thread th12(pop_process);

    th1.join();
    th2.join();
    th3.join();
    th4.join();
    th5.join();
    th6.join();
    th7.join();
    th8.join();
    th9.join();
    th10.join();
    th11.join();
    th12.join();

    return 0;
}
