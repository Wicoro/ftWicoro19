#ifndef ITERATOR_HPP
#define ITERATOR_HPP

template <typename T>
class MutantStack;

// ITERATOR
template <typename T>
class iterator {
private:
    typename MutantStack<T>::Node* _node;  // pointeur vers la node de MSTACK

public:
    iterator(typename MutantStack<T>::Node* node) : _node(node) {}

    T& operator*() { return _node->val; }
    const T& operator*() const { return _node->val; }

    iterator& operator++() {
        if (_node) _node = _node->under;
        return *this;
    }

    iterator operator++(int) {
        iterator temp = *this;
        if (_node) _node = _node->under;
        return temp;
    }

    bool operator!=(const iterator& other) const {
        return _node != other._node;
    }

    bool operator==(const iterator& other) const {
        return _node == other._node;
    }
};

#endif
