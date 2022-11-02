/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** SafeQueue
*/

#pragma once

#include <iostream>
#include <mutex>
#include <optional>
#include <queue>
#include <thread>

/**
 * @brief SafeQueue class
 *
 */
class NonEmptyQueue : public std::exception {
  public:
    /// @brief Constructor
    /// @param msg to display
    explicit NonEmptyQueue(std::string msg)
    {
        _what = std::move(msg);
    }

    /// @brief Exception what
    /// @return Error message
    const char *what() const noexcept override
    {
        return _what.c_str();
    }

  private:
    /// @brief Error message string
    std::string _what;
};

/// @brief Template class for a thread-safe queue.
/// @tparam T Type of the queue.
template <typename T>
/// @brief Thread-safe queue.
/// @tparam T Type of the queue.
class SafeQueue {
  public:
    /// @brief Default constructor
    SafeQueue() = default;

    /// @brief Move constructor
    /// @param other SafeQueue
    SafeQueue(SafeQueue<T> &&other) noexcept(false)
    {
        std::lock_guard<std::mutex> lock(_mutex);
        if (!empty()) {
            throw NonEmptyQueue("Moving into a non-empty queue");
        }
        _queue = std::move(other._queue);
    }

    /// @brief Destructor
    virtual ~SafeQueue() noexcept(false)
    {
        std::lock_guard<std::mutex> lock(_mutex);
        if (!empty()) {
            throw NonEmptyQueue("Destroying a non-empty queue");
        }
    }

    /// @brief Getter for SafeQueue size
    /// @return unsigned long SafeQueue size
    unsigned long getSize() const
    {
        std::lock_guard<std::mutex> lock(_mutex);
        return _queue.size();
    }

    /// @brief Removes the next element in the queue, effectively reducing its size by one.
    /// @return std::optional<T> The value of the element that was removed from the queue.
    std::optional<T> pop()
    {
        std::lock_guard<std::mutex> lock(_mutex);
        if (_queue.empty()) {
            return {};
        }
        T tmp = _queue.front();
        _queue.pop();
        return tmp;
    }

    /**
     * @brief Pushes the given element value onto the queue.
     * 
     * @param item Element to push
     */
    void push(const T &item)
    {
        std::lock_guard<std::mutex> lock(_mutex);
        _queue.push(item);
    }

  private:
    /// @brief Private variable for the queue.
    std::queue<T> _queue;
    /// @brief Private variable for mutex.
    mutable std::mutex _mutex;

    /// @brief Private method to check if the queue is empty.
    /// @return bool True if the queue is empty, false otherwise.
    bool empty() const
    {
        return _queue.empty();
    }
};
