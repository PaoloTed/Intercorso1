
#include "traversable.hpp"
#include "mappable.hpp"
#include "dictionary.hpp"

namespace Intercorso1 {


/* ************************************************************************** */

    template<typename Data>
    // type InsertAll(argument) specifiers; // Copy of the value; From TraversableContainer; True if all are inserted
    bool DictionaryContainer<Data>::InsertAll(const TraversableContainer<Data> &container) {
        bool inserted = true;
        container.Traverse(
                [&](const Data &data) {
                    inserted = Insert(data) && inserted;//Controllo AND tra il valore di inserted e il risultato della funzione Insert
                }
        );
        return inserted;
    }

    // type InsertAll(argument) specifiers; // Move of the value; From MappableContainer; True if all are inserted
    template<typename Data>
    bool DictionaryContainer<Data>::InsertAll(MappableContainer<Data> &&container) {
        bool inserted = true;
        container.Map(
                [&](const Data &data) {
                    inserted = Insert(std::move(data)) && inserted;//Controllo AND tra il valore di inserted e il risultato della funzione Insert
                }
        );
        return inserted;
    }

    // type RemoveAll(argument) specifiers; // From TraversableContainer; True if all are removed
    template<typename Data>
    bool DictionaryContainer<Data>::RemoveAll(TraversableContainer<Data> &container) {
        bool removed = true;
        container.Map(
                [&](const Data &data) {
                    removed = Remove(data) && removed;//Controllo AND tra il valore di removed e il risultato della funzione Remove
                }
        );
        return removed;
    }

    // type InsertSome(argument) specifiers; // Copy of the value; From TraversableContainer; True if some is inserted
    //TODO : Implementare, chiedere alla prof che si intende per some
    template<typename Data>
    bool DictionaryContainer<Data>::InsertSome(const TraversableContainer<Data> &container) {

    }

    // type InsertSome(argument) specifiers; // Move of the value; From MappableContainer; True if some is inserted
    //TODO : Implementare, chiedere alla prof che si intende per some
    template<typename Data>
    bool DictionaryContainer<Data>::InsertSome(MappableContainer<Data> &&container) {}

    // type RemoveSome(argument) specifiers; // From TraversableContainer; True if some is removed
    //TODO : Implementare, chiedere alla prof che si intende per some
    template<typename Data>
    bool DictionaryContainer<Data>::RemoveSome(TraversableContainer<Data> &container) {}

/* ************************************************************************** */

}
