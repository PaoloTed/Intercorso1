
#ifndef QUEUELST_HPP
#define QUEUELST_HPP

/* ************************************************************************** */

#include "../queue.hpp"
#include "../../list/list.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

    template<typename Data>
    class QueueLst : virtual public Queue<Data>, virtual protected List<Data> {
        // Must extend Queue<Data>,
        //             List<Data>

    private:

        // ...

    protected:

        // using List<Data>::???;

        // ...

    public:

        // Default constructor
        // QueueLst() specifier;
        QueueLst() = default;

        /* ************************************************************************ */

        // Specific constructor
        // QueueLst(argument) specifiers; // A stack obtained from a TraversableContainer
        QueueLst(const TraversableContainer<Data> &traCon){
            List<Data>::List(traCon);
        }

        // QueueLst(argument) specifiers; // A stack obtained from a MappableContainer
        QueueLst(MappableContainer<Data> && mapCon){
            List<Data>::List(std::move(mapCon));
        }

        /* ************************************************************************ */

        // Copy constructor
        // QueueLst(argument);
            QueueLst(const QueueLst & que){
            List<Data>::List(que);
        }

        // Move constructor
        // QueueLst(argument);
        QueueLst(QueueLst && que) noexcept{
            List<Data>::List(std::move(que));
            };

        /* ************************************************************************ */

        // Destructor
        // ~QueueLst() specifier;
        virtual ~QueueLst() = default;

        /* ************************************************************************ */

        // Copy assignment
        // type operator=(argument);
        QueueLst &operator=(const QueueLst &que){
            List<Data>::operator=(que);
            return *this;
        }

        // Move assignment
        // type operator=(argument);
        QueueLst &operator=(QueueLst && que) noexcept{
            List<Data>::operator=(std::move(que));
            return *this;
        }

        /* ************************************************************************ */

        // Comparison operators
        // type operator==(argument) specifiers;
        bool operator==(const QueueLst & que) const{
            return List<Data>::operator==(que);
        }

        // type operator!=(argument) specifiers;
        bool operator!=(const QueueLst & que) const{
            return List<Data>::operator!=(que);
        }

        /* ************************************************************************ */

        // Specific member functions (inherited from Queue)

        // type Head() specifiers; // Override Queue member (non-mutable version; must throw std::length_error when empty)
        Data &Head() override{
            return List<Data>::Front();
        }

        // type Head() specifiers; // Override Queue member (mutable version; must throw std::length_error when empty)
        const Data &Head() const override{
            return List<Data>::Front();
        }
        // type Dequeue() specifiers; // Override Queue member (must throw std::length_error when empty)
        void Dequeue() override{
            List<Data>::RemoveFromFront();
        }
        // type HeadNDequeue() specifiers; // Override Queue member (must throw std::length_error when empty)
        Data HeadNDequeue() override{
            return List<Data>::FrontNRemove();
        }
        // type Enqueue(argument) specifiers; // Override Queue member (copy of the value)
        void Enqueue(const Data &d) override{
            List<Data>::InsertAtBack(d);}
        // type Enqueue(argument) specifiers; / Override Queue member (move of the value)
        void Enqueue(Data &&d) override{
            List<Data>::InsertAtBack(std::move(d));
        }

        /* ************************************************************************ */

        // Specific member function (inherited from ClearableContainer)

        // using List<Data>::Clear;
        using List<Data>::Clear;

    protected:

        // Auxiliary functions, if necessary!

    };

/* ************************************************************************** */

}

#include "queuelst.cpp"

#endif
