#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <ostream>
#include <stdexcept>
#include "Dict.h"
#include "TableEntry.h"

#include "../../P1/PRA_2526_P1/ListLinked.h"

template <typename V>
class HashTable: public Dict<V> {

    private:
        int n;
	int max;
	ListLinked<TableEntry<V>>* table;

	int h(std::string key) {
		int sum = 0;
		for(char c:key){
			sum += int(c);
		}

		return sum % max;
	}

    public:
        HashTable(int size){
		table = new ListLinked<TableEntry<V>>[size];
		n = 0;
		max = size;
	}

	~HashTable(){
		delete[] table;
	}

	int capacity() {
		return max;
	}

	friend std::ostream& operator<<(std::ostream &out, const HashTable<V> &th){
		out << "HashTable [entries: " << th.entries();
		out << ", capacity: " << th.capacity() << "]" << std::endl;
		out << "==============" << std::endl << std::endl;

		for (int i = 0; i < th.max; i++) {
			out << "== Cubeta " << i << " ==" << std::endl << std::endl;
			out << th.table[i] << std::endl << std::endl;
		}
		out << "==============" << std::endl;

		return out;
	}

	V operator[](std::string key){
		for (int i = 0; i < n; i++) {
			int pos = table[i].search(key);
			if (pos != -1){
				return table[i][pos].value;
			}
		}
		throw std::runtime_error("Key '" + key + "' not found");
	}
        
};

#endif
