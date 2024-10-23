#pragma once
#ifndef TemplateCash_H
#define TemplateCash_H

#include <unordered_map>

template <typename KEY, typename VALUE>
class TemplateCash;

template <typename KEY, typename VALUE>
class Node {
  friend TemplateCash<KEY, VALUE>;
  KEY key;
  VALUE value;
  Node<KEY, VALUE>* next;
  Node<KEY, VALUE>* prev;

  Node(const KEY& k, const VALUE& v) : key(k), value(v) {
    next = nullptr;
    prev = nullptr;
  }
};

template <typename KEY, typename VALUE>
class TemplateCash {
  int capacity;
  std::unordered_map<KEY, Node<KEY, VALUE>*> cacheMap;
  Node<KEY, VALUE>* head = nullptr;
  Node<KEY, VALUE>* tail = nullptr;

  // Add a node right after the head
  // (most recently used position)
  void add(Node<KEY, VALUE>* node) {
    Node<KEY, VALUE>* nextNode = head->next;
    head->next = node;
    node->prev = head;
    node->next = nextNode;
    nextNode->prev = node;
  }

  // Remove a node from the list
  void remove(Node<KEY, VALUE>* node) {
    assert(node->next);
    assert(node->prev);
    Node<KEY, VALUE>* prevNode = node->prev;
    Node<KEY, VALUE>* nextNode = node->next;
    prevNode->next = nextNode;
    nextNode->prev = prevNode;
  }

 public:
  TemplateCash(int capacity)
      : capacity(capacity), head(new Node<KEY, VALUE>(KEY(), VALUE())), tail(new Node<KEY, VALUE>(KEY(), VALUE())) {
    head->next = tail;
    tail->prev = head;
  }

  ~TemplateCash() {
    auto it = head;
    for (; it != tail;) {
      auto itPrev = it;
      it = it->next;
      delete itPrev;
    }
    delete tail;
  }

  bool exists(const KEY& key) { return cacheMap.find(key) != cacheMap.end(); }

  // Function to get the value for a given key
  VALUE get(const KEY& key) {
    Node<KEY, VALUE>* node = cacheMap.at(key);
    remove(node);
    add(node);
    return node->value;
  }

  // Function to put a key-value pair into the cache
  template <typename TVALUE>
  void put(const KEY& key, TVALUE&& value) {
    if (cacheMap.find(key) != cacheMap.end()) {
      Node<KEY, VALUE>* oldNode = cacheMap[key];
      remove(oldNode);
    }

    Node<KEY, VALUE>* node = new Node<KEY, VALUE>(key, std::forward<TVALUE>(value));
    cacheMap.emplace(key, node);
    add(node);

    if (cacheMap.size() > capacity) {
      Node<KEY, VALUE>* nodeToDelete = tail->prev;
      remove(nodeToDelete);
      cacheMap.erase(nodeToDelete->key);
      delete nodeToDelete;
    }
  }
};

#endif  // !TemplateCash
