#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <cmath>

class MyClass
{
public:
	MyClass() = default;
	MyClass(int val):val_(val){}
	MyClass(double val):val_(::ceil(val)){}
	~MyClass() = default;

	void SetVal(int val) { val_ = val; }
	void SetVal(double val) { val_ = ::ceil(val); }
	int GetVal()const { return val_; }

	MyClass& operator=(const MyClass& other) = default;
	bool operator<(const MyClass& other)const
	{

		return val_ <other.val_;

	}




private:
	int val_;
};

int main()
{
	std::vector<MyClass> collection;
	collection.reserve(15);
	for (size_t i = 0; i < collection.capacity(); i++)
	{
		double tmp = 1 + ::rand() % 10;
		tmp += 1. / (1 + ::rand() % 10);
		//в переменную tmp помещаем число от 1 до 10
		//с дробной частью от 0.1 до 1.0

		collection.emplace_back(tmp);
	}

	for (size_t i = 0; i < collection.size(); i++)
	{
		std::cout << collection[i].GetVal() << ' ';
	}

	//std::sort(collection.begin(), collection.end());
	std::cout << "\n";
	//for (size_t i = 0; i < collection.size(); i++)
	//{
		//std::cout << collection[i].GetVal() << ' ';
	//}

	//чтобы класс мог быть помещен в set он должен сравниваться на < 

	std::multiset<MyClass> sortedCollection;


	//std::set - хранит элементы в отсрортированном виде, только уникальные элементы

	for (auto& el : collection)
	{
		sortedCollection.insert(el);
	}

	for (auto& el : sortedCollection)
	{
		std::cout << el.GetVal() << ' ';
	}


	return 0;

}

