/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** SafeQueue
*/

#ifndef SAFEQUEUE_HPP
#define SAFEQUEUE_HPP

#include <queue>
#include <optional>
#include <thread>
#include <mutex>
#include <iostream>

class NonEmptyQueue : public std::exception {
    public:
        explicit NonEmptyQueue(std::string msg);
        const char* what() const noexcept override;
    private:
        std::string _what;
};

template <typename T>
class SafeQueue
{
    public:
        SafeQueue() = default;
        SafeQueue(const SafeQueue<T> &) = delete;
        SafeQueue& operator=(const SafeQueue<T> &) = delete;
        SafeQueue(SafeQueue<T>&& other) noexcept(false);

        virtual ~SafeQueue() noexcept(false);
        unsigned long size() const;
        std::optional<T> pop();
        void push(const T &item);

    private:
        std::queue<T> _queue;
        mutable std::mutex _mutex;

        bool empty() const;
};

#endif //SAFEQUEUE_HPP
