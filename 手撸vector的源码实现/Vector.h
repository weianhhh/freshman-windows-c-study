#pragma once
#include <iostream>
using namespace std;
namespace yazi {
	namespace stl {
		template <typename T>
		class Vector
		{
		public:
			Vector();
			~Vector();

			void push_back(const T& vlaue);
			void pop_back();
			int size() const;
			int capacity() const;
			void show() const;
			void reserve(int size);

		private:
			T* m_data;
			int m_size;
			int m_capacity;
		};
		template <typename T>
		Vector<T>::Vector() : m_data(nullptr), m_size(0), m_capacity(0)
		{
		}

		template <typename T>
		Vector<T>::~Vector()
		{
			if (m_data != nullptr)
			{
				delete[] m_data;
				m_data = nullptr;
			}
			m_size = 0;
			m_capacity = 0;
		}

		template <typename T>
		void Vector<T>::push_back(const T& value)
		{
			if (m_size < m_capacity)
			{
				m_data[m_size] = value;
				m_size++;
				return;
			}
			if (m_capacity == 0)
			{
				m_capacity = 1;
			}
			else
			{
				m_capacity *= 2;
			}
			T* data = new T[m_capacity];
			for (int i = 0; i < m_size; i++)
			{
				data[i] = m_data[i];
			}
			if (m_data != nullptr)
			{
				delete[] m_data;
				m_data = nullptr;
			}
			m_data = data;
			m_data[m_size] = value;
			m_size++;
		}

		template <typename T>
		void Vector<T>::pop_back()
		{
			if (m_size > 0)
			{
				m_size--;
			}
		}

		template <typename T>
		int Vector<T>::size() const
		{
			return m_size;
		}

		template <typename T>
		int Vector<T>::capacity() const
		{
			return m_capacity;
		}
		template <typename T>
		void Vector<T>::show() const
		{
			std::cout << "size=" << size() << "capacity=" << capacity() << std::endl;
			for (int i = 0; i < m_size; i++)
			{
				std::cout << m_data[i] << ",";
			}
			std::cout << std::endl;
		}
		template <typename T>
		void Vector<T>::reserve(int size)
		{
			if (m_capacity >= size)
			{
				return;
			}
			while(m_capacity < size)
			{
				if (m_capacity == 0)
				{
					m_capacity = 1;
				}
				else
				{
					m_capacity *= 2;
				}
			}
			T* data = new T[m_capacity];
			for (int i = 0; i < m_size; i++)
			{
				data[i] = m_data[i];
			}
			if (m_data != nullptr)
			{
				delete [] m_data;
				m_data = nullptr;
			}
			m_data = data;
		}
		
	}


}