#include "queuevec.hpp"

namespace Intercorso1 {

/* ************************************************************************** */

// ...
template<typename Data>
QueueVec<Data>::QueueVec(const TraversableContainer<Data>& traCon) : Vector<Data>(traCon) {
    tail(size);
    Vector<Data>::Resize(size *2);
}

template<typename Data>


/* ************************************************************************** */

}
