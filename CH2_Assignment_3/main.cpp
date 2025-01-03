#include <iostream>

using namespace std;

template <typename T>
class SimpleVector
{
private:
	T* _Data;
	int _CurrentSize;
	int _CurrentCapacity;
	int _CurrentIndex;

public:
	SimpleVector()
		: _CurrentSize(10)
		, _CurrentCapacity(0)
		, _CurrentIndex(-1)
	{
		_Data = new T[10];
	}
	SimpleVector(int _index)
		: _CurrentSize(_index)
		, _CurrentCapacity(0)
		, _CurrentIndex(-1)
	{
		_Data = new T[_index];
	}
	~SimpleVector()
	{
		delete _Data;
	}
	T& operator[](int _index)
	{
		if (_index >= _CurrentCapacity)
			throw std::out_of_range("Index out of range.");

		return _Data[_index];
	}

	void push_back(const T& _data)
	{
		if (_CurrentCapacity > 10)
			return;

		_Data[++_CurrentIndex] = _data;
		_CurrentCapacity++;
	}

	void pop_back()
	{
		if (_CurrentCapacity < 0)
			return;

		_Data[_CurrentIndex--].~T();
		_CurrentCapacity--;
	}

	int size()
	{
		return _CurrentSize;
	}

	int capacity()
	{
		return _CurrentCapacity;
	}
};




int main(void)
{

	SimpleVector<int> new_int(5);
	new_int.push_back(1);
	new_int.push_back(2);
	new_int.push_back(3);
	new_int.pop_back();


	cout << new_int[0] << endl;
	cout << new_int.size() << endl;
	cout << new_int.capacity() << endl;



	return 0;
}