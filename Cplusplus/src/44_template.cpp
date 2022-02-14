#include <iostream>

// template<typename T, int N> class Array
template<class T, int N> class Array
{
private:
	T m_Array[N];
public:
	int GetSize()
	{
		return N;
	}
};

template<typename T>
struct node
{
	T dta;
	node<T>* next;

	node()
	{
		this->next = nullptr;
	}

	node(T dta)
	{
		this->dta = dta;
		this->next = nullptr;
	}

};

template<typename DT>
class ListaEncadeada
{
private:
	node<DT>* first;
public:
	ListaEncadeada()
	{
		this->first = nullptr;
	}

	friend inline std::ostream& operator << (std::ostream& out, ListaEncadeada<DT>& l);

	void add(DT dta)
	{
		if (this->first == nullptr)
		{
			node<DT>* nd = new node<DT>(dta);
			this->first = nd;
		}
		else
		{
			node<DT>* aux = this->first;
			for (; aux->next != nullptr; aux = aux->next);
			node<DT>* nd = new node<DT>(dta);
			aux->next = nd;
		}
	}

	void list()
	{
		if (this->first == nullptr) return;

		node<DT>* aux = this->first;
		for (; aux != nullptr; aux = aux->next)
			std::cout << aux->dta << std::endl;
	}

};

template <typename Data>
void Print(Data e)
{
	std::cout << e << std::endl;
}

int templates()
{
	ListaEncadeada<int> numeros;
	numeros.add(10);
	numeros.add(15);
	numeros.add(20);

	numeros.list();

	Array<float, 5> arr;

	std::cin.get();

	return 0;
}