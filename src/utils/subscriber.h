
#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

#include <functional>
#include <list>
#include <memory>
#include <unordered_map>

class Subscriber;

using PublisherKey = unsigned int;
using SubscriberKey = unsigned int;
using Unique_Key = unsigned int;

Unique_Key unique();

class Publisher : public std::enable_shared_from_this<Publisher> {
 public:
  Publisher() = default;
  Publisher(Publisher&& publisher);
  virtual ~Publisher() {};

  // todo to private friend Connection
  void emit();
  void addSubscriber(std::weak_ptr<Subscriber> subscriber);
  void removeSubscriber(std::weak_ptr<Subscriber> subscriber);

 protected:
  void checkZompies();
  std::unordered_map<SubscriberKey, std::weak_ptr<Subscriber>> m_subscribers;
};

class Subscriber {
  friend Publisher;

 public:
  Subscriber();
  virtual ~Subscriber() = default;

 protected:
  virtual void notify(std::weak_ptr<Publisher> publisher) = 0;

 private:
  const Unique_Key m_key;
};

#endif  // SUBSCRIBER_H
