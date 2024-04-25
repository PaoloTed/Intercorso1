#include <stdexcept>

namespace lasd {

    template<typename Data>
    Vector<Data>::Vector(const unsigned long size_vett) {
        size_vett = size;
        Elements = new Data[size_vett]();
    }

    template<typename Data>
    Vector<Data>::Vector(const TraversableContainer<Data> &container) {
        Vector(container.Size());
        unsigned long i{0};
        container.Traverse([&i, this](const Data &data) {
            Elements[i++] = data;
        });
    }

    template<typename Data>
    Vector<Data>::Vector(MappableContainer<Data> &&container) {
        Vector(container.Size());
        unsigned long i{0};
        container.Map([&i, this](Data &data) {
            Elements[i++] = std::move(data);
        });
    }

    template<typename Data>
    Vector<Data>::Vector(const Vector<Data> &vector) {
        size = vector.size;
        Elements = new Data[size]{};
        for (unsigned long i = 0; i < size; i++) {
            Elements[i] = vector.Elements[i];
        }
    }

    template<typename Data>
    Vector<Data>::Vector(Vector<Data> &&vector) noexcept {
        std::swap(size, vector.size);
        std::swap(Elements, vector.Elements);
    }

    template<typename Data>
    Vector<Data> &Vector<Data>::operator=(const Vector<Data> &vector) {
        Vector<Data> *temp = new Vector<Data>(vector);
        std::swap(*temp, *this);
        delete temp;
        return *this;
    }

    template<typename Data>
    Vector<Data> &Vector<Data>::operator=(Vector<Data> &&vector) {
        std::swap(size, vector.size);
        std::swap(Elements, vector.Elements);
        return *this;
    }

    template<typename Data>
    bool Vector<Data>::operator==(const Vector<Data> &vector) const noexcept {
        if (size == vector.size && size == 0) {
            return true;
        }
        if (size == vector.size) {
            for (unsigned long i = 0; i < size; i++) {
                if (Elements[i] != vector.Elements[i]) {
                    return false;
                }
            }
            return true;
        } else {
            return false;
        }
    }

    template<typename Data>
    bool Vector<Data>::operator!=(const Vector<Data> &vector) const noexcept {
        return !(*this == vector);
    }

    template<typename Data>
    void Vector<Data>::Clear() const {
        delete[] Elements;
        size = 0;
        Elements = nullptr;
    }

    template<typename Data>
    void Vector<Data>::Resize(const unsigned long new_size) {
        if (new_size == 0) {
            Clear();
        } else if (size != new_size) {
            Data *new_elements = new Data[new_size]{};
            unsigned long min_size = (size < new_size) ? size : new_size;
            for (unsigned long i = 0; i < min_size; i++) {
                std::swap(new_elements[i], Elements[i]);
            }
            std::swap(Elements, new_elements);
            size = new_size;
            delete[] new_elements;
        }
    }

    template<typename Data>
    const Data &Vector<Data>::operator[](unsigned int i) const {
        if (i >= size) {
            throw std::out_of_range("Index out of range");
        }
        return Elements[i];
    }

    template<typename Data>
    Data &Vector<Data>::operator[](unsigned int i) {
        if (i >= size) {
            throw std::out_of_range("Index out of range");
        }
        return Elements[i];
    }

    template<typename Data>
    const Data &Vector<Data>::Front() const {
        if (size == 0) {
            throw std::length_error("Empty vector");
        }
        return Elements[0];
    }

    template<typename Data>
    Data &Vector<Data>::Front() {
        if (size == 0) {
            throw std::length_error("Empty vector");
        }
        return Elements[0];
    }

    template<typename Data>
    const Data &Vector<Data>::Back() const {
        if (size == 0) {
            throw std::length_error("Empty vector");
        }
        return Elements[size - 1];
    }

    template<typename Data>
    Data &Vector<Data>::Back() {
        if (size == 0) {
            throw std::length_error("Empty vector");
        }
        return Elements[size - 1];
    }

/* ************************************************************************** */

//SortableVector Implementation

    template<typename Data>
    SortableVector<Data>::SortableVector(const unsigned long size) {
        Vector<Data>::Vector(size);
    }

    template<typename Data>
    SortableVector<Data>::SortableVector(const TraversableContainer<Data> &container) {
        Vector<Data>::Vector(container);
    }

    template<typename Data>
    SortableVector<Data>::SortableVector( MappableContainer<Data> &&container) {
        Vector<Data>::Vector(std::move(container));
    }

    template<typename Data>
    SortableVector<Data>::SortableVector(const SortableVector<Data> &sorVec) {
        Vector<Data>::Vector(sorVec);
    }

    template<typename Data>
    SortableVector<Data>::SortableVector(SortableVector<Data> &&sorVec) noexcept {
        Vector<Data>::Vector(std::move(sorVec));
    }


    template<typename Data>
    SortableVector<Data>& SortableVector<Data>::operator=(const SortableVector<Data> & sorVec) {
        Vector<Data>::operator=(sorVec);
        return *this;
    }

    template<typename Data>
    SortableVector<Data>& SortableVector<Data>::operator=(SortableVector<Data> && sorVec) noexcept {
        Vector<Data>::operator=(std::move(sorVec));
        return *this;
    }

    template<typename Data>
    void SortableVector<Data>::Traverse(SortableVector::TraverseFun fun) const {
        PreOrderTraverse(fun);
    }
}
