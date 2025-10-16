#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include "exeptions/ValueNotFound.hpp"

template <typename T>
typename T::iterator easyfind(T& container, int ref) {
    typename T::iterator it = std::find(container.begin(), container.end(), ref);
    if (it == container.end())
        throw ValueNotFound();
    return it;
}

#endif