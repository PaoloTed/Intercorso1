
#ifndef STACKVEC_HPP
#define STACKVEC_HPP

/* ************************************************************************** */

#include "../stack.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

    template<typename Data>
    class StackVec : virtual public Stack<Data>, virtual protected Vector<Data> {
        // Must extend Stack<Data>,
        //             Vector<Data>

    private:

        // ...

    protected:

        using Container::size;

        // using Vector<Data>::???;
        unsigned int index{0};
        using Vector<Data>::element;

        // ...

    public:

        // Default constructor
        // StackVec() specifier;
        StackVec() : Vector<Data>::Vector(1) {};

        /* ************************************************************************ */

        // Specific constructor
        // StackVec(argument) specifiers; // A stack obtained from a TraversableContainer
        StackVec(const TraversableContainer<Data> &traCon) : Vector<Data>::Vector(traCon) {
            index = size;
        };
        // StackVec(argument) specifiers; // A stack obtained from a MappableContainer
        StackVec(MappableContainer<Data> &&mapCon) : Vector<Data>::Vector(std::move(mapCon)) {
            index = size;
        };

        /* ************************************************************************ */

        // Copy constructor
        // StackVec(argument);
        StackVec(const StackVec &s) : Vector<Data>::Vector(s) {
            index = s.index;
        };

        // Move constructor
        // StackVec(argument);
        StackVec(StackVec &&s) noexcept ;
        /* ************************************************************************ */

        // Destructor
        // ~StackVec() specifier;
        virtual ~StackVec() = default;

        /* ************************************************************************ */

        // Copy assignment
        // type operator=(argument);
        StackVec &operator=(const StackVec &s);

        // Move assignment
        // type operator=(argument);
        StackVec &operator=(StackVec &&s) noexcept;

        /* ************************************************************************ */

        // Comparison operators
        // type operator==(argument) specifiers;
        bool operator==(const StackVec &s) const noexcept;
        // type operator!=(argument) specifiers;
        bool operator!=(const StackVec &s) const noexcept;

        /* ************************************************************************ */

        // Specific member functions (inherited from Stack)

        // type Top() specifiers; // Override Stack member (non-mutable version; must throw std::length_error when empty)
        const Data &Top() const override;
        // type Top() specifiers; // Override Stack member (non-mutable version; must throw std::length_error when empty)
        Data &Top() override;
        // type Pop() specifiers; // Override Stack member (must throw std::length_error when empty)
        void Pop() override;
        // type TopNPop() specifiers; // Override Stack member (must throw std::length_error when empty)
        Data TopNPop() override;
        // type Push(argument) specifiers; // Override Stack member (copy of the value)
        void Push(const Data &dat) override;
        // type Push(argument) specifiers; // Override Stack member (move of the value)
        void Push(Data &&dat) override;

        /* ************************************************************************ */

        // Specific member functions (inherited from Container)

        // type Empty() specifiers; // Override Container member
        bool Empty() const override;

        // type Size() specifiers; // Override Container member
        unsigned int Size() const;

        /* ************************************************************************ */

        // Specific member function (inherited from ClearableContainer)

        // type Clear() specifiers; // Override ClearableContainer member
        void Clear() override;

    protected:

        // Auxiliary functions, if necessary!
        void Expand();
        void Reduce();

    };

/* ************************************************************************** */

}

#include "stackvec.cpp"

#endif
