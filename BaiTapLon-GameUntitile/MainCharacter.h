﻿#pragma once
#include "Object.h"

#include "Engine.h"
#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <iostream>
#include <string.h>
#include <ctime> 
#include <cstdlib> 
#include <random>
// tất cả các Object character là kế thừa từ class Object
// cứ pháp kế thừa :
// class DuocKeThua : accessMode(public,private,...) KeThua

// 1 Constructor có thể được ghi đè trong 1 class kế thừa bằng cứ pháp 
// DuocKeThua( type st , stNew ) : KeThua (st)

// Trong trường hợp này MainCharacter mình sẽ tạo 1 contructor được đè từ class Object
class MainCharacter : public Object 
{

public : MainCharacter(All* all) : Object(all) {}
       
      

       void drawObject();
       void updateObject();
       void cleanObject();
};

