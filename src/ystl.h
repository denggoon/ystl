#pragma once
#include <iostream>
using namespace std;

template <typename T>
class YAMENode //�����
{
private:
	T value; //��� �ڷ����̴� Ŀ���ϴ� ���ø�
	YAMENode<T>* next; //���� ���
	YAMENode<T>* prev; //���� ���

public:
	YAMENode(T _value = 0) : value(_value)
	{
		next = nullptr;
		prev = nullptr;
		//���� ������ ����, ������ ����Ű�� ����
	}

	T GetValue() const
	{
		return value;
		//YAMEList���� �����ؾ��ϹǷ�
	}

	T& GetValue()
	{
		return value;
	}

	YAMENode<T>*& GetNext()
	{
		return next;
		//���� YAMElist���� ���������� ������ private �̹Ƿ�
	}

	YAMENode<T>*& GetPrev()
	{
		return prev;
		//���� YAMElist���� ���������� ������ private �̹Ƿ�
	}

	void SetNext(YAMENode<T>*& ref)
	{
		next = ref;
	}

	void SetPrev(YAMENode<T>*& ref)
	{
		prev = ref;
	}

	~YAMENode()
	{
		cout << "Value: " << value << endl;
		cout << "Node Destructor!" << endl;
	}

	friend ostream& operator<<(ostream& os, const YAMENode& node);
};

template <typename T>
class YAMEList
{
private:
	size_t list_size;
	YAMENode<T>* first;
	YAMENode<T>* last;

	YAMEList(const YAMEList& list) {}
	YAMEList& operator=(const YAMEList& list){}

public:
	YAMEList();
	~YAMEList();

	//capacity
	bool empty() const;
	size_t size() const;
	size_t max_size() const;

	//element access
	T& front();
	const T front() const;

	T& back();
	const T back() const;

	//modifiers
	void assign(size_t n, const T& val);
	void assign();

	void emplace_front();
	void push_front();
	void pop_front();
	void emplace_back();
	void push_back(const T& element);
	void push_back(T& element);
	void pop_back();
	void emplace();
	void insert();
	void erase();
	void swap();
	void resize();
	void clear();

	//operations
	void splice();
	void remove();
	void remove_if();
	void unique();
	void merge();
	void sort();
	void reverse();

	//observers
	void get_allocator();
};