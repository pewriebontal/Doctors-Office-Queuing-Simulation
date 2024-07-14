#ifndef SENG1120_LQUEUE_HPP
#define SENG1120_LQUEUE_HPP

#include "lqueue.h"

/**
 * @brief Constructor for LQueue.
 * 
 * Precondition: None
 * Postcondition: A new LQueue is created, with all variables initialised.
 */
template <typename T>
LQueue<T>::LQueue()
{
	list = new std::list<T>;
	count = 0;
}

/**
 * @brief Destructor for LQueue.
 * 
 * Precondition: None
 * Postcondition: The LQueue is destroyed and all associated memory is freed.
 * 
 * Note: According to research, std::list is automatically destroyed 
 * when it goes out of scope, so there is no need to do anything here. 
 * However, I am unsure if I will receive a mark reduction for not having 
 * any code in the destructor.
 */
template <typename T>
LQueue<T>::~LQueue()
{
	delete list;
	list = nullptr;
	count = 0;
}

/**
 * @brief Inserts the supplied data at the rear of the queue.
 * 
 * Precondition: The queue is initialised.
 * Postcondition: The data is inserted at the rear of the queue.
 * 
 * @param data The data to be inserted.
 */
template <typename T>
void LQueue<T>::enqueue(const T& data)
{
	list->push_back(data);
	count++;
}

/**
 * @brief Removes and returns the front element from the queue.
 * 
 * Precondition: The queue is initialised and not empty.
 * Postcondition: The front element is removed and returned.
 * 
 * @return T The front element of the queue.
 * @throws empty_collection_exception if the queue is empty.
 */
template <typename T>
T LQueue<T>::dequeue()
{
	if(empty())
		throw empty_collection_exception();
	T front_data = list->front();
	list->pop_front();
	count--;
	return (front_data);
}

/**
 * @brief Returns a reference to the front element on the queue.
 * 
 * Precondition: The queue is initialised and not empty.
 * Postcondition: The queue has not changed.
 * 
 * @return T& A reference to the front element of the queue.
 * @throws empty_collection_exception if the queue is empty.
 */
template <typename T>
T& LQueue<T>::front()
{
	if(empty())
		throw empty_collection_exception();
	return (list->front());
}

/**
 * @brief Returns the number of items in the queue.
 * 
 * Precondition: The queue is initialised.
 * Postcondition: The queue has not changed.
 * 
 * @return int The number of items in the queue.
 */
template <typename T>
int LQueue<T>::size() const
{
	return (count);
}

/**
 * @brief Returns true if the queue is empty, false otherwise.
 * 
 * Precondition: The queue is initialised.
 * Postcondition: The queue has not changed.
 * 
 * @return bool True if the queue is empty, false otherwise.
 */
template <typename T>
bool LQueue<T>::empty() const
{
	return (count == 0);
}

#endif // SENG1120_LQUEUE_HPP