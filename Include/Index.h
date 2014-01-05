// Based on the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.
// Changes made for the purpose of this assignment

// The Index abstract class.

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

template<typename Key, typename E> class Index {
private:

    void operator =(const Index&) {
    }

    Index(const Index&) {
    }

public:

    Index() {
    } // Default constructor

    virtual ~Index() {
    } // Base destructor

    // Reinitialize index
    virtual void clear() = 0;

    // Insert a record
    // k: The key for the record being inserted.
    // e: The record being inserted.
    virtual void insert(const Key& k, const E& e) = 0;
    // Remove and return a record.
    // k: The key of the record to be removed.
    // Return: A maching record. If multiple records match
    // "k", remove an arbitrary one. Return NULL if no record
    // with key "k" exists.

    virtual void postOrderNOT(Index<Key, E>*&) = 0;
    virtual void postOrderNOT(BSTNode<Key, E>*, Index<Key, E>*&) = 0;
    virtual void postOrderAND(Index<Key, E>*, Index<Key, E>*&) = 0;
    virtual void postOrderAND(BSTNode<Key, E>*, Index<Key, E>*, Index<Key, E>*&) = 0;
    virtual void merge(BSTNode<Key, E>*, Index<Key, E>*, Index<Key, E>*&) = 0;
    virtual void merge(Index<Key, E>* secondTree, Index<Key, E>* &mergeTree) = 0;

    virtual void getVector(vector <E>&) = 0;
    virtual void getVector(BSTNode<Key, E>*, vector <E>&) = 0;

    virtual E remove(const Key& k) = 0;

    // Remove and return an arbitrary record from index.
    // Return: The record removed, or NULL if none exists.
    virtual E removeAny() = 0;

    // Return: A record matching "k" (NULL if none exists).
    // If multiple records match, return an arbitrary one.
    // k: The key of the record to find
    virtual E find(const Key& k) const = 0;

    // Return the number of records in the index.
    virtual int size() = 0;

    // Prints the index.
    virtual void print() = 0;
};