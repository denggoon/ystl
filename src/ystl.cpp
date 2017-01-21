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
	if (first == nullptr) //첫 노드가 널포인터이면
	{
		first = new YAMENode<T>(element); 
		//새로 노드 생성하고 first가 포인트하도록한다.

		last = first;
		//첫 요소이기때문에 first와 last가 같다.

	}
	else { //첫 요소가 갖춰진 상태이면

		YAMENode<T>* oldLastNode = last;
		//새 포인터가 last의 주소를 저장해둔다.

		last = new YAMENode<T>(element);
		//last는 새로운 노드를 맞이한다.

		oldLastNode->SetNext(last);
		//옛 노드의 다음 노드는 새로운 last 노드이고

		last->SetPrev(oldLastNode);
		//반대로 새 노드의 이전 노드는 옛 last 노드이다.

	}

	list_size++;
	//크기가 늘어났다.
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
	//임시 노드 포인터가 last의 이전노드 주소를 가지고 있는다.

	delete last;
	//라스트는 지워진다.

	last = temp;
	//새로운 라스트는 뒤에서 두번째 last이자, temp에 저장되어있던
	//노드이다.

	list_size--;
	//길이가 줄었다.

	if (list_size == 0)
		first = last;

	//first = last라고 하긴 했으나 사실상 nullptr이다.
}


