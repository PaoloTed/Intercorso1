#include "list.hpp"

namespace Intercorso1 {

/* ************************************************************************** */

// ...
    template<typename Data>
    List<Data>::Node::Node(const Data &valueInsert) {
        value = {valueInsert};
    }

    template<typename Data>
    List<Data>::Node::Node(Data &&valueInsert) {
        std::swap(value, valueInsert);
    }

    template<typename Data>
    List<Data>::Node::Node(const Node &node) {
        value = {node.value};
    }

    template<typename Data>
    List<Data>::Node::Node(Node &&node) noexcept {
        std::swap(value, node.value);
        std::swap(next, node.next);
    }

    template<typename Data>
    List<Data>::Node::~Node() {
        delete next;
    }

    //Two nodes are equal if they have the same value and the same next nodes
    template<typename Data>
    bool List<Data>::Node::operator==(const Node &node) const {
        Node *temp1 = next;
        Node *temp2 = node.next;

        while (temp1 != nullptr && temp2 != nullptr) {
            if (temp1->value != temp2->value) {
                return false;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        //If in the end of while condition both are nullptr, they are equal
        if (temp1 == nullptr && temp2 == nullptr) {
            return true;
        }
        return false;
    }

    template<typename Data>
    bool List<Data>::Node::operator!=(const Node &node) const {
        return !(*this == node);
    }

    //TODO::
    template<typename Data>
    List<Data>::List(const TraversableContainer<Data> &container) {

    }

    template<typename Data>
    List<Data>::List(MappableContainer<Data> &&container) {

    }

    template<typename Data>
    List<Data>::List(const List& list) {
        if(size == list.size) {
            if (list.head != nullptr) {
                head = new Node(list.head->value);
                Node *tempOutside = list.head->next;
                Node *tempLocal = head;
                while (tempOutside != nullptr) {
                    tempLocal->next = new Node(tempOutside->value);
                    tempOutside = tempOutside->next;
                    tempLocal = tempLocal->next;
                }
                tail = tempLocal;
            }
        }else{
            throw std::length_error("The size of the local list is different from the size of the list to copy");
        }
    }






/* ************************************************************************** */

}
