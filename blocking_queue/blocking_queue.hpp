//
// Created by HANYOUNG PARK on 4/11/21.
//

#ifndef BLOCKING_QUEUE_BLOCKING_QUEUE_HPP
#define BLOCKING_QUEUE_BLOCKING_QUEUE_HPP

#include <queue>
#include <boost/thread.hpp>

/**
 * Thread-Safe Queue
 * Don't mix use between [front, pop] and [poll]. Even it's not crushed,
 * it can't be guaranteed that the front is correct.
 * @tparam T
 */
template<typename T>
class blocking_queue {
public:
    [[nodiscard]] bool empty() const {
        return q.empty();
    }

    void push(T val) {
        mutex.lock();
        q.push(val);
        mutex.unlock();
    }

    void pop() {
        mutex.lock();
        q.pop();
        mutex.unlock();
    }

    T front() const {
        return q.front();
    }

    T poll() {
        mutex.lock();
        T ret = q.front();
        q.pop();
        mutex.unlock();
        return ret;
    }

private:
    std::queue<T> q;
    boost::mutex mutex;
};


#endif //BLOCKING_QUEUE_BLOCKING_QUEUE_HPP
