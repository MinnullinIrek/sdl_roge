#include "log_window.h"

#include <algorithm>
#include <iterator>

template <typename T>
static void split(const std::string& str, int splitLength, T&& it) {
  int NumSubstrings = str.length() / splitLength;

  for (auto i = 0; i < NumSubstrings; i++) {
    it = (str.substr(i * splitLength, splitLength));
    ++it;
  }

  // If there are leftover characters, create a shorter item at the end.
  if (str.length() % splitLength != 0) {
    it = (str.substr(splitLength * NumSubstrings));
    ++it;
  }
}

std::shared_ptr<LogWindow> LogWindow::inst;

LogWindow::LogWindow(const RectangleI& rect) : IWindow(rect) {}

void LogWindow::show(const std::function<void(Text&&, const Coord&)>& visualizator, const Coord& parentCd) {
  const auto h = m_rectangle.height();
  auto startI = m_text.size() > h ? m_text.size() - h : 0;
  int i = 0;
  for (auto it = m_text.cbegin() + startI; it != m_text.cend(); ++it, ++i) {
    visualizator(Text(*it, {125, 125, 125}, {0, 0, 0}), parentCd + m_rectangle.lu + Coord{0, i});
  }
}

void LogWindow::notify(std::weak_ptr<Publisher> /*publisher*/) {}

void LogWindow::appendMessage(const std::string& text) {
  split(text, (m_rectangle.rd.x - m_rectangle.lu.x), std::back_inserter(m_text));
}
