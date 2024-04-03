
#ifndef LINEAR_HPP
#define LINEAR_HPP

/* ************************************************************************** */

#include "mappable.hpp"

/* ************************************************************************** */

namespace Intercorso1 {

/* ************************************************************************** */

    template<typename Data>
    class LinearContainer
            : virtual public PreOrderMappableContainer<Data>, virtual public PostOrderMappableContainer<Data> {
        // Must extend PreOrderMappableContainer<Data>,
        //             PostOrderMappableContainer<Data>

    private:

        // ...

    protected:

        // ...

    public:

        // Destructor
        // ~LinearContainer() specifiers

        /* ************************************************************************ */

        // Copy assignment
        // type operator=(argument); // Copy assignment of abstract types is not possible.
        LinearContainer &operator=(const LinearContainer &) = delete;

        // Move assignment
        // type operator=(argument); // Move assignment of abstract types is not possible.
        LinearContainer &operator=(LinearContainer &&) = delete;

        /* ************************************************************************ */

        // Comparison operators
        // type operator==(argument) specifiers; // Comparison of abstract types is possible.
        LinearContainer &operator==(const LinearContainer &) const = delete;
        // type operator!=(argument) specifiers; // Comparison of abstract types is possible.
        LinearContainer &operator!=(const LinearContainer &) const = delete;

        /* ************************************************************************ */

        // Specific member functions

        // type operator[](argument) specifiers; // (non-mutable version; concrete function must throw std::out_of_range when out of range)
        virtual Data& operator[](const unsigned long)const override = 0;
        // type operator[](argument) specifiers; // (mutable version; concrete function must throw std::out_of_range when out of range)
        virtual Data& operator[](const unsigned long) override = 0;
        // type Front() specifiers; // (non-mutable version; concrete function must throw std::length_error when empty)
        virtual Data& Front() const override = 0;
        // type Front() specifiers; // (mutable version; concrete function must throw std::length_error when empty)
        virtual Data& Front() override = 0;
        // type Back() specifiers; // (non-mutable version; concrete function must throw std::length_error when empty)
        virtual Data& Back() const override = 0;
        // type Back() specifiers; // (mutable version; concrete function must throw std::length_error when empty)
        virtual Data& Back() override = 0;

        /* ************************************************************************ */

        // Specific member function (inherited from TraversableContainer)

        // using typename TraversableContainer<Data>::TraverseFun;

        // type Traverse(argument) specifiers; // Override TraversableContainer member

        /* ************************************************************************ */

        // Specific member function (inherited from PreOrderTraversableContainer)

        // type PreOrderTraverse(argument) specifiers; // Override PreOrderTraversableContainer member

        /* ************************************************************************ */

        // Specific member function (inherited from PostOrderTraversableContainer)

        // type PostOrderTraverse(argument) specifiers; // Override PostOrderTraversableContainer member

        /* ************************************************************************ */

        // Specific member function (inherited from MappableContainer)

        // using typename MappableContainer<Data>::MapFun;

        // type Map(argument) specifiers; // Override MappableContainer member

        /* ************************************************************************ */

        // Specific member function (inherited from PreOrderMappableContainer)

        // type PreOrderMap(argument) specifiers; // Override PreOrderMappableContainer member

        /* ************************************************************************ */

        // Specific member function (inherited from PostOrderMappableContainer)

        // type PostOrderMap(argument) specifiers; // Override PostOrderMappableContainer member

    };

/* ************************************************************************** */

    template<typename Data>
    class SortableLinearContainer : virtual public LinearContainer<Data> {
        // Must extend LinearContainer<Data>

    private:

        // ...

    protected:

        // ...

    public:

        // Destructor
        // ~SortableLinearContainer() specifiers

        /* ************************************************************************ */

        // Copy assignment
        // type operator=(argument); // Copy assignment of abstract types is not possible.

        // Move assignment
        // type operator=(argument); // Move assignment of abstract types is not be possible.

        /* ************************************************************************ */

        // Comparison operators
        // type operator==(argument) specifiers; // Comparison of abstract types is possible.
        // type operator!=(argument) specifiers; // Comparison of abstract types is possible.

        /* ************************************************************************ */

        // Specific member function

        // type Sort() specifiers;

    protected:

        // Auxiliary member functions

        // ...

    };

/* ************************************************************************** */

}

#include "linear.cpp"

#endif
