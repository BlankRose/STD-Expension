/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   STD-Expension - Vector2D.hpp                    */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Wed Nov 30 22:33:53 CET 2022      */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#ifndef __VECTOR2D_HPP__
# define __VECTOR2D_HPP__

/* Two dimensional vector, mostly used for
 * 2 dimensional vectorial calculus
 * */
template < typename X = float, typename Y = X, typename Diff = float >
class Vector2D
{
	private:
		/* Data */

	public:
		Vector2D();
		Vector2D(const Vector2D &src);
		~Vector2D();

		Vector2D	&operator=(const Vector2D &src);
};

#endif /* __VECTOR2D_HPP__ */