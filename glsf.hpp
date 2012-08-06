#ifndef __GLSF_HPP__
#define __GLSF_HPP__

#include "glsf.h"
#include <stdexcept>
#include <vector>

namespace glsf {

/**
 * @class Rect
 */
struct Rect
{
    Rect() 
      : x0(0), y0(0), x1(0), y1(0) {}
    
    Rect( float X0, float Y0, float X1, float Y1 )
      : x0(X0), y0(Y0), x1(X1), y1(Y1) {}
    
    float x0, y0, x1, y1;
};

/**
 * @class Color
 */
struct Color
{
    Color()
      : r(0), g(0), b(0), a(0) {}
    
    Color( float R, float G, float B, float A )
      : r(R), g(G), b(B), a(A) {}
    
    float r, g, b, a;
};

/**
 * @class String
 */
struct String
{
    String() {}
    
    String( const Rect& rect__, const Color& color__, const char* string__ )
      : rect(rect__), color(color__), string(string__) {}

    Rect rect;
    Color color;
    std::string string;
};

/**
 * @class Font
 */
class Font
{
public:
    Font() 
      : font_(NULL), size_(0) {}
    
    Font( const char* filename__, float size__, const char* pre__ = "" )
      : font_(NULL), size_(size__)
    {
        font_ = glsfCreateFont(filename__, size__, pre__);
        if( font_ == NULL )
            throw std::runtime_error("glsfCreateFont failed");
    }
    
    void draw( const std::vector<String>& strings__ )
    {
        glsfBegin(font_);
        for( int i = 0; i < strings__.size(); ++i )
            glsfString( 
                (float*)&strings__[i].rect,
                (float*)&strings__[i].color,
                strings__[i].string.c_str() );
        glsfEnd();
    }
    
    void draw( 
        const Rect& rect__, 
        const Color& color__, 
        const char* string__ )
    {
        glsfDrawString(font_, (float*)&rect__, (float*)&color__, string__);
    }
    
    float size() const { return size_; }

private:
    GLSFfont* font_;
    float size_;
};

} // namespace glsf

#endif
