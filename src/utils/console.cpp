#include "console.h"

ConsoleGame::ConsoleGame() : ConsoleWindows(), cash(50) {}

void ConsoleGame::DrawBuffer() { ConsoleWindows::DrawBuffer(); }

void ConsoleGame::DrawBufferRegion(short x, short y, short columns, short rows) {
  ConsoleWindows::DrawBufferRegion(x, y, columns, rows);
}

void ConsoleGame::FillBuffer(CHAR c, WORD attr) { ConsoleWindows::FillBuffer(c, attr); }

bool ConsoleGame::IsKeyDown(int key) { return ConsoleWindows::IsKeyDown(key); }

bool ConsoleGame::IsKeyPressed(int key) { return ConsoleWindows::IsKeyPressed(key); }

void ConsoleGame::SetTitle(const char* title) { ConsoleWindows::SetTitle(title); }
void ConsoleGame::SetWindowSize(SHORT width, SHORT height, bool adjustBuffer) {
  ConsoleWindows::SetWindowSize(width, height, adjustBuffer);
}
