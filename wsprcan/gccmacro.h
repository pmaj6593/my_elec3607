#ifndef foopulsegccmacrohfoo
 #define foopulsegccmacrohfoo

 /***
   This file is part of PulseAudio.

   Copyright 2004-2006 Lennart Poettering

   PulseAudio is free software; you can redistribute it and/or modify
   it under the terms of the GNU Lesser General Public License as published
   by the Free Software Foundation; either version 2.1 of the License,
   or (at your option) any later version.

   PulseAudio is distributed in the hope that it will be useful, but
   WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
   General Public License for more details.

   You should have received a copy of the GNU Lesser General Public License
   along with PulseAudio; if not, see <http://www.gnu.org/licenses/>.
 ***/

 #if defined(__GNUC__)
 #ifdef __MINGW32__
 /* libintl overrides printf with a #define. As this breaks this attribute,
  * it has a workaround. However the workaround isn't enabled for MINGW
  * builds (only cygwin) */
 #define PA_GCC_PRINTF_ATTR(a,b) __attribute__ ((format (__printf__, a, b)))
 #else
 #define PA_GCC_PRINTF_ATTR(a,b) __attribute__ ((format (printf, a, b)))
 #endif
 #else

 #define PA_GCC_PRINTF_ATTR(a,b)
 #endif

 #if defined(__GNUC__) && (__GNUC__ >= 4)
 #define PA_GCC_SENTINEL __attribute__ ((sentinel))
 #else

 #define PA_GCC_SENTINEL
 #endif

 #ifdef __GNUC__
 #define PA_GCC_NORETURN __attribute__((noreturn))
 #else

 #define PA_GCC_NORETURN
 #endif

 #ifdef __GNUC__
 #define PA_GCC_UNUSED __attribute__ ((unused))
 #else

 #define PA_GCC_UNUSED
 #endif

 #ifdef __GNUC__
 #define PA_GCC_DESTRUCTOR __attribute__ ((destructor))
 #else

 #define PA_GCC_DESTRUCTOR
 #endif

 #ifndef PA_GCC_PURE
 #ifdef __GNUC__
 #define PA_GCC_PURE __attribute__ ((pure))
 #else

 #define PA_GCC_PURE
 #endif
 #endif

 #ifndef PA_GCC_CONST
 #ifdef __GNUC__
 #define PA_GCC_CONST __attribute__ ((const))
 #else

 #define PA_GCC_CONST
 #endif
 #endif

 #ifndef PA_GCC_DEPRECATED
 #ifdef __GNUC__
 #define PA_GCC_DEPRECATED __attribute__ ((deprecated))
 #else

 #define PA_GCC_DEPRECATED
 #endif
 #endif

 #ifndef PA_GCC_PACKED
 #ifdef __GNUC__
 #define PA_GCC_PACKED __attribute__ ((packed))
 #else

 #define PA_GCC_PACKED
 #endif
 #endif

 #ifndef PA_GCC_ALLOC_SIZE
 #if defined(__GNUC__) && (__GNUC__ >= 4) && (__GNUC_MINOR__ >= 3)
 #define PA_GCC_ALLOC_SIZE(x) __attribute__ ((__alloc_size__(x)))
 #define PA_GCC_ALLOC_SIZE2(x,y) __attribute__ ((__alloc_size__(x,y)))
 #else

 #define PA_GCC_ALLOC_SIZE(x)

 #define PA_GCC_ALLOC_SIZE2(x,y)
 #endif
 #endif

 #ifndef PA_GCC_MALLOC
 #ifdef __GNUC__
 #define PA_GCC_MALLOC __attribute__ ((malloc))
 #else

 #define PA_GCC_MALLOC
 #endif
 #endif

 #ifndef PA_GCC_WEAKREF
 #if defined(__GNUC__) && defined(__ELF__) && (((__GNUC__ == 4) && (__GNUC_MINOR__ > 1)) || (__GNUC__ > 4))

 #define PA_GCC_WEAKREF(x) __attribute__((weakref(#x)))
 #endif
 #endif

 #ifndef PA_LIKELY
 #ifdef __GNUC__
 #define PA_LIKELY(x) (__builtin_expect(!!(x),1))
 #define PA_UNLIKELY(x) (__builtin_expect(!!(x),0))
 #else
 #define PA_LIKELY(x) (x)
 #define PA_UNLIKELY(x) (x)
 #endif
 #endif

 #ifdef __GNUC__
 #define PA_CLAMP(x, low, high)                                          \
     __extension__ ({                                                    \
             typeof(x) _x = (x);                                         \
             typeof(low) _low = (low);                                   \
             typeof(high) _high = (high);                                \
             ((_x > _high) ? _high : ((_x < _low) ? _low : _x));         \
         })
 #else
 #define PA_CLAMP(x, low, high) (((x) > (high)) ? (high) : (((x) < (low)) ? (low) : (x)))
 #endif

 #ifdef __GNUC__
 #define PA_CLAMP_UNLIKELY(x, low, high)                                 \
     __extension__ ({                                                    \
             typeof(x) _x = (x);                                         \
             typeof(low) _low = (low);                                   \
             typeof(high) _high = (high);                                \
             (PA_UNLIKELY(_x > _high) ? _high : (PA_UNLIKELY(_x < _low) ? _low : _x)); \
         })
 #else
 #define PA_CLAMP_UNLIKELY(x, low, high) (PA_UNLIKELY((x) > (high)) ? (high) : (PA_UNLIKELY((x) < (low)) ? (low) : (x)))
 #endif

 /* We don't define a PA_CLAMP_LIKELY here, because it doesn't really
  * make sense: we cannot know if it is more likely that the value is
  * lower or greater than the boundaries. */

 #endif
