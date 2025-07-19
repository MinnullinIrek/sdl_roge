#include "game_drawer.h"

GameDrawer::GameDrawer() : window(), cash(50) {
  m_actionKey[EAction::down] = KEY_ARROW_DOWN;
  m_actionKey[EAction::left] = KEY_ARROW_LEFT;
  m_actionKey[EAction::up] = KEY_ARROW_UP;
  m_actionKey[EAction::right] = KEY_ARROW_RIGHT;
}

void GameDrawer::DrawBuffer() { window.drawBuffer(); }

void GameDrawer::DrawBufferRegion(short x, short y, short columns, short rows) {
  window.drawBufferRegion(x, y, columns, rows);
}

void GameDrawer::FillBuffer(CHAR c, WORD attr) { window.fillBuffer(c, attr); }

// bool GameDrawer::IsKeyDown(int key) { return window.isKeyDown(key); }
//
// bool GameDrawer::IsKeyPressed(int key) { return window.isKeyPressed(key); }

void GameDrawer::SetTitle(const char* title) { window.setTitle(title); }
void GameDrawer::SetWindowSize(SHORT width, SHORT height, bool adjustBuffer) {
  window.setWindowSize(width, height, adjustBuffer);
}

bool GameDrawer::isKeyDown(int key) { return window.isKeyDown(key); }

bool GameDrawer::isKeyPressed(int key) { return window.isKeyPressed(key); }

EAction GameDrawer::getPressed() {
  for (const auto& a : m_actionKey) {
    if (isKeyDown(a.second)) {
      return a.first;
    }
  }
  return EAction::none;
}
