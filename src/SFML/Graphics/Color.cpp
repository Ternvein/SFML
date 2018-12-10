////////////////////////////////////////////////////////////
//
// SFML - Simple and Fast Multimedia Library
// Copyright (C) 2007-2018 Laurent Gomila (laurent@sfml-dev.org)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Graphics/Color.hpp>
#include <algorithm>


namespace sf
{
////////////////////////////////////////////////////////////
// Static member data
////////////////////////////////////////////////////////////
const Color Color::Black        (0.0f,  0.0f,   0.0f);
const Color Color::White        (1.0f,  1.0f,   1.0f);
const Color Color::Red          (1.0f,  0.0f,   0.0f);
const Color Color::Green        (0.0f,  1.0f,   0.0f);
const Color Color::Blue         (0.0f,  0.0f,   1.0f);
const Color Color::Yellow       (1.0f,  1.0f,   0.0f);
const Color Color::Magenta      (1.0f,  0.0f,   1.0f);
const Color Color::Cyan         (0.0f,  1.0f,   1.0f);
const Color Color::Transparent  (0.0f,  0.0f,   0.0f,   0.0f);


////////////////////////////////////////////////////////////
Color::Color() :
r(0),
g(0),
b(0),
a(1.0f)
{

}


////////////////////////////////////////////////////////////
Color::Color(float red, float green, float blue, float alpha) :
r(red),
g(green),
b(blue),
a(alpha)
{

}


////////////////////////////////////////////////////////////
Color::Color(Uint32 color) :
r(1.0f / 255.0f * ((color & 0xff000000) >> 24)),
g(1.0f / 255.0f * ((color & 0x00ff0000) >> 16)),
b(1.0f / 255.0f * ((color & 0x0000ff00) >> 8 )),
a(1.0f / 255.0f * ((color & 0x000000ff) >> 0 ))
{

}


////////////////////////////////////////////////////////////
Uint32 Color::toInteger() const
{
    return (Uint32(r / (1.0f / 255.0f)) << 24) | (Uint32(g / (1.0f / 255.0f)) << 16) | (Uint32(b / (1.0f / 255.0f)) << 8) | Uint32(a / (1.0f / 255.0f));
}


////////////////////////////////////////////////////////////
bool operator ==(const Color& left, const Color& right)
{
    return (left.r == right.r) &&
           (left.g == right.g) &&
           (left.b == right.b) &&
           (left.a == right.a);
}


////////////////////////////////////////////////////////////
bool operator !=(const Color& left, const Color& right)
{
    return !(left == right);
}


////////////////////////////////////////////////////////////
Color operator +(const Color& left, const Color& right)
{
    return Color(float(std::min(left.r + right.r, 1.0f)),
                 float(std::min(left.g + right.g, 1.0f)),
                 float(std::min(left.b + right.b, 1.0f)),
                 float(std::min(left.a + right.a, 1.0f)));
}


////////////////////////////////////////////////////////////
Color operator -(const Color& left, const Color& right)
{
    return Color(float(std::max(left.r - right.r, 0.0f)),
                 float(std::max(left.g - right.g, 0.0f)),
                 float(std::max(left.b - right.b, 0.0f)),
                 float(std::max(left.a - right.a, 0.0f)));
}


////////////////////////////////////////////////////////////
Color operator *(const Color& left, const Color& right)
{
    return Color(float(left.r * right.r),
                 float(left.g * right.g),
                 float(left.b * right.b),
                 float(left.a * right.a));
}


////////////////////////////////////////////////////////////
Color& operator +=(Color& left, const Color& right)
{
    return left = left + right;
}


////////////////////////////////////////////////////////////
Color& operator -=(Color& left, const Color& right)
{
    return left = left - right;
}


////////////////////////////////////////////////////////////
Color& operator *=(Color& left, const Color& right)
{
    return left = left * right;
}

} // namespace sf
