/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   STD-Expension - Colors.cpp                      */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Thu Dec  1 16:28:06 CET 2022      */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#include <Colors.hpp>
__STDEX_NAMESPACE_USING__

/* Initialize default values */

Colors::color_type		Colors::BLACK	= 0x000000;
Colors::color_type		Colors::RED		= 0xFF0000;
Colors::color_type		Colors::GREEN	= 0x00FF00;
Colors::color_type		Colors::BLUE	= 0x0000FF;
Colors::color_type		Colors::CYAN	= 0x00FFFF;
Colors::color_type		Colors::PINK	= 0xFF00FF;
Colors::color_type		Colors::YELLOW	= 0xFFFF00;
Colors::color_type		Colors::WHITE	= 0xFFFFFF;

/* ****************************************************** */
/*                                                        */
/*                      CONSTRUCTORS                      */
/* Functions called when creating or destroying an object */
/*                                                        */
/* ****************************************************** */

Colors::Colors():
	_value(0x0) {}

Colors::Colors(const color_type &v):
	_value(v) {}

Colors::Colors(	const precision_type &r, const precision_type &g,
				const precision_type &b, const precision_type &a):
	_value(fromFloat(r, g, b, a)) {}

Colors::Colors(	const single_type &r, const single_type &g,
				const single_type &b, const single_type &a):
	_value(fromRGBA(r, g, b, a)) {}

Colors::Colors(const Colors &s):
	_value(s._value) {}

Colors::~Colors() {}

/* ****************************************************** */
/*                                                        */
/*                   OPERATORS OVERLOAD                   */
/*          Functions for overloading operators           */
/*                                                        */
/* ****************************************************** */

Colors				&Colors::operator=(const Colors &s)
	{ _value = s._value; return *this; }

Colors				&Colors::operator=(const color_type &v)
	{ _value = v; return *this; }

Colors				Colors::operator+(const Colors &s)
	{ return mixColor(_value, s._value); }

Colors				Colors::operator+(const color_type &v)
	{ return mixColor(_value, v); }

Colors::operator	Colors::color_type()
	{ return _value; }

/* ****************************************************** */
/*                                                        */
/*                      CLASS METHODS                     */
/* Declarations of member functions used by ALL instances */
/*                                                        */
/* ****************************************************** */

/* Generates a color value upon given seperated RBG values
 * (float value between 0 and 1)
 *
 * @param[in]	red: Red value
 * @param[in]	green: Green value
 * @param[in]	blue: Blue value
 * @param[in]	alpha: Transparency value
 * 
 * @returns		Color value of given parameters
 */
Colors::color_type	Colors::fromFloat(
	const float & r, const float & g, const float & b, const float & a)
{
	return (((single_type)(a * 255.0f) << 24) \
			+ ((single_type)(r * 255.0f) << 16) \
			+ ((single_type)(g * 255.0f) << 8) \
			+ (single_type)(b * 255.0f));
}

/* Generates a color value upon given seperated RBG values
 * (unsigned char between 0 and 255)
 *
 * @param[in]	red: Red value
 * @param[in]	green: Green value
 * @param[in]	blue: Blue value
 * @param[in]	alpha: Transparency value
 * 
 * @returns		Color value of given parameters
 */
Colors::color_type	Colors::fromRGBA(
	const single_type & r, const single_type & g, const single_type & b, const single_type & a)
{
	return ((a << 24) + (r << 16) + (g << 8) + b);
}

/* Generates a new color, based off the mix of
 * the two given colors
 *
 * @param[in]	first: Color value
 * @param[in]	second: Color value
 * 
 * @returns		Color value of the mixed colors
 */
Colors::color_type	Colors::mixColor(const color_type & a, const color_type & b)
{
	// Checks if one is full transparent
	if (((single_type)(b >> 24)) == 0xFF) return a;
	if (((single_type)(a >> 24)) == 0xFF) return b;

	// Get each values as float between 0 and 1
	float	aa = 1.0f - (float)(single_type)(a >> 24) / 255.0f,	ba = 1.0f - (float)(single_type)(b >> 24) / 255.0f;
	float	ar = (float)(single_type)(a >> 16) / 255.0f,		br = (float)(single_type)(b >> 16) / 255.0f;
	float	ag = (float)(single_type)(a >> 8) / 255.0f,			bg = (float)(single_type)(b >> 8) / 255.0f;
	float	ab = (float)(single_type)(a) / 255.0f,				bb = (float)(single_type)(b) / 255.0f;

	// Calculate the new color
	// PS: Floats are more precise for divisions
	float	na = 1.0f - (1.0f - aa) * (1.0f - ba);
	float	nr = ar * aa / na + br * ba * (1.0f - aa) / na;
	float	ng = ag * aa / na + bg * ba * (1.0f - aa) / na;
	float	nb = ab * aa / na + bb * ba * (1.0f - aa) / na;

	// Return the new color in values between 0 and 255
	return (fromFloat(nr, ng, nb, 1.0f - na));
}

/* ****************************************************** */
/*                                                        */
/*                     OBJECT METHODS                     */
/*   Declarations of member functions used by instances   */
/*                                                        */
/* ****************************************************** */

Colors::color_type		&Colors::getValue()			{ return _value; }
Colors::color_type		Colors::getValue() const	{ return _value; }
Colors::single_type		Colors::getAlpha() const	{ return _value >> 24; }
Colors::single_type		Colors::getRed() const		{ return _value >> 16; }
Colors::single_type		Colors::getGreen() const	{ return _value >> 8; }
Colors::single_type		Colors::getBlue() const		{ return _value >> 0; }

void	Colors::setValue(const color_type &v)		{ _value = v; }
void	Colors::setRed(const single_type &r)		{ _value = fromRGBA(r, getGreen(), getBlue(), getAlpha()); }
void	Colors::setGreen(const single_type &g)		{ _value = fromRGBA(getRed(), g, getBlue(), getAlpha()); }
void	Colors::setBlue(const single_type &b)		{ _value = fromRGBA(getRed(), getGreen(), b, getAlpha()); }
void	Colors::setAlpha(const single_type &a)		{ _value = fromRGBA(getRed(), getGreen(), getBlue(), a); }
void	Colors::setRed(const precision_type &r)		{ _value = fromRGBA(255 / r, getGreen(), getBlue(), getAlpha()); }
void	Colors::setGreen(const precision_type &g)	{ _value = fromRGBA(getRed(), 255 / g, getBlue(), getAlpha()); }
void	Colors::setBlue(const precision_type &b)	{ _value = fromRGBA(getRed(), getGreen(), 255 / b, getAlpha()); }
void	Colors::setAlpha(const precision_type &a)	{ _value = fromRGBA(getRed(), getGreen(), getBlue(), 255 / a); }
