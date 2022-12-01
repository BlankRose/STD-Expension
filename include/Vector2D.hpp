/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   STD-Expension - Vector2D.hpp                    */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Thu Dec  1 15:17:01 CET 2022      */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#ifndef __VECTOR2D_HPP__
# define __VECTOR2D_HPP__

# include <cmath>
# include <iostream>
# include <utils/stdex_base.hpp>

__STDEX_NAMESPACE_BEGIN__

/* Two dimensional vector, mostly used for 2 dimensional vectorial calculus
 * 
 * Calculus can be done with vectors of other types as long as those types
 * doesn't conflits with the other's types
 * */
template < typename X = float, typename Y = X, typename Diff = float >
class Vector2D {

	public:
			////// TYPE DEFINITIONS //////

		typedef X		x_type;
		typedef Y		y_type;
		typedef Diff	distance_type;

			////// OBJECT VARIABLES //////

		x_type			x;
		y_type			y;

			//////// CONSTRUCTORS ////////

		Vector2D(x_type x = x_type(), y_type y = y_type()):
			x(x), y(y) {}

		Vector2D(const Vector2D &src):
			x(src.x), y(src.y) {}

		template <typename T, typename U>
		Vector2D(T x = T(), U y = U()):
			x(x_type(x)), y(y_type(y)) {}

		template <typename T, typename U>
		Vector2D(const Vector2D<T, U> &src):
			x(x_type(src.x)), y(y_type(src.y)) {}

		~Vector2D() {}

			/////// OBJECT METHODS ///////

		distance_type	getDistance(void) const
			{ return (sqrt(pow((distance_type) x, 2) + pow((distance_type) y, 2))); }

		distance_type	getDistance(const Vector2D &cmp)
			{ return (std::max(*this, cmp) - std::min(*this, cmp)).getDistance() ; }

			//// INCREMENTAL OVERLOADS ///

		template < typename T, typename U >
		Vector2D		&operator=(const Vector2D<T, U> &ext)
			{ x = ext.x; y = ext.y; return *this; }

		template < typename T, typename U >
		Vector2D		operator+(const Vector2D<T, U> &ext) const
			{ return Vector2D(x + ext.x, y + ext.y); }

		template < typename T, typename U >
		Vector2D		operator-(const Vector2D<T, U> &ext) const
			{ return Vector2D(x - ext.x, x - ext.y); }

		template < typename T, typename U >
		Vector2D		operator*(const Vector2D<T, U> &ext) const
			{ return Vector2D(x * ext.x, y * ext.y); }

		template < typename T, typename U >
		Vector2D		operator/(const Vector2D<T, U> &ext) const
			{ return Vector2D(x / ext.x, y / ext.y); }

		template < typename T, typename U >
		Vector2D		operator%(const Vector2D<T, U> &ext) const
			{ return Vector2D(x % ext.x, y % ext.y); }

		template < typename T, typename U >
		Vector2D		&operator+=(const Vector2D<T, U> &ext)
			{ x += ext.x; y += ext.y; return *this; }

		template < typename T, typename U >
		Vector2D		&operator-=(const Vector2D<T, U> &ext)
			{ x -= ext.x; y -= ext.y; return *this; }

		template < typename T, typename U >
		Vector2D		&operator*=(const Vector2D<T, U> &ext)
			{ x *= ext.x; y *= ext.y; return *this; }

		template < typename T, typename U >
		Vector2D		&operator/=(const Vector2D<T, U> &ext)
			{ x /= ext.x; y /= ext.y; return *this; }

		template < typename T, typename U >
		Vector2D		&operator%=(const Vector2D<T, U> &ext)
			{ x %= ext.x; y %= ext.y; return *this; }

			//// MULTIPLIERS OVERLOADS ///

		template < typename T >
		Vector2D		operator*(const T &multiplier) const
			{ return Vector2D(x * multiplier, y * multiplier); }
		template < typename T >
		Vector2D		operator/(const T &multiplier) const
			{ return Vector2D(x / multiplier, y / multiplier); }
		template < typename T >
		Vector2D		operator%(const T &multiplier) const
			{ return Vector2D(x % multiplier, y % multiplier); }

		template < typename T >
		Vector2D		&operator*=(const T &multiplier)
			{ x *= multiplier; y *= multiplier; return *this; }
		template < typename T >
		Vector2D		&operator/=(const T &multiplier)
			{ x /= multiplier; y /= multiplier; return *this; }
		template < typename T >
		Vector2D		&operator%=(const T &multiplier)
			{ x %= multiplier; y %= multiplier; return *this; }

};

	//////// COMPARAISONS ////////

template < typename LX, typename LY, typename LD, typename RX, typename RY, typename RD >
bool		operator==(const Vector2D<LX, LY, LD> &lhs, const Vector2D<RX, RY, RD> &rhs)
	{ return ( lhs.x == rhs.x && lhs.y == rhs.y ); }

template < typename LX, typename LY, typename LD, typename RX, typename RY, typename RD >
bool		operator!=(const Vector2D<LX, LY, LD> &lhs, const Vector2D<RX, RY, RD> &rhs)
	{ return !( lhs == rhs ); }

template < typename LX, typename LY, typename LD, typename RX, typename RY, typename RD >
bool		operator<(const Vector2D<LX, LY, LD> &lhs, const Vector2D<RX, RY, RD> &rhs)
	{ return ( lhs.getDistance() < rhs.getDistance() ); }

template < typename LX, typename LY, typename LD, typename RX, typename RY, typename RD >
bool		operator>(const Vector2D<LX, LY, LD> &lhs, const Vector2D<RX, RY, RD> &rhs)
	{ return ( rhs < lhs ); }

template < typename LX, typename LY, typename LD, typename RX, typename RY, typename RD >
bool		operator>=(const Vector2D<LX, LY, LD> &lhs, const Vector2D<RX, RY, RD> &rhs)
	{ return !( lhs < rhs ); }

template < typename LX, typename LY, typename LD, typename RX, typename RY, typename RD >
bool		operator<=(const Vector2D<LX, LY, LD> &lhs, const Vector2D<RX, RY, RD> &rhs)
	{ return !( rhs < lhs ); }

	/////////// OUTPUT ///////////

template <typename X, typename Y>
std::ostream		&operator<<(std::ostream &out, const Vector2D<X, Y> &v)
{
	out << v.x << ";" << v.y;
	return (out);
}

__STDEX_NAMESPACE_END__

#endif /* __VECTOR2D_HPP__ */