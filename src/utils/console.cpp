#include "console.h"

ConsoleGame::ConsoleGame() : Game(), cash(50) {}

void ConsoleGame::DrawBuffer() { Game::DrawBuffer(); }

void ConsoleGame::DrawBufferRegion(short x, short y, short columns, short rows) {
  Game::DrawBufferRegion(x, y, columns, rows);
}

void ConsoleGame::FillBuffer(CHAR c, WORD attr) { Game::FillBuffer(c, attr); }

bool ConsoleGame::IsKeyDown(int key) { return Game::IsKeyDown(key); }

bool ConsoleGame::IsKeyPressed(int key) { return Game::IsKeyPressed(key); }

void ConsoleGame::SetTitle(const char* title) { Game::SetTitle(title); }
void ConsoleGame::SetWindowSize(SHORT width, SHORT height, bool adjustBuffer) {
  Game::SetWindowSize(width, height, adjustBuffer);
}
