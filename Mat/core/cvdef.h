#pragma once


#ifndef CV_EXPORTS
# if (defined _WIN32 || defined WINCE || defined __CYGWIN__) && defined(CVAPI_EXPORTS)
#   define CV_EXPORTS __declspec(dllexport)
# elif defined __GNUC__ && __GNUC__ >= 4 && (defined(CVAPI_EXPORTS) || defined(__APPLE__))
#   define CV_EXPORTS __attribute__ ((visibility ("default")))
# endif
#endif

#ifndef CV_EXPORTS
# define CV_EXPORTS
#endif


#ifndef CV_NOEXCEPT
#  if __cplusplus >= 201103L || (defined(_MSC_VER) && _MSC_VER >= 1900/*MSVS 2015*/)
#    define CV_NOEXCEPT noexcept
#  endif
#endif
#ifndef CV_NOEXCEPT
#  define CV_NOEXCEPT
#endif

/****************************************************************************************\
*                                  CV_NODISCARD attribute                                *
* encourages the compiler to issue a warning if the return value is discarded (C++17)    *
\****************************************************************************************/
#ifndef CV_NODISCARD
#  if defined(__GNUC__)
#    define CV_NODISCARD __attribute__((__warn_unused_result__)) // at least available with GCC 3.4
#  elif defined(__clang__) && defined(__has_attribute)
#    if __has_attribute(__warn_unused_result__)
#      define CV_NODISCARD __attribute__((__warn_unused_result__))
#    endif
#  endif
#endif
#ifndef CV_NODISCARD
#  define CV_NODISCARD /* nothing by default */
#endif