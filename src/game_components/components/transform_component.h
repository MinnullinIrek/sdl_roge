#ifndef TRANSFORMCOMPONENT_H
#define TRANSFORMCOMPONENT_H

#include "../EntityManager.h"
#include "../Game.h"
#include "headers.h"
#include "coords.h"

class TransformComponent: public Component {
    public:
  CoordPair<float> position;
     CoordPair<float> velocity;
        int width;
        int height;
        int scale;

        TransformComponent(int posX, int posY, int velX, int velY, int w, int h, int s) {
            position = CoordPair<float>(posX, posY);
          velocity = CoordPair<float>(velX, velY);
            width = w;
            height = h;
            scale = s;
        }

        void Initialize() override {
        
        }

        void Update(float deltaTime) override {
            position.x += velocity.x * deltaTime;
            position.y += velocity.y * deltaTime;
        }

        void Render() override {
            /*SDL_Rect transformRectangle = {
                (int) position.x,
                (int) position.y,
                width,
                height
            };
            SDL_SetRenderDrawColor(Game::renderer, 255, 255, 255, 255);
            SDL_RenderFillRect(Game::renderer, &transformRectangle);*/
        }
};

#endif
