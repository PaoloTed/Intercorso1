
#ifndef STACKLST_HPP
#define STACKLST_HPP

/* ************************************************************************** */

#include "../stack.hpp"
#include "../../list/list.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

    template<typename Data>
    class StackLst : virtual public Stack<Data>, virtual protected List<Data> {
        // Must extend Stack<Data>,
        //             List<Data>

    private:

        // ...

    protected:

        // using List<Data>::???;
        using Container::size;

        // ...

    public:

        // Default constructor
        // StackLst() specifier;
        StackLst() = default;

        /* ************************************************************************ */

        // Specific constructor
        // StackLst(argument) specifiers; // A stack obtained from a TraversableContainer
        StackLst(const TraversableContainer<Data> &traCon) : List<Data>::List(traCon) {};

        // StackLst(argument) specifiers; // A stack obtained from a MappableContainer
        StackLst(MappableContainer<Data> &&mapCon) : List<Data>::List(std::move(mapCon)) {};

        /* ************************************************************************ */

        // Copy constructor
        // StackLst(argument);
        //todo
        StackLst(const StackLst &s) : List<Data>::List(s) {};

        // Move constructor
        // StackLst(argument);
        StackLst(StackLst &&s) : List<Data>::List(std::move(s)) {};

        /* ************************************************************************ */

        // Destructor
        // ~StackLst() specifier;
        virtual ~StackLst() = default;

        /* ************************************************************************ */

        // Copy assignment
        // type operator=(argument);
        StackLst &operator=(const StackLst &stk) {
            List<Data>::operator=(stk);
            return *this;
        }

        // Move assignment
        // type operator=(argument);
        StackLst &operator=(StackLst &&stk) noexcept {
            List<Data>::operator=(std::move(stk));
            return *this;
        }

        /* ************************************************************************ */

        // Comparison operators
        // type operator==(argument) specifiers;
        bool operator==(const StackLst &stk) const noexcept { return List<Data>::operator==(stk); }

        // type operator!=(argument) specifiers;
        bool operator!=(const StackLst &stk) const noexcept { return List<Data>::operator!=(stk); }

        /* ************************************************************************ */

        // Specific member functions (inherited from Stack)

        // type Top() specifiers; // Override Stack member (non-mutable version; must throw std::length_error when empty)
        const Data &Top() const override {
            if(size==0)
                throw std::length_error("Stack is empty");
            return List<Data>::Front();
        }

        // type Top() specifiers; // Override Stack member (non-mutable version; must throw std::length_error when empty)
        Data &Top() override {
            if(size==0)
                throw std::length_error("Stack is empty ");
            return List<Data>::Front(); }

        // type Pop() specifiers; // Override Stack member (must throw std::length_error when empty)
        void Pop() override {
            if(size==0)
                throw std::length_error("Stack is empty");
            List<Data>::RemoveFromFront();
        }

        // type TopNPop() specifiers; // Override Stack member (must throw std::length_error when empty)
        Data TopNPop() override {
            if(size==0)
                throw std::length_error("Stack is empty");
            return List<Data>::FrontNRemove();
        }

        // type Push(argument) specifiers; // Override Stack member (copy of the value)
        void Push(const Data &data) override { List<Data>::InsertAtFront(data); }

        // type Push(argument) specifiers; // Override Stack member (move of the value)
        void Push(Data &&data) override { List<Data>::InsertAtFront(std::move(data)); }

        /* ************************************************************************ */

        // Specific member function (inherited from ClearableContainer)

        // using List<Data>::Clear;
        using List<Data>::Clear;

    protected:

        // Auxiliary functions, if necessary!

    };

/* ************************************************************************** */

}

#include "stacklst.cpp"

#endif
