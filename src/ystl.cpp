#include "ystl.h"

template <typename T>
ostream& operator<<(ostream& os, const YAMENode<T>& node)
{
	if (node == NULL)
	{
		os << "NULL" << endl;
		return os;
	}

	os << value << endl;
	return os;
}

template <typename T>
YAMEList<T>::YAMEList()
{
	first = nullptr;
	last = nullptr;
	list_size = 0;
}

template <typename T>
YAMEList<T>::~YAMEList()
{
	cout << "YAMEList Destructor" << endl;
	

	YAMENode<T>* temp;
	while (first != nullptr)
	{
		temp = first->GetNext();
		delete first;
		first = temp;
	}

	first = nullptr;
	last = nullptr;
}

template <typename T>
bool YAMEList<T>::empty() const
{
	return list_size == 0 ? true : false;
}


template <typename T>
size_t YAMEList<T>::size() const
{
	return list_size;
}

template <typename T>
T& YAMEList<T>::front()
{
	return first->GetValue();
}

/*
template <typename T>
T YAMEList<T>::front() const
{
	return first->GetValue();
}
*/

template <typename T>
T& YAMEList<T>::back()
{
	return last->GetValue();
}

template<typename T>
void assign(size_t n, const T& val)
{
	for (int i = 0; i < n; i++)
	{
		push_back(val);
	}
}

template <typename T>
void YAMEList<T>::push_back(T& element)
{
	if (first == nullptr) //ù ��尡 ���������̸�
	{
		first = new YAMENode<T>(element); 
		//���� ��� �����ϰ� first�� ����Ʈ�ϵ����Ѵ�.

		last = first;
		//ù ����̱⶧���� first�� last�� ����.

	}
	else { //ù ��Ұ� ������ �����̸�

		YAMENode<T>* oldLastNode = last;
		//�� �����Ͱ� last�� �ּҸ� �����صд�.

		last = new YAMENode<T>(element);
		//last�� ���ο� ��带 �����Ѵ�.

		oldLastNode->SetNext(last);
		//�� ����� ���� ���� ���ο� last ����̰�

		last->SetPrev(oldLastNode);
		//�ݴ�� �� ����� ���� ���� �� last ����̴�.

	}

	list_size++;
	//ũ�Ⱑ �þ��.
}

template <typename T>
void YAMEList<T>::push_back(const T& element)
{
	if (first == nullptr)
	{
		first = new YAMENode<T>(element);
		last = first;

	}
	else {

		YAMENode<T>* oldLastNode = last;

		last = new YAMENode<T>(element);

		oldLastNode->SetNext(last);
		last->SetPrev(oldLastNode);

	}

	list_size++;
}

template <typename T>
void YAMEList<T>::pop_back()
{
	YAMENode<T>* temp;

	temp = last->GetPrev();
	//�ӽ� ��� �����Ͱ� last�� ������� �ּҸ� ������ �ִ´�.

	delete last;
	//��Ʈ�� ��������.

	last = temp;
	//���ο� ��Ʈ�� �ڿ��� �ι�° last����, temp�� ����Ǿ��ִ�
	//����̴�.

	list_size--;
	//���̰� �پ���.

	if (list_size == 0)
		first = last;

	//first = last��� �ϱ� ������ ��ǻ� nullptr�̴�.
}


