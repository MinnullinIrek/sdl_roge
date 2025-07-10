#include "console.h"

ConsoleGame::ConsoleGame() : window(), cash(50) {
  m_actionKey[EAction::down] = KEY_ARROW_DOWN;
  m_actionKey[EAction::left] = KEY_ARROW_LEFT;
  m_actionKey[EAction::up] = KEY_ARROW_UP;
  m_actionKey[EAction::right] = KEY_ARROW_RIGHT;
}

void ConsoleGame::DrawBuffer() { window.drawBuffer(); }

void ConsoleGame::DrawBufferRegion(short x, short y, short columns, short rows) {
  window.drawBufferRegion(x, y, columns, rows);
}

void ConsoleGame::FillBuffer(CHAR c, WORD attr) { window.fillBuffer(c, attr); }

// bool ConsoleGame::IsKeyDown(int key) { return window.isKeyDown(key); }
//
// bool ConsoleGame::IsKeyPressed(int key) { return window.isKeyPressed(key); }

void ConsoleGame::SetTitle(const char* title) { window.setTitle(title); }
void ConsoleGame::SetWindowSize(SHORT width, SHORT height, bool adjustBuffer) {
  window.setWindowSize(width, height, adjustBuffer);
}

bool ConsoleGame::isKeyDown(int key) { return window.isKeyDown(key); }

bool ConsoleGame::isKeyPressed(int key) { return window.isKeyPressed(key); }

EAction ConsoleGame::getPressed() {
  for (const auto& a : m_actionKey) {
    if (isKeyDown(a.second)) {
      return a.first;
    }
  }
  return EAction::none;
}
