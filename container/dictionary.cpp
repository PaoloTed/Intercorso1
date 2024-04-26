namespace lasd {
/* ************************************************************************** */

    template<typename Data>
    // type InsertAll(argument) specifiers; // Copy of the value; From TraversableContainer; True if all are inserted
    inline bool DictionaryContainer<Data>::InsertAll(const TraversableContainer<Data> &container) {
        bool inserted = true;
        container.Traverse(
                [this,&inserted](const Data &data) {
                    //Serve this per chiamare la funzione Insert della classe DictionaryContainer
                    inserted = Insert(data) && inserted;//Controllo AND tra il valore di inserted e il risultato della funzione Insert
                }
        );
        return inserted;
    }

    // type InsertAll(argument) specifiers; // Move of the value; From MappableContainer; True if all are inserted
    template<typename Data>
    inline bool DictionaryContainer<Data>::InsertAll(MappableContainer<Data> &&container) {
        bool inserted = true;
        container.Map(
                [this,&inserted](const Data &data) {
                    inserted = Insert(std::move(data)) && inserted;//Controllo AND tra il valore di inserted e il risultato della funzione Insert
                }
        );
        return inserted;
    }

    // type RemoveAll(argument) specifiers; // From TraversableContainer; True if all are removed
    template<typename Data>
    inline bool DictionaryContainer<Data>::RemoveAll(TraversableContainer<Data> &container) {
        bool removed = true;
        container.Traverse(
                [this,&removed](const Data &data) {
                    removed = Remove(data) && removed;//Controllo AND tra il valore di removed e il risultato della funzione Remove
                }
        );
        return removed;
    }

    // type InsertSome(argument) specifiers; // Copy of the value; From TraversableContainer; True if some is inserted
    //True se almeno un elemento è stato inserito, fase se tutti non sono stati inseriti
    template<typename Data>
    inline bool DictionaryContainer<Data>::InsertSome(const TraversableContainer<Data> &container) {
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
    inline bool DictionaryContainer<Data>::InsertSome(MappableContainer<Data> &&container) {
        bool inserted = false;
        container.Map(
                [this,&inserted](const Data &data) {
                    inserted = Insert(std::move(data)) || inserted;//Controllo OR tra il valore di inserted e il risultato della funzione Insert
                }
        );
        return inserted;
    }

    // type RemoveSome(argument) specifiers; // From TraversableContainer; True if some is removed
    template<typename Data>
    inline bool DictionaryContainer<Data>::RemoveSome(TraversableContainer<Data> &container) {
        bool removed = false;
        container.Traverse(
                [this,&removed](const Data &data) {
                    removed = Remove(data) || removed;//Controllo OR tra il valore di removed e il risultato della funzione Remove
                }
        );
        return removed;
    }

/* ************************************************************************** */

}
