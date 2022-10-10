/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
**  SafeQueue
*/

#include "SafeQueue.hpp"

NonEmptyQueue::NonEmptyQueue(std::string msg)
{
    _what = std::move(msg);
}

const char* NonEmptyQueue::what() const noexcept
{
    return _what.c_str();
}

template<typename T>
bool SafeQueue<T>::empty() const
{
    return _queue.empty();
}

template<typename T>
SafeQueue<T>::SafeQueue(SafeQueue<T> &&other) noexcept(false)
{
    std::lock_guard<std::mutex> lock(_mutex);
    if (!empty()) {
        throw NonEmptyQueue("Moving into a non-empty queue");
    }
    _queue = std::move(other._queue);
}

template<typename T>
SafeQueue<T>::~SafeQueue() noexcept(false) {
    std::lock_guard<std::mutex> lock(_mutex);
    if (!empty()) {
        throw NonEmptyQueue("Destroying a non-empty queue");
    }
}

template<typename T>
unsigned long SafeQueue<T>::getSize() const
{
    std::lock_guard<std::mutex> lock(_mutex);
    return _queue.size();
}

template<typename T>
std::optional<T> SafeQueue<T>::pop() {
    std::lock_guard<std::mutex> lock(_mutex);
    if (_queue.empty()) {
        return {};
    }
    T tmp = _queue.front();
    _queue.pop();
    return tmp;
}

template<typename T>
void SafeQueue<T>::push(const T &item) {
    std::lock_guard<std::mutex> lock(_mutex);
    _queue.push(item);
}
