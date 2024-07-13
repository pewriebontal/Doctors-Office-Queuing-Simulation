#ifndef SENG1120_LQUEUE_HPP
#define SENG1120_LQUEUE_HPP

#include "lqueue.h"

template <typename T>
LQueue<T>::LQueue()
{
    list = new std::list<T>;
    count = 0;
}

template <typename T>
LQueue<T>::~LQueue()
{
    delete list;
    list = NULL;
    count = 0;
}

template <typename T>
void LQueue<T>::enqueue(const T &data)
{
    list->push_back(data);
    count++;
}

template <typename T>
T LQueue<T>::dequeue()
{
    if (empty())
        throw empty_collection_exception();
    T front_data = list->front();
    list->pop_front();
    count--;
    return (front_data);
}

template <typename T>
T &LQueue<T>::front()
{
    if (empty())
        throw empty_collection_exception();
    return (list->front());
}

template <typename T>
int LQueue<T>::size() const
{
    return (count);
}

template <typename T>
bool LQueue<T>::empty() const
{
    return (count == 0);
}

#endif // SENG1120_LQUEUE_HPP