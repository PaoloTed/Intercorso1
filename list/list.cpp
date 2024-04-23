#include "list.hpp"

namespace lasd {

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
    List<Data>::List(const List<Data> &list) {
        if (size == list.size) {
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
        } else {
            throw std::length_error("The size of the local list is different from the size of the list to copy");
        }
    }

    template<typename Data>
    List<Data>::List(List &&list) noexcept {
        std::swap(size, list.size);
        std::swap(head, list.head);
        std::swap(tail, list.tail);
    }

    template<typename Data>
    List<Data>::~List() {
        delete head;
    }

    //TODO::
    template<typename Data>
    List<Data> &List<Data>::operator=(const List &list) {

        return *this;
    }

    template<typename Data>
    List<Data> &List<Data>::operator=(List &&list) noexcept {
        std::swap(size, list.size);
        std::swap(head, list.head);
        std::swap(tail, list.tail);
        return *this;
    }

    //given that == operator is defined in Node class, we can use it to compare two lists
    template<typename Data>
    bool List<Data>::operator==(const List &list) const {
        if (size == list.size) {
            return *head == *list.head;
        }
        return false;
    }

    template<typename Data>
    bool List<Data>::operator!=(const List &list) const {
        return !(*this == list);
    }

    template<typename Data>
    void List<Data>::InsertAtFront(const Data &data) {
        Node *temp = new Node(data);
        temp->next = head;
        head = temp;
        if (tail == nullptr) {
            tail = head;
        }
        ++size;
    }

    template<typename Data>
    void List<Data>::InsertAtFront(Data &&data) {
        Node *temp = new Node(std::move(data));
        temp->next = head;
        head = temp;
        if (tail == nullptr) {
            tail = head;
        }
        ++size;
    }

    template<typename Data>
    void List<Data>::RemoveFromFront() {
        if (size == 0) {
            throw std::length_error("The list is empty");
        }
        if (head != nullptr) {
            Node *temp = head;
            head = head->next;
            temp->next = nullptr;
            delete temp;
            --size;
        }
    }

    template<typename Data>
    Data List<Data>::FrontNRemove() {
        if (size == 0) {
            throw std::length_error("The list is empty");
        }
        if (head != nullptr) {
            Node *temp = head;
            head = head->next;
            temp->next = nullptr;
            Data value = temp->value;
            delete temp;
            --size;
            return value;
        }
    }

    template<typename Data>
    void List<Data>::InsertAtBack(const Data &data) {
        Node *temp = new Node(data);
        if (tail != nullptr) {
            tail->next = temp;
            tail = temp;
        } else {
            head = tail = temp;
        }
        ++size;
    }

    template<typename Data>
    void List<Data>::InsertAtBack(Data &&data) {
        Node *temp = new Node(std::move(data));
        if (tail != nullptr) {
            tail->next = temp;
            tail = temp;
        } else {
            head = tail = temp;
        }
        ++size;
    }

    template<typename Data>
    void List<Data>::Clear() {
        size = 0;
        delete head;
        head = tail = nullptr;
    }

    template<typename Data>
    bool List<Data>::Insert(const Data &data) {
        if (!Exists(data)) {
            InsertAtBack(data);
            return true;
        }
        return false;
    }

    template<typename Data>
    bool List<Data>::Insert(Data &&data) {
        if (!Exists(data)) {
            InsertAtBack(std::move(data));
            return true;
        }
        return false;
    }

    template<typename Data>
    bool List<Data>::Remove(const Data &data) {
        if (size == 0) {
            return false;
        }
        if (head->value == data) {
            RemoveFromFront();
            return true;
        }
        Node *temp = head->next;
        Node *tempPrev = head;
        while (temp != nullptr) {
            if (temp->value == data) {
                tempPrev->next = temp->next;
                if (temp->next == nullptr) {
                    tail = tempPrev;
                }
                temp->next = nullptr;
                delete temp;
                --size;
                return true;
            }
            tempPrev = temp;
            temp = temp->next;
        }
        return false;
    }

    template<typename Data>
    const Data &List<Data>::operator[](const unsigned long index) const {
        if (index >= size) {
            throw std::out_of_range("The index is out of range");
        }
        Node *temp = head;
        for (unsigned long i = 0; i < index; ++i) {
            temp = temp->next;
        }
        return temp->value;
    }

    template<typename Data>
    Data &List<Data>::operator[](const unsigned long index) {
        if (index >= size) {
            throw std::out_of_range("The index is out of range");
        }
        Node *temp = head;
        for (unsigned long i = 0; i < index; ++i) {
            temp = temp->next;
        }
        return temp->value;
    }

    template<typename Data>
    const Data &List<Data>::Front() const {
        if (size == 0) {
            throw std::length_error("The list is empty");
        }
        return head->value;
    }

    template<typename Data>
    Data &List<Data>::Front() {
        if (size == 0) {
            throw std::length_error("The list is empty");
        }
        return head->value;
    }

    template<typename Data>
    const Data &List<Data>::Back() const {
        if (size == 0) {
            throw std::length_error("The list is empty");
        }
        return tail->value;
    }

    template<typename Data>
    Data &List<Data>::Back() {
        if (size == 0) {
            throw std::length_error("The list is empty");
        }
        return tail->value;
    }

    template<typename Data>
    void List<Data>::PreOrderTraverse(TraverseFun fun, Node *node) const {
        if (node != nullptr) {
            fun(node->value);
            PreOrderTraverse(fun, node->next);
        }
    }

    template<typename Data>
    void List<Data>::PostOrderTraverse(TraverseFun fun, Node *node) const {
        if (node != nullptr) {
            PostOrderTraverse(fun, node->next);
            fun(node->value);
        }
    }

    template<typename Data>
    void List<Data>::PreOrderMap(MapFun fun, Node *node) const {
        if (node != nullptr) {
            fun(node->value);
            PreOrderMap(fun, node->next);
        }
    }

    template<typename Data>
    void List<Data>::PostOrderMap(MapFun fun, Node *node) const {
        if (node != nullptr) {
            PostOrderMap(fun, node->next);
            fun(node->value);
        }
    }










/* ************************************************************************** */

}
