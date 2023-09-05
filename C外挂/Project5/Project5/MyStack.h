#pragma once
template<class T>
class MyStack {
	T* pBuff;
	size_t len;
public:
	MyStack() { pBuff = nullptr; len = 0; }
	~MyStack() { if (pBuff) delete[] pBuff; pBuff = nullptr; len = 0; }
	void push(const T& data);
	T getTop() {
		return pBuff[len - 1];
	}
	void pop() {
		len--;
	}
	bool isEmpty() {
		return (len == 0);
	}
};
template<class T>
void MyStack<T>::push(const T& data) {
	T* pTemp = new T[len + 1];
	if (pBuff) {
		memcpy(pTemp, pBuff, sizeof(T) * len);
		delete[] pBuff;
	}
	pBuff = pTemp;
	pBuff[len++] = data;

}
