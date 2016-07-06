/**
 *
 *      ┌─┐╔═╗┌┬┐┌─┐
 *      │  ║ ║ ││├┤
 *      └─┘╚═╝─┴┘└─┘
 *   ┌─┐┌─┐╔╗╔┬  ┬┌─┐┌─┐
 *   │  ├─┤║║║└┐┌┘├─┤└─┐
 *   └─┘┴ ┴╝╚╝ └┘ ┴ ┴└─┘
 *
 * Copyright (c) 2016 Code on Canvas Pty Ltd, http://CodeOnCanvas.cc
 *
 **/

#include "cocSceneObject.h"

namespace coc {

namespace scene {

Object::Object() :
    objectID(""),
    objectType(coc::scene::ObjectTypeBase),
    x(0.0f),
    y(0.0f),
    width(0.0f),
    height(0.0f),
    scale(1.0f),
    rotation(0.0f),
    color(1.0f, 1.0f, 1.0f, 1.0f),
    parent(NULL) {
    
    //
}

Object::~Object() {
    //
}

};

};