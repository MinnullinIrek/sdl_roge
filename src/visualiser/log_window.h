#ifndef LOG_WINDOW_H
#define LOG_WINDOW_H
#include <vector>
#include <string_view>

#include "../utils/subscriber.h"
#include "iwindow.h"
using namespace std::literals;

class LogWindow : public IWindow, public Subscriber {
 public:
  const std::string name = "logwindow";
  void show(const std::function<void(Text&&, const Coord&)>& visualizator, const Coord& parentCd);
  void notify(std::weak_ptr<Publisher> pub) override;
  void appendMessage(const std::string& text);
  static std::shared_ptr<LogWindow> instance() { return inst; }
  static void init(const RectangleI& rect) { inst = std::make_shared<LogWindow>(rect); }
  template <class... Ts>
  void Log(const Ts&... args) {
    std::stringstream str;
    str << /*GetTimeStamp() <<*/ ":";
    ((str << args), ...);
    appendMessage(str.str());
  }
  LogWindow(const RectangleI& rect);

 private:
  static std::shared_ptr<LogWindow> inst;
  //Text m_header;
  std::vector<std::string> m_text;
};

#endif
