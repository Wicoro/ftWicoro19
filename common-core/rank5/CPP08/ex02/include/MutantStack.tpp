//default constructor etc (deep copy)
template <typename T>
MutantStack<T>::MutantStack() : _topNode(NULL), _size(0) {}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack& other) : _topNode(NULL), _size(other._size){
	Node	*crt_old = other._topNode;
	if (!crt_old)
		return;
	
	_topNode = new Node(crt_old->val);
	Node	*crt_new = _topNode;

	while (crt_old->under) {
		crt_old = crt_old->under;
		crt_new->under = new Node(crt_old->val);
		crt_new->under->above = crt_new;
		crt_new = crt_new->under;
	}
}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& other) {
	if (this == &other)
		return *this;

	while (_topNode) {
		pop();
	}

	Node* crt_old = other._topNode;
	if (!crt_old) {
		_topNode = NULL;
		_size = 0;
		return *this;
	}

	_topNode = new Node(crt_old->val);
	Node* crt_new = _topNode;

	while (crt_old->under) {
		crt_old = crt_old->under;
		crt_new->under = new Node(crt_old->val);
		crt_new->under->above = crt_new;
		crt_new = crt_new->under;
	}

	_size = other._size;
	return *this;
}

template <typename T>
MutantStack<T>::~MutantStack() {
    while (_topNode)
        pop();
}


//member funciton
template <typename T>
void MutantStack<T>::push(const T& val) {
	Node	*n = new Node(val);

	if (_topNode)
		_topNode->above = n;
	n->under = _topNode;
	_topNode = n;
	_size++;
}

template <typename T>
void MutantStack<T>::pop() {
	if (!_topNode)
		return;
	Node	*p;

	p = _topNode;
	_topNode = _topNode->under;
	if (_topNode)
		_topNode->above = NULL;
	delete p;
	_size--;
}

template <typename T>
T& MutantStack<T>::top() {
	return _topNode->val;
}


template <typename T>
const T& MutantStack<T>::top() const {
	return _topNode->val;
}

template <typename T>
bool MutantStack<T>::empty() const {
	if (_topNode)
		return (false);
	return (true);
}

template <typename T>
size_t MutantStack<T>::size() const {
	return (_size);
}

// Conversion constructor
// Stack -> Mutant
template <typename T>
MutantStack<T>::MutantStack(const std::stack<T>& s) : _topNode(NULL), _size(0) {
	std::stack<T> temp(s);
	while (!temp.empty()) {
		push(temp.top());
		temp.pop();
	}
}

//Mutant -> Stack
template <typename T>
MutantStack<T>::operator std::stack<T>() const {
	std::stack<T> s;
	Node* crt = _topNode;
	while (crt) {
		s.push(crt->val);  // Push each element into std::stack
		crt = crt->under;
	}
	return s;
}