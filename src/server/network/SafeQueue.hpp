/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** SafeQueue
*/

#ifndef SAFEQUEUE_HPP
#define SAFEQUEUE_HPP

#include <iostream>
#include <mutex>
#include <optional>
#include <queue>
#include <thread>

/// @brief Exception when SafeQueue is not empty.
class NonEmptyQueue : public std::exception {
  public:
    /// @brief Constructor
    /// @param msg to display
    explicit NonEmptyQueue(std::string msg);

    /// @brief Exception what
    /// @return Error message
    const char *what() const noexcept override;

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

    /// @brief Copy constructor deleted
    /// @param SafeQueue to copy
    SafeQueue(const SafeQueue<T> &) = delete;

    /// @brief Assignement constructor deleted
    /// @param SafeQueue to assign
    SafeQueue &operator=(const SafeQueue<T> &) = delete;

    /// @brief Move constructor
    /// @param Other SafeQueue
    SafeQueue(SafeQueue<T> &&other) noexcept(false);

    /// @brief Destructor
    virtual ~SafeQueue() noexcept(false);

    /// @brief Getter for SafeQueue size
    /// @return unsigned long SafeQueue size
    unsigned long getSize() const;

    /// @brief Removes the next element in the queue, effectively reducing its size by one.
    /// @return std::optional<T> The value of the element that was removed from the queue.
    std::optional<T> pop();

    /// @brief Pushes the given element value onto the queue.
    /// @param item The value of the element to push onto the queue.
    void push(const T &item);

  private:
    /// @brief Private variable for the queue.
    std::queue<T> _queue;
    /// @brief Private variable for mutex.
    mutable std::mutex _mutex;

    /// @brief Private method to check if the queue is empty.
    /// @return bool True if the queue is empty, false otherwise.
    bool empty() const;
};

#endif // SAFEQUEUE_HPP
