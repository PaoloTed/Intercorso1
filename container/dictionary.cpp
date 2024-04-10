
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
                [this,&inserted](const Data &data) {
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
                [this,&inserted](const Data &data) {
                    inserted = Insert(std::move(data)) && inserted;
                }
        );
        return inserted;
    }

    // type RemoveAll(argument) specifiers; // From TraversableContainer; True if all are removed
    template<typename Data>
    bool DictionaryContainer<Data>::RemoveAll(TraversableContainer<Data> &container) {
        bool removed = true;
        container.Map(
                [this,&removed](const Data &data) {
                    removed = Remove(data) && removed;
                }
        );
        return removed;
    }

    // type InsertSome(argument) specifiers; // Copy of the value; From TraversableContainer; True if some is inserted
    template<typename Data>
    bool DictionaryContainer<Data>::InsertSome(const TraversableContainer<Data> &container) {
        bool inserted = false;
        container.Traverse(
                [this,&inserted](const Data &data) {
                    inserted = Insert(data) || inserted;//Controllo OR tra il valore di inserted e il risultato della funzione Insert
                }
        );
        return inserted;
    }

    // type InsertSome(argument) specifiers; // Move of the value; From MappableContainer; True if some is inserted
    template<typename Data>
    bool DictionaryContainer<Data>::InsertSome(MappableContainer<Data> &&container) {
        bool inserted = false;
        container.Map(
                [this,&inserted](const Data &data) {
                    inserted = Insert(std::move(data)) || inserted;
                }
        );
        return inserted;
    }

    // type RemoveSome(argument) specifiers; // From TraversableContainer; True if some is removed
    template<typename Data>
    bool DictionaryContainer<Data>::RemoveSome(TraversableContainer<Data> &container) {
        bool removed = false;
        container.Map(
                [this,&removed](const Data &data) {
                    removed = Remove(data) || removed;
                }
        );
        return removed;
    }

/* ************************************************************************** */

}
