#include "SDL.h"
#include "log.h"
// #include <ui.h>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_render.h>

#include <cmath>

// void Line(float x1, float y1, float x2, float y2, const Color& color)
//{
//     // Bresenham's line algorithm
//     const bool steep = (fabs(y2 - y1) > fabs(x2 - x1));
//     if (steep)
//     {
//         std::swap(x1, y1);
//         std::swap(x2, y2);
//     }
//
//     if (x1 > x2)
//     {
//         std::swap(x1, x2);
//         std::swap(y1, y2);
//     }
//
//     const float dx = x2 - x1;
//     const float dy = fabs(y2 - y1);
//
//     float error = dx / 2.0f;
//     const int ystep = (y1 < y2) ? 1 : -1;
//     int y = (int)y1;
//
//     const int maxX = (int)x2;
//
//     for (int x = (int)x1; x < maxX; x++)
//     {
//         if (steep)
//         {
//             SetPixel(y, x, color);
//         }
//         else
//         {
//             SetPixel(x, y, color);
//         }
//
//         error -= dy;
//         if (error < 0)
//         {
//             y += ystep;
//             error += dx;
//         }
//     }
// }

SDL_AppResult SDL_Fail() {
  SDL_LogError(SDL_LOG_CATEGORY_CUSTOM, "Error %s", SDL_GetError());
  return SDL_APP_FAILURE;
}

SDL_AppResult start() {
  if (SDL_Init(SDL_INIT_VIDEO)) {
    return SDL_Fail();
  }

  // create a window
  SDL_Window* window = SDL_CreateWindow("Window", 352, 430, SDL_WINDOW_RESIZABLE);
  if (!window) {
    return SDL_Fail();
  }

  SDL_Renderer* renderer = SDL_CreateRenderer(window, NULL);
  if (!renderer) {
    return SDL_Fail();
  }

  // print some information about the window
  SDL_ShowWindow(window);
  {
    int width, height, bbwidth, bbheight;
    SDL_GetWindowSize(window, &width, &height);
    SDL_GetWindowSizeInPixels(window, &bbwidth, &bbheight);
    SDL_Log("Window size: %ix%i", width, height);
    SDL_Log("Backbuffer size: %ix%i", bbwidth, bbheight);
    if (width != bbwidth) {
      SDL_Log("This is a highdpi environment.");
    }
  }

  // set up the application data
  // *appstate = new AppContext{
  //    window,
  //    renderer,
  // };

  SDL_Log("Application started successfully!");
  SDL_Event e;
  bool quit = false;

  SDL_Renderer* ren = SDL_CreateRenderer(window, NULL);
  if (ren == nullptr) {
    std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
    SDL_DestroyWindow(window);
    SDL_Quit();
    return SDL_Fail();
  }

  while (!quit) {
    while (SDL_PollEvent(&e)) {
      if (e.type == SDL_EVENT_QUIT) {
        quit = true;
      }
    }

    SDL_RenderClear(ren);
    // SDL_RenderTexture(ren, tex, NULL, NULL);
    SDL_RenderPresent(ren);
  }

  // SDL_DestroyTexture(tex);
  SDL_DestroyRenderer(ren);
  SDL_DestroyWindow(window);
  SDL_Quit();
}


int start2() {
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
    return 1;
  }

  SDL_Window* win = SDL_CreateWindow("SDL3 Image", 640, 480, 0);
  if (win == nullptr) {
    std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
    SDL_Quit();
    return 1;
  }

  SDL_Renderer* ren = SDL_CreateRenderer(win, NULL);
  if (ren == nullptr) {
    std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
    SDL_DestroyWindow(win);
    SDL_Quit();
    return 1;
  }
   SDL_SetRenderDrawColor(ren, 255, 125, 0, 255);

  SDL_Surface* bmp = SDL_CreateSurface(500, 500, SDL_PixelFormat::SDL_PIXELFORMAT_RGBA64_FLOAT);
  SDL_Rect r{0, 0, 100, 100};
  SDL_FillSurfaceRect(bmp, &r, 0);

  /* Select the color for drawing. It is set to red here. */
  //SDL_SetRenderDrawColor(ren, 255, 125, 0, 255);

  /* Clear the entire screen to our selected color. */
  //SDL_RenderClear(ren);

  /*SDL_SetRenderDrawColor(ren, 255, 0, 0, 255);

  SDL_FRect rectangle;
  rectangle.x = 0.f;
  rectangle.y = 0.f;
  rectangle.w = 10.f;
  rectangle.h = 10.f;

  SDL_RenderFillRect(ren, &rectangle);
  SDL_RenderClear(ren);*/

  //  SDL_SetRenderDrawColor(ren, 125, 0, 0, 255);

  // SDL_SetRenderDrawColor(ren, 0, 0, 0, 125);
  // SDL_SetRenderScale(ren, 2, 2);
  // SDL_RenderPoint(ren, 10, 10);

  // SDL_RenderClear(ren);

  // SDL_SetRenderDrawColor(ren, 255, 255, 255, 125);

  // SDL_FRect r{10, 10, 100, 100};
  // SDL_SetRenderDrawColor(ren, 0, 0, 0, 125);
  // SDL_RenderFillRect(ren, &r);
  // SDL_SetRenderDrawColor(ren, 0, 0, 0, 125);

  // SDL_SetRenderColorScale(ren, 2);
  // SDL_SetRenderDrawColor(ren, 125, 0, 0, 0);
  //// SDL_RenderDrawPoints(renderer, points, 4);
  // SDL_RenderLine(ren, 0, 0, 10, 10);

  // SDL_SetRenderDrawColor(ren, 125, 0, 0, 255);

  // SDL_Surface* bmp = SDL_LoadBMP(R"(C:\wasm\sdl_tutorial\resources\lettuce.bmp)");
  // if (bmp == nullptr) {
  //   std::cerr << "SDL_LoadBMP Error: " << SDL_GetError() << std::endl;
  //   SDL_DestroyRenderer(ren);
  //   SDL_DestroyWindow(win);
  //   SDL_Quit();
  //   return 1;
  // }

  // SDL_Texture* tex = SDL_CreateTextureFromSurface(ren, bmp);
  // SDL_DestroySurface(bmp);

  // if (tex == nullptr) {
  //   std::cerr << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
  //   SDL_DestroyRenderer(ren);
  //   SDL_DestroyWindow(win);
  //   SDL_Quit();
  //   return 1;
  // }

  SDL_Event e;
  bool quit = false;

  while (!quit) {
    while (SDL_PollEvent(&e)) {
      if (e.type == SDL_EVENT_QUIT) {
        quit = true;
      }
    }

    SDL_RenderClear(ren);
    // SDL_RenderTexture(ren, tex, NULL, NULL);
    SDL_RenderPresent(ren);
  }

  // SDL_DestroyTexture(tex);
  SDL_DestroyRenderer(ren);
  SDL_DestroyWindow(win);
  SDL_Quit();
}

int main(int argc, char** argv) {
  LOG("hello from lib");
  SDL_Log("%s", "Start sdl log");

  start2();

  return 0;
}
