/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   STD-Expension - stdex_base.hpp                  */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Thu Dec  1 15:21:12 CET 2022      */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#ifndef __STDEX_BASE_HPP__
# define __STDEX_BASE_HPP__

//==--------------------------------------==//
// *                                      * //
//             GLOBAL SETTINGS              //
// *                                      * //
//==--------------------------------------==//

// Namespace used by the library
// (Comment or remove to turn OFF namespace)

# define __STDEX_NAMESPACE__		stdex



//==--------------------------------------==//
// *                                      * //
//             PARAMS TRIGGERS              //
// *                                      * //
//==--------------------------------------==//

// Please don't modify below
// unless you know what you are doing

# ifdef __STDEX_NAMESPACE__
#  define __STDEX_NAMESPACE_USING__ using namespace __STDEX_NAMESPACE__;
#  define __STDEX_NAMESPACE_BEGIN__	namespace __STDEX_NAMESPACE__ {
#  define __STDEX_NAMESPACE_END__	};
# endif

#endif /* __STDEX_BASE_HPP__ */