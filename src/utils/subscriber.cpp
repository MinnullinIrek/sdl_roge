
#include "subscriber.h"

#include <algorithm>

Unique_Key unique() {
  static Unique_Key unique_key = 0;
  return unique_key++;
}

Subscriber::Subscriber() : m_key(unique()) {}

void Publisher::emit() {
  std::weak_ptr<Publisher> wThis = shared_from_this();
  std::for_each(m_subscribers.begin(), m_subscribers.end(),
                [wThis](auto &subscriber) {
                  auto lockedSubscriber = subscriber.second.lock();
                  if (lockedSubscriber) {
                    lockedSubscriber->notify(wThis);
                  }
                });
}

void Publisher::addSubscriber(std::weak_ptr<Subscriber> subscriber) {
  auto locked = subscriber.lock();
  if (locked) {
    m_subscribers[locked->m_key] = subscriber;
  }
}

void Publisher::removeSubscriber(std::weak_ptr<Subscriber> subscriber) {
  auto locked = subscriber.lock();
  if (locked) {
    m_subscribers.erase(locked->m_key);
  } else {
    checkZompies();
  }
}

void Publisher::checkZompies() {
  auto it = m_subscribers.begin();
  for (; it != m_subscribers.end();) {
    auto locked = it->second.lock();
    if (!locked) {
      it = m_subscribers.erase(it);
    }
    ++it;
  }
}

Publisher::Publisher(Publisher &&publisher)
    : m_subscribers(std::move(publisher.m_subscribers)) {}
