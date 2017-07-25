#pragma once

#include <stack>
#include <queue>
//#include <type_traits>
#include <cassert>

//用两个栈实现队列
template <typename T>
class Queue
{
public:
	Queue() = default;
	~Queue() = default;

	void appendTail(const T& node);
	T deleteHead();
private:
	std::stack<T> m_stack_one;
	std::stack<T> m_stack_two;
};

template <typename T>
void Queue<T>::appendTail(const T& node)
{
	m_stack_one.push(node);
}

template <typename T>
T Queue<T>::deleteHead()
{
	if (m_stack_two.empty())
	{
		//m_stack_two.swap(m_stack_one);
		while (!m_stack_one.empty())
		{
			T& data = m_stack_one.top();
			m_stack_one.pop();
			m_stack_two.push(data);
		}
	}

	if (m_stack_two.empty())
	{
		throw std::exception("queue is empty.");
	}

	T head = m_stack_two.top();
	m_stack_two.pop();

	return head;
}

template <typename T>
class Stack
{
public:
	Stack() = default;
	~Stack() = default;

	void appendTop(const T& node);
	T deleteTop();
private:
	std::queue<T> m_queue_one;
	std::queue<T> m_queue_two;
};

template <typename T>
void Stack<T>::appendTop(const T& node)
{
	m_queue_one.push(node);
}

template <typename T>
T Stack<T>::deleteTop()
{
	if (m_queue_two.empty())
	{
		if (m_queue_one.empty())
		{
			throw std::exception("stack is empty.");
		}

		while (m_queue_one.size() > 1)
		{
			T& data = m_queue_one.front();
			m_queue_one.pop();
			m_queue_two.push(data);
		}

		T top = m_queue_one.front();
		m_queue_one.pop();
		assert(m_queue_one.empty());

		return top;
	}
	else
	{
		if (m_queue_two.empty())
		{
			throw std::exception("stack is empty.");
		}

		while (m_queue_two.size() > 1)
		{
			T& data = m_queue_two.front();
			m_queue_two.pop();
			m_queue_one.push(data);
		}

		T top = m_queue_two.front();
		m_queue_two.pop();
		assert(m_queue_two.empty());

		return top;
	}
}

template <typename T>
class MinStack
{
public:
	MinStack() = default;
	~MinStack() = default;
public:
	void push(const T& value);
	void pop();
	const T& min() const;
private:
	std::stack<T> m_data;
	std::stack<T> m_min;
};

template <typename T>
void MinStack<T>::push(const T& value)
{
	m_data.push(value);

	if (m_min.size() == 0 || value < m_min.top())
	{
		m_min.push(value);
	}
	else
	{
		m_min.push(m_min.top());
	}
}

template <typename T>
void MinStack<T>::pop()
{
	assert(m_data.size() > 0 && m_min.size() > 0);

	m_data.pop();
	m_min.pop();
}

template <typename T>
const T& MinStack<T>::min() const
{
	assert(m_data.size() > 0 && m_min.size() > 0);

	return m_min.top();
}

bool IsPopOrder(const int* pPush, const int* pPop, int nLength)
{
	bool bPossible = false;

	if (pPush != nullptr && pPop != nullptr && nLength > 0)
	{
		const int* pNextPush = pPush;
		const int* pNextPop = pPop;

		std::stack<int> stackData;

		while (pNextPop - pPop < nLength)
		{
			while (stackData.empty() || stackData.top() != *pNextPop)
			{
				if (pNextPush - pPush >= nLength)
				{
					break;
				}

				stackData.push(*pNextPush);
				++pNextPush;
			}

			if (stackData.top() != *pNextPop)
			{
				break;
			}

			stackData.pop();
			++pNextPop;
		}

		if (stackData.empty() && pNextPop - pPop >= nLength)
		{
			bPossible = true;
		}
	}

	return bPossible;
}