#pragma once
#include <iostream>
using namespace std;

template <typename T>
class YAMENode //노드기반
{
private:
	T value; //어떠한 자료형이던 커버하는 템플릿
	YAMENode<T>* next; //다음 노드
	YAMENode<T>* prev; //이전 노드

public:
	YAMENode(T _value = 0) : value(_value)
	{
		next = nullptr;
		prev = nullptr;
		//최초 생성시 다음, 이전을 가리키지 않음
	}

	T GetValue() const
	{
		return value;
		//YAMEList에서 참조해야하므로
	}

	T& GetValue()
	{
		return value;
	}

	YAMENode<T>*& GetNext()
	{
		return next;
		//역시 YAMElist에서 참조할일이 있으나 private 이므로
	}

	YAMENode<T>*& GetPrev()
	{
		return prev;
		//역시 YAMElist에서 참조할일이 있으나 private 이므로
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