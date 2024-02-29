#include <iostream>
#pragma once

typedef int value_type;

class CircularBuffer {
private:
	value_type* buffer;
	int actual_length;
	int cont_length;
	class iterator : public std::iterator<std::output_iterator_tag, value_type> {
	private:
		CircularBuffer& container_;
		size_t index_{ 0 };
		bool first_step;
	public:
		value_type& operator*() const;
		iterator& operator+(int N);
		iterator& operator++();
		iterator operator++(int);
		bool operator!=(const iterator& right) const;
		bool operator==(const iterator& right) const;
		iterator(CircularBuffer& container, size_t index_ = 0);
	};
public:
	int start_val, end_val;
	class iterator;
	CircularBuffer();
	CircularBuffer(const CircularBuffer& cb);
	~CircularBuffer();
	///������������ ����� �������� �������.
	///Designs Circular Buffer with given capacity
	CircularBuffer(int capacity);
	//������������ ����� �������� �������, ������� ��������� ��� ��������� elem.
	///Designs Circular Buffer with given capacity and fills elem into every node
	CircularBuffer(int capacity, const value_type& elem);

	//������ �� �������. �� ��������� ������������ �������.
	///Provides access by index without checking correctness of given index
	value_type& operator[](int i);
	const value_type& operator[](int i) const;

	//������ �� �������. ������ ������� ���������� � ������ ��������� �������.
	///Provides access by index safely(with checking correctness of given index)
	value_type& at(int i);
	const value_type& at(int i) const;
	iterator begin();
	iterator end();
	//Pointer to first element
	value_type& front(); //������ �� ������ �������.
	//Pointer to last element
	value_type& back();  //������ �� ��������� �������.
	const value_type& front() const;
	const value_type& back() const;

	int give_index_in_circle(int index);

	//������������ - �������� ��������� ����� ���, ��� ��� ������ �������
	//������������ � ������ �������������� ������. ���������� ��������� 
	//�� ������ �������.
	//Linearize circular buffer(buffer will be rotated so that the first element will be literally the first)
	value_type* linearize();
	//���������, �������� �� ����� ���������������.
	//Method for checking buffer linearization
	bool is_linearized() const;
	//�������� ����� ���, ��� �� �������� ������� �������� ������� 
	//� �������� new_begin.
	//Rotates buffer so that the element with index 'new_begin' will be the first
	void rotate(int new_begin);
	//���������� ���������, ���������� � ������.
	//Size of buffer(number of elements contained in the buffer)
	int size() const;
	bool empty() const;
	//true, ���� size() == capacity().
	//Method for checking buffer fullness
	bool full() const;
	//���������� ��������� ����� � ������.
	//Returns number of free nodes of buffer
	int reserve() const;
	//������� ������
	//Returns buffer capacity
	int capacity() const;

	void set_capacity(int new_capacity);
	//�������� ������ ������.
	//� ������ ����������, ����� �������� ����������� ��������� item.
	//Method for changing buffer size, if buffer will become bigger new nodes will contain 'item'
	void resize(int new_size, const value_type& item = value_type());
	//�������� ������������.
	//Assigment operator
	CircularBuffer& operator=(const CircularBuffer& cb);
	//���������� ���������� ������ � ������� cb.
	//Method for swapping buffers contents
	void swap(CircularBuffer& cb);

	//��������� ������� � ����� ������. 
	//���� ������� ������ ������ ����� ��� �������, �� ��������������
	//������ ������� ������ (�.�., ����� �����������). 
	//Push element in the back of buffer(if buffer is full, item will be placed at the beginning of the buffer)
	void push_back(const value_type& item = value_type());
	//��������� ����� ������� ����� ������ ��������� ������. 
	//���������� push_back, ����� ���������� ��������� ������� ������.
	//Works exactly the same as the push_back but item will be placed at the beginning of the buffer(if buffer is full, item will be placed at the end of the buffer)
	void push_front(const value_type& item = value_type());
	//������� ��������� ������� ������.
	//Removes the last element of buffer
	void pop_back();
	//������� ������ ������� ������.
	//Removes the first element of buffer
	void pop_front();

	//��������� ������� item �� ������� pos. ������� ������ �������� ����������.
	//Insert element item by the index pos. Buffer capacity remains unchanged
	void insert(int pos, const value_type& item = value_type());
	//������� �������� �� ������ � ��������� [first, last).
	//Removes buffer's elements in interval [first, last)
	void erase(int first, int last);
	//������� �����.
	//Clears the buffer
	void clear();

	friend bool operator==(const CircularBuffer& a, const CircularBuffer& b);
	friend bool operator!=(const CircularBuffer& a, const CircularBuffer& b);
};

