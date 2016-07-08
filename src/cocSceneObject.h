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

#pragma once

#include "cocSceneGlobals.h"

namespace coc {
namespace scene {

enum ObjectType {
    ObjectTypeBase = 0,
    ObjectTypeShape = 1,
    ObjectTypeTexture = 2
};

class Object {

friend class Solver;
friend class Renderer;
friend class RendererCI;
friend class RendererOF;

public:

    Object(std::string objID="");
    ~Object();
    
    virtual void setup() {};
    virtual void update() {};
    virtual void draw() {};

	virtual void pointMoved(int x, int y, int mouseID) {};
	virtual void pointDragged(int x, int y, int mouseID) {};
	virtual void pointPressed(int x, int y, int mouseID) {};
	virtual void pointReleased(int x, int y, int mouseID) {};
    
    void addChild(Object & child);
    void addChildAt(Object & child, int index);
    bool removeChild(Object & child);
    bool removeChildAt(int index);
    void removeAllChildren();
    bool contains(const Object & child);
    Object & getChildAt(int index);
    Object & getChildByID(std::string objectID);
    void setChildIndex(Object & child, int index);
    int getChildIndex(const Object & child);
    int numChildren();

    coc::Value<float> x;
    coc::Value<float> y;
    coc::Value<float> width;
    coc::Value<float> height;
    coc::Value<float> scale;
    coc::Value<float> rotation;
    coc::Value<float> transformationPointX;
    coc::Value<float> transformationPointY;
    coc::Value<float> alpha;
    coc::Value<bool> visible;
    
    glm::vec4 color;
    
protected:

    std::string objectID;
    unsigned int objectType;
    
    glm::mat4 modelMatrix;
    
    coc::scene::Object * parent;
    std::vector<coc::scene::Object *> children;
    
};
};
};