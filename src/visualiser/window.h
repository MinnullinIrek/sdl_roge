#ifndef WINDOW_H
#define WINDOW_H

// #include <functional>
#include <functional>
#include <string>
#include <vector>
#include <string_view>

#include "headers.h"
#include "subscriber.h"
#include "iwindow.h"

class Window : public IWindow, public Subscriber {
 public:
  // Window();
  Window(
      std::function<int(std::weak_ptr<Publisher>, std::string&, Color&, Color&)>&& updater,
      std::string text = "",
      const Color& color = {255, 255, 255},
      const Color& bgColor = {0, 0, 0},
      const RectangleI& rect = {{0, 0}, {1, 0}},
      bool needDeliver = true);

  virtual ~Window();

  std::vector<std::string> getText(int start = 0);
  int getStart();

  std::string m_text;
  Color m_color;
  Color m_bgColor;

  virtual void show(const std::function<void(Text&&, const Coord&)>& visualizator, const Coord& parentCd) override;

  void notify(std::weak_ptr<Publisher> publisher) override;
  virtual void clear();
  virtual void destroy();
 private:
  std::vector<std::string> deliver();
  // std::function<std::string()> m_asker;
  int m_start = 0;
  std::function<int(std::weak_ptr<Publisher>, std::string&, Color&, Color&)> m_updater;
  bool m_needDeliver;
};

#endif  // WINDOW_H
