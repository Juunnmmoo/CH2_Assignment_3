#include <iostream>
#include <algorithm>

using namespace std;

template <typename T>
class SimpleVector
{
private:
	T* _Data;
	int _CurrentSize;
	int _CurrentCapacity;

	void resize(int _newCapacity)
	{
		if (_newCapacity <= _CurrentCapacity)
			return;

		T* newData = new T[_newCapacity];
		
		for (int i = 0; i < _CurrentSize; i++)
			newData[i] = _Data[i];

		delete _Data;
		_Data = newData;
		_CurrentCapacity = _newCapacity;
	}

public:
	SimpleVector()
		: _Data(new T[10])
		, _CurrentSize(0)
		, _CurrentCapacity(10)
	{
		
	}
	SimpleVector(int _index)
		: _Data(new T[_index])
		, _CurrentSize(0)
		, _CurrentCapacity(_index)
	{
	}

	SimpleVector(const SimpleVector& _other)
		: _Data(new T[_other.capacity()])
		, _CurrentSize(_other.size())
		, _CurrentCapacity(_other.capacity())
	{
		for (int i = 0; i < _CurrentSize; i++)
		{
			_Data[i] = _other[i];
		}

	}
	
	~SimpleVector()
	{
		delete _Data;
		_Data = nullptr;
	}

	T& operator[](int _index) 
	{
		if (_index >= _CurrentSize)
			throw out_of_range("Error");

		return _Data[_index];
	}

	const T& operator[](int _index) const
	{
		if (_index >= _CurrentSize)
			throw out_of_range("Error");

		return _Data[_index];
	}

	void push_back(const T& _data)
	{
		if (_CurrentSize >= _CurrentCapacity)
		{
			resize(_CurrentSize + 5);
		}

		_Data[_CurrentSize] = _data;
		_CurrentSize++;
	}

	void pop_back()
	{
		if (_CurrentSize <= 0)
			return;

		_CurrentSize--;
	}

	int size() const
	{
		return _CurrentSize;
	}

	int capacity() const
	{
		return _CurrentCapacity;
	}

	void sortData()
	{
		sort(_Data, _Data + _CurrentSize);
	}
};




int main(void)
{

	SimpleVector<int> new_int(5);
	new_int.push_back(5);
	new_int.push_back(4);
	new_int.push_back(3);
	new_int.push_back(2);
	new_int.push_back(1);
	new_int.sortData();

	new_int.push_back(8);
	new_int.push_back(7);
	new_int.push_back(6);



	for (int i = 0; i < new_int.size(); i++)
	{
		cout << new_int[i] << " ";
	}

	cout << endl;
	cout << new_int.size() << endl;
	cout << new_int.capacity() << endl;


	SimpleVector<int> temp_int(new_int);

	for (int i = 0; i < temp_int.size(); i++)
	{
		cout << temp_int[i] << " ";
	}

	cout << endl;
	cout << temp_int.size() << endl;
	cout << temp_int.capacity() << endl;

	return 0;
}