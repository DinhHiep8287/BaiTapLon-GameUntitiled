﻿#pragma once
#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <iostream>
#include <string.h>
#include <ctime> 
#include <cstdlib> 
#include <random>
using namespace std;
#include "Transform.h"
#include "Vector2D.h"

// struct All lưu thông tin gồm : texture , tọa độ , độ cao dài , hướng texture 
struct All
{
    SDL_Texture* texture;
    float x, y, width, height;
    SDL_RendererFlip flip;


    All(SDL_Texture* _texture, float _x, float _y, float _width, float _height, SDL_RendererFlip _flip = SDL_FLIP_NONE)
    {
        texture = _texture;
        x = _x;
        y = _y;
        width = _width;
        height = _height;
        flip = _flip;
    }
};
class Object
{
public : Transform* O_tranform;
       float O_width, O_height;
       SDL_Texture* O_texture;
       SDL_RendererFlip O_flip;

       Object(All* all)
       {
           O_texture = all->texture;
           O_width = all->width;
           O_height = all->height;
           O_flip = all->flip;
           O_tranform = new Transform(all->x, all->y);
       }
       void drawObject()
       {
           
       }
       void updateObject();
       void cleanObject();  
};

