#ifndef BSNODE_H
#define BSNODE_H

#include <ostream>

template <typename T>
class BSNode {
	public:
		T elem;
		BSNode<T>* left;
		BSNode<T>* right;

};

#endif
