
#ifndef QUEUEVEC_HPP
#define QUEUEVEC_HPP

/* ************************************************************************** */

#include "../queue.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

    template<typename Data>
    class QueueVec : virtual public Queue<Data>, virtual protected Vector<Data> {
        // Must extend Queue<Data>,
        //             Vector<Data>

    private:

        // ...

    protected:

        // using Vector<Data>::???;
        using Container::size;
        using Vector<Data>::element;

        unsigned int head{0}, tail{0};

        // ...

    public:

        // Default constructor
        // QueueVec() specifier;
        QueueVec() {
            Vector<Data>::Vector(5);
        }

        /* ************************************************************************ */

        // Specific constructor
        // QueueVec(argument) specifiers; // A stack obtained from a TraversableContainer
        QueueVec(const TraversableContainer<Data> &container);

        // QueueVec(argument) specifiers; // A stack obtained from a MappableContainer
        QueueVec(MappableContainer<Data> &&container);

        /* ************************************************************************ */

        // Copy constructor
        // QueueVec(argument);
        QueueVec(const QueueVec &queue);

        // Move constructor
        // QueueVec(argument);
        QueueVec(QueueVec &&queue) noexcept ;
        /* ************************************************************************ */

        // Destructor
        // ~QueueVec() specifier;
        virtual ~QueueVec() = default;

        /* ************************************************************************ */

        // Copy assignment
        // type operator=(argument);
        QueueVec &operator=(const QueueVec &queue) ;

        // Move assignment
        // type operator=(argument);
        QueueVec &operator=(QueueVec &&queue) noexcept ;

        /* ************************************************************************ */

        // Comparison operators
        // type operator==(argument) specifiers;
        bool operator==(const QueueVec &queue) const noexcept ;

        // type operator!=(argument) specifiers;
        bool operator!=(const QueueVec &queue) const noexcept {
            return !(*this == queue);
        }

        /* ************************************************************************ */

        // Specific member functions (inherited from Queue)

        // type Head() specifiers; // Override Queue member (non-mutable version; must throw std::length_error when empty)
        const Data &Head() const override;

        // type Head() specifiers; // Override Queue member (mutable version; must throw std::length_error when empty)
        Data &Head() override;

        // type Dequeue() specifiers; // Override Queue member (must throw std::length_error when empty)
        void Dequeue() override;

        // type HeadNDequeue() specifiers; // Override Queue member (must throw std::length_error when empty)
        Data HeadNDequeue() override;

        // type Enqueue(argument) specifiers; // Override Queue member (copy of the value)
        void Enqueue(const Data &data) override;

        // type Enqueue(argument) specifiers; // Override Queue member (move of the value)
        void Enqueue(Data &&data) override;

        /* ************************************************************************ */

        // Specific member functions (inherited from Container)

        // type Empty() specifiers; // Override Container member
        bool Empty() const override {
            return (head == tail);
        }

        // type Size() specifiers; // Override Container member
        unsigned int Size() const override {
            return ((size + tail) - head) % size;
        }

        /* ************************************************************************ */

        // Specific member function (inherited from ClearableContainer)

        // type Clear() specifiers; // Override ClearableContainer member
        void Clear() override ;

        void Resize(unsigned int new_size, unsigned int num);

        void Reduce();

        void Expand();

    protected:

        // Auxiliary functions, if necessary!

    };

/* ************************************************************************** */

}

#include "queuevec.cpp"

#endif
