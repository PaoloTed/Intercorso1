
#include <stdexcept>
#
namespace lasd {

/* ************************************************************************** */

// ...


    template<typename Data>
    bool LinearContainer<Data>::operator==(const LinearContainer<Data> &linCon) const noexcept {
        if (size == linCon.size) {
            for (unsigned long i = 0; i < size; i++) {
                if ((*this)[i] != linCon[i]) {
                    return false;
                }
            }
            return true;
        }
        return false;
    }

    template<typename Data>
    bool LinearContainer<Data>::operator!=(const LinearContainer<Data> &linCon) const {
        return !(*this == linCon);
    }

    template<typename Data>
    Data &LinearContainer<Data>::Front() const {
        if (size == 0) {
            throw std::length_error("Empty container");
        }
        return (*this)[0];
    }

    template<typename Data>
    Data &LinearContainer<Data>::Front() {
        if (size == 0) {
            throw std::length_error("Empty container");
        }
        return (*this)[0];
    }

    template<typename Data>
    Data &LinearContainer<Data>::Back() const {
        if (size == 0) {
            throw std::length_error("Empty container");
        }
        return (*this)[size - 1];
    }

    template<typename Data>
    Data &LinearContainer<Data>::Back() {
        if (size == 0) {
            throw std::length_error("Empty container");
        }
        return (*this)[size - 1];
    }

    template<typename Data>
    void LinearContainer<Data>::Traverse(LinearContainer::TraverseFun fun) const {
        PreOrderTraverse(fun);
    }

    template<typename Data>
    void LinearContainer<Data>::PreOrderTraverse(LinearContainer::TraverseFun fun) const {
        for (unsigned long i = 0; i < size; i++) {
            fun((*this)[i]);
        }
    }

    template<typename Data>
    void LinearContainer<Data>::PostOrderTraverse(LinearContainer::TraverseFun fun) const {
        for ( long i = size - 1; i >= 0; i--) {
            fun((*this)[i]);
        }
    }

    template<typename Data>
    void LinearContainer<Data>::Map(const LinearContainer::MapFun fun) {
        PreOrderMap(fun);
    }

    template<typename Data>
    void LinearContainer<Data>::PreOrderMap(const LinearContainer::MapFun fun) {
        for (unsigned long i = 0; i < size; i++) {
            fun((*this)[i]);
        }
    }

    template<typename Data>
    void LinearContainer<Data>::PostOrderMap(const LinearContainer::MapFun fun) {
        for (long i = size - 1; i >= 0; i--) {
            fun((*this)[i]);
        }
    }

    //SortableLinearContainer

    template<typename Data>
    bool SortableLinearContainer<Data>::operator==(const SortableLinearContainer<Data> &sorCon) const noexcept {
        return LinearContainer<Data>::operator==(sorCon);
    }

    template<typename Data>
    bool SortableLinearContainer<Data>::operator!=(const SortableLinearContainer<Data> &sorCon) const noexcept {
        return LinearContainer<Data>::operator!=(sorCon);
    }

    template<typename Data>
    void SortableLinearContainer<Data>::Sort() {
        //TODO
    }

    //Specific member function
    //BubbleSort quicksort etc

/* ************************************************************************** */

}
