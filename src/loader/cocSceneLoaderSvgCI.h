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

#if defined( COC_CI )

#include "cocSceneLoaderSvg.h"

namespace cinder {
    class XmlTree;
}

namespace coc {
namespace scene {

//--------------------------------------------------------------
class LoaderSvgCI : public LoaderSvg {

public:

    LoaderSvgCI();
    ~LoaderSvgCI();
    
    void load(Object * object, std::string svgPath) override;

    void parseGroup(Object * object, const ci::XmlTree & xml);
    void parseGroupItem(Object * object, const ci::XmlTree & xml);
    void parseNode(Object * object, const ci::XmlTree & xml);
    void parsePath(Object * object, const ci::XmlTree & xml);
    void parsePolygon(Object * object, const ci::XmlTree & xml);
    void parsePolyline(Object * object, const ci::XmlTree & xml);
    void parseLine(Object * object, const ci::XmlTree & xml);
    void parseRect(Object * object, const ci::XmlTree & xml);
    void parseCircle(Object * object, const ci::XmlTree & xml);
    void parseEllipse(Object * object, const ci::XmlTree & xml);
    void parseUse(Object * object, const ci::XmlTree & xml);
    void parseDefs(Object * object, const ci::XmlTree & xml);
    void parseImage(Object * object, const ci::XmlTree & xml);
    void parseLinearGradient(Object * object, const ci::XmlTree & xml);
    void parseRadialGradient(Object * object, const ci::XmlTree & xml);
    void parseText(Object * object, const ci::XmlTree & xml);
    
    glm::mat3 parseTransform(const std::string & value);
    bool parseTransformComponent(const char **c, glm::mat3 * result);
    std::vector<float> parseFloatList(const char **c);
    float parseFloat(const char **sInOut);
    bool isNumeric(char c);
    
//    void load(Object * parent, const ci::XmlTree & xml);
  
    bool bDefs;
    std::map<std::string, const ci::XmlTree &> defs;
};

};
};

#endif