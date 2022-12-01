/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   STD-Expension - Colors.hpp                      */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Thu Dec  1 15:25:24 CET 2022      */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#ifndef __COLORS_HPP__
# define __COLORS_HPP__

# include <cstdint>
# include <utils/stdex_base.hpp>

__STDEX_NAMESPACE_BEGIN__

/* A colorfull class for easier handling of colors
 * 
 * Values can be defined with either complete integers [0, 255]
 * or with more precise types such as float or double [0, 1]
 * */
class Colors {

	public:
			////// TYPE DEFINITIONS //////

		typedef uint32_t	color_type;			// Type for whole color values
		typedef uint8_t		single_type;		// Type for a byte of values
		typedef float		precision_type;		// Type for a byte of values with precision

			////// CLASS VARIABLES ///////

		static color_type	BLACK;
		static color_type	RED;
		static color_type	GREEN;
		static color_type	BLUE;
		static color_type	CYAN;
		static color_type	PINK;
		static color_type	YELLOW;
		static color_type	WHITE;

	private:
			////// OBJECT VARIABLES //////

		color_type			_value;

	public:
			//////// CONSTRUCTORS ////////

		Colors();
		Colors(const color_type & value);
		Colors(const precision_type & red, const precision_type & green, const precision_type & blue, const precision_type & alpha = .0f);
		Colors(const single_type & red, const single_type & green, const single_type & blue, const single_type & alpha = 0);
		Colors(const Colors & src);
		~Colors();

			/////// CLASS METHODS ////////

		static color_type	fromFloat(const precision_type & red, const precision_type & green, const precision_type & blue, const precision_type & alpha = 0.0f);
		static color_type	fromRGBA(const single_type & red, const single_type & green, const single_type & blue, const single_type & alpha = 0x0);
		static color_type	fromARGB(const single_type & alpha, const single_type & red, const single_type & green, const single_type & blue);
		static color_type	mixColor(const color_type & first, const color_type & second);

			///////// OVERLOADS //////////

		Colors				&operator=(const Colors & src);
		Colors				&operator=(const color_type & value);
		Colors				operator+(const Colors & src);
		Colors				operator+(const color_type & value);
		operator			color_type();

			////////// GETTERS ///////////

		color_type			&getValue();
		color_type			getValue() const;
		single_type			getAlpha() const;
		single_type			getRed() const;
		single_type			getGreen() const;
		single_type			getBlue() const;

			////////// SETTERS ///////////

		void				setValue(const color_type & value);
		void				setAlpha(const single_type & alpha);
		void				setAlpha(const precision_type & alpha);
		void				setRed(const single_type & red);
		void				setRed(const precision_type & red);
		void				setGreen(const single_type & green);
		void				setGreen(const precision_type & green);
		void				setBlue(const single_type & blue);
		void				setBlue(const precision_type & blue);

};

__STDEX_NAMESPACE_END__

#endif /* __COLORS_HPP__ */