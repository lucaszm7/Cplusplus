#include <iostream>

#define MAX_NAME 256
#define TABLE_SIZE 10


struct Person
{
	char name[MAX_NAME];
	int age;
};

std::ostream& operator << (std::ostream& out, const Person& p)
{
	out << p.name;
	return out;
}

template <typename T>
class Hash
{
private:
	T* hash_table[TABLE_SIZE];
	#define DELETED_NODE (T*)(0xFFFFFFFFFFFFFFFFUL)
public:

	Hash()
	{
		for (int i = 0; i < TABLE_SIZE; ++i)
			hash_table[i] = nullptr;
	}

	~Hash()
	{
		for (int i = 0; i < TABLE_SIZE; ++i)
			if (hash_table[i] != nullptr && hash_table[i] != DELETED_NODE) delete hash_table[i];
	}

	bool insert(T* dta)
	{
		if (dta == nullptr) 
			return false;

		unsigned int index = hash_function(dta->name);

		for (int i = 0; i < TABLE_SIZE; ++i)
		{
			unsigned int nTry = index + i % TABLE_SIZE;
			if (hash_table[nTry] == nullptr || hash_table[nTry] == DELETED_NODE)
			{
				hash_table[nTry] = dta;
				return true;
			}
		}
		return false;
	}

	T* remove(const std::string& key)
	{ 
		unsigned int index = hash_function(key);
		for (int i = 0; i < TABLE_SIZE; ++i)
		{
			unsigned int nTry = (index + i) % TABLE_SIZE;
			if (hash_table[nTry] == nullptr) return nullptr;
			if (hash_table[nTry] == DELETED_NODE) continue;
			if (hash_table[nTry] != nullptr && hash_table[nTry]->name == key)
			{
				T* value = hash_table[nTry];
				hash_table[index] = DELETED_NODE;
				return value;
			}
				return hash_table[nTry];
		}
		return nullptr;
	}

	T* lookUp(const std::string& key)
	{
		unsigned int index = hash_function(key);
		for (int i = 0; i < TABLE_SIZE; ++i)
		{
			unsigned int nTry = (index + i) % TABLE_SIZE;
			if (hash_table[nTry] == nullptr) return nullptr;
			if (hash_table[nTry] == DELETED_NODE) continue;
			if (hash_table[nTry] != nullptr && hash_table[nTry]->name == key)
				return hash_table[nTry];
		}
		return nullptr;
	}

	unsigned int hash_function(const std::string& name) const
	{
		unsigned int hash_value = 0;
		for (int i = 0; i < name.size(); ++i)
		{
			hash_value += name[i];
			hash_value = (hash_value * name[i]) % TABLE_SIZE;
		}
		return hash_value;
	}

	friend auto operator<<(std::ostream& out, Hash<T> const& hash) -> std::ostream& {
		for (int i = 0; i < TABLE_SIZE; ++i)
		{
			if (hash.hash_table[i] == nullptr ) out << i << "\t---\n";
			else if (hash.hash_table[i] == DELETED_NODE) out << i << "\t--- DELETED ---\n";
			else out << i << "\t" << *(hash.hash_table[i]) << "\n";
		}
		return out;
	}
};


int main()
{
	Hash<Person> hash;
	Person* p0 = new Person{ "Lucas" };
	Person* p1 = new Person{ "Joao" };
	Person* p2 = new Person{ "Maria" };
	Person* p3 = new Person{ "Guiga" };
	Person* p4 = new Person{ "Angol" };
	Person* p5 = new Person{ "Carla" };
	Person* p6 = new Person{ "Raiza" };
	Person* p7 = new Person{ "Nanda" };
	Person* p8 = new Person{ "Pavas" };


	hash.insert(p0);
	hash.insert(p1);
	hash.insert(p2);
	hash.insert(p3);
	hash.insert(p4);
	hash.insert(p5);
	hash.insert(p6);
	hash.insert(p7);
	hash.insert(p8);


	Person* l = hash.lookUp("Lucas");
	if (l != nullptr) std::cout << *l << "\n";
	
	Person* c = hash.lookUp("Carla");
	if (c != nullptr) std::cout << *c << "\n";
	else std::cout << "Not Found" << "\n";

	hash.remove("Lucas");

	std::cout << hash;
	
	std::cin.get();
	return 0;
}