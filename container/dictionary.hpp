
#ifndef DICTIONARY_HPP
#define DICTIONARY_HPP

/* ************************************************************************** */
#include "testable.hpp"
/* ************************************************************************** */

namespace Intercorso1 {

/* ************************************************************************** */

    template<typename Data>
    class DictionaryContainer : virtual public TestableContainer<Data> {
        // Must extend TestableContainer<Data>

    private:

        // ...

    protected:

        // ...

    public:

        // Destructor
        // ~DictionaryContainer() specifiers
        virtual ~DictionaryContainer() = default;

        /* ************************************************************************ */

        // Copy assignment
        // type operator=(argument); // Copy assignment of abstract types is not possible.
        DictionaryContainer &operator=(const DictionaryContainer &) = delete;

        // Move assignment
        // type operator=(argument); // Move assignment of abstract types is not possible.
        DictionaryContainer &operator=(DictionaryContainer &&) = delete;

        /* ************************************************************************ */

        // Comparison operators
        // type operator==(argument) specifiers; // Comparison of abstract types is not possible.
        bool operator==(const DictionaryContainer &) const = delete;

        // type operator!=(argument) specifiers; // Comparison of abstract types is not possible.
        bool operator!=(const DictionaryContainer &) const = delete;

        /* ************************************************************************ */

        // Specific member functions

        // type Insert(argument) specifiers; // Copy of the value
        virtual bool Insert(const Data &) = 0;

        // type Insert(argument) specifiers; // Move of the value
        virtual bool Insert(Data &&) = 0;

        // type Remove(argument) specifiers;
        virtual bool Remove(const Data &) = 0;

        // type InsertAll(argument) specifiers; // Copy of the value; From TraversableContainer; True if all are inserted
        inline virtual bool InsertAll(const TraversableContainer<Data> &);

        // type InsertAll(argument) specifiers; // Move of the value; From MappableContainer; True if all are inserted
        inline virtual bool InsertAll(MappableContainer<Data> &&);

        // type RemoveAll(argument) specifiers; // From TraversableContainer; True if all are removed
        inline bool RemoveAll(TraversableContainer<Data> &);

        // type InsertSome(argument) specifiers; // Copy of the value; From TraversableContainer; True if some is inserted
        inline bool InsertSome(const TraversableContainer<Data> &);

        // type InsertSome(argument) specifiers; // Move of the value; From MappableContainer; True if some is inserted
        inline bool InsertSome(MappableContainer<Data> &&);

        // type RemoveSome(argument) specifiers; // From TraversableContainer; True if some is removed
        inline bool RemoveSome(TraversableContainer<Data> &);

    };

/* ************************************************************************** */

}

#include "dictionary.cpp"

#endif
