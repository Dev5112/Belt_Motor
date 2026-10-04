#ifndef INCLUDE_NLOHMANN_JSON_HPP_
#define INCLUDE_NLOHMANN_JSON_HPP_
#include <algorithm> 
#include <cmath> 
#include <cstddef> 
#include <cstdint> 
#include <functional> 
#include <initializer_list> 
#ifndef JSON_NO_IO
    #include <iosfwd> 
#endif  
#include <iterator> 
#include <limits> 
#include <memory> 
#include <set> 
#include <stdexcept> 
#include <string> 
#include <type_traits> 
#include <unordered_map> 
#include <utility> 
#include <vector> 
#include <utility>
#ifndef JSON_SKIP_LIBRARY_VERSION_CHECK
    #if defined(NLOHMANN_JSON_VERSION_MAJOR) && defined(NLOHMANN_JSON_VERSION_MINOR) && defined(NLOHMANN_JSON_VERSION_PATCH)
        #if NLOHMANN_JSON_VERSION_MAJOR != 3 || NLOHMANN_JSON_VERSION_MINOR != 12 || NLOHMANN_JSON_VERSION_PATCH != 0
            #warning "Already included a different version of the library!"
        #endif
    #endif
#endif
#define NLOHMANN_JSON_VERSION_MAJOR 3   
#define NLOHMANN_JSON_VERSION_MINOR 12  
#define NLOHMANN_JSON_VERSION_PATCH 0   
#ifndef JSON_DIAGNOSTICS
    #define JSON_DIAGNOSTICS 0
#endif
#ifndef JSON_DIAGNOSTIC_POSITIONS
    #define JSON_DIAGNOSTIC_POSITIONS 0
#endif
#ifndef JSON_USE_LEGACY_DISCARDED_VALUE_COMPARISON
    #define JSON_USE_LEGACY_DISCARDED_VALUE_COMPARISON 0
#endif
#ifndef JSON_BRACE_INIT_COPY_SEMANTICS
    #define JSON_BRACE_INIT_COPY_SEMANTICS 0
#endif
#ifndef JSON_PRECISE_STREAM_POSITION
    #define JSON_PRECISE_STREAM_POSITION 0
#endif
#ifndef JSON_STRICT_NUL_HANDLING
    #define JSON_STRICT_NUL_HANDLING 0
#endif
#if JSON_DIAGNOSTICS
    #define NLOHMANN_JSON_ABI_TAG_DIAGNOSTICS _diag
#else
    #define NLOHMANN_JSON_ABI_TAG_DIAGNOSTICS
#endif
#if JSON_DIAGNOSTIC_POSITIONS
    #define NLOHMANN_JSON_ABI_TAG_DIAGNOSTIC_POSITIONS _dp
#else
    #define NLOHMANN_JSON_ABI_TAG_DIAGNOSTIC_POSITIONS
#endif
#if JSON_USE_LEGACY_DISCARDED_VALUE_COMPARISON
    #define NLOHMANN_JSON_ABI_TAG_LEGACY_DISCARDED_VALUE_COMPARISON _ldvcmp
#else
    #define NLOHMANN_JSON_ABI_TAG_LEGACY_DISCARDED_VALUE_COMPARISON
#endif
#if JSON_BRACE_INIT_COPY_SEMANTICS
    #define NLOHMANN_JSON_ABI_TAG_BRACE_INIT_COPY_SEMANTICS _bics
#else
    #define NLOHMANN_JSON_ABI_TAG_BRACE_INIT_COPY_SEMANTICS
#endif
#if JSON_PRECISE_STREAM_POSITION
    #define NLOHMANN_JSON_ABI_TAG_PRECISE_STREAM_POSITION _psp
#else
    #define NLOHMANN_JSON_ABI_TAG_PRECISE_STREAM_POSITION
#endif
#if JSON_STRICT_NUL_HANDLING
    #define NLOHMANN_JSON_ABI_TAG_STRICT_NUL_HANDLING _snul
#else
    #define NLOHMANN_JSON_ABI_TAG_STRICT_NUL_HANDLING
#endif
#ifndef NLOHMANN_JSON_NAMESPACE_NO_VERSION
    #define NLOHMANN_JSON_NAMESPACE_NO_VERSION 0
#endif
#define NLOHMANN_JSON_ABI_TAGS_CONCAT_EX(a, b, c, d, e, f) json_abi ## a ## b ## c ## d ## e ## f
#define NLOHMANN_JSON_ABI_TAGS_CONCAT(a, b, c, d, e, f) \
    NLOHMANN_JSON_ABI_TAGS_CONCAT_EX(a, b, c, d, e, f)
#define NLOHMANN_JSON_ABI_TAGS                                       \
    NLOHMANN_JSON_ABI_TAGS_CONCAT(                                   \
            NLOHMANN_JSON_ABI_TAG_DIAGNOSTICS,                       \
            NLOHMANN_JSON_ABI_TAG_LEGACY_DISCARDED_VALUE_COMPARISON, \
            NLOHMANN_JSON_ABI_TAG_DIAGNOSTIC_POSITIONS,              \
            NLOHMANN_JSON_ABI_TAG_BRACE_INIT_COPY_SEMANTICS,         \
            NLOHMANN_JSON_ABI_TAG_PRECISE_STREAM_POSITION,           \
            NLOHMANN_JSON_ABI_TAG_STRICT_NUL_HANDLING)
#define NLOHMANN_JSON_NAMESPACE_VERSION_CONCAT_EX(major, minor, patch) \
    _v ## major ## _ ## minor ## _ ## patch
#define NLOHMANN_JSON_NAMESPACE_VERSION_CONCAT(major, minor, patch) \
    NLOHMANN_JSON_NAMESPACE_VERSION_CONCAT_EX(major, minor, patch)
#if NLOHMANN_JSON_NAMESPACE_NO_VERSION
#define NLOHMANN_JSON_NAMESPACE_VERSION
#else
#define NLOHMANN_JSON_NAMESPACE_VERSION                                 \
    NLOHMANN_JSON_NAMESPACE_VERSION_CONCAT(NLOHMANN_JSON_VERSION_MAJOR, \
                                           NLOHMANN_JSON_VERSION_MINOR, \
                                           NLOHMANN_JSON_VERSION_PATCH)
#endif
#define NLOHMANN_JSON_NAMESPACE_CONCAT_EX(a, b) a ## b
#define NLOHMANN_JSON_NAMESPACE_CONCAT(a, b) \
    NLOHMANN_JSON_NAMESPACE_CONCAT_EX(a, b)
#ifndef NLOHMANN_JSON_NAMESPACE
#define NLOHMANN_JSON_NAMESPACE               \
    nlohmann::NLOHMANN_JSON_NAMESPACE_CONCAT( \
            NLOHMANN_JSON_ABI_TAGS,           \
            NLOHMANN_JSON_NAMESPACE_VERSION)
#endif
#ifndef NLOHMANN_JSON_NAMESPACE_BEGIN
#define NLOHMANN_JSON_NAMESPACE_BEGIN                \
    namespace nlohmann                               \
    {                                                \
    inline namespace NLOHMANN_JSON_NAMESPACE_CONCAT( \
                NLOHMANN_JSON_ABI_TAGS,              \
                NLOHMANN_JSON_NAMESPACE_VERSION)     \
    {
#endif
#ifndef NLOHMANN_JSON_NAMESPACE_END
#define NLOHMANN_JSON_NAMESPACE_END                                     \
    }   \
    }  
#endif
#include <algorithm> 
#include <array> 
#include <forward_list> 
#include <iterator> 
#include <map> 
#include <string> 
#include <tuple> 
#include <type_traits> 
#include <unordered_map> 
#include <utility> 
#include <valarray> 
#include <vector> 
#include <cstddef> 
#include <exception> 
#if JSON_DIAGNOSTICS
    #include <numeric> 
#endif
#include <stdexcept> 
#include <string> 
#include <vector> 
#include <array> 
#include <cmath> 
#include <cstddef> 
#include <cstdint> 
#include <limits> 
#include <string> 
#include <type_traits> 
#include <utility> 
#include <type_traits>
NLOHMANN_JSON_NAMESPACE_BEGIN
namespace detail
{
template<typename ...Ts> struct make_void
{
    using type = void;
};
template<typename ...Ts> using void_t = typename make_void<Ts...>::type;
}  
NLOHMANN_JSON_NAMESPACE_END
NLOHMANN_JSON_NAMESPACE_BEGIN
namespace detail
{
struct nonesuch
{
    nonesuch() = delete;
    ~nonesuch() = delete;
    nonesuch(nonesuch const&) = delete;
    nonesuch(nonesuch const&&) = delete;
    void operator=(nonesuch const&) = delete;
    void operator=(nonesuch&&) = delete;
};
template<class Default,
         class AlwaysVoid,
         template<class...> class Op,
         class... Args>
struct detector
{
    using value_t = std::false_type;
    using type = Default;
};
template<class Default, template<class...> class Op, class... Args>
struct detector<Default, void_t<Op<Args...>>, Op, Args...>
{
    using value_t = std::true_type;
    using type = Op<Args...>;
};
template<template<class...> class Op, class... Args>
using is_detected = typename detector<nonesuch, void, Op, Args...>::value_t;
template<template<class...> class Op, class... Args>
struct is_detected_lazy : is_detected<Op, Args...> { };
template<template<class...> class Op, class... Args>
using detected_t = typename detector<nonesuch, void, Op, Args...>::type;
template<class Default, template<class...> class Op, class... Args>
using detected_or = detector<Default, void, Op, Args...>;
template<class Default, template<class...> class Op, class... Args>
using detected_or_t = typename detected_or<Default, Op, Args...>::type;
template<class Expected, template<class...> class Op, class... Args>
using is_detected_exact = std::is_same<Expected, detected_t<Op, Args...>>;
template<class To, template<class...> class Op, class... Args>
using is_detected_convertible =
    std::is_convertible<detected_t<Op, Args...>, To>;
}  
NLOHMANN_JSON_NAMESPACE_END
#if !defined(JSON_HEDLEY_VERSION) || (JSON_HEDLEY_VERSION < 15)
#if defined(JSON_HEDLEY_VERSION)
    #undef JSON_HEDLEY_VERSION
#endif
#define JSON_HEDLEY_VERSION 15
#if defined(JSON_HEDLEY_STRINGIFY_EX)
    #undef JSON_HEDLEY_STRINGIFY_EX
#endif
#define JSON_HEDLEY_STRINGIFY_EX(x) #x
#if defined(JSON_HEDLEY_STRINGIFY)
    #undef JSON_HEDLEY_STRINGIFY
#endif
#define JSON_HEDLEY_STRINGIFY(x) JSON_HEDLEY_STRINGIFY_EX(x)
#if defined(JSON_HEDLEY_CONCAT_EX)
    #undef JSON_HEDLEY_CONCAT_EX
#endif
#define JSON_HEDLEY_CONCAT_EX(a,b) a##b
#if defined(JSON_HEDLEY_CONCAT)
    #undef JSON_HEDLEY_CONCAT
#endif
#define JSON_HEDLEY_CONCAT(a,b) JSON_HEDLEY_CONCAT_EX(a,b)
#if defined(JSON_HEDLEY_CONCAT3_EX)
    #undef JSON_HEDLEY_CONCAT3_EX
#endif
#define JSON_HEDLEY_CONCAT3_EX(a,b,c) a##b##c
#if defined(JSON_HEDLEY_CONCAT3)
    #undef JSON_HEDLEY_CONCAT3
#endif
#define JSON_HEDLEY_CONCAT3(a,b,c) JSON_HEDLEY_CONCAT3_EX(a,b,c)
#if defined(JSON_HEDLEY_VERSION_ENCODE)
    #undef JSON_HEDLEY_VERSION_ENCODE
#endif
#define JSON_HEDLEY_VERSION_ENCODE(major,minor,revision) (((major) * 1000000) + ((minor) * 1000) + (revision))
#if defined(JSON_HEDLEY_VERSION_DECODE_MAJOR)
    #undef JSON_HEDLEY_VERSION_DECODE_MAJOR
#endif
#define JSON_HEDLEY_VERSION_DECODE_MAJOR(version) ((version) / 1000000)
#if defined(JSON_HEDLEY_VERSION_DECODE_MINOR)
    #undef JSON_HEDLEY_VERSION_DECODE_MINOR
#endif
#define JSON_HEDLEY_VERSION_DECODE_MINOR(version) (((version) % 1000000) / 1000)
#if defined(JSON_HEDLEY_VERSION_DECODE_REVISION)
    #undef JSON_HEDLEY_VERSION_DECODE_REVISION
#endif
#define JSON_HEDLEY_VERSION_DECODE_REVISION(version) ((version) % 1000)
#if defined(JSON_HEDLEY_GNUC_VERSION)
    #undef JSON_HEDLEY_GNUC_VERSION
#endif
#if defined(__GNUC__) && defined(__GNUC_PATCHLEVEL__)
    #define JSON_HEDLEY_GNUC_VERSION JSON_HEDLEY_VERSION_ENCODE(__GNUC__, __GNUC_MINOR__, __GNUC_PATCHLEVEL__)
#elif defined(__GNUC__)
    #define JSON_HEDLEY_GNUC_VERSION JSON_HEDLEY_VERSION_ENCODE(__GNUC__, __GNUC_MINOR__, 0)
#endif
#if defined(JSON_HEDLEY_GNUC_VERSION_CHECK)
    #undef JSON_HEDLEY_GNUC_VERSION_CHECK
#endif
#if defined(JSON_HEDLEY_GNUC_VERSION)
    #define JSON_HEDLEY_GNUC_VERSION_CHECK(major,minor,patch) (JSON_HEDLEY_GNUC_VERSION >= JSON_HEDLEY_VERSION_ENCODE(major, minor, patch))
#else
    #define JSON_HEDLEY_GNUC_VERSION_CHECK(major,minor,patch) (0)
#endif
#if defined(JSON_HEDLEY_MSVC_VERSION)
    #undef JSON_HEDLEY_MSVC_VERSION
#endif
#if defined(_MSC_FULL_VER) && (_MSC_FULL_VER >= 140000000) && !defined(__ICL)
    #define JSON_HEDLEY_MSVC_VERSION JSON_HEDLEY_VERSION_ENCODE(_MSC_FULL_VER / 10000000, (_MSC_FULL_VER % 10000000) / 100000, (_MSC_FULL_VER % 100000) / 100)
#elif defined(_MSC_FULL_VER) && !defined(__ICL)
    #define JSON_HEDLEY_MSVC_VERSION JSON_HEDLEY_VERSION_ENCODE(_MSC_FULL_VER / 1000000, (_MSC_FULL_VER % 1000000) / 10000, (_MSC_FULL_VER % 10000) / 10)
#elif defined(_MSC_VER) && !defined(__ICL)
    #define JSON_HEDLEY_MSVC_VERSION JSON_HEDLEY_VERSION_ENCODE(_MSC_VER / 100, _MSC_VER % 100, 0)
#endif
#if defined(JSON_HEDLEY_MSVC_VERSION_CHECK)
    #undef JSON_HEDLEY_MSVC_VERSION_CHECK
#endif
#if !defined(JSON_HEDLEY_MSVC_VERSION)
    #define JSON_HEDLEY_MSVC_VERSION_CHECK(major,minor,patch) (0)
#elif defined(_MSC_VER) && (_MSC_VER >= 1400)
    #define JSON_HEDLEY_MSVC_VERSION_CHECK(major,minor,patch) (_MSC_FULL_VER >= ((major * 10000000) + (minor * 100000) + (patch)))
#elif defined(_MSC_VER) && (_MSC_VER >= 1200)
    #define JSON_HEDLEY_MSVC_VERSION_CHECK(major,minor,patch) (_MSC_FULL_VER >= ((major * 1000000) + (minor * 10000) + (patch)))
#else
    #define JSON_HEDLEY_MSVC_VERSION_CHECK(major,minor,patch) (_MSC_VER >= ((major * 100) + (minor)))
#endif
#if defined(JSON_HEDLEY_INTEL_VERSION)
    #undef JSON_HEDLEY_INTEL_VERSION
#endif
#if defined(__INTEL_COMPILER) && defined(__INTEL_COMPILER_UPDATE) && !defined(__ICL)
    #define JSON_HEDLEY_INTEL_VERSION JSON_HEDLEY_VERSION_ENCODE(__INTEL_COMPILER / 100, __INTEL_COMPILER % 100, __INTEL_COMPILER_UPDATE)
#elif defined(__INTEL_COMPILER) && !defined(__ICL)
    #define JSON_HEDLEY_INTEL_VERSION JSON_HEDLEY_VERSION_ENCODE(__INTEL_COMPILER / 100, __INTEL_COMPILER % 100, 0)
#endif
#if defined(JSON_HEDLEY_INTEL_VERSION_CHECK)
    #undef JSON_HEDLEY_INTEL_VERSION_CHECK
#endif
#if defined(JSON_HEDLEY_INTEL_VERSION)
    #define JSON_HEDLEY_INTEL_VERSION_CHECK(major,minor,patch) (JSON_HEDLEY_INTEL_VERSION >= JSON_HEDLEY_VERSION_ENCODE(major, minor, patch))
#else
    #define JSON_HEDLEY_INTEL_VERSION_CHECK(major,minor,patch) (0)
#endif
#if defined(JSON_HEDLEY_INTEL_CL_VERSION)
    #undef JSON_HEDLEY_INTEL_CL_VERSION
#endif
#if defined(__INTEL_COMPILER) && defined(__INTEL_COMPILER_UPDATE) && defined(__ICL)
    #define JSON_HEDLEY_INTEL_CL_VERSION JSON_HEDLEY_VERSION_ENCODE(__INTEL_COMPILER, __INTEL_COMPILER_UPDATE, 0)
#endif
#if defined(JSON_HEDLEY_INTEL_CL_VERSION_CHECK)
    #undef JSON_HEDLEY_INTEL_CL_VERSION_CHECK
#endif
#if defined(JSON_HEDLEY_INTEL_CL_VERSION)
    #define JSON_HEDLEY_INTEL_CL_VERSION_CHECK(major,minor,patch) (JSON_HEDLEY_INTEL_CL_VERSION >= JSON_HEDLEY_VERSION_ENCODE(major, minor, patch))
#else
    #define JSON_HEDLEY_INTEL_CL_VERSION_CHECK(major,minor,patch) (0)
#endif
#if defined(JSON_HEDLEY_PGI_VERSION)
    #undef JSON_HEDLEY_PGI_VERSION
#endif
#if defined(__PGI) && defined(__PGIC__) && defined(__PGIC_MINOR__) && defined(__PGIC_PATCHLEVEL__)
    #define JSON_HEDLEY_PGI_VERSION JSON_HEDLEY_VERSION_ENCODE(__PGIC__, __PGIC_MINOR__, __PGIC_PATCHLEVEL__)
#endif
#if defined(JSON_HEDLEY_PGI_VERSION_CHECK)
    #undef JSON_HEDLEY_PGI_VERSION_CHECK
#endif
#if defined(JSON_HEDLEY_PGI_VERSION)
    #define JSON_HEDLEY_PGI_VERSION_CHECK(major,minor,patch) (JSON_HEDLEY_PGI_VERSION >= JSON_HEDLEY_VERSION_ENCODE(major, minor, patch))
#else
    #define JSON_HEDLEY_PGI_VERSION_CHECK(major,minor,patch) (0)
#endif
#if defined(JSON_HEDLEY_SUNPRO_VERSION)
    #undef JSON_HEDLEY_SUNPRO_VERSION
#endif
#if defined(__SUNPRO_C) && (__SUNPRO_C > 0x1000)
    #define JSON_HEDLEY_SUNPRO_VERSION JSON_HEDLEY_VERSION_ENCODE((((__SUNPRO_C >> 16) & 0xf) * 10) + ((__SUNPRO_C >> 12) & 0xf), (((__SUNPRO_C >> 8) & 0xf) * 10) + ((__SUNPRO_C >> 4) & 0xf), (__SUNPRO_C & 0xf) * 10)
#elif defined(__SUNPRO_C)
    #define JSON_HEDLEY_SUNPRO_VERSION JSON_HEDLEY_VERSION_ENCODE((__SUNPRO_C >> 8) & 0xf, (__SUNPRO_C >> 4) & 0xf, (__SUNPRO_C) & 0xf)
#elif defined(__SUNPRO_CC) && (__SUNPRO_CC > 0x1000)
    #define JSON_HEDLEY_SUNPRO_VERSION JSON_HEDLEY_VERSION_ENCODE((((__SUNPRO_CC >> 16) & 0xf) * 10) + ((__SUNPRO_CC >> 12) & 0xf), (((__SUNPRO_CC >> 8) & 0xf) * 10) + ((__SUNPRO_CC >> 4) & 0xf), (__SUNPRO_CC & 0xf) * 10)
#elif defined(__SUNPRO_CC)
    #define JSON_HEDLEY_SUNPRO_VERSION JSON_HEDLEY_VERSION_ENCODE((__SUNPRO_CC >> 8) & 0xf, (__SUNPRO_CC >> 4) & 0xf, (__SUNPRO_CC) & 0xf)
#endif
#if defined(JSON_HEDLEY_SUNPRO_VERSION_CHECK)
    #undef JSON_HEDLEY_SUNPRO_VERSION_CHECK
#endif
#if defined(JSON_HEDLEY_SUNPRO_VERSION)
    #define JSON_HEDLEY_SUNPRO_VERSION_CHECK(major,minor,patch) (JSON_HEDLEY_SUNPRO_VERSION >= JSON_HEDLEY_VERSION_ENCODE(major, minor, patch))
#else
    #define JSON_HEDLEY_SUNPRO_VERSION_CHECK(major,minor,patch) (0)
#endif
#if defined(JSON_HEDLEY_EMSCRIPTEN_VERSION)
    #undef JSON_HEDLEY_EMSCRIPTEN_VERSION
#endif
#if defined(__EMSCRIPTEN__)
    #define JSON_HEDLEY_EMSCRIPTEN_VERSION JSON_HEDLEY_VERSION_ENCODE(__EMSCRIPTEN_major__, __EMSCRIPTEN_minor__, __EMSCRIPTEN_tiny__)
#endif
#if defined(JSON_HEDLEY_EMSCRIPTEN_VERSION_CHECK)
    #undef JSON_HEDLEY_EMSCRIPTEN_VERSION_CHECK
#endif
#if defined(JSON_HEDLEY_EMSCRIPTEN_VERSION)
    #define JSON_HEDLEY_EMSCRIPTEN_VERSION_CHECK(major,minor,patch) (JSON_HEDLEY_EMSCRIPTEN_VERSION >= JSON_HEDLEY_VERSION_ENCODE(major, minor, patch))
#else
    #define JSON_HEDLEY_EMSCRIPTEN_VERSION_CHECK(major,minor,patch) (0)
#endif
#if defined(JSON_HEDLEY_ARM_VERSION)
    #undef JSON_HEDLEY_ARM_VERSION
#endif
#if defined(__CC_ARM) && defined(__ARMCOMPILER_VERSION)
    #define JSON_HEDLEY_ARM_VERSION JSON_HEDLEY_VERSION_ENCODE(__ARMCOMPILER_VERSION / 1000000, (__ARMCOMPILER_VERSION % 1000000) / 10000, (__ARMCOMPILER_VERSION % 10000) / 100)
#elif defined(__CC_ARM) && defined(__ARMCC_VERSION)
    #define JSON_HEDLEY_ARM_VERSION JSON_HEDLEY_VERSION_ENCODE(__ARMCC_VERSION / 1000000, (__ARMCC_VERSION % 1000000) / 10000, (__ARMCC_VERSION % 10000) / 100)
#endif
#if defined(JSON_HEDLEY_ARM_VERSION_CHECK)
    #undef JSON_HEDLEY_ARM_VERSION_CHECK
#endif
#if defined(JSON_HEDLEY_ARM_VERSION)
    #define JSON_HEDLEY_ARM_VERSION_CHECK(major,minor,patch) (JSON_HEDLEY_ARM_VERSION >= JSON_HEDLEY_VERSION_ENCODE(major, minor, patch))
#else
    #define JSON_HEDLEY_ARM_VERSION_CHECK(major,minor,patch) (0)
#endif
#if defined(JSON_HEDLEY_IBM_VERSION)
    #undef JSON_HEDLEY_IBM_VERSION
#endif
#if defined(__ibmxl__)
    #define JSON_HEDLEY_IBM_VERSION JSON_HEDLEY_VERSION_ENCODE(__ibmxl_version__, __ibmxl_release__, __ibmxl_modification__)
#elif defined(__xlC__) && defined(__xlC_ver__)
    #define JSON_HEDLEY_IBM_VERSION JSON_HEDLEY_VERSION_ENCODE(__xlC__ >> 8, __xlC__ & 0xff, (__xlC_ver__ >> 8) & 0xff)
#elif defined(__xlC__)
    #define JSON_HEDLEY_IBM_VERSION JSON_HEDLEY_VERSION_ENCODE(__xlC__ >> 8, __xlC__ & 0xff, 0)
#endif
#if defined(JSON_HEDLEY_IBM_VERSION_CHECK)
    #undef JSON_HEDLEY_IBM_VERSION_CHECK
#endif
#if defined(JSON_HEDLEY_IBM_VERSION)
    #define JSON_HEDLEY_IBM_VERSION_CHECK(major,minor,patch) (JSON_HEDLEY_IBM_VERSION >= JSON_HEDLEY_VERSION_ENCODE(major, minor, patch))
#else
    #define JSON_HEDLEY_IBM_VERSION_CHECK(major,minor,patch) (0)
#endif
#if defined(JSON_HEDLEY_TI_VERSION)
    #undef JSON_HEDLEY_TI_VERSION
#endif
#if \
    defined(__TI_COMPILER_VERSION__) && \
    ( \
      defined(__TMS470__) || defined(__TI_ARM__) || \
      defined(__MSP430__) || \
      defined(__TMS320C2000__) \
    )
#if (__TI_COMPILER_VERSION__ >= 16000000)
    #define JSON_HEDLEY_TI_VERSION JSON_HEDLEY_VERSION_ENCODE(__TI_COMPILER_VERSION__ / 1000000, (__TI_COMPILER_VERSION__ % 1000000) / 1000, (__TI_COMPILER_VERSION__ % 1000))
#endif
#endif
#if defined(JSON_HEDLEY_TI_VERSION_CHECK)
    #undef JSON_HEDLEY_TI_VERSION_CHECK
#endif
#if defined(JSON_HEDLEY_TI_VERSION)
    #define JSON_HEDLEY_TI_VERSION_CHECK(major,minor,patch) (JSON_HEDLEY_TI_VERSION >= JSON_HEDLEY_VERSION_ENCODE(major, minor, patch))
#else
    #define JSON_HEDLEY_TI_VERSION_CHECK(major,minor,patch) (0)
#endif
#if defined(JSON_HEDLEY_TI_CL2000_VERSION)
    #undef JSON_HEDLEY_TI_CL2000_VERSION
#endif
#if defined(__TI_COMPILER_VERSION__) && defined(__TMS320C2000__)
    #define JSON_HEDLEY_TI_CL2000_VERSION JSON_HEDLEY_VERSION_ENCODE(__TI_COMPILER_VERSION__ / 1000000, (__TI_COMPILER_VERSION__ % 1000000) / 1000, (__TI_COMPILER_VERSION__ % 1000))
#endif
#if defined(JSON_HEDLEY_TI_CL2000_VERSION_CHECK)
    #undef JSON_HEDLEY_TI_CL2000_VERSION_CHECK
#endif
#if defined(JSON_HEDLEY_TI_CL2000_VERSION)
    #define JSON_HEDLEY_TI_CL2000_VERSION_CHECK(major,minor,patch) (JSON_HEDLEY_TI_CL2000_VERSION >= JSON_HEDLEY_VERSION_ENCODE(major, minor, patch))
#else
    #define JSON_HEDLEY_TI_CL2000_VERSION_CHECK(major,minor,patch) (0)
#endif
#if defined(JSON_HEDLEY_TI_CL430_VERSION)
    #undef JSON_HEDLEY_TI_CL430_VERSION
#endif
#if defined(__TI_COMPILER_VERSION__) && defined(__MSP430__)
    #define JSON_HEDLEY_TI_CL430_VERSION JSON_HEDLEY_VERSION_ENCODE(__TI_COMPILER_VERSION__ / 1000000, (__TI_COMPILER_VERSION__ % 1000000) / 1000, (__TI_COMPILER_VERSION__ % 1000))
#endif
#if defined(JSON_HEDLEY_TI_CL430_VERSION_CHECK)
    #undef JSON_HEDLEY_TI_CL430_VERSION_CHECK
#endif
#if defined(JSON_HEDLEY_TI_CL430_VERSION)
    #define JSON_HEDLEY_TI_CL430_VERSION_CHECK(major,minor,patch) (JSON_HEDLEY_TI_CL430_VERSION >= JSON_HEDLEY_VERSION_ENCODE(major, minor, patch))
#else
    #define JSON_HEDLEY_TI_CL430_VERSION_CHECK(major,minor,patch) (0)
#endif
#if defined(JSON_HEDLEY_TI_ARMCL_VERSION)
    #undef JSON_HEDLEY_TI_ARMCL_VERSION
#endif
#if defined(__TI_COMPILER_VERSION__) && (defined(__TMS470__) || defined(__TI_ARM__))
    #define JSON_HEDLEY_TI_ARMCL_VERSION JSON_HEDLEY_VERSION_ENCODE(__TI_COMPILER_VERSION__ / 1000000, (__TI_COMPILER_VERSION__ % 1000000) / 1000, (__TI_COMPILER_VERSION__ % 1000))
#endif
#if defined(JSON_HEDLEY_TI_ARMCL_VERSION_CHECK)
    #undef JSON_HEDLEY_TI_ARMCL_VERSION_CHECK
#endif
#if defined(JSON_HEDLEY_TI_ARMCL_VERSION)
    #define JSON_HEDLEY_TI_ARMCL_VERSION_CHECK(major,minor,patch) (JSON_HEDLEY_TI_ARMCL_VERSION >= JSON_HEDLEY_VERSION_ENCODE(major, minor, patch))
#else
    #define JSON_HEDLEY_TI_ARMCL_VERSION_CHECK(major,minor,patch) (0)
#endif
#if defined(JSON_HEDLEY_TI_CL6X_VERSION)
    #undef JSON_HEDLEY_TI_CL6X_VERSION
#endif
#if defined(__TI_COMPILER_VERSION__) && defined(__TMS320C6X__)
    #define JSON_HEDLEY_TI_CL6X_VERSION JSON_HEDLEY_VERSION_ENCODE(__TI_COMPILER_VERSION__ / 1000000, (__TI_COMPILER_VERSION__ % 1000000) / 1000, (__TI_COMPILER_VERSION__ % 1000))
#endif
#if defined(JSON_HEDLEY_TI_CL6X_VERSION_CHECK)
    #undef JSON_HEDLEY_TI_CL6X_VERSION_CHECK
#endif
#if defined(JSON_HEDLEY_TI_CL6X_VERSION)
    #define JSON_HEDLEY_TI_CL6X_VERSION_CHECK(major,minor,patch) (JSON_HEDLEY_TI_CL6X_VERSION >= JSON_HEDLEY_VERSION_ENCODE(major, minor, patch))
#else
    #define JSON_HEDLEY_TI_CL6X_VERSION_CHECK(major,minor,patch) (0)
#endif
#if defined(JSON_HEDLEY_TI_CL7X_VERSION)
    #undef JSON_HEDLEY_TI_CL7X_VERSION
#endif
#if defined(__TI_COMPILER_VERSION__) && defined(__C7000__)
    #define JSON_HEDLEY_TI_CL7X_VERSION JSON_HEDLEY_VERSION_ENCODE(__TI_COMPILER_VERSION__ / 1000000, (__TI_COMPILER_VERSION__ % 1000000) / 1000, (__TI_COMPILER_VERSION__ % 1000))
#endif
#if defined(JSON_HEDLEY_TI_CL7X_VERSION_CHECK)
    #undef JSON_HEDLEY_TI_CL7X_VERSION_CHECK
#endif
#if defined(JSON_HEDLEY_TI_CL7X_VERSION)
    #define JSON_HEDLEY_TI_CL7X_VERSION_CHECK(major,minor,patch) (JSON_HEDLEY_TI_CL7X_VERSION >= JSON_HEDLEY_VERSION_ENCODE(major, minor, patch))
#else
    #define JSON_HEDLEY_TI_CL7X_VERSION_CHECK(major,minor,patch) (0)
#endif
#if defined(JSON_HEDLEY_TI_CLPRU_VERSION)
    #undef JSON_HEDLEY_TI_CLPRU_VERSION
#endif
#if defined(__TI_COMPILER_VERSION__) && defined(__PRU__)
    #define JSON_HEDLEY_TI_CLPRU_VERSION JSON_HEDLEY_VERSION_ENCODE(__TI_COMPILER_VERSION__ / 1000000, (__TI_COMPILER_VERSION__ % 1000000) / 1000, (__TI_COMPILER_VERSION__ % 1000))
#endif
#if defined(JSON_HEDLEY_TI_CLPRU_VERSION_CHECK)
    #undef JSON_HEDLEY_TI_CLPRU_VERSION_CHECK
#endif
#if defined(JSON_HEDLEY_TI_CLPRU_VERSION)
    #define JSON_HEDLEY_TI_CLPRU_VERSION_CHECK(major,minor,patch) (JSON_HEDLEY_TI_CLPRU_VERSION >= JSON_HEDLEY_VERSION_ENCODE(major, minor, patch))
#else
    #define JSON_HEDLEY_TI_CLPRU_VERSION_CHECK(major,minor,patch) (0)
#endif
#if defined(JSON_HEDLEY_CRAY_VERSION)
    #undef JSON_HEDLEY_CRAY_VERSION
#endif
#if defined(_CRAYC)
    #if defined(_RELEASE_PATCHLEVEL)
        #define JSON_HEDLEY_CRAY_VERSION JSON_HEDLEY_VERSION_ENCODE(_RELEASE_MAJOR, _RELEASE_MINOR, _RELEASE_PATCHLEVEL)
    #else
        #define JSON_HEDLEY_CRAY_VERSION JSON_HEDLEY_VERSION_ENCODE(_RELEASE_MAJOR, _RELEASE_MINOR, 0)
    #endif
#endif
#if defined(JSON_HEDLEY_CRAY_VERSION_CHECK)
    #undef JSON_HEDLEY_CRAY_VERSION_CHECK
#endif
#if defined(JSON_HEDLEY_CRAY_VERSION)
    #define JSON_HEDLEY_CRAY_VERSION_CHECK(major,minor,patch) (JSON_HEDLEY_CRAY_VERSION >= JSON_HEDLEY_VERSION_ENCODE(major, minor, patch))
#else
    #define JSON_HEDLEY_CRAY_VERSION_CHECK(major,minor,patch) (0)
#endif
#if defined(JSON_HEDLEY_IAR_VERSION)
    #undef JSON_HEDLEY_IAR_VERSION
#endif
#if defined(__IAR_SYSTEMS_ICC__)
    #if __VER__ > 1000
        #define JSON_HEDLEY_IAR_VERSION JSON_HEDLEY_VERSION_ENCODE((__VER__ / 1000000), ((__VER__ / 1000) % 1000), (__VER__ % 1000))
    #else
        #define JSON_HEDLEY_IAR_VERSION JSON_HEDLEY_VERSION_ENCODE(__VER__ / 100, __VER__ % 100, 0)
    #endif
#endif
#if defined(JSON_HEDLEY_IAR_VERSION_CHECK)
    #undef JSON_HEDLEY_IAR_VERSION_CHECK
#endif
#if defined(JSON_HEDLEY_IAR_VERSION)
    #define JSON_HEDLEY_IAR_VERSION_CHECK(major,minor,patch) (JSON_HEDLEY_IAR_VERSION >= JSON_HEDLEY_VERSION_ENCODE(major, minor, patch))
#else
    #define JSON_HEDLEY_IAR_VERSION_CHECK(major,minor,patch) (0)
#endif
#if defined(JSON_HEDLEY_TINYC_VERSION)
    #undef JSON_HEDLEY_TINYC_VERSION
#endif
#if defined(__TINYC__)
    #define JSON_HEDLEY_TINYC_VERSION JSON_HEDLEY_VERSION_ENCODE(__TINYC__ / 1000, (__TINYC__ / 100) % 10, __TINYC__ % 100)
#endif
#if defined(JSON_HEDLEY_TINYC_VERSION_CHECK)
    #undef JSON_HEDLEY_TINYC_VERSION_CHECK
#endif
#if defined(JSON_HEDLEY_TINYC_VERSION)
    #define JSON_HEDLEY_TINYC_VERSION_CHECK(major,minor,patch) (JSON_HEDLEY_TINYC_VERSION >= JSON_HEDLEY_VERSION_ENCODE(major, minor, patch))
#else
    #define JSON_HEDLEY_TINYC_VERSION_CHECK(major,minor,patch) (0)
#endif
#if defined(JSON_HEDLEY_DMC_VERSION)
    #undef JSON_HEDLEY_DMC_VERSION
#endif
#if defined(__DMC__)
    #define JSON_HEDLEY_DMC_VERSION JSON_HEDLEY_VERSION_ENCODE(__DMC__ >> 8, (__DMC__ >> 4) & 0xf, __DMC__ & 0xf)
#endif
#if defined(JSON_HEDLEY_DMC_VERSION_CHECK)
    #undef JSON_HEDLEY_DMC_VERSION_CHECK
#endif
#if defined(JSON_HEDLEY_DMC_VERSION)
    #define JSON_HEDLEY_DMC_VERSION_CHECK(major,minor,patch) (JSON_HEDLEY_DMC_VERSION >= JSON_HEDLEY_VERSION_ENCODE(major, minor, patch))
#else
    #define JSON_HEDLEY_DMC_VERSION_CHECK(major,minor,patch) (0)
#endif
#if defined(JSON_HEDLEY_COMPCERT_VERSION)
    #undef JSON_HEDLEY_COMPCERT_VERSION
#endif
#if defined(__COMPCERT_VERSION__)
    #define JSON_HEDLEY_COMPCERT_VERSION JSON_HEDLEY_VERSION_ENCODE(__COMPCERT_VERSION__ / 10000, (__COMPCERT_VERSION__ / 100) % 100, __COMPCERT_VERSION__ % 100)
#endif
#if defined(JSON_HEDLEY_COMPCERT_VERSION_CHECK)
    #undef JSON_HEDLEY_COMPCERT_VERSION_CHECK
#endif
#if defined(JSON_HEDLEY_COMPCERT_VERSION)
    #define JSON_HEDLEY_COMPCERT_VERSION_CHECK(major,minor,patch) (JSON_HEDLEY_COMPCERT_VERSION >= JSON_HEDLEY_VERSION_ENCODE(major, minor, patch))
#else
    #define JSON_HEDLEY_COMPCERT_VERSION_CHECK(major,minor,patch) (0)
#endif
#if defined(JSON_HEDLEY_PELLES_VERSION)
    #undef JSON_HEDLEY_PELLES_VERSION
#endif
#if defined(__POCC__)
    #define JSON_HEDLEY_PELLES_VERSION JSON_HEDLEY_VERSION_ENCODE(__POCC__ / 100, __POCC__ % 100, 0)
#endif
#if defined(JSON_HEDLEY_PELLES_VERSION_CHECK)
    #undef JSON_HEDLEY_PELLES_VERSION_CHECK
#endif
#if defined(JSON_HEDLEY_PELLES_VERSION)
    #define JSON_HEDLEY_PELLES_VERSION_CHECK(major,minor,patch) (JSON_HEDLEY_PELLES_VERSION >= JSON_HEDLEY_VERSION_ENCODE(major, minor, patch))
#else
    #define JSON_HEDLEY_PELLES_VERSION_CHECK(major,minor,patch) (0)
#endif
#if defined(JSON_HEDLEY_MCST_LCC_VERSION)
    #undef JSON_HEDLEY_MCST_LCC_VERSION
#endif
#if defined(__LCC__) && defined(__LCC_MINOR__)
    #define JSON_HEDLEY_MCST_LCC_VERSION JSON_HEDLEY_VERSION_ENCODE(__LCC__ / 100, __LCC__ % 100, __LCC_MINOR__)
#endif
#if defined(JSON_HEDLEY_MCST_LCC_VERSION_CHECK)
    #undef JSON_HEDLEY_MCST_LCC_VERSION_CHECK
#endif
#if defined(JSON_HEDLEY_MCST_LCC_VERSION)
    #define JSON_HEDLEY_MCST_LCC_VERSION_CHECK(major,minor,patch) (JSON_HEDLEY_MCST_LCC_VERSION >= JSON_HEDLEY_VERSION_ENCODE(major, minor, patch))
#else
    #define JSON_HEDLEY_MCST_LCC_VERSION_CHECK(major,minor,patch) (0)
#endif
#if defined(JSON_HEDLEY_GCC_VERSION)
    #undef JSON_HEDLEY_GCC_VERSION
#endif
#if \
    defined(JSON_HEDLEY_GNUC_VERSION) && \
    !defined(__clang__) && \
    !defined(JSON_HEDLEY_INTEL_VERSION) && \
    !defined(JSON_HEDLEY_PGI_VERSION) && \
    !defined(JSON_HEDLEY_ARM_VERSION) && \
    !defined(JSON_HEDLEY_CRAY_VERSION) && \
    !defined(JSON_HEDLEY_TI_VERSION) && \
    !defined(JSON_HEDLEY_TI_ARMCL_VERSION) && \
    !defined(JSON_HEDLEY_TI_CL430_VERSION) && \
    !defined(JSON_HEDLEY_TI_CL2000_VERSION) && \
    !defined(JSON_HEDLEY_TI_CL6X_VERSION) && \
    !defined(JSON_HEDLEY_TI_CL7X_VERSION) && \
    !defined(JSON_HEDLEY_TI_CLPRU_VERSION) && \
    !defined(__COMPCERT__) && \
    !defined(JSON_HEDLEY_MCST_LCC_VERSION)
    #define JSON_HEDLEY_GCC_VERSION JSON_HEDLEY_GNUC_VERSION
#endif
#if defined(JSON_HEDLEY_GCC_VERSION_CHECK)
    #undef JSON_HEDLEY_GCC_VERSION_CHECK
#endif
#if defined(JSON_HEDLEY_GCC_VERSION)
    #define JSON_HEDLEY_GCC_VERSION_CHECK(major,minor,patch) (JSON_HEDLEY_GCC_VERSION >= JSON_HEDLEY_VERSION_ENCODE(major, minor, patch))
#else
    #define JSON_HEDLEY_GCC_VERSION_CHECK(major,minor,patch) (0)
#endif
#if defined(JSON_HEDLEY_HAS_ATTRIBUTE)
    #undef JSON_HEDLEY_HAS_ATTRIBUTE
#endif
#if \
  defined(__has_attribute) && \
  ( \
    (!defined(JSON_HEDLEY_IAR_VERSION) || JSON_HEDLEY_IAR_VERSION_CHECK(8,5,9)) \
  )
#  define JSON_HEDLEY_HAS_ATTRIBUTE(attribute) __has_attribute(attribute)
#else
#  define JSON_HEDLEY_HAS_ATTRIBUTE(attribute) (0)
#endif
#if defined(JSON_HEDLEY_GNUC_HAS_ATTRIBUTE)
    #undef JSON_HEDLEY_GNUC_HAS_ATTRIBUTE
#endif
#if defined(__has_attribute)
    #define JSON_HEDLEY_GNUC_HAS_ATTRIBUTE(attribute,major,minor,patch) JSON_HEDLEY_HAS_ATTRIBUTE(attribute)
#else
    #define JSON_HEDLEY_GNUC_HAS_ATTRIBUTE(attribute,major,minor,patch) JSON_HEDLEY_GNUC_VERSION_CHECK(major,minor,patch)
#endif
#if defined(JSON_HEDLEY_GCC_HAS_ATTRIBUTE)
    #undef JSON_HEDLEY_GCC_HAS_ATTRIBUTE
#endif
#if defined(__has_attribute)
    #define JSON_HEDLEY_GCC_HAS_ATTRIBUTE(attribute,major,minor,patch) JSON_HEDLEY_HAS_ATTRIBUTE(attribute)
#else
    #define JSON_HEDLEY_GCC_HAS_ATTRIBUTE(attribute,major,minor,patch) JSON_HEDLEY_GCC_VERSION_CHECK(major,minor,patch)
#endif
#if defined(JSON_HEDLEY_HAS_CPP_ATTRIBUTE)
    #undef JSON_HEDLEY_HAS_CPP_ATTRIBUTE
#endif
#if \
    defined(__has_cpp_attribute) && \
    defined(__cplusplus) && \
    (!defined(JSON_HEDLEY_SUNPRO_VERSION) || JSON_HEDLEY_SUNPRO_VERSION_CHECK(5,15,0))
    #define JSON_HEDLEY_HAS_CPP_ATTRIBUTE(attribute) __has_cpp_attribute(attribute)
#else
    #define JSON_HEDLEY_HAS_CPP_ATTRIBUTE(attribute) (0)
#endif
#if defined(JSON_HEDLEY_HAS_CPP_ATTRIBUTE_NS)
    #undef JSON_HEDLEY_HAS_CPP_ATTRIBUTE_NS
#endif
#if !defined(__cplusplus) || !defined(__has_cpp_attribute)
    #define JSON_HEDLEY_HAS_CPP_ATTRIBUTE_NS(ns,attribute) (0)
#elif \
    !defined(JSON_HEDLEY_PGI_VERSION) && \
    !defined(JSON_HEDLEY_IAR_VERSION) && \
    (!defined(JSON_HEDLEY_SUNPRO_VERSION) || JSON_HEDLEY_SUNPRO_VERSION_CHECK(5,15,0)) && \
    (!defined(JSON_HEDLEY_MSVC_VERSION) || JSON_HEDLEY_MSVC_VERSION_CHECK(19,20,0))
    #define JSON_HEDLEY_HAS_CPP_ATTRIBUTE_NS(ns,attribute) JSON_HEDLEY_HAS_CPP_ATTRIBUTE(ns::attribute)
#else
    #define JSON_HEDLEY_HAS_CPP_ATTRIBUTE_NS(ns,attribute) (0)
#endif
#if defined(JSON_HEDLEY_GNUC_HAS_CPP_ATTRIBUTE)
    #undef JSON_HEDLEY_GNUC_HAS_CPP_ATTRIBUTE
#endif
#if defined(__has_cpp_attribute) && defined(__cplusplus)
    #define JSON_HEDLEY_GNUC_HAS_CPP_ATTRIBUTE(attribute,major,minor,patch) __has_cpp_attribute(attribute)
#else
    #define JSON_HEDLEY_GNUC_HAS_CPP_ATTRIBUTE(attribute,major,minor,patch) JSON_HEDLEY_GNUC_VERSION_CHECK(major,minor,patch)
#endif
#if defined(JSON_HEDLEY_GCC_HAS_CPP_ATTRIBUTE)
    #undef JSON_HEDLEY_GCC_HAS_CPP_ATTRIBUTE
#endif
#if defined(__has_cpp_attribute) && defined(__cplusplus)
    #define JSON_HEDLEY_GCC_HAS_CPP_ATTRIBUTE(attribute,major,minor,patch) __has_cpp_attribute(attribute)
#else
    #define JSON_HEDLEY_GCC_HAS_CPP_ATTRIBUTE(attribute,major,minor,patch) JSON_HEDLEY_GCC_VERSION_CHECK(major,minor,patch)
#endif
#if defined(JSON_HEDLEY_HAS_BUILTIN)
    #undef JSON_HEDLEY_HAS_BUILTIN
#endif
#if defined(__has_builtin)
    #define JSON_HEDLEY_HAS_BUILTIN(builtin) __has_builtin(builtin)
#else
    #define JSON_HEDLEY_HAS_BUILTIN(builtin) (0)
#endif
#if defined(JSON_HEDLEY_GNUC_HAS_BUILTIN)
    #undef JSON_HEDLEY_GNUC_HAS_BUILTIN
#endif
#if defined(__has_builtin)
    #define JSON_HEDLEY_GNUC_HAS_BUILTIN(builtin,major,minor,patch) __has_builtin(builtin)
#else
    #define JSON_HEDLEY_GNUC_HAS_BUILTIN(builtin,major,minor,patch) JSON_HEDLEY_GNUC_VERSION_CHECK(major,minor,patch)
#endif
#if defined(JSON_HEDLEY_GCC_HAS_BUILTIN)
    #undef JSON_HEDLEY_GCC_HAS_BUILTIN
#endif
#if defined(__has_builtin)
    #define JSON_HEDLEY_GCC_HAS_BUILTIN(builtin,major,minor,patch) __has_builtin(builtin)
#else
    #define JSON_HEDLEY_GCC_HAS_BUILTIN(builtin,major,minor,patch) JSON_HEDLEY_GCC_VERSION_CHECK(major,minor,patch)
#endif
#if defined(JSON_HEDLEY_HAS_FEATURE)
    #undef JSON_HEDLEY_HAS_FEATURE
#endif
#if defined(__has_feature)
    #define JSON_HEDLEY_HAS_FEATURE(feature) __has_feature(feature)
#else
    #define JSON_HEDLEY_HAS_FEATURE(feature) (0)
#endif
#if defined(JSON_HEDLEY_GNUC_HAS_FEATURE)
    #undef JSON_HEDLEY_GNUC_HAS_FEATURE
#endif
#if defined(__has_feature)
    #define JSON_HEDLEY_GNUC_HAS_FEATURE(feature,major,minor,patch) __has_feature(feature)
#else
    #define JSON_HEDLEY_GNUC_HAS_FEATURE(feature,major,minor,patch) JSON_HEDLEY_GNUC_VERSION_CHECK(major,minor,patch)
#endif
#if defined(JSON_HEDLEY_GCC_HAS_FEATURE)
    #undef JSON_HEDLEY_GCC_HAS_FEATURE
#endif
#if defined(__has_feature)
    #define JSON_HEDLEY_GCC_HAS_FEATURE(feature,major,minor,patch) __has_feature(feature)
#else
    #define JSON_HEDLEY_GCC_HAS_FEATURE(feature,major,minor,patch) JSON_HEDLEY_GCC_VERSION_CHECK(major,minor,patch)
#endif
#if defined(JSON_HEDLEY_HAS_EXTENSION)
    #undef JSON_HEDLEY_HAS_EXTENSION
#endif
#if defined(__has_extension)
    #define JSON_HEDLEY_HAS_EXTENSION(extension) __has_extension(extension)
#else
    #define JSON_HEDLEY_HAS_EXTENSION(extension) (0)
#endif
#if defined(JSON_HEDLEY_GNUC_HAS_EXTENSION)
    #undef JSON_HEDLEY_GNUC_HAS_EXTENSION
#endif
#if defined(__has_extension)
    #define JSON_HEDLEY_GNUC_HAS_EXTENSION(extension,major,minor,patch) __has_extension(extension)
#else
    #define JSON_HEDLEY_GNUC_HAS_EXTENSION(extension,major,minor,patch) JSON_HEDLEY_GNUC_VERSION_CHECK(major,minor,patch)
#endif
#if defined(JSON_HEDLEY_GCC_HAS_EXTENSION)
    #undef JSON_HEDLEY_GCC_HAS_EXTENSION
#endif
#if defined(__has_extension)
    #define JSON_HEDLEY_GCC_HAS_EXTENSION(extension,major,minor,patch) __has_extension(extension)
#else
    #define JSON_HEDLEY_GCC_HAS_EXTENSION(extension,major,minor,patch) JSON_HEDLEY_GCC_VERSION_CHECK(major,minor,patch)
#endif
#if defined(JSON_HEDLEY_HAS_DECLSPEC_ATTRIBUTE)
    #undef JSON_HEDLEY_HAS_DECLSPEC_ATTRIBUTE
#endif
#if defined(__has_declspec_attribute)
    #define JSON_HEDLEY_HAS_DECLSPEC_ATTRIBUTE(attribute) __has_declspec_attribute(attribute)
#else
    #define JSON_HEDLEY_HAS_DECLSPEC_ATTRIBUTE(attribute) (0)
#endif
#if defined(JSON_HEDLEY_GNUC_HAS_DECLSPEC_ATTRIBUTE)
    #undef JSON_HEDLEY_GNUC_HAS_DECLSPEC_ATTRIBUTE
#endif
#if defined(__has_declspec_attribute)
    #define JSON_HEDLEY_GNUC_HAS_DECLSPEC_ATTRIBUTE(attribute,major,minor,patch) __has_declspec_attribute(attribute)
#else
    #define JSON_HEDLEY_GNUC_HAS_DECLSPEC_ATTRIBUTE(attribute,major,minor,patch) JSON_HEDLEY_GNUC_VERSION_CHECK(major,minor,patch)
#endif
#if defined(JSON_HEDLEY_GCC_HAS_DECLSPEC_ATTRIBUTE)
    #undef JSON_HEDLEY_GCC_HAS_DECLSPEC_ATTRIBUTE
#endif
#if defined(__has_declspec_attribute)
    #define JSON_HEDLEY_GCC_HAS_DECLSPEC_ATTRIBUTE(attribute,major,minor,patch) __has_declspec_attribute(attribute)
#else
    #define JSON_HEDLEY_GCC_HAS_DECLSPEC_ATTRIBUTE(attribute,major,minor,patch) JSON_HEDLEY_GCC_VERSION_CHECK(major,minor,patch)
#endif
#if defined(JSON_HEDLEY_HAS_WARNING)
    #undef JSON_HEDLEY_HAS_WARNING
#endif
#if defined(__has_warning)
    #define JSON_HEDLEY_HAS_WARNING(warning) __has_warning(warning)
#else
    #define JSON_HEDLEY_HAS_WARNING(warning) (0)
#endif
#if defined(JSON_HEDLEY_GNUC_HAS_WARNING)
    #undef JSON_HEDLEY_GNUC_HAS_WARNING
#endif
#if defined(__has_warning)
    #define JSON_HEDLEY_GNUC_HAS_WARNING(warning,major,minor,patch) __has_warning(warning)
#else
    #define JSON_HEDLEY_GNUC_HAS_WARNING(warning,major,minor,patch) JSON_HEDLEY_GNUC_VERSION_CHECK(major,minor,patch)
#endif
#if defined(JSON_HEDLEY_GCC_HAS_WARNING)
    #undef JSON_HEDLEY_GCC_HAS_WARNING
#endif
#if defined(__has_warning)
    #define JSON_HEDLEY_GCC_HAS_WARNING(warning,major,minor,patch) __has_warning(warning)
#else
    #define JSON_HEDLEY_GCC_HAS_WARNING(warning,major,minor,patch) JSON_HEDLEY_GCC_VERSION_CHECK(major,minor,patch)
#endif
#if \
    (defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901L)) || \
    defined(__clang__) || \
    JSON_HEDLEY_GCC_VERSION_CHECK(3,0,0) || \
    JSON_HEDLEY_INTEL_VERSION_CHECK(13,0,0) || \
    JSON_HEDLEY_IAR_VERSION_CHECK(8,0,0) || \
    JSON_HEDLEY_PGI_VERSION_CHECK(18,4,0) || \
    JSON_HEDLEY_ARM_VERSION_CHECK(4,1,0) || \
    JSON_HEDLEY_TI_VERSION_CHECK(15,12,0) || \
    JSON_HEDLEY_TI_ARMCL_VERSION_CHECK(4,7,0) || \
    JSON_HEDLEY_TI_CL430_VERSION_CHECK(2,0,1) || \
    JSON_HEDLEY_TI_CL2000_VERSION_CHECK(6,1,0) || \
    JSON_HEDLEY_TI_CL6X_VERSION_CHECK(7,0,0) || \
    JSON_HEDLEY_TI_CL7X_VERSION_CHECK(1,2,0) || \
    JSON_HEDLEY_TI_CLPRU_VERSION_CHECK(2,1,0) || \
    JSON_HEDLEY_CRAY_VERSION_CHECK(5,0,0) || \
    JSON_HEDLEY_TINYC_VERSION_CHECK(0,9,17) || \
    JSON_HEDLEY_SUNPRO_VERSION_CHECK(8,0,0) || \
    (JSON_HEDLEY_IBM_VERSION_CHECK(10,1,0) && defined(__C99_PRAGMA_OPERATOR))
    #define JSON_HEDLEY_PRAGMA(value) _Pragma(#value)
#elif JSON_HEDLEY_MSVC_VERSION_CHECK(15,0,0)
    #define JSON_HEDLEY_PRAGMA(value) __pragma(value)
#else
    #define JSON_HEDLEY_PRAGMA(value)
#endif
#if defined(JSON_HEDLEY_DIAGNOSTIC_PUSH)
    #undef JSON_HEDLEY_DIAGNOSTIC_PUSH
#endif
#if defined(JSON_HEDLEY_DIAGNOSTIC_POP)
    #undef JSON_HEDLEY_DIAGNOSTIC_POP
#endif
#if defined(__clang__)
    #define JSON_HEDLEY_DIAGNOSTIC_PUSH _Pragma("clang diagnostic push")
    #define JSON_HEDLEY_DIAGNOSTIC_POP _Pragma("clang diagnostic pop")
#elif JSON_HEDLEY_INTEL_VERSION_CHECK(13,0,0)
    #define JSON_HEDLEY_DIAGNOSTIC_PUSH _Pragma("warning(push)")
    #define JSON_HEDLEY_DIAGNOSTIC_POP _Pragma("warning(pop)")
#elif JSON_HEDLEY_GCC_VERSION_CHECK(4,6,0)
    #define JSON_HEDLEY_DIAGNOSTIC_PUSH _Pragma("GCC diagnostic push")
    #define JSON_HEDLEY_DIAGNOSTIC_POP _Pragma("GCC diagnostic pop")
#elif \
    JSON_HEDLEY_MSVC_VERSION_CHECK(15,0,0) || \
    JSON_HEDLEY_INTEL_CL_VERSION_CHECK(2021,1,0)
    #define JSON_HEDLEY_DIAGNOSTIC_PUSH __pragma(warning(push))
    #define JSON_HEDLEY_DIAGNOSTIC_POP __pragma(warning(pop))
#elif JSON_HEDLEY_ARM_VERSION_CHECK(5,6,0)
    #define JSON_HEDLEY_DIAGNOSTIC_PUSH _Pragma("push")
    #define JSON_HEDLEY_DIAGNOSTIC_POP _Pragma("pop")
#elif \
    JSON_HEDLEY_TI_VERSION_CHECK(15,12,0) || \
    JSON_HEDLEY_TI_ARMCL_VERSION_CHECK(5,2,0) || \
    JSON_HEDLEY_TI_CL430_VERSION_CHECK(4,4,0) || \
    JSON_HEDLEY_TI_CL6X_VERSION_CHECK(8,1,0) || \
    JSON_HEDLEY_TI_CL7X_VERSION_CHECK(1,2,0) || \
    JSON_HEDLEY_TI_CLPRU_VERSION_CHECK(2,1,0)
    #define JSON_HEDLEY_DIAGNOSTIC_PUSH _Pragma("diag_push")
    #define JSON_HEDLEY_DIAGNOSTIC_POP _Pragma("diag_pop")
#elif JSON_HEDLEY_PELLES_VERSION_CHECK(2,90,0)
    #define JSON_HEDLEY_DIAGNOSTIC_PUSH _Pragma("warning(push)")
    #define JSON_HEDLEY_DIAGNOSTIC_POP _Pragma("warning(pop)")
#else
    #define JSON_HEDLEY_DIAGNOSTIC_PUSH
    #define JSON_HEDLEY_DIAGNOSTIC_POP
#endif
#if defined(JSON_HEDLEY_DIAGNOSTIC_DISABLE_CPP98_COMPAT_WRAP_)
    #undef JSON_HEDLEY_DIAGNOSTIC_DISABLE_CPP98_COMPAT_WRAP_
#endif
#if defined(__cplusplus)
#  if JSON_HEDLEY_HAS_WARNING("-Wc++98-compat")
#    if JSON_HEDLEY_HAS_WARNING("-Wc++17-extensions")
#      if JSON_HEDLEY_HAS_WARNING("-Wc++1z-extensions")
#        define JSON_HEDLEY_DIAGNOSTIC_DISABLE_CPP98_COMPAT_WRAP_(xpr) \
    JSON_HEDLEY_DIAGNOSTIC_PUSH \
    _Pragma("clang diagnostic ignored \"-Wc++98-compat\"") \
    _Pragma("clang diagnostic ignored \"-Wc++17-extensions\"") \
    _Pragma("clang diagnostic ignored \"-Wc++1z-extensions\"") \
    xpr \
    JSON_HEDLEY_DIAGNOSTIC_POP
#      else
#        define JSON_HEDLEY_DIAGNOSTIC_DISABLE_CPP98_COMPAT_WRAP_(xpr) \
    JSON_HEDLEY_DIAGNOSTIC_PUSH \
    _Pragma("clang diagnostic ignored \"-Wc++98-compat\"") \
    _Pragma("clang diagnostic ignored \"-Wc++17-extensions\"") \
    xpr \
    JSON_HEDLEY_DIAGNOSTIC_POP
#      endif
#    else
#      define JSON_HEDLEY_DIAGNOSTIC_DISABLE_CPP98_COMPAT_WRAP_(xpr) \
    JSON_HEDLEY_DIAGNOSTIC_PUSH \
    _Pragma("clang diagnostic ignored \"-Wc++98-compat\"") \
    xpr \
    JSON_HEDLEY_DIAGNOSTIC_POP
#    endif
#  endif
#endif
#if !defined(JSON_HEDLEY_DIAGNOSTIC_DISABLE_CPP98_COMPAT_WRAP_)
    #define JSON_HEDLEY_DIAGNOSTIC_DISABLE_CPP98_COMPAT_WRAP_(x) x
#endif
#if defined(JSON_HEDLEY_CONST_CAST)
    #undef JSON_HEDLEY_CONST_CAST
#endif
#if defined(__cplusplus)
#  define JSON_HEDLEY_CONST_CAST(T, expr) (const_cast<T>(expr))
#elif \
  JSON_HEDLEY_HAS_WARNING("-Wcast-qual") || \
  JSON_HEDLEY_GCC_VERSION_CHECK(4,6,0) || \
  JSON_HEDLEY_INTEL_VERSION_CHECK(13,0,0)
#  define JSON_HEDLEY_CONST_CAST(T, expr) (__extension__ ({ \
        JSON_HEDLEY_DIAGNOSTIC_PUSH \
        JSON_HEDLEY_DIAGNOSTIC_DISABLE_CAST_QUAL \
        ((T) (expr)); \
        JSON_HEDLEY_DIAGNOSTIC_POP \
    }))
#else
#  define JSON_HEDLEY_CONST_CAST(T, expr) ((T) (expr))
#endif
#if defined(JSON_HEDLEY_REINTERPRET_CAST)
    #undef JSON_HEDLEY_REINTERPRET_CAST
#endif
#if defined(__cplusplus)
    #define JSON_HEDLEY_REINTERPRET_CAST(T, expr) (reinterpret_cast<T>(expr))
#else
    #define JSON_HEDLEY_REINTERPRET_CAST(T, expr) ((T) (expr))
#endif
#if defined(JSON_HEDLEY_STATIC_CAST)
    #undef JSON_HEDLEY_STATIC_CAST
#endif
#if defined(__cplusplus)
    #define JSON_HEDLEY_STATIC_CAST(T, expr) (static_cast<T>(expr))
#else
    #define JSON_HEDLEY_STATIC_CAST(T, expr) ((T) (expr))
#endif
#if defined(JSON_HEDLEY_CPP_CAST)
    #undef JSON_HEDLEY_CPP_CAST
#endif
#if defined(__cplusplus)
#  if JSON_HEDLEY_HAS_WARNING("-Wold-style-cast")
#    define JSON_HEDLEY_CPP_CAST(T, expr) \
    JSON_HEDLEY_DIAGNOSTIC_PUSH \
    _Pragma("clang diagnostic ignored \"-Wold-style-cast\"") \
    ((T) (expr)) \
    JSON_HEDLEY_DIAGNOSTIC_POP
#  elif JSON_HEDLEY_IAR_VERSION_CHECK(8,3,0)
#    define JSON_HEDLEY_CPP_CAST(T, expr) \
    JSON_HEDLEY_DIAGNOSTIC_PUSH \
    _Pragma("diag_suppress=Pe137") \
    JSON_HEDLEY_DIAGNOSTIC_POP
#  else
#    define JSON_HEDLEY_CPP_CAST(T, expr) ((T) (expr))
#  endif
#else
#  define JSON_HEDLEY_CPP_CAST(T, expr) (expr)
#endif
#if defined(JSON_HEDLEY_DIAGNOSTIC_DISABLE_DEPRECATED)
    #undef JSON_HEDLEY_DIAGNOSTIC_DISABLE_DEPRECATED
#endif
#if JSON_HEDLEY_HAS_WARNING("-Wdeprecated-declarations")
    #define JSON_HEDLEY_DIAGNOSTIC_DISABLE_DEPRECATED _Pragma("clang diagnostic ignored \"-Wdeprecated-declarations\"")
#elif JSON_HEDLEY_INTEL_VERSION_CHECK(13,0,0)
    #define JSON_HEDLEY_DIAGNOSTIC_DISABLE_DEPRECATED _Pragma("warning(disable:1478 1786)")
#elif JSON_HEDLEY_INTEL_CL_VERSION_CHECK(2021,1,0)
    #define JSON_HEDLEY_DIAGNOSTIC_DISABLE_DEPRECATED __pragma(warning(disable:1478 1786))
#elif JSON_HEDLEY_PGI_VERSION_CHECK(20,7,0)
    #define JSON_HEDLEY_DIAGNOSTIC_DISABLE_DEPRECATED _Pragma("diag_suppress 1215,1216,1444,1445")
#elif JSON_HEDLEY_PGI_VERSION_CHECK(17,10,0)
    #define JSON_HEDLEY_DIAGNOSTIC_DISABLE_DEPRECATED _Pragma("diag_suppress 1215,1444")
#elif JSON_HEDLEY_GCC_VERSION_CHECK(4,3,0)
    #define JSON_HEDLEY_DIAGNOSTIC_DISABLE_DEPRECATED _Pragma("GCC diagnostic ignored \"-Wdeprecated-declarations\"")
#elif JSON_HEDLEY_MSVC_VERSION_CHECK(15,0,0)
    #define JSON_HEDLEY_DIAGNOSTIC_DISABLE_DEPRECATED __pragma(warning(disable:4996))
#elif JSON_HEDLEY_MCST_LCC_VERSION_CHECK(1,25,10)
    #define JSON_HEDLEY_DIAGNOSTIC_DISABLE_DEPRECATED _Pragma("diag_suppress 1215,1444")
#elif \
    JSON_HEDLEY_TI_VERSION_CHECK(15,12,0) || \
    (JSON_HEDLEY_TI_ARMCL_VERSION_CHECK(4,8,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
    JSON_HEDLEY_TI_ARMCL_VERSION_CHECK(5,2,0) || \
    (JSON_HEDLEY_TI_CL2000_VERSION_CHECK(6,0,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
    JSON_HEDLEY_TI_CL2000_VERSION_CHECK(6,4,0) || \
    (JSON_HEDLEY_TI_CL430_VERSION_CHECK(4,0,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
    JSON_HEDLEY_TI_CL430_VERSION_CHECK(4,3,0) || \
    (JSON_HEDLEY_TI_CL6X_VERSION_CHECK(7,2,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
    JSON_HEDLEY_TI_CL6X_VERSION_CHECK(7,5,0) || \
    JSON_HEDLEY_TI_CL7X_VERSION_CHECK(1,2,0) || \
    JSON_HEDLEY_TI_CLPRU_VERSION_CHECK(2,1,0)
    #define JSON_HEDLEY_DIAGNOSTIC_DISABLE_DEPRECATED _Pragma("diag_suppress 1291,1718")
#elif JSON_HEDLEY_SUNPRO_VERSION_CHECK(5,13,0) && !defined(__cplusplus)
    #define JSON_HEDLEY_DIAGNOSTIC_DISABLE_DEPRECATED _Pragma("error_messages(off,E_DEPRECATED_ATT,E_DEPRECATED_ATT_MESS)")
#elif JSON_HEDLEY_SUNPRO_VERSION_CHECK(5,13,0) && defined(__cplusplus)
    #define JSON_HEDLEY_DIAGNOSTIC_DISABLE_DEPRECATED _Pragma("error_messages(off,symdeprecated,symdeprecated2)")
#elif JSON_HEDLEY_IAR_VERSION_CHECK(8,0,0)
    #define JSON_HEDLEY_DIAGNOSTIC_DISABLE_DEPRECATED _Pragma("diag_suppress=Pe1444,Pe1215")
#elif JSON_HEDLEY_PELLES_VERSION_CHECK(2,90,0)
    #define JSON_HEDLEY_DIAGNOSTIC_DISABLE_DEPRECATED _Pragma("warn(disable:2241)")
#else
    #define JSON_HEDLEY_DIAGNOSTIC_DISABLE_DEPRECATED
#endif
#if defined(JSON_HEDLEY_DIAGNOSTIC_DISABLE_UNKNOWN_PRAGMAS)
    #undef JSON_HEDLEY_DIAGNOSTIC_DISABLE_UNKNOWN_PRAGMAS
#endif
#if JSON_HEDLEY_HAS_WARNING("-Wunknown-pragmas")
    #define JSON_HEDLEY_DIAGNOSTIC_DISABLE_UNKNOWN_PRAGMAS _Pragma("clang diagnostic ignored \"-Wunknown-pragmas\"")
#elif JSON_HEDLEY_INTEL_VERSION_CHECK(13,0,0)
    #define JSON_HEDLEY_DIAGNOSTIC_DISABLE_UNKNOWN_PRAGMAS _Pragma("warning(disable:161)")
#elif JSON_HEDLEY_INTEL_CL_VERSION_CHECK(2021,1,0)
    #define JSON_HEDLEY_DIAGNOSTIC_DISABLE_UNKNOWN_PRAGMAS __pragma(warning(disable:161))
#elif JSON_HEDLEY_PGI_VERSION_CHECK(17,10,0)
    #define JSON_HEDLEY_DIAGNOSTIC_DISABLE_UNKNOWN_PRAGMAS _Pragma("diag_suppress 1675")
#elif JSON_HEDLEY_GCC_VERSION_CHECK(4,3,0)
    #define JSON_HEDLEY_DIAGNOSTIC_DISABLE_UNKNOWN_PRAGMAS _Pragma("GCC diagnostic ignored \"-Wunknown-pragmas\"")
#elif JSON_HEDLEY_MSVC_VERSION_CHECK(15,0,0)
    #define JSON_HEDLEY_DIAGNOSTIC_DISABLE_UNKNOWN_PRAGMAS __pragma(warning(disable:4068))
#elif \
    JSON_HEDLEY_TI_VERSION_CHECK(16,9,0) || \
    JSON_HEDLEY_TI_CL6X_VERSION_CHECK(8,0,0) || \
    JSON_HEDLEY_TI_CL7X_VERSION_CHECK(1,2,0) || \
    JSON_HEDLEY_TI_CLPRU_VERSION_CHECK(2,3,0)
    #define JSON_HEDLEY_DIAGNOSTIC_DISABLE_UNKNOWN_PRAGMAS _Pragma("diag_suppress 163")
#elif JSON_HEDLEY_TI_CL6X_VERSION_CHECK(8,0,0)
    #define JSON_HEDLEY_DIAGNOSTIC_DISABLE_UNKNOWN_PRAGMAS _Pragma("diag_suppress 163")
#elif JSON_HEDLEY_IAR_VERSION_CHECK(8,0,0)
    #define JSON_HEDLEY_DIAGNOSTIC_DISABLE_UNKNOWN_PRAGMAS _Pragma("diag_suppress=Pe161")
#elif JSON_HEDLEY_MCST_LCC_VERSION_CHECK(1,25,10)
    #define JSON_HEDLEY_DIAGNOSTIC_DISABLE_UNKNOWN_PRAGMAS _Pragma("diag_suppress 161")
#else
    #define JSON_HEDLEY_DIAGNOSTIC_DISABLE_UNKNOWN_PRAGMAS
#endif
#if defined(JSON_HEDLEY_DIAGNOSTIC_DISABLE_UNKNOWN_CPP_ATTRIBUTES)
    #undef JSON_HEDLEY_DIAGNOSTIC_DISABLE_UNKNOWN_CPP_ATTRIBUTES
#endif
#if JSON_HEDLEY_HAS_WARNING("-Wunknown-attributes")
    #define JSON_HEDLEY_DIAGNOSTIC_DISABLE_UNKNOWN_CPP_ATTRIBUTES _Pragma("clang diagnostic ignored \"-Wunknown-attributes\"")
#elif JSON_HEDLEY_GCC_VERSION_CHECK(4,6,0)
    #define JSON_HEDLEY_DIAGNOSTIC_DISABLE_UNKNOWN_CPP_ATTRIBUTES _Pragma("GCC diagnostic ignored \"-Wdeprecated-declarations\"")
#elif JSON_HEDLEY_INTEL_VERSION_CHECK(17,0,0)
    #define JSON_HEDLEY_DIAGNOSTIC_DISABLE_UNKNOWN_CPP_ATTRIBUTES _Pragma("warning(disable:1292)")
#elif JSON_HEDLEY_INTEL_CL_VERSION_CHECK(2021,1,0)
    #define JSON_HEDLEY_DIAGNOSTIC_DISABLE_UNKNOWN_CPP_ATTRIBUTES __pragma(warning(disable:1292))
#elif JSON_HEDLEY_MSVC_VERSION_CHECK(19,0,0)
    #define JSON_HEDLEY_DIAGNOSTIC_DISABLE_UNKNOWN_CPP_ATTRIBUTES __pragma(warning(disable:5030))
#elif JSON_HEDLEY_PGI_VERSION_CHECK(20,7,0)
    #define JSON_HEDLEY_DIAGNOSTIC_DISABLE_UNKNOWN_CPP_ATTRIBUTES _Pragma("diag_suppress 1097,1098")
#elif JSON_HEDLEY_PGI_VERSION_CHECK(17,10,0)
    #define JSON_HEDLEY_DIAGNOSTIC_DISABLE_UNKNOWN_CPP_ATTRIBUTES _Pragma("diag_suppress 1097")
#elif JSON_HEDLEY_SUNPRO_VERSION_CHECK(5,14,0) && defined(__cplusplus)
    #define JSON_HEDLEY_DIAGNOSTIC_DISABLE_UNKNOWN_CPP_ATTRIBUTES _Pragma("error_messages(off,attrskipunsup)")
#elif \
    JSON_HEDLEY_TI_VERSION_CHECK(18,1,0) || \
    JSON_HEDLEY_TI_CL6X_VERSION_CHECK(8,3,0) || \
    JSON_HEDLEY_TI_CL7X_VERSION_CHECK(1,2,0)
    #define JSON_HEDLEY_DIAGNOSTIC_DISABLE_UNKNOWN_CPP_ATTRIBUTES _Pragma("diag_suppress 1173")
#elif JSON_HEDLEY_IAR_VERSION_CHECK(8,0,0)
    #define JSON_HEDLEY_DIAGNOSTIC_DISABLE_UNKNOWN_CPP_ATTRIBUTES _Pragma("diag_suppress=Pe1097")
#elif JSON_HEDLEY_MCST_LCC_VERSION_CHECK(1,25,10)
    #define JSON_HEDLEY_DIAGNOSTIC_DISABLE_UNKNOWN_CPP_ATTRIBUTES _Pragma("diag_suppress 1097")
#else
    #define JSON_HEDLEY_DIAGNOSTIC_DISABLE_UNKNOWN_CPP_ATTRIBUTES
#endif
#if defined(JSON_HEDLEY_DIAGNOSTIC_DISABLE_CAST_QUAL)
    #undef JSON_HEDLEY_DIAGNOSTIC_DISABLE_CAST_QUAL
#endif
#if JSON_HEDLEY_HAS_WARNING("-Wcast-qual")
    #define JSON_HEDLEY_DIAGNOSTIC_DISABLE_CAST_QUAL _Pragma("clang diagnostic ignored \"-Wcast-qual\"")
#elif JSON_HEDLEY_INTEL_VERSION_CHECK(13,0,0)
    #define JSON_HEDLEY_DIAGNOSTIC_DISABLE_CAST_QUAL _Pragma("warning(disable:2203 2331)")
#elif JSON_HEDLEY_GCC_VERSION_CHECK(3,0,0)
    #define JSON_HEDLEY_DIAGNOSTIC_DISABLE_CAST_QUAL _Pragma("GCC diagnostic ignored \"-Wcast-qual\"")
#else
    #define JSON_HEDLEY_DIAGNOSTIC_DISABLE_CAST_QUAL
#endif
#if defined(JSON_HEDLEY_DIAGNOSTIC_DISABLE_UNUSED_FUNCTION)
    #undef JSON_HEDLEY_DIAGNOSTIC_DISABLE_UNUSED_FUNCTION
#endif
#if JSON_HEDLEY_HAS_WARNING("-Wunused-function")
    #define JSON_HEDLEY_DIAGNOSTIC_DISABLE_UNUSED_FUNCTION _Pragma("clang diagnostic ignored \"-Wunused-function\"")
#elif JSON_HEDLEY_GCC_VERSION_CHECK(3,4,0)
    #define JSON_HEDLEY_DIAGNOSTIC_DISABLE_UNUSED_FUNCTION _Pragma("GCC diagnostic ignored \"-Wunused-function\"")
#elif JSON_HEDLEY_MSVC_VERSION_CHECK(1,0,0)
    #define JSON_HEDLEY_DIAGNOSTIC_DISABLE_UNUSED_FUNCTION __pragma(warning(disable:4505))
#elif JSON_HEDLEY_MCST_LCC_VERSION_CHECK(1,25,10)
    #define JSON_HEDLEY_DIAGNOSTIC_DISABLE_UNUSED_FUNCTION _Pragma("diag_suppress 3142")
#else
    #define JSON_HEDLEY_DIAGNOSTIC_DISABLE_UNUSED_FUNCTION
#endif
#if defined(JSON_HEDLEY_DEPRECATED)
    #undef JSON_HEDLEY_DEPRECATED
#endif
#if defined(JSON_HEDLEY_DEPRECATED_FOR)
    #undef JSON_HEDLEY_DEPRECATED_FOR
#endif
#if \
    JSON_HEDLEY_MSVC_VERSION_CHECK(14,0,0) || \
    JSON_HEDLEY_INTEL_CL_VERSION_CHECK(2021,1,0)
    #define JSON_HEDLEY_DEPRECATED(since) __declspec(deprecated("Since " # since))
    #define JSON_HEDLEY_DEPRECATED_FOR(since, replacement) __declspec(deprecated("Since " #since "; use " #replacement))
#elif \
    (JSON_HEDLEY_HAS_EXTENSION(attribute_deprecated_with_message) && !defined(JSON_HEDLEY_IAR_VERSION)) || \
    JSON_HEDLEY_GCC_VERSION_CHECK(4,5,0) || \
    JSON_HEDLEY_INTEL_VERSION_CHECK(13,0,0) || \
    JSON_HEDLEY_ARM_VERSION_CHECK(5,6,0) || \
    JSON_HEDLEY_SUNPRO_VERSION_CHECK(5,13,0) || \
    JSON_HEDLEY_PGI_VERSION_CHECK(17,10,0) || \
    JSON_HEDLEY_TI_VERSION_CHECK(18,1,0) || \
    JSON_HEDLEY_TI_ARMCL_VERSION_CHECK(18,1,0) || \
    JSON_HEDLEY_TI_CL6X_VERSION_CHECK(8,3,0) || \
    JSON_HEDLEY_TI_CL7X_VERSION_CHECK(1,2,0) || \
    JSON_HEDLEY_TI_CLPRU_VERSION_CHECK(2,3,0) || \
    JSON_HEDLEY_MCST_LCC_VERSION_CHECK(1,25,10)
    #define JSON_HEDLEY_DEPRECATED(since) __attribute__((__deprecated__("Since " #since)))
    #define JSON_HEDLEY_DEPRECATED_FOR(since, replacement) __attribute__((__deprecated__("Since " #since "; use " #replacement)))
#elif defined(__cplusplus) && (__cplusplus >= 201402L)
    #define JSON_HEDLEY_DEPRECATED(since) JSON_HEDLEY_DIAGNOSTIC_DISABLE_CPP98_COMPAT_WRAP_([[deprecated("Since " #since)]])
    #define JSON_HEDLEY_DEPRECATED_FOR(since, replacement) JSON_HEDLEY_DIAGNOSTIC_DISABLE_CPP98_COMPAT_WRAP_([[deprecated("Since " #since "; use " #replacement)]])
#elif \
    JSON_HEDLEY_HAS_ATTRIBUTE(deprecated) || \
    JSON_HEDLEY_GCC_VERSION_CHECK(3,1,0) || \
    JSON_HEDLEY_ARM_VERSION_CHECK(4,1,0) || \
    JSON_HEDLEY_TI_VERSION_CHECK(15,12,0) || \
    (JSON_HEDLEY_TI_ARMCL_VERSION_CHECK(4,8,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
    JSON_HEDLEY_TI_ARMCL_VERSION_CHECK(5,2,0) || \
    (JSON_HEDLEY_TI_CL2000_VERSION_CHECK(6,0,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
    JSON_HEDLEY_TI_CL2000_VERSION_CHECK(6,4,0) || \
    (JSON_HEDLEY_TI_CL430_VERSION_CHECK(4,0,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
    JSON_HEDLEY_TI_CL430_VERSION_CHECK(4,3,0) || \
    (JSON_HEDLEY_TI_CL6X_VERSION_CHECK(7,2,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
    JSON_HEDLEY_TI_CL6X_VERSION_CHECK(7,5,0) || \
    JSON_HEDLEY_TI_CL7X_VERSION_CHECK(1,2,0) || \
    JSON_HEDLEY_TI_CLPRU_VERSION_CHECK(2,1,0) || \
    JSON_HEDLEY_MCST_LCC_VERSION_CHECK(1,25,10) || \
    JSON_HEDLEY_IAR_VERSION_CHECK(8,10,0)
    #define JSON_HEDLEY_DEPRECATED(since) __attribute__((__deprecated__))
    #define JSON_HEDLEY_DEPRECATED_FOR(since, replacement) __attribute__((__deprecated__))
#elif \
    JSON_HEDLEY_MSVC_VERSION_CHECK(13,10,0) || \
    JSON_HEDLEY_PELLES_VERSION_CHECK(6,50,0) || \
    JSON_HEDLEY_INTEL_CL_VERSION_CHECK(2021,1,0)
    #define JSON_HEDLEY_DEPRECATED(since) __declspec(deprecated)
    #define JSON_HEDLEY_DEPRECATED_FOR(since, replacement) __declspec(deprecated)
#elif JSON_HEDLEY_IAR_VERSION_CHECK(8,0,0)
    #define JSON_HEDLEY_DEPRECATED(since) _Pragma("deprecated")
    #define JSON_HEDLEY_DEPRECATED_FOR(since, replacement) _Pragma("deprecated")
#else
    #define JSON_HEDLEY_DEPRECATED(since)
    #define JSON_HEDLEY_DEPRECATED_FOR(since, replacement)
#endif
#if defined(JSON_HEDLEY_UNAVAILABLE)
    #undef JSON_HEDLEY_UNAVAILABLE
#endif
#if \
    JSON_HEDLEY_HAS_ATTRIBUTE(warning) || \
    JSON_HEDLEY_GCC_VERSION_CHECK(4,3,0) || \
    JSON_HEDLEY_INTEL_VERSION_CHECK(13,0,0) || \
    JSON_HEDLEY_MCST_LCC_VERSION_CHECK(1,25,10)
    #define JSON_HEDLEY_UNAVAILABLE(available_since) __attribute__((__warning__("Not available until " #available_since)))
#else
    #define JSON_HEDLEY_UNAVAILABLE(available_since)
#endif
#if defined(JSON_HEDLEY_WARN_UNUSED_RESULT)
    #undef JSON_HEDLEY_WARN_UNUSED_RESULT
#endif
#if defined(JSON_HEDLEY_WARN_UNUSED_RESULT_MSG)
    #undef JSON_HEDLEY_WARN_UNUSED_RESULT_MSG
#endif
#if \
    JSON_HEDLEY_HAS_ATTRIBUTE(warn_unused_result) || \
    JSON_HEDLEY_GCC_VERSION_CHECK(3,4,0) || \
    JSON_HEDLEY_INTEL_VERSION_CHECK(13,0,0) || \
    JSON_HEDLEY_TI_VERSION_CHECK(15,12,0) || \
    (JSON_HEDLEY_TI_ARMCL_VERSION_CHECK(4,8,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
    JSON_HEDLEY_TI_ARMCL_VERSION_CHECK(5,2,0) || \
    (JSON_HEDLEY_TI_CL2000_VERSION_CHECK(6,0,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
    JSON_HEDLEY_TI_CL2000_VERSION_CHECK(6,4,0) || \
    (JSON_HEDLEY_TI_CL430_VERSION_CHECK(4,0,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
    JSON_HEDLEY_TI_CL430_VERSION_CHECK(4,3,0) || \
    (JSON_HEDLEY_TI_CL6X_VERSION_CHECK(7,2,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
    JSON_HEDLEY_TI_CL6X_VERSION_CHECK(7,5,0) || \
    JSON_HEDLEY_TI_CL7X_VERSION_CHECK(1,2,0) || \
    JSON_HEDLEY_TI_CLPRU_VERSION_CHECK(2,1,0) || \
    (JSON_HEDLEY_SUNPRO_VERSION_CHECK(5,15,0) && defined(__cplusplus)) || \
    JSON_HEDLEY_PGI_VERSION_CHECK(17,10,0) || \
    JSON_HEDLEY_MCST_LCC_VERSION_CHECK(1,25,10)
    #define JSON_HEDLEY_WARN_UNUSED_RESULT __attribute__((__warn_unused_result__))
    #define JSON_HEDLEY_WARN_UNUSED_RESULT_MSG(msg) __attribute__((__warn_unused_result__))
#elif (JSON_HEDLEY_HAS_CPP_ATTRIBUTE(nodiscard) >= 201907L)
    #define JSON_HEDLEY_WARN_UNUSED_RESULT JSON_HEDLEY_DIAGNOSTIC_DISABLE_CPP98_COMPAT_WRAP_([[nodiscard]])
    #define JSON_HEDLEY_WARN_UNUSED_RESULT_MSG(msg) JSON_HEDLEY_DIAGNOSTIC_DISABLE_CPP98_COMPAT_WRAP_([[nodiscard(msg)]])
#elif JSON_HEDLEY_HAS_CPP_ATTRIBUTE(nodiscard)
    #define JSON_HEDLEY_WARN_UNUSED_RESULT JSON_HEDLEY_DIAGNOSTIC_DISABLE_CPP98_COMPAT_WRAP_([[nodiscard]])
    #define JSON_HEDLEY_WARN_UNUSED_RESULT_MSG(msg) JSON_HEDLEY_DIAGNOSTIC_DISABLE_CPP98_COMPAT_WRAP_([[nodiscard]])
#elif defined(_Check_return_) 
    #define JSON_HEDLEY_WARN_UNUSED_RESULT _Check_return_
    #define JSON_HEDLEY_WARN_UNUSED_RESULT_MSG(msg) _Check_return_
#else
    #define JSON_HEDLEY_WARN_UNUSED_RESULT
    #define JSON_HEDLEY_WARN_UNUSED_RESULT_MSG(msg)
#endif
#if defined(JSON_HEDLEY_SENTINEL)
    #undef JSON_HEDLEY_SENTINEL
#endif
#if \
    JSON_HEDLEY_HAS_ATTRIBUTE(sentinel) || \
    JSON_HEDLEY_GCC_VERSION_CHECK(4,0,0) || \
    JSON_HEDLEY_INTEL_VERSION_CHECK(13,0,0) || \
    JSON_HEDLEY_ARM_VERSION_CHECK(5,4,0) || \
    JSON_HEDLEY_MCST_LCC_VERSION_CHECK(1,25,10)
    #define JSON_HEDLEY_SENTINEL(position) __attribute__((__sentinel__(position)))
#else
    #define JSON_HEDLEY_SENTINEL(position)
#endif
#if defined(JSON_HEDLEY_NO_RETURN)
    #undef JSON_HEDLEY_NO_RETURN
#endif
#if JSON_HEDLEY_IAR_VERSION_CHECK(8,0,0)
    #define JSON_HEDLEY_NO_RETURN __noreturn
#elif \
    JSON_HEDLEY_INTEL_VERSION_CHECK(13,0,0) || \
    JSON_HEDLEY_MCST_LCC_VERSION_CHECK(1,25,10)
    #define JSON_HEDLEY_NO_RETURN __attribute__((__noreturn__))
#elif defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201112L
    #define JSON_HEDLEY_NO_RETURN _Noreturn
#elif defined(__cplusplus) && (__cplusplus >= 201103L)
    #define JSON_HEDLEY_NO_RETURN JSON_HEDLEY_DIAGNOSTIC_DISABLE_CPP98_COMPAT_WRAP_([[noreturn]])
#elif \
    JSON_HEDLEY_HAS_ATTRIBUTE(noreturn) || \
    JSON_HEDLEY_GCC_VERSION_CHECK(3,2,0) || \
    JSON_HEDLEY_SUNPRO_VERSION_CHECK(5,11,0) || \
    JSON_HEDLEY_ARM_VERSION_CHECK(4,1,0) || \
    JSON_HEDLEY_IBM_VERSION_CHECK(10,1,0) || \
    JSON_HEDLEY_TI_VERSION_CHECK(15,12,0) || \
    (JSON_HEDLEY_TI_ARMCL_VERSION_CHECK(4,8,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
    JSON_HEDLEY_TI_ARMCL_VERSION_CHECK(5,2,0) || \
    (JSON_HEDLEY_TI_CL2000_VERSION_CHECK(6,0,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
    JSON_HEDLEY_TI_CL2000_VERSION_CHECK(6,4,0) || \
    (JSON_HEDLEY_TI_CL430_VERSION_CHECK(4,0,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
    JSON_HEDLEY_TI_CL430_VERSION_CHECK(4,3,0) || \
    (JSON_HEDLEY_TI_CL6X_VERSION_CHECK(7,2,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
    JSON_HEDLEY_TI_CL6X_VERSION_CHECK(7,5,0) || \
    JSON_HEDLEY_TI_CL7X_VERSION_CHECK(1,2,0) || \
    JSON_HEDLEY_TI_CLPRU_VERSION_CHECK(2,1,0) || \
    JSON_HEDLEY_IAR_VERSION_CHECK(8,10,0)
    #define JSON_HEDLEY_NO_RETURN __attribute__((__noreturn__))
#elif JSON_HEDLEY_SUNPRO_VERSION_CHECK(5,10,0)
    #define JSON_HEDLEY_NO_RETURN _Pragma("does_not_return")
#elif \
    JSON_HEDLEY_MSVC_VERSION_CHECK(13,10,0) || \
    JSON_HEDLEY_INTEL_CL_VERSION_CHECK(2021,1,0)
    #define JSON_HEDLEY_NO_RETURN __declspec(noreturn)
#elif JSON_HEDLEY_TI_CL6X_VERSION_CHECK(6,0,0) && defined(__cplusplus)
    #define JSON_HEDLEY_NO_RETURN _Pragma("FUNC_NEVER_RETURNS;")
#elif JSON_HEDLEY_COMPCERT_VERSION_CHECK(3,2,0)
    #define JSON_HEDLEY_NO_RETURN __attribute((noreturn))
#elif JSON_HEDLEY_PELLES_VERSION_CHECK(9,0,0)
    #define JSON_HEDLEY_NO_RETURN __declspec(noreturn)
#else
    #define JSON_HEDLEY_NO_RETURN
#endif
#if defined(JSON_HEDLEY_NO_ESCAPE)
    #undef JSON_HEDLEY_NO_ESCAPE
#endif
#if JSON_HEDLEY_HAS_ATTRIBUTE(noescape)
    #define JSON_HEDLEY_NO_ESCAPE __attribute__((__noescape__))
#else
    #define JSON_HEDLEY_NO_ESCAPE
#endif
#if defined(JSON_HEDLEY_UNREACHABLE)
    #undef JSON_HEDLEY_UNREACHABLE
#endif
#if defined(JSON_HEDLEY_UNREACHABLE_RETURN)
    #undef JSON_HEDLEY_UNREACHABLE_RETURN
#endif
#if defined(JSON_HEDLEY_ASSUME)
    #undef JSON_HEDLEY_ASSUME
#endif
#if \
    JSON_HEDLEY_MSVC_VERSION_CHECK(13,10,0) || \
    JSON_HEDLEY_INTEL_VERSION_CHECK(13,0,0) || \
    JSON_HEDLEY_INTEL_CL_VERSION_CHECK(2021,1,0)
    #define JSON_HEDLEY_ASSUME(expr) __assume(expr)
#elif JSON_HEDLEY_HAS_BUILTIN(__builtin_assume)
    #define JSON_HEDLEY_ASSUME(expr) __builtin_assume(expr)
#elif \
    JSON_HEDLEY_TI_CL2000_VERSION_CHECK(6,2,0) || \
    JSON_HEDLEY_TI_CL6X_VERSION_CHECK(4,0,0)
    #if defined(__cplusplus)
        #define JSON_HEDLEY_ASSUME(expr) std::_nassert(expr)
    #else
        #define JSON_HEDLEY_ASSUME(expr) _nassert(expr)
    #endif
#endif
#if \
    (JSON_HEDLEY_HAS_BUILTIN(__builtin_unreachable) && (!defined(JSON_HEDLEY_ARM_VERSION))) || \
    JSON_HEDLEY_GCC_VERSION_CHECK(4,5,0) || \
    JSON_HEDLEY_PGI_VERSION_CHECK(18,10,0) || \
    JSON_HEDLEY_INTEL_VERSION_CHECK(13,0,0) || \
    JSON_HEDLEY_IBM_VERSION_CHECK(13,1,5) || \
    JSON_HEDLEY_CRAY_VERSION_CHECK(10,0,0) || \
    JSON_HEDLEY_MCST_LCC_VERSION_CHECK(1,25,10)
    #define JSON_HEDLEY_UNREACHABLE() __builtin_unreachable()
#elif defined(JSON_HEDLEY_ASSUME)
    #define JSON_HEDLEY_UNREACHABLE() JSON_HEDLEY_ASSUME(0)
#endif
#if !defined(JSON_HEDLEY_ASSUME)
    #if defined(JSON_HEDLEY_UNREACHABLE)
        #define JSON_HEDLEY_ASSUME(expr) JSON_HEDLEY_STATIC_CAST(void, ((expr) ? 1 : (JSON_HEDLEY_UNREACHABLE(), 1)))
    #else
        #define JSON_HEDLEY_ASSUME(expr) JSON_HEDLEY_STATIC_CAST(void, expr)
    #endif
#endif
#if defined(JSON_HEDLEY_UNREACHABLE)
    #if  \
        JSON_HEDLEY_TI_CL2000_VERSION_CHECK(6,2,0) || \
        JSON_HEDLEY_TI_CL6X_VERSION_CHECK(4,0,0)
        #define JSON_HEDLEY_UNREACHABLE_RETURN(value) return (JSON_HEDLEY_STATIC_CAST(void, JSON_HEDLEY_ASSUME(0)), (value))
    #else
        #define JSON_HEDLEY_UNREACHABLE_RETURN(value) JSON_HEDLEY_UNREACHABLE()
    #endif
#else
    #define JSON_HEDLEY_UNREACHABLE_RETURN(value) return (value)
#endif
#if !defined(JSON_HEDLEY_UNREACHABLE)
    #define JSON_HEDLEY_UNREACHABLE() JSON_HEDLEY_ASSUME(0)
#endif
JSON_HEDLEY_DIAGNOSTIC_PUSH
#if JSON_HEDLEY_HAS_WARNING("-Wpedantic")
    #pragma clang diagnostic ignored "-Wpedantic"
#endif
#if JSON_HEDLEY_HAS_WARNING("-Wc++98-compat-pedantic") && defined(__cplusplus)
    #pragma clang diagnostic ignored "-Wc++98-compat-pedantic"
#endif
#if JSON_HEDLEY_GCC_HAS_WARNING("-Wvariadic-macros",4,0,0)
    #if defined(__clang__)
        #pragma clang diagnostic ignored "-Wvariadic-macros"
    #elif defined(JSON_HEDLEY_GCC_VERSION)
        #pragma GCC diagnostic ignored "-Wvariadic-macros"
    #endif
#endif
#if defined(JSON_HEDLEY_NON_NULL)
    #undef JSON_HEDLEY_NON_NULL
#endif
#if \
    JSON_HEDLEY_HAS_ATTRIBUTE(nonnull) || \
    JSON_HEDLEY_GCC_VERSION_CHECK(3,3,0) || \
    JSON_HEDLEY_INTEL_VERSION_CHECK(13,0,0) || \
    JSON_HEDLEY_ARM_VERSION_CHECK(4,1,0)
    #define JSON_HEDLEY_NON_NULL(...) __attribute__((__nonnull__(__VA_ARGS__)))
#else
    #define JSON_HEDLEY_NON_NULL(...)
#endif
JSON_HEDLEY_DIAGNOSTIC_POP
#if defined(JSON_HEDLEY_PRINTF_FORMAT)
    #undef JSON_HEDLEY_PRINTF_FORMAT
#endif
#if defined(__MINGW32__) && JSON_HEDLEY_GCC_HAS_ATTRIBUTE(format,4,4,0) && !defined(__USE_MINGW_ANSI_STDIO)
    #define JSON_HEDLEY_PRINTF_FORMAT(string_idx,first_to_check) __attribute__((__format__(ms_printf, string_idx, first_to_check)))
#elif defined(__MINGW32__) && JSON_HEDLEY_GCC_HAS_ATTRIBUTE(format,4,4,0) && defined(__USE_MINGW_ANSI_STDIO)
    #define JSON_HEDLEY_PRINTF_FORMAT(string_idx,first_to_check) __attribute__((__format__(gnu_printf, string_idx, first_to_check)))
#elif \
    JSON_HEDLEY_HAS_ATTRIBUTE(format) || \
    JSON_HEDLEY_GCC_VERSION_CHECK(3,1,0) || \
    JSON_HEDLEY_INTEL_VERSION_CHECK(13,0,0) || \
    JSON_HEDLEY_ARM_VERSION_CHECK(5,6,0) || \
    JSON_HEDLEY_IBM_VERSION_CHECK(10,1,0) || \
    JSON_HEDLEY_TI_VERSION_CHECK(15,12,0) || \
    (JSON_HEDLEY_TI_ARMCL_VERSION_CHECK(4,8,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
    JSON_HEDLEY_TI_ARMCL_VERSION_CHECK(5,2,0) || \
    (JSON_HEDLEY_TI_CL2000_VERSION_CHECK(6,0,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
    JSON_HEDLEY_TI_CL2000_VERSION_CHECK(6,4,0) || \
    (JSON_HEDLEY_TI_CL430_VERSION_CHECK(4,0,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
    JSON_HEDLEY_TI_CL430_VERSION_CHECK(4,3,0) || \
    (JSON_HEDLEY_TI_CL6X_VERSION_CHECK(7,2,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
    JSON_HEDLEY_TI_CL6X_VERSION_CHECK(7,5,0) || \
    JSON_HEDLEY_TI_CL7X_VERSION_CHECK(1,2,0) || \
    JSON_HEDLEY_TI_CLPRU_VERSION_CHECK(2,1,0) || \
    JSON_HEDLEY_MCST_LCC_VERSION_CHECK(1,25,10)
    #define JSON_HEDLEY_PRINTF_FORMAT(string_idx,first_to_check) __attribute__((__format__(__printf__, string_idx, first_to_check)))
#elif JSON_HEDLEY_PELLES_VERSION_CHECK(6,0,0)
    #define JSON_HEDLEY_PRINTF_FORMAT(string_idx,first_to_check) __declspec(vaformat(printf,string_idx,first_to_check))
#else
    #define JSON_HEDLEY_PRINTF_FORMAT(string_idx,first_to_check)
#endif
#if defined(JSON_HEDLEY_CONSTEXPR)
    #undef JSON_HEDLEY_CONSTEXPR
#endif
#if defined(__cplusplus)
    #if __cplusplus >= 201103L
        #define JSON_HEDLEY_CONSTEXPR JSON_HEDLEY_DIAGNOSTIC_DISABLE_CPP98_COMPAT_WRAP_(constexpr)
    #endif
#endif
#if !defined(JSON_HEDLEY_CONSTEXPR)
    #define JSON_HEDLEY_CONSTEXPR
#endif
#if defined(JSON_HEDLEY_PREDICT)
    #undef JSON_HEDLEY_PREDICT
#endif
#if defined(JSON_HEDLEY_LIKELY)
    #undef JSON_HEDLEY_LIKELY
#endif
#if defined(JSON_HEDLEY_UNLIKELY)
    #undef JSON_HEDLEY_UNLIKELY
#endif
#if defined(JSON_HEDLEY_UNPREDICTABLE)
    #undef JSON_HEDLEY_UNPREDICTABLE
#endif
#if JSON_HEDLEY_HAS_BUILTIN(__builtin_unpredictable)
    #define JSON_HEDLEY_UNPREDICTABLE(expr) __builtin_unpredictable((expr))
#endif
#if \
  (JSON_HEDLEY_HAS_BUILTIN(__builtin_expect_with_probability) && !defined(JSON_HEDLEY_PGI_VERSION)) || \
  JSON_HEDLEY_GCC_VERSION_CHECK(9,0,0) || \
  JSON_HEDLEY_MCST_LCC_VERSION_CHECK(1,25,10)
#  define JSON_HEDLEY_PREDICT(expr, value, probability) __builtin_expect_with_probability(  (expr), (value), (probability))
#  define JSON_HEDLEY_PREDICT_TRUE(expr, probability)   __builtin_expect_with_probability(!!(expr),    1   , (probability))
#  define JSON_HEDLEY_PREDICT_FALSE(expr, probability)  __builtin_expect_with_probability(!!(expr),    0   , (probability))
#  define JSON_HEDLEY_LIKELY(expr)                      __builtin_expect                 (!!(expr),    1                  )
#  define JSON_HEDLEY_UNLIKELY(expr)                    __builtin_expect                 (!!(expr),    0                  )
#elif \
  (JSON_HEDLEY_HAS_BUILTIN(__builtin_expect) && !defined(JSON_HEDLEY_INTEL_CL_VERSION)) || \
  JSON_HEDLEY_GCC_VERSION_CHECK(3,0,0) || \
  JSON_HEDLEY_INTEL_VERSION_CHECK(13,0,0) || \
  (JSON_HEDLEY_SUNPRO_VERSION_CHECK(5,15,0) && defined(__cplusplus)) || \
  JSON_HEDLEY_ARM_VERSION_CHECK(4,1,0) || \
  JSON_HEDLEY_IBM_VERSION_CHECK(10,1,0) || \
  JSON_HEDLEY_TI_VERSION_CHECK(15,12,0) || \
  JSON_HEDLEY_TI_ARMCL_VERSION_CHECK(4,7,0) || \
  JSON_HEDLEY_TI_CL430_VERSION_CHECK(3,1,0) || \
  JSON_HEDLEY_TI_CL2000_VERSION_CHECK(6,1,0) || \
  JSON_HEDLEY_TI_CL6X_VERSION_CHECK(6,1,0) || \
  JSON_HEDLEY_TI_CL7X_VERSION_CHECK(1,2,0) || \
  JSON_HEDLEY_TI_CLPRU_VERSION_CHECK(2,1,0) || \
  JSON_HEDLEY_TINYC_VERSION_CHECK(0,9,27) || \
  JSON_HEDLEY_CRAY_VERSION_CHECK(8,1,0) || \
  JSON_HEDLEY_MCST_LCC_VERSION_CHECK(1,25,10)
#  define JSON_HEDLEY_PREDICT(expr, expected, probability) \
    (((probability) >= 0.9) ? __builtin_expect((expr), (expected)) : (JSON_HEDLEY_STATIC_CAST(void, expected), (expr)))
#  define JSON_HEDLEY_PREDICT_TRUE(expr, probability) \
    (__extension__ ({ \
        double hedley_probability_ = (probability); \
        ((hedley_probability_ >= 0.9) ? __builtin_expect(!!(expr), 1) : ((hedley_probability_ <= 0.1) ? __builtin_expect(!!(expr), 0) : !!(expr))); \
    }))
#  define JSON_HEDLEY_PREDICT_FALSE(expr, probability) \
    (__extension__ ({ \
        double hedley_probability_ = (probability); \
        ((hedley_probability_ >= 0.9) ? __builtin_expect(!!(expr), 0) : ((hedley_probability_ <= 0.1) ? __builtin_expect(!!(expr), 1) : !!(expr))); \
    }))
#  define JSON_HEDLEY_LIKELY(expr)   __builtin_expect(!!(expr), 1)
#  define JSON_HEDLEY_UNLIKELY(expr) __builtin_expect(!!(expr), 0)
#else
#  define JSON_HEDLEY_PREDICT(expr, expected, probability) (JSON_HEDLEY_STATIC_CAST(void, expected), (expr))
#  define JSON_HEDLEY_PREDICT_TRUE(expr, probability) (!!(expr))
#  define JSON_HEDLEY_PREDICT_FALSE(expr, probability) (!!(expr))
#  define JSON_HEDLEY_LIKELY(expr) (!!(expr))
#  define JSON_HEDLEY_UNLIKELY(expr) (!!(expr))
#endif
#if !defined(JSON_HEDLEY_UNPREDICTABLE)
    #define JSON_HEDLEY_UNPREDICTABLE(expr) JSON_HEDLEY_PREDICT(expr, 1, 0.5)
#endif
#if defined(JSON_HEDLEY_MALLOC)
    #undef JSON_HEDLEY_MALLOC
#endif
#if \
    JSON_HEDLEY_HAS_ATTRIBUTE(malloc) || \
    JSON_HEDLEY_GCC_VERSION_CHECK(3,1,0) || \
    JSON_HEDLEY_INTEL_VERSION_CHECK(13,0,0) || \
    JSON_HEDLEY_SUNPRO_VERSION_CHECK(5,11,0) || \
    JSON_HEDLEY_ARM_VERSION_CHECK(4,1,0) || \
    JSON_HEDLEY_IBM_VERSION_CHECK(12,1,0) || \
    JSON_HEDLEY_TI_VERSION_CHECK(15,12,0) || \
    (JSON_HEDLEY_TI_ARMCL_VERSION_CHECK(4,8,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
    JSON_HEDLEY_TI_ARMCL_VERSION_CHECK(5,2,0) || \
    (JSON_HEDLEY_TI_CL2000_VERSION_CHECK(6,0,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
    JSON_HEDLEY_TI_CL2000_VERSION_CHECK(6,4,0) || \
    (JSON_HEDLEY_TI_CL430_VERSION_CHECK(4,0,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
    JSON_HEDLEY_TI_CL430_VERSION_CHECK(4,3,0) || \
    (JSON_HEDLEY_TI_CL6X_VERSION_CHECK(7,2,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
    JSON_HEDLEY_TI_CL6X_VERSION_CHECK(7,5,0) || \
    JSON_HEDLEY_TI_CL7X_VERSION_CHECK(1,2,0) || \
    JSON_HEDLEY_TI_CLPRU_VERSION_CHECK(2,1,0) || \
    JSON_HEDLEY_MCST_LCC_VERSION_CHECK(1,25,10)
    #define JSON_HEDLEY_MALLOC __attribute__((__malloc__))
#elif JSON_HEDLEY_SUNPRO_VERSION_CHECK(5,10,0)
    #define JSON_HEDLEY_MALLOC _Pragma("returns_new_memory")
#elif \
    JSON_HEDLEY_MSVC_VERSION_CHECK(14,0,0) || \
    JSON_HEDLEY_INTEL_CL_VERSION_CHECK(2021,1,0)
    #define JSON_HEDLEY_MALLOC __declspec(restrict)
#else
    #define JSON_HEDLEY_MALLOC
#endif
#if defined(JSON_HEDLEY_PURE)
    #undef JSON_HEDLEY_PURE
#endif
#if \
  JSON_HEDLEY_HAS_ATTRIBUTE(pure) || \
  JSON_HEDLEY_GCC_VERSION_CHECK(2,96,0) || \
  JSON_HEDLEY_INTEL_VERSION_CHECK(13,0,0) || \
  JSON_HEDLEY_SUNPRO_VERSION_CHECK(5,11,0) || \
  JSON_HEDLEY_ARM_VERSION_CHECK(4,1,0) || \
  JSON_HEDLEY_IBM_VERSION_CHECK(10,1,0) || \
  JSON_HEDLEY_TI_VERSION_CHECK(15,12,0) || \
  (JSON_HEDLEY_TI_ARMCL_VERSION_CHECK(4,8,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
  JSON_HEDLEY_TI_ARMCL_VERSION_CHECK(5,2,0) || \
  (JSON_HEDLEY_TI_CL2000_VERSION_CHECK(6,0,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
  JSON_HEDLEY_TI_CL2000_VERSION_CHECK(6,4,0) || \
  (JSON_HEDLEY_TI_CL430_VERSION_CHECK(4,0,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
  JSON_HEDLEY_TI_CL430_VERSION_CHECK(4,3,0) || \
  (JSON_HEDLEY_TI_CL6X_VERSION_CHECK(7,2,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
  JSON_HEDLEY_TI_CL6X_VERSION_CHECK(7,5,0) || \
  JSON_HEDLEY_TI_CL7X_VERSION_CHECK(1,2,0) || \
  JSON_HEDLEY_TI_CLPRU_VERSION_CHECK(2,1,0) || \
  JSON_HEDLEY_PGI_VERSION_CHECK(17,10,0) || \
  JSON_HEDLEY_MCST_LCC_VERSION_CHECK(1,25,10)
#  define JSON_HEDLEY_PURE __attribute__((__pure__))
#elif JSON_HEDLEY_SUNPRO_VERSION_CHECK(5,10,0)
#  define JSON_HEDLEY_PURE _Pragma("does_not_write_global_data")
#elif defined(__cplusplus) && \
    ( \
      JSON_HEDLEY_TI_CL430_VERSION_CHECK(2,0,1) || \
      JSON_HEDLEY_TI_CL6X_VERSION_CHECK(4,0,0) || \
      JSON_HEDLEY_TI_CL7X_VERSION_CHECK(1,2,0) \
    )
#  define JSON_HEDLEY_PURE _Pragma("FUNC_IS_PURE;")
#else
#  define JSON_HEDLEY_PURE
#endif
#if defined(JSON_HEDLEY_CONST)
    #undef JSON_HEDLEY_CONST
#endif
#if \
    JSON_HEDLEY_HAS_ATTRIBUTE(const) || \
    JSON_HEDLEY_GCC_VERSION_CHECK(2,5,0) || \
    JSON_HEDLEY_INTEL_VERSION_CHECK(13,0,0) || \
    JSON_HEDLEY_SUNPRO_VERSION_CHECK(5,11,0) || \
    JSON_HEDLEY_ARM_VERSION_CHECK(4,1,0) || \
    JSON_HEDLEY_IBM_VERSION_CHECK(10,1,0) || \
    JSON_HEDLEY_TI_VERSION_CHECK(15,12,0) || \
    (JSON_HEDLEY_TI_ARMCL_VERSION_CHECK(4,8,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
    JSON_HEDLEY_TI_ARMCL_VERSION_CHECK(5,2,0) || \
    (JSON_HEDLEY_TI_CL2000_VERSION_CHECK(6,0,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
    JSON_HEDLEY_TI_CL2000_VERSION_CHECK(6,4,0) || \
    (JSON_HEDLEY_TI_CL430_VERSION_CHECK(4,0,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
    JSON_HEDLEY_TI_CL430_VERSION_CHECK(4,3,0) || \
    (JSON_HEDLEY_TI_CL6X_VERSION_CHECK(7,2,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
    JSON_HEDLEY_TI_CL6X_VERSION_CHECK(7,5,0) || \
    JSON_HEDLEY_TI_CL7X_VERSION_CHECK(1,2,0) || \
    JSON_HEDLEY_TI_CLPRU_VERSION_CHECK(2,1,0) || \
    JSON_HEDLEY_PGI_VERSION_CHECK(17,10,0) || \
    JSON_HEDLEY_MCST_LCC_VERSION_CHECK(1,25,10)
    #define JSON_HEDLEY_CONST __attribute__((__const__))
#elif \
    JSON_HEDLEY_SUNPRO_VERSION_CHECK(5,10,0)
    #define JSON_HEDLEY_CONST _Pragma("no_side_effect")
#else
    #define JSON_HEDLEY_CONST JSON_HEDLEY_PURE
#endif
#if defined(JSON_HEDLEY_RESTRICT)
    #undef JSON_HEDLEY_RESTRICT
#endif
#if defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901L) && !defined(__cplusplus)
    #define JSON_HEDLEY_RESTRICT restrict
#elif \
    JSON_HEDLEY_GCC_VERSION_CHECK(3,1,0) || \
    JSON_HEDLEY_MSVC_VERSION_CHECK(14,0,0) || \
    JSON_HEDLEY_INTEL_VERSION_CHECK(13,0,0) || \
    JSON_HEDLEY_INTEL_CL_VERSION_CHECK(2021,1,0) || \
    JSON_HEDLEY_ARM_VERSION_CHECK(4,1,0) || \
    JSON_HEDLEY_IBM_VERSION_CHECK(10,1,0) || \
    JSON_HEDLEY_PGI_VERSION_CHECK(17,10,0) || \
    JSON_HEDLEY_TI_CL430_VERSION_CHECK(4,3,0) || \
    JSON_HEDLEY_TI_CL2000_VERSION_CHECK(6,2,4) || \
    JSON_HEDLEY_TI_CL6X_VERSION_CHECK(8,1,0) || \
    JSON_HEDLEY_TI_CL7X_VERSION_CHECK(1,2,0) || \
    (JSON_HEDLEY_SUNPRO_VERSION_CHECK(5,14,0) && defined(__cplusplus)) || \
    JSON_HEDLEY_IAR_VERSION_CHECK(8,0,0) || \
    defined(__clang__) || \
    JSON_HEDLEY_MCST_LCC_VERSION_CHECK(1,25,10)
    #define JSON_HEDLEY_RESTRICT __restrict
#elif JSON_HEDLEY_SUNPRO_VERSION_CHECK(5,3,0) && !defined(__cplusplus)
    #define JSON_HEDLEY_RESTRICT _Restrict
#else
    #define JSON_HEDLEY_RESTRICT
#endif
#if defined(JSON_HEDLEY_INLINE)
    #undef JSON_HEDLEY_INLINE
#endif
#if \
    (defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901L)) || \
    (defined(__cplusplus) && (__cplusplus >= 199711L))
    #define JSON_HEDLEY_INLINE inline
#elif \
    defined(JSON_HEDLEY_GCC_VERSION) || \
    JSON_HEDLEY_ARM_VERSION_CHECK(6,2,0)
    #define JSON_HEDLEY_INLINE __inline__
#elif \
    JSON_HEDLEY_MSVC_VERSION_CHECK(12,0,0) || \
    JSON_HEDLEY_INTEL_CL_VERSION_CHECK(2021,1,0) || \
    JSON_HEDLEY_ARM_VERSION_CHECK(4,1,0) || \
    JSON_HEDLEY_TI_ARMCL_VERSION_CHECK(5,1,0) || \
    JSON_HEDLEY_TI_CL430_VERSION_CHECK(3,1,0) || \
    JSON_HEDLEY_TI_CL2000_VERSION_CHECK(6,2,0) || \
    JSON_HEDLEY_TI_CL6X_VERSION_CHECK(8,0,0) || \
    JSON_HEDLEY_TI_CL7X_VERSION_CHECK(1,2,0) || \
    JSON_HEDLEY_TI_CLPRU_VERSION_CHECK(2,1,0) || \
    JSON_HEDLEY_MCST_LCC_VERSION_CHECK(1,25,10)
    #define JSON_HEDLEY_INLINE __inline
#else
    #define JSON_HEDLEY_INLINE
#endif
#if defined(JSON_HEDLEY_ALWAYS_INLINE)
    #undef JSON_HEDLEY_ALWAYS_INLINE
#endif
#if \
  JSON_HEDLEY_HAS_ATTRIBUTE(always_inline) || \
  JSON_HEDLEY_GCC_VERSION_CHECK(4,0,0) || \
  JSON_HEDLEY_INTEL_VERSION_CHECK(13,0,0) || \
  JSON_HEDLEY_SUNPRO_VERSION_CHECK(5,11,0) || \
  JSON_HEDLEY_ARM_VERSION_CHECK(4,1,0) || \
  JSON_HEDLEY_IBM_VERSION_CHECK(10,1,0) || \
  JSON_HEDLEY_TI_VERSION_CHECK(15,12,0) || \
  (JSON_HEDLEY_TI_ARMCL_VERSION_CHECK(4,8,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
  JSON_HEDLEY_TI_ARMCL_VERSION_CHECK(5,2,0) || \
  (JSON_HEDLEY_TI_CL2000_VERSION_CHECK(6,0,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
  JSON_HEDLEY_TI_CL2000_VERSION_CHECK(6,4,0) || \
  (JSON_HEDLEY_TI_CL430_VERSION_CHECK(4,0,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
  JSON_HEDLEY_TI_CL430_VERSION_CHECK(4,3,0) || \
  (JSON_HEDLEY_TI_CL6X_VERSION_CHECK(7,2,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
  JSON_HEDLEY_TI_CL6X_VERSION_CHECK(7,5,0) || \
  JSON_HEDLEY_TI_CL7X_VERSION_CHECK(1,2,0) || \
  JSON_HEDLEY_TI_CLPRU_VERSION_CHECK(2,1,0) || \
  JSON_HEDLEY_MCST_LCC_VERSION_CHECK(1,25,10) || \
  JSON_HEDLEY_IAR_VERSION_CHECK(8,10,0)
#  define JSON_HEDLEY_ALWAYS_INLINE __attribute__((__always_inline__)) JSON_HEDLEY_INLINE
#elif \
  JSON_HEDLEY_MSVC_VERSION_CHECK(12,0,0) || \
  JSON_HEDLEY_INTEL_CL_VERSION_CHECK(2021,1,0)
#  define JSON_HEDLEY_ALWAYS_INLINE __forceinline
#elif defined(__cplusplus) && \
    ( \
      JSON_HEDLEY_TI_ARMCL_VERSION_CHECK(5,2,0) || \
      JSON_HEDLEY_TI_CL430_VERSION_CHECK(4,3,0) || \
      JSON_HEDLEY_TI_CL2000_VERSION_CHECK(6,4,0) || \
      JSON_HEDLEY_TI_CL6X_VERSION_CHECK(6,1,0) || \
      JSON_HEDLEY_TI_CL7X_VERSION_CHECK(1,2,0) || \
      JSON_HEDLEY_TI_CLPRU_VERSION_CHECK(2,1,0) \
    )
#  define JSON_HEDLEY_ALWAYS_INLINE _Pragma("FUNC_ALWAYS_INLINE;")
#elif JSON_HEDLEY_IAR_VERSION_CHECK(8,0,0)
#  define JSON_HEDLEY_ALWAYS_INLINE _Pragma("inline=forced")
#else
#  define JSON_HEDLEY_ALWAYS_INLINE JSON_HEDLEY_INLINE
#endif
#if defined(JSON_HEDLEY_NEVER_INLINE)
    #undef JSON_HEDLEY_NEVER_INLINE
#endif
#if \
    JSON_HEDLEY_HAS_ATTRIBUTE(noinline) || \
    JSON_HEDLEY_GCC_VERSION_CHECK(4,0,0) || \
    JSON_HEDLEY_INTEL_VERSION_CHECK(13,0,0) || \
    JSON_HEDLEY_SUNPRO_VERSION_CHECK(5,11,0) || \
    JSON_HEDLEY_ARM_VERSION_CHECK(4,1,0) || \
    JSON_HEDLEY_IBM_VERSION_CHECK(10,1,0) || \
    JSON_HEDLEY_TI_VERSION_CHECK(15,12,0) || \
    (JSON_HEDLEY_TI_ARMCL_VERSION_CHECK(4,8,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
    JSON_HEDLEY_TI_ARMCL_VERSION_CHECK(5,2,0) || \
    (JSON_HEDLEY_TI_CL2000_VERSION_CHECK(6,0,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
    JSON_HEDLEY_TI_CL2000_VERSION_CHECK(6,4,0) || \
    (JSON_HEDLEY_TI_CL430_VERSION_CHECK(4,0,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
    JSON_HEDLEY_TI_CL430_VERSION_CHECK(4,3,0) || \
    (JSON_HEDLEY_TI_CL6X_VERSION_CHECK(7,2,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
    JSON_HEDLEY_TI_CL6X_VERSION_CHECK(7,5,0) || \
    JSON_HEDLEY_TI_CL7X_VERSION_CHECK(1,2,0) || \
    JSON_HEDLEY_TI_CLPRU_VERSION_CHECK(2,1,0) || \
    JSON_HEDLEY_MCST_LCC_VERSION_CHECK(1,25,10) || \
    JSON_HEDLEY_IAR_VERSION_CHECK(8,10,0)
    #define JSON_HEDLEY_NEVER_INLINE __attribute__((__noinline__))
#elif \
    JSON_HEDLEY_MSVC_VERSION_CHECK(13,10,0) || \
    JSON_HEDLEY_INTEL_CL_VERSION_CHECK(2021,1,0)
    #define JSON_HEDLEY_NEVER_INLINE __declspec(noinline)
#elif JSON_HEDLEY_PGI_VERSION_CHECK(10,2,0)
    #define JSON_HEDLEY_NEVER_INLINE _Pragma("noinline")
#elif JSON_HEDLEY_TI_CL6X_VERSION_CHECK(6,0,0) && defined(__cplusplus)
    #define JSON_HEDLEY_NEVER_INLINE _Pragma("FUNC_CANNOT_INLINE;")
#elif JSON_HEDLEY_IAR_VERSION_CHECK(8,0,0)
    #define JSON_HEDLEY_NEVER_INLINE _Pragma("inline=never")
#elif JSON_HEDLEY_COMPCERT_VERSION_CHECK(3,2,0)
    #define JSON_HEDLEY_NEVER_INLINE __attribute((noinline))
#elif JSON_HEDLEY_PELLES_VERSION_CHECK(9,0,0)
    #define JSON_HEDLEY_NEVER_INLINE __declspec(noinline)
#else
    #define JSON_HEDLEY_NEVER_INLINE
#endif
#if defined(JSON_HEDLEY_PRIVATE)
    #undef JSON_HEDLEY_PRIVATE
#endif
#if defined(JSON_HEDLEY_PUBLIC)
    #undef JSON_HEDLEY_PUBLIC
#endif
#if defined(JSON_HEDLEY_IMPORT)
    #undef JSON_HEDLEY_IMPORT
#endif
#if defined(_WIN32) || defined(__CYGWIN__)
#  define JSON_HEDLEY_PRIVATE
#  define JSON_HEDLEY_PUBLIC   __declspec(dllexport)
#  define JSON_HEDLEY_IMPORT   __declspec(dllimport)
#else
#  if \
    JSON_HEDLEY_HAS_ATTRIBUTE(visibility) || \
    JSON_HEDLEY_GCC_VERSION_CHECK(3,3,0) || \
    JSON_HEDLEY_SUNPRO_VERSION_CHECK(5,11,0) || \
    JSON_HEDLEY_INTEL_VERSION_CHECK(13,0,0) || \
    JSON_HEDLEY_ARM_VERSION_CHECK(4,1,0) || \
    JSON_HEDLEY_IBM_VERSION_CHECK(13,1,0) || \
    ( \
      defined(__TI_EABI__) && \
      ( \
        (JSON_HEDLEY_TI_CL6X_VERSION_CHECK(7,2,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
        JSON_HEDLEY_TI_CL6X_VERSION_CHECK(7,5,0) \
      ) \
    ) || \
    JSON_HEDLEY_MCST_LCC_VERSION_CHECK(1,25,10)
#    define JSON_HEDLEY_PRIVATE __attribute__((__visibility__("hidden")))
#    define JSON_HEDLEY_PUBLIC  __attribute__((__visibility__("default")))
#  else
#    define JSON_HEDLEY_PRIVATE
#    define JSON_HEDLEY_PUBLIC
#  endif
#  define JSON_HEDLEY_IMPORT    extern
#endif
#if defined(JSON_HEDLEY_NO_THROW)
    #undef JSON_HEDLEY_NO_THROW
#endif
#if \
    JSON_HEDLEY_HAS_ATTRIBUTE(nothrow) || \
    JSON_HEDLEY_GCC_VERSION_CHECK(3,3,0) || \
    JSON_HEDLEY_INTEL_VERSION_CHECK(13,0,0) || \
    JSON_HEDLEY_MCST_LCC_VERSION_CHECK(1,25,10)
    #define JSON_HEDLEY_NO_THROW __attribute__((__nothrow__))
#elif \
    JSON_HEDLEY_MSVC_VERSION_CHECK(13,1,0) || \
    JSON_HEDLEY_INTEL_CL_VERSION_CHECK(2021,1,0) || \
    JSON_HEDLEY_ARM_VERSION_CHECK(4,1,0)
    #define JSON_HEDLEY_NO_THROW __declspec(nothrow)
#else
    #define JSON_HEDLEY_NO_THROW
#endif
#if defined(JSON_HEDLEY_FALL_THROUGH)
    #undef JSON_HEDLEY_FALL_THROUGH
#endif
#if \
    JSON_HEDLEY_HAS_ATTRIBUTE(fallthrough) || \
    JSON_HEDLEY_GCC_VERSION_CHECK(7,0,0) || \
    JSON_HEDLEY_MCST_LCC_VERSION_CHECK(1,25,10)
    #define JSON_HEDLEY_FALL_THROUGH __attribute__((__fallthrough__))
#elif JSON_HEDLEY_HAS_CPP_ATTRIBUTE_NS(clang,fallthrough)
    #define JSON_HEDLEY_FALL_THROUGH JSON_HEDLEY_DIAGNOSTIC_DISABLE_CPP98_COMPAT_WRAP_([[clang::fallthrough]])
#elif JSON_HEDLEY_HAS_CPP_ATTRIBUTE(fallthrough)
    #define JSON_HEDLEY_FALL_THROUGH JSON_HEDLEY_DIAGNOSTIC_DISABLE_CPP98_COMPAT_WRAP_([[fallthrough]])
#elif defined(__fallthrough) 
    #define JSON_HEDLEY_FALL_THROUGH __fallthrough
#else
    #define JSON_HEDLEY_FALL_THROUGH
#endif
#if defined(JSON_HEDLEY_RETURNS_NON_NULL)
    #undef JSON_HEDLEY_RETURNS_NON_NULL
#endif
#if \
    JSON_HEDLEY_HAS_ATTRIBUTE(returns_nonnull) || \
    JSON_HEDLEY_GCC_VERSION_CHECK(4,9,0) || \
    JSON_HEDLEY_MCST_LCC_VERSION_CHECK(1,25,10)
    #define JSON_HEDLEY_RETURNS_NON_NULL __attribute__((__returns_nonnull__))
#elif defined(_Ret_notnull_) 
    #define JSON_HEDLEY_RETURNS_NON_NULL _Ret_notnull_
#else
    #define JSON_HEDLEY_RETURNS_NON_NULL
#endif
#if defined(JSON_HEDLEY_ARRAY_PARAM)
    #undef JSON_HEDLEY_ARRAY_PARAM
#endif
#if \
    defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901L) && \
    !defined(__STDC_NO_VLA__) && \
    !defined(__cplusplus) && \
    !defined(JSON_HEDLEY_PGI_VERSION) && \
    !defined(JSON_HEDLEY_TINYC_VERSION)
    #define JSON_HEDLEY_ARRAY_PARAM(name) (name)
#else
    #define JSON_HEDLEY_ARRAY_PARAM(name)
#endif
#if defined(JSON_HEDLEY_IS_CONSTANT)
    #undef JSON_HEDLEY_IS_CONSTANT
#endif
#if defined(JSON_HEDLEY_REQUIRE_CONSTEXPR)
    #undef JSON_HEDLEY_REQUIRE_CONSTEXPR
#endif
#if defined(JSON_HEDLEY_IS_CONSTEXPR_)
    #undef JSON_HEDLEY_IS_CONSTEXPR_
#endif
#if \
    JSON_HEDLEY_HAS_BUILTIN(__builtin_constant_p) || \
    JSON_HEDLEY_GCC_VERSION_CHECK(3,4,0) || \
    JSON_HEDLEY_INTEL_VERSION_CHECK(13,0,0) || \
    JSON_HEDLEY_TINYC_VERSION_CHECK(0,9,19) || \
    JSON_HEDLEY_ARM_VERSION_CHECK(4,1,0) || \
    JSON_HEDLEY_IBM_VERSION_CHECK(13,1,0) || \
    JSON_HEDLEY_TI_CL6X_VERSION_CHECK(6,1,0) || \
    (JSON_HEDLEY_SUNPRO_VERSION_CHECK(5,10,0) && !defined(__cplusplus)) || \
    JSON_HEDLEY_CRAY_VERSION_CHECK(8,1,0) || \
    JSON_HEDLEY_MCST_LCC_VERSION_CHECK(1,25,10)
    #define JSON_HEDLEY_IS_CONSTANT(expr) __builtin_constant_p(expr)
#endif
#if !defined(__cplusplus)
#  if \
       JSON_HEDLEY_HAS_BUILTIN(__builtin_types_compatible_p) || \
       JSON_HEDLEY_GCC_VERSION_CHECK(3,4,0) || \
       JSON_HEDLEY_INTEL_VERSION_CHECK(13,0,0) || \
       JSON_HEDLEY_IBM_VERSION_CHECK(13,1,0) || \
       JSON_HEDLEY_CRAY_VERSION_CHECK(8,1,0) || \
       JSON_HEDLEY_ARM_VERSION_CHECK(5,4,0) || \
       JSON_HEDLEY_TINYC_VERSION_CHECK(0,9,24)
#if defined(__INTPTR_TYPE__)
    #define JSON_HEDLEY_IS_CONSTEXPR_(expr) __builtin_types_compatible_p(__typeof__((1 ? (void*) ((__INTPTR_TYPE__) ((expr) * 0)) : (int*) 0)), int*)
#else
    #include <stdint.h>
    #define JSON_HEDLEY_IS_CONSTEXPR_(expr) __builtin_types_compatible_p(__typeof__((1 ? (void*) ((intptr_t) ((expr) * 0)) : (int*) 0)), int*)
#endif
#  elif \
       ( \
          defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 201112L) && \
          !defined(JSON_HEDLEY_SUNPRO_VERSION) && \
          !defined(JSON_HEDLEY_PGI_VERSION) && \
          !defined(JSON_HEDLEY_IAR_VERSION)) || \
       (JSON_HEDLEY_HAS_EXTENSION(c_generic_selections) && !defined(JSON_HEDLEY_IAR_VERSION)) || \
       JSON_HEDLEY_GCC_VERSION_CHECK(4,9,0) || \
       JSON_HEDLEY_INTEL_VERSION_CHECK(17,0,0) || \
       JSON_HEDLEY_IBM_VERSION_CHECK(12,1,0) || \
       JSON_HEDLEY_ARM_VERSION_CHECK(5,3,0)
#if defined(__INTPTR_TYPE__)
    #define JSON_HEDLEY_IS_CONSTEXPR_(expr) _Generic((1 ? (void*) ((__INTPTR_TYPE__) ((expr) * 0)) : (int*) 0), int*: 1, void*: 0)
#else
    #include <stdint.h>
    #define JSON_HEDLEY_IS_CONSTEXPR_(expr) _Generic((1 ? (void*) ((intptr_t) * 0) : (int*) 0), int*: 1, void*: 0)
#endif
#  elif \
       defined(JSON_HEDLEY_GCC_VERSION) || \
       defined(JSON_HEDLEY_INTEL_VERSION) || \
       defined(JSON_HEDLEY_TINYC_VERSION) || \
       defined(JSON_HEDLEY_TI_ARMCL_VERSION) || \
       JSON_HEDLEY_TI_CL430_VERSION_CHECK(18,12,0) || \
       defined(JSON_HEDLEY_TI_CL2000_VERSION) || \
       defined(JSON_HEDLEY_TI_CL6X_VERSION) || \
       defined(JSON_HEDLEY_TI_CL7X_VERSION) || \
       defined(JSON_HEDLEY_TI_CLPRU_VERSION) || \
       defined(__clang__)
#    define JSON_HEDLEY_IS_CONSTEXPR_(expr) ( \
        sizeof(void) != \
        sizeof(*( \
                  1 ? \
                  ((void*) ((expr) * 0L) ) : \
((struct { char v[sizeof(void) * 2]; } *) 1) \
                ) \
              ) \
                                            )
#  endif
#endif
#if defined(JSON_HEDLEY_IS_CONSTEXPR_)
    #if !defined(JSON_HEDLEY_IS_CONSTANT)
        #define JSON_HEDLEY_IS_CONSTANT(expr) JSON_HEDLEY_IS_CONSTEXPR_(expr)
    #endif
    #define JSON_HEDLEY_REQUIRE_CONSTEXPR(expr) (JSON_HEDLEY_IS_CONSTEXPR_(expr) ? (expr) : (-1))
#else
    #if !defined(JSON_HEDLEY_IS_CONSTANT)
        #define JSON_HEDLEY_IS_CONSTANT(expr) (0)
    #endif
    #define JSON_HEDLEY_REQUIRE_CONSTEXPR(expr) (expr)
#endif
#if defined(JSON_HEDLEY_BEGIN_C_DECLS)
    #undef JSON_HEDLEY_BEGIN_C_DECLS
#endif
#if defined(JSON_HEDLEY_END_C_DECLS)
    #undef JSON_HEDLEY_END_C_DECLS
#endif
#if defined(JSON_HEDLEY_C_DECL)
    #undef JSON_HEDLEY_C_DECL
#endif
#if defined(__cplusplus)
    #define JSON_HEDLEY_BEGIN_C_DECLS extern "C" {
    #define JSON_HEDLEY_END_C_DECLS }
    #define JSON_HEDLEY_C_DECL extern "C"
#else
    #define JSON_HEDLEY_BEGIN_C_DECLS
    #define JSON_HEDLEY_END_C_DECLS
    #define JSON_HEDLEY_C_DECL
#endif
#if defined(JSON_HEDLEY_STATIC_ASSERT)
    #undef JSON_HEDLEY_STATIC_ASSERT
#endif
#if \
  !defined(__cplusplus) && ( \
      (defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 201112L)) || \
      (JSON_HEDLEY_HAS_FEATURE(c_static_assert) && !defined(JSON_HEDLEY_INTEL_CL_VERSION)) || \
      JSON_HEDLEY_GCC_VERSION_CHECK(6,0,0) || \
      JSON_HEDLEY_INTEL_VERSION_CHECK(13,0,0) || \
      defined(_Static_assert) \
    )
#  define JSON_HEDLEY_STATIC_ASSERT(expr, message) _Static_assert(expr, message)
#elif \
  (defined(__cplusplus) && (__cplusplus >= 201103L)) || \
  JSON_HEDLEY_MSVC_VERSION_CHECK(16,0,0) || \
  JSON_HEDLEY_INTEL_CL_VERSION_CHECK(2021,1,0)
#  define JSON_HEDLEY_STATIC_ASSERT(expr, message) JSON_HEDLEY_DIAGNOSTIC_DISABLE_CPP98_COMPAT_WRAP_(static_assert(expr, message))
#else
#  define JSON_HEDLEY_STATIC_ASSERT(expr, message)
#endif
#if defined(JSON_HEDLEY_NULL)
    #undef JSON_HEDLEY_NULL
#endif
#if defined(__cplusplus)
    #if __cplusplus >= 201103L
        #define JSON_HEDLEY_NULL JSON_HEDLEY_DIAGNOSTIC_DISABLE_CPP98_COMPAT_WRAP_(nullptr)
    #elif defined(NULL)
        #define JSON_HEDLEY_NULL NULL
    #else
        #define JSON_HEDLEY_NULL JSON_HEDLEY_STATIC_CAST(void*, 0)
    #endif
#elif defined(NULL)
    #define JSON_HEDLEY_NULL NULL
#else
    #define JSON_HEDLEY_NULL ((void*) 0)
#endif
#if defined(JSON_HEDLEY_MESSAGE)
    #undef JSON_HEDLEY_MESSAGE
#endif
#if JSON_HEDLEY_HAS_WARNING("-Wunknown-pragmas")
#  define JSON_HEDLEY_MESSAGE(msg) \
    JSON_HEDLEY_DIAGNOSTIC_PUSH \
    JSON_HEDLEY_DIAGNOSTIC_DISABLE_UNKNOWN_PRAGMAS \
    JSON_HEDLEY_PRAGMA(message msg) \
    JSON_HEDLEY_DIAGNOSTIC_POP
#elif \
  JSON_HEDLEY_GCC_VERSION_CHECK(4,4,0) || \
  JSON_HEDLEY_INTEL_VERSION_CHECK(13,0,0)
#  define JSON_HEDLEY_MESSAGE(msg) JSON_HEDLEY_PRAGMA(message msg)
#elif JSON_HEDLEY_CRAY_VERSION_CHECK(5,0,0)
#  define JSON_HEDLEY_MESSAGE(msg) JSON_HEDLEY_PRAGMA(_CRI message msg)
#elif JSON_HEDLEY_IAR_VERSION_CHECK(8,0,0)
#  define JSON_HEDLEY_MESSAGE(msg) JSON_HEDLEY_PRAGMA(message(msg))
#elif JSON_HEDLEY_PELLES_VERSION_CHECK(2,0,0)
#  define JSON_HEDLEY_MESSAGE(msg) JSON_HEDLEY_PRAGMA(message(msg))
#else
#  define JSON_HEDLEY_MESSAGE(msg)
#endif
#if defined(JSON_HEDLEY_WARNING)
    #undef JSON_HEDLEY_WARNING
#endif
#if JSON_HEDLEY_HAS_WARNING("-Wunknown-pragmas")
#  define JSON_HEDLEY_WARNING(msg) \
    JSON_HEDLEY_DIAGNOSTIC_PUSH \
    JSON_HEDLEY_DIAGNOSTIC_DISABLE_UNKNOWN_PRAGMAS \
    JSON_HEDLEY_PRAGMA(clang warning msg) \
    JSON_HEDLEY_DIAGNOSTIC_POP
#elif \
  JSON_HEDLEY_GCC_VERSION_CHECK(4,8,0) || \
  JSON_HEDLEY_PGI_VERSION_CHECK(18,4,0) || \
  JSON_HEDLEY_INTEL_VERSION_CHECK(13,0,0)
#  define JSON_HEDLEY_WARNING(msg) JSON_HEDLEY_PRAGMA(GCC warning msg)
#elif \
  JSON_HEDLEY_MSVC_VERSION_CHECK(15,0,0) || \
  JSON_HEDLEY_INTEL_CL_VERSION_CHECK(2021,1,0)
#  define JSON_HEDLEY_WARNING(msg) JSON_HEDLEY_PRAGMA(message(msg))
#else
#  define JSON_HEDLEY_WARNING(msg) JSON_HEDLEY_MESSAGE(msg)
#endif
#if defined(JSON_HEDLEY_REQUIRE)
    #undef JSON_HEDLEY_REQUIRE
#endif
#if defined(JSON_HEDLEY_REQUIRE_MSG)
    #undef JSON_HEDLEY_REQUIRE_MSG
#endif
#if JSON_HEDLEY_HAS_ATTRIBUTE(diagnose_if)
#  if JSON_HEDLEY_HAS_WARNING("-Wgcc-compat")
#    define JSON_HEDLEY_REQUIRE(expr) \
    JSON_HEDLEY_DIAGNOSTIC_PUSH \
    _Pragma("clang diagnostic ignored \"-Wgcc-compat\"") \
    __attribute__((diagnose_if(!(expr), #expr, "error"))) \
    JSON_HEDLEY_DIAGNOSTIC_POP
#    define JSON_HEDLEY_REQUIRE_MSG(expr,msg) \
    JSON_HEDLEY_DIAGNOSTIC_PUSH \
    _Pragma("clang diagnostic ignored \"-Wgcc-compat\"") \
    __attribute__((diagnose_if(!(expr), msg, "error"))) \
    JSON_HEDLEY_DIAGNOSTIC_POP
#  else
#    define JSON_HEDLEY_REQUIRE(expr) __attribute__((diagnose_if(!(expr), #expr, "error")))
#    define JSON_HEDLEY_REQUIRE_MSG(expr,msg) __attribute__((diagnose_if(!(expr), msg, "error")))
#  endif
#else
#  define JSON_HEDLEY_REQUIRE(expr)
#  define JSON_HEDLEY_REQUIRE_MSG(expr,msg)
#endif
#if defined(JSON_HEDLEY_FLAGS)
    #undef JSON_HEDLEY_FLAGS
#endif
#if JSON_HEDLEY_HAS_ATTRIBUTE(flag_enum) && (!defined(__cplusplus) || JSON_HEDLEY_HAS_WARNING("-Wbitfield-enum-conversion"))
    #define JSON_HEDLEY_FLAGS __attribute__((__flag_enum__))
#else
    #define JSON_HEDLEY_FLAGS
#endif
#if defined(JSON_HEDLEY_FLAGS_CAST)
    #undef JSON_HEDLEY_FLAGS_CAST
#endif
#if JSON_HEDLEY_INTEL_VERSION_CHECK(19,0,0)
#  define JSON_HEDLEY_FLAGS_CAST(T, expr) (__extension__ ({ \
        JSON_HEDLEY_DIAGNOSTIC_PUSH \
        _Pragma("warning(disable:188)") \
        ((T) (expr)); \
        JSON_HEDLEY_DIAGNOSTIC_POP \
    }))
#else
#  define JSON_HEDLEY_FLAGS_CAST(T, expr) JSON_HEDLEY_STATIC_CAST(T, expr)
#endif
#if defined(JSON_HEDLEY_EMPTY_BASES)
    #undef JSON_HEDLEY_EMPTY_BASES
#endif
#if \
    (JSON_HEDLEY_MSVC_VERSION_CHECK(19,0,23918) && !JSON_HEDLEY_MSVC_VERSION_CHECK(20,0,0)) || \
    JSON_HEDLEY_INTEL_CL_VERSION_CHECK(2021,1,0)
    #define JSON_HEDLEY_EMPTY_BASES __declspec(empty_bases)
#else
    #define JSON_HEDLEY_EMPTY_BASES
#endif
#if defined(JSON_HEDLEY_GCC_NOT_CLANG_VERSION_CHECK)
    #undef JSON_HEDLEY_GCC_NOT_CLANG_VERSION_CHECK
#endif
#if defined(__clang__)
    #define JSON_HEDLEY_GCC_NOT_CLANG_VERSION_CHECK(major,minor,patch) (0)
#else
    #define JSON_HEDLEY_GCC_NOT_CLANG_VERSION_CHECK(major,minor,patch) JSON_HEDLEY_GCC_VERSION_CHECK(major,minor,patch)
#endif
#if defined(JSON_HEDLEY_CLANG_HAS_ATTRIBUTE)
    #undef JSON_HEDLEY_CLANG_HAS_ATTRIBUTE
#endif
#define JSON_HEDLEY_CLANG_HAS_ATTRIBUTE(attribute) JSON_HEDLEY_HAS_ATTRIBUTE(attribute)
#if defined(JSON_HEDLEY_CLANG_HAS_CPP_ATTRIBUTE)
    #undef JSON_HEDLEY_CLANG_HAS_CPP_ATTRIBUTE
#endif
#define JSON_HEDLEY_CLANG_HAS_CPP_ATTRIBUTE(attribute) JSON_HEDLEY_HAS_CPP_ATTRIBUTE(attribute)
#if defined(JSON_HEDLEY_CLANG_HAS_BUILTIN)
    #undef JSON_HEDLEY_CLANG_HAS_BUILTIN
#endif
#define JSON_HEDLEY_CLANG_HAS_BUILTIN(builtin) JSON_HEDLEY_HAS_BUILTIN(builtin)
#if defined(JSON_HEDLEY_CLANG_HAS_FEATURE)
    #undef JSON_HEDLEY_CLANG_HAS_FEATURE
#endif
#define JSON_HEDLEY_CLANG_HAS_FEATURE(feature) JSON_HEDLEY_HAS_FEATURE(feature)
#if defined(JSON_HEDLEY_CLANG_HAS_EXTENSION)
    #undef JSON_HEDLEY_CLANG_HAS_EXTENSION
#endif
#define JSON_HEDLEY_CLANG_HAS_EXTENSION(extension) JSON_HEDLEY_HAS_EXTENSION(extension)
#if defined(JSON_HEDLEY_CLANG_HAS_DECLSPEC_DECLSPEC_ATTRIBUTE)
    #undef JSON_HEDLEY_CLANG_HAS_DECLSPEC_DECLSPEC_ATTRIBUTE
#endif
#define JSON_HEDLEY_CLANG_HAS_DECLSPEC_ATTRIBUTE(attribute) JSON_HEDLEY_HAS_DECLSPEC_ATTRIBUTE(attribute)
#if defined(JSON_HEDLEY_CLANG_HAS_WARNING)
    #undef JSON_HEDLEY_CLANG_HAS_WARNING
#endif
#define JSON_HEDLEY_CLANG_HAS_WARNING(warning) JSON_HEDLEY_HAS_WARNING(warning)
#endif 
#if !defined(JSON_SKIP_UNSUPPORTED_COMPILER_CHECK)
    #if defined(__clang__)
        #if (__clang_major__ * 10000 + __clang_minor__ * 100 + __clang_patchlevel__) < 30400
            #error "unsupported Clang version - see https://github.com/nlohmann/json#supported-compilers"
        #endif
    #elif defined(__GNUC__) && !(defined(__ICC) || defined(__INTEL_COMPILER))
        #if (__GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__) < 40800
            #error "unsupported GCC version - see https://github.com/nlohmann/json#supported-compilers"
        #endif
    #endif
#endif
#if !defined(JSON_HAS_CPP_26) && !defined(JSON_HAS_CPP_23) && !defined(JSON_HAS_CPP_20) && !defined(JSON_HAS_CPP_17) && !defined(JSON_HAS_CPP_14) && !defined(JSON_HAS_CPP_11)
    #if (defined(__cplusplus) && __cplusplus > 202302L) || (defined(_MSVC_LANG) && _MSVC_LANG > 202302L)
        #define JSON_HAS_CPP_26
        #define JSON_HAS_CPP_23
        #define JSON_HAS_CPP_20
        #define JSON_HAS_CPP_17
        #define JSON_HAS_CPP_14
    #elif (defined(__cplusplus) && __cplusplus > 202002L) || (defined(_MSVC_LANG) && _MSVC_LANG > 202002L)
        #define JSON_HAS_CPP_23
        #define JSON_HAS_CPP_20
        #define JSON_HAS_CPP_17
        #define JSON_HAS_CPP_14
    #elif (defined(__cplusplus) && __cplusplus > 201703L) || (defined(_MSVC_LANG) && _MSVC_LANG > 201703L)
        #define JSON_HAS_CPP_20
        #define JSON_HAS_CPP_17
        #define JSON_HAS_CPP_14
    #elif (defined(__cplusplus) && __cplusplus > 201402L) || (defined(_HAS_CXX17) && _HAS_CXX17 == 1) 
        #define JSON_HAS_CPP_17
        #define JSON_HAS_CPP_14
    #elif (defined(__cplusplus) && __cplusplus > 201103L) || (defined(_HAS_CXX14) && _HAS_CXX14 == 1)
        #define JSON_HAS_CPP_14
    #endif
    #define JSON_HAS_CPP_11
#endif
#ifdef __has_include
    #if __has_include(<version>)
        #include <version>
    #endif
#endif
#if !defined(JSON_HAS_FILESYSTEM) && !defined(JSON_HAS_EXPERIMENTAL_FILESYSTEM)
    #ifdef JSON_HAS_CPP_17
        #if defined(__cpp_lib_filesystem)
            #define JSON_HAS_FILESYSTEM 1
        #elif defined(__cpp_lib_experimental_filesystem)
            #define JSON_HAS_EXPERIMENTAL_FILESYSTEM 1
        #elif !defined(__has_include)
            #define JSON_HAS_EXPERIMENTAL_FILESYSTEM 1
        #elif __has_include(<filesystem>)
            #define JSON_HAS_FILESYSTEM 1
        #elif __has_include(<experimental/filesystem>)
            #define JSON_HAS_EXPERIMENTAL_FILESYSTEM 1
        #endif
        #if defined(__MINGW32__) && defined(__GNUC__) && __GNUC__ == 8
            #undef JSON_HAS_FILESYSTEM
            #undef JSON_HAS_EXPERIMENTAL_FILESYSTEM
        #endif
        #if defined(__GNUC__) && !defined(__clang__) && __GNUC__ < 8
            #undef JSON_HAS_FILESYSTEM
            #undef JSON_HAS_EXPERIMENTAL_FILESYSTEM
        #endif
        #if defined(__clang_major__) && __clang_major__ < 7
            #undef JSON_HAS_FILESYSTEM
            #undef JSON_HAS_EXPERIMENTAL_FILESYSTEM
        #endif
        #if defined(_MSC_VER) && _MSC_VER < 1914
            #undef JSON_HAS_FILESYSTEM
            #undef JSON_HAS_EXPERIMENTAL_FILESYSTEM
        #endif
        #if defined(__IPHONE_OS_VERSION_MIN_REQUIRED) && __IPHONE_OS_VERSION_MIN_REQUIRED < 130000
            #undef JSON_HAS_FILESYSTEM
            #undef JSON_HAS_EXPERIMENTAL_FILESYSTEM
        #endif
        #if defined(__MAC_OS_X_VERSION_MIN_REQUIRED) && __MAC_OS_X_VERSION_MIN_REQUIRED < 101500
            #undef JSON_HAS_FILESYSTEM
            #undef JSON_HAS_EXPERIMENTAL_FILESYSTEM
        #endif
    #endif
#endif
#ifndef JSON_HAS_EXPERIMENTAL_FILESYSTEM
    #define JSON_HAS_EXPERIMENTAL_FILESYSTEM 0
#endif
#ifndef JSON_HAS_FILESYSTEM
    #define JSON_HAS_FILESYSTEM 0
#endif
#ifndef JSON_HAS_THREE_WAY_COMPARISON
    #if defined(__cpp_impl_three_way_comparison) && __cpp_impl_three_way_comparison >= 201907L \
        && defined(__cpp_lib_three_way_comparison) && __cpp_lib_three_way_comparison >= 201907L
        #define JSON_HAS_THREE_WAY_COMPARISON 1
    #else
        #define JSON_HAS_THREE_WAY_COMPARISON 0
    #endif
#endif
#ifndef JSON_HAS_RANGES
    #if defined(__GLIBCXX__) && __GLIBCXX__ == 20210427
        #define JSON_HAS_RANGES 0
    #elif defined(_GLIBCXX_RELEASE) && _GLIBCXX_RELEASE < 11
        #define JSON_HAS_RANGES 0
    #elif defined(__clang__) && !defined(__apple_build_version__) \
        && __clang_major__ < 16 && defined(__GLIBCXX__)
        #define JSON_HAS_RANGES 0
    #elif defined(_LIBCPP_VERSION) && _LIBCPP_VERSION < 160000
        #define JSON_HAS_RANGES 0
    #elif defined(__CUDACC__) && defined(__CUDACC_VER_MAJOR__) && __CUDACC_VER_MAJOR__ == 12 \
        && defined(__CUDACC_VER_MINOR__) && (__CUDACC_VER_MINOR__ == 0 || __CUDACC_VER_MINOR__ == 1)
        #define JSON_HAS_RANGES 0
    #elif defined(__cpp_lib_ranges)
        #define JSON_HAS_RANGES 1
    #else
        #define JSON_HAS_RANGES 0
    #endif
#endif
#ifndef JSON_HAS_STD_FORMAT
    #if defined(JSON_HAS_CPP_20) && defined(__cpp_lib_format)
        #define JSON_HAS_STD_FORMAT 1
    #else
        #define JSON_HAS_STD_FORMAT 0
    #endif
#endif
#ifndef JSON_HAS_STATIC_RTTI
    #if !defined(_HAS_STATIC_RTTI) || _HAS_STATIC_RTTI != 0
        #define JSON_HAS_STATIC_RTTI 1
    #else
        #define JSON_HAS_STATIC_RTTI 0
    #endif
#endif
#ifdef JSON_HAS_CPP_17
    #define JSON_INLINE_VARIABLE inline
#else
    #define JSON_INLINE_VARIABLE
#endif
#if JSON_HEDLEY_HAS_ATTRIBUTE(no_unique_address)
    #define JSON_NO_UNIQUE_ADDRESS [[no_unique_address]]
#else
    #define JSON_NO_UNIQUE_ADDRESS
#endif
#if !defined(JSON_NO_THREAD_LOCAL) && defined(__clang__) && defined(__MINGW32__)
    #define JSON_NO_THREAD_LOCAL 1
#endif
#if (defined(__cpp_exceptions) || defined(__EXCEPTIONS) || defined(_CPPUNWIND)) && !defined(JSON_NOEXCEPTION)
    #define JSON_THROW(exception) throw exception
    #define JSON_TRY try
    #define JSON_CATCH(exception) catch(exception)
    #define JSON_INTERNAL_CATCH(exception) catch(exception)
#else
    #include <cstdlib>
    #define JSON_THROW(exception) std::abort()
    #define JSON_TRY if(true)
    #define JSON_CATCH(exception) if(false)
    #define JSON_INTERNAL_CATCH(exception) if(false)
#endif
#if defined(JSON_THROW_USER)
    #undef JSON_THROW
    #define JSON_THROW JSON_THROW_USER
#endif
#if defined(JSON_TRY_USER)
    #undef JSON_TRY
    #define JSON_TRY JSON_TRY_USER
#endif
#if defined(JSON_CATCH_USER)
    #undef JSON_CATCH
    #define JSON_CATCH JSON_CATCH_USER
    #undef JSON_INTERNAL_CATCH
    #define JSON_INTERNAL_CATCH JSON_CATCH_USER
#endif
#if defined(JSON_INTERNAL_CATCH_USER)
    #undef JSON_INTERNAL_CATCH
    #define JSON_INTERNAL_CATCH JSON_INTERNAL_CATCH_USER
#endif
#if !defined(JSON_ASSERT)
    #include <cassert> 
    #define JSON_ASSERT(x) assert(x)
#endif
#if defined(JSON_TESTS_PRIVATE)
    #define JSON_PRIVATE_UNLESS_TESTED public
#else
    #define JSON_PRIVATE_UNLESS_TESTED private
#endif
#define NLOHMANN_JSON_SERIALIZE_ENUM(ENUM_TYPE, ...)                                            \
    template<typename BasicJsonType>                                                            \
    inline void to_json(BasicJsonType& j, const ENUM_TYPE& e)                                   \
    {                                                                                           \
                                        \
        static_assert(std::is_enum<ENUM_TYPE>::value, #ENUM_TYPE " must be an enum!");          \
         \
        static const std::pair<ENUM_TYPE, BasicJsonType> m[] = __VA_ARGS__;                     \
        auto it = std::find_if(std::begin(m), std::end(m),                                      \
                               [e](const std::pair<ENUM_TYPE, BasicJsonType>& ej_pair) -> bool  \
        {                                                                                       \
            return ej_pair.first == e;                                                          \
        });                                                                                     \
        j = ((it != std::end(m)) ? it : std::begin(m))->second;                                 \
    }                                                                                           \
    template<typename BasicJsonType>                                                            \
    inline void from_json(const BasicJsonType& j, ENUM_TYPE& e)                                 \
    {                                                                                           \
                                        \
        static_assert(std::is_enum<ENUM_TYPE>::value, #ENUM_TYPE " must be an enum!");          \
         \
        static const std::pair<ENUM_TYPE, BasicJsonType> m[] = __VA_ARGS__;                     \
        auto it = std::find_if(std::begin(m), std::end(m),                                      \
                               [&j](const std::pair<ENUM_TYPE, BasicJsonType>& ej_pair) -> bool \
        {                                                                                       \
            return ej_pair.second == j;                                                         \
        });                                                                                     \
        e = ((it != std::end(m)) ? it : std::begin(m))->first;                                  \
    }
template<typename ExceptionType>
void templated_json_throw(ExceptionType exception)
{
    JSON_THROW(exception);
    (void)exception;
}
#define NLOHMANN_JSON_SERIALIZE_ENUM_STRICT(ENUM_TYPE, ...)                                     \
    template<typename BasicJsonType>                                                            \
    inline void to_json(BasicJsonType& j, const ENUM_TYPE& e)                                   \
    {                                                                                           \
                                        \
        static_assert(std::is_enum<ENUM_TYPE>::value, #ENUM_TYPE " must be an enum!");          \
         \
        static const std::pair<ENUM_TYPE, BasicJsonType> m[] = __VA_ARGS__;                     \
        auto it = std::find_if(std::begin(m), std::end(m),                                      \
                               [e](const std::pair<ENUM_TYPE, BasicJsonType>& ej_pair) -> bool  \
        {                                                                                       \
            return ej_pair.first == e;                                                          \
        });                                                                                     \
        if (it != std::end(m)) j = it->second;                                                  \
        else templated_json_throw<nlohmann::detail::out_of_range>(nlohmann::detail::out_of_range::create(410,"enum value out of range for " #ENUM_TYPE, nullptr)); \
    }                                                                                           \
    template<typename BasicJsonType>                                                            \
    inline void from_json(const BasicJsonType& j, ENUM_TYPE& e)                                 \
    {                                                                                           \
                                        \
        static_assert(std::is_enum<ENUM_TYPE>::value, #ENUM_TYPE " must be an enum!");          \
         \
        static const std::pair<ENUM_TYPE, BasicJsonType> m[] = __VA_ARGS__;                     \
        auto it = std::find_if(std::begin(m), std::end(m),                                      \
                               [&j](const std::pair<ENUM_TYPE, BasicJsonType>& ej_pair) -> bool \
        {                                                                                       \
            return ej_pair.second == j;                                                         \
        });                                                                                     \
        if (it != std::end(m)) e = it->first;                                                   \
        else templated_json_throw<nlohmann::detail::out_of_range>(nlohmann::detail::out_of_range::create(410, nlohmann::detail::concat("enum value out of range for " #ENUM_TYPE ": ", j.dump(-1, ' ', false, nlohmann::detail::error_handler_t::replace)), &j)); \
    }
#define NLOHMANN_BASIC_JSON_TPL_DECLARATION                                \
    template<template<typename, typename, typename...> class ObjectType,   \
             template<typename, typename...> class ArrayType,              \
             class StringType, class BooleanType, class NumberIntegerType, \
             class NumberUnsignedType, class NumberFloatType,              \
             template<typename> class AllocatorType,                       \
             template<typename, typename = void> class JSONSerializer,     \
             class BinaryType,                                             \
             class CustomBaseClass>
#define NLOHMANN_BASIC_JSON_TPL                                            \
    basic_json<ObjectType, ArrayType, StringType, BooleanType,             \
    NumberIntegerType, NumberUnsignedType, NumberFloatType,                \
    AllocatorType, JSONSerializer, BinaryType, CustomBaseClass>
#define NLOHMANN_JSON_EXPAND( x ) x
#define NLOHMANN_JSON_GET_MACRO(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, NAME,...) NAME
#define NLOHMANN_JSON_PASTE(...) NLOHMANN_JSON_EXPAND(NLOHMANN_JSON_GET_MACRO(__VA_ARGS__, \
        NLOHMANN_JSON_PASTE64, \
        NLOHMANN_JSON_PASTE63, \
        NLOHMANN_JSON_PASTE62, \
        NLOHMANN_JSON_PASTE61, \
        NLOHMANN_JSON_PASTE60, \
        NLOHMANN_JSON_PASTE59, \
        NLOHMANN_JSON_PASTE58, \
        NLOHMANN_JSON_PASTE57, \
        NLOHMANN_JSON_PASTE56, \
        NLOHMANN_JSON_PASTE55, \
        NLOHMANN_JSON_PASTE54, \
        NLOHMANN_JSON_PASTE53, \
        NLOHMANN_JSON_PASTE52, \
        NLOHMANN_JSON_PASTE51, \
        NLOHMANN_JSON_PASTE50, \
        NLOHMANN_JSON_PASTE49, \
        NLOHMANN_JSON_PASTE48, \
        NLOHMANN_JSON_PASTE47, \
        NLOHMANN_JSON_PASTE46, \
        NLOHMANN_JSON_PASTE45, \
        NLOHMANN_JSON_PASTE44, \
        NLOHMANN_JSON_PASTE43, \
        NLOHMANN_JSON_PASTE42, \
        NLOHMANN_JSON_PASTE41, \
        NLOHMANN_JSON_PASTE40, \
        NLOHMANN_JSON_PASTE39, \
        NLOHMANN_JSON_PASTE38, \
        NLOHMANN_JSON_PASTE37, \
        NLOHMANN_JSON_PASTE36, \
        NLOHMANN_JSON_PASTE35, \
        NLOHMANN_JSON_PASTE34, \
        NLOHMANN_JSON_PASTE33, \
        NLOHMANN_JSON_PASTE32, \
        NLOHMANN_JSON_PASTE31, \
        NLOHMANN_JSON_PASTE30, \
        NLOHMANN_JSON_PASTE29, \
        NLOHMANN_JSON_PASTE28, \
        NLOHMANN_JSON_PASTE27, \
        NLOHMANN_JSON_PASTE26, \
        NLOHMANN_JSON_PASTE25, \
        NLOHMANN_JSON_PASTE24, \
        NLOHMANN_JSON_PASTE23, \
        NLOHMANN_JSON_PASTE22, \
        NLOHMANN_JSON_PASTE21, \
        NLOHMANN_JSON_PASTE20, \
        NLOHMANN_JSON_PASTE19, \
        NLOHMANN_JSON_PASTE18, \
        NLOHMANN_JSON_PASTE17, \
        NLOHMANN_JSON_PASTE16, \
        NLOHMANN_JSON_PASTE15, \
        NLOHMANN_JSON_PASTE14, \
        NLOHMANN_JSON_PASTE13, \
        NLOHMANN_JSON_PASTE12, \
        NLOHMANN_JSON_PASTE11, \
        NLOHMANN_JSON_PASTE10, \
        NLOHMANN_JSON_PASTE9, \
        NLOHMANN_JSON_PASTE8, \
        NLOHMANN_JSON_PASTE7, \
        NLOHMANN_JSON_PASTE6, \
        NLOHMANN_JSON_PASTE5, \
        NLOHMANN_JSON_PASTE4, \
        NLOHMANN_JSON_PASTE3, \
        NLOHMANN_JSON_PASTE2, \
        NLOHMANN_JSON_PASTE1)(__VA_ARGS__))
#define NLOHMANN_JSON_PASTE2(func, v1) func(v1)
#define NLOHMANN_JSON_PASTE3(func, v1, v2) NLOHMANN_JSON_PASTE2(func, v1) NLOHMANN_JSON_PASTE2(func, v2)
#define NLOHMANN_JSON_PASTE4(func, v1, v2, v3) NLOHMANN_JSON_PASTE2(func, v1) NLOHMANN_JSON_PASTE3(func, v2, v3)
#define NLOHMANN_JSON_PASTE5(func, v1, v2, v3, v4) NLOHMANN_JSON_PASTE2(func, v1) NLOHMANN_JSON_PASTE4(func, v2, v3, v4)
#define NLOHMANN_JSON_PASTE6(func, v1, v2, v3, v4, v5) NLOHMANN_JSON_PASTE2(func, v1) NLOHMANN_JSON_PASTE5(func, v2, v3, v4, v5)
#define NLOHMANN_JSON_PASTE7(func, v1, v2, v3, v4, v5, v6) NLOHMANN_JSON_PASTE2(func, v1) NLOHMANN_JSON_PASTE6(func, v2, v3, v4, v5, v6)
#define NLOHMANN_JSON_PASTE8(func, v1, v2, v3, v4, v5, v6, v7) NLOHMANN_JSON_PASTE2(func, v1) NLOHMANN_JSON_PASTE7(func, v2, v3, v4, v5, v6, v7)
#define NLOHMANN_JSON_PASTE9(func, v1, v2, v3, v4, v5, v6, v7, v8) NLOHMANN_JSON_PASTE2(func, v1) NLOHMANN_JSON_PASTE8(func, v2, v3, v4, v5, v6, v7, v8)
#define NLOHMANN_JSON_PASTE10(func, v1, v2, v3, v4, v5, v6, v7, v8, v9) NLOHMANN_JSON_PASTE2(func, v1) NLOHMANN_JSON_PASTE9(func, v2, v3, v4, v5, v6, v7, v8, v9)
#define NLOHMANN_JSON_PASTE11(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) NLOHMANN_JSON_PASTE2(func, v1) NLOHMANN_JSON_PASTE10(func, v2, v3, v4, v5, v6, v7, v8, v9, v10)
#define NLOHMANN_JSON_PASTE12(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11) NLOHMANN_JSON_PASTE2(func, v1) NLOHMANN_JSON_PASTE11(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11)
#define NLOHMANN_JSON_PASTE13(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12) NLOHMANN_JSON_PASTE2(func, v1) NLOHMANN_JSON_PASTE12(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12)
#define NLOHMANN_JSON_PASTE14(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13) NLOHMANN_JSON_PASTE2(func, v1) NLOHMANN_JSON_PASTE13(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13)
#define NLOHMANN_JSON_PASTE15(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14) NLOHMANN_JSON_PASTE2(func, v1) NLOHMANN_JSON_PASTE14(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14)
#define NLOHMANN_JSON_PASTE16(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15) NLOHMANN_JSON_PASTE2(func, v1) NLOHMANN_JSON_PASTE15(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15)
#define NLOHMANN_JSON_PASTE17(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) NLOHMANN_JSON_PASTE2(func, v1) NLOHMANN_JSON_PASTE16(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#define NLOHMANN_JSON_PASTE18(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17) NLOHMANN_JSON_PASTE2(func, v1) NLOHMANN_JSON_PASTE17(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17)
#define NLOHMANN_JSON_PASTE19(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18) NLOHMANN_JSON_PASTE2(func, v1) NLOHMANN_JSON_PASTE18(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18)
#define NLOHMANN_JSON_PASTE20(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19) NLOHMANN_JSON_PASTE2(func, v1) NLOHMANN_JSON_PASTE19(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19)
#define NLOHMANN_JSON_PASTE21(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20) NLOHMANN_JSON_PASTE2(func, v1) NLOHMANN_JSON_PASTE20(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20)
#define NLOHMANN_JSON_PASTE22(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21) NLOHMANN_JSON_PASTE2(func, v1) NLOHMANN_JSON_PASTE21(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21)
#define NLOHMANN_JSON_PASTE23(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22) NLOHMANN_JSON_PASTE2(func, v1) NLOHMANN_JSON_PASTE22(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22)
#define NLOHMANN_JSON_PASTE24(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23) NLOHMANN_JSON_PASTE2(func, v1) NLOHMANN_JSON_PASTE23(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23)
#define NLOHMANN_JSON_PASTE25(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24) NLOHMANN_JSON_PASTE2(func, v1) NLOHMANN_JSON_PASTE24(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24)
#define NLOHMANN_JSON_PASTE26(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25) NLOHMANN_JSON_PASTE2(func, v1) NLOHMANN_JSON_PASTE25(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25)
#define NLOHMANN_JSON_PASTE27(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26) NLOHMANN_JSON_PASTE2(func, v1) NLOHMANN_JSON_PASTE26(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26)
#define NLOHMANN_JSON_PASTE28(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27) NLOHMANN_JSON_PASTE2(func, v1) NLOHMANN_JSON_PASTE27(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27)
#define NLOHMANN_JSON_PASTE29(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28) NLOHMANN_JSON_PASTE2(func, v1) NLOHMANN_JSON_PASTE28(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28)
#define NLOHMANN_JSON_PASTE30(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29) NLOHMANN_JSON_PASTE2(func, v1) NLOHMANN_JSON_PASTE29(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29)
#define NLOHMANN_JSON_PASTE31(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30) NLOHMANN_JSON_PASTE2(func, v1) NLOHMANN_JSON_PASTE30(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30)
#define NLOHMANN_JSON_PASTE32(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31) NLOHMANN_JSON_PASTE2(func, v1) NLOHMANN_JSON_PASTE31(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31)
#define NLOHMANN_JSON_PASTE33(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32) NLOHMANN_JSON_PASTE2(func, v1) NLOHMANN_JSON_PASTE32(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32)
#define NLOHMANN_JSON_PASTE34(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33) NLOHMANN_JSON_PASTE2(func, v1) NLOHMANN_JSON_PASTE33(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33)
#define NLOHMANN_JSON_PASTE35(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34) NLOHMANN_JSON_PASTE2(func, v1) NLOHMANN_JSON_PASTE34(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34)
#define NLOHMANN_JSON_PASTE36(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35) NLOHMANN_JSON_PASTE2(func, v1) NLOHMANN_JSON_PASTE35(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35)
#define NLOHMANN_JSON_PASTE37(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36) NLOHMANN_JSON_PASTE2(func, v1) NLOHMANN_JSON_PASTE36(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36)
#define NLOHMANN_JSON_PASTE38(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37) NLOHMANN_JSON_PASTE2(func, v1) NLOHMANN_JSON_PASTE37(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37)
#define NLOHMANN_JSON_PASTE39(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38) NLOHMANN_JSON_PASTE2(func, v1) NLOHMANN_JSON_PASTE38(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38)
#define NLOHMANN_JSON_PASTE40(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39) NLOHMANN_JSON_PASTE2(func, v1) NLOHMANN_JSON_PASTE39(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39)
#define NLOHMANN_JSON_PASTE41(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40) NLOHMANN_JSON_PASTE2(func, v1) NLOHMANN_JSON_PASTE40(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40)
#define NLOHMANN_JSON_PASTE42(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41) NLOHMANN_JSON_PASTE2(func, v1) NLOHMANN_JSON_PASTE41(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41)
#define NLOHMANN_JSON_PASTE43(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42) NLOHMANN_JSON_PASTE2(func, v1) NLOHMANN_JSON_PASTE42(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42)
#define NLOHMANN_JSON_PASTE44(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43) NLOHMANN_JSON_PASTE2(func, v1) NLOHMANN_JSON_PASTE43(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43)
#define NLOHMANN_JSON_PASTE45(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44) NLOHMANN_JSON_PASTE2(func, v1) NLOHMANN_JSON_PASTE44(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44)
#define NLOHMANN_JSON_PASTE46(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45) NLOHMANN_JSON_PASTE2(func, v1) NLOHMANN_JSON_PASTE45(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45)
#define NLOHMANN_JSON_PASTE47(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46) NLOHMANN_JSON_PASTE2(func, v1) NLOHMANN_JSON_PASTE46(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46)
#define NLOHMANN_JSON_PASTE48(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47) NLOHMANN_JSON_PASTE2(func, v1) NLOHMANN_JSON_PASTE47(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47)
#define NLOHMANN_JSON_PASTE49(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48) NLOHMANN_JSON_PASTE2(func, v1) NLOHMANN_JSON_PASTE48(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48)
#define NLOHMANN_JSON_PASTE50(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49) NLOHMANN_JSON_PASTE2(func, v1) NLOHMANN_JSON_PASTE49(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49)
#define NLOHMANN_JSON_PASTE51(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50) NLOHMANN_JSON_PASTE2(func, v1) NLOHMANN_JSON_PASTE50(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50)
#define NLOHMANN_JSON_PASTE52(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51) NLOHMANN_JSON_PASTE2(func, v1) NLOHMANN_JSON_PASTE51(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51)
#define NLOHMANN_JSON_PASTE53(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52) NLOHMANN_JSON_PASTE2(func, v1) NLOHMANN_JSON_PASTE52(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52)
#define NLOHMANN_JSON_PASTE54(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53) NLOHMANN_JSON_PASTE2(func, v1) NLOHMANN_JSON_PASTE53(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53)
#define NLOHMANN_JSON_PASTE55(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54) NLOHMANN_JSON_PASTE2(func, v1) NLOHMANN_JSON_PASTE54(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54)
#define NLOHMANN_JSON_PASTE56(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55) NLOHMANN_JSON_PASTE2(func, v1) NLOHMANN_JSON_PASTE55(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55)
#define NLOHMANN_JSON_PASTE57(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56) NLOHMANN_JSON_PASTE2(func, v1) NLOHMANN_JSON_PASTE56(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56)
#define NLOHMANN_JSON_PASTE58(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57) NLOHMANN_JSON_PASTE2(func, v1) NLOHMANN_JSON_PASTE57(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57)
#define NLOHMANN_JSON_PASTE59(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58) NLOHMANN_JSON_PASTE2(func, v1) NLOHMANN_JSON_PASTE58(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58)
#define NLOHMANN_JSON_PASTE60(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59) NLOHMANN_JSON_PASTE2(func, v1) NLOHMANN_JSON_PASTE59(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59)
#define NLOHMANN_JSON_PASTE61(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60) NLOHMANN_JSON_PASTE2(func, v1) NLOHMANN_JSON_PASTE60(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60)
#define NLOHMANN_JSON_PASTE62(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61) NLOHMANN_JSON_PASTE2(func, v1) NLOHMANN_JSON_PASTE61(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61)
#define NLOHMANN_JSON_PASTE63(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62) NLOHMANN_JSON_PASTE2(func, v1) NLOHMANN_JSON_PASTE62(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62)
#define NLOHMANN_JSON_PASTE64(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63) NLOHMANN_JSON_PASTE2(func, v1) NLOHMANN_JSON_PASTE63(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63)
#define NLOHMANN_JSON_DOUBLE_PASTE(...) NLOHMANN_JSON_EXPAND(NLOHMANN_JSON_GET_MACRO(__VA_ARGS__, \
        NLOHMANN_JSON_DOUBLE_PASTE63, \
        NLOHMANN_JSON_DOUBLE_PASTE63, \
        NLOHMANN_JSON_DOUBLE_PASTE61, \
        NLOHMANN_JSON_DOUBLE_PASTE61, \
        NLOHMANN_JSON_DOUBLE_PASTE59, \
        NLOHMANN_JSON_DOUBLE_PASTE59, \
        NLOHMANN_JSON_DOUBLE_PASTE57, \
        NLOHMANN_JSON_DOUBLE_PASTE57, \
        NLOHMANN_JSON_DOUBLE_PASTE55, \
        NLOHMANN_JSON_DOUBLE_PASTE55, \
        NLOHMANN_JSON_DOUBLE_PASTE53, \
        NLOHMANN_JSON_DOUBLE_PASTE53, \
        NLOHMANN_JSON_DOUBLE_PASTE51, \
        NLOHMANN_JSON_DOUBLE_PASTE51, \
        NLOHMANN_JSON_DOUBLE_PASTE49, \
        NLOHMANN_JSON_DOUBLE_PASTE49, \
        NLOHMANN_JSON_DOUBLE_PASTE47, \
        NLOHMANN_JSON_DOUBLE_PASTE47, \
        NLOHMANN_JSON_DOUBLE_PASTE45, \
        NLOHMANN_JSON_DOUBLE_PASTE45, \
        NLOHMANN_JSON_DOUBLE_PASTE43, \
        NLOHMANN_JSON_DOUBLE_PASTE43, \
        NLOHMANN_JSON_DOUBLE_PASTE41, \
        NLOHMANN_JSON_DOUBLE_PASTE41, \
        NLOHMANN_JSON_DOUBLE_PASTE39, \
        NLOHMANN_JSON_DOUBLE_PASTE39, \
        NLOHMANN_JSON_DOUBLE_PASTE37, \
        NLOHMANN_JSON_DOUBLE_PASTE37, \
        NLOHMANN_JSON_DOUBLE_PASTE35, \
        NLOHMANN_JSON_DOUBLE_PASTE35, \
        NLOHMANN_JSON_DOUBLE_PASTE33, \
        NLOHMANN_JSON_DOUBLE_PASTE33, \
        NLOHMANN_JSON_DOUBLE_PASTE31, \
        NLOHMANN_JSON_DOUBLE_PASTE31, \
        NLOHMANN_JSON_DOUBLE_PASTE29, \
        NLOHMANN_JSON_DOUBLE_PASTE29, \
        NLOHMANN_JSON_DOUBLE_PASTE27, \
        NLOHMANN_JSON_DOUBLE_PASTE27, \
        NLOHMANN_JSON_DOUBLE_PASTE25, \
        NLOHMANN_JSON_DOUBLE_PASTE25, \
        NLOHMANN_JSON_DOUBLE_PASTE23, \
        NLOHMANN_JSON_DOUBLE_PASTE23, \
        NLOHMANN_JSON_DOUBLE_PASTE21, \
        NLOHMANN_JSON_DOUBLE_PASTE21, \
        NLOHMANN_JSON_DOUBLE_PASTE19, \
        NLOHMANN_JSON_DOUBLE_PASTE19, \
        NLOHMANN_JSON_DOUBLE_PASTE17, \
        NLOHMANN_JSON_DOUBLE_PASTE17, \
        NLOHMANN_JSON_DOUBLE_PASTE15, \
        NLOHMANN_JSON_DOUBLE_PASTE15, \
        NLOHMANN_JSON_DOUBLE_PASTE13, \
        NLOHMANN_JSON_DOUBLE_PASTE13, \
        NLOHMANN_JSON_DOUBLE_PASTE11, \
        NLOHMANN_JSON_DOUBLE_PASTE11, \
        NLOHMANN_JSON_DOUBLE_PASTE9, \
        NLOHMANN_JSON_DOUBLE_PASTE9, \
        NLOHMANN_JSON_DOUBLE_PASTE7, \
        NLOHMANN_JSON_DOUBLE_PASTE7, \
        NLOHMANN_JSON_DOUBLE_PASTE5, \
        NLOHMANN_JSON_DOUBLE_PASTE5, \
        NLOHMANN_JSON_DOUBLE_PASTE3, \
        NLOHMANN_JSON_DOUBLE_PASTE3, \
        NLOHMANN_JSON_DOUBLE_PASTE1, \
        NLOHMANN_JSON_DOUBLE_PASTE1)(__VA_ARGS__))
#define NLOHMANN_JSON_DOUBLE_PASTE3(func, v1, v2) func(v1, v2)
#define NLOHMANN_JSON_DOUBLE_PASTE5(func, v1, v2, v3, v4) NLOHMANN_JSON_DOUBLE_PASTE3(func, v1, v2) NLOHMANN_JSON_DOUBLE_PASTE3(func, v3, v4)
#define NLOHMANN_JSON_DOUBLE_PASTE7(func, v1, v2, v3, v4, v5, v6) NLOHMANN_JSON_DOUBLE_PASTE3(func, v1, v2) NLOHMANN_JSON_DOUBLE_PASTE5(func, v3, v4, v5, v6)
#define NLOHMANN_JSON_DOUBLE_PASTE9(func, v1, v2, v3, v4, v5, v6, v7, v8) NLOHMANN_JSON_DOUBLE_PASTE3(func, v1, v2) NLOHMANN_JSON_DOUBLE_PASTE7(func, v3, v4, v5, v6, v7, v8)
#define NLOHMANN_JSON_DOUBLE_PASTE11(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) NLOHMANN_JSON_DOUBLE_PASTE3(func, v1, v2) NLOHMANN_JSON_DOUBLE_PASTE9(func, v3, v4, v5, v6, v7, v8, v9, v10)
#define NLOHMANN_JSON_DOUBLE_PASTE13(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12) NLOHMANN_JSON_DOUBLE_PASTE3(func, v1, v2) NLOHMANN_JSON_DOUBLE_PASTE11(func, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12)
#define NLOHMANN_JSON_DOUBLE_PASTE15(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14) NLOHMANN_JSON_DOUBLE_PASTE3(func, v1, v2) NLOHMANN_JSON_DOUBLE_PASTE13(func, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14)
#define NLOHMANN_JSON_DOUBLE_PASTE17(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) NLOHMANN_JSON_DOUBLE_PASTE3(func, v1, v2) NLOHMANN_JSON_DOUBLE_PASTE15(func, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#define NLOHMANN_JSON_DOUBLE_PASTE19(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18) NLOHMANN_JSON_DOUBLE_PASTE3(func, v1, v2) NLOHMANN_JSON_DOUBLE_PASTE17(func, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18)
#define NLOHMANN_JSON_DOUBLE_PASTE21(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20) NLOHMANN_JSON_DOUBLE_PASTE3(func, v1, v2) NLOHMANN_JSON_DOUBLE_PASTE19(func, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20)
#define NLOHMANN_JSON_DOUBLE_PASTE23(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22) NLOHMANN_JSON_DOUBLE_PASTE3(func, v1, v2) NLOHMANN_JSON_DOUBLE_PASTE21(func, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22)
#define NLOHMANN_JSON_DOUBLE_PASTE25(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24) NLOHMANN_JSON_DOUBLE_PASTE3(func, v1, v2) NLOHMANN_JSON_DOUBLE_PASTE23(func, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24)
#define NLOHMANN_JSON_DOUBLE_PASTE27(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26) NLOHMANN_JSON_DOUBLE_PASTE3(func, v1, v2) NLOHMANN_JSON_DOUBLE_PASTE25(func, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26)
#define NLOHMANN_JSON_DOUBLE_PASTE29(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28) NLOHMANN_JSON_DOUBLE_PASTE3(func, v1, v2) NLOHMANN_JSON_DOUBLE_PASTE27(func, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28)
#define NLOHMANN_JSON_DOUBLE_PASTE31(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30) NLOHMANN_JSON_DOUBLE_PASTE3(func, v1, v2) NLOHMANN_JSON_DOUBLE_PASTE29(func, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30)
#define NLOHMANN_JSON_DOUBLE_PASTE33(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32) NLOHMANN_JSON_DOUBLE_PASTE3(func, v1, v2) NLOHMANN_JSON_DOUBLE_PASTE31(func, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32)
#define NLOHMANN_JSON_DOUBLE_PASTE35(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34) NLOHMANN_JSON_DOUBLE_PASTE3(func, v1, v2) NLOHMANN_JSON_DOUBLE_PASTE33(func, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34)
#define NLOHMANN_JSON_DOUBLE_PASTE37(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36) NLOHMANN_JSON_DOUBLE_PASTE3(func, v1, v2) NLOHMANN_JSON_DOUBLE_PASTE35(func, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36)
#define NLOHMANN_JSON_DOUBLE_PASTE39(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38) NLOHMANN_JSON_DOUBLE_PASTE3(func, v1, v2) NLOHMANN_JSON_DOUBLE_PASTE37(func, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38)
#define NLOHMANN_JSON_DOUBLE_PASTE41(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40) NLOHMANN_JSON_DOUBLE_PASTE3(func, v1, v2) NLOHMANN_JSON_DOUBLE_PASTE39(func, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40)
#define NLOHMANN_JSON_DOUBLE_PASTE43(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42) NLOHMANN_JSON_DOUBLE_PASTE3(func, v1, v2) NLOHMANN_JSON_DOUBLE_PASTE41(func, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42)
#define NLOHMANN_JSON_DOUBLE_PASTE45(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44) NLOHMANN_JSON_DOUBLE_PASTE3(func, v1, v2) NLOHMANN_JSON_DOUBLE_PASTE43(func, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44)
#define NLOHMANN_JSON_DOUBLE_PASTE47(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46) NLOHMANN_JSON_DOUBLE_PASTE3(func, v1, v2) NLOHMANN_JSON_DOUBLE_PASTE45(func, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46)
#define NLOHMANN_JSON_DOUBLE_PASTE49(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48) NLOHMANN_JSON_DOUBLE_PASTE3(func, v1, v2) NLOHMANN_JSON_DOUBLE_PASTE47(func, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48)
#define NLOHMANN_JSON_DOUBLE_PASTE51(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50) NLOHMANN_JSON_DOUBLE_PASTE3(func, v1, v2) NLOHMANN_JSON_DOUBLE_PASTE49(func, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50)
#define NLOHMANN_JSON_DOUBLE_PASTE53(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52) NLOHMANN_JSON_DOUBLE_PASTE3(func, v1, v2) NLOHMANN_JSON_DOUBLE_PASTE51(func, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52)
#define NLOHMANN_JSON_DOUBLE_PASTE55(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54) NLOHMANN_JSON_DOUBLE_PASTE3(func, v1, v2) NLOHMANN_JSON_DOUBLE_PASTE53(func, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54)
#define NLOHMANN_JSON_DOUBLE_PASTE57(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56) NLOHMANN_JSON_DOUBLE_PASTE3(func, v1, v2) NLOHMANN_JSON_DOUBLE_PASTE55(func, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56)
#define NLOHMANN_JSON_DOUBLE_PASTE59(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58) NLOHMANN_JSON_DOUBLE_PASTE3(func, v1, v2) NLOHMANN_JSON_DOUBLE_PASTE57(func, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58)
#define NLOHMANN_JSON_DOUBLE_PASTE61(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60) NLOHMANN_JSON_DOUBLE_PASTE3(func, v1, v2) NLOHMANN_JSON_DOUBLE_PASTE59(func, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60)
#define NLOHMANN_JSON_DOUBLE_PASTE63(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62) NLOHMANN_JSON_DOUBLE_PASTE3(func, v1, v2) NLOHMANN_JSON_DOUBLE_PASTE61(func, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62)
#define NLOHMANN_JSON_TO(v1) nlohmann_json_j[#v1] = nlohmann_json_t.v1;
#define NLOHMANN_JSON_FROM(v1) nlohmann_json_j.at(#v1).get_to(nlohmann_json_t.v1);
#define NLOHMANN_JSON_FROM_WITH_DEFAULT(v1) nlohmann_json_t.v1 = !nlohmann_json_j.is_null() ? nlohmann_json_j.value(#v1, nlohmann_json_default_obj.v1) : nlohmann_json_default_obj.v1;
#define NLOHMANN_JSON_TO_WITH_NAME(v1, v2) nlohmann_json_j[v1] = nlohmann_json_t.v2;
#define NLOHMANN_JSON_FROM_WITH_NAME(v1, v2) nlohmann_json_j.at(v1).get_to(nlohmann_json_t.v2);
#define NLOHMANN_JSON_FROM_WITH_DEFAULT_WITH_NAME(v1, v2) nlohmann_json_t.v2 = !nlohmann_json_j.is_null() ? nlohmann_json_j.value(v1, nlohmann_json_default_obj.v2) : nlohmann_json_default_obj.v2;
#define NLOHMANN_JSON_BASIC_TYPE_TEMPLATE(...) template<typename BasicJsonType, nlohmann::detail::enable_if_t<nlohmann::detail::is_basic_json<BasicJsonType>::value, int> = 0> __VA_ARGS__
#define NLOHMANN_JSON_TYPE_BODY(Prefix, ...) NLOHMANN_JSON_EXPAND(NLOHMANN_JSON_GET_MACRO(__VA_ARGS__, \
        Prefix ## MEMBERS, Prefix ## MEMBERS, Prefix ## MEMBERS, Prefix ## MEMBERS, Prefix ## MEMBERS, Prefix ## MEMBERS, Prefix ## MEMBERS, Prefix ## MEMBERS, \
        Prefix ## MEMBERS, Prefix ## MEMBERS, Prefix ## MEMBERS, Prefix ## MEMBERS, Prefix ## MEMBERS, Prefix ## MEMBERS, Prefix ## MEMBERS, Prefix ## MEMBERS, \
        Prefix ## MEMBERS, Prefix ## MEMBERS, Prefix ## MEMBERS, Prefix ## MEMBERS, Prefix ## MEMBERS, Prefix ## MEMBERS, Prefix ## MEMBERS, Prefix ## MEMBERS, \
        Prefix ## MEMBERS, Prefix ## MEMBERS, Prefix ## MEMBERS, Prefix ## MEMBERS, Prefix ## MEMBERS, Prefix ## MEMBERS, Prefix ## MEMBERS, Prefix ## MEMBERS, \
        Prefix ## MEMBERS, Prefix ## MEMBERS, Prefix ## MEMBERS, Prefix ## MEMBERS, Prefix ## MEMBERS, Prefix ## MEMBERS, Prefix ## MEMBERS, Prefix ## MEMBERS, \
        Prefix ## MEMBERS, Prefix ## MEMBERS, Prefix ## MEMBERS, Prefix ## MEMBERS, Prefix ## MEMBERS, Prefix ## MEMBERS, Prefix ## MEMBERS, Prefix ## MEMBERS, \
        Prefix ## MEMBERS, Prefix ## MEMBERS, Prefix ## MEMBERS, Prefix ## MEMBERS, Prefix ## MEMBERS, Prefix ## MEMBERS, Prefix ## MEMBERS, Prefix ## MEMBERS, \
        Prefix ## MEMBERS, Prefix ## MEMBERS, Prefix ## MEMBERS, Prefix ## MEMBERS, Prefix ## MEMBERS, Prefix ## MEMBERS, Prefix ## MEMBERS, Prefix ## EMPTY, \
        NLOHMANN_JSON_TYPE_BODY_SENTINEL))
#define NLOHMANN_JSON_DERIVED_TYPE_BODY_(Prefix, Type, ...) NLOHMANN_JSON_TYPE_BODY(Prefix, __VA_ARGS__)
#define NLOHMANN_JSON_DERIVED_TYPE_BODY(Prefix, ...) NLOHMANN_JSON_EXPAND(NLOHMANN_JSON_DERIVED_TYPE_BODY_(Prefix, __VA_ARGS__))
#define NLOHMANN_JSON_DEFINE_TYPE_INTRUSIVE_MEMBERS(Type, ...)  \
    NLOHMANN_JSON_BASIC_TYPE_TEMPLATE(friend void to_json(BasicJsonType& nlohmann_json_j, const Type& nlohmann_json_t) { NLOHMANN_JSON_EXPAND(NLOHMANN_JSON_PASTE(NLOHMANN_JSON_TO, __VA_ARGS__)) }) \
    NLOHMANN_JSON_BASIC_TYPE_TEMPLATE(friend void from_json(const BasicJsonType& nlohmann_json_j, Type& nlohmann_json_t) { NLOHMANN_JSON_EXPAND(NLOHMANN_JSON_PASTE(NLOHMANN_JSON_FROM, __VA_ARGS__)) })
#define NLOHMANN_JSON_DEFINE_TYPE_INTRUSIVE_EMPTY(Type)  \
    NLOHMANN_JSON_BASIC_TYPE_TEMPLATE(friend void to_json(BasicJsonType& nlohmann_json_j, const Type&) { nlohmann_json_j = BasicJsonType::object(); }) \
     \
    NLOHMANN_JSON_BASIC_TYPE_TEMPLATE(friend void from_json(const BasicJsonType&, Type&) noexcept { })
#define NLOHMANN_DEFINE_TYPE_INTRUSIVE(...) NLOHMANN_JSON_EXPAND(NLOHMANN_JSON_TYPE_BODY(NLOHMANN_JSON_DEFINE_TYPE_INTRUSIVE_, __VA_ARGS__)(__VA_ARGS__))
#define NLOHMANN_DEFINE_TYPE_INTRUSIVE_WITH_NAMES(Type, ...)  \
    NLOHMANN_JSON_BASIC_TYPE_TEMPLATE(friend void to_json(BasicJsonType& nlohmann_json_j, const Type& nlohmann_json_t) { NLOHMANN_JSON_EXPAND(NLOHMANN_JSON_DOUBLE_PASTE(NLOHMANN_JSON_TO_WITH_NAME, __VA_ARGS__)) }) \
    NLOHMANN_JSON_BASIC_TYPE_TEMPLATE(friend void from_json(const BasicJsonType& nlohmann_json_j, Type& nlohmann_json_t) { NLOHMANN_JSON_EXPAND(NLOHMANN_JSON_DOUBLE_PASTE(NLOHMANN_JSON_FROM_WITH_NAME, __VA_ARGS__)) })
#define NLOHMANN_JSON_DEFINE_TYPE_INTRUSIVE_WITH_DEFAULT_MEMBERS(Type, ...)  \
    NLOHMANN_JSON_BASIC_TYPE_TEMPLATE(friend void to_json(BasicJsonType& nlohmann_json_j, const Type& nlohmann_json_t) { NLOHMANN_JSON_EXPAND(NLOHMANN_JSON_PASTE(NLOHMANN_JSON_TO, __VA_ARGS__)) }) \
    NLOHMANN_JSON_BASIC_TYPE_TEMPLATE(friend void from_json(const BasicJsonType& nlohmann_json_j, Type& nlohmann_json_t) { const Type nlohmann_json_default_obj{}; NLOHMANN_JSON_EXPAND(NLOHMANN_JSON_PASTE(NLOHMANN_JSON_FROM_WITH_DEFAULT, __VA_ARGS__)) })
#define NLOHMANN_JSON_DEFINE_TYPE_INTRUSIVE_WITH_DEFAULT_EMPTY(Type) NLOHMANN_JSON_DEFINE_TYPE_INTRUSIVE_EMPTY(Type)
#define NLOHMANN_DEFINE_TYPE_INTRUSIVE_WITH_DEFAULT(...) NLOHMANN_JSON_EXPAND(NLOHMANN_JSON_TYPE_BODY(NLOHMANN_JSON_DEFINE_TYPE_INTRUSIVE_WITH_DEFAULT_, __VA_ARGS__)(__VA_ARGS__))
#define NLOHMANN_DEFINE_TYPE_INTRUSIVE_WITH_DEFAULT_WITH_NAMES(Type, ...)  \
    NLOHMANN_JSON_BASIC_TYPE_TEMPLATE(friend void to_json(BasicJsonType& nlohmann_json_j, const Type& nlohmann_json_t) { NLOHMANN_JSON_EXPAND(NLOHMANN_JSON_DOUBLE_PASTE(NLOHMANN_JSON_TO_WITH_NAME, __VA_ARGS__)) }) \
    NLOHMANN_JSON_BASIC_TYPE_TEMPLATE(friend void from_json(const BasicJsonType& nlohmann_json_j, Type& nlohmann_json_t) { const Type nlohmann_json_default_obj{}; NLOHMANN_JSON_EXPAND(NLOHMANN_JSON_DOUBLE_PASTE(NLOHMANN_JSON_FROM_WITH_DEFAULT_WITH_NAME, __VA_ARGS__)) })
#define NLOHMANN_JSON_DEFINE_TYPE_INTRUSIVE_ONLY_SERIALIZE_MEMBERS(Type, ...)  \
    NLOHMANN_JSON_BASIC_TYPE_TEMPLATE(friend void to_json(BasicJsonType& nlohmann_json_j, const Type& nlohmann_json_t) { NLOHMANN_JSON_EXPAND(NLOHMANN_JSON_PASTE(NLOHMANN_JSON_TO, __VA_ARGS__)) })
#define NLOHMANN_JSON_DEFINE_TYPE_INTRUSIVE_ONLY_SERIALIZE_EMPTY(Type)  \
    NLOHMANN_JSON_BASIC_TYPE_TEMPLATE(friend void to_json(BasicJsonType& nlohmann_json_j, const Type&) { nlohmann_json_j = BasicJsonType::object(); })
#define NLOHMANN_DEFINE_TYPE_INTRUSIVE_ONLY_SERIALIZE(...) NLOHMANN_JSON_EXPAND(NLOHMANN_JSON_TYPE_BODY(NLOHMANN_JSON_DEFINE_TYPE_INTRUSIVE_ONLY_SERIALIZE_, __VA_ARGS__)(__VA_ARGS__))
#define NLOHMANN_DEFINE_TYPE_INTRUSIVE_ONLY_SERIALIZE_WITH_NAMES(Type, ...)  \
    NLOHMANN_JSON_BASIC_TYPE_TEMPLATE(friend void to_json(BasicJsonType& nlohmann_json_j, const Type& nlohmann_json_t) { NLOHMANN_JSON_EXPAND(NLOHMANN_JSON_DOUBLE_PASTE(NLOHMANN_JSON_TO_WITH_NAME, __VA_ARGS__)) })
#define NLOHMANN_JSON_DEFINE_TYPE_NON_INTRUSIVE_MEMBERS(Type, ...)  \
    NLOHMANN_JSON_BASIC_TYPE_TEMPLATE(void to_json(BasicJsonType& nlohmann_json_j, const Type& nlohmann_json_t) { NLOHMANN_JSON_EXPAND(NLOHMANN_JSON_PASTE(NLOHMANN_JSON_TO, __VA_ARGS__)) }) \
    NLOHMANN_JSON_BASIC_TYPE_TEMPLATE(void from_json(const BasicJsonType& nlohmann_json_j, Type& nlohmann_json_t) { NLOHMANN_JSON_EXPAND(NLOHMANN_JSON_PASTE(NLOHMANN_JSON_FROM, __VA_ARGS__)) })
#define NLOHMANN_JSON_DEFINE_TYPE_NON_INTRUSIVE_EMPTY(Type)  \
    NLOHMANN_JSON_BASIC_TYPE_TEMPLATE(void to_json(BasicJsonType& nlohmann_json_j, const Type&) { nlohmann_json_j = BasicJsonType::object(); }) \
     \
    NLOHMANN_JSON_BASIC_TYPE_TEMPLATE(void from_json(const BasicJsonType&, Type&) noexcept { })
#define NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(...) NLOHMANN_JSON_EXPAND(NLOHMANN_JSON_TYPE_BODY(NLOHMANN_JSON_DEFINE_TYPE_NON_INTRUSIVE_, __VA_ARGS__)(__VA_ARGS__))
#define NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE_WITH_NAMES(Type, ...)  \
    NLOHMANN_JSON_BASIC_TYPE_TEMPLATE(void to_json(BasicJsonType& nlohmann_json_j, const Type& nlohmann_json_t) { NLOHMANN_JSON_EXPAND(NLOHMANN_JSON_DOUBLE_PASTE(NLOHMANN_JSON_TO_WITH_NAME, __VA_ARGS__)) }) \
    NLOHMANN_JSON_BASIC_TYPE_TEMPLATE(void from_json(const BasicJsonType& nlohmann_json_j, Type& nlohmann_json_t) { NLOHMANN_JSON_EXPAND(NLOHMANN_JSON_DOUBLE_PASTE(NLOHMANN_JSON_FROM_WITH_NAME, __VA_ARGS__)) })
#define NLOHMANN_JSON_DEFINE_TYPE_NON_INTRUSIVE_WITH_DEFAULT_MEMBERS(Type, ...)  \
    NLOHMANN_JSON_BASIC_TYPE_TEMPLATE(void to_json(BasicJsonType& nlohmann_json_j, const Type& nlohmann_json_t) { NLOHMANN_JSON_EXPAND(NLOHMANN_JSON_PASTE(NLOHMANN_JSON_TO, __VA_ARGS__)) }) \
    NLOHMANN_JSON_BASIC_TYPE_TEMPLATE(void from_json(const BasicJsonType& nlohmann_json_j, Type& nlohmann_json_t) { const Type nlohmann_json_default_obj{}; NLOHMANN_JSON_EXPAND(NLOHMANN_JSON_PASTE(NLOHMANN_JSON_FROM_WITH_DEFAULT, __VA_ARGS__)) })
#define NLOHMANN_JSON_DEFINE_TYPE_NON_INTRUSIVE_WITH_DEFAULT_EMPTY(Type) NLOHMANN_JSON_DEFINE_TYPE_NON_INTRUSIVE_EMPTY(Type)
#define NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE_WITH_DEFAULT(...) NLOHMANN_JSON_EXPAND(NLOHMANN_JSON_TYPE_BODY(NLOHMANN_JSON_DEFINE_TYPE_NON_INTRUSIVE_WITH_DEFAULT_, __VA_ARGS__)(__VA_ARGS__))
#define NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE_WITH_DEFAULT_WITH_NAMES(Type, ...)  \
    NLOHMANN_JSON_BASIC_TYPE_TEMPLATE(void to_json(BasicJsonType& nlohmann_json_j, const Type& nlohmann_json_t) { NLOHMANN_JSON_EXPAND(NLOHMANN_JSON_DOUBLE_PASTE(NLOHMANN_JSON_TO_WITH_NAME, __VA_ARGS__)) }) \
    NLOHMANN_JSON_BASIC_TYPE_TEMPLATE(void from_json(const BasicJsonType& nlohmann_json_j, Type& nlohmann_json_t) { const Type nlohmann_json_default_obj{}; NLOHMANN_JSON_EXPAND(NLOHMANN_JSON_DOUBLE_PASTE(NLOHMANN_JSON_FROM_WITH_DEFAULT_WITH_NAME, __VA_ARGS__)) })
#define NLOHMANN_JSON_DEFINE_TYPE_NON_INTRUSIVE_ONLY_SERIALIZE_MEMBERS(Type, ...)  \
    NLOHMANN_JSON_BASIC_TYPE_TEMPLATE(void to_json(BasicJsonType& nlohmann_json_j, const Type& nlohmann_json_t) { NLOHMANN_JSON_EXPAND(NLOHMANN_JSON_PASTE(NLOHMANN_JSON_TO, __VA_ARGS__)) })
#define NLOHMANN_JSON_DEFINE_TYPE_NON_INTRUSIVE_ONLY_SERIALIZE_EMPTY(Type)  \
    NLOHMANN_JSON_BASIC_TYPE_TEMPLATE(void to_json(BasicJsonType& nlohmann_json_j, const Type&) { nlohmann_json_j = BasicJsonType::object(); })
#define NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE_ONLY_SERIALIZE(...) NLOHMANN_JSON_EXPAND(NLOHMANN_JSON_TYPE_BODY(NLOHMANN_JSON_DEFINE_TYPE_NON_INTRUSIVE_ONLY_SERIALIZE_, __VA_ARGS__)(__VA_ARGS__))
#define NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE_ONLY_SERIALIZE_WITH_NAMES(Type, ...)  \
    NLOHMANN_JSON_BASIC_TYPE_TEMPLATE(void to_json(BasicJsonType& nlohmann_json_j, const Type& nlohmann_json_t) { NLOHMANN_JSON_EXPAND(NLOHMANN_JSON_DOUBLE_PASTE(NLOHMANN_JSON_TO_WITH_NAME, __VA_ARGS__)) })
#define NLOHMANN_JSON_DEFINE_DERIVED_TYPE_INTRUSIVE_MEMBERS(Type, BaseType, ...)  \
    NLOHMANN_JSON_BASIC_TYPE_TEMPLATE(friend void to_json(BasicJsonType& nlohmann_json_j, const Type& nlohmann_json_t) { nlohmann::to_json(nlohmann_json_j, static_cast<const BaseType &>(nlohmann_json_t)); NLOHMANN_JSON_EXPAND(NLOHMANN_JSON_PASTE(NLOHMANN_JSON_TO, __VA_ARGS__)) }) \
    NLOHMANN_JSON_BASIC_TYPE_TEMPLATE(friend void from_json(const BasicJsonType& nlohmann_json_j, Type& nlohmann_json_t) { nlohmann::from_json(nlohmann_json_j, static_cast<BaseType&>(nlohmann_json_t)); NLOHMANN_JSON_EXPAND(NLOHMANN_JSON_PASTE(NLOHMANN_JSON_FROM, __VA_ARGS__)) })
#define NLOHMANN_JSON_DEFINE_DERIVED_TYPE_INTRUSIVE_EMPTY(Type, BaseType)  \
    NLOHMANN_JSON_BASIC_TYPE_TEMPLATE(friend void to_json(BasicJsonType& nlohmann_json_j, const Type& nlohmann_json_t) { nlohmann::to_json(nlohmann_json_j, static_cast<const BaseType &>(nlohmann_json_t)); }) \
     \
    NLOHMANN_JSON_BASIC_TYPE_TEMPLATE(friend void from_json(const BasicJsonType& nlohmann_json_j, Type& nlohmann_json_t) { nlohmann::from_json(nlohmann_json_j, static_cast<BaseType&>(nlohmann_json_t)); })
#define NLOHMANN_DEFINE_DERIVED_TYPE_INTRUSIVE(...) NLOHMANN_JSON_EXPAND(NLOHMANN_JSON_DERIVED_TYPE_BODY(NLOHMANN_JSON_DEFINE_DERIVED_TYPE_INTRUSIVE_, __VA_ARGS__)(__VA_ARGS__))
#define NLOHMANN_DEFINE_DERIVED_TYPE_INTRUSIVE_WITH_NAMES(Type, BaseType, ...)  \
    NLOHMANN_JSON_BASIC_TYPE_TEMPLATE(friend void to_json(BasicJsonType& nlohmann_json_j, const Type& nlohmann_json_t) { nlohmann::to_json(nlohmann_json_j, static_cast<const BaseType &>(nlohmann_json_t)); NLOHMANN_JSON_EXPAND(NLOHMANN_JSON_DOUBLE_PASTE(NLOHMANN_JSON_TO_WITH_NAME, __VA_ARGS__)) }) \
    NLOHMANN_JSON_BASIC_TYPE_TEMPLATE(friend void from_json(const BasicJsonType& nlohmann_json_j, Type& nlohmann_json_t) { nlohmann::from_json(nlohmann_json_j, static_cast<BaseType&>(nlohmann_json_t)); NLOHMANN_JSON_EXPAND(NLOHMANN_JSON_DOUBLE_PASTE(NLOHMANN_JSON_FROM_WITH_NAME, __VA_ARGS__)) })
#define NLOHMANN_JSON_DEFINE_DERIVED_TYPE_INTRUSIVE_WITH_DEFAULT_MEMBERS(Type, BaseType, ...)  \
    NLOHMANN_JSON_BASIC_TYPE_TEMPLATE(friend void to_json(BasicJsonType& nlohmann_json_j, const Type& nlohmann_json_t) { nlohmann::to_json(nlohmann_json_j, static_cast<const BaseType&>(nlohmann_json_t)); NLOHMANN_JSON_EXPAND(NLOHMANN_JSON_PASTE(NLOHMANN_JSON_TO, __VA_ARGS__)) }) \
    NLOHMANN_JSON_BASIC_TYPE_TEMPLATE(friend void from_json(const BasicJsonType& nlohmann_json_j, Type& nlohmann_json_t) { nlohmann::from_json(nlohmann_json_j, static_cast<BaseType&>(nlohmann_json_t)); const Type nlohmann_json_default_obj{}; NLOHMANN_JSON_EXPAND(NLOHMANN_JSON_PASTE(NLOHMANN_JSON_FROM_WITH_DEFAULT, __VA_ARGS__)) })
#define NLOHMANN_JSON_DEFINE_DERIVED_TYPE_INTRUSIVE_WITH_DEFAULT_EMPTY(Type, BaseType) NLOHMANN_JSON_DEFINE_DERIVED_TYPE_INTRUSIVE_EMPTY(Type, BaseType)
#define NLOHMANN_DEFINE_DERIVED_TYPE_INTRUSIVE_WITH_DEFAULT(...) NLOHMANN_JSON_EXPAND(NLOHMANN_JSON_DERIVED_TYPE_BODY(NLOHMANN_JSON_DEFINE_DERIVED_TYPE_INTRUSIVE_WITH_DEFAULT_, __VA_ARGS__)(__VA_ARGS__))
#define NLOHMANN_DEFINE_DERIVED_TYPE_INTRUSIVE_WITH_DEFAULT_WITH_NAMES(Type, BaseType, ...)  \
    NLOHMANN_JSON_BASIC_TYPE_TEMPLATE(friend void to_json(BasicJsonType& nlohmann_json_j, const Type& nlohmann_json_t) { nlohmann::to_json(nlohmann_json_j, static_cast<const BaseType&>(nlohmann_json_t)); NLOHMANN_JSON_EXPAND(NLOHMANN_JSON_DOUBLE_PASTE(NLOHMANN_JSON_TO_WITH_NAME, __VA_ARGS__)) }) \
    NLOHMANN_JSON_BASIC_TYPE_TEMPLATE(friend void from_json(const BasicJsonType& nlohmann_json_j, Type& nlohmann_json_t) { nlohmann::from_json(nlohmann_json_j, static_cast<BaseType&>(nlohmann_json_t)); const Type nlohmann_json_default_obj{}; NLOHMANN_JSON_EXPAND(NLOHMANN_JSON_DOUBLE_PASTE(NLOHMANN_JSON_FROM_WITH_DEFAULT_WITH_NAME, __VA_ARGS__)) })
#define NLOHMANN_JSON_DEFINE_DERIVED_TYPE_INTRUSIVE_ONLY_SERIALIZE_MEMBERS(Type, BaseType, ...)  \
    NLOHMANN_JSON_BASIC_TYPE_TEMPLATE(friend void to_json(BasicJsonType& nlohmann_json_j, const Type& nlohmann_json_t) { nlohmann::to_json(nlohmann_json_j, static_cast<const BaseType &>(nlohmann_json_t)); NLOHMANN_JSON_EXPAND(NLOHMANN_JSON_PASTE(NLOHMANN_JSON_TO, __VA_ARGS__)) })
#define NLOHMANN_JSON_DEFINE_DERIVED_TYPE_INTRUSIVE_ONLY_SERIALIZE_EMPTY(Type, BaseType)  \
    NLOHMANN_JSON_BASIC_TYPE_TEMPLATE(friend void to_json(BasicJsonType& nlohmann_json_j, const Type& nlohmann_json_t) { nlohmann::to_json(nlohmann_json_j, static_cast<const BaseType &>(nlohmann_json_t)); })
#define NLOHMANN_DEFINE_DERIVED_TYPE_INTRUSIVE_ONLY_SERIALIZE(...) NLOHMANN_JSON_EXPAND(NLOHMANN_JSON_DERIVED_TYPE_BODY(NLOHMANN_JSON_DEFINE_DERIVED_TYPE_INTRUSIVE_ONLY_SERIALIZE_, __VA_ARGS__)(__VA_ARGS__))
#define NLOHMANN_DEFINE_DERIVED_TYPE_INTRUSIVE_ONLY_SERIALIZE_WITH_NAMES(Type, BaseType, ...)  \
    NLOHMANN_JSON_BASIC_TYPE_TEMPLATE(friend void to_json(BasicJsonType& nlohmann_json_j, const Type& nlohmann_json_t) { nlohmann::to_json(nlohmann_json_j, static_cast<const BaseType &>(nlohmann_json_t)); NLOHMANN_JSON_EXPAND(NLOHMANN_JSON_DOUBLE_PASTE(NLOHMANN_JSON_TO_WITH_NAME, __VA_ARGS__)) })
#define NLOHMANN_JSON_DEFINE_DERIVED_TYPE_NON_INTRUSIVE_MEMBERS(Type, BaseType, ...)  \
    NLOHMANN_JSON_BASIC_TYPE_TEMPLATE(void to_json(BasicJsonType& nlohmann_json_j, const Type& nlohmann_json_t) { nlohmann::to_json(nlohmann_json_j, static_cast<const BaseType &>(nlohmann_json_t)); NLOHMANN_JSON_EXPAND(NLOHMANN_JSON_PASTE(NLOHMANN_JSON_TO, __VA_ARGS__)) }) \
    NLOHMANN_JSON_BASIC_TYPE_TEMPLATE(void from_json(const BasicJsonType& nlohmann_json_j, Type& nlohmann_json_t) { nlohmann::from_json(nlohmann_json_j, static_cast<BaseType&>(nlohmann_json_t)); NLOHMANN_JSON_EXPAND(NLOHMANN_JSON_PASTE(NLOHMANN_JSON_FROM, __VA_ARGS__)) })
#define NLOHMANN_JSON_DEFINE_DERIVED_TYPE_NON_INTRUSIVE_EMPTY(Type, BaseType)  \
    NLOHMANN_JSON_BASIC_TYPE_TEMPLATE(void to_json(BasicJsonType& nlohmann_json_j, const Type& nlohmann_json_t) { nlohmann::to_json(nlohmann_json_j, static_cast<const BaseType &>(nlohmann_json_t)); }) \
     \
    NLOHMANN_JSON_BASIC_TYPE_TEMPLATE(void from_json(const BasicJsonType& nlohmann_json_j, Type& nlohmann_json_t) { nlohmann::from_json(nlohmann_json_j, static_cast<BaseType&>(nlohmann_json_t)); })
#define NLOHMANN_DEFINE_DERIVED_TYPE_NON_INTRUSIVE(...) NLOHMANN_JSON_EXPAND(NLOHMANN_JSON_DERIVED_TYPE_BODY(NLOHMANN_JSON_DEFINE_DERIVED_TYPE_NON_INTRUSIVE_, __VA_ARGS__)(__VA_ARGS__))
#define NLOHMANN_DEFINE_DERIVED_TYPE_NON_INTRUSIVE_WITH_NAMES(Type, BaseType, ...)  \
    NLOHMANN_JSON_BASIC_TYPE_TEMPLATE(void to_json(BasicJsonType& nlohmann_json_j, const Type& nlohmann_json_t) { nlohmann::to_json(nlohmann_json_j, static_cast<const BaseType &>(nlohmann_json_t)); NLOHMANN_JSON_EXPAND(NLOHMANN_JSON_DOUBLE_PASTE(NLOHMANN_JSON_TO_WITH_NAME, __VA_ARGS__)) }) \
    NLOHMANN_JSON_BASIC_TYPE_TEMPLATE(void from_json(const BasicJsonType& nlohmann_json_j, Type& nlohmann_json_t) { nlohmann::from_json(nlohmann_json_j, static_cast<BaseType&>(nlohmann_json_t)); NLOHMANN_JSON_EXPAND(NLOHMANN_JSON_DOUBLE_PASTE(NLOHMANN_JSON_FROM_WITH_NAME, __VA_ARGS__)) })
#define NLOHMANN_JSON_DEFINE_DERIVED_TYPE_NON_INTRUSIVE_WITH_DEFAULT_MEMBERS(Type, BaseType, ...)  \
    NLOHMANN_JSON_BASIC_TYPE_TEMPLATE(void to_json(BasicJsonType& nlohmann_json_j, const Type& nlohmann_json_t) { nlohmann::to_json(nlohmann_json_j, static_cast<const BaseType &>(nlohmann_json_t)); NLOHMANN_JSON_EXPAND(NLOHMANN_JSON_PASTE(NLOHMANN_JSON_TO, __VA_ARGS__)) }) \
    NLOHMANN_JSON_BASIC_TYPE_TEMPLATE(void from_json(const BasicJsonType& nlohmann_json_j, Type& nlohmann_json_t) { nlohmann::from_json(nlohmann_json_j, static_cast<BaseType&>(nlohmann_json_t)); const Type nlohmann_json_default_obj{}; NLOHMANN_JSON_EXPAND(NLOHMANN_JSON_PASTE(NLOHMANN_JSON_FROM_WITH_DEFAULT, __VA_ARGS__)) })
#define NLOHMANN_JSON_DEFINE_DERIVED_TYPE_NON_INTRUSIVE_WITH_DEFAULT_EMPTY(Type, BaseType) NLOHMANN_JSON_DEFINE_DERIVED_TYPE_NON_INTRUSIVE_EMPTY(Type, BaseType)
#define NLOHMANN_DEFINE_DERIVED_TYPE_NON_INTRUSIVE_WITH_DEFAULT(...) NLOHMANN_JSON_EXPAND(NLOHMANN_JSON_DERIVED_TYPE_BODY(NLOHMANN_JSON_DEFINE_DERIVED_TYPE_NON_INTRUSIVE_WITH_DEFAULT_, __VA_ARGS__)(__VA_ARGS__))
#define NLOHMANN_DEFINE_DERIVED_TYPE_NON_INTRUSIVE_WITH_DEFAULT_WITH_NAMES(Type, BaseType, ...)  \
    NLOHMANN_JSON_BASIC_TYPE_TEMPLATE(void to_json(BasicJsonType& nlohmann_json_j, const Type& nlohmann_json_t) { nlohmann::to_json(nlohmann_json_j, static_cast<const BaseType &>(nlohmann_json_t)); NLOHMANN_JSON_EXPAND(NLOHMANN_JSON_DOUBLE_PASTE(NLOHMANN_JSON_TO_WITH_NAME, __VA_ARGS__)) }) \
    NLOHMANN_JSON_BASIC_TYPE_TEMPLATE(void from_json(const BasicJsonType& nlohmann_json_j, Type& nlohmann_json_t) { nlohmann::from_json(nlohmann_json_j, static_cast<BaseType&>(nlohmann_json_t)); const Type nlohmann_json_default_obj{}; NLOHMANN_JSON_EXPAND(NLOHMANN_JSON_DOUBLE_PASTE(NLOHMANN_JSON_FROM_WITH_DEFAULT_WITH_NAME, __VA_ARGS__)) })
#define NLOHMANN_JSON_DEFINE_DERIVED_TYPE_NON_INTRUSIVE_ONLY_SERIALIZE_MEMBERS(Type, BaseType, ...)  \
    NLOHMANN_JSON_BASIC_TYPE_TEMPLATE(void to_json(BasicJsonType& nlohmann_json_j, const Type& nlohmann_json_t) { nlohmann::to_json(nlohmann_json_j, static_cast<const BaseType &>(nlohmann_json_t)); NLOHMANN_JSON_EXPAND(NLOHMANN_JSON_PASTE(NLOHMANN_JSON_TO, __VA_ARGS__)) })
#define NLOHMANN_JSON_DEFINE_DERIVED_TYPE_NON_INTRUSIVE_ONLY_SERIALIZE_EMPTY(Type, BaseType)  \
    NLOHMANN_JSON_BASIC_TYPE_TEMPLATE(void to_json(BasicJsonType& nlohmann_json_j, const Type& nlohmann_json_t) { nlohmann::to_json(nlohmann_json_j, static_cast<const BaseType &>(nlohmann_json_t)); })
#define NLOHMANN_DEFINE_DERIVED_TYPE_NON_INTRUSIVE_ONLY_SERIALIZE(...) NLOHMANN_JSON_EXPAND(NLOHMANN_JSON_DERIVED_TYPE_BODY(NLOHMANN_JSON_DEFINE_DERIVED_TYPE_NON_INTRUSIVE_ONLY_SERIALIZE_, __VA_ARGS__)(__VA_ARGS__))
#define NLOHMANN_DEFINE_DERIVED_TYPE_NON_INTRUSIVE_ONLY_SERIALIZE_WITH_NAMES(Type, BaseType, ...)  \
    NLOHMANN_JSON_BASIC_TYPE_TEMPLATE(void to_json(BasicJsonType& nlohmann_json_j, const Type& nlohmann_json_t) { nlohmann::to_json(nlohmann_json_j, static_cast<const BaseType &>(nlohmann_json_t)); NLOHMANN_JSON_EXPAND(NLOHMANN_JSON_DOUBLE_PASTE(NLOHMANN_JSON_TO_WITH_NAME, __VA_ARGS__)) })
#define NLOHMANN_CAN_CALL_STD_FUNC_IMPL(std_name)                                 \
    namespace detail {                                                            \
    using std::std_name;                                                          \
    \
    template<typename... T>                                                       \
    using result_of_##std_name = decltype(std_name(std::declval<T>()...));        \
    }                                                                             \
    \
    namespace detail2 {                                                           \
    struct std_name##_tag                                                         \
    {                                                                             \
    };                                                                            \
    \
    template<typename... T>                                                       \
    std_name##_tag std_name(T&&...);                                              \
    \
    template<typename... T>                                                       \
    using result_of_##std_name = decltype(std_name(std::declval<T>()...));        \
    \
    template<typename... T>                                                       \
    struct would_call_std_##std_name                                              \
    {                                                                             \
        static constexpr auto const value = ::nlohmann::detail::                  \
                                            is_detected_exact<std_name##_tag, result_of_##std_name, T...>::value; \
    };                                                                            \
    }  \
    \
    template<typename... T>                                                       \
    struct would_call_std_##std_name : detail2::would_call_std_##std_name<T...>   \
    {                                                                             \
    }
#ifndef JSON_USE_IMPLICIT_CONVERSIONS
    #define JSON_USE_IMPLICIT_CONVERSIONS 1
#endif
#if JSON_USE_IMPLICIT_CONVERSIONS
    #define JSON_EXPLICIT
#else
    #define JSON_EXPLICIT explicit
#endif
#ifndef JSON_DISABLE_ENUM_SERIALIZATION
    #define JSON_DISABLE_ENUM_SERIALIZATION 0
#endif
#ifndef JSON_DISABLE_TUPLE_REFERENCE_CONVERSION
    #define JSON_DISABLE_TUPLE_REFERENCE_CONVERSION 0
#endif
#if JSON_HAS_THREE_WAY_COMPARISON
    #include <compare> 
#endif
NLOHMANN_JSON_NAMESPACE_BEGIN
namespace detail
{
enum class value_t : std::uint8_t
{
    null,             
    object,           
    array,            
    string,           
    boolean,          
    number_integer,   
    number_unsigned,  
    number_float,     
    binary,           
    discarded         
};
#if JSON_HAS_THREE_WAY_COMPARISON
    inline std::partial_ordering operator<=>(const value_t lhs, const value_t rhs) noexcept 
#else
    inline bool operator<(const value_t lhs, const value_t rhs) noexcept
#endif
{
    static constexpr std::array<std::uint8_t, 9> order = {{
            0 , 3 , 4 , 5 ,
            1 , 2 , 2 , 2 ,
            6 
        }
    };
    const auto l_index = static_cast<std::size_t>(lhs);
    const auto r_index = static_cast<std::size_t>(rhs);
#if JSON_HAS_THREE_WAY_COMPARISON
    if (l_index < order.size() && r_index < order.size())
    {
        return order[l_index] <=> order[r_index]; 
    }
    return std::partial_ordering::unordered;
#else
    return l_index < order.size() && r_index < order.size() && order[l_index] < order[r_index];
#endif
}
#if JSON_HAS_THREE_WAY_COMPARISON && defined(__GNUC__)
inline bool operator<(const value_t lhs, const value_t rhs) noexcept
{
    return std::is_lt(lhs <=> rhs); 
}
#endif
template<typename IntegerType, typename FloatType>
FloatType compare_integer_with_float(const IntegerType i, const FloatType f) noexcept
{
    const auto ordered = [](int c) noexcept
    {
        return static_cast<FloatType>(c);
    };
    if (std::isnan(f))
    {
        return f;
    }
    const FloatType bound = std::ldexp(static_cast<FloatType>(1), std::numeric_limits<IntegerType>::digits);
    if (f >= bound)
    {
        return ordered(-1);
    }
    if (std::is_signed<IntegerType>::value ? (f < -bound) : (f < static_cast<FloatType>(0)))
    {
        return ordered(1);
    }
    const FloatType truncated = std::trunc(f);
    const auto as_integer = static_cast<IntegerType>(truncated);
    if (i != as_integer)
    {
        return ordered(i < as_integer ? -1 : 1);
    }
    const FloatType fraction = f - truncated;
    if (fraction > static_cast<FloatType>(0))
    {
        return ordered(-1);
    }
    if (fraction < static_cast<FloatType>(0))
    {
        return ordered(1);
    }
    return ordered(0);
}
}  
NLOHMANN_JSON_NAMESPACE_END
#include <cstddef> 
NLOHMANN_JSON_NAMESPACE_BEGIN
namespace detail
{
template<typename StringType>
inline StringType escape(const StringType& s)
{
    auto next_special = [&s](std::size_t from)
    {
        const auto tilde = s.find_first_of('~', from);
        const auto slash = s.find_first_of('/', from);
        return tilde < slash ? tilde : slash; 
    };
    auto pos = next_special(0);
    if (pos == StringType::npos)
    {
        return s;
    }
    StringType result;
    result.reserve(s.size() + 2);
    std::size_t run = 0;
    while (pos != StringType::npos)
    {
        result.append(s.data() + run, pos - run);
        result.append(s[pos] == '~' ? "~0" : "~1", 2);
        run = pos + 1;
        pos = next_special(run);
    }
    result.append(s.data() + run, s.size() - run);
    return result;
}
template<typename StringType>
inline void unescape(StringType& s)
{
    auto pos = s.find_first_of('~', 0);
    if (pos == StringType::npos)
    {
        return;
    }
    StringType result;
    result.reserve(s.size());
    std::size_t run = 0;
    while (pos != StringType::npos)
    {
        result.append(s.data() + run, pos - run);
        const auto next = pos + 1;
        if (next < s.size() && (s[next] == '0' || s[next] == '1'))
        {
            result.append(s[next] == '0' ? "~" : "/", 1);
            run = pos + 2;
        }
        else
        {
            result.append("~", 1);
            run = pos + 1;
        }
        pos = s.find_first_of('~', run);
    }
    result.append(s.data() + run, s.size() - run);
    s = result;
}
}  
NLOHMANN_JSON_NAMESPACE_END
#include <cstddef> 
NLOHMANN_JSON_NAMESPACE_BEGIN
namespace detail
{
struct position_t
{
    std::size_t chars_read_total = 0;
    std::size_t chars_read_current_line = 0;
    std::size_t lines_read = 0;
    constexpr operator size_t() const
    {
        return chars_read_total;
    }
};
}  
NLOHMANN_JSON_NAMESPACE_END
#include <cstddef> 
#include <type_traits> 
#include <utility> 
NLOHMANN_JSON_NAMESPACE_BEGIN
namespace detail
{
template<typename T>
using uncvref_t = typename std::remove_cv<typename std::remove_reference<T>::type>::type;
#ifdef JSON_HAS_CPP_14
using std::enable_if_t;
using std::index_sequence;
using std::make_index_sequence;
using std::index_sequence_for;
#else
template<bool B, typename T = void>
using enable_if_t = typename std::enable_if<B, T>::type;
template <typename T, T... Ints>
struct integer_sequence
{
    using value_type = T;
    static constexpr std::size_t size() noexcept
    {
        return sizeof...(Ints);
    }
};
template <size_t... Ints>
using index_sequence = integer_sequence<size_t, Ints...>;
namespace utility_internal
{
template <typename Seq, size_t SeqSize, size_t Rem>
struct Extend;
template <typename T, T... Ints, size_t SeqSize>
struct Extend<integer_sequence<T, Ints...>, SeqSize, 0>
{
    using type = integer_sequence < T, Ints..., (Ints + SeqSize)... >;
};
template <typename T, T... Ints, size_t SeqSize>
struct Extend<integer_sequence<T, Ints...>, SeqSize, 1>
{
    using type = integer_sequence < T, Ints..., (Ints + SeqSize)..., 2 * SeqSize >;
};
template <typename T, size_t N>
struct Gen
{
    using type =
        typename Extend < typename Gen < T, N / 2 >::type, N / 2, N % 2 >::type;
};
template <typename T>
struct Gen<T, 0>
{
    using type = integer_sequence<T>;
};
}  
template <typename T, T N>
using make_integer_sequence = typename utility_internal::Gen<T, N>::type;
template <size_t N>
using make_index_sequence = make_integer_sequence<size_t, N>;
template <typename... Ts>
using index_sequence_for = make_index_sequence<sizeof...(Ts)>;
#endif
template<unsigned N> struct priority_tag : priority_tag < N - 1 > {};
template<> struct priority_tag<0> {};
template<typename T>
struct static_const
{
    static JSON_INLINE_VARIABLE constexpr T value{};
};
#ifndef JSON_HAS_CPP_17
    template<typename T>
    constexpr T static_const<T>::value;
#endif
}  
NLOHMANN_JSON_NAMESPACE_END
#include <limits> 
#include <string> 
#include <tuple> 
#include <type_traits> 
#include <utility> 
#include <vector> 
#if defined(__cpp_lib_byte) && __cpp_lib_byte >= 201603L
    #include <cstddef> 
#endif
#include <iterator> 
NLOHMANN_JSON_NAMESPACE_BEGIN
namespace detail
{
template<typename It, typename = void>
struct iterator_types {};
template<typename It>
struct iterator_types <
    It,
    void_t<typename It::difference_type, typename It::value_type, typename It::pointer,
    typename It::reference, typename It::iterator_category >>
{
    using difference_type = typename It::difference_type;
    using value_type = typename It::value_type;
    using pointer = typename It::pointer;
    using reference = typename It::reference;
    using iterator_category = typename It::iterator_category;
};
template<typename T, typename = void>
struct iterator_traits
{
};
template<typename T>
struct iterator_traits < T, enable_if_t < !std::is_pointer<T>::value >>
    : iterator_types<T>
{
};
template<typename T>
struct iterator_traits<T*, enable_if_t<std::is_object<T>::value>>
{
    using iterator_category = std::random_access_iterator_tag;
    using value_type = T;
    using difference_type = ptrdiff_t;
    using pointer = T*;
    using reference = T&;
};
}  
NLOHMANN_JSON_NAMESPACE_END
#ifdef JSON_HAS_CPP_17
    #include <optional> 
#endif
NLOHMANN_JSON_NAMESPACE_BEGIN
NLOHMANN_CAN_CALL_STD_FUNC_IMPL(begin);
NLOHMANN_JSON_NAMESPACE_END
NLOHMANN_JSON_NAMESPACE_BEGIN
NLOHMANN_CAN_CALL_STD_FUNC_IMPL(end);
NLOHMANN_JSON_NAMESPACE_END
#ifndef INCLUDE_NLOHMANN_JSON_FWD_HPP_
    #define INCLUDE_NLOHMANN_JSON_FWD_HPP_
    #include <cstdint> 
    #include <map> 
    #include <string> 
    #include <vector> 
    NLOHMANN_JSON_NAMESPACE_BEGIN
    template<typename T = void, typename SFINAE = void>
    struct adl_serializer; 
    template<template<typename U, typename V, typename... Args> class ObjectType =
    std::map,
    template<typename U, typename... Args> class ArrayType = std::vector,
    class StringType = std::string, class BooleanType = bool,
    class NumberIntegerType = std::int64_t,
    class NumberUnsignedType = std::uint64_t,
    class NumberFloatType = double,
    template<typename U> class AllocatorType = std::allocator,
    template<typename T, typename SFINAE = void> class JSONSerializer =
    adl_serializer,
    class BinaryType = std::vector<std::uint8_t>, 
    class CustomBaseClass = void>
    class basic_json; 
    template<typename RefStringType>
    class json_pointer; 
    using json = basic_json<>;
    template<class Key, class T, class IgnoredLess, class Allocator>
    struct ordered_map; 
    using ordered_json = basic_json<nlohmann::ordered_map>;
    NLOHMANN_JSON_NAMESPACE_END
#endif  
NLOHMANN_JSON_NAMESPACE_BEGIN
namespace detail
{
template<typename> struct is_basic_json : std::false_type {};
NLOHMANN_BASIC_JSON_TPL_DECLARATION
struct is_basic_json<NLOHMANN_BASIC_JSON_TPL> : std::true_type {};
template<typename BasicJsonContext>
struct is_basic_json_context :
    std::integral_constant < bool,
    is_basic_json<typename std::remove_cv<typename std::remove_pointer<BasicJsonContext>::type>::type>::value
    || std::is_same<BasicJsonContext, std::nullptr_t>::value >
{};
template<typename>
class json_ref;
template<typename>
struct is_json_ref : std::false_type {};
template<typename T>
struct is_json_ref<json_ref<T>> : std::true_type {};
template<typename T>
using mapped_type_t = typename T::mapped_type;
template<typename T>
using key_type_t = typename T::key_type;
template<typename T>
using value_type_t = typename T::value_type;
template<typename T>
using difference_type_t = typename T::difference_type;
template<typename T>
using pointer_t = typename T::pointer;
template<typename T>
using reference_t = typename T::reference;
template<typename T>
using iterator_category_t = typename T::iterator_category;
template<typename T, typename... Args>
using to_json_function = decltype(T::to_json(std::declval<Args>()...));
template<typename T, typename... Args>
using from_json_function = decltype(T::from_json(std::declval<Args>()...));
template<typename T, typename U>
using get_template_function = decltype(std::declval<T>().template get<U>());
template<typename BasicJsonType, typename T, typename = void>
struct has_from_json : std::false_type {};
template <typename BasicJsonType, typename T>
struct is_getable
{
    static constexpr bool value = is_detected<get_template_function, const BasicJsonType&, T>::value;
};
template<typename BasicJsonType, typename T>
struct has_from_json < BasicJsonType, T, enable_if_t < !is_basic_json<T>::value >>
{
    using serializer = typename BasicJsonType::template json_serializer<T, void>;
    static constexpr bool value =
        is_detected_exact<void, from_json_function, serializer,
        const BasicJsonType&, T&>::value;
};
template<typename BasicJsonType, typename T, typename = void>
struct has_non_default_from_json : std::false_type {};
template<typename BasicJsonType, typename T>
struct has_non_default_from_json < BasicJsonType, T, enable_if_t < !is_basic_json<T>::value >>
{
    using serializer = typename BasicJsonType::template json_serializer<T, void>;
    static constexpr bool value =
        is_detected_exact<T, from_json_function, serializer,
        const BasicJsonType&>::value;
};
template<typename BasicJsonType, typename T, typename = void>
struct has_to_json : std::false_type {};
template<typename BasicJsonType, typename T>
struct has_to_json < BasicJsonType, T, enable_if_t < !is_basic_json<T>::value >>
{
    using serializer = typename BasicJsonType::template json_serializer<T, void>;
    static constexpr bool value =
        is_detected_exact<void, to_json_function, serializer, BasicJsonType&,
        T>::value;
};
template<typename T>
using detect_key_compare = typename T::key_compare;
template<typename BasicJsonType>
struct actual_object_comparator
{
    using object_t = typename BasicJsonType::object_t;
    using object_comparator_t = typename BasicJsonType::default_object_comparator_t;
    using type = detected_or_t<object_comparator_t, detect_key_compare, object_t>;
};
template<typename BasicJsonType>
using actual_object_comparator_t = typename actual_object_comparator<BasicJsonType>::type;
template<typename T>
struct char_traits : std::char_traits<T>
{};
template<>
struct char_traits<unsigned char> : std::char_traits<char>
{
    using char_type = unsigned char;
    using int_type = uint64_t;
    static int_type to_int_type(char_type c) noexcept
    {
        return static_cast<int_type>(c);
    }
    static char_type to_char_type(int_type i) noexcept
    {
        return static_cast<char_type>(i);
    }
    static constexpr int_type eof() noexcept
    {
        return static_cast<int_type>(std::char_traits<char>::eof());
    }
};
template<>
struct char_traits<signed char> : std::char_traits<char>
{
    using char_type = signed char;
    using int_type = uint64_t;
    static int_type to_int_type(char_type c) noexcept
    {
        return static_cast<int_type>(static_cast<unsigned char>(c));
    }
    static char_type to_char_type(int_type i) noexcept
    {
        return static_cast<char_type>(i);
    }
    static constexpr int_type eof() noexcept
    {
        return static_cast<int_type>(std::char_traits<char>::eof());
    }
};
#if defined(__cpp_lib_byte) && __cpp_lib_byte >= 201603L
template<>
struct char_traits<std::byte> : std::char_traits<char>
{
    using char_type = std::byte;
    using int_type = uint64_t;
    static int_type to_int_type(char_type c) noexcept
    {
        return static_cast<int_type>(std::to_integer<unsigned char>(c));
    }
    static char_type to_char_type(int_type i) noexcept
    {
        return std::byte(static_cast<unsigned char>(i));
    }
    static constexpr int_type eof() noexcept
    {
        return static_cast<int_type>(std::char_traits<char>::eof());
    }
};
#endif
template<class...> struct conjunction : std::true_type { };
template<class B> struct conjunction<B> : B { };
template<class B, class... Bn>
struct conjunction<B, Bn...>
: std::conditional<static_cast<bool>(B::value), conjunction<Bn...>, B>::type {};
template<class B> struct negation : std::integral_constant < bool, !B::value > { };
template <typename T>
struct is_default_constructible : std::is_default_constructible<T> {};
template <typename T1, typename T2>
struct is_default_constructible<std::pair<T1, T2>>
    : conjunction<is_default_constructible<T1>, is_default_constructible<T2>> {};
template <typename T1, typename T2>
struct is_default_constructible<const std::pair<T1, T2>>
    : conjunction<is_default_constructible<T1>, is_default_constructible<T2>> {};
template <typename... Ts>
struct is_default_constructible<std::tuple<Ts...>>
    : conjunction<is_default_constructible<Ts>...> {};
template <typename... Ts>
struct is_default_constructible<const std::tuple<Ts...>>
    : conjunction<is_default_constructible<Ts>...> {};
template <typename T, typename... Args>
struct is_constructible : std::is_constructible<T, Args...> {};
template <typename T1, typename T2>
struct is_constructible<std::pair<T1, T2>> : is_default_constructible<std::pair<T1, T2>> {};
template <typename T1, typename T2>
struct is_constructible<const std::pair<T1, T2>> : is_default_constructible<const std::pair<T1, T2>> {};
template <typename... Ts>
struct is_constructible<std::tuple<Ts...>> : is_default_constructible<std::tuple<Ts...>> {};
template <typename... Ts>
struct is_constructible<const std::tuple<Ts...>> : is_default_constructible<const std::tuple<Ts...>> {};
template<typename T, typename = void>
struct is_iterator_traits : std::false_type {};
template<typename T>
struct is_iterator_traits<iterator_traits<T>>
{
  private:
    using traits = iterator_traits<T>;
  public:
    static constexpr auto value =
        is_detected<value_type_t, traits>::value &&
        is_detected<difference_type_t, traits>::value &&
        is_detected<pointer_t, traits>::value &&
        is_detected<iterator_category_t, traits>::value &&
        is_detected<reference_t, traits>::value;
};
template<typename T>
struct is_range
{
  private:
    using t_ref = typename std::add_lvalue_reference<T>::type;
    using iterator = detected_t<result_of_begin, t_ref>;
    using sentinel = detected_t<result_of_end, t_ref>;
    static constexpr auto is_iterator_begin =
        is_iterator_traits<iterator_traits<iterator>>::value;
  public:
    static constexpr bool value = !std::is_same<iterator, nonesuch>::value && !std::is_same<sentinel, nonesuch>::value && is_iterator_begin;
};
template<typename R>
using iterator_t = enable_if_t<is_range<R>::value, result_of_begin<decltype(std::declval<R&>())>>;
template<typename T>
using range_value_t = value_type_t<iterator_traits<iterator_t<T>>>;
template<typename T, typename = void>
struct is_complete_type : std::false_type {};
template<typename T>
struct is_complete_type<T, decltype(void(sizeof(T)))> : std::true_type {};
template<typename BasicJsonType, typename CompatibleObjectType,
         typename = void>
struct is_compatible_object_type_impl : std::false_type {};
template<typename BasicJsonType, typename CompatibleObjectType>
struct is_compatible_object_type_impl <
    BasicJsonType, CompatibleObjectType,
    enable_if_t < is_detected<mapped_type_t, CompatibleObjectType>::value&&
    is_detected<key_type_t, CompatibleObjectType>::value >>
{
    using object_t = typename BasicJsonType::object_t;
    static constexpr bool value =
        is_constructible<typename object_t::key_type,
        typename CompatibleObjectType::key_type>::value &&
        is_constructible<typename object_t::mapped_type,
        typename CompatibleObjectType::mapped_type>::value;
};
template<typename BasicJsonType, typename CompatibleObjectType>
struct is_compatible_object_type
    : is_compatible_object_type_impl<BasicJsonType, CompatibleObjectType> {};
template<typename BasicJsonType, typename ConstructibleObjectType,
         typename = void>
struct is_constructible_object_type_impl : std::false_type {};
template<typename BasicJsonType, typename ConstructibleObjectType>
struct is_constructible_object_type_impl <
    BasicJsonType, ConstructibleObjectType,
    enable_if_t < is_detected<mapped_type_t, ConstructibleObjectType>::value&&
    is_detected<key_type_t, ConstructibleObjectType>::value >>
{
    using object_t = typename BasicJsonType::object_t;
    static constexpr bool value =
        (is_default_constructible<ConstructibleObjectType>::value &&
         (std::is_move_assignable<ConstructibleObjectType>::value ||
          std::is_copy_assignable<ConstructibleObjectType>::value) &&
         (is_constructible<typename ConstructibleObjectType::key_type,
          typename object_t::key_type>::value &&
          std::is_same <
          typename object_t::mapped_type,
          typename ConstructibleObjectType::mapped_type >::value)) ||
        (has_from_json<BasicJsonType,
         typename ConstructibleObjectType::mapped_type>::value ||
         has_non_default_from_json <
         BasicJsonType,
         typename ConstructibleObjectType::mapped_type >::value);
};
template<typename BasicJsonType, typename ConstructibleObjectType>
struct is_constructible_object_type
    : is_constructible_object_type_impl<BasicJsonType,
      ConstructibleObjectType> {};
template<typename BasicJsonType, typename CompatibleStringType>
struct is_compatible_string_type
{
    static constexpr auto value =
        is_constructible<typename BasicJsonType::string_t, CompatibleStringType>::value;
};
template<typename BasicJsonType, typename ConstructibleStringType>
struct is_constructible_string_type
{
#ifdef __INTEL_COMPILER
    using laundered_type = decltype(std::declval<ConstructibleStringType>());
#else
    using laundered_type = ConstructibleStringType;
#endif
    static constexpr auto value =
        conjunction <
        is_constructible<laundered_type, typename BasicJsonType::string_t>,
        is_detected_exact<typename BasicJsonType::string_t::value_type,
        value_type_t, laundered_type >>::value;
};
template<typename IteratorType> class iteration_proxy;
template<typename IteratorType> class iteration_proxy_value;
template<typename T> struct is_iteration_proxy_type : std::false_type {};
template<typename T> struct is_iteration_proxy_type<iteration_proxy<T>>       : std::true_type {};
template<typename T> struct is_iteration_proxy_type<iteration_proxy_value<T>> : std::true_type {};
#ifdef JSON_HAS_CPP_17
template<typename T> struct is_range_view_optional_type : std::false_type {};
template<typename T> struct is_range_view_optional_type<std::optional<T>> : std::true_type {};
#else
template<typename T> struct is_range_view_optional_type : std::false_type {};
#endif
#if JSON_HAS_RANGES && !defined(__MINGW32__)
template < typename T, bool SafeToCheck =
           !is_iteration_proxy_type<T>::value &&
           !is_iteration_proxy_type<detected_t<range_value_t, T>>::value &&
           !is_basic_json<detected_t<range_value_t, T>>::value &&
           !is_range_view_optional_type<T>::value >
struct is_compatible_range_view : std::false_type {};
template<typename T>
struct is_compatible_range_view<T, true>
    : std::bool_constant<std::ranges::view<T>> {};
#endif
template<typename BasicJsonType, typename CompatibleArrayType, typename = void>
struct is_compatible_array_type_impl : std::false_type {};
template<typename BasicJsonType, typename CompatibleArrayType>
struct is_compatible_array_type_impl <
    BasicJsonType, CompatibleArrayType,
    enable_if_t <
    is_detected<iterator_t, CompatibleArrayType>::value&&
    is_iterator_traits<iterator_traits<detected_t<iterator_t, CompatibleArrayType>>>::value&&
    !std::is_same<CompatibleArrayType, detected_t<range_value_t, CompatibleArrayType>>::value
#if JSON_HAS_RANGES && !defined(__MINGW32__)
&& !is_compatible_range_view<CompatibleArrayType>::value
#endif
            >>
{
    static constexpr bool value =
        is_constructible<BasicJsonType,
        range_value_t<CompatibleArrayType>>::value;
};
#if JSON_HAS_RANGES && !defined(__MINGW32__)
template<typename BasicJsonType, typename CompatibleArrayType>
struct is_compatible_array_type_impl <
    BasicJsonType, CompatibleArrayType,
    enable_if_t < is_compatible_range_view<CompatibleArrayType>::value
    && !std::is_same<detected_t<range_value_t, CompatibleArrayType>, char>::value
    && !std::is_same<detected_t<range_value_t, CompatibleArrayType>, wchar_t>::value >>
{
    static constexpr bool value =
        is_constructible<BasicJsonType,
        std::ranges::range_value_t<CompatibleArrayType>>::value;
};
#endif
template<typename BasicJsonType, typename CompatibleArrayType>
struct is_compatible_array_type
    : is_compatible_array_type_impl<BasicJsonType, CompatibleArrayType> {};
template<typename BasicJsonType, typename ConstructibleArrayType, typename = void>
struct is_constructible_array_type_impl : std::false_type {};
template<typename BasicJsonType, typename ConstructibleArrayType>
struct is_constructible_array_type_impl <
    BasicJsonType, ConstructibleArrayType,
    enable_if_t<std::is_same<ConstructibleArrayType,
    typename BasicJsonType::value_type>::value >>
            : std::true_type {};
template<typename BasicJsonType, typename ConstructibleArrayType>
struct is_constructible_array_type_impl <
    BasicJsonType, ConstructibleArrayType,
    enable_if_t < !std::is_same<ConstructibleArrayType,
    typename BasicJsonType::value_type>::value&&
    !is_compatible_string_type<BasicJsonType, ConstructibleArrayType>::value&&
    is_default_constructible<ConstructibleArrayType>::value&&
(std::is_move_assignable<ConstructibleArrayType>::value ||
 std::is_copy_assignable<ConstructibleArrayType>::value)&&
is_detected<iterator_t, ConstructibleArrayType>::value&&
is_iterator_traits<iterator_traits<detected_t<iterator_t, ConstructibleArrayType>>>::value&&
is_detected<range_value_t, ConstructibleArrayType>::value&&
!std::is_same<ConstructibleArrayType, detected_t<range_value_t, ConstructibleArrayType>>::value&&
is_complete_type <
detected_t<range_value_t, ConstructibleArrayType >>::value >>
{
    using value_type = range_value_t<ConstructibleArrayType>;
    static constexpr bool value =
        std::is_same<value_type,
        typename BasicJsonType::array_t::value_type>::value ||
        has_from_json<BasicJsonType,
        value_type>::value ||
        has_non_default_from_json <
        BasicJsonType,
        value_type >::value;
};
template<typename BasicJsonType, typename ConstructibleArrayType>
struct is_constructible_array_type
    : is_constructible_array_type_impl<BasicJsonType, ConstructibleArrayType> {};
template<typename RealIntegerType, typename CompatibleNumberIntegerType,
         typename = void>
struct is_compatible_integer_type_impl : std::false_type {};
template<typename RealIntegerType, typename CompatibleNumberIntegerType>
struct is_compatible_integer_type_impl <
    RealIntegerType, CompatibleNumberIntegerType,
    enable_if_t < std::is_integral<RealIntegerType>::value&&
    std::is_integral<CompatibleNumberIntegerType>::value&&
    !std::is_same<bool, CompatibleNumberIntegerType>::value >>
{
    using RealLimits = std::numeric_limits<RealIntegerType>;
    using CompatibleLimits = std::numeric_limits<CompatibleNumberIntegerType>;
    static constexpr auto value =
        is_constructible<RealIntegerType,
        CompatibleNumberIntegerType>::value &&
        CompatibleLimits::is_integer &&
        RealLimits::is_signed == CompatibleLimits::is_signed;
};
template<typename RealIntegerType, typename CompatibleNumberIntegerType>
struct is_compatible_integer_type
    : is_compatible_integer_type_impl<RealIntegerType,
      CompatibleNumberIntegerType> {};
template<typename BasicJsonType, typename CompatibleType, typename = void>
struct is_compatible_type_impl: std::false_type {};
template<typename BasicJsonType, typename CompatibleType>
struct is_compatible_type_impl <
    BasicJsonType, CompatibleType,
    enable_if_t<is_complete_type<CompatibleType>::value >>
{
    static constexpr bool value =
        has_to_json<BasicJsonType, CompatibleType>::value;
};
template<typename BasicJsonType, typename CompatibleType>
struct is_compatible_type
    : is_compatible_type_impl<BasicJsonType, CompatibleType> {};
template<typename BasicJsonType, typename T>
struct is_basic_json_reference_tuple : std::false_type {};
template<typename BasicJsonType, typename T>
struct is_basic_json_reference_tuple<BasicJsonType, std::tuple<T>>
{
    static constexpr bool value =
        std::is_reference<T>::value && std::is_same<uncvref_t<T>, BasicJsonType>::value;
};
template<typename BasicJsonType, typename CompatibleArrayType>
struct is_compatible_binary_type
{
    static constexpr bool value =
        std::is_same<typename BasicJsonType::binary_t::container_type, CompatibleArrayType>::value &&
        !std::is_same<typename BasicJsonType::binary_t::container_type, std::vector<std::uint8_t>>::value;
};
template<typename BasicJsonType, typename CompatibleReferenceType>
struct is_compatible_reference_type_impl
{
    using JsonType = uncvref_t<BasicJsonType>;
    using CVType = typename std::remove_reference<CompatibleReferenceType>::type;
    using Type = typename std::remove_cv<CVType>::type;
    constexpr static bool value = std::is_reference<CompatibleReferenceType>::value &&
                                  (!std::is_const<typename std::remove_reference<BasicJsonType>::type>::value || std::is_const<CVType>::value) &&
                                  (std::is_same<typename JsonType::boolean_t, Type>::value ||
                                   std::is_same<typename JsonType::number_float_t, Type>::value ||
                                   std::is_same<typename JsonType::number_integer_t, Type>::value ||
                                   std::is_same<typename JsonType::number_unsigned_t, Type>::value ||
                                   std::is_same<typename JsonType::string_t, Type>::value ||
                                   std::is_same<typename JsonType::binary_t, Type>::value ||
                                   std::is_same<typename JsonType::object_t, Type>::value ||
                                   std::is_same<typename JsonType::array_t, Type>::value);
};
template<typename BasicJsonType, typename CompatibleReferenceType>
struct is_compatible_reference_type
    : is_compatible_reference_type_impl<BasicJsonType, CompatibleReferenceType> {};
template<typename T1, typename T2>
struct is_constructible_tuple : std::false_type {};
template<typename T1, typename... Args>
struct is_constructible_tuple<T1, std::tuple<Args...>> : conjunction<is_constructible<T1, Args>...> {};
template<typename BasicJsonType, typename T>
struct is_json_iterator_of : std::false_type {};
template<typename BasicJsonType>
struct is_json_iterator_of<BasicJsonType, typename BasicJsonType::iterator> : std::true_type {};
template<typename BasicJsonType>
struct is_json_iterator_of<BasicJsonType, typename BasicJsonType::const_iterator> : std::true_type
{};
template<template <typename...> class Primary, typename T>
struct is_specialization_of : std::false_type {};
template<template <typename...> class Primary, typename... Args>
struct is_specialization_of<Primary, Primary<Args...>> : std::true_type {};
template<typename T>
using is_json_pointer = is_specialization_of<::nlohmann::json_pointer, uncvref_t<T>>;
template <typename A, typename B>
struct is_json_pointer_of : std::false_type {};
template <typename A>
struct is_json_pointer_of<A, ::nlohmann::json_pointer<A>> : std::true_type {};
template <typename A>
struct is_json_pointer_of<A, ::nlohmann::json_pointer<A>&> : std::true_type {};
template<typename Compare, typename A, typename B, typename = void>
struct is_comparable_no_json_pointer : std::false_type {};
template<typename Compare, typename A, typename B>
struct is_comparable_no_json_pointer < Compare, A, B, enable_if_t <
std::is_constructible <decltype(std::declval<Compare>()(std::declval<A>(), std::declval<B>()))>::value
&& std::is_constructible <decltype(std::declval<Compare>()(std::declval<B>(), std::declval<A>()))>::value
>> : std::true_type {};
template<typename Compare, typename A, typename B, bool = is_json_pointer_of<uncvref_t<A>, uncvref_t<B>>::value>
struct is_comparable : std::false_type {};
template<typename Compare, typename A, typename B>
struct is_comparable<Compare, A, B, false> : is_comparable_no_json_pointer<Compare, A, B> {};
template<typename T>
using detect_is_transparent = typename T::is_transparent;
template<typename Comparator, typename ObjectKeyType, typename KeyTypeCVRef, bool RequireTransparentComparator = true,
         bool ExcludeObjectKeyType = RequireTransparentComparator, typename KeyType = uncvref_t<KeyTypeCVRef>>
using is_usable_as_key_type = typename std::conditional <
                              is_comparable<Comparator, ObjectKeyType, KeyTypeCVRef>::value
                              && !(ExcludeObjectKeyType && std::is_same<KeyType,
                                   ObjectKeyType>::value)
                              && (!RequireTransparentComparator
                                  || is_detected <detect_is_transparent, Comparator>::value)
                              && !is_json_pointer<KeyType>::value,
                              std::true_type,
                              std::false_type >::type;
template<typename BasicJsonType, typename KeyTypeCVRef, bool RequireTransparentComparator = true,
         bool ExcludeObjectKeyType = RequireTransparentComparator, typename KeyType = uncvref_t<KeyTypeCVRef>>
using is_usable_as_basic_json_key_type = typename std::conditional <
    (is_usable_as_key_type<typename BasicJsonType::object_comparator_t,
     typename BasicJsonType::object_t::key_type, KeyTypeCVRef,
     RequireTransparentComparator, ExcludeObjectKeyType>::value
     && !is_json_iterator_of<BasicJsonType, KeyType>::value)
#ifdef JSON_HAS_CPP_17
    || std::is_convertible<KeyType, std::string_view>::value
#endif
    , std::true_type,
    std::false_type >::type;
template<typename ObjectType, typename KeyType>
using detect_erase_with_key_type = decltype(std::declval<ObjectType&>().erase(std::declval<KeyType>()));
template<typename BasicJsonType, typename KeyType>
using has_erase_with_key_type = typename std::conditional <
                                is_detected <
                                detect_erase_with_key_type,
                                typename BasicJsonType::object_t, KeyType >::value,
                                std::true_type,
                                std::false_type >::type;
template<typename ObjectType, typename IteratorType>
using detect_erase_with_iterator = decltype(std::declval<ObjectType&>().erase(std::declval<IteratorType>()));
template<typename ObjectType, typename IteratorType>
using erase_returns_void = is_detected_exact<void, detect_erase_with_iterator, ObjectType, IteratorType>;
template<typename T>
using detect_capacity = decltype(std::declval<const T&>().capacity());
template<typename T>
struct has_capacity : std::integral_constant<bool, is_detected<detect_capacity, T>::value> {};
template <typename T>
struct is_ordered_map
{
    using one = char;
    struct two
    {
        char x[2]; 
    };
    template <typename C> static one test( decltype(&C::capacity) ) ;
    template <typename C> static two test(...);
    enum { value = sizeof(test<T>(nullptr)) == sizeof(char) }; 
};
template < typename T, typename U, enable_if_t < !std::is_same<T, U>::value, int > = 0 >
T conditional_static_cast(U value)
{
    return static_cast<T>(value);
}
template<typename T, typename U, enable_if_t<std::is_same<T, U>::value, int> = 0>
T conditional_static_cast(U value)
{
    return value;
}
template<typename... Types>
using all_integral = conjunction<std::is_integral<Types>...>;
template<typename... Types>
using all_signed = conjunction<std::is_signed<Types>...>;
template<typename... Types>
using all_unsigned = conjunction<std::is_unsigned<Types>...>;
template<typename... Types>
using same_sign = std::integral_constant < bool,
      all_signed<Types...>::value || all_unsigned<Types...>::value >;
template<typename OfType, typename T>
using never_out_of_range = std::integral_constant < bool,
      (std::is_signed<OfType>::value && (sizeof(T) < sizeof(OfType)))
      || (same_sign<OfType, T>::value && sizeof(OfType) == sizeof(T)) >;
template<typename OfType, typename T,
         bool OfTypeSigned = std::is_signed<OfType>::value,
         bool TSigned = std::is_signed<T>::value>
struct value_in_range_of_impl2;
template<typename OfType, typename T>
struct value_in_range_of_impl2<OfType, T, false, false>
{
    static constexpr bool test(T val)
    {
        using CommonType = typename std::common_type<OfType, T>::type;
        return static_cast<CommonType>(val) <= static_cast<CommonType>((std::numeric_limits<OfType>::max)());
    }
};
template<typename OfType, typename T>
struct value_in_range_of_impl2<OfType, T, true, false>
{
    static constexpr bool test(T val)
    {
        using CommonType = typename std::common_type<OfType, T>::type;
        return static_cast<CommonType>(val) <= static_cast<CommonType>((std::numeric_limits<OfType>::max)());
    }
};
template<typename OfType, typename T>
struct value_in_range_of_impl2<OfType, T, false, true>
{
    static constexpr bool test(T val)
    {
        using CommonType = typename std::common_type<OfType, T>::type;
        return val >= 0 && static_cast<CommonType>(val) <= static_cast<CommonType>((std::numeric_limits<OfType>::max)());
    }
};
template<typename OfType, typename T>
struct value_in_range_of_impl2<OfType, T, true, true>
{
    static constexpr bool test(T val)
    {
        using CommonType = typename std::common_type<OfType, T>::type;
        return static_cast<CommonType>(val) >= static_cast<CommonType>((std::numeric_limits<OfType>::min)())
               && static_cast<CommonType>(val) <= static_cast<CommonType>((std::numeric_limits<OfType>::max)());
    }
};
template<typename OfType, typename T,
         bool NeverOutOfRange = never_out_of_range<OfType, T>::value,
         typename = detail::enable_if_t<all_integral<OfType, T>::value>>
struct value_in_range_of_impl1;
template<typename OfType, typename T>
struct value_in_range_of_impl1<OfType, T, false>
{
    static constexpr bool test(T val)
    {
        return value_in_range_of_impl2<OfType, T>::test(val);
    }
};
template<typename OfType, typename T>
struct value_in_range_of_impl1<OfType, T, true>
{
    static constexpr bool test(T )
    {
        return true;
    }
};
template<typename OfType, typename T>
constexpr bool value_in_range_of(T val)
{
    return value_in_range_of_impl1<OfType, T>::test(val);
}
template<bool Value>
using bool_constant = std::integral_constant<bool, Value>;
namespace impl
{
template<typename T>
constexpr bool is_c_string()
{
    using TUnExt = typename std::remove_extent<T>::type;
    using TUnCVExt = typename std::remove_cv<TUnExt>::type;
    using TUnPtr = typename std::remove_pointer<T>::type;
    using TUnCVPtr = typename std::remove_cv<TUnPtr>::type;
    return
        (std::is_array<T>::value && std::is_same<TUnCVExt, char>::value)
        || (std::is_pointer<T>::value && std::is_same<TUnCVPtr, char>::value);
}
}  
template<typename T>
struct is_c_string : bool_constant<impl::is_c_string<T>()> {};
template<typename T>
using is_c_string_uncvref = is_c_string<uncvref_t<T>>;
namespace impl
{
template<typename T>
constexpr bool is_transparent()
{
    return is_detected<detect_is_transparent, T>::value;
}
}  
template<typename T>
struct is_transparent : bool_constant<impl::is_transparent<T>()> {};
}  
NLOHMANN_JSON_NAMESPACE_END
#include <cstring> 
#include <string> 
#include <utility> 
NLOHMANN_JSON_NAMESPACE_BEGIN
namespace detail
{
inline std::size_t concat_length()
{
    return 0;
}
template<typename... Args>
inline std::size_t concat_length(const char* cstr, const Args& ... rest);
template<typename StringType, typename... Args>
inline std::size_t concat_length(const StringType& str, const Args& ... rest);
template<typename... Args>
inline std::size_t concat_length(const char , const Args& ... rest)
{
    return 1 + concat_length(rest...);
}
template<typename... Args>
inline std::size_t concat_length(const char* cstr, const Args& ... rest)
{
    return ::strlen(cstr) + concat_length(rest...);
}
template<typename StringType, typename... Args>
inline std::size_t concat_length(const StringType& str, const Args& ... rest)
{
    return str.size() + concat_length(rest...);
}
template<typename OutStringType>
inline void concat_into(OutStringType& )
{}
template<typename StringType, typename Arg>
using string_can_append = decltype(std::declval<StringType&>().append(std::declval < Arg && > ()));
template<typename StringType, typename Arg>
using detect_string_can_append = is_detected<string_can_append, StringType, Arg>;
template<typename StringType, typename Arg>
using string_can_append_op = decltype(std::declval<StringType&>() += std::declval < Arg && > ());
template<typename StringType, typename Arg>
using detect_string_can_append_op = is_detected<string_can_append_op, StringType, Arg>;
template<typename StringType, typename Arg>
using string_can_append_iter = decltype(std::declval<StringType&>().append(std::declval<const Arg&>().begin(), std::declval<const Arg&>().end()));
template<typename StringType, typename Arg>
using detect_string_can_append_iter = is_detected<string_can_append_iter, StringType, Arg>;
template<typename StringType, typename Arg>
using string_can_append_data = decltype(std::declval<StringType&>().append(std::declval<const Arg&>().data(), std::declval<const Arg&>().size()));
template<typename StringType, typename Arg>
using detect_string_can_append_data = is_detected<string_can_append_data, StringType, Arg>;
template < typename OutStringType, typename Arg, typename... Args,
           enable_if_t < !detect_string_can_append<OutStringType, Arg>::value
                         && detect_string_can_append_op<OutStringType, Arg>::value, int > = 0 >
inline void concat_into(OutStringType& out, Arg && arg, Args && ... rest);
template < typename OutStringType, typename Arg, typename... Args,
           enable_if_t < !detect_string_can_append<OutStringType, Arg>::value
                         && !detect_string_can_append_op<OutStringType, Arg>::value
                         && detect_string_can_append_iter<OutStringType, Arg>::value, int > = 0 >
inline void concat_into(OutStringType& out, const Arg& arg, Args && ... rest);
template < typename OutStringType, typename Arg, typename... Args,
           enable_if_t < !detect_string_can_append<OutStringType, Arg>::value
                         && !detect_string_can_append_op<OutStringType, Arg>::value
                         && !detect_string_can_append_iter<OutStringType, Arg>::value
                         && detect_string_can_append_data<OutStringType, Arg>::value, int > = 0 >
inline void concat_into(OutStringType& out, const Arg& arg, Args && ... rest);
template<typename OutStringType, typename Arg, typename... Args,
         enable_if_t<detect_string_can_append<OutStringType, Arg>::value, int> = 0>
inline void concat_into(OutStringType& out, Arg && arg, Args && ... rest)
{
    out.append(std::forward<Arg>(arg));
    concat_into(out, std::forward<Args>(rest)...);
}
template < typename OutStringType, typename Arg, typename... Args,
           enable_if_t < !detect_string_can_append<OutStringType, Arg>::value
                         && detect_string_can_append_op<OutStringType, Arg>::value, int > >
inline void concat_into(OutStringType& out, Arg&& arg, Args&& ... rest)
{
    out += std::forward<Arg>(arg);
    concat_into(out, std::forward<Args>(rest)...);
}
template < typename OutStringType, typename Arg, typename... Args,
           enable_if_t < !detect_string_can_append<OutStringType, Arg>::value
                         && !detect_string_can_append_op<OutStringType, Arg>::value
                         && detect_string_can_append_iter<OutStringType, Arg>::value, int > >
inline void concat_into(OutStringType& out, const Arg& arg, Args&& ... rest)
{
    out.append(arg.begin(), arg.end());
    concat_into(out, std::forward<Args>(rest)...);
}
template < typename OutStringType, typename Arg, typename... Args,
           enable_if_t < !detect_string_can_append<OutStringType, Arg>::value
                         && !detect_string_can_append_op<OutStringType, Arg>::value
                         && !detect_string_can_append_iter<OutStringType, Arg>::value
                         && detect_string_can_append_data<OutStringType, Arg>::value, int > >
inline void concat_into(OutStringType& out, const Arg& arg, Args&& ... rest)
{
    out.append(arg.data(), arg.size());
    concat_into(out, std::forward<Args>(rest)...);
}
template<typename OutStringType = std::string, typename... Args>
inline OutStringType concat(Args && ... args)
{
    OutStringType str;
    str.reserve(concat_length(args...));
    concat_into(str, std::forward<Args>(args)...);
    return str;
}
}  
NLOHMANN_JSON_NAMESPACE_END
#if defined(__clang__)
    JSON_HEDLEY_DIAGNOSTIC_PUSH
    JSON_HEDLEY_PRAGMA(clang diagnostic ignored "-Wweak-vtables")
#endif
NLOHMANN_JSON_NAMESPACE_BEGIN
namespace detail
{
class exception : public std::exception
{
  public:
    const char* what() const noexcept override
    {
        return m.what();
    }
    const int id; 
  protected:
    JSON_HEDLEY_NON_NULL(3)
    exception(int id_, const char* what_arg) : id(id_), m(what_arg) {} 
    static std::string name(const std::string& ename, int id_)
    {
        return concat("[json.exception.", ename, '.', std::to_string(id_), "] ");
    }
    static std::string diagnostics(std::nullptr_t )
    {
        return "";
    }
    template<typename BasicJsonType>
    static std::string diagnostics(const BasicJsonType* leaf_element)
    {
#if JSON_DIAGNOSTICS
        std::vector<std::string> tokens;
        for (const auto* current = leaf_element; current != nullptr && current->m_parent != nullptr; current = current->m_parent)
        {
            switch (current->m_parent->type())
            {
                case value_t::array:
                {
                    for (std::size_t i = 0; i < current->m_parent->m_data.m_value.array->size(); ++i)
                    {
                        if (&current->m_parent->m_data.m_value.array->operator[](i) == current)
                        {
                            tokens.emplace_back(std::to_string(i));
                            break;
                        }
                    }
                    break;
                }
                case value_t::object:
                {
                    for (const auto& element : *current->m_parent->m_data.m_value.object)
                    {
                        if (&element.second == current)
                        {
                            tokens.emplace_back(element.first.data());
                            break;
                        }
                    }
                    break;
                }
                case value_t::null: 
                case value_t::string: 
                case value_t::boolean: 
                case value_t::number_integer: 
                case value_t::number_unsigned: 
                case value_t::number_float: 
                case value_t::binary: 
                case value_t::discarded: 
                default:   
                    break; 
            }
        }
        if (tokens.empty())
        {
            return "";
        }
        auto str = std::accumulate(tokens.rbegin(), tokens.rend(), std::string{},
                                   [](const std::string & a, const std::string & b)
        {
            return concat(a, '/', detail::escape(b));
        });
        return concat('(', str, ") ", get_byte_positions(leaf_element));
#else
        return get_byte_positions(leaf_element);
#endif
    }
  private:
    std::runtime_error m;
#if JSON_DIAGNOSTIC_POSITIONS
    template<typename BasicJsonType>
    static std::string get_byte_positions(const BasicJsonType* leaf_element)
    {
        if ((leaf_element->start_pos() != std::string::npos) && (leaf_element->end_pos() != std::string::npos))
        {
            return concat("(bytes ", std::to_string(leaf_element->start_pos()), "-", std::to_string(leaf_element->end_pos()), ") ");
        }
        return "";
    }
#else
    template<typename BasicJsonType>
    static std::string get_byte_positions(const BasicJsonType* leaf_element)
    {
        static_cast<void>(leaf_element);
        return "";
    }
#endif
};
class parse_error : public exception
{
  public:
    template<typename BasicJsonContext, enable_if_t<is_basic_json_context<BasicJsonContext>::value, int> = 0>
    static parse_error create(int id_, const position_t& pos, const std::string& what_arg, BasicJsonContext context)
    {
        const std::string w = concat(exception::name("parse_error", id_), "parse error",
                                     position_string(pos), ": ", exception::diagnostics(context), what_arg);
        return {id_, pos.chars_read_total, w.c_str()};
    }
    template<typename BasicJsonContext, enable_if_t<is_basic_json_context<BasicJsonContext>::value, int> = 0>
    static parse_error create(int id_, std::size_t byte_, const std::string& what_arg, BasicJsonContext context)
    {
        const std::string w = concat(exception::name("parse_error", id_), "parse error",
                                     (byte_ != 0 ? (concat(" at byte ", std::to_string(byte_))) : ""),
                                     ": ", exception::diagnostics(context), what_arg);
        return {id_, byte_, w.c_str()};
    }
    const std::size_t byte;
  private:
    parse_error(int id_, std::size_t byte_, const char* what_arg)
        : exception(id_, what_arg), byte(byte_) {}
    static std::string position_string(const position_t& pos)
    {
        return concat(" at line ", std::to_string(pos.lines_read + 1),
                      ", column ", std::to_string(pos.chars_read_current_line));
    }
};
class invalid_iterator : public exception
{
  public:
    template<typename BasicJsonContext, enable_if_t<is_basic_json_context<BasicJsonContext>::value, int> = 0>
    static invalid_iterator create(int id_, const std::string& what_arg, BasicJsonContext context)
    {
        const std::string w = concat(exception::name("invalid_iterator", id_), exception::diagnostics(context), what_arg);
        return {id_, w.c_str()};
    }
  private:
    JSON_HEDLEY_NON_NULL(3)
    invalid_iterator(int id_, const char* what_arg)
        : exception(id_, what_arg) {}
};
class type_error : public exception
{
  public:
    template<typename BasicJsonContext, enable_if_t<is_basic_json_context<BasicJsonContext>::value, int> = 0>
    static type_error create(int id_, const std::string& what_arg, BasicJsonContext context)
    {
        const std::string w = concat(exception::name("type_error", id_), exception::diagnostics(context), what_arg);
        return {id_, w.c_str()};
    }
  private:
    JSON_HEDLEY_NON_NULL(3)
    type_error(int id_, const char* what_arg) : exception(id_, what_arg) {}
};
class out_of_range : public exception
{
  public:
    template<typename BasicJsonContext, enable_if_t<is_basic_json_context<BasicJsonContext>::value, int> = 0>
    static out_of_range create(int id_, const std::string& what_arg, BasicJsonContext context)
    {
        const std::string w = concat(exception::name("out_of_range", id_), exception::diagnostics(context), what_arg);
        return {id_, w.c_str()};
    }
  private:
    JSON_HEDLEY_NON_NULL(3)
    out_of_range(int id_, const char* what_arg) : exception(id_, what_arg) {}
};
class other_error : public exception
{
  public:
    template<typename BasicJsonContext, enable_if_t<is_basic_json_context<BasicJsonContext>::value, int> = 0>
    static other_error create(int id_, const std::string& what_arg, BasicJsonContext context)
    {
        const std::string w = concat(exception::name("other_error", id_), exception::diagnostics(context), what_arg);
        return {id_, w.c_str()};
    }
  private:
    JSON_HEDLEY_NON_NULL(3)
    other_error(int id_, const char* what_arg) : exception(id_, what_arg) {}
};
}  
NLOHMANN_JSON_NAMESPACE_END
#if defined(__clang__)
    JSON_HEDLEY_DIAGNOSTIC_POP
#endif
NLOHMANN_JSON_NAMESPACE_BEGIN
namespace detail
{
template <class T> struct identity_tag {};
}  
NLOHMANN_JSON_NAMESPACE_END
#if JSON_HAS_EXPERIMENTAL_FILESYSTEM
#include <experimental/filesystem>
NLOHMANN_JSON_NAMESPACE_BEGIN
namespace detail
{
namespace std_fs = std::experimental::filesystem;
}  
NLOHMANN_JSON_NAMESPACE_END
#elif JSON_HAS_FILESYSTEM
#include <filesystem> 
NLOHMANN_JSON_NAMESPACE_BEGIN
namespace detail
{
namespace std_fs = std::filesystem;
}  
NLOHMANN_JSON_NAMESPACE_END
#endif
NLOHMANN_JSON_NAMESPACE_BEGIN
namespace detail
{
#ifdef JSON_HAS_CPP_17
template<bool... Booleans>
struct cxpr_or_impl : std::integral_constant < bool, (Booleans || ...) > {};
template<bool... Booleans>
struct cxpr_and_impl : std::integral_constant < bool, (Booleans &&...) > {};
#else
template<bool... Booleans>
struct cxpr_or_impl : std::false_type {};
template<bool... Booleans>
struct cxpr_or_impl<true, Booleans...> : std::true_type {};
template<bool... Booleans>
struct cxpr_or_impl<false, Booleans...> : cxpr_or_impl<Booleans...> {};
template<bool... Booleans>
struct cxpr_and_impl : std::true_type {};
template<bool... Booleans>
struct cxpr_and_impl<true, Booleans...> : cxpr_and_impl<Booleans...> {};
template<bool... Booleans>
struct cxpr_and_impl<false, Booleans...> : std::false_type {};
#endif
template<class Boolean>
struct cxpr_not : std::integral_constant < bool, !Boolean::value > {};
template<class... Booleans>
struct cxpr_or : cxpr_or_impl<Booleans::value...> {};
template<bool... Booleans>
struct cxpr_or_c : cxpr_or_impl<Booleans...> {};
template<class... Booleans>
struct cxpr_and : cxpr_and_impl<Booleans::value...> {};
template<bool... Booleans>
struct cxpr_and_c : cxpr_and_impl<Booleans...> {};
}  
NLOHMANN_JSON_NAMESPACE_END
#ifdef JSON_HAS_CPP_17
    #include <optional> 
#endif
#if JSON_HAS_FILESYSTEM || JSON_HAS_EXPERIMENTAL_FILESYSTEM
    #include <string_view> 
#endif
NLOHMANN_JSON_NAMESPACE_BEGIN
namespace detail
{
template<typename BasicJsonType>
inline void from_json(const BasicJsonType& j, typename std::nullptr_t& n)
{
    if (JSON_HEDLEY_UNLIKELY(!j.is_null()))
    {
        JSON_THROW(type_error::create(302, concat("type must be null, but is ", j.type_name()), &j));
    }
    n = nullptr;
}
#ifdef JSON_HAS_CPP_17
template < typename BasicJsonType, typename T,
           typename std::enable_if < !nlohmann::detail::is_basic_json<T>::value, int >::type = 0 >
void from_json(const BasicJsonType& j, std::optional<T>& opt)
{
    if (j.is_null())
    {
        opt = std::nullopt;
    }
    else
    {
        opt.emplace(j.template get<T>());
    }
}
#endif 
template < typename BasicJsonType, typename ArithmeticType,
           enable_if_t < std::is_arithmetic<ArithmeticType>::value&&
                         !std::is_same<ArithmeticType, typename BasicJsonType::boolean_t>::value,
                         int > = 0 >
void get_arithmetic_value(const BasicJsonType& j, ArithmeticType& val)
{
    switch (static_cast<value_t>(j))
    {
        case value_t::number_unsigned:
        {
            val = static_cast<ArithmeticType>(*j.template get_ptr<const typename BasicJsonType::number_unsigned_t*>());
            break;
        }
        case value_t::number_integer:
        {
            val = static_cast<ArithmeticType>(*j.template get_ptr<const typename BasicJsonType::number_integer_t*>());
            break;
        }
        case value_t::number_float:
        {
            val = static_cast<ArithmeticType>(*j.template get_ptr<const typename BasicJsonType::number_float_t*>());
            break;
        }
        case value_t::null:
        case value_t::object:
        case value_t::array:
        case value_t::string:
        case value_t::boolean:
        case value_t::binary:
        case value_t::discarded:
        default:
            JSON_THROW(type_error::create(302, concat("type must be number, but is ", j.type_name()), &j));
    }
}
template<typename BasicJsonType>
inline void from_json(const BasicJsonType& j, typename BasicJsonType::boolean_t& b)
{
    if (JSON_HEDLEY_UNLIKELY(!j.is_boolean()))
    {
        JSON_THROW(type_error::create(302, concat("type must be boolean, but is ", j.type_name()), &j));
    }
    b = *j.template get_ptr<const typename BasicJsonType::boolean_t*>();
}
template<typename BasicJsonType>
inline void from_json(const BasicJsonType& j, typename BasicJsonType::string_t& s)
{
    if (JSON_HEDLEY_UNLIKELY(!j.is_string()))
    {
        JSON_THROW(type_error::create(302, concat("type must be string, but is ", j.type_name()), &j));
    }
    s = *j.template get_ptr<const typename BasicJsonType::string_t*>();
}
template <
    typename BasicJsonType, typename StringType,
    enable_if_t <
        std::is_assignable<StringType&, const typename BasicJsonType::string_t>::value
        && is_detected_exact<typename BasicJsonType::string_t::value_type, value_type_t, StringType>::value
        && !std::is_same<typename BasicJsonType::string_t, StringType>::value
        && !is_json_ref<StringType>::value, int > = 0 >
inline void from_json(const BasicJsonType& j, StringType& s)
{
    if (JSON_HEDLEY_UNLIKELY(!j.is_string()))
    {
        JSON_THROW(type_error::create(302, concat("type must be string, but is ", j.type_name()), &j));
    }
    s = *j.template get_ptr<const typename BasicJsonType::string_t*>();
}
template<typename BasicJsonType>
inline void from_json(const BasicJsonType& j, typename BasicJsonType::number_float_t& val)
{
    get_arithmetic_value(j, val);
}
template<typename BasicJsonType>
inline void from_json(const BasicJsonType& j, typename BasicJsonType::number_unsigned_t& val)
{
    get_arithmetic_value(j, val);
}
template<typename BasicJsonType>
inline void from_json(const BasicJsonType& j, typename BasicJsonType::number_integer_t& val)
{
    get_arithmetic_value(j, val);
}
#if !JSON_DISABLE_ENUM_SERIALIZATION
template<typename BasicJsonType, typename EnumType,
         enable_if_t<std::is_enum<EnumType>::value, int> = 0>
inline void from_json(const BasicJsonType& j, EnumType& e)
{
    using underlying_type = typename std::underlying_type<EnumType>::type;
    using value_type = typename std::conditional<std::is_same<underlying_type, typename BasicJsonType::boolean_t>::value,
          typename BasicJsonType::number_unsigned_t, underlying_type>::type;
    value_type val;
    get_arithmetic_value(j, val);
    e = static_cast<EnumType>(static_cast<underlying_type>(val));
}
#endif  
template<typename BasicJsonType, typename T, typename Allocator,
         enable_if_t<is_getable<BasicJsonType, T>::value, int> = 0>
inline void from_json(const BasicJsonType& j, std::forward_list<T, Allocator>& l)
{
    if (JSON_HEDLEY_UNLIKELY(!j.is_array()))
    {
        JSON_THROW(type_error::create(302, concat("type must be array, but is ", j.type_name()), &j));
    }
    l.clear();
    std::transform(j.rbegin(), j.rend(),
                   std::front_inserter(l), [](const BasicJsonType & i)
    {
        return i.template get<T>();
    });
}
template<typename BasicJsonType, typename T,
         enable_if_t<is_getable<BasicJsonType, T>::value, int> = 0>
inline void from_json(const BasicJsonType& j, std::valarray<T>& l)
{
    if (JSON_HEDLEY_UNLIKELY(!j.is_array()))
    {
        JSON_THROW(type_error::create(302, concat("type must be array, but is ", j.type_name()), &j));
    }
    l.resize(j.size());
    std::transform(j.begin(), j.end(), std::begin(l),
                   [](const BasicJsonType & elem)
    {
        return elem.template get<T>();
    });
}
template<typename BasicJsonType, typename T, std::size_t N>
auto from_json(const BasicJsonType& j, T (&arr)[N])  
-> decltype(j.template get<T>(), void())
{
    for (std::size_t i = 0; i < N; ++i)
    {
        arr[i] = j.at(i).template get<T>();
    }
}
template<typename BasicJsonType, typename T, std::size_t N1, std::size_t N2>
auto from_json(const BasicJsonType& j, T (&arr)[N1][N2])  
-> decltype(j.template get<T>(), void())
{
    for (std::size_t i1 = 0; i1 < N1; ++i1)
    {
        for (std::size_t i2 = 0; i2 < N2; ++i2)
        {
            arr[i1][i2] = j.at(i1).at(i2).template get<T>();
        }
    }
}
template<typename BasicJsonType, typename T, std::size_t N1, std::size_t N2, std::size_t N3>
auto from_json(const BasicJsonType& j, T (&arr)[N1][N2][N3])  
-> decltype(j.template get<T>(), void())
{
    for (std::size_t i1 = 0; i1 < N1; ++i1)
    {
        for (std::size_t i2 = 0; i2 < N2; ++i2)
        {
            for (std::size_t i3 = 0; i3 < N3; ++i3)
            {
                arr[i1][i2][i3] = j.at(i1).at(i2).at(i3).template get<T>();
            }
        }
    }
}
template<typename BasicJsonType, typename T, std::size_t N1, std::size_t N2, std::size_t N3, std::size_t N4>
auto from_json(const BasicJsonType& j, T (&arr)[N1][N2][N3][N4])  
-> decltype(j.template get<T>(), void())
{
    for (std::size_t i1 = 0; i1 < N1; ++i1)
    {
        for (std::size_t i2 = 0; i2 < N2; ++i2)
        {
            for (std::size_t i3 = 0; i3 < N3; ++i3)
            {
                for (std::size_t i4 = 0; i4 < N4; ++i4)
                {
                    arr[i1][i2][i3][i4] = j.at(i1).at(i2).at(i3).at(i4).template get<T>();
                }
            }
        }
    }
}
template<typename BasicJsonType>
inline void from_json_array_impl(const BasicJsonType& j, typename BasicJsonType::array_t& arr, priority_tag<3> )
{
    arr = *j.template get_ptr<const typename BasicJsonType::array_t*>();
}
template<typename BasicJsonType, typename T, std::size_t N>
auto from_json_array_impl(const BasicJsonType& j, std::array<T, N>& arr,
                          priority_tag<2> )
-> decltype(j.template get<T>(), void())
{
    for (std::size_t i = 0; i < N; ++i)
    {
        arr[i] = j.at(i).template get<T>();
    }
}
template<typename BasicJsonType, typename ConstructibleArrayType,
         enable_if_t<
             std::is_assignable<ConstructibleArrayType&, ConstructibleArrayType>::value,
             int> = 0>
auto from_json_array_impl(const BasicJsonType& j, ConstructibleArrayType& arr, priority_tag<1> )
-> decltype(
    arr.reserve(std::declval<typename ConstructibleArrayType::size_type>()),
    j.template get<typename ConstructibleArrayType::value_type>(),
    void())
{
    using std::end;
    ConstructibleArrayType ret;
    ret.reserve(j.size());
    std::transform(j.begin(), j.end(),
                   std::inserter(ret, end(ret)), [](const BasicJsonType & i)
    {
        return i.template get<typename ConstructibleArrayType::value_type>();
    });
    arr = std::move(ret);
}
template<typename BasicJsonType, typename ConstructibleArrayType,
         enable_if_t<
             std::is_assignable<ConstructibleArrayType&, ConstructibleArrayType>::value,
             int> = 0>
inline void from_json_array_impl(const BasicJsonType& j, ConstructibleArrayType& arr,
                                 priority_tag<0> )
{
    using std::end;
    ConstructibleArrayType ret;
    std::transform(
        j.begin(), j.end(), std::inserter(ret, end(ret)),
        [](const BasicJsonType & i)
    {
        return i.template get<typename ConstructibleArrayType::value_type>();
    });
    arr = std::move(ret);
}
template < typename BasicJsonType, typename ConstructibleArrayType,
           enable_if_t <
               is_constructible_array_type<BasicJsonType, ConstructibleArrayType>::value&&
               !is_constructible_object_type<BasicJsonType, ConstructibleArrayType>::value&&
               !is_constructible_string_type<BasicJsonType, ConstructibleArrayType>::value&&
               !std::is_same<ConstructibleArrayType, typename BasicJsonType::binary_t>::value&&
               !is_compatible_binary_type<BasicJsonType, ConstructibleArrayType>::value&&
               !is_basic_json<ConstructibleArrayType>::value,
               int > = 0 >
auto from_json(const BasicJsonType& j, ConstructibleArrayType& arr)
-> decltype(from_json_array_impl(j, arr, priority_tag<3> {}),
j.template get<typename ConstructibleArrayType::value_type>(),
void())
{
    if (JSON_HEDLEY_UNLIKELY(!j.is_array()))
    {
        JSON_THROW(type_error::create(302, concat("type must be array, but is ", j.type_name()), &j));
    }
    from_json_array_impl(j, arr, priority_tag<3> {});
}
template < typename BasicJsonType, typename T, std::size_t... Idx >
std::array<T, sizeof...(Idx)> from_json_inplace_array_impl(const BasicJsonType& j,
                     identity_tag<std::array<T, sizeof...(Idx)>> , index_sequence<Idx...> )
{
    return { { j.at(Idx).template get<T>()... } };
}
template < typename BasicJsonType, typename T, std::size_t N >
auto from_json(const BasicJsonType& j, identity_tag<std::array<T, N>> tag)
-> decltype(from_json_inplace_array_impl(j, tag, make_index_sequence<N> {}))
{
    if (JSON_HEDLEY_UNLIKELY(!j.is_array()))
    {
        JSON_THROW(type_error::create(302, concat("type must be array, but is ", j.type_name()), &j));
    }
    return from_json_inplace_array_impl(j, tag, make_index_sequence<N> {});
}
template<typename BasicJsonType>
inline void from_json(const BasicJsonType& j, typename BasicJsonType::binary_t& bin)
{
    if (JSON_HEDLEY_UNLIKELY(!j.is_binary()))
    {
        JSON_THROW(type_error::create(302, concat("type must be binary, but is ", j.type_name()), &j));
    }
    bin = *j.template get_ptr<const typename BasicJsonType::binary_t*>();
}
template < typename BasicJsonType, typename CompatibleArrayType,
           enable_if_t < is_compatible_binary_type<BasicJsonType, CompatibleArrayType>::value,
                         int > = 0 >
inline void from_json(const BasicJsonType& j, CompatibleArrayType& bin)
{
    if (j.is_binary())
    {
        bin = static_cast<CompatibleArrayType>(*j.template get_ptr<const typename BasicJsonType::binary_t*>());
    }
    else if (j.is_array())
    {
        from_json_array_impl(j, bin, priority_tag<3> {});
    }
    else
    {
        JSON_THROW(type_error::create(302, concat("type must be binary or array, but is ", j.type_name()), &j));
    }
}
template<typename ConstructibleObjectType>
auto from_json_object_reserve(ConstructibleObjectType& obj, typename ConstructibleObjectType::size_type size, priority_tag<1> )
-> decltype(obj.reserve(size), void())
{
    obj.reserve(size);
}
template<typename ConstructibleObjectType>
inline void from_json_object_reserve(ConstructibleObjectType& , std::size_t , priority_tag<0> )
{}
template<typename BasicJsonType, typename ConstructibleObjectType,
         enable_if_t<is_constructible_object_type<BasicJsonType, ConstructibleObjectType>::value, int> = 0>
inline void from_json(const BasicJsonType& j, ConstructibleObjectType& obj)
{
    if (JSON_HEDLEY_UNLIKELY(!j.is_object()))
    {
        JSON_THROW(type_error::create(302, concat("type must be object, but is ", j.type_name()), &j));
    }
    ConstructibleObjectType ret;
    const auto* inner_object = j.template get_ptr<const typename BasicJsonType::object_t*>();
    from_json_object_reserve(ret, inner_object->size(), priority_tag<1> {});
    for (const auto& p : *inner_object)
    {
        ret.emplace(p.first, p.second.template get<typename ConstructibleObjectType::mapped_type>());
    }
    obj = std::move(ret);
}
template < typename BasicJsonType, typename ArithmeticType,
           enable_if_t <
               std::is_arithmetic<ArithmeticType>::value&&
               !std::is_same<ArithmeticType, typename BasicJsonType::number_unsigned_t>::value&&
               !std::is_same<ArithmeticType, typename BasicJsonType::number_integer_t>::value&&
               !std::is_same<ArithmeticType, typename BasicJsonType::number_float_t>::value&&
               !std::is_same<ArithmeticType, typename BasicJsonType::boolean_t>::value,
               int > = 0 >
inline void from_json(const BasicJsonType& j, ArithmeticType& val)
{
    switch (static_cast<value_t>(j))
    {
        case value_t::number_unsigned:
        {
            val = static_cast<ArithmeticType>(*j.template get_ptr<const typename BasicJsonType::number_unsigned_t*>());
            break;
        }
        case value_t::number_integer:
        {
            val = static_cast<ArithmeticType>(*j.template get_ptr<const typename BasicJsonType::number_integer_t*>());
            break;
        }
        case value_t::number_float:
        {
            val = static_cast<ArithmeticType>(*j.template get_ptr<const typename BasicJsonType::number_float_t*>());
            break;
        }
        case value_t::boolean:
        {
            val = static_cast<ArithmeticType>(*j.template get_ptr<const typename BasicJsonType::boolean_t*>());
            break;
        }
        case value_t::null:
        case value_t::object:
        case value_t::array:
        case value_t::string:
        case value_t::binary:
        case value_t::discarded:
        default:
            JSON_THROW(type_error::create(302, concat("type must be number, but is ", j.type_name()), &j));
    }
}
template<typename BasicJsonType, typename Type>
detail::uncvref_t<Type> from_json_tuple_get_impl(BasicJsonType&& j, detail::identity_tag<Type> , detail::priority_tag<0> )
{
    return std::forward<BasicJsonType>(j).template get<detail::uncvref_t<Type>>();
}
template<typename BasicJsonType, typename Type,
         detail::enable_if_t<detail::is_compatible_reference_type<BasicJsonType, Type>::value, int> = 0>
Type from_json_tuple_get_impl(BasicJsonType && j, detail::identity_tag<Type> , detail::priority_tag<1> )
{
    return std::forward<BasicJsonType>(j).template get_ref<Type>();
}
template<typename BasicJsonType, typename Type,
         detail::enable_if_t<std::is_arithmetic<uncvref_t<Type>>::value, int> = 0>
detail::uncvref_t<Type> from_json_tuple_get_impl(BasicJsonType && j, detail::identity_tag<Type> , detail::priority_tag<2> )
{
    return std::forward<BasicJsonType>(j).template get<detail::uncvref_t<Type>>();
}
template<std::size_t PTagValue, typename BasicJsonType, typename... Types>
using tuple_type = std::tuple < decltype(from_json_tuple_get_impl(std::declval<BasicJsonType>(), detail::identity_tag<Types> {}, detail::priority_tag<PTagValue> {}))... >;
template<std::size_t PTagValue, typename... Args, typename BasicJsonType, std::size_t... Idx>
tuple_type<PTagValue, const BasicJsonType&, Args...> from_json_tuple_impl_base(const BasicJsonType& j, index_sequence<Idx...> )
{
    return tuple_type<PTagValue, const BasicJsonType&, Args...>(from_json_tuple_get_impl(j.at(Idx), detail::identity_tag<Args> {}, detail::priority_tag<PTagValue> {})...);
}
template<std::size_t PTagValue, typename BasicJsonType>
std::tuple<> from_json_tuple_impl_base(const BasicJsonType& , index_sequence<> )
{
    return {};
}
template < typename BasicJsonType, class A1, class A2 >
std::pair<A1, A2> from_json_tuple_impl(const BasicJsonType& j, identity_tag<std::pair<A1, A2>> , priority_tag<0> )
{
    return {j.at(0).template get<A1>(),
            j.at(1).template get<A2>()};
}
template<typename BasicJsonType, typename A1, typename A2>
inline void from_json_tuple_impl(const BasicJsonType& j, std::pair<A1, A2>& p, priority_tag<1> )
{
    p = from_json_tuple_impl(j, identity_tag<std::pair<A1, A2>> {}, priority_tag<0> {});
}
template<typename BasicJsonType, typename... Args>
std::tuple<Args...> from_json_tuple_impl(const BasicJsonType& j, identity_tag<std::tuple<Args...>> , priority_tag<2> )
{
    static_assert(cxpr_and<cxpr_or<cxpr_not<std::is_reference<Args>>, is_compatible_reference_type<const BasicJsonType&, Args>>...>::value,
                  "Can not return a tuple containing references to types not contained in a Json, try Json::get_to()");
    return from_json_tuple_impl_base<1, Args...>(j, index_sequence_for<Args...> {});
}
template<typename BasicJsonType, typename... Args>
inline void from_json_tuple_impl(const BasicJsonType& j, std::tuple<Args...>& t, priority_tag<3> )
{
    t = from_json_tuple_impl_base<2, Args...>(j, index_sequence_for<Args...> {});
}
template<typename BasicJsonType, typename TupleRelated>
auto from_json(const BasicJsonType& j, TupleRelated&& t)
-> decltype(from_json_tuple_impl(j, std::forward<TupleRelated>(t), priority_tag<3> {}))
{
    if (JSON_HEDLEY_UNLIKELY(!j.is_array()))
    {
        JSON_THROW(type_error::create(302, concat("type must be array, but is ", j.type_name()), &j));
    }
    return from_json_tuple_impl(j, std::forward<TupleRelated>(t), priority_tag<3> {});
}
template < typename BasicJsonType, typename Key, typename Value, typename Compare, typename Allocator,
           typename = enable_if_t < !std::is_constructible <
                                        typename BasicJsonType::string_t, Key >::value >>
inline void from_json(const BasicJsonType& j, std::map<Key, Value, Compare, Allocator>& m)
{
    if (JSON_HEDLEY_UNLIKELY(!j.is_array()))
    {
        JSON_THROW(type_error::create(302, concat("type must be array, but is ", j.type_name()), &j));
    }
    m.clear();
    for (const auto& p : j)
    {
        if (JSON_HEDLEY_UNLIKELY(!p.is_array()))
        {
            JSON_THROW(type_error::create(302, concat("type must be array, but is ", p.type_name()), &p));
        }
        m.emplace(p.at(0).template get<Key>(), p.at(1).template get<Value>());
    }
}
template < typename BasicJsonType, typename Key, typename Value, typename Hash, typename KeyEqual, typename Allocator,
           typename = enable_if_t < !std::is_constructible <
                                        typename BasicJsonType::string_t, Key >::value >>
inline void from_json(const BasicJsonType& j, std::unordered_map<Key, Value, Hash, KeyEqual, Allocator>& m)
{
    if (JSON_HEDLEY_UNLIKELY(!j.is_array()))
    {
        JSON_THROW(type_error::create(302, concat("type must be array, but is ", j.type_name()), &j));
    }
    m.clear();
    for (const auto& p : j)
    {
        if (JSON_HEDLEY_UNLIKELY(!p.is_array()))
        {
            JSON_THROW(type_error::create(302, concat("type must be array, but is ", p.type_name()), &p));
        }
        m.emplace(p.at(0).template get<Key>(), p.at(1).template get<Value>());
    }
}
#if JSON_HAS_FILESYSTEM || JSON_HAS_EXPERIMENTAL_FILESYSTEM
template<typename BasicJsonType>
struct has_from_json<BasicJsonType, std_fs::path, void> : std::true_type {};
template<typename BasicJsonType>
inline void from_json(const BasicJsonType& j, std_fs::path& p)
{
    if (JSON_HEDLEY_UNLIKELY(!j.is_string()))
    {
        JSON_THROW(type_error::create(302, concat("type must be string, but is ", j.type_name()), &j));
    }
    const auto& s = *j.template get_ptr<const typename BasicJsonType::string_t*>();
#if defined(__cpp_lib_char8_t) && (__cpp_lib_char8_t >= 201907L)
    p = std_fs::path(std::u8string_view(reinterpret_cast<const char8_t*>(s.data()), s.size()));
#else
    p = std_fs::u8path(s); 
#endif
}
#endif
struct from_json_fn
{
    template<typename BasicJsonType, typename T>
    auto operator()(const BasicJsonType& j, T&& val) const
    noexcept(noexcept(from_json(j, std::forward<T>(val))))
    -> decltype(from_json(j, std::forward<T>(val)))
    {
        return from_json(j, std::forward<T>(val));
    }
};
}  
#ifndef JSON_HAS_CPP_17
namespace 
{
#endif
JSON_INLINE_VARIABLE constexpr const auto& from_json = 
    detail::static_const<detail::from_json_fn>::value;
#ifndef JSON_HAS_CPP_17
}  
#endif
NLOHMANN_JSON_NAMESPACE_END
#ifdef JSON_HAS_CPP_17
    #include <optional> 
#endif
#include <algorithm> 
#include <iterator> 
#include <memory> 
#include <string> 
#include <tuple> 
#include <type_traits> 
#include <utility> 
#include <valarray> 
#include <vector> 
#include <cstddef> 
#include <iterator> 
#include <tuple> 
#include <utility> 
#if JSON_HAS_RANGES
    #include <ranges> 
#endif
#include <array> 
#include <cstddef> 
#include <cstdint> 
#include <string> 
NLOHMANN_JSON_NAMESPACE_BEGIN
namespace detail
{
template<typename StringType>
void int_to_string(StringType& target, std::size_t value)
{
    using std::to_string;
    target = to_string(value);
}
template<typename StringType>
StringType to_string(std::size_t value)
{
    StringType result;
    int_to_string(result, value);
    return result;
}
inline std::string hex_byte(const std::uint8_t byte)
{
    std::string result = "00";
    constexpr const char* nibble_to_hex = "0123456789ABCDEF";
    result[0] = nibble_to_hex[byte / 16];
    result[1] = nibble_to_hex[byte % 16];
    return result;
}
template<typename Out>
void encode_utf8(std::uint32_t cp, const Out& out)
{
    JSON_ASSERT(cp <= 0x10FFFF);
    if (cp < 0x80)
    {
        out(cp);
    }
    else if (cp <= 0x7FF)
    {
        out(0xC0u | (cp >> 6u));
        out(0x80u | (cp & 0x3Fu));
    }
    else if (cp <= 0xFFFF)
    {
        out(0xE0u | (cp >> 12u));
        out(0x80u | ((cp >> 6u) & 0x3Fu));
        out(0x80u | (cp & 0x3Fu));
    }
    else
    {
        out(0xF0u | (cp >> 18u));
        out(0x80u | ((cp >> 12u) & 0x3Fu));
        out(0x80u | ((cp >> 6u) & 0x3Fu));
        out(0x80u | (cp & 0x3Fu));
    }
}
static constexpr std::uint8_t UTF8_ACCEPT = 0;
static constexpr std::uint8_t UTF8_REJECT = 1;
inline std::uint8_t decode(std::uint8_t& state, std::uint32_t& codep, const std::uint8_t byte) noexcept
{
    static const std::array<std::uint8_t, 400> utf8d =
    {
        {
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 
            7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 
            8, 8, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 
            0xA, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x3, 
            0xB, 0x6, 0x6, 0x6, 0x5, 0x8, 0x8, 0x8, 0x8, 0x8, 0x8, 0x8, 0x8, 0x8, 0x8, 0x8, 
            0x0, 0x1, 0x2, 0x3, 0x5, 0x8, 0x7, 0x1, 0x1, 0x1, 0x4, 0x6, 0x1, 0x1, 0x1, 0x1, 
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 
            1, 2, 1, 1, 1, 1, 1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 
            1, 2, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 3, 1, 1, 1, 1, 1, 1, 
            1, 3, 1, 1, 1, 1, 1, 3, 1, 3, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 
        }
    };
    JSON_ASSERT(static_cast<std::size_t>(byte) < utf8d.size());
    const std::uint8_t type = utf8d[byte];
    codep = (state != UTF8_ACCEPT)
            ? (byte & 0x3fu) | (codep << 6u)
            : (0xFFu >> type) & (byte);
    const std::size_t index = 256u + (static_cast<std::size_t>(state) * 16u) + static_cast<std::size_t>(type);
    JSON_ASSERT(index < utf8d.size());
    state = utf8d[index];
    return state;
}
template<typename StringType>
inline bool is_valid_utf8(const StringType& s, const std::size_t first = 0) noexcept
{
    std::uint8_t state = UTF8_ACCEPT;
    std::uint32_t codepoint = 0;
    for (std::size_t i = first; i < s.size(); ++i)
    {
        decode(state, codepoint, static_cast<std::uint8_t>(s[i]));
        if (state == UTF8_REJECT)
        {
            return false;
        }
    }
    return state == UTF8_ACCEPT;
}
}  
NLOHMANN_JSON_NAMESPACE_END
NLOHMANN_JSON_NAMESPACE_BEGIN
namespace detail
{
template<typename IteratorType> class iteration_proxy_value
{
  public:
    using difference_type = std::ptrdiff_t;
    using value_type = iteration_proxy_value;
    using pointer = value_type *;
    using reference = value_type &;
    using iterator_category = std::forward_iterator_tag;
    using string_type = typename std::remove_cv< typename std::remove_reference<decltype( std::declval<IteratorType>().key() ) >::type >::type;
  private:
    IteratorType anchor{};
    std::size_t array_index = 0;
    mutable std::size_t array_index_last = 0;
    mutable string_type array_index_str = "0";
    string_type empty_str{};
  public:
    explicit iteration_proxy_value() = default;
    explicit iteration_proxy_value(IteratorType it, std::size_t array_index_ = 0)
    noexcept(std::is_nothrow_move_constructible<IteratorType>::value
             && std::is_nothrow_default_constructible<string_type>::value)
        : anchor(std::move(it))
        , array_index(array_index_)
    {}
    iteration_proxy_value(iteration_proxy_value const&) = default;
    iteration_proxy_value& operator=(iteration_proxy_value const&) = default;
    iteration_proxy_value(iteration_proxy_value&&)
    noexcept(std::is_nothrow_move_constructible<IteratorType>::value
             && std::is_nothrow_move_constructible<string_type>::value) = default; 
    iteration_proxy_value& operator=(iteration_proxy_value&&)
    noexcept(std::is_nothrow_move_assignable<IteratorType>::value
             && std::is_nothrow_move_assignable<string_type>::value) = default; 
    ~iteration_proxy_value() = default;
    const iteration_proxy_value& operator*() const
    {
        return *this;
    }
    iteration_proxy_value& operator++()
    {
        ++anchor;
        ++array_index;
        return *this;
    }
    iteration_proxy_value operator++(int)& 
    {
        auto tmp = iteration_proxy_value(anchor, array_index);
        ++anchor;
        ++array_index;
        return tmp;
    }
    bool operator==(const iteration_proxy_value& o) const
    {
        return anchor == o.anchor;
    }
    bool operator!=(const iteration_proxy_value& o) const
    {
        return anchor != o.anchor;
    }
    const string_type& key() const
    {
        JSON_ASSERT(anchor.m_object != nullptr);
        switch (anchor.m_object->type())
        {
            case value_t::array:
            {
                if (array_index != array_index_last)
                {
                    int_to_string( array_index_str, array_index );
                    array_index_last = array_index;
                }
                return array_index_str;
            }
            case value_t::object:
                return anchor.key();
            case value_t::null:
            case value_t::string:
            case value_t::boolean:
            case value_t::number_integer:
            case value_t::number_unsigned:
            case value_t::number_float:
            case value_t::binary:
            case value_t::discarded:
            default:
                return empty_str;
        }
    }
    typename IteratorType::reference value() const
    {
        return anchor.value();
    }
};
template<typename IteratorType> class iteration_proxy
{
  private:
    typename IteratorType::pointer container = nullptr;
  public:
    explicit iteration_proxy() = default;
    explicit iteration_proxy(typename IteratorType::reference cont) noexcept
        : container(&cont) {}
    iteration_proxy(iteration_proxy const&) = default;
    iteration_proxy& operator=(iteration_proxy const&) = default;
    iteration_proxy(iteration_proxy&&) noexcept = default;
    iteration_proxy& operator=(iteration_proxy&&) noexcept = default;
    ~iteration_proxy() = default;
    iteration_proxy_value<IteratorType> begin() const noexcept
    {
        return iteration_proxy_value<IteratorType>(container->begin());
    }
    iteration_proxy_value<IteratorType> end() const noexcept
    {
        return iteration_proxy_value<IteratorType>(container->end());
    }
};
template<std::size_t N, typename IteratorType, enable_if_t<N == 0, int> = 0>
auto get(const nlohmann::detail::iteration_proxy_value<IteratorType>& i) -> decltype(i.key())
{
    return i.key();
}
template<std::size_t N, typename IteratorType, enable_if_t<N == 1, int> = 0>
auto get(const nlohmann::detail::iteration_proxy_value<IteratorType>& i) -> decltype(i.value())
{
    return i.value();
}
}  
NLOHMANN_JSON_NAMESPACE_END
namespace std
{
#if defined(__clang__)
    JSON_HEDLEY_DIAGNOSTIC_PUSH
    JSON_HEDLEY_PRAGMA(clang diagnostic ignored "-Wmismatched-tags")
#endif
template<typename IteratorType>
class tuple_size<::nlohmann::detail::iteration_proxy_value<IteratorType>> 
    : public std::integral_constant<std::size_t, 2> {};
template<std::size_t N, typename IteratorType>
class tuple_element<N, ::nlohmann::detail::iteration_proxy_value<IteratorType >> 
{
  public:
    using type = decltype(
                     get<N>(std::declval <
                            ::nlohmann::detail::iteration_proxy_value<IteratorType >> ()));
};
#if defined(__clang__)
    JSON_HEDLEY_DIAGNOSTIC_POP
#endif
}  
#if JSON_HAS_RANGES
    template <typename IteratorType>
    inline constexpr bool ::std::ranges::enable_borrowed_range<::nlohmann::detail::iteration_proxy<IteratorType>> = true;
#endif
NLOHMANN_JSON_NAMESPACE_BEGIN
namespace detail
{
template<value_t> struct external_constructor;
template<>
struct external_constructor<value_t::boolean>
{
    template<typename BasicJsonType>
    static void construct(BasicJsonType& j, typename BasicJsonType::boolean_t b) noexcept
    {
        j.m_data.m_value.destroy(j.m_data.m_type);
        j.m_data.m_type = value_t::boolean;
        j.m_data.m_value = b;
        j.assert_invariant();
    }
};
template<>
struct external_constructor<value_t::string>
{
    template<typename BasicJsonType>
    static void construct(BasicJsonType& j, const typename BasicJsonType::string_t& s)
    {
        j.m_data.m_value.destroy(j.m_data.m_type);
        j.m_data.m_type = value_t::string;
        j.m_data.m_value = s;
        j.assert_invariant();
    }
    template<typename BasicJsonType>
    static void construct(BasicJsonType& j, typename BasicJsonType::string_t&& s)
    {
        j.m_data.m_value.destroy(j.m_data.m_type);
        j.m_data.m_type = value_t::string;
        j.m_data.m_value = std::move(s);
        j.assert_invariant();
    }
    template < typename BasicJsonType, typename CompatibleStringType,
               enable_if_t < !std::is_same<CompatibleStringType, typename BasicJsonType::string_t>::value,
                             int > = 0 >
    static void construct(BasicJsonType& j, const CompatibleStringType& str)
    {
        j.m_data.m_value.destroy(j.m_data.m_type);
        j.m_data.m_type = value_t::string;
        j.m_data.m_value.string = j.template create<typename BasicJsonType::string_t>(str);
        j.assert_invariant();
    }
};
template<>
struct external_constructor<value_t::binary>
{
    template<typename BasicJsonType>
    static void construct(BasicJsonType& j, const typename BasicJsonType::binary_t& b)
    {
        j.m_data.m_value.destroy(j.m_data.m_type);
        j.m_data.m_type = value_t::binary;
        j.m_data.m_value = typename BasicJsonType::binary_t(b);
        j.assert_invariant();
    }
    template<typename BasicJsonType>
    static void construct(BasicJsonType& j, typename BasicJsonType::binary_t&& b)
    {
        j.m_data.m_value.destroy(j.m_data.m_type);
        j.m_data.m_type = value_t::binary;
        j.m_data.m_value = typename BasicJsonType::binary_t(std::move(b));
        j.assert_invariant();
    }
};
template<>
struct external_constructor<value_t::number_float>
{
    template<typename BasicJsonType>
    static void construct(BasicJsonType& j, typename BasicJsonType::number_float_t val) noexcept
    {
        j.m_data.m_value.destroy(j.m_data.m_type);
        j.m_data.m_type = value_t::number_float;
        j.m_data.m_value = val;
        j.assert_invariant();
    }
};
template<>
struct external_constructor<value_t::number_unsigned>
{
    template<typename BasicJsonType>
    static void construct(BasicJsonType& j, typename BasicJsonType::number_unsigned_t val) noexcept
    {
        j.m_data.m_value.destroy(j.m_data.m_type);
        j.m_data.m_type = value_t::number_unsigned;
        j.m_data.m_value = val;
        j.assert_invariant();
    }
};
template<>
struct external_constructor<value_t::number_integer>
{
    template<typename BasicJsonType>
    static void construct(BasicJsonType& j, typename BasicJsonType::number_integer_t val) noexcept
    {
        j.m_data.m_value.destroy(j.m_data.m_type);
        j.m_data.m_type = value_t::number_integer;
        j.m_data.m_value = val;
        j.assert_invariant();
    }
};
template<>
struct external_constructor<value_t::array>
{
    template<typename BasicJsonType>
    static void construct(BasicJsonType& j, const typename BasicJsonType::array_t& arr)
    {
        j.m_data.m_value.destroy(j.m_data.m_type);
        j.m_data.m_type = value_t::array;
        j.m_data.m_value = arr;
        j.set_parents();
        j.assert_invariant();
    }
    template<typename BasicJsonType>
    static void construct(BasicJsonType& j, typename BasicJsonType::array_t&& arr)
    {
        j.m_data.m_value.destroy(j.m_data.m_type);
        j.m_data.m_type = value_t::array;
        j.m_data.m_value = std::move(arr);
        j.set_parents();
        j.assert_invariant();
    }
    template < typename BasicJsonType, typename CompatibleArrayType,
               enable_if_t < !std::is_same<CompatibleArrayType, typename BasicJsonType::array_t>::value
#if JSON_HAS_RANGES && !defined(__MINGW32__)
                             && !is_compatible_range_view<CompatibleArrayType>::value
#endif
                             , int > = 0 >
    static void construct(BasicJsonType& j, const CompatibleArrayType& arr)
    {
        using std::begin;
        using std::end;
        j.m_data.m_value.destroy(j.m_data.m_type);
        j.m_data.m_type = value_t::array;
        j.m_data.m_value.array = j.template create<typename BasicJsonType::array_t>(begin(arr), end(arr));
        j.set_parents();
        j.assert_invariant();
    }
    template<typename BasicJsonType>
    static void construct(BasicJsonType& j, const std::vector<bool>& arr)
    {
        j.m_data.m_value.destroy(j.m_data.m_type);
        j.m_data.m_type = value_t::array;
        j.m_data.m_value = value_t::array;
        j.m_data.m_value.array->reserve(arr.size());
        for (const bool x : arr)
        {
            j.m_data.m_value.array->push_back(x);
            j.set_parent(j.m_data.m_value.array->back());
        }
        j.assert_invariant();
    }
    template<typename BasicJsonType, typename T,
             enable_if_t<std::is_convertible<T, BasicJsonType>::value, int> = 0>
    static void construct(BasicJsonType& j, const std::valarray<T>& arr)
    {
        j.m_data.m_value.destroy(j.m_data.m_type);
        j.m_data.m_type = value_t::array;
        j.m_data.m_value = value_t::array;
        j.m_data.m_value.array->resize(arr.size());
        std::copy(std::begin(arr), std::end(arr), j.m_data.m_value.array->begin());
        j.set_parents();
        j.assert_invariant();
    }
#if JSON_HAS_RANGES && !defined(__MINGW32__)
    template<typename BasicJsonType, typename CompatibleArrayType,
             enable_if_t<is_compatible_range_view<std::remove_cvref_t<CompatibleArrayType>>::value, int> = 0>
    static void construct(BasicJsonType& j, CompatibleArrayType && arr)
    {
        j.m_data.m_value.destroy(j.m_data.m_type);
        j.m_data.m_type = value_t::array;
        j.m_data.m_value = value_t::array;
        for (auto&& x : std::forward<CompatibleArrayType>(arr))
        {
            j.m_data.m_value.array->push_back(x);
        }
        j.set_parents();
        j.assert_invariant();
    }
#endif
};
template<>
struct external_constructor<value_t::object>
{
    template<typename BasicJsonType>
    static void construct(BasicJsonType& j, const typename BasicJsonType::object_t& obj)
    {
        j.m_data.m_value.destroy(j.m_data.m_type);
        j.m_data.m_type = value_t::object;
        j.m_data.m_value = obj;
        j.set_parents();
        j.assert_invariant();
    }
    template<typename BasicJsonType>
    static void construct(BasicJsonType& j, typename BasicJsonType::object_t&& obj)
    {
        j.m_data.m_value.destroy(j.m_data.m_type);
        j.m_data.m_type = value_t::object;
        j.m_data.m_value = std::move(obj);
        j.set_parents();
        j.assert_invariant();
    }
    template < typename BasicJsonType, typename CompatibleObjectType,
               enable_if_t < !std::is_same<CompatibleObjectType, typename BasicJsonType::object_t>::value, int > = 0 >
    static void construct(BasicJsonType& j, const CompatibleObjectType& obj)
    {
        using std::begin;
        using std::end;
        j.m_data.m_value.destroy(j.m_data.m_type);
        j.m_data.m_type = value_t::object;
        j.m_data.m_value.object = j.template create<typename BasicJsonType::object_t>(begin(obj), end(obj));
        j.set_parents();
        j.assert_invariant();
    }
};
#ifdef JSON_HAS_CPP_17
template<typename BasicJsonType, typename T,
         enable_if_t<std::is_constructible<BasicJsonType, T>::value, int> = 0>
void to_json(BasicJsonType& j, const std::optional<T>& opt) noexcept(std::is_nothrow_assignable<BasicJsonType&, const T&>::value)
{
    if (opt.has_value())
    {
        j = *opt;
    }
    else
    {
        j = nullptr;
    }
}
#endif
template<typename BasicJsonType, typename T,
         enable_if_t<std::is_same<T, typename BasicJsonType::boolean_t>::value, int> = 0>
inline void to_json(BasicJsonType& j, T b) noexcept
{
    external_constructor<value_t::boolean>::construct(j, b);
}
template < typename BasicJsonType, typename BoolRef,
           enable_if_t <
               ((std::is_same<std::vector<bool>::reference, BoolRef>::value
                 && !std::is_same <std::vector<bool>::reference, typename BasicJsonType::boolean_t&>::value)
                || (std::is_same<std::vector<bool>::const_reference, BoolRef>::value
                    && !std::is_same <detail::uncvref_t<std::vector<bool>::const_reference>,
                                      typename BasicJsonType::boolean_t >::value))
               && std::is_convertible<const BoolRef&, typename BasicJsonType::boolean_t>::value, int > = 0 >
inline void to_json(BasicJsonType& j, const BoolRef& b) noexcept
{
    external_constructor<value_t::boolean>::construct(j, static_cast<typename BasicJsonType::boolean_t>(b));
}
template<typename BasicJsonType, typename CompatibleString,
         enable_if_t<std::is_constructible<typename BasicJsonType::string_t, CompatibleString>::value, int> = 0>
inline void to_json(BasicJsonType& j, const CompatibleString& s)
{
    external_constructor<value_t::string>::construct(j, s);
}
template<typename BasicJsonType>
inline void to_json(BasicJsonType& j, typename BasicJsonType::string_t&& s)
{
    external_constructor<value_t::string>::construct(j, std::move(s));
}
template<typename BasicJsonType, typename FloatType,
         enable_if_t<std::is_floating_point<FloatType>::value, int> = 0>
inline void to_json(BasicJsonType& j, FloatType val) noexcept
{
    external_constructor<value_t::number_float>::construct(j, static_cast<typename BasicJsonType::number_float_t>(val));
}
template<typename BasicJsonType, typename CompatibleNumberUnsignedType,
         enable_if_t<is_compatible_integer_type<typename BasicJsonType::number_unsigned_t, CompatibleNumberUnsignedType>::value, int> = 0>
inline void to_json(BasicJsonType& j, CompatibleNumberUnsignedType val) noexcept
{
    external_constructor<value_t::number_unsigned>::construct(j, static_cast<typename BasicJsonType::number_unsigned_t>(val));
}
template<typename BasicJsonType, typename CompatibleNumberIntegerType,
         enable_if_t<is_compatible_integer_type<typename BasicJsonType::number_integer_t, CompatibleNumberIntegerType>::value, int> = 0>
inline void to_json(BasicJsonType& j, CompatibleNumberIntegerType val) noexcept
{
    external_constructor<value_t::number_integer>::construct(j, static_cast<typename BasicJsonType::number_integer_t>(val));
}
#if !JSON_DISABLE_ENUM_SERIALIZATION
template<typename BasicJsonType, typename EnumType,
         enable_if_t<std::is_enum<EnumType>::value, int> = 0>
inline void to_json(BasicJsonType& j, EnumType e) noexcept
{
    using underlying_type = typename std::underlying_type<EnumType>::type;
    static constexpr value_t integral_value_t = std::is_unsigned<underlying_type>::value ? value_t::number_unsigned : value_t::number_integer;
    external_constructor<integral_value_t>::construct(j, static_cast<underlying_type>(e));
}
#endif  
template<typename BasicJsonType>
inline void to_json(BasicJsonType& j, const std::vector<bool>& e)
{
    external_constructor<value_t::array>::construct(j, e);
}
template < typename BasicJsonType, typename CompatibleArrayType,
           enable_if_t < is_compatible_array_type<BasicJsonType,
                         CompatibleArrayType>::value&&
                         !is_compatible_object_type<BasicJsonType, CompatibleArrayType>::value&&
                         !is_compatible_string_type<BasicJsonType, CompatibleArrayType>::value&&
                         !std::is_same<typename BasicJsonType::binary_t, CompatibleArrayType>::value&&
                         !is_compatible_binary_type<BasicJsonType, CompatibleArrayType>::value&&
                         !is_basic_json<CompatibleArrayType>::value
#if JSON_HAS_RANGES && !defined(__MINGW32__)
    && !is_compatible_range_view<CompatibleArrayType>::value
#endif
                         ,
                         int > = 0 >
inline void to_json(BasicJsonType& j, const CompatibleArrayType& arr)
{
    external_constructor<value_t::array>::construct(j, arr);
}
#if JSON_HAS_RANGES && !defined(__MINGW32__)
template < typename BasicJsonType, typename T,
           enable_if_t < is_compatible_range_view<std::remove_cvref_t<T>>::value
                         && !is_compatible_string_type<BasicJsonType, std::remove_cvref_t<T>>::value
                         && !is_compatible_object_type<BasicJsonType, std::remove_cvref_t<T>>::value
                         && !is_basic_json<std::remove_cvref_t<T>>::value, int > = 0 >
inline void to_json(BasicJsonType& j, T && arr)
{
    external_constructor<value_t::array>::construct(j, std::forward<T>(arr));
}
#endif
template<typename BasicJsonType>
inline void to_json(BasicJsonType& j, const typename BasicJsonType::binary_t& bin)
{
    external_constructor<value_t::binary>::construct(j, bin);
}
template < typename BasicJsonType, typename CompatibleArrayType,
           enable_if_t < is_compatible_binary_type<BasicJsonType, CompatibleArrayType>::value,
                         int > = 0 >
inline void to_json(BasicJsonType& j, const CompatibleArrayType& bin)
{
    external_constructor<value_t::binary>::construct(j, typename BasicJsonType::binary_t(bin));
}
template<typename BasicJsonType, typename T,
         enable_if_t<std::is_convertible<T, BasicJsonType>::value, int> = 0>
inline void to_json(BasicJsonType& j, const std::valarray<T>& arr)
{
    external_constructor<value_t::array>::construct(j, std::move(arr));
}
template<typename BasicJsonType>
inline void to_json(BasicJsonType& j, typename BasicJsonType::array_t&& arr)
{
    external_constructor<value_t::array>::construct(j, std::move(arr));
}
template < typename BasicJsonType, typename CompatibleObjectType,
           enable_if_t < is_compatible_object_type<BasicJsonType, CompatibleObjectType>::value&& !is_basic_json<CompatibleObjectType>::value, int > = 0 >
inline void to_json(BasicJsonType& j, const CompatibleObjectType& obj)
{
    external_constructor<value_t::object>::construct(j, obj);
}
template<typename BasicJsonType>
inline void to_json(BasicJsonType& j, typename BasicJsonType::object_t&& obj)
{
    external_constructor<value_t::object>::construct(j, std::move(obj));
}
template <
    typename BasicJsonType, typename T, std::size_t N,
    enable_if_t < !std::is_constructible<typename BasicJsonType::string_t,
                  const T(&)[N]>::value, 
                  int > = 0 >
inline void to_json(BasicJsonType& j, const T(&arr)[N]) 
{
    external_constructor<value_t::array>::construct(j, arr);
}
template < typename BasicJsonType, typename T1, typename T2, enable_if_t < std::is_constructible<BasicJsonType, T1>::value&& std::is_constructible<BasicJsonType, T2>::value, int > = 0 >
inline void to_json(BasicJsonType& j, const std::pair<T1, T2>& p)
{
    j = { p.first, p.second };
}
template<typename BasicJsonType, typename T,
         enable_if_t<std::is_same<T, iteration_proxy_value<typename BasicJsonType::iterator>>::value, int> = 0>
inline void to_json(BasicJsonType& j, const T& b)
{
    j = { {b.key(), b.value()} };
}
template<typename BasicJsonType, typename Tuple, std::size_t... Idx>
inline void to_json_tuple_impl(BasicJsonType& j, const Tuple& t, index_sequence<Idx...> )
{
    j = { std::get<Idx>(t)... };
}
template<typename BasicJsonType, typename Tuple>
inline void to_json_tuple_impl(BasicJsonType& j, const Tuple& t, index_sequence<0> )
{
    BasicJsonType element(std::get<0>(t));
    const bool is_member = element.is_array() && element.size() == 2
                           && element[static_cast<typename BasicJsonType::size_type>(0)].is_string();
    if (is_member)
    {
        j = BasicJsonType::object({std::move(element)});
    }
    else
    {
        j = BasicJsonType::array({std::move(element)});
    }
}
template<typename BasicJsonType, typename Tuple>
inline void to_json_tuple_impl(BasicJsonType& j, const Tuple& , index_sequence<> )
{
    using array_t = typename BasicJsonType::array_t;
    j = array_t();
}
template<typename BasicJsonType, typename T, enable_if_t<is_constructible_tuple<BasicJsonType, T>::value, int > = 0>
inline void to_json(BasicJsonType& j, const T& t)
{
    to_json_tuple_impl(j, t, make_index_sequence<std::tuple_size<T>::value> {});
}
#if JSON_HAS_FILESYSTEM || JSON_HAS_EXPERIMENTAL_FILESYSTEM
#if defined(__cpp_lib_char8_t)
template<typename BasicJsonType, typename Tr, typename Allocator>
inline void to_json(BasicJsonType& j, const std::basic_string<char8_t, Tr, Allocator>& s)
{
    using OtherAllocator = typename std::allocator_traits<Allocator>::template rebind_alloc<char>;
    j = std::basic_string<char, std::char_traits<char>, OtherAllocator>(s.begin(), s.end(), s.get_allocator());
}
#endif
template<typename BasicJsonType>
struct has_to_json<BasicJsonType, std_fs::path, void> : std::true_type {};
template<typename BasicJsonType>
inline void to_json(BasicJsonType& j, const std_fs::path& p)
{
    j = p.u8string();
}
#endif
struct to_json_fn
{
    template<typename BasicJsonType, typename T>
    auto operator()(BasicJsonType& j, T&& val) const noexcept(noexcept(to_json(j, std::forward<T>(val))))
    -> decltype(to_json(j, std::forward<T>(val)), void())
    {
        return to_json(j, std::forward<T>(val));
    }
};
}  
#ifndef JSON_HAS_CPP_17
namespace 
{
#endif
JSON_INLINE_VARIABLE constexpr const auto& to_json = 
    detail::static_const<detail::to_json_fn>::value;
#ifndef JSON_HAS_CPP_17
}  
#endif
NLOHMANN_JSON_NAMESPACE_END
NLOHMANN_JSON_NAMESPACE_BEGIN
template<typename ValueType, typename>
struct adl_serializer
{
    template<typename BasicJsonType, typename TargetType = ValueType>
    static auto from_json(BasicJsonType && j, TargetType& val) noexcept(
        noexcept(::nlohmann::from_json(std::forward<BasicJsonType>(j), val)))
    -> decltype(::nlohmann::from_json(std::forward<BasicJsonType>(j), val), void())
    {
        ::nlohmann::from_json(std::forward<BasicJsonType>(j), val);
    }
    template<typename BasicJsonType, typename TargetType = ValueType>
    static auto from_json(BasicJsonType && j) noexcept(
    noexcept(::nlohmann::from_json(std::forward<BasicJsonType>(j), detail::identity_tag<TargetType> {})))
    -> decltype(::nlohmann::from_json(std::forward<BasicJsonType>(j), detail::identity_tag<TargetType> {}))
    {
        return ::nlohmann::from_json(std::forward<BasicJsonType>(j), detail::identity_tag<TargetType> {});
    }
    template<typename BasicJsonType, typename TargetType = ValueType>
    static auto to_json(BasicJsonType& j, TargetType && val) noexcept(
        noexcept(::nlohmann::to_json(j, std::forward<TargetType>(val))))
    -> decltype(::nlohmann::to_json(j, std::forward<TargetType>(val)), void())
    {
        ::nlohmann::to_json(j, std::forward<TargetType>(val));
    }
};
NLOHMANN_JSON_NAMESPACE_END
#include <cstdint> 
#include <tuple> 
#include <utility> 
NLOHMANN_JSON_NAMESPACE_BEGIN
template<typename BinaryType>
class byte_container_with_subtype : public BinaryType
{
  public:
    using container_type = BinaryType;
    using subtype_type = std::uint64_t;
    byte_container_with_subtype() noexcept(noexcept(container_type()))
        : container_type()
    {}
    byte_container_with_subtype(const container_type& b) noexcept(noexcept(container_type(b)))
        : container_type(b)
    {}
    byte_container_with_subtype(container_type&& b) noexcept(noexcept(container_type(std::move(b))))
        : container_type(std::move(b))
    {}
    byte_container_with_subtype(const container_type& b, subtype_type subtype_) noexcept(noexcept(container_type(b)))
        : container_type(b)
        , m_subtype(subtype_)
        , m_has_subtype(true)
    {}
    byte_container_with_subtype(container_type&& b, subtype_type subtype_) noexcept(noexcept(container_type(std::move(b))))
        : container_type(std::move(b))
        , m_subtype(subtype_)
        , m_has_subtype(true)
    {}
    bool operator==(const byte_container_with_subtype& rhs) const
    {
        return std::tie(static_cast<const BinaryType&>(*this), m_subtype, m_has_subtype) ==
               std::tie(static_cast<const BinaryType&>(rhs), rhs.m_subtype, rhs.m_has_subtype);
    }
    bool operator!=(const byte_container_with_subtype& rhs) const
    {
        return !(rhs == *this);
    }
    void set_subtype(subtype_type subtype_) noexcept
    {
        m_subtype = subtype_;
        m_has_subtype = true;
    }
    constexpr subtype_type subtype() const noexcept
    {
        return m_has_subtype ? m_subtype : static_cast<subtype_type>(-1);
    }
    constexpr bool has_subtype() const noexcept
    {
        return m_has_subtype;
    }
    void clear_subtype() noexcept
    {
        m_subtype = 0;
        m_has_subtype = false;
    }
  private:
    subtype_type m_subtype = 0;
    bool m_has_subtype = false;
};
NLOHMANN_JSON_NAMESPACE_END
#include <cstdint> 
#include <cstddef> 
#include <functional> 
#include <vector> 
#include <cstddef> 
NLOHMANN_JSON_NAMESPACE_BEGIN
namespace detail
{
constexpr std::size_t recursion_depth_limit() noexcept
{
    return 128;
}
}  
NLOHMANN_JSON_NAMESPACE_END
NLOHMANN_JSON_NAMESPACE_BEGIN
namespace detail
{
inline std::size_t combine(std::size_t seed, std::size_t h) noexcept
{
    seed ^= h + 0x9e3779b9 + (seed << 6U) + (seed >> 2U);
    return seed;
}
template<typename BasicJsonType>
std::size_t hash_iteratively(const BasicJsonType& j);
template<typename BasicJsonType>
std::size_t hash(const BasicJsonType& j, const std::size_t depth = 0)
{
    using string_t = typename BasicJsonType::string_t;
    using number_integer_t = typename BasicJsonType::number_integer_t;
    using number_unsigned_t = typename BasicJsonType::number_unsigned_t;
    using number_float_t = typename BasicJsonType::number_float_t;
    const auto type = static_cast<std::size_t>(j.type());
    switch (j.type())
    {
        case BasicJsonType::value_t::null:
        case BasicJsonType::value_t::discarded:
        {
            return combine(type, 0);
        }
        case BasicJsonType::value_t::object:
        {
            if (JSON_HEDLEY_UNLIKELY(depth >= recursion_depth_limit()))
            {
                return hash_iteratively(j);
            }
            auto seed = combine(type, j.size());
            for (const auto& element : j.items())
            {
                const auto h = std::hash<string_t> {}(element.key());
                seed = combine(seed, h);
                seed = combine(seed, hash(element.value(), depth + 1));
            }
            return seed;
        }
        case BasicJsonType::value_t::array:
        {
            if (JSON_HEDLEY_UNLIKELY(depth >= recursion_depth_limit()))
            {
                return hash_iteratively(j);
            }
            auto seed = combine(type, j.size());
            for (const auto& element : j)
            {
                seed = combine(seed, hash(element, depth + 1));
            }
            return seed;
        }
        case BasicJsonType::value_t::string:
        {
            const auto h = std::hash<string_t> {}(j.template get_ref<const string_t&>());
            return combine(type, h);
        }
        case BasicJsonType::value_t::boolean:
        {
            const auto h = std::hash<bool> {}(j.template get<bool>());
            return combine(type, h);
        }
        case BasicJsonType::value_t::number_integer:
        {
            const auto h = std::hash<number_integer_t> {}(j.template get<number_integer_t>());
            return combine(type, h);
        }
        case BasicJsonType::value_t::number_unsigned:
        {
            const auto h = std::hash<number_unsigned_t> {}(j.template get<number_unsigned_t>());
            return combine(type, h);
        }
        case BasicJsonType::value_t::number_float:
        {
            const auto h = std::hash<number_float_t> {}(j.template get<number_float_t>());
            return combine(type, h);
        }
        case BasicJsonType::value_t::binary:
        {
            auto seed = combine(type, j.get_binary().size());
            const auto h = std::hash<bool> {}(j.get_binary().has_subtype());
            seed = combine(seed, h);
            seed = combine(seed, static_cast<std::size_t>(j.get_binary().subtype()));
            for (const auto byte : j.get_binary())
            {
                seed = combine(seed, std::hash<std::uint8_t> {}(static_cast<std::uint8_t>(byte)));
            }
            return seed;
        }
        default:                   
            JSON_ASSERT(false); 
            return 0;              
    }
}
template<typename BasicJsonType>
struct hash_frame
{
    hash_frame(const BasicJsonType* value_, std::size_t seed_) noexcept
        : value(value_), position(value_->cbegin()), seed(seed_)
    {}
    const BasicJsonType* value;
    typename BasicJsonType::const_iterator position;
    std::size_t seed;
};
template<typename BasicJsonType>
std::size_t hash_iteratively(const BasicJsonType& j)
{
    using string_t = typename BasicJsonType::string_t;
    std::vector<hash_frame<BasicJsonType>> stack;
    stack.emplace_back(&j, combine(static_cast<std::size_t>(j.type()), j.size()));
    while (true)
    {
        const hash_frame<BasicJsonType> frame = stack.back();
        if (frame.position == frame.value->cend())
        {
            const std::size_t h = frame.seed;
            stack.pop_back();
            if (stack.empty())
            {
                return h;
            }
            stack.back().seed = combine(stack.back().seed, h);
            continue;
        }
        if (frame.value->is_object())
        {
            stack.back().seed = combine(stack.back().seed, std::hash<string_t> {}(frame.position.key()));
        }
        const BasicJsonType& element = *frame.position;
        ++stack.back().position;
        if (element.is_structured())
        {
            stack.emplace_back(&element, combine(static_cast<std::size_t>(element.type()), element.size()));
        }
        else
        {
            stack.back().seed = combine(stack.back().seed, hash(element));
        }
    }
}
}  
NLOHMANN_JSON_NAMESPACE_END
#include <array> 
#include <cmath> 
#include <cstddef> 
#include <cstdint> 
#include <cstdio> 
#include <cstring> 
#include <iterator> 
#include <limits> 
#include <string> 
#include <utility> 
#include <vector> 
#ifdef __cpp_lib_byteswap
    #include <bit>  
#endif
#include <algorithm> 
#include <array> 
#include <cstddef> 
#include <cstdint> 
#include <cstring> 
#include <iterator> 
#include <streambuf> 
#include <string> 
#include <type_traits> 
#include <utility> 
#ifndef JSON_NO_IO
    #include <cstdio>   
    #include <istream>  
#endif                  
NLOHMANN_JSON_NAMESPACE_BEGIN
namespace detail
{
enum class input_format_t { json, cbor, msgpack, ubjson, bson, bjdata, bon8 };
#ifndef JSON_NO_IO
class file_input_adapter
{
  public:
    using char_type = char;
    JSON_HEDLEY_NON_NULL(2)
    explicit file_input_adapter(std::FILE* f) noexcept
        : m_file(f)
    {
        JSON_ASSERT(m_file != nullptr);
    }
    file_input_adapter(const file_input_adapter&) = delete;
    file_input_adapter(file_input_adapter&&) noexcept = default;
    file_input_adapter& operator=(const file_input_adapter&) = delete;
    file_input_adapter& operator=(file_input_adapter&&) = delete;
    ~file_input_adapter() = default;
    std::char_traits<char>::int_type get_character() noexcept
    {
        return std::fgetc(m_file);
    }
    template<class T>
    std::size_t get_elements(T* dest, std::size_t count = 1)
    {
        return fread(dest, 1, sizeof(T) * count, m_file);
    }
  private:
    std::FILE* m_file;
};
class input_stream_adapter
{
  public:
    using char_type = char;
    ~input_stream_adapter()
    {
        if (is != nullptr)
        {
#if JSON_PRECISE_STREAM_POSITION
            commit_lookahead();
#endif
            if ((is->rdstate() & ~std::ios::eofbit) != 0)
            {
                is->clear(is->rdstate() & std::ios::eofbit);
            }
        }
    }
    explicit input_stream_adapter(std::istream& i)
        : is(&i), sb(i.rdbuf())
    {}
    input_stream_adapter(const input_stream_adapter&) = delete;
    input_stream_adapter& operator=(input_stream_adapter&) = delete;
    input_stream_adapter& operator=(input_stream_adapter&&) = delete;
#if JSON_PRECISE_STREAM_POSITION
    input_stream_adapter(input_stream_adapter&& rhs) noexcept
        : is(rhs.is), sb(rhs.sb), lookahead(rhs.lookahead)
    {
        rhs.is = nullptr;
        rhs.sb = nullptr;
        rhs.lookahead = false;
    }
    static constexpr bool supports_lookahead = true;
    std::char_traits<char>::int_type get_character()
    {
        if (lookahead)
        {
            sb->sbumpc();
        }
        auto res = sb->sgetc();
        if (JSON_HEDLEY_UNLIKELY(res == std::char_traits<char>::eof()))
        {
            lookahead = false;
            is->clear(is->rdstate() | std::ios::eofbit);
        }
        else
        {
            lookahead = true;
        }
        return res;
    }
    void release_lookahead() noexcept
    {
        lookahead = false;
    }
#else
    input_stream_adapter(input_stream_adapter&& rhs) noexcept
        : is(rhs.is), sb(rhs.sb)
    {
        rhs.is = nullptr;
        rhs.sb = nullptr;
    }
    std::char_traits<char>::int_type get_character()
    {
        auto res = sb->sbumpc();
        if (JSON_HEDLEY_UNLIKELY(res == std::char_traits<char>::eof()))
        {
            is->clear(is->rdstate() | std::ios::eofbit);
        }
        return res;
    }
#endif
    template<class T>
    std::size_t get_elements(T* dest, std::size_t count = 1)
    {
#if JSON_PRECISE_STREAM_POSITION
        commit_lookahead();
#endif
        auto res = static_cast<std::size_t>(sb->sgetn(reinterpret_cast<char*>(dest), static_cast<std::streamsize>(count * sizeof(T))));
        if (JSON_HEDLEY_UNLIKELY(res < count * sizeof(T)))
        {
            is->clear(is->rdstate() | std::ios::eofbit);
        }
        return res;
    }
  private:
#if JSON_PRECISE_STREAM_POSITION
    void commit_lookahead()
    {
        if (lookahead)
        {
            lookahead = false;
            sb->sbumpc();
        }
    }
#endif
    std::istream* is = nullptr;
    std::streambuf* sb = nullptr;
#if JSON_PRECISE_STREAM_POSITION
    bool lookahead = false;
#endif
};
#endif  
template<typename IteratorType, typename SentinelType = IteratorType>
class iterator_input_adapter
{
    static constexpr bool sentinel_is_sized =
#if JSON_HAS_RANGES && defined(__cpp_lib_concepts) && defined(JSON_HAS_CPP_20)
        std::is_same<IteratorType, SentinelType>::value || std::sized_sentinel_for<SentinelType, IteratorType>;
#else
        std::is_same<IteratorType, SentinelType>::value;
#endif
  public:
    using char_type = typename std::iterator_traits<IteratorType>::value_type;
    static constexpr bool supports_seek =
        std::is_same<typename std::iterator_traits<IteratorType>::iterator_category, std::random_access_iterator_tag>::value
        && sentinel_is_sized
        && sizeof(char_type) == 1;
    iterator_input_adapter(IteratorType first, SentinelType last)
        : begin(first), current(std::move(first)), end(std::move(last))
    {}
    typename char_traits<char_type>::int_type get_character()
    {
        if (JSON_HEDLEY_LIKELY(current != end))
        {
            auto result = char_traits<char_type>::to_int_type(*current);
            std::advance(current, 1);
            return result;
        }
        return char_traits<char_type>::eof();
    }
    std::size_t get_consumed_count() const
    {
        return static_cast<std::size_t>(std::distance(begin, current));
    }
    template<typename ContainerType>
    void copy_consumed_range(std::size_t first_index, std::size_t last_index, ContainerType& out) const
    {
        const auto from = std::next(begin, static_cast<typename std::iterator_traits<IteratorType>::difference_type>(first_index));
        const auto to = std::next(begin, static_cast<typename std::iterator_traits<IteratorType>::difference_type>(last_index));
        out.insert(out.end(), from, to);
    }
    template<class T>
    std::size_t get_elements(T* dest, std::size_t count = 1)
    {
        return get_elements_impl(dest, count, std::integral_constant<bool, iterator_is_contiguous> {});
    }
  private:
    static constexpr bool iterator_is_contiguous = sentinel_is_sized &&
#if JSON_HAS_RANGES && defined(__cpp_lib_concepts) && defined(JSON_HAS_CPP_20)
        (std::contiguous_iterator<IteratorType> || std::is_pointer<IteratorType>::value);
#else
        std::is_pointer<IteratorType>::value;
#endif
    std::size_t remaining_count() const
    {
#if JSON_HAS_RANGES && defined(__cpp_lib_concepts) && defined(JSON_HAS_CPP_20)
        return static_cast<std::size_t>(std::ranges::distance(current, end));
#else
        return static_cast<std::size_t>(std::distance(current, end));
#endif
    }
  public:
    static constexpr bool supports_bulk_scan =
        iterator_is_contiguous && sizeof(char_type) == 1;
    const char_type* bulk_data() const
    {
        return &*current;
    }
    std::size_t bulk_remaining() const
    {
        return remaining_count();
    }
    void bulk_skip(std::size_t n)
    {
        std::advance(current, static_cast<typename std::iterator_traits<IteratorType>::difference_type>(n));
    }
  private:
    template<class T>
    std::size_t get_elements_impl(T* dest, std::size_t count, std::true_type )
    {
        const std::size_t wanted = count * sizeof(T);
        const std::size_t available = remaining_count() * sizeof(char_type);
        const std::size_t copied = (std::min)(wanted, available);
        if (JSON_HEDLEY_LIKELY(copied != 0))
        {
            JSON_ASSERT(copied <= wanted);    
            JSON_ASSERT(copied <= available); 
            std::memcpy(dest, &*current, copied);
            std::advance(current, static_cast<typename std::iterator_traits<IteratorType>::difference_type>(copied / sizeof(char_type)));
        }
        return copied;
    }
    template<class T>
    std::size_t get_elements_impl(T* dest, std::size_t count, std::false_type )
    {
        auto* ptr = reinterpret_cast<char*>(dest);
        for (std::size_t read_index = 0; read_index < count * sizeof(T); ++read_index)
        {
            if (JSON_HEDLEY_LIKELY(current != end))
            {
                ptr[read_index] = static_cast<char>(*current);
                std::advance(current, 1);
            }
            else
            {
                return read_index;
            }
        }
        return count * sizeof(T);
    }
    IteratorType begin;
    IteratorType current;
    SentinelType end;
    template<typename BaseInputAdapter, size_t T>
    friend struct wide_string_input_helper;
    bool empty() const
    {
        return current == end;
    }
};
template<typename BaseInputAdapter, size_t T>
struct wide_string_input_helper;
template<typename BaseInputAdapter>
struct wide_string_input_helper<BaseInputAdapter, 4>
{
    static void fill_buffer(BaseInputAdapter& input,
                            std::array<std::char_traits<char>::int_type, 4>& utf8_bytes,
                            size_t& utf8_bytes_index,
                            size_t& utf8_bytes_filled)
    {
        utf8_bytes_index = 0;
        if (JSON_HEDLEY_UNLIKELY(input.empty()))
        {
            utf8_bytes[0] = std::char_traits<char>::eof();
            utf8_bytes_filled = 1;
        }
        else
        {
            const auto wc = input.get_character();
            if (wc <= 0x10FFFF)
            {
                utf8_bytes_filled = 0;
                encode_utf8(static_cast<std::uint32_t>(wc), [&utf8_bytes, &utf8_bytes_filled](std::uint32_t byte)
                {
                    utf8_bytes[utf8_bytes_filled++] = static_cast<std::char_traits<char>::int_type>(byte);
                });
            }
            else
            {
                utf8_bytes[0] = 0xFF;
                utf8_bytes_filled = 1;
            }
        }
    }
};
template<typename BaseInputAdapter>
struct wide_string_input_helper<BaseInputAdapter, 2>
{
    static void fill_buffer(BaseInputAdapter& input,
                            std::array<std::char_traits<char>::int_type, 4>& utf8_bytes,
                            size_t& utf8_bytes_index,
                            size_t& utf8_bytes_filled)
    {
        utf8_bytes_index = 0;
        if (JSON_HEDLEY_UNLIKELY(input.empty()))
        {
            utf8_bytes[0] = std::char_traits<char>::eof();
            utf8_bytes_filled = 1;
        }
        else
        {
            const auto wc = input.get_character();
            if (0xD800 > wc || wc >= 0xE000)
            {
                utf8_bytes_filled = 0;
                encode_utf8(static_cast<std::uint32_t>(wc), [&utf8_bytes, &utf8_bytes_filled](std::uint32_t byte)
                {
                    utf8_bytes[utf8_bytes_filled++] = static_cast<std::char_traits<char>::int_type>(byte);
                });
            }
            else
            {
                bool valid_pair = false;
                if (wc <= 0xDBFF && JSON_HEDLEY_UNLIKELY(!input.empty()))
                {
                    const auto wc2 = static_cast<unsigned int>(input.get_character());
                    if (0xDC00 <= wc2 && wc2 <= 0xDFFF)
                    {
                        const auto charcode = 0x10000u + (((static_cast<unsigned int>(wc) & 0x3FFu) << 10u) | (wc2 & 0x3FFu));
                        utf8_bytes_filled = 0;
                        encode_utf8(charcode, [&utf8_bytes, &utf8_bytes_filled](std::uint32_t byte)
                        {
                            utf8_bytes[utf8_bytes_filled++] = static_cast<std::char_traits<char>::int_type>(byte);
                        });
                        valid_pair = true;
                    }
                }
                if (!valid_pair)
                {
                    utf8_bytes[0] = static_cast<std::char_traits<char>::int_type>(wc);
                    utf8_bytes_filled = 1;
                }
            }
        }
    }
};
template<typename BaseInputAdapter, typename WideCharType>
class wide_string_input_adapter
{
  public:
    using char_type = char;
    wide_string_input_adapter(BaseInputAdapter base)
        : base_adapter(base) {}
    typename std::char_traits<char>::int_type get_character() noexcept
    {
        if (utf8_bytes_index == utf8_bytes_filled)
        {
            fill_buffer<sizeof(WideCharType)>();
            JSON_ASSERT(utf8_bytes_filled > 0);
            JSON_ASSERT(utf8_bytes_index == 0);
        }
        JSON_ASSERT(utf8_bytes_filled > 0);
        JSON_ASSERT(utf8_bytes_index < utf8_bytes_filled);
        return utf8_bytes[utf8_bytes_index++];
    }
    template<class T>
    JSON_HEDLEY_NO_RETURN std::size_t get_elements(T* , std::size_t  = 1)
    {
        JSON_THROW(parse_error::create(112, 1, "wide string type cannot be interpreted as binary data", nullptr));
    }
  private:
    BaseInputAdapter base_adapter;
    template<size_t T>
    void fill_buffer()
    {
        wide_string_input_helper<BaseInputAdapter, T>::fill_buffer(base_adapter, utf8_bytes, utf8_bytes_index, utf8_bytes_filled);
    }
    std::array<std::char_traits<char>::int_type, 4> utf8_bytes = {{0, 0, 0, 0}};
    std::size_t utf8_bytes_index = 0;
    std::size_t utf8_bytes_filled = 0;
};
template<typename IteratorType, typename SentinelType = IteratorType, typename Enable = void>
struct iterator_input_adapter_factory
{
    using iterator_type = IteratorType;
    using sentinel_type = SentinelType;
    using char_type = typename std::iterator_traits<iterator_type>::value_type;
    using adapter_type = iterator_input_adapter<iterator_type, sentinel_type>;
    static adapter_type create(IteratorType first, SentinelType last)
    {
        return adapter_type(std::move(first), std::move(last));
    }
};
template<typename IteratorType, typename SentinelType, typename = void>
struct can_compare_ne_impl : std::false_type {};
template<typename IteratorType, typename SentinelType>
struct can_compare_ne_impl < IteratorType, SentinelType,
       void_t < decltype(std::declval<IteratorType>() != std::declval<SentinelType>()) >>
           : std::true_type {};
template<typename IteratorType, typename SentinelType, typename = void>
struct can_compare_ne_reversed : std::false_type {};
template<typename IteratorType, typename SentinelType>
struct can_compare_ne_reversed < IteratorType, SentinelType,
       void_t < decltype(std::declval<SentinelType>() != std::declval<IteratorType>()) >>
           : std::true_type {};
template<typename IteratorType, typename SentinelType>
struct can_compare_ne_either_order : std::integral_constant < bool,
    can_compare_ne_impl<IteratorType, SentinelType>::value ||
    can_compare_ne_reversed<IteratorType, SentinelType>::value > {};
template<typename IteratorType, typename SentinelType>
struct can_compare_ne : std::integral_constant < bool,
    !std::is_same<SentinelType, std::nullptr_t>::value &&
    can_compare_ne_either_order<IteratorType, SentinelType>::value > {};
template<typename T>
struct is_iterator_of_multibyte
{
    using value_type = typename std::iterator_traits<T>::value_type;
    enum 
    {
        value = sizeof(value_type) > 1
    };
};
template<typename IteratorType, typename SentinelType>
struct iterator_input_adapter_factory<IteratorType, SentinelType, enable_if_t<is_iterator_of_multibyte<IteratorType>::value>>
{
    using iterator_type = IteratorType;
    using sentinel_type = SentinelType;
    using char_type = typename std::iterator_traits<iterator_type>::value_type;
    using base_adapter_type = iterator_input_adapter<iterator_type, sentinel_type>;
    using adapter_type = wide_string_input_adapter<base_adapter_type, char_type>;
    static adapter_type create(IteratorType first, SentinelType last)
    {
        return adapter_type(base_adapter_type(std::move(first), std::move(last)));
    }
};
template < typename IteratorType, typename SentinelType = IteratorType,
           typename = typename std::enable_if <
               can_compare_ne<IteratorType, SentinelType>::value >::type >
typename iterator_input_adapter_factory<IteratorType, SentinelType>::adapter_type input_adapter(IteratorType first, SentinelType last)
{
    using factory_type = iterator_input_adapter_factory<IteratorType, SentinelType>;
    return factory_type::create(first, last);
}
template<typename ContainerType>
using container_data_t = typename std::remove_cv<typename std::remove_pointer <
                         decltype(std::declval<const ContainerType&>().data()) >::type >::type;
template<typename ContainerType>
using container_value_t = typename std::remove_cv <
                          typename std::remove_cv<typename std::remove_reference<ContainerType>::type>::type::value_type >::type;
template<typename ContainerType, typename = void>
struct is_contiguous_byte_container : std::false_type {};
template<typename ContainerType>
struct is_contiguous_byte_container < ContainerType, void_t <
    container_data_t<ContainerType>,
    container_value_t<ContainerType>,
decltype(std::declval<const ContainerType&>().size()) >>
            : std::integral_constant < bool,
        std::is_pointer<decltype(std::declval<const ContainerType&>().data())>::value&&
        std::is_integral<container_data_t<ContainerType>>::value&&
        sizeof(container_data_t<ContainerType>) == 1 &&
        std::is_same<container_data_t<ContainerType>, container_value_t<ContainerType>>::value > {};
namespace container_input_adapter_factory_impl
{
using std::begin;
using std::end;
template<typename ContainerType, typename Enable = void>
struct container_input_adapter_factory {};
template<typename ContainerType>
struct container_input_adapter_factory< ContainerType,
       void_t<decltype(begin(std::declval<ContainerType>()), end(std::declval<ContainerType>()))>>
       {
           using adapter_type = decltype(input_adapter(begin(std::declval<ContainerType>()), end(std::declval<ContainerType>())));
           static adapter_type create(ContainerType&& container)
{
    return input_adapter(begin(std::forward<ContainerType>(container)), end(std::forward<ContainerType>(container)));
}
       };
}  
template < typename ContainerType,
           enable_if_t < !is_contiguous_byte_container<ContainerType>::value, int > = 0 >
typename container_input_adapter_factory_impl::container_input_adapter_factory<ContainerType>::adapter_type input_adapter(ContainerType && container)
{
    return container_input_adapter_factory_impl::container_input_adapter_factory<ContainerType>::create(std::forward<ContainerType>(container));
}
template < typename ContainerType,
           enable_if_t < is_contiguous_byte_container<ContainerType>::value, int > = 0 >
auto input_adapter(const ContainerType& container)
-> decltype(input_adapter(container.data(), container.data() + container.size()))
{
    return input_adapter(container.data(), container.data() + container.size());
}
using string_input_adapter_type = decltype(input_adapter(std::declval<std::string>()));
#ifndef JSON_NO_IO
inline file_input_adapter input_adapter(std::FILE* file)
{
    if (file == nullptr)
    {
        JSON_THROW(parse_error::create(101, 0, "attempting to parse an empty input; check that your input string or stream contains the expected JSON", nullptr));
    }
    return file_input_adapter(file);
}
inline input_stream_adapter input_adapter(std::istream& stream)
{
    if (stream.rdbuf() == nullptr)
    {
        JSON_THROW(parse_error::create(101, 0, "attempting to parse an empty input; check that your input string or stream contains the expected JSON", nullptr));
    }
    return input_stream_adapter(stream);
}
inline input_stream_adapter input_adapter(std::istream&& stream)
{
    return input_adapter(stream);
}
#endif  
using contiguous_bytes_input_adapter = decltype(input_adapter(std::declval<const char*>(), std::declval<const char*>()));
template < typename CharT,
           typename std::enable_if <
               std::is_pointer<CharT>::value&&
               !std::is_array<CharT>::value&&
               std::is_integral<typename std::remove_pointer<CharT>::type>::value&&
               sizeof(typename std::remove_pointer<CharT>::type) == 1,
               int >::type = 0 >
contiguous_bytes_input_adapter input_adapter(CharT b)
{
    if (b == nullptr)
    {
        JSON_THROW(parse_error::create(101, 0, "attempting to parse an empty input; check that your input string or stream contains the expected JSON", nullptr));
    }
    auto length = std::strlen(reinterpret_cast<const char*>(b));
    const auto* ptr = reinterpret_cast<const char*>(b);
    return input_adapter(ptr, ptr + length); 
}
template<typename T, std::size_t N>
auto input_adapter(T (&array)[N]) -> decltype(input_adapter(array, array + N)) 
{
#if JSON_STRICT_NUL_HANDLING
    using char_t = typename std::remove_cv<T>::type;
    constexpr bool is_text_literal_type = std::is_same<char_t, char>::value
                                          || std::is_same<char_t, wchar_t>::value
                                          || std::is_same<char_t, char16_t>::value
                                          || std::is_same<char_t, char32_t>::value
#if defined(__cpp_char8_t)
                                          || std::is_same<char_t, char8_t>::value
#endif
                                          ;
    if (is_text_literal_type && N > 0 && array[N - 1] == 0)
    {
        return input_adapter(array, array + N - 1);
    }
#endif
    return input_adapter(array, array + N);
}
class span_input_adapter
{
  public:
    template < typename CharT,
               typename std::enable_if <
                   std::is_pointer<CharT>::value&&
                   std::is_integral<typename std::remove_pointer<CharT>::type>::value&&
                   sizeof(typename std::remove_pointer<CharT>::type) == 1,
                   int >::type = 0 >
    span_input_adapter(CharT b, std::size_t l)
        : ia(reinterpret_cast<const char*>(b), reinterpret_cast<const char*>(b) + l) {}
    template<class IteratorType,
             typename std::enable_if<
                 std::is_same<typename iterator_traits<IteratorType>::iterator_category, std::random_access_iterator_tag>::value,
                 int>::type = 0>
    span_input_adapter(IteratorType first, IteratorType last)
        : ia(input_adapter(first, last)) {}
    contiguous_bytes_input_adapter&& get()
    {
        return std::move(ia); 
    }
  private:
    contiguous_bytes_input_adapter ia;
};
}  
NLOHMANN_JSON_NAMESPACE_END
#include <algorithm> 
#include <cstddef>
#include <limits> 
#include <string> 
#include <type_traits> 
#include <utility> 
#include <vector> 
#include <array> 
#include <cstddef> 
#include <cstdint> 
#include <cstdio> 
#include <initializer_list> 
#include <string> 
#include <utility> 
#include <vector> 
#include <array> 
#include <cfloat> 
#include <clocale> 
#include <cstddef> 
#include <cstdint> 
#include <cstdlib> 
#include <cstring> 
#include <limits> 
#include <string> 
#include <cstdint> 
NLOHMANN_JSON_NAMESPACE_BEGIN
namespace detail
{
inline int count_leading_zeros(std::uint64_t x) noexcept
{
#if defined(__GNUC__) || defined(__clang__)
    return __builtin_clzll(x);
#else
    int n = 0;
    for (int shift = 32; shift != 0; shift >>= 1)
    {
        if ((x >> (64 - shift)) == 0)
        {
            n += shift;
            x <<= shift;
        }
    }
    return n;
#endif
}
struct uint128_parts
{
    std::uint64_t low;
    std::uint64_t high;
};
inline uint128_parts full_multiplication(std::uint64_t a, std::uint64_t b) noexcept
{
#if defined(__SIZEOF_INT128__)
    __extension__ using uint128 = unsigned __int128;
    const uint128 r = static_cast<uint128>(a) * b;
    return {static_cast<std::uint64_t>(r), static_cast<std::uint64_t>(r >> 64u)};
#else
    const std::uint64_t a_lo = a & 0xFFFFFFFFu;
    const std::uint64_t a_hi = a >> 32u;
    const std::uint64_t b_lo = b & 0xFFFFFFFFu;
    const std::uint64_t b_hi = b >> 32u;
    const std::uint64_t lo_lo = a_lo * b_lo;
    const std::uint64_t hi_lo = a_hi * b_lo;
    const std::uint64_t lo_hi = a_lo * b_hi;
    const std::uint64_t hi_hi = a_hi * b_hi;
    const std::uint64_t cross = (lo_lo >> 32u) + (hi_lo & 0xFFFFFFFFu) + lo_hi;
    return {(cross << 32u) | (lo_lo & 0xFFFFFFFFu), (hi_lo >> 32u) + (cross >> 32u) + hi_hi};
#endif
}
inline std::uint64_t read_eight_bytes(const char* p) noexcept
{
    const auto* b = reinterpret_cast<const unsigned char*>(p); 
    return static_cast<std::uint64_t>(b[0]) | (static_cast<std::uint64_t>(b[1]) << 8u)
           | (static_cast<std::uint64_t>(b[2]) << 16u) | (static_cast<std::uint64_t>(b[3]) << 24u)
           | (static_cast<std::uint64_t>(b[4]) << 32u) | (static_cast<std::uint64_t>(b[5]) << 40u)
           | (static_cast<std::uint64_t>(b[6]) << 48u) | (static_cast<std::uint64_t>(b[7]) << 56u);
}
}  
NLOHMANN_JSON_NAMESPACE_END
#include <array> 
#include <cstdint> 
NLOHMANN_JSON_NAMESPACE_BEGIN
namespace detail
{
constexpr std::int64_t pow5_128_smallest_power = -342;
constexpr std::int64_t pow5_128_largest_power = 308;
inline const std::array<std::uint64_t, 1302>& pow5_128() noexcept
{
    static const std::array<std::uint64_t, 1302> table =
    {
        {
            0xeef453d6923bd65au, 0x113faa2906a13b3fu, 0x9558b4661b6565f8u, 0x4ac7ca59a424c507u,
            0xbaaee17fa23ebf76u, 0x5d79bcf00d2df649u, 0xe95a99df8ace6f53u, 0xf4d82c2c107973dcu,
            0x91d8a02bb6c10594u, 0x79071b9b8a4be869u, 0xb64ec836a47146f9u, 0x9748e2826cdee284u,
            0xe3e27a444d8d98b7u, 0xfd1b1b2308169b25u, 0x8e6d8c6ab0787f72u, 0xfe30f0f5e50e20f7u,
            0xb208ef855c969f4fu, 0xbdbd2d335e51a935u, 0xde8b2b66b3bc4723u, 0xad2c788035e61382u,
            0x8b16fb203055ac76u, 0x4c3bcb5021afcc31u, 0xaddcb9e83c6b1793u, 0xdf4abe242a1bbf3du,
            0xd953e8624b85dd78u, 0xd71d6dad34a2af0du, 0x87d4713d6f33aa6bu, 0x8672648c40e5ad68u,
            0xa9c98d8ccb009506u, 0x680efdaf511f18c2u, 0xd43bf0effdc0ba48u, 0x0212bd1b2566def2u,
            0x84a57695fe98746du, 0x014bb630f7604b57u, 0xa5ced43b7e3e9188u, 0x419ea3bd35385e2du,
            0xcf42894a5dce35eau, 0x52064cac828675b9u, 0x818995ce7aa0e1b2u, 0x7343efebd1940993u,
            0xa1ebfb4219491a1fu, 0x1014ebe6c5f90bf8u, 0xca66fa129f9b60a6u, 0xd41a26e077774ef6u,
            0xfd00b897478238d0u, 0x8920b098955522b4u, 0x9e20735e8cb16382u, 0x55b46e5f5d5535b0u,
            0xc5a890362fddbc62u, 0xeb2189f734aa831du, 0xf712b443bbd52b7bu, 0xa5e9ec7501d523e4u,
            0x9a6bb0aa55653b2du, 0x47b233c92125366eu, 0xc1069cd4eabe89f8u, 0x999ec0bb696e840au,
            0xf148440a256e2c76u, 0xc00670ea43ca250du, 0x96cd2a865764dbcau, 0x380406926a5e5728u,
            0xbc807527ed3e12bcu, 0xc605083704f5ecf2u, 0xeba09271e88d976bu, 0xf7864a44c633682eu,
            0x93445b8731587ea3u, 0x7ab3ee6afbe0211du, 0xb8157268fdae9e4cu, 0x5960ea05bad82964u,
            0xe61acf033d1a45dfu, 0x6fb92487298e33bdu, 0x8fd0c16206306babu, 0xa5d3b6d479f8e056u,
            0xb3c4f1ba87bc8696u, 0x8f48a4899877186cu, 0xe0b62e2929aba83cu, 0x331acdabfe94de87u,
            0x8c71dcd9ba0b4925u, 0x9ff0c08b7f1d0b14u, 0xaf8e5410288e1b6fu, 0x07ecf0ae5ee44dd9u,
            0xdb71e91432b1a24au, 0xc9e82cd9f69d6150u, 0x892731ac9faf056eu, 0xbe311c083a225cd2u,
            0xab70fe17c79ac6cau, 0x6dbd630a48aaf406u, 0xd64d3d9db981787du, 0x092cbbccdad5b108u,
            0x85f0468293f0eb4eu, 0x25bbf56008c58ea5u, 0xa76c582338ed2621u, 0xaf2af2b80af6f24eu,
            0xd1476e2c07286faau, 0x1af5af660db4aee1u, 0x82cca4db847945cau, 0x50d98d9fc890ed4du,
            0xa37fce126597973cu, 0xe50ff107bab528a0u, 0xcc5fc196fefd7d0cu, 0x1e53ed49a96272c8u,
            0xff77b1fcbebcdc4fu, 0x25e8e89c13bb0f7au, 0x9faacf3df73609b1u, 0x77b191618c54e9acu,
            0xc795830d75038c1du, 0xd59df5b9ef6a2417u, 0xf97ae3d0d2446f25u, 0x4b0573286b44ad1du,
            0x9becce62836ac577u, 0x4ee367f9430aec32u, 0xc2e801fb244576d5u, 0x229c41f793cda73fu,
            0xf3a20279ed56d48au, 0x6b43527578c1110fu, 0x9845418c345644d6u, 0x830a13896b78aaa9u,
            0xbe5691ef416bd60cu, 0x23cc986bc656d553u, 0xedec366b11c6cb8fu, 0x2cbfbe86b7ec8aa8u,
            0x94b3a202eb1c3f39u, 0x7bf7d71432f3d6a9u, 0xb9e08a83a5e34f07u, 0xdaf5ccd93fb0cc53u,
            0xe858ad248f5c22c9u, 0xd1b3400f8f9cff68u, 0x91376c36d99995beu, 0x23100809b9c21fa1u,
            0xb58547448ffffb2du, 0xabd40a0c2832a78au, 0xe2e69915b3fff9f9u, 0x16c90c8f323f516cu,
            0x8dd01fad907ffc3bu, 0xae3da7d97f6792e3u, 0xb1442798f49ffb4au, 0x99cd11cfdf41779cu,
            0xdd95317f31c7fa1du, 0x40405643d711d583u, 0x8a7d3eef7f1cfc52u, 0x482835ea666b2572u,
            0xad1c8eab5ee43b66u, 0xda3243650005eecfu, 0xd863b256369d4a40u, 0x90bed43e40076a82u,
            0x873e4f75e2224e68u, 0x5a7744a6e804a291u, 0xa90de3535aaae202u, 0x711515d0a205cb36u,
            0xd3515c2831559a83u, 0x0d5a5b44ca873e03u, 0x8412d9991ed58091u, 0xe858790afe9486c2u,
            0xa5178fff668ae0b6u, 0x626e974dbe39a872u, 0xce5d73ff402d98e3u, 0xfb0a3d212dc8128fu,
            0x80fa687f881c7f8eu, 0x7ce66634bc9d0b99u, 0xa139029f6a239f72u, 0x1c1fffc1ebc44e80u,
            0xc987434744ac874eu, 0xa327ffb266b56220u, 0xfbe9141915d7a922u, 0x4bf1ff9f0062baa8u,
            0x9d71ac8fada6c9b5u, 0x6f773fc3603db4a9u, 0xc4ce17b399107c22u, 0xcb550fb4384d21d3u,
            0xf6019da07f549b2bu, 0x7e2a53a146606a48u, 0x99c102844f94e0fbu, 0x2eda7444cbfc426du,
            0xc0314325637a1939u, 0xfa911155fefb5308u, 0xf03d93eebc589f88u, 0x793555ab7eba27cau,
            0x96267c7535b763b5u, 0x4bc1558b2f3458deu, 0xbbb01b9283253ca2u, 0x9eb1aaedfb016f16u,
            0xea9c227723ee8bcbu, 0x465e15a979c1cadcu, 0x92a1958a7675175fu, 0x0bfacd89ec191ec9u,
            0xb749faed14125d36u, 0xcef980ec671f667bu, 0xe51c79a85916f484u, 0x82b7e12780e7401au,
            0x8f31cc0937ae58d2u, 0xd1b2ecb8b0908810u, 0xb2fe3f0b8599ef07u, 0x861fa7e6dcb4aa15u,
            0xdfbdcece67006ac9u, 0x67a791e093e1d49au, 0x8bd6a141006042bdu, 0xe0c8bb2c5c6d24e0u,
            0xaecc49914078536du, 0x58fae9f773886e18u, 0xda7f5bf590966848u, 0xaf39a475506a899eu,
            0x888f99797a5e012du, 0x6d8406c952429603u, 0xaab37fd7d8f58178u, 0xc8e5087ba6d33b83u,
            0xd5605fcdcf32e1d6u, 0xfb1e4a9a90880a64u, 0x855c3be0a17fcd26u, 0x5cf2eea09a55067fu,
            0xa6b34ad8c9dfc06fu, 0xf42faa48c0ea481eu, 0xd0601d8efc57b08bu, 0xf13b94daf124da26u,
            0x823c12795db6ce57u, 0x76c53d08d6b70858u, 0xa2cb1717b52481edu, 0x54768c4b0c64ca6eu,
            0xcb7ddcdda26da268u, 0xa9942f5dcf7dfd09u, 0xfe5d54150b090b02u, 0xd3f93b35435d7c4cu,
            0x9efa548d26e5a6e1u, 0xc47bc5014a1a6dafu, 0xc6b8e9b0709f109au, 0x359ab6419ca1091bu,
            0xf867241c8cc6d4c0u, 0xc30163d203c94b62u, 0x9b407691d7fc44f8u, 0x79e0de63425dcf1du,
            0xc21094364dfb5636u, 0x985915fc12f542e4u, 0xf294b943e17a2bc4u, 0x3e6f5b7b17b2939du,
            0x979cf3ca6cec5b5au, 0xa705992ceecf9c42u, 0xbd8430bd08277231u, 0x50c6ff782a838353u,
            0xece53cec4a314ebdu, 0xa4f8bf5635246428u, 0x940f4613ae5ed136u, 0x871b7795e136be99u,
            0xb913179899f68584u, 0x28e2557b59846e3fu, 0xe757dd7ec07426e5u, 0x331aeada2fe589cfu,
            0x9096ea6f3848984fu, 0x3ff0d2c85def7621u, 0xb4bca50b065abe63u, 0x0fed077a756b53a9u,
            0xe1ebce4dc7f16dfbu, 0xd3e8495912c62894u, 0x8d3360f09cf6e4bdu, 0x64712dd7abbbd95cu,
            0xb080392cc4349decu, 0xbd8d794d96aacfb3u, 0xdca04777f541c567u, 0xecf0d7a0fc5583a0u,
            0x89e42caaf9491b60u, 0xf41686c49db57244u, 0xac5d37d5b79b6239u, 0x311c2875c522ced5u,
            0xd77485cb25823ac7u, 0x7d633293366b828bu, 0x86a8d39ef77164bcu, 0xae5dff9c02033197u,
            0xa8530886b54dbdebu, 0xd9f57f830283fdfcu, 0xd267caa862a12d66u, 0xd072df63c324fd7bu,
            0x8380dea93da4bc60u, 0x4247cb9e59f71e6du, 0xa46116538d0deb78u, 0x52d9be85f074e608u,
            0xcd795be870516656u, 0x67902e276c921f8bu, 0x806bd9714632dff6u, 0x00ba1cd8a3db53b6u,
            0xa086cfcd97bf97f3u, 0x80e8a40eccd228a4u, 0xc8a883c0fdaf7df0u, 0x6122cd128006b2cdu,
            0xfad2a4b13d1b5d6cu, 0x796b805720085f81u, 0x9cc3a6eec6311a63u, 0xcbe3303674053bb0u,
            0xc3f490aa77bd60fcu, 0xbedbfc4411068a9cu, 0xf4f1b4d515acb93bu, 0xee92fb5515482d44u,
            0x991711052d8bf3c5u, 0x751bdd152d4d1c4au, 0xbf5cd54678eef0b6u, 0xd262d45a78a0635du,
            0xef340a98172aace4u, 0x86fb897116c87c34u, 0x9580869f0e7aac0eu, 0xd45d35e6ae3d4da0u,
            0xbae0a846d2195712u, 0x8974836059cca109u, 0xe998d258869facd7u, 0x2bd1a438703fc94bu,
            0x91ff83775423cc06u, 0x7b6306a34627ddcfu, 0xb67f6455292cbf08u, 0x1a3bc84c17b1d542u,
            0xe41f3d6a7377eecau, 0x20caba5f1d9e4a93u, 0x8e938662882af53eu, 0x547eb47b7282ee9cu,
            0xb23867fb2a35b28du, 0xe99e619a4f23aa43u, 0xdec681f9f4c31f31u, 0x6405fa00e2ec94d4u,
            0x8b3c113c38f9f37eu, 0xde83bc408dd3dd04u, 0xae0b158b4738705eu, 0x9624ab50b148d445u,
            0xd98ddaee19068c76u, 0x3badd624dd9b0957u, 0x87f8a8d4cfa417c9u, 0xe54ca5d70a80e5d6u,
            0xa9f6d30a038d1dbcu, 0x5e9fcf4ccd211f4cu, 0xd47487cc8470652bu, 0x7647c3200069671fu,
            0x84c8d4dfd2c63f3bu, 0x29ecd9f40041e073u, 0xa5fb0a17c777cf09u, 0xf468107100525890u,
            0xcf79cc9db955c2ccu, 0x7182148d4066eeb4u, 0x81ac1fe293d599bfu, 0xc6f14cd848405530u,
            0xa21727db38cb002fu, 0xb8ada00e5a506a7cu, 0xca9cf1d206fdc03bu, 0xa6d90811f0e4851cu,
            0xfd442e4688bd304au, 0x908f4a166d1da663u, 0x9e4a9cec15763e2eu, 0x9a598e4e043287feu,
            0xc5dd44271ad3cdbau, 0x40eff1e1853f29fdu, 0xf7549530e188c128u, 0xd12bee59e68ef47cu,
            0x9a94dd3e8cf578b9u, 0x82bb74f8301958ceu, 0xc13a148e3032d6e7u, 0xe36a52363c1faf01u,
            0xf18899b1bc3f8ca1u, 0xdc44e6c3cb279ac1u, 0x96f5600f15a7b7e5u, 0x29ab103a5ef8c0b9u,
            0xbcb2b812db11a5deu, 0x7415d448f6b6f0e7u, 0xebdf661791d60f56u, 0x111b495b3464ad21u,
            0x936b9fcebb25c995u, 0xcab10dd900beec34u, 0xb84687c269ef3bfbu, 0x3d5d514f40eea742u,
            0xe65829b3046b0afau, 0x0cb4a5a3112a5112u, 0x8ff71a0fe2c2e6dcu, 0x47f0e785eaba72abu,
            0xb3f4e093db73a093u, 0x59ed216765690f56u, 0xe0f218b8d25088b8u, 0x306869c13ec3532cu,
            0x8c974f7383725573u, 0x1e414218c73a13fbu, 0xafbd2350644eeacfu, 0xe5d1929ef90898fau,
            0xdbac6c247d62a583u, 0xdf45f746b74abf39u, 0x894bc396ce5da772u, 0x6b8bba8c328eb783u,
            0xab9eb47c81f5114fu, 0x066ea92f3f326564u, 0xd686619ba27255a2u, 0xc80a537b0efefebdu,
            0x8613fd0145877585u, 0xbd06742ce95f5f36u, 0xa798fc4196e952e7u, 0x2c48113823b73704u,
            0xd17f3b51fca3a7a0u, 0xf75a15862ca504c5u, 0x82ef85133de648c4u, 0x9a984d73dbe722fbu,
            0xa3ab66580d5fdaf5u, 0xc13e60d0d2e0ebbau, 0xcc963fee10b7d1b3u, 0x318df905079926a8u,
            0xffbbcfe994e5c61fu, 0xfdf17746497f7052u, 0x9fd561f1fd0f9bd3u, 0xfeb6ea8bedefa633u,
            0xc7caba6e7c5382c8u, 0xfe64a52ee96b8fc0u, 0xf9bd690a1b68637bu, 0x3dfdce7aa3c673b0u,
            0x9c1661a651213e2du, 0x06bea10ca65c084eu, 0xc31bfa0fe5698db8u, 0x486e494fcff30a62u,
            0xf3e2f893dec3f126u, 0x5a89dba3c3efccfau, 0x986ddb5c6b3a76b7u, 0xf89629465a75e01cu,
            0xbe89523386091465u, 0xf6bbb397f1135823u, 0xee2ba6c0678b597fu, 0x746aa07ded582e2cu,
            0x94db483840b717efu, 0xa8c2a44eb4571cdcu, 0xba121a4650e4ddebu, 0x92f34d62616ce413u,
            0xe896a0d7e51e1566u, 0x77b020baf9c81d17u, 0x915e2486ef32cd60u, 0x0ace1474dc1d122eu,
            0xb5b5ada8aaff80b8u, 0x0d819992132456bau, 0xe3231912d5bf60e6u, 0x10e1fff697ed6c69u,
            0x8df5efabc5979c8fu, 0xca8d3ffa1ef463c1u, 0xb1736b96b6fd83b3u, 0xbd308ff8a6b17cb2u,
            0xddd0467c64bce4a0u, 0xac7cb3f6d05ddbdeu, 0x8aa22c0dbef60ee4u, 0x6bcdf07a423aa96bu,
            0xad4ab7112eb3929du, 0x86c16c98d2c953c6u, 0xd89d64d57a607744u, 0xe871c7bf077ba8b7u,
            0x87625f056c7c4a8bu, 0x11471cd764ad4972u, 0xa93af6c6c79b5d2du, 0xd598e40d3dd89bcfu,
            0xd389b47879823479u, 0x4aff1d108d4ec2c3u, 0x843610cb4bf160cbu, 0xcedf722a585139bau,
            0xa54394fe1eedb8feu, 0xc2974eb4ee658828u, 0xce947a3da6a9273eu, 0x733d226229feea32u,
            0x811ccc668829b887u, 0x0806357d5a3f525fu, 0xa163ff802a3426a8u, 0xca07c2dcb0cf26f7u,
            0xc9bcff6034c13052u, 0xfc89b393dd02f0b5u, 0xfc2c3f3841f17c67u, 0xbbac2078d443ace2u,
            0x9d9ba7832936edc0u, 0xd54b944b84aa4c0du, 0xc5029163f384a931u, 0x0a9e795e65d4df11u,
            0xf64335bcf065d37du, 0x4d4617b5ff4a16d5u, 0x99ea0196163fa42eu, 0x504bced1bf8e4e45u,
            0xc06481fb9bcf8d39u, 0xe45ec2862f71e1d6u, 0xf07da27a82c37088u, 0x5d767327bb4e5a4cu,
            0x964e858c91ba2655u, 0x3a6a07f8d510f86fu, 0xbbe226efb628afeau, 0x890489f70a55368bu,
            0xeadab0aba3b2dbe5u, 0x2b45ac74ccea842eu, 0x92c8ae6b464fc96fu, 0x3b0b8bc90012929du,
            0xb77ada0617e3bbcbu, 0x09ce6ebb40173744u, 0xe55990879ddcaabdu, 0xcc420a6a101d0515u,
            0x8f57fa54c2a9eab6u, 0x9fa946824a12232du, 0xb32df8e9f3546564u, 0x47939822dc96abf9u,
            0xdff9772470297ebdu, 0x59787e2b93bc56f7u, 0x8bfbea76c619ef36u, 0x57eb4edb3c55b65au,
            0xaefae51477a06b03u, 0xede622920b6b23f1u, 0xdab99e59958885c4u, 0xe95fab368e45ecedu,
            0x88b402f7fd75539bu, 0x11dbcb0218ebb414u, 0xaae103b5fcd2a881u, 0xd652bdc29f26a119u,
            0xd59944a37c0752a2u, 0x4be76d3346f0495fu, 0x857fcae62d8493a5u, 0x6f70a4400c562ddbu,
            0xa6dfbd9fb8e5b88eu, 0xcb4ccd500f6bb952u, 0xd097ad07a71f26b2u, 0x7e2000a41346a7a7u,
            0x825ecc24c873782fu, 0x8ed400668c0c28c8u, 0xa2f67f2dfa90563bu, 0x728900802f0f32fau,
            0xcbb41ef979346bcau, 0x4f2b40a03ad2ffb9u, 0xfea126b7d78186bcu, 0xe2f610c84987bfa8u,
            0x9f24b832e6b0f436u, 0x0dd9ca7d2df4d7c9u, 0xc6ede63fa05d3143u, 0x91503d1c79720dbbu,
            0xf8a95fcf88747d94u, 0x75a44c6397ce912au, 0x9b69dbe1b548ce7cu, 0xc986afbe3ee11abau,
            0xc24452da229b021bu, 0xfbe85badce996168u, 0xf2d56790ab41c2a2u, 0xfae27299423fb9c3u,
            0x97c560ba6b0919a5u, 0xdccd879fc967d41au, 0xbdb6b8e905cb600fu, 0x5400e987bbc1c920u,
            0xed246723473e3813u, 0x290123e9aab23b68u, 0x9436c0760c86e30bu, 0xf9a0b6720aaf6521u,
            0xb94470938fa89bceu, 0xf808e40e8d5b3e69u, 0xe7958cb87392c2c2u, 0xb60b1d1230b20e04u,
            0x90bd77f3483bb9b9u, 0xb1c6f22b5e6f48c2u, 0xb4ecd5f01a4aa828u, 0x1e38aeb6360b1af3u,
            0xe2280b6c20dd5232u, 0x25c6da63c38de1b0u, 0x8d590723948a535fu, 0x579c487e5a38ad0eu,
            0xb0af48ec79ace837u, 0x2d835a9df0c6d851u, 0xdcdb1b2798182244u, 0xf8e431456cf88e65u,
            0x8a08f0f8bf0f156bu, 0x1b8e9ecb641b58ffu, 0xac8b2d36eed2dac5u, 0xe272467e3d222f3fu,
            0xd7adf884aa879177u, 0x5b0ed81dcc6abb0fu, 0x86ccbb52ea94baeau, 0x98e947129fc2b4e9u,
            0xa87fea27a539e9a5u, 0x3f2398d747b36224u, 0xd29fe4b18e88640eu, 0x8eec7f0d19a03aadu,
            0x83a3eeeef9153e89u, 0x1953cf68300424acu, 0xa48ceaaab75a8e2bu, 0x5fa8c3423c052dd7u,
            0xcdb02555653131b6u, 0x3792f412cb06794du, 0x808e17555f3ebf11u, 0xe2bbd88bbee40bd0u,
            0xa0b19d2ab70e6ed6u, 0x5b6aceaeae9d0ec4u, 0xc8de047564d20a8bu, 0xf245825a5a445275u,
            0xfb158592be068d2eu, 0xeed6e2f0f0d56712u, 0x9ced737bb6c4183du, 0x55464dd69685606bu,
            0xc428d05aa4751e4cu, 0xaa97e14c3c26b886u, 0xf53304714d9265dfu, 0xd53dd99f4b3066a8u,
            0x993fe2c6d07b7fabu, 0xe546a8038efe4029u, 0xbf8fdb78849a5f96u, 0xde98520472bdd033u,
            0xef73d256a5c0f77cu, 0x963e66858f6d4440u, 0x95a8637627989aadu, 0xdde7001379a44aa8u,
            0xbb127c53b17ec159u, 0x5560c018580d5d52u, 0xe9d71b689dde71afu, 0xaab8f01e6e10b4a6u,
            0x9226712162ab070du, 0xcab3961304ca70e8u, 0xb6b00d69bb55c8d1u, 0x3d607b97c5fd0d22u,
            0xe45c10c42a2b3b05u, 0x8cb89a7db77c506au, 0x8eb98a7a9a5b04e3u, 0x77f3608e92adb242u,
            0xb267ed1940f1c61cu, 0x55f038b237591ed3u, 0xdf01e85f912e37a3u, 0x6b6c46dec52f6688u,
            0x8b61313bbabce2c6u, 0x2323ac4b3b3da015u, 0xae397d8aa96c1b77u, 0xabec975e0a0d081au,
            0xd9c7dced53c72255u, 0x96e7bd358c904a21u, 0x881cea14545c7575u, 0x7e50d64177da2e54u,
            0xaa242499697392d2u, 0xdde50bd1d5d0b9e9u, 0xd4ad2dbfc3d07787u, 0x955e4ec64b44e864u,
            0x84ec3c97da624ab4u, 0xbd5af13bef0b113eu, 0xa6274bbdd0fadd61u, 0xecb1ad8aeacdd58eu,
            0xcfb11ead453994bau, 0x67de18eda5814af2u, 0x81ceb32c4b43fcf4u, 0x80eacf948770ced7u,
            0xa2425ff75e14fc31u, 0xa1258379a94d028du, 0xcad2f7f5359a3b3eu, 0x096ee45813a04330u,
            0xfd87b5f28300ca0du, 0x8bca9d6e188853fcu, 0x9e74d1b791e07e48u, 0x775ea264cf55347eu,
            0xc612062576589ddau, 0x95364afe032a819eu, 0xf79687aed3eec551u, 0x3a83ddbd83f52205u,
            0x9abe14cd44753b52u, 0xc4926a9672793543u, 0xc16d9a0095928a27u, 0x75b7053c0f178294u,
            0xf1c90080baf72cb1u, 0x5324c68b12dd6339u, 0x971da05074da7beeu, 0xd3f6fc16ebca5e04u,
            0xbce5086492111aeau, 0x88f4bb1ca6bcf585u, 0xec1e4a7db69561a5u, 0x2b31e9e3d06c32e6u,
            0x9392ee8e921d5d07u, 0x3aff322e62439fd0u, 0xb877aa3236a4b449u, 0x09befeb9fad487c3u,
            0xe69594bec44de15bu, 0x4c2ebe687989a9b4u, 0x901d7cf73ab0acd9u, 0x0f9d37014bf60a11u,
            0xb424dc35095cd80fu, 0x538484c19ef38c95u, 0xe12e13424bb40e13u, 0x2865a5f206b06fbau,
            0x8cbccc096f5088cbu, 0xf93f87b7442e45d4u, 0xafebff0bcb24aafeu, 0xf78f69a51539d749u,
            0xdbe6fecebdedd5beu, 0xb573440e5a884d1cu, 0x89705f4136b4a597u, 0x31680a88f8953031u,
            0xabcc77118461cefcu, 0xfdc20d2b36ba7c3eu, 0xd6bf94d5e57a42bcu, 0x3d32907604691b4du,
            0x8637bd05af6c69b5u, 0xa63f9a49c2c1b110u, 0xa7c5ac471b478423u, 0x0fcf80dc33721d54u,
            0xd1b71758e219652bu, 0xd3c36113404ea4a9u, 0x83126e978d4fdf3bu, 0x645a1cac083126eau,
            0xa3d70a3d70a3d70au, 0x3d70a3d70a3d70a4u, 0xccccccccccccccccu, 0xcccccccccccccccdu,
            0x8000000000000000u, 0x0000000000000000u, 0xa000000000000000u, 0x0000000000000000u,
            0xc800000000000000u, 0x0000000000000000u, 0xfa00000000000000u, 0x0000000000000000u,
            0x9c40000000000000u, 0x0000000000000000u, 0xc350000000000000u, 0x0000000000000000u,
            0xf424000000000000u, 0x0000000000000000u, 0x9896800000000000u, 0x0000000000000000u,
            0xbebc200000000000u, 0x0000000000000000u, 0xee6b280000000000u, 0x0000000000000000u,
            0x9502f90000000000u, 0x0000000000000000u, 0xba43b74000000000u, 0x0000000000000000u,
            0xe8d4a51000000000u, 0x0000000000000000u, 0x9184e72a00000000u, 0x0000000000000000u,
            0xb5e620f480000000u, 0x0000000000000000u, 0xe35fa931a0000000u, 0x0000000000000000u,
            0x8e1bc9bf04000000u, 0x0000000000000000u, 0xb1a2bc2ec5000000u, 0x0000000000000000u,
            0xde0b6b3a76400000u, 0x0000000000000000u, 0x8ac7230489e80000u, 0x0000000000000000u,
            0xad78ebc5ac620000u, 0x0000000000000000u, 0xd8d726b7177a8000u, 0x0000000000000000u,
            0x878678326eac9000u, 0x0000000000000000u, 0xa968163f0a57b400u, 0x0000000000000000u,
            0xd3c21bcecceda100u, 0x0000000000000000u, 0x84595161401484a0u, 0x0000000000000000u,
            0xa56fa5b99019a5c8u, 0x0000000000000000u, 0xcecb8f27f4200f3au, 0x0000000000000000u,
            0x813f3978f8940984u, 0x4000000000000000u, 0xa18f07d736b90be5u, 0x5000000000000000u,
            0xc9f2c9cd04674edeu, 0xa400000000000000u, 0xfc6f7c4045812296u, 0x4d00000000000000u,
            0x9dc5ada82b70b59du, 0xf020000000000000u, 0xc5371912364ce305u, 0x6c28000000000000u,
            0xf684df56c3e01bc6u, 0xc732000000000000u, 0x9a130b963a6c115cu, 0x3c7f400000000000u,
            0xc097ce7bc90715b3u, 0x4b9f100000000000u, 0xf0bdc21abb48db20u, 0x1e86d40000000000u,
            0x96769950b50d88f4u, 0x1314448000000000u, 0xbc143fa4e250eb31u, 0x17d955a000000000u,
            0xeb194f8e1ae525fdu, 0x5dcfab0800000000u, 0x92efd1b8d0cf37beu, 0x5aa1cae500000000u,
            0xb7abc627050305adu, 0xf14a3d9e40000000u, 0xe596b7b0c643c719u, 0x6d9ccd05d0000000u,
            0x8f7e32ce7bea5c6fu, 0xe4820023a2000000u, 0xb35dbf821ae4f38bu, 0xdda2802c8a800000u,
            0xe0352f62a19e306eu, 0xd50b2037ad200000u, 0x8c213d9da502de45u, 0x4526f422cc340000u,
            0xaf298d050e4395d6u, 0x9670b12b7f410000u, 0xdaf3f04651d47b4cu, 0x3c0cdd765f114000u,
            0x88d8762bf324cd0fu, 0xa5880a69fb6ac800u, 0xab0e93b6efee0053u, 0x8eea0d047a457a00u,
            0xd5d238a4abe98068u, 0x72a4904598d6d880u, 0x85a36366eb71f041u, 0x47a6da2b7f864750u,
            0xa70c3c40a64e6c51u, 0x999090b65f67d924u, 0xd0cf4b50cfe20765u, 0xfff4b4e3f741cf6du,
            0x82818f1281ed449fu, 0xbff8f10e7a8921a4u, 0xa321f2d7226895c7u, 0xaff72d52192b6a0du,
            0xcbea6f8ceb02bb39u, 0x9bf4f8a69f764490u, 0xfee50b7025c36a08u, 0x02f236d04753d5b4u,
            0x9f4f2726179a2245u, 0x01d762422c946590u, 0xc722f0ef9d80aad6u, 0x424d3ad2b7b97ef5u,
            0xf8ebad2b84e0d58bu, 0xd2e0898765a7deb2u, 0x9b934c3b330c8577u, 0x63cc55f49f88eb2fu,
            0xc2781f49ffcfa6d5u, 0x3cbf6b71c76b25fbu, 0xf316271c7fc3908au, 0x8bef464e3945ef7au,
            0x97edd871cfda3a56u, 0x97758bf0e3cbb5acu, 0xbde94e8e43d0c8ecu, 0x3d52eeed1cbea317u,
            0xed63a231d4c4fb27u, 0x4ca7aaa863ee4bddu, 0x945e455f24fb1cf8u, 0x8fe8caa93e74ef6au,
            0xb975d6b6ee39e436u, 0xb3e2fd538e122b44u, 0xe7d34c64a9c85d44u, 0x60dbbca87196b616u,
            0x90e40fbeea1d3a4au, 0xbc8955e946fe31cdu, 0xb51d13aea4a488ddu, 0x6babab6398bdbe41u,
            0xe264589a4dcdab14u, 0xc696963c7eed2dd1u, 0x8d7eb76070a08aecu, 0xfc1e1de5cf543ca2u,
            0xb0de65388cc8ada8u, 0x3b25a55f43294bcbu, 0xdd15fe86affad912u, 0x49ef0eb713f39ebeu,
            0x8a2dbf142dfcc7abu, 0x6e3569326c784337u, 0xacb92ed9397bf996u, 0x49c2c37f07965404u,
            0xd7e77a8f87daf7fbu, 0xdc33745ec97be906u, 0x86f0ac99b4e8dafdu, 0x69a028bb3ded71a3u,
            0xa8acd7c0222311bcu, 0xc40832ea0d68ce0cu, 0xd2d80db02aabd62bu, 0xf50a3fa490c30190u,
            0x83c7088e1aab65dbu, 0x792667c6da79e0fau, 0xa4b8cab1a1563f52u, 0x577001b891185938u,
            0xcde6fd5e09abcf26u, 0xed4c0226b55e6f86u, 0x80b05e5ac60b6178u, 0x544f8158315b05b4u,
            0xa0dc75f1778e39d6u, 0x696361ae3db1c721u, 0xc913936dd571c84cu, 0x03bc3a19cd1e38e9u,
            0xfb5878494ace3a5fu, 0x04ab48a04065c723u, 0x9d174b2dcec0e47bu, 0x62eb0d64283f9c76u,
            0xc45d1df942711d9au, 0x3ba5d0bd324f8394u, 0xf5746577930d6500u, 0xca8f44ec7ee36479u,
            0x9968bf6abbe85f20u, 0x7e998b13cf4e1ecbu, 0xbfc2ef456ae276e8u, 0x9e3fedd8c321a67eu,
            0xefb3ab16c59b14a2u, 0xc5cfe94ef3ea101eu, 0x95d04aee3b80ece5u, 0xbba1f1d158724a12u,
            0xbb445da9ca61281fu, 0x2a8a6e45ae8edc97u, 0xea1575143cf97226u, 0xf52d09d71a3293bdu,
            0x924d692ca61be758u, 0x593c2626705f9c56u, 0xb6e0c377cfa2e12eu, 0x6f8b2fb00c77836cu,
            0xe498f455c38b997au, 0x0b6dfb9c0f956447u, 0x8edf98b59a373fecu, 0x4724bd4189bd5eacu,
            0xb2977ee300c50fe7u, 0x58edec91ec2cb657u, 0xdf3d5e9bc0f653e1u, 0x2f2967b66737e3edu,
            0x8b865b215899f46cu, 0xbd79e0d20082ee74u, 0xae67f1e9aec07187u, 0xecd8590680a3aa11u,
            0xda01ee641a708de9u, 0xe80e6f4820cc9495u, 0x884134fe908658b2u, 0x3109058d147fdcddu,
            0xaa51823e34a7eedeu, 0xbd4b46f0599fd415u, 0xd4e5e2cdc1d1ea96u, 0x6c9e18ac7007c91au,
            0x850fadc09923329eu, 0x03e2cf6bc604ddb0u, 0xa6539930bf6bff45u, 0x84db8346b786151cu,
            0xcfe87f7cef46ff16u, 0xe612641865679a63u, 0x81f14fae158c5f6eu, 0x4fcb7e8f3f60c07eu,
            0xa26da3999aef7749u, 0xe3be5e330f38f09du, 0xcb090c8001ab551cu, 0x5cadf5bfd3072cc5u,
            0xfdcb4fa002162a63u, 0x73d9732fc7c8f7f6u, 0x9e9f11c4014dda7eu, 0x2867e7fddcdd9afau,
            0xc646d63501a1511du, 0xb281e1fd541501b8u, 0xf7d88bc24209a565u, 0x1f225a7ca91a4226u,
            0x9ae757596946075fu, 0x3375788de9b06958u, 0xc1a12d2fc3978937u, 0x0052d6b1641c83aeu,
            0xf209787bb47d6b84u, 0xc0678c5dbd23a49au, 0x9745eb4d50ce6332u, 0xf840b7ba963646e0u,
            0xbd176620a501fbffu, 0xb650e5a93bc3d898u, 0xec5d3fa8ce427affu, 0xa3e51f138ab4cebeu,
            0x93ba47c980e98cdfu, 0xc66f336c36b10137u, 0xb8a8d9bbe123f017u, 0xb80b0047445d4184u,
            0xe6d3102ad96cec1du, 0xa60dc059157491e5u, 0x9043ea1ac7e41392u, 0x87c89837ad68db2fu,
            0xb454e4a179dd1877u, 0x29babe4598c311fbu, 0xe16a1dc9d8545e94u, 0xf4296dd6fef3d67au,
            0x8ce2529e2734bb1du, 0x1899e4a65f58660cu, 0xb01ae745b101e9e4u, 0x5ec05dcff72e7f8fu,
            0xdc21a1171d42645du, 0x76707543f4fa1f73u, 0x899504ae72497ebau, 0x6a06494a791c53a8u,
            0xabfa45da0edbde69u, 0x0487db9d17636892u, 0xd6f8d7509292d603u, 0x45a9d2845d3c42b6u,
            0x865b86925b9bc5c2u, 0x0b8a2392ba45a9b2u, 0xa7f26836f282b732u, 0x8e6cac7768d7141eu,
            0xd1ef0244af2364ffu, 0x3207d795430cd926u, 0x8335616aed761f1fu, 0x7f44e6bd49e807b8u,
            0xa402b9c5a8d3a6e7u, 0x5f16206c9c6209a6u, 0xcd036837130890a1u, 0x36dba887c37a8c0fu,
            0x802221226be55a64u, 0xc2494954da2c9789u, 0xa02aa96b06deb0fdu, 0xf2db9baa10b7bd6cu,
            0xc83553c5c8965d3du, 0x6f92829494e5acc7u, 0xfa42a8b73abbf48cu, 0xcb772339ba1f17f9u,
            0x9c69a97284b578d7u, 0xff2a760414536efbu, 0xc38413cf25e2d70du, 0xfef5138519684abau,
            0xf46518c2ef5b8cd1u, 0x7eb258665fc25d69u, 0x98bf2f79d5993802u, 0xef2f773ffbd97a61u,
            0xbeeefb584aff8603u, 0xaafb550ffacfd8fau, 0xeeaaba2e5dbf6784u, 0x95ba2a53f983cf38u,
            0x952ab45cfa97a0b2u, 0xdd945a747bf26183u, 0xba756174393d88dfu, 0x94f971119aeef9e4u,
            0xe912b9d1478ceb17u, 0x7a37cd5601aab85du, 0x91abb422ccb812eeu, 0xac62e055c10ab33au,
            0xb616a12b7fe617aau, 0x577b986b314d6009u, 0xe39c49765fdf9d94u, 0xed5a7e85fda0b80bu,
            0x8e41ade9fbebc27du, 0x14588f13be847307u, 0xb1d219647ae6b31cu, 0x596eb2d8ae258fc8u,
            0xde469fbd99a05fe3u, 0x6fca5f8ed9aef3bbu, 0x8aec23d680043beeu, 0x25de7bb9480d5854u,
            0xada72ccc20054ae9u, 0xaf561aa79a10ae6au, 0xd910f7ff28069da4u, 0x1b2ba1518094da04u,
            0x87aa9aff79042286u, 0x90fb44d2f05d0842u, 0xa99541bf57452b28u, 0x353a1607ac744a53u,
            0xd3fa922f2d1675f2u, 0x42889b8997915ce8u, 0x847c9b5d7c2e09b7u, 0x69956135febada11u,
            0xa59bc234db398c25u, 0x43fab9837e699095u, 0xcf02b2c21207ef2eu, 0x94f967e45e03f4bbu,
            0x8161afb94b44f57du, 0x1d1be0eebac278f5u, 0xa1ba1ba79e1632dcu, 0x6462d92a69731732u,
            0xca28a291859bbf93u, 0x7d7b8f7503cfdcfeu, 0xfcb2cb35e702af78u, 0x5cda735244c3d43eu,
            0x9defbf01b061adabu, 0x3a0888136afa64a7u, 0xc56baec21c7a1916u, 0x088aaa1845b8fdd0u,
            0xf6c69a72a3989f5bu, 0x8aad549e57273d45u, 0x9a3c2087a63f6399u, 0x36ac54e2f678864bu,
            0xc0cb28a98fcf3c7fu, 0x84576a1bb416a7ddu, 0xf0fdf2d3f3c30b9fu, 0x656d44a2a11c51d5u,
            0x969eb7c47859e743u, 0x9f644ae5a4b1b325u, 0xbc4665b596706114u, 0x873d5d9f0dde1feeu,
            0xeb57ff22fc0c7959u, 0xa90cb506d155a7eau, 0x9316ff75dd87cbd8u, 0x09a7f12442d588f2u,
            0xb7dcbf5354e9beceu, 0x0c11ed6d538aeb2fu, 0xe5d3ef282a242e81u, 0x8f1668c8a86da5fau,
            0x8fa475791a569d10u, 0xf96e017d694487bcu, 0xb38d92d760ec4455u, 0x37c981dcc395a9acu,
            0xe070f78d3927556au, 0x85bbe253f47b1417u, 0x8c469ab843b89562u, 0x93956d7478ccec8eu,
            0xaf58416654a6babbu, 0x387ac8d1970027b2u, 0xdb2e51bfe9d0696au, 0x06997b05fcc0319eu,
            0x88fcf317f22241e2u, 0x441fece3bdf81f03u, 0xab3c2fddeeaad25au, 0xd527e81cad7626c3u,
            0xd60b3bd56a5586f1u, 0x8a71e223d8d3b074u, 0x85c7056562757456u, 0xf6872d5667844e49u,
            0xa738c6bebb12d16cu, 0xb428f8ac016561dbu, 0xd106f86e69d785c7u, 0xe13336d701beba52u,
            0x82a45b450226b39cu, 0xecc0024661173473u, 0xa34d721642b06084u, 0x27f002d7f95d0190u,
            0xcc20ce9bd35c78a5u, 0x31ec038df7b441f4u, 0xff290242c83396ceu, 0x7e67047175a15271u,
            0x9f79a169bd203e41u, 0x0f0062c6e984d386u, 0xc75809c42c684dd1u, 0x52c07b78a3e60868u,
            0xf92e0c3537826145u, 0xa7709a56ccdf8a82u, 0x9bbcc7a142b17ccbu, 0x88a66076400bb691u,
            0xc2abf989935ddbfeu, 0x6acff893d00ea435u, 0xf356f7ebf83552feu, 0x0583f6b8c4124d43u,
            0x98165af37b2153deu, 0xc3727a337a8b704au, 0xbe1bf1b059e9a8d6u, 0x744f18c0592e4c5cu,
            0xeda2ee1c7064130cu, 0x1162def06f79df73u, 0x9485d4d1c63e8be7u, 0x8addcb5645ac2ba8u,
            0xb9a74a0637ce2ee1u, 0x6d953e2bd7173692u, 0xe8111c87c5c1ba99u, 0xc8fa8db6ccdd0437u,
            0x910ab1d4db9914a0u, 0x1d9c9892400a22a2u, 0xb54d5e4a127f59c8u, 0x2503beb6d00cab4bu,
            0xe2a0b5dc971f303au, 0x2e44ae64840fd61du, 0x8da471a9de737e24u, 0x5ceaecfed289e5d2u,
            0xb10d8e1456105dadu, 0x7425a83e872c5f47u, 0xdd50f1996b947518u, 0xd12f124e28f77719u,
            0x8a5296ffe33cc92fu, 0x82bd6b70d99aaa6fu, 0xace73cbfdc0bfb7bu, 0x636cc64d1001550bu,
            0xd8210befd30efa5au, 0x3c47f7e05401aa4eu, 0x8714a775e3e95c78u, 0x65acfaec34810a71u,
            0xa8d9d1535ce3b396u, 0x7f1839a741a14d0du, 0xd31045a8341ca07cu, 0x1ede48111209a050u,
            0x83ea2b892091e44du, 0x934aed0aab460432u, 0xa4e4b66b68b65d60u, 0xf81da84d5617853fu,
            0xce1de40642e3f4b9u, 0x36251260ab9d668eu, 0x80d2ae83e9ce78f3u, 0xc1d72b7c6b426019u,
            0xa1075a24e4421730u, 0xb24cf65b8612f81fu, 0xc94930ae1d529cfcu, 0xdee033f26797b627u,
            0xfb9b7cd9a4a7443cu, 0x169840ef017da3b1u, 0x9d412e0806e88aa5u, 0x8e1f289560ee864eu,
            0xc491798a08a2ad4eu, 0xf1a6f2bab92a27e2u, 0xf5b5d7ec8acb58a2u, 0xae10af696774b1dbu,
            0x9991a6f3d6bf1765u, 0xacca6da1e0a8ef29u, 0xbff610b0cc6edd3fu, 0x17fd090a58d32af3u,
            0xeff394dcff8a948eu, 0xddfc4b4cef07f5b0u, 0x95f83d0a1fb69cd9u, 0x4abdaf101564f98eu,
            0xbb764c4ca7a4440fu, 0x9d6d1ad41abe37f1u, 0xea53df5fd18d5513u, 0x84c86189216dc5edu,
            0x92746b9be2f8552cu, 0x32fd3cf5b4e49bb4u, 0xb7118682dbb66a77u, 0x3fbc8c33221dc2a1u,
            0xe4d5e82392a40515u, 0x0fabaf3feaa5334au, 0x8f05b1163ba6832du, 0x29cb4d87f2a7400eu,
            0xb2c71d5bca9023f8u, 0x743e20e9ef511012u, 0xdf78e4b2bd342cf6u, 0x914da9246b255416u,
            0x8bab8eefb6409c1au, 0x1ad089b6c2f7548eu, 0xae9672aba3d0c320u, 0xa184ac2473b529b1u,
            0xda3c0f568cc4f3e8u, 0xc9e5d72d90a2741eu, 0x8865899617fb1871u, 0x7e2fa67c7a658892u,
            0xaa7eebfb9df9de8du, 0xddbb901b98feeab7u, 0xd51ea6fa85785631u, 0x552a74227f3ea565u,
            0x8533285c936b35deu, 0xd53a88958f87275fu, 0xa67ff273b8460356u, 0x8a892abaf368f137u,
            0xd01fef10a657842cu, 0x2d2b7569b0432d85u, 0x8213f56a67f6b29bu, 0x9c3b29620e29fc73u,
            0xa298f2c501f45f42u, 0x8349f3ba91b47b8fu, 0xcb3f2f7642717713u, 0x241c70a936219a73u,
            0xfe0efb53d30dd4d7u, 0xed238cd383aa0110u, 0x9ec95d1463e8a506u, 0xf4363804324a40aau,
            0xc67bb4597ce2ce48u, 0xb143c6053edcd0d5u, 0xf81aa16fdc1b81dau, 0xdd94b7868e94050au,
            0x9b10a4e5e9913128u, 0xca7cf2b4191c8326u, 0xc1d4ce1f63f57d72u, 0xfd1c2f611f63a3f0u,
            0xf24a01a73cf2dccfu, 0xbc633b39673c8cecu, 0x976e41088617ca01u, 0xd5be0503e085d813u,
            0xbd49d14aa79dbc82u, 0x4b2d8644d8a74e18u, 0xec9c459d51852ba2u, 0xddf8e7d60ed1219eu,
            0x93e1ab8252f33b45u, 0xcabb90e5c942b503u, 0xb8da1662e7b00a17u, 0x3d6a751f3b936243u,
            0xe7109bfba19c0c9du, 0x0cc512670a783ad4u, 0x906a617d450187e2u, 0x27fb2b80668b24c5u,
            0xb484f9dc9641e9dau, 0xb1f9f660802dedf6u, 0xe1a63853bbd26451u, 0x5e7873f8a0396973u,
            0x8d07e33455637eb2u, 0xdb0b487b6423e1e8u, 0xb049dc016abc5e5fu, 0x91ce1a9a3d2cda62u,
            0xdc5c5301c56b75f7u, 0x7641a140cc7810fbu, 0x89b9b3e11b6329bau, 0xa9e904c87fcb0a9du,
            0xac2820d9623bf429u, 0x546345fa9fbdcd44u, 0xd732290fbacaf133u, 0xa97c177947ad4095u,
            0x867f59a9d4bed6c0u, 0x49ed8eabcccc485du, 0xa81f301449ee8c70u, 0x5c68f256bfff5a74u,
            0xd226fc195c6a2f8cu, 0x73832eec6fff3111u, 0x83585d8fd9c25db7u, 0xc831fd53c5ff7eabu,
            0xa42e74f3d032f525u, 0xba3e7ca8b77f5e55u, 0xcd3a1230c43fb26fu, 0x28ce1bd2e55f35ebu,
            0x80444b5e7aa7cf85u, 0x7980d163cf5b81b3u, 0xa0555e361951c366u, 0xd7e105bcc332621fu,
            0xc86ab5c39fa63440u, 0x8dd9472bf3fefaa7u, 0xfa856334878fc150u, 0xb14f98f6f0feb951u,
            0x9c935e00d4b9d8d2u, 0x6ed1bf9a569f33d3u, 0xc3b8358109e84f07u, 0x0a862f80ec4700c8u,
            0xf4a642e14c6262c8u, 0xcd27bb612758c0fau, 0x98e7e9cccfbd7dbdu, 0x8038d51cb897789cu,
            0xbf21e44003acdd2cu, 0xe0470a63e6bd56c3u, 0xeeea5d5004981478u, 0x1858ccfce06cac74u,
            0x95527a5202df0ccbu, 0x0f37801e0c43ebc8u, 0xbaa718e68396cffdu, 0xd30560258f54e6bau,
            0xe950df20247c83fdu, 0x47c6b82ef32a2069u, 0x91d28b7416cdd27eu, 0x4cdc331d57fa5441u,
            0xb6472e511c81471du, 0xe0133fe4adf8e952u, 0xe3d8f9e563a198e5u, 0x58180fddd97723a6u,
            0x8e679c2f5e44ff8fu, 0x570f09eaa7ea7648u,
        }
    };
    return table;
}
}  
NLOHMANN_JSON_NAMESPACE_END
#if defined(JSON_HAS_CPP_17) && defined(__has_include)
    #if __has_include(<charconv>)
        #include <charconv> 
        #include <system_error> 
    #endif
#endif
NLOHMANN_JSON_NAMESPACE_BEGIN
namespace detail
{
template<typename NumberUnsignedType>
bool parse_integer_unsigned(const char* first, const char* last, NumberUnsignedType& value) noexcept
{
    std::uint64_t x = 0;
    constexpr std::uint64_t cutoff = (std::numeric_limits<std::uint64_t>::max)() / 10u;
    constexpr std::uint64_t cutlim = (std::numeric_limits<std::uint64_t>::max)() % 10u;
    for (const char* p = first; p != last; ++p)
    {
        const auto digit = static_cast<std::uint64_t>(static_cast<unsigned char>(*p) - static_cast<unsigned char>('0'));
        if (JSON_HEDLEY_UNLIKELY(x > cutoff || (x == cutoff && digit > cutlim)))
        {
            return false;
        }
        x = (x * 10u) + digit;
    }
    value = static_cast<NumberUnsignedType>(x);
    return static_cast<std::uint64_t>(value) == x;
}
template<typename NumberIntegerType>
bool parse_integer_signed(const char* first, const char* last, NumberIntegerType& value) noexcept
{
    JSON_ASSERT(first != last && *first == '-');
    std::uint64_t magnitude = 0;
    constexpr std::uint64_t limit = static_cast<std::uint64_t>((std::numeric_limits<std::int64_t>::max)()) + 1u;
    for (const char* p = first + 1; p != last; ++p)
    {
        const auto digit = static_cast<std::uint64_t>(static_cast<unsigned char>(*p) - static_cast<unsigned char>('0'));
        if (JSON_HEDLEY_UNLIKELY(magnitude > (limit - digit) / 10u))
        {
            return false;
        }
        magnitude = (magnitude * 10u) + digit;
    }
    const std::int64_t x = (magnitude == limit)
                           ? (std::numeric_limits<std::int64_t>::min)()
                           : -static_cast<std::int64_t>(magnitude);
    value = static_cast<NumberIntegerType>(x);
    return static_cast<std::int64_t>(value) == x;
}
inline bool parse_float_fast(const char* first, const char* last, double& out) noexcept
{
#if defined(FLT_EVAL_METHOD) && FLT_EVAL_METHOD != 0
    static_cast<void>(first);
    static_cast<void>(last);
    static_cast<void>(out);
    return false;
#else
    static const std::array<double, 23> powers_of_ten =
    {
        {
            1e0, 1e1, 1e2, 1e3, 1e4, 1e5, 1e6, 1e7, 1e8, 1e9, 1e10, 1e11,
            1e12, 1e13, 1e14, 1e15, 1e16, 1e17, 1e18, 1e19, 1e20, 1e21, 1e22
        }
    };
    const char* p = first;
    bool negative = false;
    if (p != last && (*p == '-' || *p == '+'))
    {
        negative = (*p == '-');
        ++p;
    }
    std::uint64_t significand = 0;
    int num_digits = 0;
    int fractional_digits = 0;
    bool seen_dot = false;
    bool any_digit = false;
    for (; p != last; ++p)
    {
        const char c = *p;
        if (c >= '0' && c <= '9')
        {
            any_digit = true;
            if (JSON_HEDLEY_UNLIKELY(num_digits >= 19))
            {
                return false; 
            }
            significand = (significand * 10u) + static_cast<std::uint64_t>(c - '0');
            ++num_digits;
            fractional_digits += static_cast<int>(seen_dot);
        }
        else if (c == '.')
        {
            if (JSON_HEDLEY_UNLIKELY(seen_dot))
            {
                return false;
            }
            seen_dot = true;
        }
        else if (c == 'e' || c == 'E')
        {
            ++p;
            break;
        }
        else
        {
            return false;
        }
    }
    if (JSON_HEDLEY_UNLIKELY(!any_digit))
    {
        return false;
    }
    int exponent = 0;
    if (p != last) 
    {
        bool exp_negative = false;
        if (p != last && (*p == '-' || *p == '+'))
        {
            exp_negative = (*p == '-');
            ++p;
        }
        bool any_exp_digit = false;
        for (; p != last; ++p)
        {
            if (JSON_HEDLEY_UNLIKELY(*p < '0' || *p > '9'))
            {
                return false;
            }
            exponent = (exponent * 10) + (*p - '0');
            any_exp_digit = true;
            if (JSON_HEDLEY_UNLIKELY(exponent > 9999))
            {
                return false;
            }
        }
        if (JSON_HEDLEY_UNLIKELY(!any_exp_digit))
        {
            return false;
        }
        if (exp_negative)
        {
            exponent = -exponent;
        }
    }
    const int scale = exponent - fractional_digits;
    if (JSON_HEDLEY_UNLIKELY(significand >= (static_cast<std::uint64_t>(1) << 53)))
    {
        return false; 
    }
    auto result = static_cast<double>(significand);
    if (scale >= 0)
    {
        if (JSON_HEDLEY_UNLIKELY(scale > 22))
        {
            return false;
        }
        result *= powers_of_ten[static_cast<std::size_t>(scale)];
    }
    else
    {
        if (JSON_HEDLEY_UNLIKELY(-scale > 22))
        {
            return false;
        }
        result /= powers_of_ten[static_cast<std::size_t>(-scale)];
    }
    out = negative ? -result : result;
    return true;
#endif
}
template<typename FloatType>
bool parse_float_fast(const char* , const char* , FloatType& ) noexcept
{
    return false;
}
template<typename FloatType>
bool parse_float_from_chars(const char* first, const char* last, FloatType& out) noexcept
{
#if defined(JSON_HAS_CPP_17) && defined(__cpp_lib_to_chars)
    const auto result = std::from_chars(first, last, out);
    return result.ec == std::errc() && result.ptr == last;
#else
    static_cast<void>(first);
    static_cast<void>(last);
    static_cast<void>(out);
    return false;
#endif
}
inline bool is_eight_digits(std::uint64_t v) noexcept
{
    return ((v & 0xF0F0F0F0F0F0F0F0u) | (((v + 0x0606060606060606u) & 0xF0F0F0F0F0F0F0F0u) >> 4u)) == 0x3333333333333333u;
}
inline std::uint32_t parse_eight_digits(std::uint64_t v) noexcept
{
    v = ((v & 0x0F0F0F0F0F0F0F0Fu) * 2561u) >> 8u;
    v = ((v & 0x00FF00FF00FF00FFu) * 6553601u) >> 16u;
    return static_cast<std::uint32_t>(((v & 0x0000FFFF0000FFFFu) * 42949672960001u) >> 32u);
}
inline std::uint64_t eisel_lemire(std::int64_t q, std::uint64_t w) noexcept
{
    constexpr int mantissa_bits = 52;
    constexpr std::uint64_t infinity = std::uint64_t{0x7FF} << mantissa_bits;
    if (q < pow5_128_smallest_power)
    {
        return 0;
    }
    if (q > pow5_128_largest_power)
    {
        return infinity;
    }
    const int lz = count_leading_zeros(w);
    w <<= static_cast<unsigned>(lz);
    const auto index = static_cast<std::size_t>(2 * (q - pow5_128_smallest_power));
    uint128_parts product = full_multiplication(w, pow5_128()[index]);
    constexpr std::uint64_t precision_mask = 0xFFFFFFFFFFFFFFFFu >> (mantissa_bits + 3);
    if ((product.high & precision_mask) == precision_mask)
    {
        const uint128_parts second = full_multiplication(w, pow5_128()[index + 1]);
        product.low += second.high;
        if (second.high > product.low)
        {
            ++product.high;
        }
    }
    const auto upperbit = static_cast<int>(product.high >> 63u);
    const int shift = upperbit + 64 - mantissa_bits - 3;
    std::uint64_t mantissa = product.high >> static_cast<unsigned>(shift);
    std::int64_t power2 = (((152170 + 65536) * q) >> 16) + 63 + upperbit - lz + 1023;
    if (power2 <= 0) 
    {
        if (-power2 + 1 >= 64)
        {
            return 0;
        }
        mantissa >>= static_cast<unsigned>(-power2 + 1);
        mantissa += (mantissa & 1u);
        mantissa >>= 1u;
        power2 = (mantissa < (std::uint64_t{1} << mantissa_bits)) ? 0 : 1;
        return mantissa | (static_cast<std::uint64_t>(power2) << mantissa_bits);
    }
    if (product.low <= 1 && q >= -4 && q <= 23 && (mantissa & 3u) == 1
            && (mantissa << static_cast<unsigned>(shift)) == product.high)
    {
        mantissa &= ~std::uint64_t{1};
    }
    mantissa += (mantissa & 1u);
    mantissa >>= 1u;
    if (mantissa >= (std::uint64_t{2} << mantissa_bits))
    {
        mantissa = std::uint64_t{1} << mantissa_bits;
        ++power2;
    }
    mantissa &= ~(std::uint64_t{1} << mantissa_bits);
    if (power2 >= 0x7FF)
    {
        return infinity;
    }
    return mantissa | (static_cast<std::uint64_t>(power2) << mantissa_bits);
}
inline bool parse_float_eisel_lemire(const char* first, const char* last, double& out) noexcept
{
    const char* p = first;
    const bool negative = (p != last && *p == '-');
    if (negative)
    {
        ++p;
    }
    std::uint64_t w = 0;
    unsigned int digits = 0; 
    std::int64_t exponent = 0;
    bool truncated = false;
    bool in_fraction = false;
    for (;;)
    {
        while (w != 0 && digits <= 19u - 8u && last - p >= 8)
        {
            const std::uint64_t v = read_eight_bytes(p);
            if (!is_eight_digits(v))
            {
                break;
            }
            w = (w * 100000000u) + parse_eight_digits(v);
            digits += 8u;
            exponent -= in_fraction ? 8 : 0;
            p += 8;
        }
        if (p == last)
        {
            break;
        }
        const char c = *p;
        if (c >= '0' && c <= '9')
        {
            if (w == 0 && c == '0')
            {
                exponent -= in_fraction ? 1 : 0;
            }
            else if (digits < 19u)
            {
                w = (w * 10u) + static_cast<std::uint64_t>(c - '0');
                ++digits;
                exponent -= in_fraction ? 1 : 0;
            }
            else
            {
                truncated = truncated || c != '0';
                exponent += in_fraction ? 0 : 1;
            }
            ++p;
        }
        else if (c == '.')
        {
            in_fraction = true;
            ++p;
        }
        else
        {
            break; 
        }
    }
    if (p != last)
    {
        ++p; 
        bool exp_negative = false;
        if (p != last && (*p == '-' || *p == '+'))
        {
            exp_negative = (*p == '-');
            ++p;
        }
        std::int64_t exp_value = 0;
        for (; p != last; ++p)
        {
            if (exp_value < 100000)
            {
                exp_value = (exp_value * 10) + (*p - '0');
            }
        }
        exponent += exp_negative ? -exp_value : exp_value;
    }
    std::uint64_t bits = 0;
    if (w != 0)
    {
        bits = eisel_lemire(exponent, w);
        if (truncated && (w + 1 == 0 || eisel_lemire(exponent, w + 1) != bits))
        {
            return false;
        }
    }
    bits |= negative ? (std::uint64_t{1} << 63u) : 0u;
    static_assert(sizeof(double) == sizeof(std::uint64_t), "double must have 64 bits");
    std::memcpy(&out, &bits, sizeof(out));
    return true;
}
template<typename FloatType>
bool parse_float_eisel_lemire(const char* , const char* , FloatType& ) noexcept
{
    return false;
}
inline bool mantissa_fits_clinger(const char* token, std::size_t decimal_point_position, std::size_t mantissa_end) noexcept
{
    constexpr std::size_t limit = 17;
    const std::size_t neg = (token[0] == '-') ? 1u : 0u;
    const std::size_t has_dot = (decimal_point_position != std::string::npos) ? 1u : 0u;
    const std::size_t lead_zero = (token[neg] == '0') ? 1u : 0u;
    JSON_ASSERT(mantissa_end >= neg + has_dot + lead_zero);
    std::size_t digits = mantissa_end - neg - has_dot - lead_zero;
    if (JSON_HEDLEY_LIKELY(digits < limit))
    {
        return true;
    }
    if (lead_zero != 0)
    {
        JSON_ASSERT(has_dot != 0); 
        for (std::size_t i = decimal_point_position + 1;
                digits >= limit && i < mantissa_end && token[i] == '0'; ++i)
        {
            --digits;
        }
    }
    return digits < limit;
}
template<typename FloatType>
bool convert_float_fast(const char* first, const char* last, std::size_t decimal_point_position,
                        std::size_t mantissa_end, FloatType& value) noexcept
{
    if (parse_float_from_chars(first, last, value))
    {
        return true;
    }
    if (mantissa_fits_clinger(first, decimal_point_position, mantissa_end)
            && parse_float_fast(first, last, value))
    {
        return true;
    }
    return parse_float_eisel_lemire(first, last, value);
}
JSON_HEDLEY_NON_NULL(2)
inline void strtof_by_type(float& f, const char* str, char** endptr) noexcept
{
    f = std::strtof(str, endptr);
}
JSON_HEDLEY_NON_NULL(2)
inline void strtof_by_type(double& f, const char* str, char** endptr) noexcept
{
    f = std::strtod(str, endptr);
}
JSON_HEDLEY_NON_NULL(2)
inline void strtof_by_type(long double& f, const char* str, char** endptr) noexcept
{
    f = std::strtold(str, endptr);
}
inline char get_decimal_point() noexcept
{
    const auto* loc = localeconv();
    JSON_ASSERT(loc != nullptr);
    return (loc->decimal_point == nullptr) ? '.' : *(loc->decimal_point);
}
template<typename StringType, typename FloatType>
void convert_float_locale_aware(StringType& token, std::size_t decimal_point_position, FloatType& value)
{
    const bool has_dot = decimal_point_position != std::string::npos;
    char decimal_point = get_decimal_point();
    for (;;)
    {
        const bool substitute = has_dot && decimal_point != '.';
        if (substitute)
        {
            token[decimal_point_position] = static_cast<typename StringType::value_type>(decimal_point);
        }
        char* endptr = nullptr; 
        strtof_by_type(value, token.data(), &endptr);
        if (substitute)
        {
            token[decimal_point_position] = '.';
        }
        if (JSON_HEDLEY_LIKELY(endptr == token.data() + token.size()))
        {
            return;
        }
        const char current_decimal_point = get_decimal_point();
        if (current_decimal_point == decimal_point)
        {
            return;
        }
        decimal_point = current_decimal_point;
    }
}
}  
NLOHMANN_JSON_NAMESPACE_END
#include <cstddef> 
#include <cstdint> 
#include <cstring> 
#if defined(JSON_USE_SIMDUTF) && defined(JSON_HAS_CPP_17)
    #include <simdutf.h>
#endif
NLOHMANN_JSON_NAMESPACE_BEGIN
namespace detail
{
inline bool is_string_special(unsigned char c) noexcept
{
    return c == '\"' || c == '\\' || c < 0x20u || c >= 0x80u;
}
inline std::uint64_t swar_string_special(std::uint64_t v) noexcept
{
    constexpr std::uint64_t ones = 0x0101010101010101ull;
    constexpr std::uint64_t high = 0x8080808080808080ull;
    const std::uint64_t q = v ^ 0x2222222222222222ull; 
    const std::uint64_t b = v ^ 0x5C5C5C5C5C5C5C5Cull; 
    const std::uint64_t has_quote     = (q - ones) & ~q & high;
    const std::uint64_t has_backslash = (b - ones) & ~b & high;
    const std::uint64_t has_control   = (v - 0x2020202020202020ull) & ~v & high; 
    const std::uint64_t has_non_ascii = v & high;                                
    return has_quote | has_backslash | has_control | has_non_ascii;
}
inline std::size_t find_string_special(const unsigned char* data, std::size_t n) noexcept
{
    std::size_t i = 0;
    for (; i + 8 <= n; i += 8)
    {
        std::uint64_t word = 0;
        std::memcpy(&word, data + i, sizeof(word));
        if (swar_string_special(word) != 0)
        {
            for (std::size_t j = 0; j < 8; ++j)
            {
                if (is_string_special(data[i + j]))
                {
                    return i + j;
                }
            }
        }
    }
    for (; i < n; ++i)
    {
        if (is_string_special(data[i]))
        {
            return i;
        }
    }
    return n;
}
inline bool is_ascii_copyable(unsigned char c) noexcept
{
    return c >= 0x20u && c < 0x7Fu && c != '"' && c != '\\';
}
inline std::size_t find_ascii_copyable_run(const unsigned char* data, std::size_t n) noexcept
{
    constexpr std::uint64_t ones = 0x0101010101010101ull;
    constexpr std::uint64_t high = 0x8080808080808080ull;
    std::size_t i = 0;
    for (; i + 8 <= n; i += 8)
    {
        std::uint64_t v = 0;
        std::memcpy(&v, data + i, sizeof(v));
        const std::uint64_t q = v ^ 0x2222222222222222ull; 
        const std::uint64_t b = v ^ 0x5C5C5C5C5C5C5C5Cull; 
        const std::uint64_t d = v ^ 0x7F7F7F7F7F7F7F7Full; 
        const std::uint64_t stop = ((q - ones) & ~q & high)   
                                   | ((b - ones) & ~b & high)  
                                   | ((d - ones) & ~d & high)  
                                   | ((v - 0x2020202020202020ull) & ~v & high) 
                                   | (v & high);               
        if (stop != 0)
        {
            break;
        }
    }
    for (; i < n; ++i)
    {
        if (!is_ascii_copyable(data[i]))
        {
            return i;
        }
    }
    return n;
}
inline std::size_t validate_one_utf8(const unsigned char* data, std::size_t avail) noexcept
{
    const unsigned char c0 = data[0];
    if (c0 >= 0xC2 && c0 <= 0xDF)  
    {
        if (avail >= 2 && data[1] >= 0x80 && data[1] <= 0xBF)
        {
            return 2;
        }
    }
    else if (c0 == 0xE0)  
    {
        if (avail >= 3 && data[1] >= 0xA0 && data[1] <= 0xBF && data[2] >= 0x80 && data[2] <= 0xBF)
        {
            return 3;
        }
    }
    else if ((c0 >= 0xE1 && c0 <= 0xEC) || c0 == 0xEE || c0 == 0xEF)  
    {
        if (avail >= 3 && data[1] >= 0x80 && data[1] <= 0xBF && data[2] >= 0x80 && data[2] <= 0xBF)
        {
            return 3;
        }
    }
    else if (c0 == 0xED)  
    {
        if (avail >= 3 && data[1] >= 0x80 && data[1] <= 0x9F && data[2] >= 0x80 && data[2] <= 0xBF)
        {
            return 3;
        }
    }
    else if (c0 == 0xF0)  
    {
        if (avail >= 4 && data[1] >= 0x90 && data[1] <= 0xBF && data[2] >= 0x80 && data[2] <= 0xBF && data[3] >= 0x80 && data[3] <= 0xBF)
        {
            return 4;
        }
    }
    else if (c0 >= 0xF1 && c0 <= 0xF3)  
    {
        if (avail >= 4 && data[1] >= 0x80 && data[1] <= 0xBF && data[2] >= 0x80 && data[2] <= 0xBF && data[3] >= 0x80 && data[3] <= 0xBF)
        {
            return 4;
        }
    }
    else if (c0 == 0xF4)  
    {
        if (avail >= 4 && data[1] >= 0x80 && data[1] <= 0x8F && data[2] >= 0x80 && data[2] <= 0xBF && data[3] >= 0x80 && data[3] <= 0xBF)
        {
            return 4;
        }
    }
    return 0; 
}
inline std::size_t valid_utf8_prefix(const unsigned char* data, std::size_t n) noexcept
{
    constexpr std::uint64_t high = 0x8080808080808080ull;
    std::size_t pos = 0;
    while (pos < n)
    {
        if (pos + 8 <= n)
        {
            std::uint64_t word = 0;
            std::memcpy(&word, data + pos, sizeof(word));
            if ((word & high) == 0)
            {
                pos += 8;
                continue;
            }
        }
        if (data[pos] < 0x80u)
        {
            ++pos;
            continue;
        }
        const std::size_t seq = validate_one_utf8(data + pos, n - pos);
        if (seq == 0)
        {
            break; 
        }
        pos += seq;
    }
    return pos;
}
inline std::size_t scalar_string_bulk_run(const unsigned char* data, std::size_t n) noexcept
{
    std::size_t pos = 0;
    while (pos < n)
    {
        pos += find_string_special(data + pos, n - pos);
        if (pos >= n || data[pos] < 0x80u)
        {
            break; 
        }
        const std::size_t seq = validate_one_utf8(data + pos, n - pos);
        if (seq == 0)
        {
            break; 
        }
        pos += seq;
    }
    return pos;
}
#if defined(JSON_USE_SIMDUTF) && defined(JSON_HAS_CPP_17)
inline std::size_t find_string_delimiter(const unsigned char* data, std::size_t n) noexcept
{
    constexpr std::uint64_t ones = 0x0101010101010101ull;
    constexpr std::uint64_t high = 0x8080808080808080ull;
    std::size_t i = 0;
    for (; i + 8 <= n; i += 8)
    {
        std::uint64_t v = 0;
        std::memcpy(&v, data + i, sizeof(v));
        const std::uint64_t q = v ^ 0x2222222222222222ull;
        const std::uint64_t b = v ^ 0x5C5C5C5C5C5C5C5Cull;
        const std::uint64_t hit = ((q - ones) & ~q & high)
                                  | ((b - ones) & ~b & high)
                                  | ((v - 0x2020202020202020ull) & ~v & high);
        if (hit != 0)
        {
            for (std::size_t j = 0; j < 8; ++j)
            {
                const unsigned char c = data[i + j];
                if (c == '\"' || c == '\\' || c < 0x20u)
                {
                    return i + j;
                }
            }
        }
    }
    for (; i < n; ++i)
    {
        const unsigned char c = data[i];
        if (c == '\"' || c == '\\' || c < 0x20u)
        {
            return i;
        }
    }
    return n;
}
#endif
inline std::size_t string_bulk_run(const unsigned char* data, std::size_t n) noexcept
{
#if defined(JSON_USE_SIMDUTF) && defined(JSON_HAS_CPP_17)
    const std::size_t run = find_string_delimiter(data, n);
    if (run != 0 && simdutf::validate_utf8(reinterpret_cast<const char*>(data), run))
    {
        return run;
    }
#endif
    return scalar_string_bulk_run(data, n);
}
}  
NLOHMANN_JSON_NAMESPACE_END
NLOHMANN_JSON_NAMESPACE_BEGIN
namespace detail
{
template<typename BasicJsonType>
class lexer_base
{
  public:
    enum class token_type
    {
        uninitialized,    
        literal_true,     
        literal_false,    
        literal_null,     
        value_string,     
        value_unsigned,   
        value_integer,    
        value_float,      
        begin_array,      
        begin_object,     
        end_array,        
        end_object,       
        name_separator,   
        value_separator,  
        parse_error,      
        end_of_input,     
        literal_or_value  
    };
    JSON_HEDLEY_RETURNS_NON_NULL
    JSON_HEDLEY_CONST
    static const char* token_type_name(const token_type t) noexcept
    {
        switch (t)
        {
            case token_type::uninitialized:
                return "<uninitialized>";
            case token_type::literal_true:
                return "true literal";
            case token_type::literal_false:
                return "false literal";
            case token_type::literal_null:
                return "null literal";
            case token_type::value_string:
                return "string literal";
            case token_type::value_unsigned:
            case token_type::value_integer:
            case token_type::value_float:
                return "number literal";
            case token_type::begin_array:
                return "'['";
            case token_type::begin_object:
                return "'{'";
            case token_type::end_array:
                return "']'";
            case token_type::end_object:
                return "'}'";
            case token_type::name_separator:
                return "':'";
            case token_type::value_separator:
                return "','";
            case token_type::parse_error:
                return "<parse error>";
            case token_type::end_of_input:
                return "end of input";
            case token_type::literal_or_value:
                return "'[', '{', or a literal";
            default: 
                return "unknown token";
        }
    }
};
template<typename InputAdapterType>
using detect_supports_seek = decltype(InputAdapterType::supports_seek);
template<typename InputAdapterType>
constexpr bool input_adapter_supports_seek(std::true_type )
{
    return InputAdapterType::supports_seek;
}
template<typename InputAdapterType>
constexpr bool input_adapter_supports_seek(std::false_type )
{
    return false;
}
template<typename InputAdapterType>
using detect_supports_lookahead = decltype(InputAdapterType::supports_lookahead);
template<typename InputAdapterType>
constexpr bool input_adapter_supports_lookahead(std::true_type )
{
    return InputAdapterType::supports_lookahead;
}
template<typename InputAdapterType>
constexpr bool input_adapter_supports_lookahead(std::false_type )
{
    return false;
}
template<typename InputAdapterType>
using detect_supports_bulk_scan = decltype(InputAdapterType::supports_bulk_scan);
template<typename InputAdapterType>
constexpr bool input_adapter_supports_bulk_scan(std::true_type )
{
    return InputAdapterType::supports_bulk_scan;
}
template<typename InputAdapterType>
constexpr bool input_adapter_supports_bulk_scan(std::false_type )
{
    return false;
}
template<typename BasicJsonType, typename InputAdapterType>
class lexer : public lexer_base<BasicJsonType>
{
    using number_integer_t = typename BasicJsonType::number_integer_t;
    using number_unsigned_t = typename BasicJsonType::number_unsigned_t;
    using number_float_t = typename BasicJsonType::number_float_t;
    using string_t = typename BasicJsonType::string_t;
    using char_type = typename InputAdapterType::char_type;
    using char_int_type = typename char_traits<char_type>::int_type;
    static constexpr bool lazy_token_string =
        input_adapter_supports_seek<InputAdapterType>(is_detected<detect_supports_seek, InputAdapterType> {});
    static constexpr bool can_release_lookahead =
        input_adapter_supports_lookahead<InputAdapterType>(is_detected<detect_supports_lookahead, InputAdapterType> {});
    static constexpr bool bulk_scan =
        lazy_token_string
        && input_adapter_supports_bulk_scan<InputAdapterType>(is_detected<detect_supports_bulk_scan, InputAdapterType> {});
  public:
    using token_type = typename lexer_base<BasicJsonType>::token_type;
    explicit lexer(InputAdapterType&& adapter, bool ignore_comments_ = false, bool discard_number_values_ = false) noexcept
        : ia(std::move(adapter))
        , ignore_comments(ignore_comments_)
        , discard_number_values(discard_number_values_)
    {}
    lexer(const lexer&) = delete;
    lexer(lexer&&) = default; 
    lexer& operator=(lexer&) = delete;
    lexer& operator=(lexer&&) = default; 
    ~lexer() = default;
  private:
    int get_codepoint()
    {
        JSON_ASSERT(current == 'u');
        int codepoint = 0;
        const auto factors = { 12u, 8u, 4u, 0u };
        for (const auto factor : factors)
        {
            get();
            if (current >= '0' && current <= '9')
            {
                codepoint += static_cast<int>((static_cast<unsigned int>(current) - 0x30u) << factor);
            }
            else if (current >= 'A' && current <= 'F')
            {
                codepoint += static_cast<int>((static_cast<unsigned int>(current) - 0x37u) << factor);
            }
            else if (current >= 'a' && current <= 'f')
            {
                codepoint += static_cast<int>((static_cast<unsigned int>(current) - 0x57u) << factor);
            }
            else
            {
                return -1;
            }
        }
        JSON_ASSERT(0x0000 <= codepoint && codepoint <= 0xFFFF);
        return codepoint;
    }
    bool next_byte_in_range(std::initializer_list<char_int_type> ranges)
    {
        JSON_ASSERT(ranges.size() == 2 || ranges.size() == 4 || ranges.size() == 6);
        add(current);
        for (auto range = ranges.begin(); range != ranges.end(); ++range)
        {
            get();
            if (JSON_HEDLEY_LIKELY(*range <= current && current <= *(++range))) 
            {
                add(current);
            }
            else
            {
                error_message = "invalid string: ill-formed UTF-8 byte";
                return false;
            }
        }
        return true;
    }
    void scan_string_bulk(std::true_type )
    {
        if (next_unget)
        {
            return;
        }
        const std::size_t remaining = ia.bulk_remaining();
        if (remaining == 0)
        {
            return;
        }
        const auto* const data = reinterpret_cast<const unsigned char*>(ia.bulk_data());
        const std::size_t pos = string_bulk_run(data, remaining);
        if (pos == 0)
        {
            return;
        }
        token_buffer.append(reinterpret_cast<const typename string_t::value_type*>(data), pos);
        ia.bulk_skip(pos);
        position.chars_read_total += pos;
        position.chars_read_current_line += pos;
    }
    void scan_string_bulk(std::false_type ) const noexcept {}
    token_type scan_string()
    {
        reset();
        JSON_ASSERT(current == '\"');
        while (true)
        {
            scan_string_bulk(std::integral_constant<bool, bulk_scan> {});
            switch (get())
            {
                case char_traits<char_type>::eof():
                {
                    error_message = "invalid string: missing closing quote";
                    return token_type::parse_error;
                }
                case '\"':
                {
                    return token_type::value_string;
                }
                case '\\':
                {
                    switch (get())
                    {
                        case '\"':
                            add('\"');
                            break;
                        case '\\':
                            add('\\');
                            break;
                        case '/':
                            add('/');
                            break;
                        case 'b':
                            add('\b');
                            break;
                        case 'f':
                            add('\f');
                            break;
                        case 'n':
                            add('\n');
                            break;
                        case 'r':
                            add('\r');
                            break;
                        case 't':
                            add('\t');
                            break;
                        case 'u':
                        {
                            const int codepoint1 = get_codepoint();
                            int codepoint = codepoint1; 
                            if (JSON_HEDLEY_UNLIKELY(codepoint1 == -1))
                            {
                                error_message = "invalid string: '\\u' must be followed by 4 hex digits";
                                return token_type::parse_error;
                            }
                            if (0xD800 <= codepoint1 && codepoint1 <= 0xDBFF)
                            {
                                if (JSON_HEDLEY_LIKELY(get() == '\\' && get() == 'u'))
                                {
                                    const int codepoint2 = get_codepoint();
                                    if (JSON_HEDLEY_UNLIKELY(codepoint2 == -1))
                                    {
                                        error_message = "invalid string: '\\u' must be followed by 4 hex digits";
                                        return token_type::parse_error;
                                    }
                                    if (JSON_HEDLEY_LIKELY(0xDC00 <= codepoint2 && codepoint2 <= 0xDFFF))
                                    {
                                        codepoint = static_cast<int>(
                                                        (static_cast<unsigned int>(codepoint1) << 10u)
                                                        + static_cast<unsigned int>(codepoint2)
                                                        - 0x35FDC00u);
                                    }
                                    else
                                    {
                                        error_message = "invalid string: surrogate U+D800..U+DBFF must be followed by U+DC00..U+DFFF";
                                        return token_type::parse_error;
                                    }
                                }
                                else
                                {
                                    error_message = "invalid string: surrogate U+D800..U+DBFF must be followed by U+DC00..U+DFFF";
                                    return token_type::parse_error;
                                }
                            }
                            else
                            {
                                if (JSON_HEDLEY_UNLIKELY(0xDC00 <= codepoint1 && codepoint1 <= 0xDFFF))
                                {
                                    error_message = "invalid string: surrogate U+DC00..U+DFFF must follow U+D800..U+DBFF";
                                    return token_type::parse_error;
                                }
                            }
                            JSON_ASSERT(0x00 <= codepoint && codepoint <= 0x10FFFF);
                            encode_utf8(static_cast<std::uint32_t>(codepoint), [this](std::uint32_t byte)
                            {
                                add(static_cast<char_int_type>(byte));
                            });
                            break;
                        }
                        default:
                            error_message = "invalid string: forbidden character after backslash";
                            return token_type::parse_error;
                    }
                    break;
                }
                case 0x00:
                {
                    error_message = "invalid string: control character U+0000 (NUL) must be escaped to \\u0000";
                    return token_type::parse_error;
                }
                case 0x01:
                {
                    error_message = "invalid string: control character U+0001 (SOH) must be escaped to \\u0001";
                    return token_type::parse_error;
                }
                case 0x02:
                {
                    error_message = "invalid string: control character U+0002 (STX) must be escaped to \\u0002";
                    return token_type::parse_error;
                }
                case 0x03:
                {
                    error_message = "invalid string: control character U+0003 (ETX) must be escaped to \\u0003";
                    return token_type::parse_error;
                }
                case 0x04:
                {
                    error_message = "invalid string: control character U+0004 (EOT) must be escaped to \\u0004";
                    return token_type::parse_error;
                }
                case 0x05:
                {
                    error_message = "invalid string: control character U+0005 (ENQ) must be escaped to \\u0005";
                    return token_type::parse_error;
                }
                case 0x06:
                {
                    error_message = "invalid string: control character U+0006 (ACK) must be escaped to \\u0006";
                    return token_type::parse_error;
                }
                case 0x07:
                {
                    error_message = "invalid string: control character U+0007 (BEL) must be escaped to \\u0007";
                    return token_type::parse_error;
                }
                case 0x08:
                {
                    error_message = "invalid string: control character U+0008 (BS) must be escaped to \\u0008 or \\b";
                    return token_type::parse_error;
                }
                case 0x09:
                {
                    error_message = "invalid string: control character U+0009 (HT) must be escaped to \\u0009 or \\t";
                    return token_type::parse_error;
                }
                case 0x0A:
                {
                    error_message = "invalid string: control character U+000A (LF) must be escaped to \\u000A or \\n";
                    return token_type::parse_error;
                }
                case 0x0B:
                {
                    error_message = "invalid string: control character U+000B (VT) must be escaped to \\u000B";
                    return token_type::parse_error;
                }
                case 0x0C:
                {
                    error_message = "invalid string: control character U+000C (FF) must be escaped to \\u000C or \\f";
                    return token_type::parse_error;
                }
                case 0x0D:
                {
                    error_message = "invalid string: control character U+000D (CR) must be escaped to \\u000D or \\r";
                    return token_type::parse_error;
                }
                case 0x0E:
                {
                    error_message = "invalid string: control character U+000E (SO) must be escaped to \\u000E";
                    return token_type::parse_error;
                }
                case 0x0F:
                {
                    error_message = "invalid string: control character U+000F (SI) must be escaped to \\u000F";
                    return token_type::parse_error;
                }
                case 0x10:
                {
                    error_message = "invalid string: control character U+0010 (DLE) must be escaped to \\u0010";
                    return token_type::parse_error;
                }
                case 0x11:
                {
                    error_message = "invalid string: control character U+0011 (DC1) must be escaped to \\u0011";
                    return token_type::parse_error;
                }
                case 0x12:
                {
                    error_message = "invalid string: control character U+0012 (DC2) must be escaped to \\u0012";
                    return token_type::parse_error;
                }
                case 0x13:
                {
                    error_message = "invalid string: control character U+0013 (DC3) must be escaped to \\u0013";
                    return token_type::parse_error;
                }
                case 0x14:
                {
                    error_message = "invalid string: control character U+0014 (DC4) must be escaped to \\u0014";
                    return token_type::parse_error;
                }
                case 0x15:
                {
                    error_message = "invalid string: control character U+0015 (NAK) must be escaped to \\u0015";
                    return token_type::parse_error;
                }
                case 0x16:
                {
                    error_message = "invalid string: control character U+0016 (SYN) must be escaped to \\u0016";
                    return token_type::parse_error;
                }
                case 0x17:
                {
                    error_message = "invalid string: control character U+0017 (ETB) must be escaped to \\u0017";
                    return token_type::parse_error;
                }
                case 0x18:
                {
                    error_message = "invalid string: control character U+0018 (CAN) must be escaped to \\u0018";
                    return token_type::parse_error;
                }
                case 0x19:
                {
                    error_message = "invalid string: control character U+0019 (EM) must be escaped to \\u0019";
                    return token_type::parse_error;
                }
                case 0x1A:
                {
                    error_message = "invalid string: control character U+001A (SUB) must be escaped to \\u001A";
                    return token_type::parse_error;
                }
                case 0x1B:
                {
                    error_message = "invalid string: control character U+001B (ESC) must be escaped to \\u001B";
                    return token_type::parse_error;
                }
                case 0x1C:
                {
                    error_message = "invalid string: control character U+001C (FS) must be escaped to \\u001C";
                    return token_type::parse_error;
                }
                case 0x1D:
                {
                    error_message = "invalid string: control character U+001D (GS) must be escaped to \\u001D";
                    return token_type::parse_error;
                }
                case 0x1E:
                {
                    error_message = "invalid string: control character U+001E (RS) must be escaped to \\u001E";
                    return token_type::parse_error;
                }
                case 0x1F:
                {
                    error_message = "invalid string: control character U+001F (US) must be escaped to \\u001F";
                    return token_type::parse_error;
                }
                case 0x20:
                case 0x21:
                case 0x23:
                case 0x24:
                case 0x25:
                case 0x26:
                case 0x27:
                case 0x28:
                case 0x29:
                case 0x2A:
                case 0x2B:
                case 0x2C:
                case 0x2D:
                case 0x2E:
                case 0x2F:
                case 0x30:
                case 0x31:
                case 0x32:
                case 0x33:
                case 0x34:
                case 0x35:
                case 0x36:
                case 0x37:
                case 0x38:
                case 0x39:
                case 0x3A:
                case 0x3B:
                case 0x3C:
                case 0x3D:
                case 0x3E:
                case 0x3F:
                case 0x40:
                case 0x41:
                case 0x42:
                case 0x43:
                case 0x44:
                case 0x45:
                case 0x46:
                case 0x47:
                case 0x48:
                case 0x49:
                case 0x4A:
                case 0x4B:
                case 0x4C:
                case 0x4D:
                case 0x4E:
                case 0x4F:
                case 0x50:
                case 0x51:
                case 0x52:
                case 0x53:
                case 0x54:
                case 0x55:
                case 0x56:
                case 0x57:
                case 0x58:
                case 0x59:
                case 0x5A:
                case 0x5B:
                case 0x5D:
                case 0x5E:
                case 0x5F:
                case 0x60:
                case 0x61:
                case 0x62:
                case 0x63:
                case 0x64:
                case 0x65:
                case 0x66:
                case 0x67:
                case 0x68:
                case 0x69:
                case 0x6A:
                case 0x6B:
                case 0x6C:
                case 0x6D:
                case 0x6E:
                case 0x6F:
                case 0x70:
                case 0x71:
                case 0x72:
                case 0x73:
                case 0x74:
                case 0x75:
                case 0x76:
                case 0x77:
                case 0x78:
                case 0x79:
                case 0x7A:
                case 0x7B:
                case 0x7C:
                case 0x7D:
                case 0x7E:
                case 0x7F:
                {
                    add(current);
                    break;
                }
                case 0xC2:
                case 0xC3:
                case 0xC4:
                case 0xC5:
                case 0xC6:
                case 0xC7:
                case 0xC8:
                case 0xC9:
                case 0xCA:
                case 0xCB:
                case 0xCC:
                case 0xCD:
                case 0xCE:
                case 0xCF:
                case 0xD0:
                case 0xD1:
                case 0xD2:
                case 0xD3:
                case 0xD4:
                case 0xD5:
                case 0xD6:
                case 0xD7:
                case 0xD8:
                case 0xD9:
                case 0xDA:
                case 0xDB:
                case 0xDC:
                case 0xDD:
                case 0xDE:
                case 0xDF:
                {
                    if (JSON_HEDLEY_UNLIKELY(!next_byte_in_range({0x80, 0xBF})))
                    {
                        return token_type::parse_error;
                    }
                    break;
                }
                case 0xE0:
                {
                    if (JSON_HEDLEY_UNLIKELY(!(next_byte_in_range({0xA0, 0xBF, 0x80, 0xBF}))))
                    {
                        return token_type::parse_error;
                    }
                    break;
                }
                case 0xE1:
                case 0xE2:
                case 0xE3:
                case 0xE4:
                case 0xE5:
                case 0xE6:
                case 0xE7:
                case 0xE8:
                case 0xE9:
                case 0xEA:
                case 0xEB:
                case 0xEC:
                case 0xEE:
                case 0xEF:
                {
                    if (JSON_HEDLEY_UNLIKELY(!(next_byte_in_range({0x80, 0xBF, 0x80, 0xBF}))))
                    {
                        return token_type::parse_error;
                    }
                    break;
                }
                case 0xED:
                {
                    if (JSON_HEDLEY_UNLIKELY(!(next_byte_in_range({0x80, 0x9F, 0x80, 0xBF}))))
                    {
                        return token_type::parse_error;
                    }
                    break;
                }
                case 0xF0:
                {
                    if (JSON_HEDLEY_UNLIKELY(!(next_byte_in_range({0x90, 0xBF, 0x80, 0xBF, 0x80, 0xBF}))))
                    {
                        return token_type::parse_error;
                    }
                    break;
                }
                case 0xF1:
                case 0xF2:
                case 0xF3:
                {
                    if (JSON_HEDLEY_UNLIKELY(!(next_byte_in_range({0x80, 0xBF, 0x80, 0xBF, 0x80, 0xBF}))))
                    {
                        return token_type::parse_error;
                    }
                    break;
                }
                case 0xF4:
                {
                    if (JSON_HEDLEY_UNLIKELY(!(next_byte_in_range({0x80, 0x8F, 0x80, 0xBF, 0x80, 0xBF}))))
                    {
                        return token_type::parse_error;
                    }
                    break;
                }
                default:
                {
                    error_message = "invalid string: ill-formed UTF-8 byte";
                    return token_type::parse_error;
                }
            }
        }
    }
    bool scan_comment()
    {
        switch (get())
        {
            case '/':
            {
                while (true)
                {
                    switch (get())
                    {
                        case '\n':
                        case '\r':
                        case char_traits<char_type>::eof():
#if !JSON_STRICT_NUL_HANDLING
                        case '\0':
#endif
                            return true;
                        default:
                            break;
                    }
                }
                JSON_HEDLEY_UNREACHABLE();
            }
            case '*':
            {
                while (true)
                {
                    switch (get())
                    {
#if !JSON_STRICT_NUL_HANDLING
                        case '\0':
#endif
                        case char_traits<char_type>::eof():
                        {
                            error_message = "invalid comment; missing closing '*/'";
                            return false;
                        }
                        case '*':
                        {
                            switch (get())
                            {
                                case '/':
                                    return true;
                                default:
                                {
                                    unget();
                                    continue;
                                }
                            }
                        }
                        default:
                            continue;
                    }
                }
                JSON_HEDLEY_UNREACHABLE();
            }
            default:
            {
                error_message = "invalid comment; expecting '/' or '*' after '/'";
                return false;
            }
        }
    }
    token_type scan_number()  
    {
        reset();
        token_type number_type = token_type::value_unsigned;
        std::size_t mantissa_end = std::string::npos;
        switch (current)
        {
            case '-':
            {
                add(current);
                goto scan_number_minus;
            }
            case '0':
            {
                add(current);
                goto scan_number_zero;
            }
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
            {
                add(current);
                goto scan_number_any1;
            }
            default:            
                JSON_ASSERT(false); 
        }
scan_number_minus:
        number_type = token_type::value_integer;
        switch (get())
        {
            case '0':
            {
                add(current);
                goto scan_number_zero;
            }
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
            {
                add(current);
                goto scan_number_any1;
            }
            default:
            {
                error_message = "invalid number; expected digit after '-'";
                return token_type::parse_error;
            }
        }
scan_number_zero:
        switch (get())
        {
            case '.':
            {
                add(current);
                decimal_point_position = token_buffer.size() - 1;
                goto scan_number_decimal1;
            }
            case 'e':
            case 'E':
            {
                add(current);
                goto scan_number_exponent;
            }
            default:
                goto scan_number_done;
        }
scan_number_any1:
        switch (get())
        {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
            {
                add(current);
                goto scan_number_any1;
            }
            case '.':
            {
                add(current);
                decimal_point_position = token_buffer.size() - 1;
                goto scan_number_decimal1;
            }
            case 'e':
            case 'E':
            {
                add(current);
                goto scan_number_exponent;
            }
            default:
                goto scan_number_done;
        }
scan_number_decimal1:
        number_type = token_type::value_float;
        switch (get())
        {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
            {
                add(current);
                goto scan_number_decimal2;
            }
            default:
            {
                error_message = "invalid number; expected digit after '.'";
                return token_type::parse_error;
            }
        }
scan_number_decimal2:
        switch (get())
        {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
            {
                add(current);
                goto scan_number_decimal2;
            }
            case 'e':
            case 'E':
            {
                add(current);
                goto scan_number_exponent;
            }
            default:
                goto scan_number_done;
        }
scan_number_exponent:
        number_type = token_type::value_float;
        mantissa_end = token_buffer.size() - 1;
        switch (get())
        {
            case '+':
            case '-':
            {
                add(current);
                goto scan_number_sign;
            }
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
            {
                add(current);
                goto scan_number_any2;
            }
            default:
            {
                error_message =
                    "invalid number; expected '+', '-', or digit after exponent";
                return token_type::parse_error;
            }
        }
scan_number_sign:
        switch (get())
        {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
            {
                add(current);
                goto scan_number_any2;
            }
            default:
            {
                error_message = "invalid number; expected digit after exponent sign";
                return token_type::parse_error;
            }
        }
scan_number_any2:
        switch (get())
        {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
            {
                add(current);
                goto scan_number_any2;
            }
            default:
                goto scan_number_done;
        }
scan_number_done:
        unget();
        if (mantissa_end == std::string::npos)
        {
            mantissa_end = token_buffer.size();
        }
        return convert_number(number_type, mantissa_end);
    }
    token_type convert_integer(token_type number_type, const char* first, const char* last)
    {
        if (number_type == token_type::value_unsigned)
        {
            if (parse_integer_unsigned(first, last, value_unsigned))
            {
                return token_type::value_unsigned;
            }
        }
        else if (number_type == token_type::value_integer)
        {
            if (parse_integer_signed(first, last, value_integer))
            {
                return token_type::value_integer;
            }
        }
        return token_type::uninitialized;
    }
    token_type convert_number(token_type number_type, std::size_t mantissa_end)
    {
        if (discard_number_values)
        {
            constexpr std::size_t safe_digit_count = 18;
            if (number_type == token_type::value_unsigned && token_buffer.size() <= safe_digit_count)
            {
                return token_type::value_unsigned;
            }
            if (number_type == token_type::value_integer && token_buffer.size() - 1 <= safe_digit_count)
            {
                return token_type::value_integer;
            }
        }
        const char* const num_begin = token_buffer.data();
        const char* const num_end = num_begin + token_buffer.size();
        if (number_type != token_type::value_float)
        {
            const token_type integer_result = convert_integer(number_type, num_begin, num_end);
            if (integer_result != token_type::uninitialized)
            {
                return integer_result;
            }
        }
        if (convert_float_fast(num_begin, num_end, decimal_point_position, mantissa_end, value_float))
        {
            return token_type::value_float;
        }
        convert_float_locale_aware(token_buffer, decimal_point_position, value_float);
        return token_type::value_float;
    }
    token_type scan_number_bulk_contiguous()
    {
        if (next_unget)
        {
            return token_type::uninitialized;
        }
        const std::size_t rem = ia.bulk_remaining();
        if (rem == 0)
        {
            return token_type::uninitialized;
        }
        const char* const data = reinterpret_cast<const char*>(ia.bulk_data()) - 1;
        const std::size_t avail = rem + 1;
        std::size_t i = 0;
        std::size_t dot_index = std::string::npos;
        token_type number_type = token_type::value_unsigned;
        if (data[0] == '-')
        {
            number_type = token_type::value_integer;
            i = 1;
            if (i >= avail)
            {
                return token_type::uninitialized;
            }
        }
        if (data[i] == '0')
        {
            ++i;
        }
        else if (data[i] >= '1' && data[i] <= '9')
        {
            ++i;
            while (i < avail && data[i] >= '0' && data[i] <= '9')
            {
                ++i;
            }
        }
        else
        {
            return token_type::uninitialized;
        }
        if (i < avail && data[i] == '.')
        {
            number_type = token_type::value_float;
            dot_index = i;
            ++i;
            if (i >= avail || !(data[i] >= '0' && data[i] <= '9'))
            {
                return token_type::uninitialized;
            }
            while (i < avail && data[i] >= '0' && data[i] <= '9')
            {
                ++i;
            }
        }
        const std::size_t mantissa_end = i;
        if (i < avail && (data[i] == 'e' || data[i] == 'E'))
        {
            number_type = token_type::value_float;
            ++i;
            if (i < avail && (data[i] == '+' || data[i] == '-'))
            {
                ++i;
            }
            if (i >= avail || !(data[i] >= '0' && data[i] <= '9'))
            {
                return token_type::uninitialized;
            }
            while (i < avail && data[i] >= '0' && data[i] <= '9')
            {
                ++i;
            }
        }
        const std::size_t len = i;
        reset();
#if !JSON_DIAGNOSTIC_POSITIONS
        if (number_type != token_type::value_float)
        {
            const token_type integer_result = convert_integer(number_type, data, data + len);
            if (JSON_HEDLEY_LIKELY(integer_result != token_type::uninitialized))
            {
                ia.bulk_skip(len - 1);
                position.chars_read_total += (len - 1);
                position.chars_read_current_line += (len - 1);
                return integer_result;
            }
            number_type = token_type::value_float;
        }
#endif
        token_buffer.append(reinterpret_cast<const typename string_t::value_type*>(data), len);
        decimal_point_position = dot_index;
        ia.bulk_skip(len - 1);
        position.chars_read_total += (len - 1);
        position.chars_read_current_line += (len - 1);
        return convert_number(number_type, mantissa_end);
    }
    token_type scan_number_dispatch(std::true_type )
    {
        const token_type t = scan_number_bulk_contiguous();
        return (t != token_type::uninitialized) ? t : scan_number();
    }
    token_type scan_number_dispatch(std::false_type )
    {
        return scan_number();
    }
    JSON_HEDLEY_NON_NULL(2)
    token_type scan_literal(const char_type* literal_text, const std::size_t length,
                            token_type return_type)
    {
        JSON_ASSERT(char_traits<char_type>::to_char_type(current) == literal_text[0]);
        for (std::size_t i = 1; i < length; ++i)
        {
            if (JSON_HEDLEY_UNLIKELY(char_traits<char_type>::to_char_type(get()) != literal_text[i]))
            {
                error_message = "invalid literal";
                return token_type::parse_error;
            }
        }
        return return_type;
    }
    void reset() noexcept
    {
        token_buffer.clear();
        decimal_point_position = std::string::npos;
#if JSON_DIAGNOSTIC_POSITIONS
        token_start_position = position.chars_read_total - 1;
#endif
        note_token_start(std::integral_constant<bool, lazy_token_string> {});
    }
    void note_token_start(std::true_type ) noexcept
    {
        token_string_start = ia.get_consumed_count() - 1;
    }
    void note_token_start(std::false_type ) noexcept
    {
        token_string.clear();
        token_string.push_back(char_traits<char_type>::to_char_type(current));
    }
    char_int_type get()
    {
        advance_position();
        if (next_unget)
        {
            next_unget = false;
        }
        else
        {
            current = ia.get_character();
        }
        return track_after_read();
    }
    void advance_position() noexcept
    {
        ++position.chars_read_total;
        ++position.chars_read_current_line;
    }
    char_int_type track_after_read()
    {
        capture_char(std::integral_constant<bool, lazy_token_string> {});
        if (current == '\n')
        {
            ++position.lines_read;
            chars_read_before_newline = position.chars_read_current_line;
            position.chars_read_current_line = 0;
        }
        return current;
    }
    char_int_type get_ignoring_pending_unget()
    {
        JSON_ASSERT(!next_unget);
        advance_position();
        current = ia.get_character();
        return track_after_read();
    }
    void capture_char(std::true_type ) const noexcept {}
    void capture_char(std::false_type )
    {
        if (JSON_HEDLEY_LIKELY(current != char_traits<char_type>::eof()))
        {
            token_string.push_back(char_traits<char_type>::to_char_type(current));
        }
    }
    void unget()
    {
        next_unget = true;
        --position.chars_read_total;
        if (position.chars_read_current_line == 0)
        {
            if (position.lines_read > 0)
            {
                --position.lines_read;
            }
            position.chars_read_current_line = (chars_read_before_newline > 0)
                                               ? chars_read_before_newline - 1
                                               : 0;
        }
        else
        {
            --position.chars_read_current_line;
        }
        uncapture_char(std::integral_constant<bool, lazy_token_string> {});
    }
    void release_lookahead_impl(std::false_type ) const noexcept {}
    void release_lookahead_impl(std::true_type )
    {
        if (next_unget)
        {
            next_unget = false;
            ia.release_lookahead();
        }
    }
    void uncapture_char(std::true_type ) const noexcept {}
    void uncapture_char(std::false_type )
    {
        if (JSON_HEDLEY_LIKELY(current != char_traits<char_type>::eof()))
        {
            JSON_ASSERT(!token_string.empty());
            token_string.pop_back();
        }
    }
    void add(char_int_type c)
    {
        token_buffer.push_back(static_cast<typename string_t::value_type>(c));
    }
  public:
    constexpr number_integer_t get_number_integer() const noexcept
    {
        return value_integer;
    }
    constexpr number_unsigned_t get_number_unsigned() const noexcept
    {
        return value_unsigned;
    }
    constexpr number_float_t get_number_float() const noexcept
    {
        return value_float;
    }
    string_t& get_string()
    {
        return token_buffer;
    }
    constexpr position_t get_position() const noexcept
    {
        return position;
    }
    void release_lookahead()
    {
        release_lookahead_impl(std::integral_constant<bool, can_release_lookahead> {});
    }
#if JSON_DIAGNOSTIC_POSITIONS
    constexpr std::size_t get_token_start_position() const noexcept
    {
        return token_start_position;
    }
#endif
    const std::vector<char_type>& collect_token_chars(std::vector<char_type>& out, std::true_type ) const
    {
        const bool pending_real_unget = next_unget && current != char_traits<char_type>::eof();
        const std::size_t stop = ia.get_consumed_count() - (pending_real_unget ? 1u : 0u);
        if (JSON_HEDLEY_LIKELY(stop >= token_string_start))
        {
            ia.copy_consumed_range(token_string_start, stop, out);
        }
        return out;
    }
    const std::vector<char_type>& collect_token_chars(std::vector<char_type>& , std::false_type ) const
    {
        return token_string;
    }
    std::string get_token_string() const
    {
        std::vector<char_type> reconstructed;
        const std::vector<char_type>& chars = collect_token_chars(reconstructed, std::integral_constant<bool, lazy_token_string> {});
        std::string result;
        for (const auto c : chars)
        {
            if (static_cast<unsigned char>(c) <= '\x1F')
            {
                std::array<char, 9> cs{{}};
                static_cast<void>((std::snprintf)(cs.data(), cs.size(), "<U+%.4X>", static_cast<unsigned char>(c))); 
                result += cs.data();
            }
            else
            {
                result.push_back(static_cast<std::string::value_type>(c));
            }
        }
        return result;
    }
    JSON_HEDLEY_RETURNS_NON_NULL
    constexpr const char* get_error_message() const noexcept
    {
        return error_message;
    }
    bool skip_bom()
    {
        if (get() == 0xEF)
        {
            return get() == 0xBB && get() == 0xBF;
        }
        unget();
        return true;
    }
    bool current_is_whitespace() const noexcept
    {
        return current == ' ' || current == '\t' || current == '\n' || current == '\r';
    }
    void skip_whitespace()
    {
        get();
        if (!current_is_whitespace())
        {
            return;
        }
        do
        {
            get_ignoring_pending_unget();
        }
        while (current_is_whitespace());
    }
    token_type scan()
    {
        if (position.chars_read_total == 0 && !skip_bom())
        {
            error_message = "invalid BOM; must be 0xEF 0xBB 0xBF if given";
            return token_type::parse_error;
        }
        skip_whitespace();
        while (ignore_comments && current == '/')
        {
            if (!scan_comment())
            {
                return token_type::parse_error;
            }
            skip_whitespace();
        }
        switch (current)
        {
            case '[':
                return token_type::begin_array;
            case ']':
                return token_type::end_array;
            case '{':
                return token_type::begin_object;
            case '}':
                return token_type::end_object;
            case ':':
                return token_type::name_separator;
            case ',':
                return token_type::value_separator;
            case 't':
            {
                std::array<char_type, 4> true_literal = {{static_cast<char_type>('t'), static_cast<char_type>('r'), static_cast<char_type>('u'), static_cast<char_type>('e')}};
                return scan_literal(true_literal.data(), true_literal.size(), token_type::literal_true);
            }
            case 'f':
            {
                std::array<char_type, 5> false_literal = {{static_cast<char_type>('f'), static_cast<char_type>('a'), static_cast<char_type>('l'), static_cast<char_type>('s'), static_cast<char_type>('e')}};
                return scan_literal(false_literal.data(), false_literal.size(), token_type::literal_false);
            }
            case 'n':
            {
                std::array<char_type, 4> null_literal = {{static_cast<char_type>('n'), static_cast<char_type>('u'), static_cast<char_type>('l'), static_cast<char_type>('l')}};
                return scan_literal(null_literal.data(), null_literal.size(), token_type::literal_null);
            }
            case '\"':
                return scan_string();
            case '-':
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                return scan_number_dispatch(std::integral_constant<bool, bulk_scan> {});
#if !JSON_STRICT_NUL_HANDLING
            case '\0':
#endif
            case char_traits<char_type>::eof():
                return token_type::end_of_input;
            default:
                error_message = "invalid literal";
                return token_type::parse_error;
        }
    }
  private:
    InputAdapterType ia;
    const bool ignore_comments = false;
    char_int_type current = char_traits<char_type>::eof();
    bool next_unget = false;
    position_t position {};
    std::size_t chars_read_before_newline = 0;
    std::vector<char_type> token_string {};
    std::size_t token_string_start = 0;
#if JSON_DIAGNOSTIC_POSITIONS
    std::size_t token_start_position = 0;
#endif
    string_t token_buffer {};
    const char* error_message = "";
    number_integer_t value_integer = 0;
    number_unsigned_t value_unsigned = 0;
    number_float_t value_float = 0;
    std::size_t decimal_point_position = std::string::npos;
    const bool discard_number_values = false;
};
}  
NLOHMANN_JSON_NAMESPACE_END
NLOHMANN_JSON_NAMESPACE_BEGIN
template<typename BasicJsonType>
struct json_sax
{
    using number_integer_t = typename BasicJsonType::number_integer_t;
    using number_unsigned_t = typename BasicJsonType::number_unsigned_t;
    using number_float_t = typename BasicJsonType::number_float_t;
    using string_t = typename BasicJsonType::string_t;
    using binary_t = typename BasicJsonType::binary_t;
    virtual bool null() = 0;
    virtual bool boolean(bool val) = 0;
    virtual bool number_integer(number_integer_t val) = 0;
    virtual bool number_unsigned(number_unsigned_t val) = 0;
    virtual bool number_float(number_float_t val, const string_t& s) = 0;
    virtual bool string(string_t& val) = 0;
    virtual bool binary(binary_t& val) = 0;
    virtual bool start_object(std::size_t elements) = 0;
    virtual bool key(string_t& val) = 0;
    virtual bool end_object() = 0;
    virtual bool start_array(std::size_t elements) = 0;
    virtual bool end_array() = 0;
    virtual bool parse_error(std::size_t position,
                             const std::string& last_token,
                             const detail::exception& ex) = 0;
    json_sax() = default;
    json_sax(const json_sax&) = default;
    json_sax(json_sax&&) noexcept = default;
    json_sax& operator=(const json_sax&) = default;
    json_sax& operator=(json_sax&&) noexcept = default;
    virtual ~json_sax() = default;
};
namespace detail
{
constexpr std::size_t unknown_size()
{
    return (std::numeric_limits<std::size_t>::max)();
}
template<typename ArrayType>
auto reserve_array(ArrayType& arr, std::size_t len, priority_tag<1> )
-> decltype(arr.reserve(len), void())
{
    constexpr std::size_t reserve_cap = 16384;
    arr.reserve((std::min)(len, reserve_cap));
}
template<typename ArrayType>
inline void reserve_array(ArrayType& , std::size_t , priority_tag<0> )
{}
#if JSON_DIAGNOSTIC_POSITIONS
struct diagnostic_positions
{
    template<typename BasicJsonType, typename LexerType>
    static void set_from_lexer(BasicJsonType& v, LexerType* lexer)
    {
        if (lexer)
        {
            v.end_position = lexer->get_position();
            switch (v.type())
            {
                case value_t::boolean:
                {
                    v.start_position = v.end_position - (v.m_data.m_value.boolean ? 4 : 5);
                    break;
                }
                case value_t::null:
                {
                    v.start_position = v.end_position - 4;
                    break;
                }
                case value_t::string:
                {
                    v.start_position = lexer->get_token_start_position();
                    break;
                }
                case value_t::discarded:
                {
                    v.end_position = std::string::npos;
                    v.start_position = v.end_position;
                    break;
                }
                case value_t::binary:
                case value_t::number_integer:
                case value_t::number_unsigned:
                case value_t::number_float:
                {
                    v.start_position = v.end_position - lexer->get_string().size();
                    break;
                }
                case value_t::object:
                case value_t::array:
                {
                    break;
                }
                default: 
                    JSON_ASSERT(false); 
            }
        }
    }
};
#endif
template<typename BasicJsonType, typename InputAdapterType>
class json_sax_dom_parser
{
  public:
    using number_integer_t = typename BasicJsonType::number_integer_t;
    using number_unsigned_t = typename BasicJsonType::number_unsigned_t;
    using number_float_t = typename BasicJsonType::number_float_t;
    using string_t = typename BasicJsonType::string_t;
    using binary_t = typename BasicJsonType::binary_t;
    using lexer_t = lexer<BasicJsonType, InputAdapterType>;
    explicit json_sax_dom_parser(BasicJsonType& r, const bool allow_exceptions_ = true, lexer_t* lexer_ = nullptr)
        : root(r), allow_exceptions(allow_exceptions_), m_lexer_ref(lexer_)
    {}
    json_sax_dom_parser(const json_sax_dom_parser&) = delete;
    json_sax_dom_parser(json_sax_dom_parser&&) = default; 
    json_sax_dom_parser& operator=(const json_sax_dom_parser&) = delete;
    json_sax_dom_parser& operator=(json_sax_dom_parser&&) = default; 
    ~json_sax_dom_parser() = default;
    bool null()
    {
        handle_value(nullptr);
        return true;
    }
    bool boolean(bool val)
    {
        handle_value(val);
        return true;
    }
    bool number_integer(number_integer_t val)
    {
        handle_value(val);
        return true;
    }
    bool number_unsigned(number_unsigned_t val)
    {
        handle_value(val);
        return true;
    }
    bool number_float(number_float_t val, const string_t& )
    {
        handle_value(val);
        return true;
    }
    bool string(string_t& val)
    {
        handle_value(std::move(val));
        return true;
    }
    bool binary(binary_t& val)
    {
        handle_value(std::move(val));
        return true;
    }
    bool start_object(std::size_t len)
    {
        ref_stack.push_back(handle_value(BasicJsonType::value_t::object));
#if JSON_DIAGNOSTIC_POSITIONS
        if (m_lexer_ref)
        {
            ref_stack.back()->start_position = m_lexer_ref->get_position() - 1;
        }
#endif
        if (JSON_HEDLEY_UNLIKELY(len != detail::unknown_size() && len > ref_stack.back()->max_size()))
        {
            return parse_error(0, "", out_of_range::create(408, concat("excessive object size: ", std::to_string(len)), ref_stack.back()));
        }
        return true;
    }
    bool key(string_t& val)
    {
        JSON_ASSERT(!ref_stack.empty());
        JSON_ASSERT(ref_stack.back()->is_object());
        object_element = &(ref_stack.back()->m_data.m_value.object->operator[](val));
        return true;
    }
    bool end_object()
    {
        JSON_ASSERT(!ref_stack.empty());
        JSON_ASSERT(ref_stack.back()->is_object());
#if JSON_DIAGNOSTIC_POSITIONS
        if (m_lexer_ref)
        {
            ref_stack.back()->end_position = m_lexer_ref->get_position();
        }
#endif
        ref_stack.back()->set_parents();
        ref_stack.pop_back();
        return true;
    }
    bool start_array(std::size_t len)
    {
        ref_stack.push_back(handle_value(BasicJsonType::value_t::array));
#if JSON_DIAGNOSTIC_POSITIONS
        if (m_lexer_ref)
        {
            ref_stack.back()->start_position = m_lexer_ref->get_position() - 1;
        }
#endif
        if (JSON_HEDLEY_UNLIKELY(len != detail::unknown_size() && len > ref_stack.back()->max_size()))
        {
            return parse_error(0, "", out_of_range::create(408, concat("excessive array size: ", std::to_string(len)), ref_stack.back()));
        }
        if (len != detail::unknown_size())
        {
            reserve_array(*ref_stack.back()->m_data.m_value.array, len, priority_tag<1> {});
        }
        return true;
    }
    bool end_array()
    {
        JSON_ASSERT(!ref_stack.empty());
        JSON_ASSERT(ref_stack.back()->is_array());
#if JSON_DIAGNOSTIC_POSITIONS
        if (m_lexer_ref)
        {
            ref_stack.back()->end_position = m_lexer_ref->get_position();
        }
#endif
        ref_stack.back()->set_parents();
        ref_stack.pop_back();
        return true;
    }
    template<class Exception>
    bool parse_error(std::size_t , const std::string& ,
                     const Exception& ex)
    {
        errored = true;
        static_cast<void>(ex);
        if (allow_exceptions)
        {
            JSON_THROW(ex);
        }
        return false;
    }
    constexpr bool is_errored() const
    {
        return errored;
    }
  private:
    template<typename Value>
    JSON_HEDLEY_RETURNS_NON_NULL
    BasicJsonType* handle_value(Value&& v)
    {
        if (ref_stack.empty())
        {
            root = BasicJsonType(std::forward<Value>(v));
#if JSON_DIAGNOSTIC_POSITIONS
            diagnostic_positions::set_from_lexer(root, m_lexer_ref);
#endif
            return &root;
        }
        JSON_ASSERT(ref_stack.back()->is_array() || ref_stack.back()->is_object());
        if (ref_stack.back()->is_array())
        {
            ref_stack.back()->m_data.m_value.array->emplace_back(std::forward<Value>(v));
#if JSON_DIAGNOSTIC_POSITIONS
            diagnostic_positions::set_from_lexer(ref_stack.back()->m_data.m_value.array->back(), m_lexer_ref);
#endif
            return &(ref_stack.back()->m_data.m_value.array->back());
        }
        JSON_ASSERT(ref_stack.back()->is_object());
        JSON_ASSERT(object_element);
        *object_element = BasicJsonType(std::forward<Value>(v));
#if JSON_DIAGNOSTIC_POSITIONS
        diagnostic_positions::set_from_lexer(*object_element, m_lexer_ref);
#endif
        return object_element;
    }
    BasicJsonType& root;
    std::vector<BasicJsonType*> ref_stack {};
    BasicJsonType* object_element = nullptr;
    bool errored = false;
    const bool allow_exceptions = true;
    lexer_t* m_lexer_ref = nullptr;
};
template<typename BasicJsonType, typename InputAdapterType>
class json_sax_dom_callback_parser
{
  public:
    using number_integer_t = typename BasicJsonType::number_integer_t;
    using number_unsigned_t = typename BasicJsonType::number_unsigned_t;
    using number_float_t = typename BasicJsonType::number_float_t;
    using string_t = typename BasicJsonType::string_t;
    using binary_t = typename BasicJsonType::binary_t;
    using parser_callback_t = typename BasicJsonType::parser_callback_t;
    using parse_event_t = typename BasicJsonType::parse_event_t;
    using lexer_t = lexer<BasicJsonType, InputAdapterType>;
    json_sax_dom_callback_parser(BasicJsonType& r,
                                 parser_callback_t cb,
                                 const bool allow_exceptions_ = true,
                                 lexer_t* lexer_ = nullptr)
        : root(r), callback(std::move(cb)), allow_exceptions(allow_exceptions_), m_lexer_ref(lexer_)
    {
        keep_stack.push_back(true);
    }
    json_sax_dom_callback_parser(const json_sax_dom_callback_parser&) = delete;
    json_sax_dom_callback_parser(json_sax_dom_callback_parser&&) = default; 
    json_sax_dom_callback_parser& operator=(const json_sax_dom_callback_parser&) = delete;
    json_sax_dom_callback_parser& operator=(json_sax_dom_callback_parser&&) = default; 
    ~json_sax_dom_callback_parser() = default;
    bool null()
    {
        handle_value(nullptr);
        return true;
    }
    bool boolean(bool val)
    {
        handle_value(val);
        return true;
    }
    bool number_integer(number_integer_t val)
    {
        handle_value(val);
        return true;
    }
    bool number_unsigned(number_unsigned_t val)
    {
        handle_value(val);
        return true;
    }
    bool number_float(number_float_t val, const string_t& )
    {
        handle_value(val);
        return true;
    }
    bool string(string_t& val)
    {
        handle_value(std::move(val));
        return true;
    }
    bool binary(binary_t& val)
    {
        handle_value(std::move(val));
        return true;
    }
    bool start_object(std::size_t len)
    {
        const bool keep = keep_stack.back() && callback(static_cast<int>(ref_stack.size()), parse_event_t::object_start, discarded);
        keep_stack.push_back(keep);
        container_key_stack.push_back(current_key());
        auto val = handle_value(BasicJsonType::value_t::object, true);
        ref_stack.push_back(val.second);
        if (ref_stack.back())
        {
#if JSON_DIAGNOSTIC_POSITIONS
            if (m_lexer_ref)
            {
                ref_stack.back()->start_position = m_lexer_ref->get_position() - 1;
            }
#endif
            if (JSON_HEDLEY_UNLIKELY(len != detail::unknown_size() && len > ref_stack.back()->max_size()))
            {
                return parse_error(0, "", out_of_range::create(408, concat("excessive object size: ", std::to_string(len)), ref_stack.back()));
            }
        }
        return true;
    }
    bool key(string_t& val)
    {
        if (!keep_stack.back() || !ref_stack.back())
        {
            if (keep_stack.back())
            {
                BasicJsonType k = BasicJsonType(val);
                static_cast<void>(callback(static_cast<int>(ref_stack.size()), parse_event_t::key, k));
            }
            return true;
        }
        BasicJsonType k = BasicJsonType(val);
        const bool keep = callback(static_cast<int>(ref_stack.size()), parse_event_t::key, k);
        key_keep_stack.push_back(keep);
        key_stack.push_back(val);
        if (keep && ref_stack.back())
        {
            auto& obj = *ref_stack.back()->m_data.m_value.object;
            const auto it = obj.find(val);
            if (it != obj.end())
            {
                duplicate_key_stash.emplace_back(&(it->second), it->second);
            }
            object_element = &(obj[val] = discarded);
        }
        return true;
    }
    bool end_object()
    {
        if (ref_stack.back())
        {
            if (!callback(static_cast<int>(ref_stack.size()) - 1, parse_event_t::object_end, *ref_stack.back()))
            {
                if (!resolve_duplicate_key_stash(ref_stack.back(), true))
                {
                    *ref_stack.back() = discarded;
#if JSON_DIAGNOSTIC_POSITIONS
                    diagnostic_positions::set_from_lexer(*ref_stack.back(), m_lexer_ref);
#endif
                }
            }
            else
            {
#if JSON_DIAGNOSTIC_POSITIONS
                if (m_lexer_ref)
                {
                    ref_stack.back()->end_position = m_lexer_ref->get_position();
                }
#endif
                ref_stack.back()->set_parents();
                resolve_duplicate_key_stash(ref_stack.back(), false);
            }
        }
        JSON_ASSERT(!ref_stack.empty());
        JSON_ASSERT(!keep_stack.empty());
        JSON_ASSERT(!container_key_stack.empty());
        ref_stack.pop_back();
        keep_stack.pop_back();
        const string_t object_key = std::move(container_key_stack.back());
        container_key_stack.pop_back();
        if (!ref_stack.empty() && ref_stack.back() && ref_stack.back()->is_structured())
        {
            remove_discarded_value(*ref_stack.back(), object_key);
        }
        return true;
    }
    bool start_array(std::size_t len)
    {
        const bool keep = keep_stack.back() && callback(static_cast<int>(ref_stack.size()), parse_event_t::array_start, discarded);
        keep_stack.push_back(keep);
        container_key_stack.push_back(current_key());
        auto val = handle_value(BasicJsonType::value_t::array, true);
        ref_stack.push_back(val.second);
        if (ref_stack.back())
        {
#if JSON_DIAGNOSTIC_POSITIONS
            if (m_lexer_ref)
            {
                ref_stack.back()->start_position = m_lexer_ref->get_position() - 1;
            }
#endif
            if (JSON_HEDLEY_UNLIKELY(len != detail::unknown_size() && len > ref_stack.back()->max_size()))
            {
                return parse_error(0, "", out_of_range::create(408, concat("excessive array size: ", std::to_string(len)), ref_stack.back()));
            }
            if (len != detail::unknown_size())
            {
                reserve_array(*ref_stack.back()->m_data.m_value.array, len, priority_tag<1> {});
            }
        }
        return true;
    }
    bool end_array()
    {
        bool keep = true;
        const bool stored = ref_stack.back() != nullptr;
        if (stored)
        {
            keep = callback(static_cast<int>(ref_stack.size()) - 1, parse_event_t::array_end, *ref_stack.back());
            if (keep)
            {
#if JSON_DIAGNOSTIC_POSITIONS
                if (m_lexer_ref)
                {
                    ref_stack.back()->end_position = m_lexer_ref->get_position();
                }
#endif
                ref_stack.back()->set_parents();
                resolve_duplicate_key_stash(ref_stack.back(), false);
            }
            else
            {
                if (!resolve_duplicate_key_stash(ref_stack.back(), true))
                {
                    *ref_stack.back() = discarded;
#if JSON_DIAGNOSTIC_POSITIONS
                    diagnostic_positions::set_from_lexer(*ref_stack.back(), m_lexer_ref);
#endif
                }
            }
        }
        JSON_ASSERT(!ref_stack.empty());
        JSON_ASSERT(!keep_stack.empty());
        JSON_ASSERT(!container_key_stack.empty());
        ref_stack.pop_back();
        keep_stack.pop_back();
        const string_t object_key = std::move(container_key_stack.back());
        container_key_stack.pop_back();
        if (!ref_stack.empty() && ref_stack.back())
        {
            if (!keep && ref_stack.back()->is_array())
            {
                ref_stack.back()->m_data.m_value.array->pop_back();
            }
            else if ((!keep || !stored) && ref_stack.back()->is_object())
            {
                remove_discarded_value(*ref_stack.back(), object_key);
            }
        }
        return true;
    }
    template<class Exception>
    bool parse_error(std::size_t , const std::string& ,
                     const Exception& ex)
    {
        errored = true;
        static_cast<void>(ex);
        if (allow_exceptions)
        {
            JSON_THROW(ex);
        }
        return false;
    }
    constexpr bool is_errored() const
    {
        return errored;
    }
  private:
    bool resolve_duplicate_key_stash(BasicJsonType* slot, bool restore_value)
    {
        const auto it = std::find_if(duplicate_key_stash.begin(), duplicate_key_stash.end(),
                                     [slot](const std::pair<BasicJsonType*, BasicJsonType>& entry)
        {
            return entry.first == slot;
        });
        if (it == duplicate_key_stash.end())
        {
            return false;
        }
        if (restore_value)
        {
            *slot = std::move(it->second);
        }
        duplicate_key_stash.erase(it);
        return true;
    }
    string_t current_key() const
    {
        if (!ref_stack.empty() && ref_stack.back() && ref_stack.back()->is_object()
                && !key_stack.empty())
        {
            return key_stack.back();
        }
        return string_t{};
    }
    void remove_discarded_value(BasicJsonType& parent, const string_t& key)
    {
        if (parent.is_array())
        {
            auto& array = *parent.m_data.m_value.array;
            if (!array.empty() && array.back().is_discarded())
            {
                array.pop_back();
            }
        }
        else if (parent.is_object())
        {
            auto& object = *parent.m_data.m_value.object;
            const auto it = object.find(key);
            if (it != object.end() && it->second.is_discarded())
            {
                if (!resolve_duplicate_key_stash(&it->second, true))
                {
                    object.erase(it);
                }
            }
        }
    }
    template<typename Value>
    std::pair<bool, BasicJsonType*> handle_value(Value&& v, const bool skip_callback = false)
    {
        JSON_ASSERT(!keep_stack.empty());
        if (!keep_stack.back())
        {
            return {false, nullptr};
        }
        auto value = BasicJsonType(std::forward<Value>(v));
#if JSON_DIAGNOSTIC_POSITIONS
        diagnostic_positions::set_from_lexer(value, m_lexer_ref);
#endif
        const bool keep = skip_callback || callback(static_cast<int>(ref_stack.size()), parse_event_t::value, value);
        if (!keep)
        {
            if (!ref_stack.empty() && ref_stack.back() && ref_stack.back()->is_object())
            {
                JSON_ASSERT(!key_keep_stack.empty());
                JSON_ASSERT(!key_stack.empty());
                const bool placeholder_stored = key_keep_stack.back();
                key_keep_stack.pop_back();
                const string_t key = std::move(key_stack.back());
                key_stack.pop_back();
                if (placeholder_stored)
                {
                    remove_discarded_value(*ref_stack.back(), key);
                }
            }
            return {false, nullptr};
        }
        if (ref_stack.empty())
        {
            root = std::move(value);
            return {true, & root};
        }
        if (!ref_stack.back())
        {
            return {false, nullptr};
        }
        JSON_ASSERT(ref_stack.back()->is_array() || ref_stack.back()->is_object());
        if (ref_stack.back()->is_array())
        {
            ref_stack.back()->m_data.m_value.array->emplace_back(std::move(value));
            return {true, & (ref_stack.back()->m_data.m_value.array->back())};
        }
        JSON_ASSERT(ref_stack.back()->is_object());
        JSON_ASSERT(!key_keep_stack.empty());
        JSON_ASSERT(!key_stack.empty());
        const bool store_element = key_keep_stack.back();
        key_keep_stack.pop_back();
        key_stack.pop_back();
        if (!store_element)
        {
            return {false, nullptr};
        }
        JSON_ASSERT(object_element);
        *object_element = std::move(value);
        if (!skip_callback)
        {
            resolve_duplicate_key_stash(object_element, false);
        }
        return {true, object_element};
    }
    BasicJsonType& root;
    std::vector<BasicJsonType*> ref_stack {};
    std::vector<bool> keep_stack {}; 
    std::vector<bool> key_keep_stack {}; 
    std::vector<string_t> key_stack {}; 
    std::vector<string_t> container_key_stack {}; 
    BasicJsonType* object_element = nullptr;
    std::vector<std::pair<BasicJsonType*, BasicJsonType>> duplicate_key_stash {};
    bool errored = false;
    const parser_callback_t callback = nullptr;
    const bool allow_exceptions = true;
    BasicJsonType discarded = BasicJsonType::value_t::discarded;
    lexer_t* m_lexer_ref = nullptr;
};
template<typename BasicJsonType>
class json_sax_acceptor
{
  public:
    using number_integer_t = typename BasicJsonType::number_integer_t;
    using number_unsigned_t = typename BasicJsonType::number_unsigned_t;
    using number_float_t = typename BasicJsonType::number_float_t;
    using string_t = typename BasicJsonType::string_t;
    using binary_t = typename BasicJsonType::binary_t;
    bool null()
    {
        return true;
    }
    bool boolean(bool )
    {
        return true;
    }
    bool number_integer(number_integer_t )
    {
        return true;
    }
    bool number_unsigned(number_unsigned_t )
    {
        return true;
    }
    bool number_float(number_float_t , const string_t& )
    {
        return true;
    }
    bool string(string_t& )
    {
        return true;
    }
    bool binary(binary_t& )
    {
        return true;
    }
    bool start_object(std::size_t  = detail::unknown_size())
    {
        return true;
    }
    bool key(string_t& )
    {
        return true;
    }
    bool end_object()
    {
        return true;
    }
    bool start_array(std::size_t  = detail::unknown_size())
    {
        return true;
    }
    bool end_array()
    {
        return true;
    }
    bool parse_error(std::size_t , const std::string& , const detail::exception& )
    {
        return false;
    }
};
}  
NLOHMANN_JSON_NAMESPACE_END
#include <cstdint> 
#include <utility> 
#include <string> 
NLOHMANN_JSON_NAMESPACE_BEGIN
namespace detail
{
template<typename T>
using null_function_t = decltype(std::declval<T&>().null());
template<typename T>
using boolean_function_t =
    decltype(std::declval<T&>().boolean(std::declval<bool>()));
template<typename T, typename Integer>
using number_integer_function_t =
    decltype(std::declval<T&>().number_integer(std::declval<Integer>()));
template<typename T, typename Unsigned>
using number_unsigned_function_t =
    decltype(std::declval<T&>().number_unsigned(std::declval<Unsigned>()));
template<typename T, typename Float, typename String>
using number_float_function_t = decltype(std::declval<T&>().number_float(
                                    std::declval<Float>(), std::declval<const String&>()));
template<typename T, typename String>
using string_function_t =
    decltype(std::declval<T&>().string(std::declval<String&>()));
template<typename T, typename Binary>
using binary_function_t =
    decltype(std::declval<T&>().binary(std::declval<Binary&>()));
template<typename T>
using start_object_function_t =
    decltype(std::declval<T&>().start_object(std::declval<std::size_t>()));
template<typename T, typename String>
using key_function_t =
    decltype(std::declval<T&>().key(std::declval<String&>()));
template<typename T>
using end_object_function_t = decltype(std::declval<T&>().end_object());
template<typename T>
using start_array_function_t =
    decltype(std::declval<T&>().start_array(std::declval<std::size_t>()));
template<typename T>
using end_array_function_t = decltype(std::declval<T&>().end_array());
template<typename T, typename Exception>
using parse_error_function_t = decltype(std::declval<T&>().parse_error(
        std::declval<std::size_t>(), std::declval<const std::string&>(),
        std::declval<const Exception&>()));
template<typename SAX, typename BasicJsonType>
struct is_sax
{
  private:
    static_assert(is_basic_json<BasicJsonType>::value,
                  "BasicJsonType must be of type basic_json<...>");
    using number_integer_t = typename BasicJsonType::number_integer_t;
    using number_unsigned_t = typename BasicJsonType::number_unsigned_t;
    using number_float_t = typename BasicJsonType::number_float_t;
    using string_t = typename BasicJsonType::string_t;
    using binary_t = typename BasicJsonType::binary_t;
    using exception_t = typename BasicJsonType::exception;
  public:
    static constexpr bool value =
        is_detected_exact<bool, null_function_t, SAX>::value &&
        is_detected_exact<bool, boolean_function_t, SAX>::value &&
        is_detected_exact<bool, number_integer_function_t, SAX, number_integer_t>::value &&
        is_detected_exact<bool, number_unsigned_function_t, SAX, number_unsigned_t>::value &&
        is_detected_exact<bool, number_float_function_t, SAX, number_float_t, string_t>::value &&
        is_detected_exact<bool, string_function_t, SAX, string_t>::value &&
        is_detected_exact<bool, binary_function_t, SAX, binary_t>::value &&
        is_detected_exact<bool, start_object_function_t, SAX>::value &&
        is_detected_exact<bool, key_function_t, SAX, string_t>::value &&
        is_detected_exact<bool, end_object_function_t, SAX>::value &&
        is_detected_exact<bool, start_array_function_t, SAX>::value &&
        is_detected_exact<bool, end_array_function_t, SAX>::value &&
        is_detected_exact<bool, parse_error_function_t, SAX, exception_t>::value;
};
template<typename SAX, typename BasicJsonType>
struct is_sax_static_asserts
{
  private:
    static_assert(is_basic_json<BasicJsonType>::value,
                  "BasicJsonType must be of type basic_json<...>");
    using number_integer_t = typename BasicJsonType::number_integer_t;
    using number_unsigned_t = typename BasicJsonType::number_unsigned_t;
    using number_float_t = typename BasicJsonType::number_float_t;
    using string_t = typename BasicJsonType::string_t;
    using binary_t = typename BasicJsonType::binary_t;
    using exception_t = typename BasicJsonType::exception;
  public:
    static_assert(is_detected_exact<bool, null_function_t, SAX>::value,
                  "Missing/invalid function: bool null()");
    static_assert(is_detected_exact<bool, boolean_function_t, SAX>::value,
                  "Missing/invalid function: bool boolean(bool)");
    static_assert(is_detected_exact<bool, boolean_function_t, SAX>::value,
                  "Missing/invalid function: bool boolean(bool)");
    static_assert(
        is_detected_exact<bool, number_integer_function_t, SAX,
        number_integer_t>::value,
        "Missing/invalid function: bool number_integer(number_integer_t)");
    static_assert(
        is_detected_exact<bool, number_unsigned_function_t, SAX,
        number_unsigned_t>::value,
        "Missing/invalid function: bool number_unsigned(number_unsigned_t)");
    static_assert(is_detected_exact<bool, number_float_function_t, SAX,
                  number_float_t, string_t>::value,
                  "Missing/invalid function: bool number_float(number_float_t, const string_t&)");
    static_assert(
        is_detected_exact<bool, string_function_t, SAX, string_t>::value,
        "Missing/invalid function: bool string(string_t&)");
    static_assert(
        is_detected_exact<bool, binary_function_t, SAX, binary_t>::value,
        "Missing/invalid function: bool binary(binary_t&)");
    static_assert(is_detected_exact<bool, start_object_function_t, SAX>::value,
                  "Missing/invalid function: bool start_object(std::size_t)");
    static_assert(is_detected_exact<bool, key_function_t, SAX, string_t>::value,
                  "Missing/invalid function: bool key(string_t&)");
    static_assert(is_detected_exact<bool, end_object_function_t, SAX>::value,
                  "Missing/invalid function: bool end_object()");
    static_assert(is_detected_exact<bool, start_array_function_t, SAX>::value,
                  "Missing/invalid function: bool start_array(std::size_t)");
    static_assert(is_detected_exact<bool, end_array_function_t, SAX>::value,
                  "Missing/invalid function: bool end_array()");
    static_assert(
        is_detected_exact<bool, parse_error_function_t, SAX, exception_t>::value,
        "Missing/invalid function: bool parse_error(std::size_t, const "
        "std::string&, const exception&)");
};
}  
NLOHMANN_JSON_NAMESPACE_END
NLOHMANN_JSON_NAMESPACE_BEGIN
namespace detail
{
enum class cbor_tag_handler_t
{
    error,   
    ignore,  
    store    
};
inline bool little_endianness(int num = 1) noexcept
{
    return *reinterpret_cast<char*>(&num) == 1;
}
JSON_INLINE_VARIABLE constexpr std::size_t max_valueless_container_size = 1 << 20;
template<typename BasicJsonType, typename InputAdapterType, typename SAX = json_sax_dom_parser<BasicJsonType, InputAdapterType>>
class binary_reader
{
    using number_integer_t = typename BasicJsonType::number_integer_t;
    using number_unsigned_t = typename BasicJsonType::number_unsigned_t;
    using number_float_t = typename BasicJsonType::number_float_t;
    using string_t = typename BasicJsonType::string_t;
    using binary_t = typename BasicJsonType::binary_t;
    using json_sax_t = SAX;
    using char_type = typename InputAdapterType::char_type;
    using char_int_type = typename char_traits<char_type>::int_type;
    static constexpr bool bulk_scan =
        input_adapter_supports_bulk_scan<InputAdapterType>(is_detected<detect_supports_bulk_scan, InputAdapterType> {});
  public:
    explicit binary_reader(InputAdapterType&& adapter, const input_format_t format = input_format_t::json) noexcept : ia(std::move(adapter)), input_format(format)
    {
        (void)detail::is_sax_static_asserts<SAX, BasicJsonType> {};
    }
    binary_reader(const binary_reader&) = delete;
    binary_reader(binary_reader&&) = default; 
    binary_reader& operator=(const binary_reader&) = delete;
    binary_reader& operator=(binary_reader&&) = default; 
    ~binary_reader() = default;
    JSON_HEDLEY_NON_NULL(2)
    bool sax_parse(json_sax_t* sax_,
                   const bool strict = true,
                   const cbor_tag_handler_t tag_handler = cbor_tag_handler_t::error)
    {
        sax = sax_;
        container_stack.clear();
        bon8_pushback_size = 0;
        bool result = false;
        switch (input_format)
        {
            case input_format_t::bson:
                result = parse_bson_internal();
                break;
            case input_format_t::cbor:
                result = parse_cbor_internal(tag_handler);
                break;
            case input_format_t::msgpack:
                result = parse_msgpack_internal();
                break;
            case input_format_t::ubjson:
            case input_format_t::bjdata:
                result = parse_ubjson_internal();
                break;
            case input_format_t::bon8:
                result = parse_bon8_internal();
                break;
            case input_format_t::json: 
            default:            
                JSON_ASSERT(false); 
        }
        if (result && strict)
        {
            if (input_format == input_format_t::ubjson || input_format == input_format_t::bjdata)
            {
                get_ignore_noop();
            }
            else if (input_format == input_format_t::bon8)
            {
                get_bon8();
            }
            else
            {
                get();
            }
            if (JSON_HEDLEY_UNLIKELY(current != char_traits<char_type>::eof()))
            {
                return sax->parse_error(chars_read, get_token_string(), parse_error::create(110, chars_read,
                                        exception_message(input_format, concat("expected end of input; last byte: 0x", get_token_string()), "value"), nullptr));
            }
        }
        return result;
    }
  private:
    struct container_frame
    {
        container_frame(const std::size_t remaining_, const bool is_object_,
                        const char_int_type type_marker_ = 0) noexcept
            : remaining(remaining_), type_marker(type_marker_), is_object(is_object_) {}
        std::size_t remaining;
        std::size_t start_position = 0;
        char_int_type type_marker;
        std::int32_t declared_size = 0;
        bool is_object;
    };
    bool enter_container(const bool is_object, const std::size_t len,
                         const char_int_type type_marker = 0)
    {
        if (JSON_HEDLEY_UNLIKELY(is_object ? !sax->start_object(len) : !sax->start_array(len)))
        {
            return false;
        }
        container_stack.emplace_back(len, is_object, type_marker);
        return true;
    }
    bool enter_array(const std::size_t len, const char_int_type type_marker = 0)
    {
        return enter_container(false, len, type_marker);
    }
    bool enter_object(const std::size_t len, const char_int_type type_marker = 0)
    {
        return enter_container(true, len, type_marker);
    }
    bool leave_container()
    {
        const bool is_object = container_stack.back().is_object;
        container_stack.pop_back();
        return is_object ? sax->end_object() : sax->end_array();
    }
    bool check_bson_document_size(const std::size_t document_start, const std::int32_t document_size)
    {
        if (JSON_HEDLEY_UNLIKELY(document_size < 0 || static_cast<std::size_t>(document_size) != chars_read - document_start))
        {
            return sax->parse_error(chars_read, get_token_string(), parse_error::create(112, chars_read,
                                    exception_message(input_format_t::bson, concat("document size ", std::to_string(document_size), " does not match the number of bytes read (", std::to_string(chars_read - document_start), ")"), "document"), nullptr));
        }
        return true;
    }
    bool open_bson_document(const bool is_object)
    {
        const std::size_t document_start = chars_read;
        std::int32_t document_size{};
        if (!get_number<std::int32_t, true>(input_format_t::bson, document_size))
        {
            return false;
        }
        if (JSON_HEDLEY_UNLIKELY(!enter_container(is_object, detail::unknown_size())))
        {
            return false;
        }
        container_frame& frame = container_stack.back();
        frame.start_position = document_start;
        frame.declared_size = document_size;
        return true;
    }
    bool parse_bson_internal()
    {
        if (JSON_HEDLEY_UNLIKELY(!open_bson_document(true)))
        {
            return false;
        }
        string_t key;
        while (true)
        {
            const auto element_type = get();
            if (element_type == 0) 
            {
                const container_frame top = container_stack.back();
                if (JSON_HEDLEY_UNLIKELY(!check_bson_document_size(top.start_position, top.declared_size)))
                {
                    return false;
                }
                if (JSON_HEDLEY_UNLIKELY(!leave_container()))
                {
                    return false;
                }
                if (container_stack.empty())
                {
                    return true;
                }
                continue;
            }
            if (JSON_HEDLEY_UNLIKELY(!unexpect_eof(input_format_t::bson, "element list")))
            {
                return false;
            }
            const std::size_t element_type_parse_position = chars_read;
            key.clear();
            if (JSON_HEDLEY_UNLIKELY(!get_bson_cstr(key)))
            {
                return false;
            }
            if (container_stack.back().is_object && !sax->key(key))
            {
                return false;
            }
            if (JSON_HEDLEY_UNLIKELY(!parse_bson_element_internal(element_type, element_type_parse_position)))
            {
                return false;
            }
        }
    }
    bool get_bson_cstr(string_t& result)
    {
        if (get_bson_cstr_bulk(result, std::integral_constant<bool, bulk_scan> {}))
        {
            return true;
        }
        auto out = std::back_inserter(result);
        while (true)
        {
            get();
            if (JSON_HEDLEY_UNLIKELY(!unexpect_eof(input_format_t::bson, "cstring")))
            {
                return false;
            }
            if (current == 0x00)
            {
                return true;
            }
            *out++ = static_cast<typename string_t::value_type>(current);
        }
    }
    bool get_bson_cstr_bulk(string_t& result, std::true_type )
    {
        const std::size_t remaining = ia.bulk_remaining();
        if (remaining == 0)
        {
            return false;
        }
        const auto* const data = reinterpret_cast<const unsigned char*>(ia.bulk_data());
        std::size_t length = 0;
        while (length < remaining && data[length] != 0x00)
        {
            ++length;
        }
        if (length == remaining)
        {
            return false;
        }
        result.append(reinterpret_cast<const typename string_t::value_type*>(data), length);
        ia.bulk_skip(length + 1);
        chars_read += length + 1;
        current = 0x00;
        return true;
    }
    bool get_bson_cstr_bulk(string_t& , std::false_type ) const noexcept
    {
        return false;
    }
    template<typename NumberType>
    bool get_bson_string(const NumberType len, string_t& result)
    {
        if (JSON_HEDLEY_UNLIKELY(len < 1))
        {
            auto last_token = get_token_string();
            return sax->parse_error(chars_read, last_token, parse_error::create(112, chars_read,
                                    exception_message(input_format_t::bson, concat("string length must be at least 1, is ", std::to_string(len)), "string"), nullptr));
        }
        if (JSON_HEDLEY_UNLIKELY(!get_string(input_format_t::bson, len - static_cast<NumberType>(1), result)))
        {
            return false;
        }
        if (JSON_HEDLEY_UNLIKELY(get() != 0x00))
        {
            auto last_token = get_token_string();
            return sax->parse_error(chars_read, last_token, parse_error::create(112, chars_read,
                                    exception_message(input_format_t::bson,
                                            "BSON string is not null-terminated",
                                            "string"), nullptr));
        }
        return true;
    }
    template<typename NumberType>
    bool get_bson_binary(const NumberType len, binary_t& result)
    {
        if (JSON_HEDLEY_UNLIKELY(len < 0))
        {
            auto last_token = get_token_string();
            return sax->parse_error(chars_read, last_token, parse_error::create(112, chars_read,
                                    exception_message(input_format_t::bson, concat("byte array length cannot be negative, is ", std::to_string(len)), "binary"), nullptr));
        }
        std::uint8_t subtype{};
        if (JSON_HEDLEY_UNLIKELY(!get_number<std::uint8_t>(input_format_t::bson, subtype)))
        {
            return false;
        }
        result.set_subtype(subtype);
        return get_binary(input_format_t::bson, len, result);
    }
    bool parse_bson_element_internal(const char_int_type element_type,
                                     const std::size_t element_type_parse_position)
    {
        switch (element_type)
        {
            case 0x01: 
            {
                double number{};
                return get_number<double, true>(input_format_t::bson, number) && sax->number_float(static_cast<number_float_t>(number), "");
            }
            case 0x02: 
            {
                std::int32_t len{};
                string_t value;
                return get_number<std::int32_t, true>(input_format_t::bson, len) && get_bson_string(len, value) && sax->string(value);
            }
            case 0x03: 
            {
                return open_bson_document(true);
            }
            case 0x04: 
            {
                return open_bson_document(false);
            }
            case 0x05: 
            {
                std::int32_t len{};
                binary_t value;
                return get_number<std::int32_t, true>(input_format_t::bson, len) && get_bson_binary(len, value) && sax->binary(value);
            }
            case 0x08: 
            {
                std::uint8_t value{};
                return get_number<std::uint8_t>(input_format_t::bson, value) && sax->boolean(value != 0);
            }
            case 0x0A: 
            {
                return sax->null();
            }
            case 0x10: 
            {
                std::int32_t value{};
                return get_number<std::int32_t, true>(input_format_t::bson, value) && sax->number_integer(conditional_static_cast<number_integer_t>(value));
            }
            case 0x12: 
            {
                std::int64_t value{};
                return get_number<std::int64_t, true>(input_format_t::bson, value) && sax->number_integer(conditional_static_cast<number_integer_t>(value));
            }
            case 0x11: 
            {
                std::uint64_t value{};
                return get_number<std::uint64_t, true>(input_format_t::bson, value) && sax->number_unsigned(value);
            }
            default: 
            {
                std::array<char, 3> cr{{}};
                static_cast<void>((std::snprintf)(cr.data(), cr.size(), "%.2hhX", static_cast<unsigned char>(element_type))); 
                const std::string cr_str{cr.data()};
                return sax->parse_error(element_type_parse_position, cr_str,
                                        parse_error::create(114, element_type_parse_position, concat("Unsupported BSON record type 0x", cr_str), nullptr));
            }
        }
    }
    template<typename NumberType>
    bool get_cbor_negative_integer()
    {
        NumberType number{};
        if (JSON_HEDLEY_UNLIKELY(!get_number(input_format_t::cbor, number)))
        {
            return false;
        }
        const auto max_val = static_cast<NumberType>((std::numeric_limits<number_integer_t>::max)());
        if (number > max_val)
        {
            return sax->parse_error(chars_read, get_token_string(),
                                    parse_error::create(112, chars_read,
                                            exception_message(input_format_t::cbor, "negative integer overflow", "value"), nullptr));
        }
        return sax->number_integer(conditional_static_cast<number_integer_t>(static_cast<number_integer_t>(-1) - static_cast<number_integer_t>(number)));
    }
    bool parse_cbor_value(const bool get_char,
                          const cbor_tag_handler_t tag_handler,
                          bool& tag_pending,
                          bool& item_read)
    {
        tag_pending = false;
        item_read = false;
        switch (get_char ? get() : current)
        {
            case char_traits<char_type>::eof():
                return unexpect_eof(input_format_t::cbor, "value");
            case 0x00:
            case 0x01:
            case 0x02:
            case 0x03:
            case 0x04:
            case 0x05:
            case 0x06:
            case 0x07:
            case 0x08:
            case 0x09:
            case 0x0A:
            case 0x0B:
            case 0x0C:
            case 0x0D:
            case 0x0E:
            case 0x0F:
            case 0x10:
            case 0x11:
            case 0x12:
            case 0x13:
            case 0x14:
            case 0x15:
            case 0x16:
            case 0x17:
                return sax->number_unsigned(static_cast<number_unsigned_t>(current));
            case 0x18: 
            {
                std::uint8_t number{};
                return get_number(input_format_t::cbor, number) && sax->number_unsigned(number);
            }
            case 0x19: 
            {
                std::uint16_t number{};
                return get_number(input_format_t::cbor, number) && sax->number_unsigned(number);
            }
            case 0x1A: 
            {
                std::uint32_t number{};
                return get_number(input_format_t::cbor, number) && sax->number_unsigned(number);
            }
            case 0x1B: 
            {
                std::uint64_t number{};
                return get_number(input_format_t::cbor, number) && sax->number_unsigned(number);
            }
            case 0x20:
            case 0x21:
            case 0x22:
            case 0x23:
            case 0x24:
            case 0x25:
            case 0x26:
            case 0x27:
            case 0x28:
            case 0x29:
            case 0x2A:
            case 0x2B:
            case 0x2C:
            case 0x2D:
            case 0x2E:
            case 0x2F:
            case 0x30:
            case 0x31:
            case 0x32:
            case 0x33:
            case 0x34:
            case 0x35:
            case 0x36:
            case 0x37:
                return sax->number_integer(static_cast<std::int8_t>(0x20 - 1 - current));
            case 0x38: 
                return get_cbor_negative_integer<std::uint8_t>();
            case 0x39: 
                return get_cbor_negative_integer<std::uint16_t>();
            case 0x3A: 
                return get_cbor_negative_integer<std::uint32_t>();
            case 0x3B: 
                return get_cbor_negative_integer<std::uint64_t>();
            case 0x40:
            case 0x41:
            case 0x42:
            case 0x43:
            case 0x44:
            case 0x45:
            case 0x46:
            case 0x47:
            case 0x48:
            case 0x49:
            case 0x4A:
            case 0x4B:
            case 0x4C:
            case 0x4D:
            case 0x4E:
            case 0x4F:
            case 0x50:
            case 0x51:
            case 0x52:
            case 0x53:
            case 0x54:
            case 0x55:
            case 0x56:
            case 0x57:
            case 0x58: 
            case 0x59: 
            case 0x5A: 
            case 0x5B: 
            case 0x5F: 
            {
                binary_t b;
                return get_cbor_binary(b) && sax->binary(b);
            }
            case 0x60:
            case 0x61:
            case 0x62:
            case 0x63:
            case 0x64:
            case 0x65:
            case 0x66:
            case 0x67:
            case 0x68:
            case 0x69:
            case 0x6A:
            case 0x6B:
            case 0x6C:
            case 0x6D:
            case 0x6E:
            case 0x6F:
            case 0x70:
            case 0x71:
            case 0x72:
            case 0x73:
            case 0x74:
            case 0x75:
            case 0x76:
            case 0x77:
            case 0x78: 
            case 0x79: 
            case 0x7A: 
            case 0x7B: 
            case 0x7F: 
            {
                string_t s;
                return get_cbor_string(s) && sax->string(s);
            }
            case 0x80:
            case 0x81:
            case 0x82:
            case 0x83:
            case 0x84:
            case 0x85:
            case 0x86:
            case 0x87:
            case 0x88:
            case 0x89:
            case 0x8A:
            case 0x8B:
            case 0x8C:
            case 0x8D:
            case 0x8E:
            case 0x8F:
            case 0x90:
            case 0x91:
            case 0x92:
            case 0x93:
            case 0x94:
            case 0x95:
            case 0x96:
            case 0x97:
                return enter_array(conditional_static_cast<std::size_t>(static_cast<unsigned int>(current) & 0x1Fu));
            case 0x98: 
            case 0x99: 
            case 0x9A: 
            case 0x9B: 
            {
                std::uint64_t len{};
                std::size_t size{};
                return get_cbor_argument(len) && get_cbor_container_size(len, size, "array") && enter_array(size);
            }
            case 0x9F: 
                return enter_array(detail::unknown_size());
            case 0xA0:
            case 0xA1:
            case 0xA2:
            case 0xA3:
            case 0xA4:
            case 0xA5:
            case 0xA6:
            case 0xA7:
            case 0xA8:
            case 0xA9:
            case 0xAA:
            case 0xAB:
            case 0xAC:
            case 0xAD:
            case 0xAE:
            case 0xAF:
            case 0xB0:
            case 0xB1:
            case 0xB2:
            case 0xB3:
            case 0xB4:
            case 0xB5:
            case 0xB6:
            case 0xB7:
                return enter_object(conditional_static_cast<std::size_t>(static_cast<unsigned int>(current) & 0x1Fu));
            case 0xB8: 
            case 0xB9: 
            case 0xBA: 
            case 0xBB: 
            {
                std::uint64_t len{};
                std::size_t size{};
                return get_cbor_argument(len) && get_cbor_container_size(len, size, "map") && enter_object(size);
            }
            case 0xBF: 
                return enter_object(detail::unknown_size());
            case 0xC0: 
            case 0xC1:
            case 0xC2:
            case 0xC3:
            case 0xC4:
            case 0xC5:
            case 0xC6:
            case 0xC7:
            case 0xC8:
            case 0xC9:
            case 0xCA:
            case 0xCB:
            case 0xCC:
            case 0xCD:
            case 0xCE:
            case 0xCF:
            case 0xD0:
            case 0xD1:
            case 0xD2:
            case 0xD3:
            case 0xD4:
            case 0xD5:
            case 0xD6:
            case 0xD7:
            {
                if (tag_handler == cbor_tag_handler_t::error)
                {
                    auto last_token = get_token_string();
                    return sax->parse_error(chars_read, last_token, parse_error::create(112, chars_read,
                                            exception_message(input_format_t::cbor, concat("invalid byte: 0x", last_token), "value"), nullptr));
                }
                tag_pending = true;
                return true;
            }
            case 0xD8: 
            case 0xD9: 
            case 0xDA: 
            case 0xDB: 
            {
                switch (tag_handler)
                {
                    case cbor_tag_handler_t::error:
                    {
                        auto last_token = get_token_string();
                        return sax->parse_error(chars_read, last_token, parse_error::create(112, chars_read,
                                                exception_message(input_format_t::cbor, concat("invalid byte: 0x", last_token), "value"), nullptr));
                    }
                    case cbor_tag_handler_t::ignore:
                    {
                        std::uint64_t subtype_to_ignore{};
                        if (!get_cbor_argument(subtype_to_ignore))
                        {
                            return false;
                        }
                        tag_pending = true;
                        return true;
                    }
                    case cbor_tag_handler_t::store:
                    {
                        std::uint64_t subtype{};
                        if (!get_cbor_argument(subtype))
                        {
                            return false;
                        }
                        binary_t b;
                        b.set_subtype(detail::conditional_static_cast<typename binary_t::subtype_type>(subtype));
                        get();
                        if ((current >= 0x40 && current <= 0x5B) || current == 0x5F)
                        {
                            return get_cbor_binary(b) && sax->binary(b);
                        }
                        tag_pending = true;
                        item_read = true;
                        return true;
                    }
                    default:                 
                        JSON_ASSERT(false); 
                        return false;        
                }
            }
            case 0xF4: 
                return sax->boolean(false);
            case 0xF5: 
                return sax->boolean(true);
            case 0xF6: 
                return sax->null();
            case 0xF9: 
                return get_half_float(input_format_t::cbor, false);
            case 0xFA: 
            {
                float number{};
                return get_number(input_format_t::cbor, number) && sax->number_float(static_cast<number_float_t>(number), "");
            }
            case 0xFB: 
            {
                double number{};
                return get_number(input_format_t::cbor, number) && sax->number_float(static_cast<number_float_t>(number), "");
            }
            default: 
            {
                auto last_token = get_token_string();
                return sax->parse_error(chars_read, last_token, parse_error::create(112, chars_read,
                                        exception_message(input_format_t::cbor, concat("invalid byte: 0x", last_token), "value"), nullptr));
            }
        }
    }
    bool get_cbor_string_chunk(string_t& result)
    {
        switch (current)
        {
            case 0x60:
            case 0x61:
            case 0x62:
            case 0x63:
            case 0x64:
            case 0x65:
            case 0x66:
            case 0x67:
            case 0x68:
            case 0x69:
            case 0x6A:
            case 0x6B:
            case 0x6C:
            case 0x6D:
            case 0x6E:
            case 0x6F:
            case 0x70:
            case 0x71:
            case 0x72:
            case 0x73:
            case 0x74:
            case 0x75:
            case 0x76:
            case 0x77:
            {
                return get_string(input_format_t::cbor, static_cast<unsigned int>(current) & 0x1Fu, result);
            }
            case 0x78: 
            {
                std::uint8_t len{};
                return get_number(input_format_t::cbor, len) && get_string(input_format_t::cbor, len, result);
            }
            case 0x79: 
            {
                std::uint16_t len{};
                return get_number(input_format_t::cbor, len) && get_string(input_format_t::cbor, len, result);
            }
            case 0x7A: 
            {
                std::uint32_t len{};
                return get_number(input_format_t::cbor, len) && get_string(input_format_t::cbor, len, result);
            }
            case 0x7B: 
            {
                std::uint64_t len{};
                return get_number(input_format_t::cbor, len) && get_string(input_format_t::cbor, len, result);
            }
            default:
            {
                auto last_token = get_token_string();
                return sax->parse_error(chars_read, last_token, parse_error::create(113, chars_read,
                                        exception_message(input_format_t::cbor, concat("expected length specification (0x60-0x7B) or indefinite string type (0x7F); last byte: 0x", last_token), "string"), nullptr));
            }
        }
    }
    bool get_cbor_string(string_t& result)
    {
        std::size_t open = 0;
        while (true)
        {
            if (JSON_HEDLEY_UNLIKELY(!unexpect_eof(input_format_t::cbor, "string")))
            {
                return false;
            }
            if (current == 0x7F) 
            {
                ++open;
                get();
                continue;
            }
            if (open != 0 && current == 0xFF)
            {
                if (--open == 0)
                {
                    return true;
                }
                get();
                continue;
            }
            if (JSON_HEDLEY_UNLIKELY(!get_cbor_string_chunk(result)))
            {
                return false;
            }
            if (open == 0)
            {
                return true;
            }
            get();
        }
    }
    bool get_cbor_object_key(string_t& result)
    {
        if (current == char_traits<char_type>::eof() || (static_cast<unsigned int>(current) & 0xE0u) == 0x60u)
        {
            return get_cbor_string(result);
        }
        const char* found = nullptr;
        switch (static_cast<unsigned int>(current) >> 5u)
        {
            case 0:
                found = "an unsigned integer";
                break;
            case 1:
                found = "a negative integer";
                break;
            case 2:
                found = "a byte string";
                break;
            case 4:
                found = "an array";
                break;
            case 5:
                found = "a map";
                break;
            case 6:
                found = "a tag";
                break;
            default: 
                switch (current)
                {
                    case 0xF4:
                    case 0xF5:
                        found = "a boolean";
                        break;
                    case 0xF6:
                        found = "null";
                        break;
                    case 0xF7:
                        found = "undefined";
                        break;
                    case 0xF9:
                    case 0xFA:
                    case 0xFB:
                        found = "a floating-point number";
                        break;
                    case 0xFF:
                        found = "a break stop code";
                        break;
                    default:
                        found = "a simple value";
                        break;
                }
                break;
        }
        auto last_token = get_token_string();
        return sax->parse_error(chars_read, last_token, parse_error::create(113, chars_read,
                                exception_message(input_format_t::cbor, concat("only string keys are supported, but found ", found, "; last byte: 0x", last_token), "object key"), nullptr));
    }
    bool get_cbor_binary_chunk(binary_t& result)
    {
        switch (current)
        {
            case 0x40:
            case 0x41:
            case 0x42:
            case 0x43:
            case 0x44:
            case 0x45:
            case 0x46:
            case 0x47:
            case 0x48:
            case 0x49:
            case 0x4A:
            case 0x4B:
            case 0x4C:
            case 0x4D:
            case 0x4E:
            case 0x4F:
            case 0x50:
            case 0x51:
            case 0x52:
            case 0x53:
            case 0x54:
            case 0x55:
            case 0x56:
            case 0x57:
            {
                return get_binary(input_format_t::cbor, static_cast<unsigned int>(current) & 0x1Fu, result);
            }
            case 0x58: 
            {
                std::uint8_t len{};
                return get_number(input_format_t::cbor, len) &&
                       get_binary(input_format_t::cbor, len, result);
            }
            case 0x59: 
            {
                std::uint16_t len{};
                return get_number(input_format_t::cbor, len) &&
                       get_binary(input_format_t::cbor, len, result);
            }
            case 0x5A: 
            {
                std::uint32_t len{};
                return get_number(input_format_t::cbor, len) &&
                       get_binary(input_format_t::cbor, len, result);
            }
            case 0x5B: 
            {
                std::uint64_t len{};
                return get_number(input_format_t::cbor, len) &&
                       get_binary(input_format_t::cbor, len, result);
            }
            default:
            {
                auto last_token = get_token_string();
                return sax->parse_error(chars_read, last_token, parse_error::create(113, chars_read,
                                        exception_message(input_format_t::cbor, concat("expected length specification (0x40-0x5B) or indefinite binary array type (0x5F); last byte: 0x", last_token), "binary"), nullptr));
            }
        }
    }
    bool get_cbor_binary(binary_t& result)
    {
        std::size_t open = 0;
        while (true)
        {
            if (JSON_HEDLEY_UNLIKELY(!unexpect_eof(input_format_t::cbor, "binary")))
            {
                return false;
            }
            if (current == 0x5F) 
            {
                ++open;
                get();
                continue;
            }
            if (open != 0 && current == 0xFF)
            {
                if (--open == 0)
                {
                    return true;
                }
                get();
                continue;
            }
            if (JSON_HEDLEY_UNLIKELY(!get_cbor_binary_chunk(result)))
            {
                return false;
            }
            if (open == 0)
            {
                return true;
            }
            get();
        }
    }
    bool get_cbor_argument(std::uint64_t& value)
    {
        switch (current & 0x1F)
        {
            case 0x18: 
            {
                std::uint8_t n{};
                if (JSON_HEDLEY_UNLIKELY(!get_number(input_format_t::cbor, n)))
                {
                    return false;
                }
                value = n;
                return true;
            }
            case 0x19: 
            {
                std::uint16_t n{};
                if (JSON_HEDLEY_UNLIKELY(!get_number(input_format_t::cbor, n)))
                {
                    return false;
                }
                value = n;
                return true;
            }
            case 0x1A: 
            {
                std::uint32_t n{};
                if (JSON_HEDLEY_UNLIKELY(!get_number(input_format_t::cbor, n)))
                {
                    return false;
                }
                value = n;
                return true;
            }
            case 0x1B: 
            {
                std::uint64_t n{};
                if (JSON_HEDLEY_UNLIKELY(!get_number(input_format_t::cbor, n)))
                {
                    return false;
                }
                value = n;
                return true;
            }
            default:                 
                JSON_ASSERT(false); 
                return false;        
        }
    }
    bool get_cbor_container_size(const std::uint64_t len, std::size_t& result, const char* context)
    {
        if (JSON_HEDLEY_UNLIKELY(!value_in_range_of<std::size_t>(len) || len == detail::unknown_size()))
        {
            return sax->parse_error(chars_read, get_token_string(), out_of_range::create(408,
                                    exception_message(input_format_t::cbor, concat("excessive ", context, " size"), "size"), nullptr));
        }
        result = conditional_static_cast<std::size_t>(len);
        return true;
    }
    bool parse_cbor_internal(const cbor_tag_handler_t tag_handler)
    {
        bool fetch = true;
        string_t key;
        while (true)
        {
            if (!container_stack.empty())
            {
                const container_frame top = container_stack.back();
                bool at_end = false;
                if (top.remaining != npos)
                {
                    at_end = (top.remaining == 0);
                    if (!at_end)
                    {
                        --container_stack.back().remaining;
                        if (top.is_object)
                        {
                            get();
                        }
                    }
                    fetch = true;
                }
                else
                {
                    at_end = (get() == 0xFF);
                    fetch = top.is_object;
                }
                if (at_end)
                {
                    if (JSON_HEDLEY_UNLIKELY(!leave_container()))
                    {
                        return false;
                    }
                    if (container_stack.empty())
                    {
                        return true;
                    }
                    continue;
                }
                if (top.is_object)
                {
                    key.clear();
                    if (JSON_HEDLEY_UNLIKELY(!get_cbor_object_key(key) || !sax->key(key)))
                    {
                        return false;
                    }
                    fetch = true;
                }
            }
            bool tag_pending = false;
            bool item_read = false;
            do
            {
                if (JSON_HEDLEY_UNLIKELY(!parse_cbor_value(fetch, tag_handler, tag_pending, item_read)))
                {
                    return false;
                }
                fetch = !item_read;
            }
            while (tag_pending);
            if (container_stack.empty())
            {
                return true;
            }
        }
    }
    bool parse_msgpack_value()
    {
        switch (get())
        {
            case char_traits<char_type>::eof():
                return unexpect_eof(input_format_t::msgpack, "value");
            case 0x00:
            case 0x01:
            case 0x02:
            case 0x03:
            case 0x04:
            case 0x05:
            case 0x06:
            case 0x07:
            case 0x08:
            case 0x09:
            case 0x0A:
            case 0x0B:
            case 0x0C:
            case 0x0D:
            case 0x0E:
            case 0x0F:
            case 0x10:
            case 0x11:
            case 0x12:
            case 0x13:
            case 0x14:
            case 0x15:
            case 0x16:
            case 0x17:
            case 0x18:
            case 0x19:
            case 0x1A:
            case 0x1B:
            case 0x1C:
            case 0x1D:
            case 0x1E:
            case 0x1F:
            case 0x20:
            case 0x21:
            case 0x22:
            case 0x23:
            case 0x24:
            case 0x25:
            case 0x26:
            case 0x27:
            case 0x28:
            case 0x29:
            case 0x2A:
            case 0x2B:
            case 0x2C:
            case 0x2D:
            case 0x2E:
            case 0x2F:
            case 0x30:
            case 0x31:
            case 0x32:
            case 0x33:
            case 0x34:
            case 0x35:
            case 0x36:
            case 0x37:
            case 0x38:
            case 0x39:
            case 0x3A:
            case 0x3B:
            case 0x3C:
            case 0x3D:
            case 0x3E:
            case 0x3F:
            case 0x40:
            case 0x41:
            case 0x42:
            case 0x43:
            case 0x44:
            case 0x45:
            case 0x46:
            case 0x47:
            case 0x48:
            case 0x49:
            case 0x4A:
            case 0x4B:
            case 0x4C:
            case 0x4D:
            case 0x4E:
            case 0x4F:
            case 0x50:
            case 0x51:
            case 0x52:
            case 0x53:
            case 0x54:
            case 0x55:
            case 0x56:
            case 0x57:
            case 0x58:
            case 0x59:
            case 0x5A:
            case 0x5B:
            case 0x5C:
            case 0x5D:
            case 0x5E:
            case 0x5F:
            case 0x60:
            case 0x61:
            case 0x62:
            case 0x63:
            case 0x64:
            case 0x65:
            case 0x66:
            case 0x67:
            case 0x68:
            case 0x69:
            case 0x6A:
            case 0x6B:
            case 0x6C:
            case 0x6D:
            case 0x6E:
            case 0x6F:
            case 0x70:
            case 0x71:
            case 0x72:
            case 0x73:
            case 0x74:
            case 0x75:
            case 0x76:
            case 0x77:
            case 0x78:
            case 0x79:
            case 0x7A:
            case 0x7B:
            case 0x7C:
            case 0x7D:
            case 0x7E:
            case 0x7F:
                return sax->number_unsigned(static_cast<number_unsigned_t>(current));
            case 0x80:
            case 0x81:
            case 0x82:
            case 0x83:
            case 0x84:
            case 0x85:
            case 0x86:
            case 0x87:
            case 0x88:
            case 0x89:
            case 0x8A:
            case 0x8B:
            case 0x8C:
            case 0x8D:
            case 0x8E:
            case 0x8F:
                return enter_object(conditional_static_cast<std::size_t>(static_cast<unsigned int>(current) & 0x0Fu));
            case 0x90:
            case 0x91:
            case 0x92:
            case 0x93:
            case 0x94:
            case 0x95:
            case 0x96:
            case 0x97:
            case 0x98:
            case 0x99:
            case 0x9A:
            case 0x9B:
            case 0x9C:
            case 0x9D:
            case 0x9E:
            case 0x9F:
                return enter_array(conditional_static_cast<std::size_t>(static_cast<unsigned int>(current) & 0x0Fu));
            case 0xA0:
            case 0xA1:
            case 0xA2:
            case 0xA3:
            case 0xA4:
            case 0xA5:
            case 0xA6:
            case 0xA7:
            case 0xA8:
            case 0xA9:
            case 0xAA:
            case 0xAB:
            case 0xAC:
            case 0xAD:
            case 0xAE:
            case 0xAF:
            case 0xB0:
            case 0xB1:
            case 0xB2:
            case 0xB3:
            case 0xB4:
            case 0xB5:
            case 0xB6:
            case 0xB7:
            case 0xB8:
            case 0xB9:
            case 0xBA:
            case 0xBB:
            case 0xBC:
            case 0xBD:
            case 0xBE:
            case 0xBF:
            case 0xD9: 
            case 0xDA: 
            case 0xDB: 
            {
                string_t s;
                return get_msgpack_string(s) && sax->string(s);
            }
            case 0xC0: 
                return sax->null();
            case 0xC2: 
                return sax->boolean(false);
            case 0xC3: 
                return sax->boolean(true);
            case 0xC4: 
            case 0xC5: 
            case 0xC6: 
            case 0xC7: 
            case 0xC8: 
            case 0xC9: 
            case 0xD4: 
            case 0xD5: 
            case 0xD6: 
            case 0xD7: 
            case 0xD8: 
            {
                binary_t b;
                return get_msgpack_binary(b) && sax->binary(b);
            }
            case 0xCA: 
            {
                float number{};
                return get_number(input_format_t::msgpack, number) && sax->number_float(static_cast<number_float_t>(number), "");
            }
            case 0xCB: 
            {
                double number{};
                return get_number(input_format_t::msgpack, number) && sax->number_float(static_cast<number_float_t>(number), "");
            }
            case 0xCC: 
            {
                std::uint8_t number{};
                return get_number(input_format_t::msgpack, number) && sax->number_unsigned(number);
            }
            case 0xCD: 
            {
                std::uint16_t number{};
                return get_number(input_format_t::msgpack, number) && sax->number_unsigned(number);
            }
            case 0xCE: 
            {
                std::uint32_t number{};
                return get_number(input_format_t::msgpack, number) && sax->number_unsigned(number);
            }
            case 0xCF: 
            {
                std::uint64_t number{};
                return get_number(input_format_t::msgpack, number) && sax->number_unsigned(number);
            }
            case 0xD0: 
            {
                std::int8_t number{};
                return get_number(input_format_t::msgpack, number) && sax->number_integer(conditional_static_cast<number_integer_t>(number));
            }
            case 0xD1: 
            {
                std::int16_t number{};
                return get_number(input_format_t::msgpack, number) && sax->number_integer(conditional_static_cast<number_integer_t>(number));
            }
            case 0xD2: 
            {
                std::int32_t number{};
                return get_number(input_format_t::msgpack, number) && sax->number_integer(conditional_static_cast<number_integer_t>(number));
            }
            case 0xD3: 
            {
                std::int64_t number{};
                return get_number(input_format_t::msgpack, number) && sax->number_integer(conditional_static_cast<number_integer_t>(number));
            }
            case 0xDC: 
            {
                std::uint16_t len{};
                return get_number(input_format_t::msgpack, len) && enter_array(static_cast<std::size_t>(len));
            }
            case 0xDD: 
            {
                std::uint32_t len{};
                return get_number(input_format_t::msgpack, len) && enter_array(conditional_static_cast<std::size_t>(len));
            }
            case 0xDE: 
            {
                std::uint16_t len{};
                return get_number(input_format_t::msgpack, len) && enter_object(static_cast<std::size_t>(len));
            }
            case 0xDF: 
            {
                std::uint32_t len{};
                return get_number(input_format_t::msgpack, len) && enter_object(conditional_static_cast<std::size_t>(len));
            }
            case 0xE0:
            case 0xE1:
            case 0xE2:
            case 0xE3:
            case 0xE4:
            case 0xE5:
            case 0xE6:
            case 0xE7:
            case 0xE8:
            case 0xE9:
            case 0xEA:
            case 0xEB:
            case 0xEC:
            case 0xED:
            case 0xEE:
            case 0xEF:
            case 0xF0:
            case 0xF1:
            case 0xF2:
            case 0xF3:
            case 0xF4:
            case 0xF5:
            case 0xF6:
            case 0xF7:
            case 0xF8:
            case 0xF9:
            case 0xFA:
            case 0xFB:
            case 0xFC:
            case 0xFD:
            case 0xFE:
            case 0xFF:
                return sax->number_integer(static_cast<std::int8_t>(current));
            default: 
            {
                auto last_token = get_token_string();
                return sax->parse_error(chars_read, last_token, parse_error::create(112, chars_read,
                                        exception_message(input_format_t::msgpack, concat("invalid byte: 0x", last_token), "value"), nullptr));
            }
        }
    }
    bool get_msgpack_string(string_t& result)
    {
        if (JSON_HEDLEY_UNLIKELY(!unexpect_eof(input_format_t::msgpack, "string")))
        {
            return false;
        }
        switch (current)
        {
            case 0xA0:
            case 0xA1:
            case 0xA2:
            case 0xA3:
            case 0xA4:
            case 0xA5:
            case 0xA6:
            case 0xA7:
            case 0xA8:
            case 0xA9:
            case 0xAA:
            case 0xAB:
            case 0xAC:
            case 0xAD:
            case 0xAE:
            case 0xAF:
            case 0xB0:
            case 0xB1:
            case 0xB2:
            case 0xB3:
            case 0xB4:
            case 0xB5:
            case 0xB6:
            case 0xB7:
            case 0xB8:
            case 0xB9:
            case 0xBA:
            case 0xBB:
            case 0xBC:
            case 0xBD:
            case 0xBE:
            case 0xBF:
            {
                return get_string(input_format_t::msgpack, static_cast<unsigned int>(current) & 0x1Fu, result);
            }
            case 0xD9: 
            {
                std::uint8_t len{};
                return get_number(input_format_t::msgpack, len) && get_string(input_format_t::msgpack, len, result);
            }
            case 0xDA: 
            {
                std::uint16_t len{};
                return get_number(input_format_t::msgpack, len) && get_string(input_format_t::msgpack, len, result);
            }
            case 0xDB: 
            {
                std::uint32_t len{};
                return get_number(input_format_t::msgpack, len) && get_string(input_format_t::msgpack, len, result);
            }
            default:
            {
                auto last_token = get_token_string();
                return sax->parse_error(chars_read, last_token, parse_error::create(113, chars_read,
                                        exception_message(input_format_t::msgpack, concat("expected length specification (0xA0-0xBF, 0xD9-0xDB); last byte: 0x", last_token), "string"), nullptr));
            }
        }
    }
    bool get_msgpack_object_key(string_t& result)
    {
        const char* found = nullptr;
        switch (current)
        {
            case 0xC0:
                found = "nil";
                break;
            case 0xC2:
            case 0xC3:
                found = "a boolean";
                break;
            case 0xCA:
            case 0xCB:
                found = "a float";
                break;
            case 0xC4:
            case 0xC5:
            case 0xC6:
                found = "a bin";
                break;
            case 0xC7:
            case 0xC8:
            case 0xC9:
            case 0xD4:
            case 0xD5:
            case 0xD6:
            case 0xD7:
            case 0xD8:
                found = "an ext";
                break;
            case 0xCC:
            case 0xCD:
            case 0xCE:
            case 0xCF:
            case 0xD0:
            case 0xD1:
            case 0xD2:
            case 0xD3:
                found = "an integer";
                break;
            case 0xDC:
            case 0xDD:
                found = "an array";
                break;
            case 0xDE:
            case 0xDF:
                found = "a map";
                break;
            default:
                if (current == char_traits<char_type>::eof())
                {
                    return get_msgpack_string(result);
                }
                if (current <= 0x7F || current >= 0xE0)
                {
                    found = "an integer";
                }
                else if (current <= 0x8F)
                {
                    found = "a map";
                }
                else if (current <= 0x9F)
                {
                    found = "an array";
                }
                else
                {
                    return get_msgpack_string(result);
                }
                break;
        }
        auto last_token = get_token_string();
        return sax->parse_error(chars_read, last_token, parse_error::create(113, chars_read,
                                exception_message(input_format_t::msgpack, concat("only string keys are supported, but found ", found, "; last byte: 0x", last_token), "object key"), nullptr));
    }
    bool get_msgpack_binary(binary_t& result)
    {
        auto assign_and_return_true = [&result](std::int8_t subtype)
        {
            result.set_subtype(static_cast<std::uint8_t>(subtype));
            return true;
        };
        switch (current)
        {
            case 0xC4: 
            {
                std::uint8_t len{};
                return get_number(input_format_t::msgpack, len) &&
                       get_binary(input_format_t::msgpack, len, result);
            }
            case 0xC5: 
            {
                std::uint16_t len{};
                return get_number(input_format_t::msgpack, len) &&
                       get_binary(input_format_t::msgpack, len, result);
            }
            case 0xC6: 
            {
                std::uint32_t len{};
                return get_number(input_format_t::msgpack, len) &&
                       get_binary(input_format_t::msgpack, len, result);
            }
            case 0xC7: 
            {
                std::uint8_t len{};
                std::int8_t subtype{};
                return get_number(input_format_t::msgpack, len) &&
                       get_number(input_format_t::msgpack, subtype) &&
                       get_binary(input_format_t::msgpack, len, result) &&
                       assign_and_return_true(subtype);
            }
            case 0xC8: 
            {
                std::uint16_t len{};
                std::int8_t subtype{};
                return get_number(input_format_t::msgpack, len) &&
                       get_number(input_format_t::msgpack, subtype) &&
                       get_binary(input_format_t::msgpack, len, result) &&
                       assign_and_return_true(subtype);
            }
            case 0xC9: 
            {
                std::uint32_t len{};
                std::int8_t subtype{};
                return get_number(input_format_t::msgpack, len) &&
                       get_number(input_format_t::msgpack, subtype) &&
                       get_binary(input_format_t::msgpack, len, result) &&
                       assign_and_return_true(subtype);
            }
            case 0xD4: 
            {
                std::int8_t subtype{};
                return get_number(input_format_t::msgpack, subtype) &&
                       get_binary(input_format_t::msgpack, 1, result) &&
                       assign_and_return_true(subtype);
            }
            case 0xD5: 
            {
                std::int8_t subtype{};
                return get_number(input_format_t::msgpack, subtype) &&
                       get_binary(input_format_t::msgpack, 2, result) &&
                       assign_and_return_true(subtype);
            }
            case 0xD6: 
            {
                std::int8_t subtype{};
                return get_number(input_format_t::msgpack, subtype) &&
                       get_binary(input_format_t::msgpack, 4, result) &&
                       assign_and_return_true(subtype);
            }
            case 0xD7: 
            {
                std::int8_t subtype{};
                return get_number(input_format_t::msgpack, subtype) &&
                       get_binary(input_format_t::msgpack, 8, result) &&
                       assign_and_return_true(subtype);
            }
            case 0xD8: 
            {
                std::int8_t subtype{};
                return get_number(input_format_t::msgpack, subtype) &&
                       get_binary(input_format_t::msgpack, 16, result) &&
                       assign_and_return_true(subtype);
            }
            default:           
                return false;  
        }
    }
    bool parse_msgpack_internal()
    {
        string_t key;
        while (true)
        {
            if (!container_stack.empty())
            {
                const bool is_object = container_stack.back().is_object;
                if (container_stack.back().remaining == 0)
                {
                    if (JSON_HEDLEY_UNLIKELY(!leave_container()))
                    {
                        return false;
                    }
                    if (container_stack.empty())
                    {
                        return true;
                    }
                    continue;
                }
                --container_stack.back().remaining;
                if (is_object)
                {
                    get();
                    key.clear();
                    if (JSON_HEDLEY_UNLIKELY(!get_msgpack_object_key(key) || !sax->key(key)))
                    {
                        return false;
                    }
                }
            }
            if (JSON_HEDLEY_UNLIKELY(!parse_msgpack_value()))
            {
                return false;
            }
            if (container_stack.empty())
            {
                return true;
            }
        }
    }
    bool parse_ubjson_internal()
    {
        string_t key;
        char_int_type prefix = get_ignore_noop();
        while (true)
        {
            const std::size_t depth = container_stack.size();
            if (JSON_HEDLEY_UNLIKELY(!get_ubjson_value(prefix)))
            {
                return false;
            }
            if (container_stack.empty())
            {
                return true;
            }
            if (container_stack.size() == depth && container_stack.back().remaining == npos)
            {
                get_ignore_noop();
            }
            for (;;)
            {
                const container_frame top = container_stack.back();
                if (top.remaining != npos)
                {
                    if (top.remaining != 0)
                    {
                        --container_stack.back().remaining;
                        if (top.is_object)
                        {
                            key.clear();
                            if (JSON_HEDLEY_UNLIKELY(!get_ubjson_string(key) || !sax->key(key)))
                            {
                                return false;
                            }
                        }
                        prefix = (top.type_marker != 0) ? top.type_marker : get_ignore_noop();
                        break;
                    }
                }
                else if (top.is_object ? (current != '}') : (current != ']'))
                {
                    if (top.is_object)
                    {
                        key.clear();
                        if (JSON_HEDLEY_UNLIKELY(!get_ubjson_string(key, false) || !sax->key(key)))
                        {
                            return false;
                        }
                        prefix = get_ignore_noop();
                    }
                    else
                    {
                        prefix = current;
                    }
                    break;
                }
                if (JSON_HEDLEY_UNLIKELY(!leave_container()))
                {
                    return false;
                }
                if (container_stack.empty())
                {
                    return true;
                }
                if (container_stack.back().remaining == npos)
                {
                    get_ignore_noop();
                }
            }
        }
    }
    template<typename NumberType>
    bool check_ubjson_string_length(const NumberType len)
    {
        if (JSON_HEDLEY_UNLIKELY(len < 0))
        {
            return sax->parse_error(chars_read, get_token_string(), parse_error::create(113, chars_read,
                                    exception_message(input_format, "string length must not be negative", "string"), nullptr));
        }
        return true;
    }
    bool get_ubjson_string(string_t& result, const bool get_char = true)
    {
        if (get_char)
        {
            get();
        }
        if (JSON_HEDLEY_UNLIKELY(!unexpect_eof(input_format, "value")))
        {
            return false;
        }
        switch (current)
        {
            case 'U':
            {
                std::uint8_t len{};
                return get_number(input_format, len) && get_string(input_format, len, result);
            }
            case 'i':
            {
                std::int8_t len{};
                return get_number(input_format, len) && check_ubjson_string_length(len) && get_string(input_format, len, result);
            }
            case 'I':
            {
                std::int16_t len{};
                return get_number(input_format, len) && check_ubjson_string_length(len) && get_string(input_format, len, result);
            }
            case 'l':
            {
                std::int32_t len{};
                return get_number(input_format, len) && check_ubjson_string_length(len) && get_string(input_format, len, result);
            }
            case 'L':
            {
                std::int64_t len{};
                return get_number(input_format, len) && check_ubjson_string_length(len) && get_string(input_format, len, result);
            }
            case 'u':
            {
                if (input_format != input_format_t::bjdata)
                {
                    break;
                }
                std::uint16_t len{};
                return get_number(input_format, len) && get_string(input_format, len, result);
            }
            case 'm':
            {
                if (input_format != input_format_t::bjdata)
                {
                    break;
                }
                std::uint32_t len{};
                return get_number(input_format, len) && get_string(input_format, len, result);
            }
            case 'M':
            {
                if (input_format != input_format_t::bjdata)
                {
                    break;
                }
                std::uint64_t len{};
                return get_number(input_format, len) && get_string(input_format, len, result);
            }
            default:
                break;
        }
        auto last_token = get_token_string();
        std::string message;
        if (input_format != input_format_t::bjdata)
        {
            message = "expected length type specification (U, i, I, l, L); last byte: 0x" + last_token;
        }
        else
        {
            message = "expected length type specification (U, i, u, I, m, l, M, L); last byte: 0x" + last_token;
        }
        return sax->parse_error(chars_read, last_token, parse_error::create(113, chars_read, exception_message(input_format, message, "string"), nullptr));
    }
    bool get_ubjson_ndarray_size(std::vector<size_t>& dim)
    {
        std::pair<std::size_t, char_int_type> size_and_type;
        size_t dimlen = 0;
        bool no_ndarray = true;
        if (JSON_HEDLEY_UNLIKELY(!get_ubjson_size_type(size_and_type, no_ndarray)))
        {
            return false;
        }
        if (size_and_type.first != npos)
        {
            if (size_and_type.second != 0)
            {
                if (size_and_type.second != 'N')
                {
                    for (std::size_t i = 0; i < size_and_type.first; ++i)
                    {
                        if (JSON_HEDLEY_UNLIKELY(!get_ubjson_size_value(dimlen, no_ndarray, size_and_type.second)))
                        {
                            return false;
                        }
                        dim.push_back(dimlen);
                    }
                }
            }
            else
            {
                for (std::size_t i = 0; i < size_and_type.first; ++i)
                {
                    if (JSON_HEDLEY_UNLIKELY(!get_ubjson_size_value(dimlen, no_ndarray)))
                    {
                        return false;
                    }
                    dim.push_back(dimlen);
                }
            }
        }
        else
        {
            while (current != ']')
            {
                if (JSON_HEDLEY_UNLIKELY(!get_ubjson_size_value(dimlen, no_ndarray, current)))
                {
                    return false;
                }
                dim.push_back(dimlen);
                get_ignore_noop();
            }
        }
        return true;
    }
    template<typename SignedType>
    bool get_ubjson_signed_count(std::size_t& result)
    {
        SignedType number{};
        if (JSON_HEDLEY_UNLIKELY(!get_number(input_format, number)))
        {
            return false;
        }
        if (JSON_HEDLEY_UNLIKELY(number < 0))
        {
            return sax->parse_error(chars_read, get_token_string(), parse_error::create(113, chars_read,
                                    exception_message(input_format, "count in an optimized container must be positive", "size"), nullptr));
        }
        if (JSON_HEDLEY_UNLIKELY(!value_in_range_of<std::size_t>(number)))
        {
            return sax->parse_error(chars_read, get_token_string(), out_of_range::create(408,
                                    exception_message(input_format, "integer value overflow", "size"), nullptr));
        }
        result = static_cast<std::size_t>(number); 
        return true;
    }
    bool get_ubjson_size_value(std::size_t& result, bool& is_ndarray, char_int_type prefix = 0)
    {
        if (prefix == 0)
        {
            prefix = get_ignore_noop();
        }
        switch (prefix)
        {
            case 'U':
            {
                std::uint8_t number{};
                if (JSON_HEDLEY_UNLIKELY(!get_number(input_format, number)))
                {
                    return false;
                }
                result = static_cast<std::size_t>(number);
                return true;
            }
            case 'i':
                return get_ubjson_signed_count<std::int8_t>(result);
            case 'I':
                return get_ubjson_signed_count<std::int16_t>(result);
            case 'l':
                return get_ubjson_signed_count<std::int32_t>(result);
            case 'L':
                return get_ubjson_signed_count<std::int64_t>(result);
            case 'u':
            {
                if (input_format != input_format_t::bjdata)
                {
                    break;
                }
                std::uint16_t number{};
                if (JSON_HEDLEY_UNLIKELY(!get_number(input_format, number)))
                {
                    return false;
                }
                result = static_cast<std::size_t>(number);
                return true;
            }
            case 'm':
            {
                if (input_format != input_format_t::bjdata)
                {
                    break;
                }
                std::uint32_t number{};
                if (JSON_HEDLEY_UNLIKELY(!get_number(input_format, number)))
                {
                    return false;
                }
                result = conditional_static_cast<std::size_t>(number);
                return true;
            }
            case 'M':
            {
                if (input_format != input_format_t::bjdata)
                {
                    break;
                }
                std::uint64_t number{};
                if (JSON_HEDLEY_UNLIKELY(!get_number(input_format, number)))
                {
                    return false;
                }
                if (!value_in_range_of<std::size_t>(number))
                {
                    return sax->parse_error(chars_read, get_token_string(), out_of_range::create(408,
                                            exception_message(input_format, "integer value overflow", "size"), nullptr));
                }
                result = detail::conditional_static_cast<std::size_t>(number);
                return true;
            }
            case '[':
            {
                if (input_format != input_format_t::bjdata)
                {
                    break;
                }
                if (is_ndarray) 
                {
                    return sax->parse_error(chars_read, get_token_string(), parse_error::create(113, chars_read, exception_message(input_format, "ndarray dimensional vector is not allowed", "size"), nullptr));
                }
                std::vector<size_t> dim;
                if (JSON_HEDLEY_UNLIKELY(!get_ubjson_ndarray_size(dim)))
                {
                    return false;
                }
                if (dim.size() == 1 || (dim.size() == 2 && dim.at(0) == 1)) 
                {
                    result = dim.at(dim.size() - 1);
                    return true;
                }
                if (!dim.empty())  
                {
                    for (auto i : dim) 
                    {
                        if ( i == 0 )
                        {
                            result = 0;
                            return true;
                        }
                    }
                    string_t key = "_ArraySize_";
                    if (JSON_HEDLEY_UNLIKELY(!sax->start_object(3) || !sax->key(key) || !sax->start_array(dim.size())))
                    {
                        return false;
                    }
                    result = 1;
                    for (auto i : dim)
                    {
                        if (JSON_HEDLEY_UNLIKELY(result > (std::numeric_limits<std::size_t>::max)() / i))
                        {
                            return sax->parse_error(chars_read, get_token_string(), out_of_range::create(408, exception_message(input_format, "excessive ndarray size caused overflow", "size"), nullptr));
                        }
                        result *= i;
                        if (result == npos)
                        {
                            return sax->parse_error(chars_read, get_token_string(), out_of_range::create(408, exception_message(input_format, "excessive ndarray size caused overflow", "size"), nullptr));
                        }
                        if (JSON_HEDLEY_UNLIKELY(!sax->number_unsigned(static_cast<number_unsigned_t>(i))))
                        {
                            return false;
                        }
                    }
                    is_ndarray = true;
                    return sax->end_array();
                }
                result = 0;
                return true;
            }
            default:
                break;
        }
        auto last_token = get_token_string();
        std::string message;
        if (input_format != input_format_t::bjdata)
        {
            message = "expected length type specification (U, i, I, l, L) after '#'; last byte: 0x" + last_token;
        }
        else
        {
            message = "expected length type specification (U, i, u, I, m, l, M, L) after '#'; last byte: 0x" + last_token;
        }
        return sax->parse_error(chars_read, last_token, parse_error::create(113, chars_read, exception_message(input_format, message, "size"), nullptr));
    }
    bool get_ubjson_size_type(std::pair<std::size_t, char_int_type>& result, bool inside_ndarray = false)
    {
        result.first = npos; 
        result.second = 0; 
        bool is_ndarray = inside_ndarray;
        get_ignore_noop();
        if (current == '$')
        {
            result.second = get();  
            if (input_format == input_format_t::bjdata
                    && JSON_HEDLEY_UNLIKELY(is_bjd_excluded_optimized_type(result.second)))
            {
                auto last_token = get_token_string();
                return sax->parse_error(chars_read, last_token, parse_error::create(112, chars_read,
                                        exception_message(input_format, concat("marker 0x", last_token, " is not a permitted optimized array type"), "type"), nullptr));
            }
            if (JSON_HEDLEY_UNLIKELY(!unexpect_eof(input_format, "type")))
            {
                return false;
            }
            get_ignore_noop();
            if (JSON_HEDLEY_UNLIKELY(current != '#'))
            {
                if (JSON_HEDLEY_UNLIKELY(!unexpect_eof(input_format, "value")))
                {
                    return false;
                }
                auto last_token = get_token_string();
                return sax->parse_error(chars_read, last_token, parse_error::create(112, chars_read,
                                        exception_message(input_format, concat("expected '#' after type information; last byte: 0x", last_token), "size"), nullptr));
            }
            const bool is_error = get_ubjson_size_value(result.first, is_ndarray);
            if (input_format == input_format_t::bjdata && is_ndarray && !inside_ndarray)
            {
                result.second |= (1 << 8); 
            }
            return is_error;
        }
        if (current == '#')
        {
            const bool is_error = get_ubjson_size_value(result.first, is_ndarray);
            if (input_format == input_format_t::bjdata && is_ndarray && !inside_ndarray)
            {
                return sax->parse_error(chars_read, get_token_string(), parse_error::create(112, chars_read,
                                        exception_message(input_format, "ndarray requires both type and size", "size"), nullptr));
            }
            return is_error;
        }
        return true;
    }
    bool get_ubjson_value(const char_int_type prefix)
    {
        switch (prefix)
        {
            case char_traits<char_type>::eof():  
                return unexpect_eof(input_format, "value");
            case 'T':  
                return sax->boolean(true);
            case 'F':  
                return sax->boolean(false);
            case 'Z':  
                return sax->null();
            case 'B':  
            {
                if (input_format != input_format_t::bjdata)
                {
                    break;
                }
                std::uint8_t number{};
                return get_number(input_format, number) && sax->number_unsigned(number);
            }
            case 'U':
            {
                std::uint8_t number{};
                return get_number(input_format, number) && sax->number_unsigned(number);
            }
            case 'i':
            {
                std::int8_t number{};
                return get_number(input_format, number) && sax->number_integer(conditional_static_cast<number_integer_t>(number));
            }
            case 'I':
            {
                std::int16_t number{};
                return get_number(input_format, number) && sax->number_integer(conditional_static_cast<number_integer_t>(number));
            }
            case 'l':
            {
                std::int32_t number{};
                return get_number(input_format, number) && sax->number_integer(conditional_static_cast<number_integer_t>(number));
            }
            case 'L':
            {
                std::int64_t number{};
                return get_number(input_format, number) && sax->number_integer(conditional_static_cast<number_integer_t>(number));
            }
            case 'u':
            {
                if (input_format != input_format_t::bjdata)
                {
                    break;
                }
                std::uint16_t number{};
                return get_number(input_format, number) && sax->number_unsigned(number);
            }
            case 'm':
            {
                if (input_format != input_format_t::bjdata)
                {
                    break;
                }
                std::uint32_t number{};
                return get_number(input_format, number) && sax->number_unsigned(number);
            }
            case 'M':
            {
                if (input_format != input_format_t::bjdata)
                {
                    break;
                }
                std::uint64_t number{};
                return get_number(input_format, number) && sax->number_unsigned(number);
            }
            case 'h':
            {
                if (input_format != input_format_t::bjdata)
                {
                    break;
                }
                return get_half_float(input_format, true);
            }
            case 'd':
            {
                float number{};
                return get_number(input_format, number) && sax->number_float(static_cast<number_float_t>(number), "");
            }
            case 'D':
            {
                double number{};
                return get_number(input_format, number) && sax->number_float(static_cast<number_float_t>(number), "");
            }
            case 'H':
            {
                return get_ubjson_high_precision_number();
            }
            case 'C':  
            {
                get();
                if (JSON_HEDLEY_UNLIKELY(!unexpect_eof(input_format, "char")))
                {
                    return false;
                }
                if (JSON_HEDLEY_UNLIKELY(current > 127))
                {
                    auto last_token = get_token_string();
                    return sax->parse_error(chars_read, last_token, parse_error::create(113, chars_read,
                                            exception_message(input_format, concat("byte after 'C' must be in range 0x00..0x7F; last byte: 0x", last_token), "char"), nullptr));
                }
                string_t s(1, static_cast<typename string_t::value_type>(current));
                return sax->string(s);
            }
            case 'S':  
            {
                string_t s;
                return get_ubjson_string(s) && sax->string(s);
            }
            case '[':  
                return get_ubjson_array();
            case '{':  
                return get_ubjson_object();
            default: 
                break;
        }
        auto last_token = get_token_string();
        return sax->parse_error(chars_read, last_token, parse_error::create(112, chars_read, exception_message(input_format, "invalid byte: 0x" + last_token, "value"), nullptr));
    }
    bool get_ubjson_array()
    {
        std::pair<std::size_t, char_int_type> size_and_type;
        if (JSON_HEDLEY_UNLIKELY(!get_ubjson_size_type(size_and_type)))
        {
            return false;
        }
        if (input_format == input_format_t::bjdata && size_and_type.first != npos && (size_and_type.second & (1 << 8)) != 0)
        {
            size_and_type.second &= ~(static_cast<char_int_type>(1) << 8);  
            const char* type_name = bjd_type_name(size_and_type.second);
            string_t key = "_ArrayType_";
            if (JSON_HEDLEY_UNLIKELY(type_name == nullptr))
            {
                auto last_token = get_token_string();
                return sax->parse_error(chars_read, last_token, parse_error::create(112, chars_read,
                                        exception_message(input_format, "invalid byte: 0x" + last_token, "type"), nullptr));
            }
            string_t type = type_name; 
            if (JSON_HEDLEY_UNLIKELY(!sax->key(key) || !sax->string(type)))
            {
                return false;
            }
            if (size_and_type.second == 'C' || size_and_type.second == 'B')
            {
                size_and_type.second = 'U';
            }
            key = "_ArrayData_";
            if (JSON_HEDLEY_UNLIKELY(!sax->key(key) || !sax->start_array(size_and_type.first) ))
            {
                return false;
            }
            for (std::size_t i = 0; i < size_and_type.first; ++i)
            {
                if (JSON_HEDLEY_UNLIKELY(!get_ubjson_value(size_and_type.second)))
                {
                    return false;
                }
            }
            return (sax->end_array() && sax->end_object());
        }
        if (input_format == input_format_t::bjdata && size_and_type.first != npos && size_and_type.second == 'B')
        {
            binary_t result;
            return get_binary(input_format, size_and_type.first, result) && sax->binary(result);
        }
        if (size_and_type.first != npos)
        {
            if (JSON_HEDLEY_UNLIKELY((size_and_type.second == 'Z' || size_and_type.second == 'T' || size_and_type.second == 'F')
                                     && size_and_type.first > max_valueless_container_size))
            {
                return sax->parse_error(chars_read, get_token_string(), out_of_range::create(408,
                                        exception_message(input_format, "excessive array size", "size"), nullptr));
            }
            if (JSON_HEDLEY_UNLIKELY(!enter_array(size_and_type.first, size_and_type.second)))
            {
                return false;
            }
            if (size_and_type.second == 'N')
            {
                container_stack.back().remaining = 0;
            }
            return true;
        }
        return enter_array(detail::unknown_size());
    }
    bool get_ubjson_object()
    {
        std::pair<std::size_t, char_int_type> size_and_type;
        if (JSON_HEDLEY_UNLIKELY(!get_ubjson_size_type(size_and_type)))
        {
            return false;
        }
        if (input_format == input_format_t::bjdata && size_and_type.first != npos && (size_and_type.second & (1 << 8)) != 0)
        {
            auto last_token = get_token_string();
            return sax->parse_error(chars_read, last_token, parse_error::create(112, chars_read,
                                    exception_message(input_format, "BJData object does not support ND-array size in optimized format", "object"), nullptr));
        }
        if (size_and_type.first != npos)
        {
            return enter_object(size_and_type.first, size_and_type.second);
        }
        return enter_object(detail::unknown_size());
    }
    bool get_ubjson_high_precision_number()
    {
        std::size_t size{};
        bool no_ndarray = true;
        auto res = get_ubjson_size_value(size, no_ndarray);
        if (JSON_HEDLEY_UNLIKELY(!res))
        {
            return res;
        }
        std::vector<char> number_vector;
        for (std::size_t i = 0; i < size; ++i)
        {
            get();
            if (JSON_HEDLEY_UNLIKELY(!unexpect_eof(input_format, "number")))
            {
                return false;
            }
            number_vector.push_back(static_cast<char>(current));
        }
        using ia_type = decltype(detail::input_adapter(number_vector));
        auto number_lexer = detail::lexer<BasicJsonType, ia_type>(detail::input_adapter(number_vector), false);
        const auto result_number = number_lexer.scan();
        const auto number_string = number_lexer.get_token_string();
        const auto result_remainder = number_lexer.scan();
        using token_type = typename detail::lexer_base<BasicJsonType>::token_type;
        if (JSON_HEDLEY_UNLIKELY(result_remainder != token_type::end_of_input))
        {
            return sax->parse_error(chars_read, number_string, parse_error::create(115, chars_read,
                                    exception_message(input_format, concat("invalid number text: ", number_lexer.get_token_string()), "high-precision number"), nullptr));
        }
        switch (result_number)
        {
            case token_type::value_integer:
                return sax->number_integer(number_lexer.get_number_integer());
            case token_type::value_unsigned:
                return sax->number_unsigned(number_lexer.get_number_unsigned());
            case token_type::value_float:
            {
                const auto parsed_float = number_lexer.get_number_float();
                if (JSON_HEDLEY_UNLIKELY(!std::isfinite(parsed_float)))
                {
                    return sax->parse_error(
                               chars_read,
                               number_string,
                               out_of_range::create(406, concat("number overflow parsing '", number_string, '\''), nullptr));
                }
                return sax->number_float(parsed_float, string_t(number_string.data(), number_string.size()));
            }
            case token_type::uninitialized:
            case token_type::literal_true:
            case token_type::literal_false:
            case token_type::literal_null:
            case token_type::value_string:
            case token_type::begin_array:
            case token_type::begin_object:
            case token_type::end_array:
            case token_type::end_object:
            case token_type::name_separator:
            case token_type::value_separator:
            case token_type::parse_error:
            case token_type::end_of_input:
            case token_type::literal_or_value:
            default:
                return sax->parse_error(chars_read, number_string, parse_error::create(115, chars_read,
                                        exception_message(input_format, concat("invalid number text: ", number_lexer.get_token_string()), "high-precision number"), nullptr));
        }
    }
    char_int_type get_bon8()
    {
        if (bon8_pushback_size != 0)
        {
            ++chars_read;
            return current = bon8_pushback[--bon8_pushback_size];
        }
        return get();
    }
    void unget_bon8(const char_int_type c)
    {
        JSON_ASSERT(bon8_pushback_size < bon8_pushback.size());
        bon8_pushback[bon8_pushback_size++] = c;
        --chars_read;
    }
    static constexpr bool is_bon8_continuation(const char_int_type c) noexcept
    {
        return 0x80 <= c && c <= 0xBF;
    }
    bool bon8_error(const std::string& detail, const char* context)
    {
        auto last_token = get_token_string();
        return sax->parse_error(chars_read, last_token, parse_error::create(112, chars_read,
                                exception_message(input_format_t::bon8, concat(detail, ": 0x", last_token), context), nullptr));
    }
    bool parse_bon8_internal()
    {
        string_t key;
        while (true)
        {
            if (!container_stack.empty())
            {
                const container_frame top = container_stack.back();
                bool at_end = false;
                if (top.remaining != npos)
                {
                    at_end = (top.remaining == 0);
                    if (!at_end)
                    {
                        --container_stack.back().remaining;
                    }
                }
                else
                {
                    at_end = (get_bon8() == 0xFE);
                    if (!at_end)
                    {
                        unget_bon8(current);
                    }
                }
                if (at_end)
                {
                    if (JSON_HEDLEY_UNLIKELY(!leave_container()))
                    {
                        return false;
                    }
                    if (container_stack.empty())
                    {
                        return true;
                    }
                    continue;
                }
                if (top.is_object)
                {
                    key.clear();
                    if (JSON_HEDLEY_UNLIKELY(!get_bon8_key(key) || !sax->key(key)))
                    {
                        return false;
                    }
                }
            }
            if (JSON_HEDLEY_UNLIKELY(!parse_bon8_value()))
            {
                return false;
            }
            if (container_stack.empty())
            {
                return true;
            }
        }
    }
    bool parse_bon8_value()
    {
        const auto byte = get_bon8();
        if (byte == char_traits<char_type>::eof())
        {
            return unexpect_eof(input_format_t::bon8, "value");
        }
        if (byte <= 0x7F)
        {
            string_t s;
            unget_bon8(byte);
            return get_bon8_string(s) && sax->string(s);
        }
        if (byte <= 0x84)
        {
            return enter_array(static_cast<std::size_t>(byte - 0x80));
        }
        if (byte == 0x85)
        {
            return enter_array(npos);
        }
        if (byte <= 0x8A)
        {
            return enter_object(static_cast<std::size_t>(byte - 0x86));
        }
        switch (byte)
        {
            case 0x8B: 
                return enter_object(npos);
            case 0x8C: 
            {
                std::int32_t number{};
                return get_number(input_format_t::bon8, number) && emit_bon8_integer(number);
            }
            case 0x8D: 
            {
                std::int64_t number{};
                return get_number(input_format_t::bon8, number) && emit_bon8_integer(number);
            }
            case 0x8E: 
            {
                float number{};
                return get_number(input_format_t::bon8, number) && sax->number_float(static_cast<number_float_t>(number), "");
            }
            case 0x8F: 
            {
                double number{};
                return get_number(input_format_t::bon8, number) && sax->number_float(static_cast<number_float_t>(number), "");
            }
            case 0xF8:
                return sax->boolean(false);
            case 0xF9:
                return sax->boolean(true);
            case 0xFA:
                return sax->null();
            case 0xFB:
                return sax->number_float(static_cast<number_float_t>(-1.0), "");
            case 0xFC:
                return sax->number_float(static_cast<number_float_t>(0.0), "");
            case 0xFD:
                return sax->number_float(static_cast<number_float_t>(1.0), "");
            case 0xFF: 
            {
                string_t s;
                return sax->string(s);
            }
            default:
                break;
        }
        if (byte <= 0xB7)
        {
            return sax->number_unsigned(static_cast<number_unsigned_t>(byte - 0x90));
        }
        if (byte <= 0xC1)
        {
            return sax->number_integer(conditional_static_cast<number_integer_t>(-1 - static_cast<number_integer_t>(byte - 0xB8)));
        }
        if (byte <= 0xF7)
        {
            const auto second = get_bon8();
            if (is_bon8_continuation(second))
            {
                string_t s;
                unget_bon8(second);
                unget_bon8(byte);
                return get_bon8_string(s) && sax->string(s);
            }
            return get_bon8_integer(byte, second);
        }
        return bon8_error("invalid byte", "value");
    }
    bool emit_bon8_integer(const std::int64_t number)
    {
        if (number >= 0)
        {
            return sax->number_unsigned(static_cast<number_unsigned_t>(number));
        }
        return sax->number_integer(static_cast<number_integer_t>(number));
    }
    bool get_bon8_integer(const char_int_type lead, const char_int_type second)
    {
        if (JSON_HEDLEY_UNLIKELY(!unexpect_eof(input_format_t::bon8, "number")))
        {
            return false;
        }
        const bool negative = second >= 0xC0;
        auto value = static_cast<std::int64_t>(negative ? (second & 0x3F) : second);
        std::int64_t offset = 0;
        int extra_bytes = 0;
        if (lead <= 0xDF)
        {
            value |= static_cast<std::int64_t>(lead - 0xC2) << (negative ? 6 : 7);
            offset = negative ? 11 : 40;
        }
        else if (lead <= 0xEF)
        {
            value |= static_cast<std::int64_t>(lead & 0x0F) << (negative ? 6 : 7);
            offset = negative ? 1931 : 3880;
            extra_bytes = 1;
        }
        else
        {
            value |= static_cast<std::int64_t>(lead & 0x07) << (negative ? 6 : 7);
            offset = negative ? 264075 : 528168;
            extra_bytes = 2;
        }
        for (int i = 0; i < extra_bytes; ++i)
        {
            if (JSON_HEDLEY_UNLIKELY(get_bon8() == char_traits<char_type>::eof()))
            {
                return unexpect_eof(input_format_t::bon8, "number");
            }
            value = (value << 8) | static_cast<std::int64_t>(current);
        }
        return negative ? sax->number_integer(static_cast<number_integer_t>(-(value + offset)))
               : sax->number_unsigned(static_cast<number_unsigned_t>(value + offset));
    }
    bool get_bon8_key(string_t& result)
    {
        const auto byte = get_bon8();
        if (byte == char_traits<char_type>::eof())
        {
            return unexpect_eof(input_format_t::bon8, "key");
        }
        if (byte == 0xFF)
        {
            return true;
        }
        if (byte <= 0x7F)
        {
            unget_bon8(byte);
            return get_bon8_string(result);
        }
        if (0xC2 <= byte && byte <= 0xF7)
        {
            const auto second = get_bon8();
            if (second == char_traits<char_type>::eof())
            {
                return unexpect_eof(input_format_t::bon8, "key");
            }
            unget_bon8(second);
            if (is_bon8_continuation(second))
            {
                unget_bon8(byte);
                return get_bon8_string(result);
            }
            current = byte;
        }
        return bon8_error("expected a string; last byte", "key");
    }
    void get_bon8_string_bulk(string_t& result, std::true_type )
    {
        if (bon8_pushback_size != 0)
        {
            return;
        }
        const std::size_t remaining = ia.bulk_remaining();
        if (remaining == 0)
        {
            return;
        }
        const auto* const data = reinterpret_cast<const unsigned char*>(ia.bulk_data());
        const std::size_t length = valid_utf8_prefix(data, remaining);
        if (length != 0)
        {
            result.append(reinterpret_cast<const typename string_t::value_type*>(data), length);
            ia.bulk_skip(length);
            chars_read += length;
        }
    }
    void get_bon8_string_bulk(string_t& , std::false_type ) const noexcept {}
    bool get_bon8_string(string_t& result)
    {
        while (true)
        {
            get_bon8_string_bulk(result, std::integral_constant<bool, bulk_scan> {});
            const auto byte = get_bon8();
            if (byte == char_traits<char_type>::eof())
            {
                return unexpect_eof(input_format_t::bon8, "string");
            }
            if (byte == 0xFF)
            {
                return true;
            }
            if (byte <= 0x7F)
            {
                result.push_back(static_cast<typename string_t::value_type>(byte));
                continue;
            }
            if (byte < 0xC2 || byte > 0xF7)
            {
                unget_bon8(byte);
                return true;
            }
            const auto second = get_bon8();
            if (second == char_traits<char_type>::eof())
            {
                return unexpect_eof(input_format_t::bon8, "string");
            }
            if (!is_bon8_continuation(second))
            {
                unget_bon8(second);
                unget_bon8(byte);
                return true;
            }
            int continuation_bytes = 0;
            bool valid_second = true;
            if (byte <= 0xDF)
            {
                continuation_bytes = 1;
            }
            else if (byte <= 0xEF)
            {
                continuation_bytes = 2;
                valid_second = (byte != 0xE0 || second >= 0xA0) && (byte != 0xED || second <= 0x9F);
            }
            else
            {
                continuation_bytes = 3;
                valid_second = byte <= 0xF4 && (byte != 0xF0 || second >= 0x90) && (byte != 0xF4 || second <= 0x8F);
            }
            if (JSON_HEDLEY_UNLIKELY(!valid_second))
            {
                return bon8_error("invalid UTF-8 byte", "string");
            }
            result.push_back(static_cast<typename string_t::value_type>(byte));
            result.push_back(static_cast<typename string_t::value_type>(second));
            for (int i = 1; i < continuation_bytes; ++i)
            {
                if (JSON_HEDLEY_UNLIKELY(get_bon8() == char_traits<char_type>::eof()))
                {
                    return unexpect_eof(input_format_t::bon8, "string");
                }
                if (JSON_HEDLEY_UNLIKELY(!is_bon8_continuation(current)))
                {
                    return bon8_error("invalid UTF-8 byte", "string");
                }
                result.push_back(static_cast<typename string_t::value_type>(current));
            }
        }
    }
    char_int_type get()
    {
        ++chars_read;
        return current = ia.get_character();
    }
    template<class T>
    bool get_to(T& dest, const input_format_t format, const char* context)
    {
        auto new_chars_read = ia.get_elements(&dest);
        chars_read += new_chars_read;
        if (JSON_HEDLEY_UNLIKELY(new_chars_read < sizeof(T)))
        {
            ++chars_read;
            sax->parse_error(chars_read, "<end of file>", parse_error::create(110, chars_read, exception_message(format, "unexpected end of input", context), nullptr));
            return false;
        }
        return true;
    }
    char_int_type get_ignore_noop()
    {
        do
        {
            get();
        }
        while (current == 'N');
        return current;
    }
    template<class NumberType>
    static void byte_swap(NumberType& number)
    {
        constexpr std::size_t sz = sizeof(number);
#ifdef __cpp_lib_byteswap
        if constexpr (sz == 1)
        {
            return;
        }
        else if constexpr(std::is_integral_v<NumberType>)
        {
            number = std::byteswap(number);
            return;
        }
        else
        {
#endif
            auto* ptr = reinterpret_cast<std::uint8_t*>(&number);
            for (std::size_t i = 0; i < sz / 2; ++i)
            {
                std::swap(ptr[i], ptr[sz - i - 1]);
            }
#ifdef __cpp_lib_byteswap
        }
#endif
    }
    template<typename NumberType, bool InputIsLittleEndian = false>
    bool get_number(const input_format_t format, NumberType& result)
    {
        if (JSON_HEDLEY_UNLIKELY(!get_to(result, format, "number")))
        {
            return false;
        }
        if (is_little_endian != (InputIsLittleEndian || format == input_format_t::bjdata))
        {
            byte_swap(result);
        }
        return true;
    }
    bool get_half_float(const input_format_t format, const bool little_endian)
    {
        const auto byte1_raw = get();
        if (JSON_HEDLEY_UNLIKELY(!unexpect_eof(format, "number")))
        {
            return false;
        }
        const auto byte2_raw = get();
        if (JSON_HEDLEY_UNLIKELY(!unexpect_eof(format, "number")))
        {
            return false;
        }
        const auto byte1 = static_cast<unsigned char>(byte1_raw);
        const auto byte2 = static_cast<unsigned char>(byte2_raw);
        const auto half = little_endian
                          ? static_cast<unsigned int>((byte2 << 8u) + byte1)
                          : static_cast<unsigned int>((byte1 << 8u) + byte2);
        const double val = [&half]
        {
            const int exp = (half >> 10u) & 0x1Fu;
            const unsigned int mant = half & 0x3FFu;
            JSON_ASSERT(exp <= 31);
            JSON_ASSERT(mant <= 1023);
            switch (exp)
            {
                case 0:
                    return std::ldexp(mant, -24);
                case 31:
                    return (mant == 0)
                    ? std::numeric_limits<double>::infinity()
                    : std::numeric_limits<double>::quiet_NaN();
                default:
                    return std::ldexp(mant + 1024, exp - 25);
            }
        }();
        return sax->number_float((half & 0x8000u) != 0
                                 ? static_cast<number_float_t>(-val)
                                 : static_cast<number_float_t>(val), "");
    }
    template<typename NumberType>
    bool get_string(const input_format_t format,
                    const NumberType len,
                    string_t& result)
    {
        const std::size_t old_size = result.size();
        if (JSON_HEDLEY_UNLIKELY(!get_bytes(format, len, "string", result)))
        {
            return false;
        }
        if (JSON_HEDLEY_UNLIKELY(!is_valid_utf8(result, old_size)))
        {
            return sax->parse_error(chars_read, get_token_string(),
                                    parse_error::create(113, chars_read,
                                            exception_message(format, "invalid string: ill-formed UTF-8 byte", "string"), nullptr));
        }
        return true;
    }
    template<typename NumberType>
    bool get_binary(const input_format_t format,
                    const NumberType len,
                    binary_t& result)
    {
        return get_bytes(format, len, "binary", result);
    }
    template<typename NumberType, typename ContainerType>
    bool get_bytes(const input_format_t format,
                   NumberType len,
                   const char* context,
                   ContainerType& result)
    {
        constexpr std::size_t chunk_size = 4096;
        while (len > 0)
        {
            const std::size_t wanted = (static_cast<std::uintmax_t>(len) < static_cast<std::uintmax_t>(chunk_size))
                                       ? static_cast<std::size_t>(len)
                                       : chunk_size;
            const std::size_t old_size = result.size();
            result.resize(old_size + wanted);
            JSON_ASSERT(result.size() == old_size + wanted);
            const std::size_t bytes_read = ia.get_elements(&result[old_size], wanted);
            chars_read += bytes_read;
            if (JSON_HEDLEY_UNLIKELY(bytes_read < wanted))
            {
                result.resize(old_size + bytes_read);
                ++chars_read;
                current = char_traits<char_type>::eof();
                return unexpect_eof(format, context);
            }
            JSON_ASSERT(bytes_read == wanted);
            len = static_cast<NumberType>(len - static_cast<NumberType>(wanted));
        }
        return true;
    }
    JSON_HEDLEY_NON_NULL(3)
    bool unexpect_eof(const input_format_t format, const char* context) const
    {
        if (JSON_HEDLEY_UNLIKELY(current == char_traits<char_type>::eof()))
        {
            return sax->parse_error(chars_read, "<end of file>",
                                    parse_error::create(110, chars_read, exception_message(format, "unexpected end of input", context), nullptr));
        }
        return true;
    }
    std::string get_token_string() const
    {
        std::array<char, 3> cr{{}};
        static_cast<void>((std::snprintf)(cr.data(), cr.size(), "%.2hhX", static_cast<unsigned char>(current))); 
        return std::string{cr.data()};
    }
    std::string exception_message(const input_format_t format,
                                  const std::string& detail,
                                  const std::string& context) const
    {
        std::string error_msg = "syntax error while parsing ";
        switch (format)
        {
            case input_format_t::cbor:
                error_msg += "CBOR";
                break;
            case input_format_t::msgpack:
                error_msg += "MessagePack";
                break;
            case input_format_t::ubjson:
                error_msg += "UBJSON";
                break;
            case input_format_t::bson:
                error_msg += "BSON";
                break;
            case input_format_t::bjdata:
                error_msg += "BJData";
                break;
            case input_format_t::bon8:
                error_msg += "BON8";
                break;
            case input_format_t::json: 
            default:            
                JSON_ASSERT(false); 
        }
        return concat(error_msg, ' ', context, ": ", detail);
    }
  private:
    static JSON_INLINE_VARIABLE constexpr std::size_t npos = detail::unknown_size();
    InputAdapterType ia;
    char_int_type current = char_traits<char_type>::eof();
    std::size_t chars_read = 0;
    const bool is_little_endian = little_endianness();
    const input_format_t input_format = input_format_t::json;
    json_sax_t* sax = nullptr;
    std::vector<container_frame> container_stack{};
    std::array<char_int_type, 2> bon8_pushback{{}};
    std::size_t bon8_pushback_size = 0;
  JSON_PRIVATE_UNLESS_TESTED:
    static constexpr bool is_bjd_excluded_optimized_type(const char_int_type marker) noexcept
    {
        return marker == '[' || marker == '{' || marker == 'S' || marker == 'H'
               || marker == 'T' || marker == 'F' || marker == 'N' || marker == 'Z';
    }
    static const char* bjd_type_name(const char_int_type marker)
    {
        switch (marker)
        {
            case 'B':
                return "byte";
            case 'C':
                return "char";
            case 'D':
                return "double";
            case 'I':
                return "int16";
            case 'L':
                return "int64";
            case 'M':
                return "uint64";
            case 'U':
                return "uint8";
            case 'd':
                return "single";
            case 'i':
                return "int8";
            case 'l':
                return "int32";
            case 'm':
                return "uint32";
            case 'u':
                return "uint16";
            default:
                return nullptr;
        }
    }
};
#ifndef JSON_HAS_CPP_17
    template<typename BasicJsonType, typename InputAdapterType, typename SAX>
    constexpr std::size_t binary_reader<BasicJsonType, InputAdapterType, SAX>::npos;
#endif
}  
NLOHMANN_JSON_NAMESPACE_END
#include <cmath> 
#include <cstdint> 
#include <functional> 
#include <string> 
#include <utility> 
#include <vector> 
NLOHMANN_JSON_NAMESPACE_BEGIN
namespace detail
{
enum class parse_event_t : std::uint8_t
{
    object_start,
    object_end,
    array_start,
    array_end,
    key,
    value
};
template<typename BasicJsonType>
using parser_callback_t =
    std::function<bool(int , parse_event_t , BasicJsonType& )>;
template<typename BasicJsonType, typename InputAdapterType>
class parser
{
    using number_integer_t = typename BasicJsonType::number_integer_t;
    using number_unsigned_t = typename BasicJsonType::number_unsigned_t;
    using number_float_t = typename BasicJsonType::number_float_t;
    using string_t = typename BasicJsonType::string_t;
    using lexer_t = lexer<BasicJsonType, InputAdapterType>;
    using token_type = typename lexer_t::token_type;
  public:
    explicit parser(InputAdapterType&& adapter,
                    parser_callback_t<BasicJsonType> cb = nullptr,
                    const bool allow_exceptions_ = true,
                    const bool ignore_comments = false,
                    const bool ignore_trailing_commas_ = false,
                    const bool discard_number_values_ = false)
        : callback(std::move(cb))
        , m_lexer(std::move(adapter), ignore_comments, discard_number_values_)
        , allow_exceptions(allow_exceptions_)
        , ignore_trailing_commas(ignore_trailing_commas_)
    {
        get_token();
    }
    void parse(const bool strict, BasicJsonType& result)
    {
        if (callback)
        {
            json_sax_dom_callback_parser<BasicJsonType, InputAdapterType> sdp(result, callback, allow_exceptions, &m_lexer);
            if (!parse_dom(sdp, strict))
            {
                result = value_t::discarded;
                return;
            }
            if (result.is_discarded())
            {
                result = nullptr;
            }
        }
        else
        {
            json_sax_dom_parser<BasicJsonType, InputAdapterType> sdp(result, allow_exceptions, &m_lexer);
            if (!parse_dom(sdp, strict))
            {
                result = value_t::discarded;
                return;
            }
        }
        result.assert_invariant();
    }
    bool accept(const bool strict = true)
    {
        json_sax_acceptor<BasicJsonType> sax_acceptor;
        return sax_parse(&sax_acceptor, strict);
    }
    template<typename SAX>
    JSON_HEDLEY_NON_NULL(2)
    bool sax_parse(SAX* sax, const bool strict = true)
    {
        (void)detail::is_sax_static_asserts<SAX, BasicJsonType> {};
        const bool result = sax_parse_internal(sax);
        if (result)
        {
            if (strict)
            {
                if (get_token() != token_type::end_of_input)
                {
                    return sax->parse_error(m_lexer.get_position(),
                                            m_lexer.get_token_string(),
                                            parse_error::create(101, m_lexer.get_position(), exception_message(token_type::end_of_input, "value"), nullptr));
                }
            }
            else
            {
                m_lexer.release_lookahead();
            }
        }
        return result;
    }
  private:
    template<typename DomSax>
    bool parse_dom(DomSax& sdp, const bool strict)
    {
        sax_parse_internal(&sdp);
        if (strict)
        {
            if (get_token() != token_type::end_of_input)
            {
                sdp.parse_error(m_lexer.get_position(),
                                m_lexer.get_token_string(),
                                parse_error::create(101, m_lexer.get_position(),
                                                    exception_message(token_type::end_of_input, "value"), nullptr));
            }
        }
        else
        {
            m_lexer.release_lookahead();
        }
        return !sdp.is_errored();
    }
    template<typename SAX>
    JSON_HEDLEY_NON_NULL(2)
    bool sax_parse_internal(SAX* sax)
    {
        std::vector<bool> states;
        bool skip_to_state_evaluation = false;
        while (true)
        {
            if (!skip_to_state_evaluation)
            {
                switch (last_token)
                {
                    case token_type::begin_object:
                    {
                        if (JSON_HEDLEY_UNLIKELY(!sax->start_object(detail::unknown_size())))
                        {
                            return false;
                        }
                        if (get_token() == token_type::end_object)
                        {
                            if (JSON_HEDLEY_UNLIKELY(!sax->end_object()))
                            {
                                return false;
                            }
                            break;
                        }
                        if (JSON_HEDLEY_UNLIKELY(last_token != token_type::value_string))
                        {
                            return sax->parse_error(m_lexer.get_position(),
                                                    m_lexer.get_token_string(),
                                                    parse_error::create(101, m_lexer.get_position(), exception_message(token_type::value_string, "object key"), nullptr));
                        }
                        if (JSON_HEDLEY_UNLIKELY(!sax->key(m_lexer.get_string())))
                        {
                            return false;
                        }
                        if (JSON_HEDLEY_UNLIKELY(get_token() != token_type::name_separator))
                        {
                            return sax->parse_error(m_lexer.get_position(),
                                                    m_lexer.get_token_string(),
                                                    parse_error::create(101, m_lexer.get_position(), exception_message(token_type::name_separator, "object separator"), nullptr));
                        }
                        states.push_back(false);
                        get_token();
                        continue;
                    }
                    case token_type::begin_array:
                    {
                        if (JSON_HEDLEY_UNLIKELY(!sax->start_array(detail::unknown_size())))
                        {
                            return false;
                        }
                        if (get_token() == token_type::end_array)
                        {
                            if (JSON_HEDLEY_UNLIKELY(!sax->end_array()))
                            {
                                return false;
                            }
                            break;
                        }
                        states.push_back(true);
                        continue;
                    }
                    case token_type::value_float:
                    {
                        const auto res = m_lexer.get_number_float();
                        if (JSON_HEDLEY_UNLIKELY(!std::isfinite(res)))
                        {
                            return sax->parse_error(m_lexer.get_position(),
                                                    m_lexer.get_token_string(),
                                                    out_of_range::create(406, concat("number overflow parsing '", m_lexer.get_token_string(), '\''), nullptr));
                        }
                        if (JSON_HEDLEY_UNLIKELY(!sax->number_float(res, m_lexer.get_string())))
                        {
                            return false;
                        }
                        break;
                    }
                    case token_type::literal_false:
                    {
                        if (JSON_HEDLEY_UNLIKELY(!sax->boolean(false)))
                        {
                            return false;
                        }
                        break;
                    }
                    case token_type::literal_null:
                    {
                        if (JSON_HEDLEY_UNLIKELY(!sax->null()))
                        {
                            return false;
                        }
                        break;
                    }
                    case token_type::literal_true:
                    {
                        if (JSON_HEDLEY_UNLIKELY(!sax->boolean(true)))
                        {
                            return false;
                        }
                        break;
                    }
                    case token_type::value_integer:
                    {
                        if (JSON_HEDLEY_UNLIKELY(!sax->number_integer(m_lexer.get_number_integer())))
                        {
                            return false;
                        }
                        break;
                    }
                    case token_type::value_string:
                    {
                        if (JSON_HEDLEY_UNLIKELY(!sax->string(m_lexer.get_string())))
                        {
                            return false;
                        }
                        break;
                    }
                    case token_type::value_unsigned:
                    {
                        if (JSON_HEDLEY_UNLIKELY(!sax->number_unsigned(m_lexer.get_number_unsigned())))
                        {
                            return false;
                        }
                        break;
                    }
                    case token_type::parse_error:
                    {
                        return sax->parse_error(m_lexer.get_position(),
                                                m_lexer.get_token_string(),
                                                parse_error::create(101, m_lexer.get_position(), exception_message(token_type::uninitialized, "value"), nullptr));
                    }
                    case token_type::end_of_input:
                    {
                        if (JSON_HEDLEY_UNLIKELY(m_lexer.get_position().chars_read_total == 1))
                        {
                            return sax->parse_error(m_lexer.get_position(),
                                                    m_lexer.get_token_string(),
                                                    parse_error::create(101, m_lexer.get_position(),
                                                            "attempting to parse an empty input; check that your input string or stream contains the expected JSON", nullptr));
                        }
                        return sax->parse_error(m_lexer.get_position(),
                                                m_lexer.get_token_string(),
                                                parse_error::create(101, m_lexer.get_position(), exception_message(token_type::literal_or_value, "value"), nullptr));
                    }
                    case token_type::uninitialized:
                    case token_type::end_array:
                    case token_type::end_object:
                    case token_type::name_separator:
                    case token_type::value_separator:
                    case token_type::literal_or_value:
                    default: 
                    {
                        return sax->parse_error(m_lexer.get_position(),
                                                m_lexer.get_token_string(),
                                                parse_error::create(101, m_lexer.get_position(), exception_message(token_type::literal_or_value, "value"), nullptr));
                    }
                }
            }
            else
            {
                skip_to_state_evaluation = false;
            }
            if (states.empty())
            {
                return true;
            }
            if (states.back())  
            {
                if (get_token() == token_type::value_separator)
                {
                    get_token();
                    if (!(ignore_trailing_commas && last_token == token_type::end_array))
                    {
                        continue;
                    }
                }
                if (JSON_HEDLEY_LIKELY(last_token == token_type::end_array))
                {
                    if (JSON_HEDLEY_UNLIKELY(!sax->end_array()))
                    {
                        return false;
                    }
                    JSON_ASSERT(!states.empty());
                    states.pop_back();
                    skip_to_state_evaluation = true;
                    continue;
                }
                return sax->parse_error(m_lexer.get_position(),
                                        m_lexer.get_token_string(),
                                        parse_error::create(101, m_lexer.get_position(), exception_message(token_type::end_array, "array"), nullptr));
            }
            if (get_token() == token_type::value_separator)
            {
                get_token();
                if (!(ignore_trailing_commas && last_token == token_type::end_object))
                {
                    if (JSON_HEDLEY_UNLIKELY(last_token != token_type::value_string))
                    {
                        return sax->parse_error(m_lexer.get_position(),
                                                m_lexer.get_token_string(),
                                                parse_error::create(101, m_lexer.get_position(), exception_message(token_type::value_string, "object key"), nullptr));
                    }
                    if (JSON_HEDLEY_UNLIKELY(!sax->key(m_lexer.get_string())))
                    {
                        return false;
                    }
                    if (JSON_HEDLEY_UNLIKELY(get_token() != token_type::name_separator))
                    {
                        return sax->parse_error(m_lexer.get_position(),
                                                m_lexer.get_token_string(),
                                                parse_error::create(101, m_lexer.get_position(), exception_message(token_type::name_separator, "object separator"), nullptr));
                    }
                    get_token();
                    continue;
                }
            }
            if (JSON_HEDLEY_LIKELY(last_token == token_type::end_object))
            {
                if (JSON_HEDLEY_UNLIKELY(!sax->end_object()))
                {
                    return false;
                }
                JSON_ASSERT(!states.empty());
                states.pop_back();
                skip_to_state_evaluation = true;
                continue;
            }
            return sax->parse_error(m_lexer.get_position(),
                                    m_lexer.get_token_string(),
                                    parse_error::create(101, m_lexer.get_position(), exception_message(token_type::end_object, "object"), nullptr));
        }
    }
    token_type get_token()
    {
        return last_token = m_lexer.scan();
    }
    std::string exception_message(const token_type expected, const std::string& context)
    {
        std::string error_msg = "syntax error ";
        if (!context.empty())
        {
            error_msg += concat("while parsing ", context, ' ');
        }
        error_msg += "- ";
        if (last_token == token_type::parse_error)
        {
            error_msg += concat(m_lexer.get_error_message(), "; last read: '",
                                m_lexer.get_token_string(), '\'');
        }
        else
        {
            error_msg += concat("unexpected ", lexer_t::token_type_name(last_token));
        }
        if (expected != token_type::uninitialized)
        {
            error_msg += concat("; expected ", lexer_t::token_type_name(expected));
        }
        return error_msg;
    }
  private:
    const parser_callback_t<BasicJsonType> callback = nullptr;
    token_type last_token = token_type::uninitialized;
    lexer_t m_lexer;
    const bool allow_exceptions = true;
    const bool ignore_trailing_commas = false;
};
}  
NLOHMANN_JSON_NAMESPACE_END
#include <cstddef> 
#include <limits>  
NLOHMANN_JSON_NAMESPACE_BEGIN
namespace detail
{
class primitive_iterator_t
{
  private:
    using difference_type = std::ptrdiff_t;
    static constexpr difference_type begin_value = 0;
    static constexpr difference_type end_value = begin_value + 1;
  JSON_PRIVATE_UNLESS_TESTED:
    difference_type m_it = (std::numeric_limits<std::ptrdiff_t>::min)();
  public:
    constexpr difference_type get_value() const noexcept
    {
        return m_it;
    }
    void set_begin() noexcept
    {
        m_it = begin_value;
    }
    void set_end() noexcept
    {
        m_it = end_value;
    }
    constexpr bool is_begin() const noexcept
    {
        return m_it == begin_value;
    }
    constexpr bool is_end() const noexcept
    {
        return m_it == end_value;
    }
    friend constexpr bool operator==(primitive_iterator_t lhs, primitive_iterator_t rhs) noexcept
    {
        return lhs.m_it == rhs.m_it;
    }
    friend constexpr bool operator<(primitive_iterator_t lhs, primitive_iterator_t rhs) noexcept
    {
        return lhs.m_it < rhs.m_it;
    }
    primitive_iterator_t operator+(difference_type n) noexcept
    {
        auto result = *this;
        result += n;
        return result;
    }
    friend constexpr difference_type operator-(primitive_iterator_t lhs, primitive_iterator_t rhs) noexcept
    {
        return lhs.m_it - rhs.m_it;
    }
    primitive_iterator_t& operator++() noexcept
    {
        ++m_it;
        return *this;
    }
    primitive_iterator_t operator++(int)& noexcept 
    {
        auto result = *this;
        ++m_it;
        return result;
    }
    primitive_iterator_t& operator--() noexcept
    {
        --m_it;
        return *this;
    }
    primitive_iterator_t operator--(int)& noexcept 
    {
        auto result = *this;
        --m_it;
        return result;
    }
    primitive_iterator_t& operator+=(difference_type n) noexcept
    {
        m_it += n;
        return *this;
    }
    primitive_iterator_t& operator-=(difference_type n) noexcept
    {
        m_it -= n;
        return *this;
    }
};
}  
NLOHMANN_JSON_NAMESPACE_END
NLOHMANN_JSON_NAMESPACE_BEGIN
namespace detail
{
template<typename BasicJsonType> struct internal_iterator
{
    typename BasicJsonType::object_t::iterator object_iterator {};
    typename BasicJsonType::array_t::iterator array_iterator {};
    primitive_iterator_t primitive_iterator {};
};
}  
NLOHMANN_JSON_NAMESPACE_END
#include <iterator> 
#include <type_traits> 
NLOHMANN_JSON_NAMESPACE_BEGIN
namespace detail
{
template<typename IteratorType> class iteration_proxy;
template<typename IteratorType> class iteration_proxy_value;
template<typename BasicJsonType>
class iter_impl 
{
    using other_iter_impl = iter_impl<typename std::conditional<std::is_const<BasicJsonType>::value, typename std::remove_const<BasicJsonType>::type, const BasicJsonType>::type>;
    friend other_iter_impl;
    friend BasicJsonType;
    friend iteration_proxy<iter_impl>;
    friend iteration_proxy_value<iter_impl>;
    using object_t = typename BasicJsonType::object_t;
    using array_t = typename BasicJsonType::array_t;
    static_assert(is_basic_json<typename std::remove_const<BasicJsonType>::type>::value,
                  "iter_impl only accepts (const) basic_json");
    static_assert(std::is_base_of<std::bidirectional_iterator_tag, std::bidirectional_iterator_tag>::value
                  &&  std::is_base_of<std::bidirectional_iterator_tag, typename std::iterator_traits<typename array_t::iterator>::iterator_category>::value,
                  "basic_json iterator assumes array and object type iterators satisfy the LegacyBidirectionalIterator named requirement.");
  public:
    using iterator_category = std::bidirectional_iterator_tag;
    using value_type = typename BasicJsonType::value_type;
    using difference_type = typename BasicJsonType::difference_type;
    using pointer = typename std::conditional<std::is_const<BasicJsonType>::value,
          typename BasicJsonType::const_pointer,
          typename BasicJsonType::pointer>::type;
    using reference =
        typename std::conditional<std::is_const<BasicJsonType>::value,
        typename BasicJsonType::const_reference,
        typename BasicJsonType::reference>::type;
    iter_impl() = default;
    ~iter_impl() = default;
    iter_impl(iter_impl&&) = default; 
    iter_impl& operator=(iter_impl&&) = default; 
    explicit iter_impl(pointer object) noexcept : m_object(object)
    {
        JSON_ASSERT(m_object != nullptr);
        switch (m_object->m_data.m_type)
        {
            case value_t::object:
            {
                m_it.object_iterator = typename object_t::iterator();
                break;
            }
            case value_t::array:
            {
                m_it.array_iterator = typename array_t::iterator();
                break;
            }
            case value_t::null:
            case value_t::string:
            case value_t::boolean:
            case value_t::number_integer:
            case value_t::number_unsigned:
            case value_t::number_float:
            case value_t::binary:
            case value_t::discarded:
            default:
            {
                m_it.primitive_iterator = primitive_iterator_t();
                break;
            }
        }
    }
    iter_impl(const iter_impl<const BasicJsonType>& other) noexcept
        : m_object(other.m_object), m_it(other.m_it)
    {}
    iter_impl& operator=(const iter_impl<const BasicJsonType>& other) noexcept
    {
        if (&other != this)
        {
            m_object = other.m_object;
            m_it = other.m_it;
        }
        return *this;
    }
    iter_impl(const iter_impl<typename std::remove_const<BasicJsonType>::type>& other) noexcept
        : m_object(other.m_object), m_it(other.m_it)
    {}
    iter_impl& operator=(const iter_impl<typename std::remove_const<BasicJsonType>::type>& other) noexcept 
    {
        m_object = other.m_object;
        m_it = other.m_it;
        return *this;
    }
  JSON_PRIVATE_UNLESS_TESTED:
    void set_begin() noexcept
    {
        JSON_ASSERT(m_object != nullptr);
        switch (m_object->m_data.m_type)
        {
            case value_t::object:
            {
                m_it.object_iterator = m_object->m_data.m_value.object->begin();
                break;
            }
            case value_t::array:
            {
                m_it.array_iterator = m_object->m_data.m_value.array->begin();
                break;
            }
            case value_t::null:
            {
                m_it.primitive_iterator.set_end();
                break;
            }
            case value_t::string:
            case value_t::boolean:
            case value_t::number_integer:
            case value_t::number_unsigned:
            case value_t::number_float:
            case value_t::binary:
            case value_t::discarded:
            default:
            {
                m_it.primitive_iterator.set_begin();
                break;
            }
        }
    }
    void set_end() noexcept
    {
        JSON_ASSERT(m_object != nullptr);
        switch (m_object->m_data.m_type)
        {
            case value_t::object:
            {
                m_it.object_iterator = m_object->m_data.m_value.object->end();
                break;
            }
            case value_t::array:
            {
                m_it.array_iterator = m_object->m_data.m_value.array->end();
                break;
            }
            case value_t::null:
            case value_t::string:
            case value_t::boolean:
            case value_t::number_integer:
            case value_t::number_unsigned:
            case value_t::number_float:
            case value_t::binary:
            case value_t::discarded:
            default:
            {
                m_it.primitive_iterator.set_end();
                break;
            }
        }
    }
  public:
    reference operator*() const
    {
        JSON_ASSERT(m_object != nullptr);
        switch (m_object->m_data.m_type)
        {
            case value_t::object:
            {
                JSON_ASSERT(m_it.object_iterator != m_object->m_data.m_value.object->end());
                return m_it.object_iterator->second;
            }
            case value_t::array:
            {
                JSON_ASSERT(m_it.array_iterator != m_object->m_data.m_value.array->end());
                return *m_it.array_iterator;
            }
            case value_t::null:
                JSON_THROW(invalid_iterator::create(214, "cannot get value", m_object));
            case value_t::string:
            case value_t::boolean:
            case value_t::number_integer:
            case value_t::number_unsigned:
            case value_t::number_float:
            case value_t::binary:
            case value_t::discarded:
            default:
            {
                if (JSON_HEDLEY_LIKELY(m_it.primitive_iterator.is_begin()))
                {
                    return *m_object;
                }
                JSON_THROW(invalid_iterator::create(214, "cannot get value", m_object));
            }
        }
    }
    pointer operator->() const
    {
        JSON_ASSERT(m_object != nullptr);
        switch (m_object->m_data.m_type)
        {
            case value_t::object:
            {
                JSON_ASSERT(m_it.object_iterator != m_object->m_data.m_value.object->end());
                return &(m_it.object_iterator->second);
            }
            case value_t::array:
            {
                JSON_ASSERT(m_it.array_iterator != m_object->m_data.m_value.array->end());
                return &*m_it.array_iterator;
            }
            case value_t::null:
            case value_t::string:
            case value_t::boolean:
            case value_t::number_integer:
            case value_t::number_unsigned:
            case value_t::number_float:
            case value_t::binary:
            case value_t::discarded:
            default:
            {
                if (JSON_HEDLEY_LIKELY(m_it.primitive_iterator.is_begin()))
                {
                    return m_object;
                }
                JSON_THROW(invalid_iterator::create(214, "cannot get value", m_object));
            }
        }
    }
    iter_impl operator++(int)& 
    {
        auto result = *this;
        ++(*this);
        return result;
    }
    iter_impl& operator++()
    {
        JSON_ASSERT(m_object != nullptr);
        switch (m_object->m_data.m_type)
        {
            case value_t::object:
            {
                std::advance(m_it.object_iterator, 1);
                break;
            }
            case value_t::array:
            {
                std::advance(m_it.array_iterator, 1);
                break;
            }
            case value_t::null:
            case value_t::string:
            case value_t::boolean:
            case value_t::number_integer:
            case value_t::number_unsigned:
            case value_t::number_float:
            case value_t::binary:
            case value_t::discarded:
            default:
            {
                ++m_it.primitive_iterator;
                break;
            }
        }
        return *this;
    }
    iter_impl operator--(int)& 
    {
        auto result = *this;
        --(*this);
        return result;
    }
    iter_impl& operator--()
    {
        JSON_ASSERT(m_object != nullptr);
        switch (m_object->m_data.m_type)
        {
            case value_t::object:
            {
                std::advance(m_it.object_iterator, -1);
                break;
            }
            case value_t::array:
            {
                std::advance(m_it.array_iterator, -1);
                break;
            }
            case value_t::null:
            case value_t::string:
            case value_t::boolean:
            case value_t::number_integer:
            case value_t::number_unsigned:
            case value_t::number_float:
            case value_t::binary:
            case value_t::discarded:
            default:
            {
                --m_it.primitive_iterator;
                break;
            }
        }
        return *this;
    }
    template < typename IterImpl, detail::enable_if_t < (std::is_same<IterImpl, iter_impl>::value || std::is_same<IterImpl, other_iter_impl>::value), std::nullptr_t > = nullptr >
    bool operator==(const IterImpl& other) const
    {
        if (JSON_HEDLEY_UNLIKELY(m_object != other.m_object))
        {
            JSON_THROW(invalid_iterator::create(212, "cannot compare iterators of different containers", m_object));
        }
        if (m_object == nullptr)
        {
            return true;
        }
        switch (m_object->m_data.m_type)
        {
            case value_t::object:
                return (m_it.object_iterator == other.m_it.object_iterator);
            case value_t::array:
                return (m_it.array_iterator == other.m_it.array_iterator);
            case value_t::null:
            case value_t::string:
            case value_t::boolean:
            case value_t::number_integer:
            case value_t::number_unsigned:
            case value_t::number_float:
            case value_t::binary:
            case value_t::discarded:
            default:
                return (m_it.primitive_iterator == other.m_it.primitive_iterator);
        }
    }
    template < typename IterImpl, detail::enable_if_t < (std::is_same<IterImpl, iter_impl>::value || std::is_same<IterImpl, other_iter_impl>::value), std::nullptr_t > = nullptr >
    bool operator!=(const IterImpl& other) const
    {
        return !operator==(other);
    }
    bool operator<(const iter_impl& other) const
    {
        if (JSON_HEDLEY_UNLIKELY(m_object != other.m_object))
        {
            JSON_THROW(invalid_iterator::create(212, "cannot compare iterators of different containers", m_object));
        }
        if (m_object == nullptr)
        {
            return false;
        }
        switch (m_object->m_data.m_type)
        {
            case value_t::object:
                JSON_THROW(invalid_iterator::create(213, "cannot compare order of object iterators", m_object));
            case value_t::array:
                return (m_it.array_iterator < other.m_it.array_iterator);
            case value_t::null:
            case value_t::string:
            case value_t::boolean:
            case value_t::number_integer:
            case value_t::number_unsigned:
            case value_t::number_float:
            case value_t::binary:
            case value_t::discarded:
            default:
                return (m_it.primitive_iterator < other.m_it.primitive_iterator);
        }
    }
    bool operator<=(const iter_impl& other) const
    {
        return !other.operator < (*this);
    }
    bool operator>(const iter_impl& other) const
    {
        return !operator<=(other);
    }
    bool operator>=(const iter_impl& other) const
    {
        return !operator<(other);
    }
    iter_impl& operator+=(difference_type i)
    {
        JSON_ASSERT(m_object != nullptr);
        switch (m_object->m_data.m_type)
        {
            case value_t::object:
                JSON_THROW(invalid_iterator::create(209, "cannot use offsets with object iterators", m_object));
            case value_t::array:
            {
                std::advance(m_it.array_iterator, i);
                break;
            }
            case value_t::null:
            case value_t::string:
            case value_t::boolean:
            case value_t::number_integer:
            case value_t::number_unsigned:
            case value_t::number_float:
            case value_t::binary:
            case value_t::discarded:
            default:
            {
                m_it.primitive_iterator += i;
                break;
            }
        }
        return *this;
    }
    iter_impl& operator-=(difference_type i)
    {
        return operator+=(-i);
    }
    iter_impl operator+(difference_type i) const
    {
        auto result = *this;
        result += i;
        return result;
    }
    friend iter_impl operator+(difference_type i, const iter_impl& it)
    {
        auto result = it;
        result += i;
        return result;
    }
    iter_impl operator-(difference_type i) const
    {
        auto result = *this;
        result -= i;
        return result;
    }
    difference_type operator-(const iter_impl& other) const
    {
        JSON_ASSERT(m_object != nullptr);
        switch (m_object->m_data.m_type)
        {
            case value_t::object:
                JSON_THROW(invalid_iterator::create(209, "cannot use offsets with object iterators", m_object));
            case value_t::array:
                return m_it.array_iterator - other.m_it.array_iterator;
            case value_t::null:
            case value_t::string:
            case value_t::boolean:
            case value_t::number_integer:
            case value_t::number_unsigned:
            case value_t::number_float:
            case value_t::binary:
            case value_t::discarded:
            default:
                return m_it.primitive_iterator - other.m_it.primitive_iterator;
        }
    }
    reference operator[](difference_type n) const
    {
        JSON_ASSERT(m_object != nullptr);
        switch (m_object->m_data.m_type)
        {
            case value_t::object:
                JSON_THROW(invalid_iterator::create(208, "cannot use operator[] for object iterators", m_object));
            case value_t::array:
                return *std::next(m_it.array_iterator, n);
            case value_t::null:
                JSON_THROW(invalid_iterator::create(214, "cannot get value", m_object));
            case value_t::string:
            case value_t::boolean:
            case value_t::number_integer:
            case value_t::number_unsigned:
            case value_t::number_float:
            case value_t::binary:
            case value_t::discarded:
            default:
            {
                if (JSON_HEDLEY_LIKELY(m_it.primitive_iterator.get_value() == -n))
                {
                    return *m_object;
                }
                JSON_THROW(invalid_iterator::create(214, "cannot get value", m_object));
            }
        }
    }
    const typename object_t::key_type& key() const
    {
        JSON_ASSERT(m_object != nullptr);
        if (JSON_HEDLEY_LIKELY(m_object->is_object()))
        {
            return m_it.object_iterator->first;
        }
        JSON_THROW(invalid_iterator::create(207, "cannot use key() for non-object iterators", m_object));
    }
    reference value() const
    {
        return operator*();
    }
  JSON_PRIVATE_UNLESS_TESTED:
    pointer m_object = nullptr;
    internal_iterator<typename std::remove_const<BasicJsonType>::type> m_it {};
};
}  
NLOHMANN_JSON_NAMESPACE_END
#include <cstddef> 
#include <iterator> 
#include <utility> 
NLOHMANN_JSON_NAMESPACE_BEGIN
namespace detail
{
template<typename Base>
class json_reverse_iterator : public std::reverse_iterator<Base>
{
  public:
    using difference_type = std::ptrdiff_t;
    using base_iterator = std::reverse_iterator<Base>;
    using reference = typename Base::reference;
    explicit json_reverse_iterator(const typename base_iterator::iterator_type& it) noexcept
        : base_iterator(it) {}
    explicit json_reverse_iterator(const base_iterator& it) noexcept : base_iterator(it) {}
    json_reverse_iterator operator++(int)& 
    {
        return static_cast<json_reverse_iterator>(base_iterator::operator++(1));
    }
    json_reverse_iterator& operator++()
    {
        return static_cast<json_reverse_iterator&>(base_iterator::operator++());
    }
    json_reverse_iterator operator--(int)& 
    {
        return static_cast<json_reverse_iterator>(base_iterator::operator--(1));
    }
    json_reverse_iterator& operator--()
    {
        return static_cast<json_reverse_iterator&>(base_iterator::operator--());
    }
    json_reverse_iterator& operator+=(difference_type i)
    {
        return static_cast<json_reverse_iterator&>(base_iterator::operator+=(i));
    }
    json_reverse_iterator operator+(difference_type i) const
    {
        return static_cast<json_reverse_iterator>(base_iterator::operator+(i));
    }
    json_reverse_iterator operator-(difference_type i) const
    {
        return static_cast<json_reverse_iterator>(base_iterator::operator-(i));
    }
    difference_type operator-(const json_reverse_iterator& other) const
    {
        return base_iterator(*this) - base_iterator(other);
    }
    reference operator[](difference_type n) const
    {
        return *(this->operator+(n));
    }
    auto key() const -> decltype(std::declval<Base>().key())
    {
        auto it = --this->base();
        return it.key();
    }
    reference value() const
    {
        auto it = --this->base();
        return it.operator * ();
    }
};
}  
NLOHMANN_JSON_NAMESPACE_END
#include <type_traits> 
NLOHMANN_JSON_NAMESPACE_BEGIN
struct json_default_base {};
namespace detail
{
template<class T>
using json_base_class = typename std::conditional <
                        std::is_same<T, void>::value,
                        ::nlohmann::json_default_base,
                        T
                        >::type;
}  
NLOHMANN_JSON_NAMESPACE_END
#include <algorithm> 
#include <cctype> 
#include <cerrno> 
#include <cstdlib> 
#ifndef JSON_NO_IO
    #include <iosfwd> 
#endif  
#include <limits> 
#include <numeric> 
#include <set> 
#include <string> 
#include <utility> 
#include <vector> 
NLOHMANN_JSON_NAMESPACE_BEGIN
template<typename RefStringType>
class json_pointer
{
    NLOHMANN_BASIC_JSON_TPL_DECLARATION
    friend class basic_json;
    template<typename>
    friend class json_pointer;
    template<typename T>
    struct string_t_helper
    {
        using type = T;
    };
    NLOHMANN_BASIC_JSON_TPL_DECLARATION
    struct string_t_helper<NLOHMANN_BASIC_JSON_TPL>
    {
        using type = StringType;
    };
  public:
    using string_t = typename string_t_helper<RefStringType>::type;
    explicit json_pointer(const string_t& s = "")
        : reference_tokens(split(s))
    {}
    string_t to_string() const
    {
        return std::accumulate(reference_tokens.begin(), reference_tokens.end(),
                               string_t{},
                               [](const string_t& a, const string_t& b)
        {
            return detail::concat<string_t>(a, '/', detail::escape(b));
        });
    }
    JSON_HEDLEY_DEPRECATED_FOR(3.11.0, to_string())
    operator string_t() const
    {
        return to_string();
    }
#ifndef JSON_NO_IO
    friend std::ostream& operator<<(std::ostream& o, const json_pointer& ptr)
    {
        o << ptr.to_string();
        return o;
    }
#endif
    json_pointer& operator/=(const json_pointer& ptr)
    {
        reference_tokens.insert(reference_tokens.end(),
                                ptr.reference_tokens.begin(),
                                ptr.reference_tokens.end());
        return *this;
    }
    json_pointer& operator/=(string_t token)
    {
        push_back(std::move(token));
        return *this;
    }
    json_pointer& operator/=(std::size_t array_idx)
    {
        return *this /= detail::to_string<string_t>(array_idx);
    }
    friend json_pointer operator/(const json_pointer& lhs,
                                  const json_pointer& rhs)
    {
        return json_pointer(lhs) /= rhs;
    }
    friend json_pointer operator/(const json_pointer& lhs, string_t token) 
    {
        return json_pointer(lhs) /= std::move(token);
    }
    friend json_pointer operator/(const json_pointer& lhs, std::size_t array_idx)
    {
        return json_pointer(lhs) /= array_idx;
    }
    json_pointer parent_pointer() const
    {
        if (empty())
        {
            return *this;
        }
        json_pointer res = *this;
        res.pop_back();
        return res;
    }
    void pop_front()
    {
        if (JSON_HEDLEY_UNLIKELY(empty()))
        {
            JSON_THROW(detail::out_of_range::create(405, "JSON pointer has no parent", nullptr));
        }
        reference_tokens.erase(reference_tokens.begin());
    }
    const string_t& front() const
    {
        if (JSON_HEDLEY_UNLIKELY(empty()))
        {
            JSON_THROW(detail::out_of_range::create(405, "JSON pointer has no parent", nullptr));
        }
        return reference_tokens.front();
    }
    void push_front(const string_t& token)
    {
        reference_tokens.insert(reference_tokens.begin(), token);
    }
    void push_front(string_t&& token)
    {
        reference_tokens.insert(reference_tokens.begin(), std::move(token));
    }
    void pop_back()
    {
        if (JSON_HEDLEY_UNLIKELY(empty()))
        {
            JSON_THROW(detail::out_of_range::create(405, "JSON pointer has no parent", nullptr));
        }
        reference_tokens.pop_back();
    }
    const string_t& back() const
    {
        if (JSON_HEDLEY_UNLIKELY(empty()))
        {
            JSON_THROW(detail::out_of_range::create(405, "JSON pointer has no parent", nullptr));
        }
        return reference_tokens.back();
    }
    void push_back(const string_t& token)
    {
        reference_tokens.push_back(token);
    }
    void push_back(string_t&& token)
    {
        reference_tokens.push_back(std::move(token));
    }
    bool empty() const noexcept
    {
        return reference_tokens.empty();
    }
  private:
    template<typename BasicJsonType>
    static typename BasicJsonType::size_type array_index(const string_t& s)
    {
        using size_type = typename BasicJsonType::size_type;
        if (JSON_HEDLEY_UNLIKELY(s.size() > 1 && s[0] == '0'))
        {
            JSON_THROW(detail::parse_error::create(106, 0, detail::concat("array index '", s, "' must not begin with '0'"), nullptr));
        }
        if (JSON_HEDLEY_UNLIKELY(s.size() > 1 && !(s[0] >= '1' && s[0] <= '9')))
        {
            JSON_THROW(detail::parse_error::create(109, 0, detail::concat("array index '", s, "' is not a number"), nullptr));
        }
        const char* p = s.data();
        char* p_end = nullptr; 
        errno = 0; 
        const unsigned long long res = std::strtoull(p, &p_end, 10); 
        if (p == p_end 
                || errno == ERANGE 
                || JSON_HEDLEY_UNLIKELY(static_cast<std::size_t>(p_end - p) != s.size())) 
        {
            JSON_THROW(detail::out_of_range::create(404, detail::concat("unresolved reference token '", s, "'"), nullptr));
        }
        if (res >= static_cast<unsigned long long>((std::numeric_limits<size_type>::max)()))  
        {
            JSON_THROW(detail::out_of_range::create(410, detail::concat("array index ", s, " exceeds size_type"), nullptr));
        }
        return static_cast<size_type>(res);
    }
  JSON_PRIVATE_UNLESS_TESTED:
    json_pointer top() const
    {
        if (JSON_HEDLEY_UNLIKELY(empty()))
        {
            JSON_THROW(detail::out_of_range::create(405, "JSON pointer has no parent", nullptr));
        }
        json_pointer result = *this;
        result.reference_tokens = {reference_tokens[0]};
        return result;
    }
  private:
    using array_parents_t = std::set<std::vector<string_t>>;
    template<typename BasicJsonType>
    BasicJsonType& get_and_create(BasicJsonType& j, const array_parents_t& array_parents) const
    {
        auto* result = &j;
        std::vector<string_t> prefix;
        for (const auto& reference_token : reference_tokens)
        {
            switch (result->type())
            {
                case detail::value_t::null:
                {
                    if (array_parents.find(prefix) != array_parents.end())
                    {
                        result = &result->operator[](array_index<BasicJsonType>(reference_token));
                    }
                    else
                    {
                        result = &result->operator[](reference_token);
                    }
                    break;
                }
                case detail::value_t::object:
                {
                    result = &result->operator[](reference_token);
                    break;
                }
                case detail::value_t::array:
                {
                    result = &result->operator[](array_index<BasicJsonType>(reference_token));
                    break;
                }
                case detail::value_t::string:
                case detail::value_t::boolean:
                case detail::value_t::number_integer:
                case detail::value_t::number_unsigned:
                case detail::value_t::number_float:
                case detail::value_t::binary:
                case detail::value_t::discarded:
                default:
                    JSON_THROW(detail::type_error::create(313, "invalid value to unflatten", &j));
            }
            prefix.push_back(reference_token);
        }
        return *result;
    }
    template<typename BasicJsonType>
    BasicJsonType& get_unchecked(BasicJsonType* ptr) const
    {
        for (const auto& reference_token : reference_tokens)
        {
            if (ptr->is_null())
            {
                const bool nums =
                    std::all_of(reference_token.begin(), reference_token.end(),
                                [](const unsigned char x)
                {
                    return std::isdigit(x);
                });
                *ptr = (nums || reference_token == "-")
                       ? detail::value_t::array
                       : detail::value_t::object;
            }
            switch (ptr->type())
            {
                case detail::value_t::object:
                {
                    ptr = &ptr->operator[](reference_token);
                    break;
                }
                case detail::value_t::array:
                {
                    if (reference_token == "-")
                    {
                        ptr = &ptr->operator[](ptr->m_data.m_value.array->size());
                    }
                    else
                    {
                        ptr = &ptr->operator[](array_index<BasicJsonType>(reference_token));
                    }
                    break;
                }
                case detail::value_t::null:
                case detail::value_t::string:
                case detail::value_t::boolean:
                case detail::value_t::number_integer:
                case detail::value_t::number_unsigned:
                case detail::value_t::number_float:
                case detail::value_t::binary:
                case detail::value_t::discarded:
                default:
                    JSON_THROW(detail::out_of_range::create(404, detail::concat("unresolved reference token '", reference_token, "'"), ptr));
            }
        }
        return *ptr;
    }
    template<typename BasicJsonType>
    BasicJsonType& get_checked(BasicJsonType* ptr) const
    {
        for (const auto& reference_token : reference_tokens)
        {
            switch (ptr->type())
            {
                case detail::value_t::object:
                {
                    ptr = &ptr->at(reference_token);
                    break;
                }
                case detail::value_t::array:
                {
                    if (JSON_HEDLEY_UNLIKELY(reference_token == "-"))
                    {
                        JSON_THROW(detail::out_of_range::create(402, detail::concat(
                                "array index '-' (", std::to_string(ptr->m_data.m_value.array->size()),
                                ") is out of range"), ptr));
                    }
                    const auto idx = array_index<BasicJsonType>(reference_token);
                    if (JSON_HEDLEY_UNLIKELY(idx >= ptr->m_data.m_value.array->size()))
                    {
                        JSON_THROW(detail::out_of_range::create(401, detail::concat(
                                "array index ", std::to_string(idx), " is out of range"), ptr));
                    }
                    ptr = &ptr->operator[](idx);
                    break;
                }
                case detail::value_t::null:
                case detail::value_t::string:
                case detail::value_t::boolean:
                case detail::value_t::number_integer:
                case detail::value_t::number_unsigned:
                case detail::value_t::number_float:
                case detail::value_t::binary:
                case detail::value_t::discarded:
                default:
                    JSON_THROW(detail::out_of_range::create(404, detail::concat("unresolved reference token '", reference_token, "'"), ptr));
            }
        }
        return *ptr;
    }
    template<typename BasicJsonType>
    const BasicJsonType& get_unchecked(const BasicJsonType* ptr) const
    {
        for (const auto& reference_token : reference_tokens)
        {
            switch (ptr->type())
            {
                case detail::value_t::object:
                {
                    ptr = &ptr->operator[](reference_token);
                    break;
                }
                case detail::value_t::array:
                {
                    if (JSON_HEDLEY_UNLIKELY(reference_token == "-"))
                    {
                        JSON_THROW(detail::out_of_range::create(402, detail::concat("array index '-' (", std::to_string(ptr->m_data.m_value.array->size()), ") is out of range"), ptr));
                    }
                    ptr = &ptr->operator[](array_index<BasicJsonType>(reference_token));
                    break;
                }
                case detail::value_t::null:
                case detail::value_t::string:
                case detail::value_t::boolean:
                case detail::value_t::number_integer:
                case detail::value_t::number_unsigned:
                case detail::value_t::number_float:
                case detail::value_t::binary:
                case detail::value_t::discarded:
                default:
                    JSON_THROW(detail::out_of_range::create(404, detail::concat("unresolved reference token '", reference_token, "'"), ptr));
            }
        }
        return *ptr;
    }
    template<typename BasicJsonType>
    const BasicJsonType& get_checked(const BasicJsonType* ptr) const
    {
        for (const auto& reference_token : reference_tokens)
        {
            switch (ptr->type())
            {
                case detail::value_t::object:
                {
                    ptr = &ptr->at(reference_token);
                    break;
                }
                case detail::value_t::array:
                {
                    if (JSON_HEDLEY_UNLIKELY(reference_token == "-"))
                    {
                        JSON_THROW(detail::out_of_range::create(402, detail::concat(
                                "array index '-' (", std::to_string(ptr->m_data.m_value.array->size()),
                                ") is out of range"), ptr));
                    }
                    const auto idx = array_index<BasicJsonType>(reference_token);
                    if (JSON_HEDLEY_UNLIKELY(idx >= ptr->m_data.m_value.array->size()))
                    {
                        JSON_THROW(detail::out_of_range::create(401, detail::concat(
                                "array index ", std::to_string(idx), " is out of range"), ptr));
                    }
                    ptr = &ptr->operator[](idx);
                    break;
                }
                case detail::value_t::null:
                case detail::value_t::string:
                case detail::value_t::boolean:
                case detail::value_t::number_integer:
                case detail::value_t::number_unsigned:
                case detail::value_t::number_float:
                case detail::value_t::binary:
                case detail::value_t::discarded:
                default:
                    JSON_THROW(detail::out_of_range::create(404, detail::concat("unresolved reference token '", reference_token, "'"), ptr));
            }
        }
        return *ptr;
    }
    template<typename BasicJsonType>
    const BasicJsonType* get_checked_or_null(const BasicJsonType* ptr) const
    {
        for (const auto& reference_token : reference_tokens)
        {
            switch (ptr->type())
            {
                case detail::value_t::object:
                {
                    const auto it = ptr->find(reference_token);
                    if (JSON_HEDLEY_UNLIKELY(it == ptr->end()))
                    {
                        return nullptr;
                    }
                    ptr = &*it;
                    break;
                }
                case detail::value_t::array:
                {
                    if (JSON_HEDLEY_UNLIKELY(reference_token == "-"))
                    {
                        return nullptr;
                    }
                    typename BasicJsonType::size_type idx{};
                    JSON_TRY
                    {
                        idx = array_index<BasicJsonType>(reference_token);
                    }
                    JSON_INTERNAL_CATCH (detail::out_of_range&)
                    {
                        return nullptr;
                    }
                    if (JSON_HEDLEY_UNLIKELY(idx >= ptr->m_data.m_value.array->size()))
                    {
                        return nullptr;
                    }
                    ptr = &ptr->operator[](idx);
                    break;
                }
                case detail::value_t::null:
                case detail::value_t::string:
                case detail::value_t::boolean:
                case detail::value_t::number_integer:
                case detail::value_t::number_unsigned:
                case detail::value_t::number_float:
                case detail::value_t::binary:
                case detail::value_t::discarded:
                default:
                    return nullptr;
            }
        }
        return ptr;
    }
    template<typename BasicJsonType>
    bool contains(const BasicJsonType* ptr) const
    {
        for (const auto& reference_token : reference_tokens)
        {
            switch (ptr->type())
            {
                case detail::value_t::object:
                {
                    if (!ptr->contains(reference_token))
                    {
                        return false;
                    }
                    ptr = &ptr->operator[](reference_token);
                    break;
                }
                case detail::value_t::array:
                {
                    if (JSON_HEDLEY_UNLIKELY(reference_token == "-"))
                    {
                        return false;
                    }
                    if (JSON_HEDLEY_UNLIKELY(reference_token.empty()))
                    {
                        return false;
                    }
                    if (JSON_HEDLEY_UNLIKELY(reference_token.size() == 1 && !('0' <= reference_token[0] && reference_token[0] <= '9')))
                    {
                        return false;
                    }
                    if (JSON_HEDLEY_UNLIKELY(reference_token.size() > 1))
                    {
                        if (JSON_HEDLEY_UNLIKELY(!('1' <= reference_token[0] && reference_token[0] <= '9')))
                        {
                            return false;
                        }
                        for (std::size_t i = 1; i < reference_token.size(); i++)
                        {
                            if (JSON_HEDLEY_UNLIKELY(!('0' <= reference_token[i] && reference_token[i] <= '9')))
                            {
                                return false;
                            }
                        }
                    }
                    errno = 0; 
                    char* p_end = nullptr; 
                    const unsigned long long magnitude = std::strtoull(reference_token.data(), &p_end, 10); 
                    if (JSON_HEDLEY_UNLIKELY(errno == ERANGE 
                                             || magnitude >= static_cast<unsigned long long>((std::numeric_limits<typename BasicJsonType::size_type>::max)()))) 
                    {
                        return false;
                    }
                    const auto idx = array_index<BasicJsonType>(reference_token);
                    if (idx >= ptr->size())
                    {
                        return false;
                    }
                    ptr = &ptr->operator[](idx);
                    break;
                }
                case detail::value_t::null:
                case detail::value_t::string:
                case detail::value_t::boolean:
                case detail::value_t::number_integer:
                case detail::value_t::number_unsigned:
                case detail::value_t::number_float:
                case detail::value_t::binary:
                case detail::value_t::discarded:
                default:
                {
                    return false;
                }
            }
        }
        return true;
    }
    static std::vector<string_t> split(const string_t& reference_string)
    {
        std::vector<string_t> result;
        if (reference_string.empty())
        {
            return result;
        }
        if (JSON_HEDLEY_UNLIKELY(reference_string[0] != '/'))
        {
            JSON_THROW(detail::parse_error::create(107, 1, detail::concat("JSON pointer must be empty or begin with '/' - was: '", reference_string, "'"), nullptr));
        }
        for (
            std::size_t slash = reference_string.find_first_of('/', 1),
            start = 1;
            start != 0;
            start = (slash == string_t::npos) ? 0 : slash + 1,
            slash = reference_string.find_first_of('/', start))
        {
            const auto count = (slash == string_t::npos ? reference_string.size() : slash) - start;
            auto reference_token = string_t(reference_string.data() + start, count);
            for (std::size_t pos = reference_token.find_first_of('~');
                    pos != string_t::npos;
                    pos = reference_token.find_first_of('~', pos + 1))
            {
                JSON_ASSERT(reference_token[pos] == '~');
                if (JSON_HEDLEY_UNLIKELY(pos == reference_token.size() - 1 ||
                                         (reference_token[pos + 1] != '0' &&
                                          reference_token[pos + 1] != '1')))
                {
                    JSON_THROW(detail::parse_error::create(108, 0, "escape character '~' must be followed with '0' or '1'", nullptr));
                }
            }
            detail::unescape(reference_token);
            result.push_back(reference_token);
        }
        return result;
    }
  private:
    template<typename BasicJsonType>
    static void flatten(const string_t& reference_string,
                        const BasicJsonType& value,
                        BasicJsonType& result)
    {
        switch (value.type())
        {
            case detail::value_t::array:
            {
                if (value.m_data.m_value.array->empty())
                {
                    result[reference_string] = nullptr;
                }
                else
                {
                    for (std::size_t i = 0; i < value.m_data.m_value.array->size(); ++i)
                    {
                        flatten(detail::concat<string_t>(reference_string, '/', std::to_string(i)),
                                value.m_data.m_value.array->operator[](i), result);
                    }
                }
                break;
            }
            case detail::value_t::object:
            {
                if (value.m_data.m_value.object->empty())
                {
                    result[reference_string] = nullptr;
                }
                else
                {
                    for (const auto& element : *value.m_data.m_value.object)
                    {
                        flatten(detail::concat<string_t>(reference_string, '/', detail::escape(element.first)), element.second, result);
                    }
                }
                break;
            }
            case detail::value_t::null:
            case detail::value_t::string:
            case detail::value_t::boolean:
            case detail::value_t::number_integer:
            case detail::value_t::number_unsigned:
            case detail::value_t::number_float:
            case detail::value_t::binary:
            case detail::value_t::discarded:
            default:
            {
                result[reference_string] = value;
                break;
            }
        }
    }
    template<typename BasicJsonType>
    static BasicJsonType
    unflatten(const BasicJsonType& value)
    {
        if (JSON_HEDLEY_UNLIKELY(!value.is_object()))
        {
            JSON_THROW(detail::type_error::create(314, "only objects can be unflattened", &value));
        }
        BasicJsonType result;
        array_parents_t array_parents;
        for (const auto& element : *value.m_data.m_value.object)
        {
            json_pointer ptr(element.first);
            std::vector<string_t> prefix;
            for (auto& reference_token : ptr.reference_tokens)
            {
                if (reference_token == "0")
                {
                    array_parents.insert(prefix);
                }
                prefix.push_back(std::move(reference_token));
            }
        }
        for (const auto& element : *value.m_data.m_value.object)
        {
            if (JSON_HEDLEY_UNLIKELY(!element.second.is_primitive()))
            {
                JSON_THROW(detail::type_error::create(315, "values in object must be primitive", &element.second));
            }
            json_pointer(element.first).get_and_create(result, array_parents) = element.second;
        }
        return result;
    }
    json_pointer<string_t> convert() const&
    {
        json_pointer<string_t> result;
        result.reference_tokens = reference_tokens;
        return result;
    }
    json_pointer<string_t> convert()&&
    {
        json_pointer<string_t> result;
        result.reference_tokens = std::move(reference_tokens);
        return result;
    }
  public:
#if JSON_HAS_THREE_WAY_COMPARISON
    template<typename RefStringTypeRhs>
    bool operator==(const json_pointer<RefStringTypeRhs>& rhs) const noexcept
    {
        return reference_tokens == rhs.reference_tokens;
    }
    JSON_HEDLEY_DEPRECATED_FOR(3.11.2, operator==(json_pointer))
    bool operator==(const string_t& rhs) const
    {
        return *this == json_pointer(rhs);
    }
    template<typename RefStringTypeRhs>
    std::strong_ordering operator<=>(const json_pointer<RefStringTypeRhs>& rhs) const noexcept 
    {
        return  reference_tokens <=> rhs.reference_tokens; 
    }
#else
    template<typename RefStringTypeLhs, typename RefStringTypeRhs>
    friend bool operator==(const json_pointer<RefStringTypeLhs>& lhs,
                           const json_pointer<RefStringTypeRhs>& rhs) noexcept;
    template<typename RefStringTypeLhs, typename StringType>
    friend bool operator==(const json_pointer<RefStringTypeLhs>& lhs,
                           const StringType& rhs);
    template<typename RefStringTypeRhs, typename StringType>
    friend bool operator==(const StringType& lhs,
                           const json_pointer<RefStringTypeRhs>& rhs);
    template<typename RefStringTypeLhs, typename RefStringTypeRhs>
    friend bool operator!=(const json_pointer<RefStringTypeLhs>& lhs,
                           const json_pointer<RefStringTypeRhs>& rhs) noexcept;
    template<typename RefStringTypeLhs, typename StringType>
    friend bool operator!=(const json_pointer<RefStringTypeLhs>& lhs,
                           const StringType& rhs);
    template<typename RefStringTypeRhs, typename StringType>
    friend bool operator!=(const StringType& lhs,
                           const json_pointer<RefStringTypeRhs>& rhs);
    template<typename RefStringTypeLhs, typename RefStringTypeRhs>
    friend bool operator<(const json_pointer<RefStringTypeLhs>& lhs,
                          const json_pointer<RefStringTypeRhs>& rhs) noexcept;
#endif
  private:
    std::vector<string_t> reference_tokens;
};
#if !JSON_HAS_THREE_WAY_COMPARISON
template<typename RefStringTypeLhs, typename RefStringTypeRhs>
inline bool operator==(const json_pointer<RefStringTypeLhs>& lhs,
                       const json_pointer<RefStringTypeRhs>& rhs) noexcept
{
    return lhs.reference_tokens == rhs.reference_tokens;
}
template<typename RefStringTypeLhs,
         typename StringType = typename json_pointer<RefStringTypeLhs>::string_t>
JSON_HEDLEY_DEPRECATED_FOR(3.11.2, operator==(json_pointer, json_pointer))
inline bool operator==(const json_pointer<RefStringTypeLhs>& lhs,
                       const StringType& rhs)
{
    return lhs == json_pointer<RefStringTypeLhs>(rhs);
}
template<typename RefStringTypeRhs,
         typename StringType = typename json_pointer<RefStringTypeRhs>::string_t>
JSON_HEDLEY_DEPRECATED_FOR(3.11.2, operator==(json_pointer, json_pointer))
inline bool operator==(const StringType& lhs,
                       const json_pointer<RefStringTypeRhs>& rhs)
{
    return json_pointer<RefStringTypeRhs>(lhs) == rhs;
}
template<typename RefStringTypeLhs, typename RefStringTypeRhs>
inline bool operator!=(const json_pointer<RefStringTypeLhs>& lhs,
                       const json_pointer<RefStringTypeRhs>& rhs) noexcept
{
    return !(lhs == rhs);
}
template<typename RefStringTypeLhs,
         typename StringType = typename json_pointer<RefStringTypeLhs>::string_t>
JSON_HEDLEY_DEPRECATED_FOR(3.11.2, operator!=(json_pointer, json_pointer))
inline bool operator!=(const json_pointer<RefStringTypeLhs>& lhs,
                       const StringType& rhs)
{
    return !(lhs == rhs);
}
template<typename RefStringTypeRhs,
         typename StringType = typename json_pointer<RefStringTypeRhs>::string_t>
JSON_HEDLEY_DEPRECATED_FOR(3.11.2, operator!=(json_pointer, json_pointer))
inline bool operator!=(const StringType& lhs,
                       const json_pointer<RefStringTypeRhs>& rhs)
{
    return !(lhs == rhs);
}
template<typename RefStringTypeLhs, typename RefStringTypeRhs>
inline bool operator<(const json_pointer<RefStringTypeLhs>& lhs,
                      const json_pointer<RefStringTypeRhs>& rhs) noexcept
{
    return lhs.reference_tokens < rhs.reference_tokens;
}
#endif
NLOHMANN_JSON_NAMESPACE_END
#include <initializer_list>
#include <utility>
NLOHMANN_JSON_NAMESPACE_BEGIN
namespace detail
{
template<typename BasicJsonType>
class json_ref
{
  public:
    using value_type = BasicJsonType;
    json_ref(value_type&& value)
        : owned_value(std::move(value))
    {}
    json_ref(const value_type& value)
        : value_ref(&value)
    {}
    json_ref(std::initializer_list<json_ref> init)
        : owned_value(init)
    {}
    template <
        class... Args,
        enable_if_t<std::is_constructible<value_type, Args...>::value, int> = 0 >
    json_ref(Args && ... args)
        : owned_value(std::forward<Args>(args)...)
    {}
    json_ref(json_ref&&) noexcept = default;
    json_ref(const json_ref&) = delete;
    json_ref& operator=(const json_ref&) = delete;
    json_ref& operator=(json_ref&&) = delete;
    ~json_ref() = default;
    value_type moved_or_copied() const
    {
        if (value_ref == nullptr)
        {
            return std::move(owned_value);
        }
        return *value_ref;
    }
    value_type const& operator*() const
    {
        return value_ref ? *value_ref : owned_value;
    }
    value_type const* operator->() const
    {
        return &** this;
    }
  private:
    mutable value_type owned_value = nullptr;
    value_type const* value_ref = nullptr;
};
}  
NLOHMANN_JSON_NAMESPACE_END
#include <algorithm> 
#include <array> 
#include <cmath> 
#include <cstdint> 
#include <cstring> 
#include <limits> 
#include <string> 
#include <type_traits> 
#include <utility> 
#include <vector> 
#ifdef _MSC_VER
    #include <cstdlib> 
#endif
#include <cstddef> 
#include <memory> 
#include <string> 
#include <type_traits> 
#include <utility> 
#include <vector> 
#ifndef JSON_NO_IO
    #include <ios>      
    #include <ostream>  
#endif  
NLOHMANN_JSON_NAMESPACE_BEGIN
namespace detail
{
template<typename CharType> struct output_adapter_protocol
{
    virtual void write_character(CharType c) = 0;
    virtual void write_characters(const CharType* s, std::size_t length) = 0;
    virtual ~output_adapter_protocol() = default;
    output_adapter_protocol() = default;
    output_adapter_protocol(const output_adapter_protocol&) = default;
    output_adapter_protocol(output_adapter_protocol&&) noexcept = default;
    output_adapter_protocol& operator=(const output_adapter_protocol&) = default;
    output_adapter_protocol& operator=(output_adapter_protocol&&) noexcept = default;
};
template<typename CharType>
using output_adapter_t = std::shared_ptr<output_adapter_protocol<CharType>>;
template<typename CharType, typename AllocatorType = std::allocator<CharType>>
class output_vector_sink
{
  public:
    explicit output_vector_sink(std::vector<CharType, AllocatorType>& vec) noexcept
        : v(vec)
    {}
    void write_character(CharType c)
    {
        v.push_back(c);
    }
    void write_characters(const CharType* s, std::size_t length)
    {
        v.insert(v.end(), s, s + length);
    }
  private:
    std::vector<CharType, AllocatorType>& v;
};
template<typename CharType, typename AllocatorType = std::allocator<CharType>>
class output_vector_adapter : public output_adapter_protocol<CharType>
{
  public:
    explicit output_vector_adapter(std::vector<CharType, AllocatorType>& vec) noexcept
        : sink(vec)
    {}
    void write_character(CharType c) override
    {
        sink.write_character(c);
    }
    void write_characters(const CharType* s, std::size_t length) override
    {
        sink.write_characters(s, length);
    }
  private:
    output_vector_sink<CharType, AllocatorType> sink;
};
#ifndef JSON_NO_IO
template<typename CharType>
class output_stream_adapter : public output_adapter_protocol<CharType>
{
  public:
    explicit output_stream_adapter(std::basic_ostream<CharType>& s) noexcept
        : stream(s)
    {}
    void write_character(CharType c) override
    {
        stream.put(c);
    }
    void write_characters(const CharType* s, std::size_t length) override
    {
        stream.write(s, static_cast<std::streamsize>(length));
    }
  private:
    std::basic_ostream<CharType>& stream;
};
#endif  
template<typename CharType, typename StringType = std::basic_string<CharType>>
class output_string_adapter : public output_adapter_protocol<CharType>
{
  public:
    explicit output_string_adapter(StringType& s) noexcept
        : str(s)
    {}
    void write_character(CharType c) override
    {
        str.push_back(c);
    }
    void write_characters(const CharType* s, std::size_t length) override
    {
        str.append(s, length);
    }
  private:
    StringType& str;
};
template<typename CharType>
class output_adapter_sink
{
  public:
    explicit output_adapter_sink(output_adapter_t<CharType> adapter)
        : oa(std::move(adapter))
    {
        JSON_ASSERT(oa);
    }
    void write_character(CharType c)
    {
        oa->write_character(c);
    }
    void write_characters(const CharType* s, std::size_t length)
    {
        oa->write_characters(s, length);
    }
  private:
    output_adapter_t<CharType> oa;
};
template<typename CharType>
struct is_output_adapter_string_char_type : std::integral_constant < bool,
    std::is_same<CharType, char>::value ||
    std::is_same<CharType, wchar_t>::value ||
    std::is_same<CharType, char16_t>::value ||
    std::is_same<CharType, char32_t>::value
#if defined(__cpp_lib_char8_t) && (__cpp_lib_char8_t >= 201907L)
    || std::is_same<CharType, char8_t>::value
#endif
    > {};
template<typename CharType>
struct output_adapter_no_string_type {};
template<typename CharType, bool = is_output_adapter_string_char_type<CharType>::value>
struct output_adapter_default_string_type
{
    using type = output_adapter_no_string_type<CharType>;
};
template<typename CharType>
struct output_adapter_default_string_type<CharType, true>
{
    using type = std::basic_string<CharType>;
};
#ifndef JSON_NO_IO
template<typename CharType>
struct output_adapter_no_ostream_type {};
template<typename CharType, bool = is_output_adapter_string_char_type<CharType>::value>
struct output_adapter_ostream_type
{
    using type = output_adapter_no_ostream_type<CharType>;
};
template<typename CharType>
struct output_adapter_ostream_type<CharType, true>
{
    using type = std::basic_ostream<CharType>;
};
#endif  
template < typename CharType, typename StringType =
           typename output_adapter_default_string_type<CharType>::type >
class output_adapter
{
  public:
    template<typename AllocatorType = std::allocator<CharType>>
    output_adapter(std::vector<CharType, AllocatorType>& vec)
        : oa(std::make_shared<output_vector_adapter<CharType, AllocatorType>>(vec)) {}
#ifndef JSON_NO_IO
    output_adapter(typename output_adapter_ostream_type<CharType>::type& s)
        : oa(std::make_shared<output_stream_adapter<CharType>>(s)) {}
#endif  
    output_adapter(StringType& s)
        : oa(std::make_shared<output_string_adapter<CharType, StringType>>(s)) {}
    operator output_adapter_t<CharType>()
    {
        return oa;
    }
  private:
    output_adapter_t<CharType> oa = nullptr;
};
}  
NLOHMANN_JSON_NAMESPACE_END
NLOHMANN_JSON_NAMESPACE_BEGIN
namespace detail
{
enum class bjdata_version_t
{
    draft2,
    draft3,
};
template<typename BasicJsonType>
std::size_t binary_reserve_hint(const BasicJsonType& j)
{
    if (j.is_array())
    {
        return j.size() + 1;
    }
    if (j.is_object())
    {
        return (j.size() * 2) + 1;
    }
    return 0;
}
template<typename BasicJsonType, typename CharType, typename OutputSinkType = output_adapter_sink<CharType>>
class binary_writer
{
    using string_t = typename BasicJsonType::string_t;
    using binary_t = typename BasicJsonType::binary_t;
    using number_float_t = typename BasicJsonType::number_float_t;
  public:
    explicit binary_writer(OutputSinkType sink) : oa(std::move(sink))
    {}
    template < typename SinkType = OutputSinkType,
               typename std::enable_if < std::is_constructible<SinkType, output_adapter_t<CharType>>::value, int >::type = 0 >
    explicit binary_writer(output_adapter_t<CharType> adapter) : oa(SinkType(std::move(adapter)))
    {}
    void write_bson(const BasicJsonType& j)
    {
        switch (j.type())
        {
            case value_t::object:
            {
                write_bson_document(j);
                break;
            }
            case value_t::null:
            case value_t::array:
            case value_t::string:
            case value_t::boolean:
            case value_t::number_integer:
            case value_t::number_unsigned:
            case value_t::number_float:
            case value_t::binary:
            case value_t::discarded:
            default:
            {
                JSON_THROW(type_error::create(317, concat("to serialize to BSON, top-level type must be object, but is ", j.type_name()), &j));
            }
        }
    }
    void write_cbor(const BasicJsonType& j)
    {
        switch (j.type())
        {
            case value_t::null:
            {
                oa.write_character(to_char_type(0xF6));
                break;
            }
            case value_t::boolean:
            {
                oa.write_character(j.m_data.m_value.boolean
                                   ? to_char_type(0xF5)
                                   : to_char_type(0xF4));
                break;
            }
            case value_t::number_integer:
            {
                if (j.m_data.m_value.number_integer >= 0)
                {
                    write_cbor_head(0x00, static_cast<std::uint64_t>(j.m_data.m_value.number_integer));
                }
                else
                {
                    write_cbor_head(0x20, static_cast<std::uint64_t>(-1 - j.m_data.m_value.number_integer));
                }
                break;
            }
            case value_t::number_unsigned:
            {
                write_cbor_head(0x00, j.m_data.m_value.number_unsigned);
                break;
            }
            case value_t::number_float:
            {
                if (std::isnan(j.m_data.m_value.number_float))
                {
                    oa.write_character(to_char_type(0xF9));
                    oa.write_character(to_char_type(0x7E));
                    oa.write_character(to_char_type(0x00));
                }
                else if (std::isinf(j.m_data.m_value.number_float))
                {
                    oa.write_character(to_char_type(0xf9));
                    oa.write_character(j.m_data.m_value.number_float > 0 ? to_char_type(0x7C) : to_char_type(0xFC));
                    oa.write_character(to_char_type(0x00));
                }
                else
                {
                    write_compact_float(j.m_data.m_value.number_float, to_char_type(0xFA), to_char_type(0xFB));
                }
                break;
            }
            case value_t::string:
            {
                write_cbor_head(0x60, j.m_data.m_value.string->size());
                oa.write_characters(
                      reinterpret_cast<const CharType*>(j.m_data.m_value.string->data()),
                      j.m_data.m_value.string->size());
                break;
            }
            case value_t::array:
            {
                write_cbor_head(0x80, j.m_data.m_value.array->size());
                for (const auto& el : *j.m_data.m_value.array)
                {
                    write_cbor(el);
                }
                break;
            }
            case value_t::binary:
            {
                if (j.m_data.m_value.binary->has_subtype())
                {
                    if (j.m_data.m_value.binary->subtype() <= (std::numeric_limits<std::uint8_t>::max)())
                    {
                        write_number(static_cast<std::uint8_t>(0xd8));
                        write_number(static_cast<std::uint8_t>(j.m_data.m_value.binary->subtype()));
                    }
                    else if (j.m_data.m_value.binary->subtype() <= (std::numeric_limits<std::uint16_t>::max)())
                    {
                        write_number(static_cast<std::uint8_t>(0xd9));
                        write_number(static_cast<std::uint16_t>(j.m_data.m_value.binary->subtype()));
                    }
                    else if (j.m_data.m_value.binary->subtype() <= (std::numeric_limits<std::uint32_t>::max)())
                    {
                        write_number(static_cast<std::uint8_t>(0xda));
                        write_number(static_cast<std::uint32_t>(j.m_data.m_value.binary->subtype()));
                    }
                    else
                    {
                        write_number(static_cast<std::uint8_t>(0xdb));
                        write_number(static_cast<std::uint64_t>(j.m_data.m_value.binary->subtype()));
                    }
                }
                const auto N = j.m_data.m_value.binary->size();
                write_cbor_head(0x40, N);
                oa.write_characters(
                      reinterpret_cast<const CharType*>(j.m_data.m_value.binary->data()),
                      N);
                break;
            }
            case value_t::object:
            {
                write_cbor_head(0xA0, j.m_data.m_value.object->size());
                for (const auto& el : *j.m_data.m_value.object)
                {
                    write_cbor(el.first);
                    write_cbor(el.second);
                }
                break;
            }
            case value_t::discarded:
            default:
                break;
        }
    }
    static std::uint32_t to_msgpack_length(const std::size_t length, const BasicJsonType& j)
    {
        if (JSON_HEDLEY_UNLIKELY(!value_in_range_of<std::uint32_t>(length)))
        {
            JSON_THROW(out_of_range::create(412, concat("MessagePack length ", std::to_string(length), " exceeds maximum of ", std::to_string((std::numeric_limits<std::uint32_t>::max)())), &j));
        }
        static_cast<void>(j);
        return static_cast<std::uint32_t>(length);
    }
    void write_msgpack_unsigned(const std::uint64_t n)
    {
        if (n < 128)
        {
            write_number(static_cast<std::uint8_t>(n));
        }
        else if (n <= (std::numeric_limits<std::uint8_t>::max)())
        {
            oa.write_character(to_char_type(0xCC));
            write_number(static_cast<std::uint8_t>(n));
        }
        else if (n <= (std::numeric_limits<std::uint16_t>::max)())
        {
            oa.write_character(to_char_type(0xCD));
            write_number(static_cast<std::uint16_t>(n));
        }
        else if (n <= (std::numeric_limits<std::uint32_t>::max)())
        {
            oa.write_character(to_char_type(0xCE));
            write_number(static_cast<std::uint32_t>(n));
        }
        else
        {
            oa.write_character(to_char_type(0xCF));
            write_number(n);
        }
    }
    void write_msgpack(const BasicJsonType& j)
    {
        switch (j.type())
        {
            case value_t::null: 
            {
                oa.write_character(to_char_type(0xC0));
                break;
            }
            case value_t::boolean: 
            {
                oa.write_character(j.m_data.m_value.boolean
                                   ? to_char_type(0xC3)
                                   : to_char_type(0xC2));
                break;
            }
            case value_t::number_integer:
            {
                if (j.m_data.m_value.number_integer >= 0)
                {
                    write_msgpack_unsigned(static_cast<std::uint64_t>(j.m_data.m_value.number_integer));
                }
                else
                {
                    if (j.m_data.m_value.number_integer >= -32)
                    {
                        write_number(static_cast<std::int8_t>(j.m_data.m_value.number_integer));
                    }
                    else if (j.m_data.m_value.number_integer >= (std::numeric_limits<std::int8_t>::min)() &&
                             j.m_data.m_value.number_integer <= (std::numeric_limits<std::int8_t>::max)())
                    {
                        oa.write_character(to_char_type(0xD0));
                        write_number(static_cast<std::int8_t>(j.m_data.m_value.number_integer));
                    }
                    else if (j.m_data.m_value.number_integer >= (std::numeric_limits<std::int16_t>::min)() &&
                             j.m_data.m_value.number_integer <= (std::numeric_limits<std::int16_t>::max)())
                    {
                        oa.write_character(to_char_type(0xD1));
                        write_number(static_cast<std::int16_t>(j.m_data.m_value.number_integer));
                    }
                    else if (j.m_data.m_value.number_integer >= (std::numeric_limits<std::int32_t>::min)() &&
                             j.m_data.m_value.number_integer <= (std::numeric_limits<std::int32_t>::max)())
                    {
                        oa.write_character(to_char_type(0xD2));
                        write_number(static_cast<std::int32_t>(j.m_data.m_value.number_integer));
                    }
                    else
                    {
                        oa.write_character(to_char_type(0xD3));
                        write_number(static_cast<std::int64_t>(j.m_data.m_value.number_integer));
                    }
                }
                break;
            }
            case value_t::number_unsigned:
            {
                write_msgpack_unsigned(static_cast<std::uint64_t>(j.m_data.m_value.number_unsigned));
                break;
            }
            case value_t::number_float:
            {
                write_compact_float(j.m_data.m_value.number_float, to_char_type(0xCA), to_char_type(0xCB));
                break;
            }
            case value_t::string:
            {
                const auto N = to_msgpack_length(j.m_data.m_value.string->size(), j);
                if (N <= 31)
                {
                    write_number(static_cast<std::uint8_t>(0xA0 | N));
                }
                else if (N <= (std::numeric_limits<std::uint8_t>::max)())
                {
                    oa.write_character(to_char_type(0xD9));
                    write_number(static_cast<std::uint8_t>(N));
                }
                else if (N <= (std::numeric_limits<std::uint16_t>::max)())
                {
                    oa.write_character(to_char_type(0xDA));
                    write_number(static_cast<std::uint16_t>(N));
                }
                else
                {
                    oa.write_character(to_char_type(0xDB));
                    write_number(static_cast<std::uint32_t>(N));
                }
                oa.write_characters(
                      reinterpret_cast<const CharType*>(j.m_data.m_value.string->data()),
                      j.m_data.m_value.string->size());
                break;
            }
            case value_t::array:
            {
                const auto N = to_msgpack_length(j.m_data.m_value.array->size(), j);
                if (N <= 15)
                {
                    write_number(static_cast<std::uint8_t>(0x90 | N));
                }
                else if (N <= (std::numeric_limits<std::uint16_t>::max)())
                {
                    oa.write_character(to_char_type(0xDC));
                    write_number(static_cast<std::uint16_t>(N));
                }
                else
                {
                    oa.write_character(to_char_type(0xDD));
                    write_number(static_cast<std::uint32_t>(N));
                }
                for (const auto& el : *j.m_data.m_value.array)
                {
                    write_msgpack(el);
                }
                break;
            }
            case value_t::binary:
            {
                const bool use_ext = j.m_data.m_value.binary->has_subtype();
                const auto N = to_msgpack_length(j.m_data.m_value.binary->size(), j);
                if (N <= (std::numeric_limits<std::uint8_t>::max)())
                {
                    std::uint8_t output_type{};
                    bool fixed = true;
                    if (use_ext)
                    {
                        switch (N)
                        {
                            case 1:
                                output_type = 0xD4; 
                                break;
                            case 2:
                                output_type = 0xD5; 
                                break;
                            case 4:
                                output_type = 0xD6; 
                                break;
                            case 8:
                                output_type = 0xD7; 
                                break;
                            case 16:
                                output_type = 0xD8; 
                                break;
                            default:
                                output_type = 0xC7; 
                                fixed = false;
                                break;
                        }
                    }
                    else
                    {
                        output_type = 0xC4; 
                        fixed = false;
                    }
                    oa.write_character(to_char_type(output_type));
                    if (!fixed)
                    {
                        write_number(static_cast<std::uint8_t>(N));
                    }
                }
                else if (N <= (std::numeric_limits<std::uint16_t>::max)())
                {
                    const std::uint8_t output_type = use_ext
                                                     ? 0xC8 
                                                     : 0xC5; 
                    oa.write_character(to_char_type(output_type));
                    write_number(static_cast<std::uint16_t>(N));
                }
                else
                {
                    const std::uint8_t output_type = use_ext
                                                     ? 0xC9 
                                                     : 0xC6; 
                    oa.write_character(to_char_type(output_type));
                    write_number(static_cast<std::uint32_t>(N));
                }
                if (use_ext)
                {
                    if (JSON_HEDLEY_UNLIKELY(j.m_data.m_value.binary->subtype() > (std::numeric_limits<std::uint8_t>::max)()))
                    {
                        JSON_THROW(out_of_range::create(415, concat("subtype ", std::to_string(j.m_data.m_value.binary->subtype()), " is too large for the MessagePack ext type (max 255)"), &j));
                    }
                    write_number(static_cast<std::int8_t>(j.m_data.m_value.binary->subtype()));
                }
                oa.write_characters(
                      reinterpret_cast<const CharType*>(j.m_data.m_value.binary->data()),
                      N);
                break;
            }
            case value_t::object:
            {
                const auto N = to_msgpack_length(j.m_data.m_value.object->size(), j);
                if (N <= 15)
                {
                    write_number(static_cast<std::uint8_t>(0x80 | (N & 0xF)));
                }
                else if (N <= (std::numeric_limits<std::uint16_t>::max)())
                {
                    oa.write_character(to_char_type(0xDE));
                    write_number(static_cast<std::uint16_t>(N));
                }
                else
                {
                    oa.write_character(to_char_type(0xDF));
                    write_number(static_cast<std::uint32_t>(N));
                }
                for (const auto& el : *j.m_data.m_value.object)
                {
                    write_msgpack(el.first);
                    write_msgpack(el.second);
                }
                break;
            }
            case value_t::discarded:
            default:
                break;
        }
    }
    void write_ubjson(const BasicJsonType& j, const bool use_count,
                      const bool use_type, const bool add_prefix = true,
                      const bool use_bjdata = false, const bjdata_version_t bjdata_version = bjdata_version_t::draft2)
    {
        const bool bjdata_draft3 = use_bjdata && bjdata_version == bjdata_version_t::draft3;
        switch (j.type())
        {
            case value_t::null:
            {
                if (add_prefix)
                {
                    oa.write_character(to_char_type('Z'));
                }
                break;
            }
            case value_t::boolean:
            {
                if (add_prefix)
                {
                    oa.write_character(j.m_data.m_value.boolean
                                       ? to_char_type('T')
                                       : to_char_type('F'));
                }
                break;
            }
            case value_t::number_integer:
            {
                write_number_with_ubjson_prefix(j.m_data.m_value.number_integer, add_prefix, use_bjdata);
                break;
            }
            case value_t::number_unsigned:
            {
                write_number_with_ubjson_prefix(j.m_data.m_value.number_unsigned, add_prefix, use_bjdata);
                break;
            }
            case value_t::number_float:
            {
                write_number_with_ubjson_prefix(j.m_data.m_value.number_float, add_prefix, use_bjdata);
                break;
            }
            case value_t::string:
            {
                if (add_prefix)
                {
                    oa.write_character(to_char_type('S'));
                }
                write_number_with_ubjson_prefix(j.m_data.m_value.string->size(), true, use_bjdata);
                oa.write_characters(
                      reinterpret_cast<const CharType*>(j.m_data.m_value.string->data()),
                      j.m_data.m_value.string->size());
                break;
            }
            case value_t::array:
            {
                if (add_prefix)
                {
                    oa.write_character(to_char_type('['));
                }
                bool prefix_required = true;
                if (use_type && !j.m_data.m_value.array->empty())
                {
                    if (!use_count)
                    {
                        JSON_THROW(other_error::create(502, "use_type requires use_size = true", &j));
                    }
                    const CharType first_prefix = ubjson_prefix(j.front(), use_bjdata);
                    const bool same_prefix = std::all_of(j.begin() + 1, j.end(),
                                                         [this, first_prefix, use_bjdata](const BasicJsonType & v)
                    {
                        return ubjson_prefix(v, use_bjdata) == first_prefix;
                    });
                    const bool valueless_type = (first_prefix == 'Z' || first_prefix == 'T' || first_prefix == 'F');
                    const bool excessive_valueless = valueless_type
                                                     && j.m_data.m_value.array->size() > detail::max_valueless_container_size;
                    if (same_prefix && !excessive_valueless
                            && !(use_bjdata && is_bjdata_excluded_type_marker(first_prefix)))
                    {
                        prefix_required = false;
                        oa.write_character(to_char_type('$'));
                        oa.write_character(first_prefix);
                    }
                }
                if (use_count)
                {
                    oa.write_character(to_char_type('#'));
                    write_number_with_ubjson_prefix(j.m_data.m_value.array->size(), true, use_bjdata);
                }
                for (const auto& el : *j.m_data.m_value.array)
                {
                    write_ubjson(el, use_count, use_type, prefix_required, use_bjdata, bjdata_version);
                }
                if (!use_count)
                {
                    oa.write_character(to_char_type(']'));
                }
                break;
            }
            case value_t::binary:
            {
                if (add_prefix)
                {
                    oa.write_character(to_char_type('['));
                }
                if (use_type && (bjdata_draft3 || !j.m_data.m_value.binary->empty()))
                {
                    if (!use_count)
                    {
                        JSON_THROW(other_error::create(502, "use_type requires use_size = true", &j));
                    }
                    oa.write_character(to_char_type('$'));
                    oa.write_character(bjdata_draft3 ? 'B' : 'U');
                }
                if (use_count)
                {
                    oa.write_character(to_char_type('#'));
                    write_number_with_ubjson_prefix(j.m_data.m_value.binary->size(), true, use_bjdata);
                }
                if (use_type)
                {
                    oa.write_characters(
                          reinterpret_cast<const CharType*>(j.m_data.m_value.binary->data()),
                          j.m_data.m_value.binary->size());
                }
                else
                {
                    for (size_t i = 0; i < j.m_data.m_value.binary->size(); ++i)
                    {
                        oa.write_character(to_char_type(bjdata_draft3 ? 'B' : 'U'));
                        oa.write_character(to_char_type(static_cast<std::uint8_t>(j.m_data.m_value.binary->data()[i])));
                    }
                }
                if (!use_count)
                {
                    oa.write_character(to_char_type(']'));
                }
                break;
            }
            case value_t::object:
            {
                if (use_bjdata && j.m_data.m_value.object->size() == 3 && j.m_data.m_value.object->find("_ArrayType_") != j.m_data.m_value.object->end() && j.m_data.m_value.object->find("_ArraySize_") != j.m_data.m_value.object->end() && j.m_data.m_value.object->find("_ArrayData_") != j.m_data.m_value.object->end())
                {
                    if (!write_bjdata_ndarray(*j.m_data.m_value.object, use_count, use_type, bjdata_version))  
                    {
                        break;
                    }
                }
                if (add_prefix)
                {
                    oa.write_character(to_char_type('{'));
                }
                bool prefix_required = true;
                if (use_type && !j.m_data.m_value.object->empty())
                {
                    if (!use_count)
                    {
                        JSON_THROW(other_error::create(502, "use_type requires use_size = true", &j));
                    }
                    const CharType first_prefix = ubjson_prefix(j.front(), use_bjdata);
                    const bool same_prefix = std::all_of(j.begin(), j.end(),
                                                         [this, first_prefix, use_bjdata](const BasicJsonType & v)
                    {
                        return ubjson_prefix(v, use_bjdata) == first_prefix;
                    });
                    if (same_prefix && !(use_bjdata && is_bjdata_excluded_type_marker(first_prefix)))
                    {
                        prefix_required = false;
                        oa.write_character(to_char_type('$'));
                        oa.write_character(first_prefix);
                    }
                }
                if (use_count)
                {
                    oa.write_character(to_char_type('#'));
                    write_number_with_ubjson_prefix(j.m_data.m_value.object->size(), true, use_bjdata);
                }
                for (const auto& el : *j.m_data.m_value.object)
                {
                    write_number_with_ubjson_prefix(el.first.size(), true, use_bjdata);
                    oa.write_characters(
                          reinterpret_cast<const CharType*>(el.first.data()),
                          el.first.size());
                    write_ubjson(el.second, use_count, use_type, prefix_required, use_bjdata, bjdata_version);
                }
                if (!use_count)
                {
                    oa.write_character(to_char_type('}'));
                }
                break;
            }
            case value_t::discarded:
            default:
                break;
        }
    }
    void write_bon8(const BasicJsonType& j)
    {
        bool string_open = false;
        write_bon8_value(j, string_open);
        if (string_open)
        {
            oa.write_character(to_char_type(0xFF));
        }
    }
  private:
    static std::size_t calc_bson_entry_header_size(const string_t& name, const BasicJsonType& j)
    {
        const auto it = name.find(static_cast<typename string_t::value_type>(0));
        if (JSON_HEDLEY_UNLIKELY(it != BasicJsonType::string_t::npos))
        {
            JSON_THROW(out_of_range::create(409, concat("BSON key cannot contain code point U+0000 (at byte ", std::to_string(it), ")"), &j));
        }
        static_cast<void>(j);
        return  1ul + name.size() + 1u;
    }
    static std::int32_t to_bson_length(const std::size_t size)
    {
        if (JSON_HEDLEY_UNLIKELY(!value_in_range_of<std::int32_t>(size)))
        {
            JSON_THROW(out_of_range::create(412, concat("BSON length ", std::to_string(size), " exceeds maximum of ", std::to_string((std::numeric_limits<std::int32_t>::max)())), nullptr));
        }
        return static_cast<std::int32_t>(size);
    }
    void write_bson_entry_header(const string_t& name,
                                 const std::uint8_t element_type)
    {
        oa.write_character(to_char_type(element_type));
        oa.write_characters(
              reinterpret_cast<const CharType*>(name.data()),
              name.size());
        oa.write_character(to_char_type(0x00));
    }
    void write_bson_boolean(const string_t& name,
                            const bool value)
    {
        write_bson_entry_header(name, 0x08);
        oa.write_character(value ? to_char_type(0x01) : to_char_type(0x00));
    }
    void write_bson_double(const string_t& name,
                           const double value)
    {
        write_bson_entry_header(name, 0x01);
        write_number<double>(value, true);
    }
    static std::size_t calc_bson_string_size(const string_t& value)
    {
        return sizeof(std::int32_t) + value.size() + 1ul;
    }
    void write_bson_string(const string_t& name,
                           const string_t& value)
    {
        write_bson_entry_header(name, 0x02);
        write_number<std::int32_t>(to_bson_length(value.size() + 1ul), true);
        oa.write_characters(
              reinterpret_cast<const CharType*>(value.data()),
              value.size());
        oa.write_character(to_char_type(0x00));
    }
    void write_bson_null(const string_t& name)
    {
        write_bson_entry_header(name, 0x0A);
    }
    static std::size_t calc_bson_integer_size(const std::int64_t value)
    {
        return (std::numeric_limits<std::int32_t>::min)() <= value && value <= (std::numeric_limits<std::int32_t>::max)()
               ? sizeof(std::int32_t)
               : sizeof(std::int64_t);
    }
    void write_bson_integer(const string_t& name,
                            const std::int64_t value)
    {
        if ((std::numeric_limits<std::int32_t>::min)() <= value && value <= (std::numeric_limits<std::int32_t>::max)())
        {
            write_bson_entry_header(name, 0x10); 
            write_number<std::int32_t>(static_cast<std::int32_t>(value), true);
        }
        else
        {
            write_bson_entry_header(name, 0x12); 
            write_number<std::int64_t>(static_cast<std::int64_t>(value), true);
        }
    }
    static constexpr std::size_t calc_bson_unsigned_size(const std::uint64_t value) noexcept
    {
        return (value <= static_cast<std::uint64_t>((std::numeric_limits<std::int32_t>::max)()))
               ? sizeof(std::int32_t)
               : sizeof(std::int64_t);
    }
    void write_bson_unsigned(const string_t& name,
                             const std::uint64_t value)
    {
        if (value <= static_cast<std::uint64_t>((std::numeric_limits<std::int32_t>::max)()))
        {
            write_bson_entry_header(name, 0x10 );
            write_number<std::int32_t>(static_cast<std::int32_t>(value), true);
        }
        else if (value <= static_cast<std::uint64_t>((std::numeric_limits<std::int64_t>::max)()))
        {
            write_bson_entry_header(name, 0x12 );
            write_number<std::int64_t>(static_cast<std::int64_t>(value), true);
        }
        else
        {
            write_bson_entry_header(name, 0x11 );
            write_number<std::uint64_t>(value, true);
        }
    }
    static std::size_t calc_bson_binary_size(const BasicJsonType& j)
    {
        const auto& value = *j.m_data.m_value.binary;
        if (value.has_subtype() && JSON_HEDLEY_UNLIKELY(value.subtype() > (std::numeric_limits<std::uint8_t>::max)()))
        {
            JSON_THROW(out_of_range::create(415, concat("subtype ", std::to_string(value.subtype()), " is too large for the BSON binary subtype (max 255)"), &j));
        }
        return sizeof(std::int32_t) + value.size() + 1ul;
    }
    void write_bson_binary(const string_t& name,
                           const binary_t& value)
    {
        write_bson_entry_header(name, 0x05);
        write_number<std::int32_t>(to_bson_length(value.size()), true);
        write_number(value.has_subtype() ? static_cast<std::uint8_t>(value.subtype()) : static_cast<std::uint8_t>(0x00));
        oa.write_characters(reinterpret_cast<const CharType*>(value.data()), value.size());
    }
    static std::size_t calc_bson_value_size(const BasicJsonType& j)
    {
        switch (j.type())
        {
            case value_t::binary:
                return calc_bson_binary_size(j);
            case value_t::boolean:
                return 1ul;
            case value_t::number_float:
                return 8ul;
            case value_t::number_integer:
                return calc_bson_integer_size(j.m_data.m_value.number_integer);
            case value_t::number_unsigned:
                return calc_bson_unsigned_size(j.m_data.m_value.number_unsigned);
            case value_t::string:
                return calc_bson_string_size(*j.m_data.m_value.string);
            case value_t::null:
                return 0ul;
            case value_t::object:
            case value_t::array:
            case value_t::discarded:
            default:
                JSON_ASSERT(false); 
                return 0ul;
        }
    }
    void write_bson_value(const string_t& name, const BasicJsonType& j)
    {
        switch (j.type())
        {
            case value_t::binary:
                return write_bson_binary(name, *j.m_data.m_value.binary);
            case value_t::boolean:
                return write_bson_boolean(name, j.m_data.m_value.boolean);
            case value_t::number_float:
                return write_bson_double(name, j.m_data.m_value.number_float);
            case value_t::number_integer:
                return write_bson_integer(name, j.m_data.m_value.number_integer);
            case value_t::number_unsigned:
                return write_bson_unsigned(name, j.m_data.m_value.number_unsigned);
            case value_t::string:
                return write_bson_string(name, *j.m_data.m_value.string);
            case value_t::null:
                return write_bson_null(name);
            case value_t::object:
            case value_t::array:
            case value_t::discarded:
            default:
                JSON_ASSERT(false); 
                return;
        }
    }
    struct bson_frame
    {
        explicit bson_frame(const BasicJsonType* value_, const std::size_t size_slot_ = 0)
            : value(value_)
            , size_slot(size_slot_)
        {
            if (value->is_object())
            {
                member = value->m_data.m_value.object->cbegin();
            }
        }
        const BasicJsonType* value;
        typename BasicJsonType::object_t::const_iterator member{};
        std::size_t index = 0;
        std::size_t size_slot;
        std::size_t entries_size = 0;
    };
    static void create_bson_index_name(const std::size_t index, string_t& name)
    {
        const auto key = std::to_string(index);
        name = string_t(key.data(), key.size());
    }
    static std::size_t calc_bson_sizes(const BasicJsonType& document, std::vector<std::size_t>& nested_sizes)
    {
        bson_frame current(&document);
        std::vector<bson_frame> parents;
        string_t index_name("", 0);
        while (true)
        {
            const BasicJsonType* nested = nullptr;
            if (current.value->is_object())
            {
                const auto& object = *current.value->m_data.m_value.object;
                while (nested == nullptr && current.member != object.cend())
                {
                    const auto& el = *current.member;
                    ++current.member;
                    current.entries_size += calc_bson_entry_header_size(el.first, el.second);
                    if (el.second.is_structured())
                    {
                        nested = &el.second;
                    }
                    else
                    {
                        current.entries_size += calc_bson_value_size(el.second);
                    }
                }
            }
            else
            {
                const auto& array = *current.value->m_data.m_value.array;
                while (nested == nullptr && current.index < array.size())
                {
                    const BasicJsonType& el = array[current.index];
                    create_bson_index_name(current.index, index_name);
                    current.entries_size += calc_bson_entry_header_size(index_name, el);
                    ++current.index;
                    if (el.is_structured())
                    {
                        nested = &el;
                    }
                    else
                    {
                        current.entries_size += calc_bson_value_size(el);
                    }
                }
            }
            if (nested != nullptr)
            {
                nested_sizes.push_back(0);
                parents.push_back(std::move(current));
                current = bson_frame(nested, nested_sizes.size() - 1);
                continue;
            }
            const std::size_t size = sizeof(std::int32_t) + current.entries_size + 1ul;
            if (parents.empty())
            {
                return size;
            }
            nested_sizes[current.size_slot] = size;
            current = std::move(parents.back());
            parents.pop_back();
            current.entries_size += size;
        }
    }
    void write_bson_document(const BasicJsonType& document)
    {
        std::vector<std::size_t> nested_sizes;
        const std::size_t document_size = calc_bson_sizes(document, nested_sizes);
        write_number<std::int32_t>(to_bson_length(document_size), true);
        bson_frame current(&document);
        std::vector<bson_frame> parents;
        std::size_t next_size = 0;
        string_t index_name("", 0);
        while (true)
        {
            const string_t* nested_name = nullptr;
            const BasicJsonType* nested = nullptr;
            if (current.value->is_object())
            {
                const auto& object = *current.value->m_data.m_value.object;
                while (nested == nullptr && current.member != object.cend())
                {
                    const auto& el = *current.member;
                    ++current.member;
                    if (el.second.is_structured())
                    {
                        nested_name = &el.first;
                        nested = &el.second;
                    }
                    else
                    {
                        write_bson_value(el.first, el.second);
                    }
                }
            }
            else
            {
                const auto& array = *current.value->m_data.m_value.array;
                while (nested == nullptr && current.index < array.size())
                {
                    const BasicJsonType& el = array[current.index];
                    create_bson_index_name(current.index, index_name);
                    ++current.index;
                    if (el.is_structured())
                    {
                        nested_name = &index_name;
                        nested = &el;
                    }
                    else
                    {
                        write_bson_value(index_name, el);
                    }
                }
            }
            if (nested != nullptr)
            {
                write_bson_entry_header(*nested_name, nested->is_object() ? 0x03 : 0x04);
                write_number<std::int32_t>(to_bson_length(nested_sizes[next_size++]), true);
                parents.push_back(std::move(current));
                current = bson_frame(nested);
                continue;
            }
            oa.write_character(to_char_type(0x00));
            if (parents.empty())
            {
                JSON_ASSERT(next_size == nested_sizes.size());
                return;
            }
            current = std::move(parents.back());
            parents.pop_back();
        }
    }
    void write_cbor_head(const std::uint8_t major_type, const std::uint64_t argument)
    {
        if (argument <= 0x17)
        {
            write_number(static_cast<std::uint8_t>(major_type + argument));
        }
        else if (argument <= (std::numeric_limits<std::uint8_t>::max)())
        {
            oa.write_character(to_char_type(static_cast<std::uint8_t>(major_type + 0x18)));
            write_number(static_cast<std::uint8_t>(argument));
        }
        else if (argument <= (std::numeric_limits<std::uint16_t>::max)())
        {
            oa.write_character(to_char_type(static_cast<std::uint8_t>(major_type + 0x19)));
            write_number(static_cast<std::uint16_t>(argument));
        }
        else if (argument <= (std::numeric_limits<std::uint32_t>::max)())
        {
            oa.write_character(to_char_type(static_cast<std::uint8_t>(major_type + 0x1A)));
            write_number(static_cast<std::uint32_t>(argument));
        }
        else
        {
            oa.write_character(to_char_type(static_cast<std::uint8_t>(major_type + 0x1B)));
            write_number(argument);
        }
    }
    template<typename NumberType, typename std::enable_if<
                 std::is_floating_point<NumberType>::value, int>::type = 0>
    void write_number_with_ubjson_prefix(const NumberType n,
                                         const bool add_prefix,
                                         const bool use_bjdata)
    {
        if (add_prefix)
        {
            oa.write_character(get_ubjson_float_prefix<NumberType>());
        }
        write_number(n, use_bjdata);
    }
    template<typename NumberType, typename std::enable_if<
                 std::is_integral<NumberType>::value, int>::type = 0>
    void write_number_with_ubjson_prefix(const NumberType n,
                                         const bool add_prefix,
                                         const bool use_bjdata)
    {
        const CharType prefix = ubjson_integer_prefix(n, use_bjdata);
        if (add_prefix)
        {
            oa.write_character(prefix);
        }
        write_ubjson_integer_payload(prefix, n, use_bjdata);
    }
    template<typename NumberType>
    static CharType ubjson_integer_prefix(const NumberType n, const bool use_bjdata) noexcept
    {
        if (value_in_range_of<std::int8_t>(n))
        {
            return 'i';
        }
        if (value_in_range_of<std::uint8_t>(n))
        {
            return 'U';
        }
        if (value_in_range_of<std::int16_t>(n))
        {
            return 'I';
        }
        if (use_bjdata && value_in_range_of<std::uint16_t>(n))
        {
            return 'u';
        }
        if (value_in_range_of<std::int32_t>(n))
        {
            return 'l';
        }
        if (use_bjdata && value_in_range_of<std::uint32_t>(n))
        {
            return 'm';
        }
        if (value_in_range_of<std::int64_t>(n))
        {
            return 'L';
        }
        if (use_bjdata && std::is_unsigned<NumberType>::value)
        {
            return 'M';
        }
        return 'H';
    }
    template<typename NumberType>
    void write_ubjson_integer_payload(const CharType prefix, const NumberType n, const bool use_bjdata)
    {
        switch (prefix)
        {
            case 'i':
                write_number(static_cast<std::int8_t>(n), use_bjdata);
                break;
            case 'U':
                write_number(static_cast<std::uint8_t>(n), use_bjdata);
                break;
            case 'I':
                write_number(static_cast<std::int16_t>(n), use_bjdata);
                break;
            case 'u':
                write_number(static_cast<std::uint16_t>(n), use_bjdata);
                break;
            case 'l':
                write_number(static_cast<std::int32_t>(n), use_bjdata);
                break;
            case 'm':
                write_number(static_cast<std::uint32_t>(n), use_bjdata);
                break;
            case 'L':
                write_number(static_cast<std::int64_t>(n), use_bjdata);
                break;
            case 'M':
                write_number(static_cast<std::uint64_t>(n), use_bjdata);
                break;
            default:
            {
                JSON_ASSERT(prefix == 'H');
                const auto number = BasicJsonType(n).dump();
                write_number_with_ubjson_prefix(number.size(), true, use_bjdata);
                for (std::size_t i = 0; i < number.size(); ++i)
                {
                    oa.write_character(to_char_type(static_cast<std::uint8_t>(number[i])));
                }
                break;
            }
        }
    }
    CharType ubjson_prefix(const BasicJsonType& j, const bool use_bjdata) const noexcept
    {
        switch (j.type())
        {
            case value_t::null:
                return 'Z';
            case value_t::boolean:
                return j.m_data.m_value.boolean ? 'T' : 'F';
            case value_t::number_integer:
                return ubjson_integer_prefix(j.m_data.m_value.number_integer, use_bjdata);
            case value_t::number_unsigned:
                return ubjson_integer_prefix(j.m_data.m_value.number_unsigned, use_bjdata);
            case value_t::number_float:
                return get_ubjson_float_prefix<number_float_t>();
            case value_t::string:
                return 'S';
            case value_t::array: 
            case value_t::binary:
                return '[';
            case value_t::object:
                return '{';
            case value_t::discarded:
            default:  
                return 'N';
        }
    }
    static constexpr bool is_bjdata_excluded_type_marker(const CharType marker) noexcept
    {
        return marker == '[' || marker == '{' || marker == 'S' || marker == 'H'
               || marker == 'T' || marker == 'F' || marker == 'N' || marker == 'Z';
    }
    template<typename FloatType>
    static constexpr CharType get_ubjson_float_prefix()
    {
        static_assert(std::is_same<FloatType, float>::value || std::is_same<FloatType, double>::value,
                      "number_float_t must be float or double for the UBJSON/BJData writer");
        return std::is_same<FloatType, float>::value ? 'd' : 'D';  
    }
    template<typename TargetType>
    static bool bjdata_ndarray_value_in_range(const BasicJsonType& el)
    {
        return el.is_number_unsigned()
               ? value_in_range_of<TargetType>(el.template get<std::uint64_t>())
               : value_in_range_of<TargetType>(el.template get<std::int64_t>());
    }
    static CharType bjdata_ndarray_type_marker(const string_t& name)
    {
        if (name == "uint8")
        {
            return 'U';
        }
        if (name == "int8")
        {
            return 'i';
        }
        if (name == "uint16")
        {
            return 'u';
        }
        if (name == "int16")
        {
            return 'I';
        }
        if (name == "uint32")
        {
            return 'm';
        }
        if (name == "int32")
        {
            return 'l';
        }
        if (name == "uint64")
        {
            return 'M';
        }
        if (name == "int64")
        {
            return 'L';
        }
        if (name == "single")
        {
            return 'd';
        }
        if (name == "double")
        {
            return 'D';
        }
        if (name == "char")
        {
            return 'C';
        }
        if (name == "byte")
        {
            return 'B';
        }
        return '\0';
    }
    template<typename T>
    bool write_bjdata_ndarray_element(const BasicJsonType& el, const bool dry_run)
    {
        if (dry_run)
        {
            return bjdata_ndarray_value_in_range<T>(el);
        }
        using storage_type = typename std::conditional<std::is_unsigned<T>::value, std::uint64_t, std::int64_t>::type;
        write_number(static_cast<T>(el.template get<storage_type>()), true);
        return true;
    }
    bool write_bjdata_ndarray_float_element(const BasicJsonType& el, const bool dry_run)
    {
        const auto dval = el.template get<double>();
        if (dry_run)
        {
            return !std::isfinite(dval) ||
                   (dval >= static_cast<double>(std::numeric_limits<float>::lowest()) &&
                    dval <= static_cast<double>((std::numeric_limits<float>::max)()));
        }
        write_number(static_cast<float>(dval), true);
        return true;
    }
    bool write_bjdata_ndarray_elements(const BasicJsonType& array_data, const CharType dtype, const bool dry_run)
    {
        for (const auto& el : array_data)
        {
            bool ok = true;
            switch (dtype)
            {
                case 'U':
                case 'C':
                case 'B':
                    ok = write_bjdata_ndarray_element<std::uint8_t>(el, dry_run);
                    break;
                case 'i':
                    ok = write_bjdata_ndarray_element<std::int8_t>(el, dry_run);
                    break;
                case 'u':
                    ok = write_bjdata_ndarray_element<std::uint16_t>(el, dry_run);
                    break;
                case 'I':
                    ok = write_bjdata_ndarray_element<std::int16_t>(el, dry_run);
                    break;
                case 'm':
                    ok = write_bjdata_ndarray_element<std::uint32_t>(el, dry_run);
                    break;
                case 'l':
                    ok = write_bjdata_ndarray_element<std::int32_t>(el, dry_run);
                    break;
                case 'M':
                    ok = write_bjdata_ndarray_element<std::uint64_t>(el, dry_run);
                    break;
                case 'L':
                    ok = write_bjdata_ndarray_element<std::int64_t>(el, dry_run);
                    break;
                case 'd':
                    ok = write_bjdata_ndarray_float_element(el, dry_run);
                    break;
                case 'D':
                default:
                    if (!dry_run)
                    {
                        write_number(el.template get<double>(), true);
                    }
                    break;
            }
            if (!ok)
            {
                return false;
            }
        }
        return true;
    }
    bool write_bjdata_ndarray(const typename BasicJsonType::object_t& value, const bool use_count, const bool use_type, const bjdata_version_t bjdata_version)
    {
        const auto& array_type = value.at("_ArrayType_");
        if (!array_type.is_string())
        {
            return true;
        }
        const CharType dtype = bjdata_ndarray_type_marker(array_type.template get<string_t>());
        if (dtype == '\0')
        {
            return true;
        }
        if (dtype == 'B' && bjdata_version < bjdata_version_t::draft3)
        {
            return true;
        }
        const auto& array_size = value.at("_ArraySize_");
        if (!array_size.is_array())
        {
            return true;
        }
        const auto& dims = array_size;
        if (dims.size() < 2 || (dims.size() == 2 && dims.at(0).is_number_integer() && dims.at(0).template get<std::int64_t>() == 1))
        {
            return true;
        }
        std::size_t len = 1;
        for (const auto& el : dims)
        {
            if (!el.is_number_integer() || (!el.is_number_unsigned() && el.template get<std::int64_t>() < 0))
            {
                return true;
            }
            const auto dim = el.template get<std::uint64_t>();
            if (!value_in_range_of<std::size_t>(dim))
            {
                return true;
            }
            const auto dim_size = static_cast<std::size_t>(dim);
            if (dim_size == 0)
            {
                return true;
            }
            if (len > (std::numeric_limits<std::size_t>::max)() / dim_size)
            {
                return true;
            }
            len *= dim_size;
        }
        const auto& array_data = value.at("_ArrayData_");
        if (!array_data.is_array() || array_data.size() != len)
        {
            return true;
        }
        const bool ndarray_is_float = (dtype == 'd' || dtype == 'D');
        for (const auto& el : array_data)
        {
            if (ndarray_is_float ? !el.is_number_float() : !el.is_number_integer())
            {
                return true;
            }
        }
        if (!write_bjdata_ndarray_elements(array_data, dtype, true))
        {
            return true;
        }
        oa.write_character(to_char_type('['));
        oa.write_character(to_char_type('$'));
        oa.write_character(dtype);
        oa.write_character(to_char_type('#'));
        write_ubjson(array_size, use_count, use_type, true,  true, bjdata_version);
        write_bjdata_ndarray_elements(array_data, dtype, false);
        return false;
    }
    void write_bon8_value(const BasicJsonType& j, bool& string_open)
    {
        switch (j.type())
        {
            case value_t::null:
            {
                write_bon8_marker(0xFA, string_open);
                break;
            }
            case value_t::boolean:
            {
                write_bon8_marker(j.m_data.m_value.boolean ? 0xF9 : 0xF8, string_open);
                break;
            }
            case value_t::number_unsigned:
            {
                if (j.m_data.m_value.number_unsigned > static_cast<typename BasicJsonType::number_unsigned_t>((std::numeric_limits<std::int64_t>::max)()))
                {
                    JSON_THROW(out_of_range::create(407, concat("integer number ", std::to_string(j.m_data.m_value.number_unsigned), " cannot be represented by BON8 as it does not fit int64"), &j));
                }
                write_bon8_integer(static_cast<std::int64_t>(j.m_data.m_value.number_unsigned));
                string_open = false;
                break;
            }
            case value_t::number_integer:
            {
                write_bon8_integer(static_cast<std::int64_t>(j.m_data.m_value.number_integer));
                string_open = false;
                break;
            }
            case value_t::number_float:
            {
                write_bon8_float(j.m_data.m_value.number_float);
                string_open = false;
                break;
            }
            case value_t::string:
            {
                write_bon8_string(*j.m_data.m_value.string, string_open, j);
                break;
            }
            case value_t::array:
            {
                const auto N = j.m_data.m_value.array->size();
                write_bon8_marker(static_cast<std::uint8_t>(N <= 4 ? 0x80 + N : 0x85), string_open);
                for (const auto& el : *j.m_data.m_value.array)
                {
                    write_bon8_value(el, string_open);
                }
                if (N > 4)
                {
                    write_bon8_marker(0xFE, string_open);
                }
                break;
            }
            case value_t::object:
            {
                const auto N = j.m_data.m_value.object->size();
                write_bon8_marker(static_cast<std::uint8_t>(N <= 4 ? 0x86 + N : 0x8B), string_open);
                for (const auto& el : *j.m_data.m_value.object)
                {
                    write_bon8_string(el.first, string_open, j);
                    write_bon8_value(el.second, string_open);
                }
                if (N > 4)
                {
                    write_bon8_marker(0xFE, string_open);
                }
                break;
            }
            case value_t::binary:
            {
                const auto N = j.m_data.m_value.binary->size();
                write_bon8_marker(static_cast<std::uint8_t>(N <= 4 ? 0x80 + N : 0x85), string_open);
                for (std::size_t i = 0; i < N; ++i)
                {
                    write_bon8_integer(static_cast<std::uint8_t>(j.m_data.m_value.binary->data()[i]));
                }
                if (N > 4)
                {
                    write_bon8_marker(0xFE, string_open);
                }
                break;
            }
            case value_t::discarded:
            default:
                break;
        }
    }
    void write_bon8_marker(const std::uint8_t marker, bool& string_open)
    {
        oa.write_character(to_char_type(marker));
        string_open = false;
    }
    void write_bon8_string(const string_t& s, bool& string_open, const BasicJsonType& context)
    {
        check_bon8_utf8(s, context);
        if (string_open)
        {
            oa.write_character(to_char_type(0xFF));
        }
        if (s.empty())
        {
            oa.write_character(to_char_type(0xFF));
            string_open = false;
        }
        else
        {
            oa.write_characters(reinterpret_cast<const CharType*>(s.data()), s.size());
            string_open = true;
        }
    }
    static void check_bon8_utf8(const string_t& s, const BasicJsonType& context)
    {
        static_cast<void>(context); 
        const auto* data = reinterpret_cast<const unsigned char*>(s.data());
        const std::size_t valid = valid_utf8_prefix(data, s.size());
        if (JSON_HEDLEY_UNLIKELY(valid != s.size()))
        {
            JSON_THROW(type_error::create(316, concat("invalid UTF-8 byte at index ", std::to_string(valid), ": 0x", detail::hex_byte(data[valid])), &context));
        }
    }
    void write_bon8_integer(std::int64_t value)
    {
        if (value < (std::numeric_limits<std::int32_t>::min)() || value > (std::numeric_limits<std::int32_t>::max)())
        {
            oa.write_character(to_char_type(0x8D));
            write_number(value);
        }
        else if (value < -33818506 || value > 67637031)
        {
            oa.write_character(to_char_type(0x8C));
            write_number(static_cast<std::int32_t>(value));
        }
        else if (value <= -264075)
        {
            value = -(value + 264075);
            write_bon8_bytes(0xF0 + ((value >> 22) & 0x07), 0xC0 + ((value >> 16) & 0x3F), value >> 8, value);
        }
        else if (value <= -1931)
        {
            value = -(value + 1931);
            write_bon8_bytes(0xE0 + ((value >> 14) & 0x0F), 0xC0 + ((value >> 8) & 0x3F), value);
        }
        else if (value <= -11)
        {
            value = -(value + 11);
            write_bon8_bytes(0xC2 + ((value >> 6) & 0x1F), 0xC0 + (value & 0x3F));
        }
        else if (value <= -1)
        {
            write_bon8_bytes(0xB8 - (value + 1));
        }
        else if (value <= 39)
        {
            write_bon8_bytes(0x90 + value);
        }
        else if (value <= 3879)
        {
            value -= 40;
            write_bon8_bytes(0xC2 + ((value >> 7) & 0x1F), value & 0x7F);
        }
        else if (value <= 528167)
        {
            value -= 3880;
            write_bon8_bytes(0xE0 + ((value >> 15) & 0x0F), (value >> 8) & 0x7F, value);
        }
        else
        {
            value -= 528168;
            write_bon8_bytes(0xF0 + ((value >> 23) & 0x07), (value >> 16) & 0x7F, value >> 8, value);
        }
    }
    template<typename... Bytes>
    void write_bon8_bytes(const Bytes... bytes)
    {
        const std::array<CharType, sizeof...(Bytes)> buffer{{to_char_type(static_cast<std::uint8_t>(bytes & 0xFF))...}};
        oa.write_characters(buffer.data(), buffer.size());
    }
    void write_bon8_float(const number_float_t n)
    {
#ifdef __GNUC__
        JSON_HEDLEY_DIAGNOSTIC_PUSH
        JSON_HEDLEY_PRAGMA(GCC diagnostic ignored "-Wfloat-equal")
#endif
        if (n == static_cast<number_float_t>(-1))
        {
            oa.write_character(to_char_type(0xFB));
        }
        else if (n == static_cast<number_float_t>(0) && !std::signbit(n))
        {
            oa.write_character(to_char_type(0xFC));
        }
        else if (n == static_cast<number_float_t>(1))
        {
            oa.write_character(to_char_type(0xFD));
        }
        else if (std::isnan(n))
        {
            write_bon8_bytes(0x8E, 0x7F, 0x80, 0x00, 0x01);
        }
        else
        {
            write_compact_float(n, to_char_type(0x8E), to_char_type(0x8F));
        }
#ifdef __GNUC__
        JSON_HEDLEY_DIAGNOSTIC_POP
#endif
    }
    static std::uint16_t byte_swap(std::uint16_t x) noexcept
    {
#if defined(__GNUC__) || defined(__clang__)
        return __builtin_bswap16(x);
#elif defined(_MSC_VER)
        return _byteswap_ushort(x);
#else
        return static_cast<std::uint16_t>((x >> 8) | (x << 8));
#endif
    }
    static std::uint32_t byte_swap(std::uint32_t x) noexcept
    {
#if defined(__GNUC__) || defined(__clang__)
        return __builtin_bswap32(x);
#elif defined(_MSC_VER)
        return _byteswap_ulong(x);
#else
        return ((x & 0x000000FFu) << 24) | ((x & 0x0000FF00u) << 8)
               | ((x & 0x00FF0000u) >> 8) | ((x & 0xFF000000u) >> 24);
#endif
    }
    static std::uint64_t byte_swap(std::uint64_t x) noexcept
    {
#if defined(__GNUC__) || defined(__clang__)
        return __builtin_bswap64(x);
#elif defined(_MSC_VER)
        return _byteswap_uint64(x);
#else
        x = ((x & 0x00000000FFFFFFFFull) << 32) | ((x & 0xFFFFFFFF00000000ull) >> 32);
        x = ((x & 0x0000FFFF0000FFFFull) << 16) | ((x & 0xFFFF0000FFFF0000ull) >> 16);
        x = ((x & 0x00FF00FF00FF00FFull) << 8) | ((x & 0xFF00FF00FF00FF00ull) >> 8);
        return x;
#endif
    }
    template<typename UIntType, std::size_t N>
    static void byte_swap_buffer(std::array<CharType, N>& a) noexcept
    {
        static_assert(sizeof(UIntType) == N, "swap width must match the buffer size");
        UIntType v{};
        std::memcpy(&v, a.data(), sizeof(v));
        v = byte_swap(v);
        std::memcpy(a.data(), &v, sizeof(v));
    }
    static void reverse_bytes(std::array<CharType, 2>& a) noexcept
    {
        byte_swap_buffer<std::uint16_t>(a);
    }
    static void reverse_bytes(std::array<CharType, 4>& a) noexcept
    {
        byte_swap_buffer<std::uint32_t>(a);
    }
    static void reverse_bytes(std::array<CharType, 8>& a) noexcept
    {
        byte_swap_buffer<std::uint64_t>(a);
    }
    template<std::size_t N>
    static void reverse_bytes(std::array<CharType, N>& a) noexcept
    {
        std::reverse(a.begin(), a.end());
    }
    template<typename NumberType>
    void write_number(const NumberType n, const bool OutputIsLittleEndian = false)
    {
        std::array<CharType, sizeof(NumberType)> vec{};
        std::memcpy(vec.data(), &n, sizeof(NumberType));
        if (is_little_endian != OutputIsLittleEndian)
        {
            reverse_bytes(vec);
        }
        oa.write_characters(vec.data(), sizeof(NumberType));
    }
    void write_compact_float(const number_float_t n, const CharType float32_marker, const CharType float64_marker)
    {
        static_assert(std::is_same<number_float_t, float>::value || std::is_same<number_float_t, double>::value,
                      "number_float_t must be float or double for the CBOR/MessagePack/BON8 writer");
#ifdef __GNUC__
        JSON_HEDLEY_DIAGNOSTIC_PUSH
        JSON_HEDLEY_PRAGMA(GCC diagnostic ignored "-Wfloat-equal")
#endif
#if defined(__GNUC__) && !defined(__clang__) && (__GNUC__ >= 7)
        JSON_HEDLEY_PRAGMA(GCC diagnostic ignored "-Wduplicated-branches")
#endif
        if (!std::isfinite(n) || ((static_cast<double>(n) >= static_cast<double>(std::numeric_limits<float>::lowest()) &&
                                   static_cast<double>(n) <= static_cast<double>((std::numeric_limits<float>::max)()) &&
                                   static_cast<double>(static_cast<float>(n)) == static_cast<double>(n))))
        {
            oa.write_character(float32_marker);
            write_number(static_cast<float>(n));
        }
        else
        {
            oa.write_character(float64_marker);
            write_number(n);
        }
#ifdef __GNUC__
        JSON_HEDLEY_DIAGNOSTIC_POP
#endif
    }
  public:
    template < typename C = CharType,
               enable_if_t < std::is_signed<C>::value && std::is_signed<char>::value > * = nullptr >
    static constexpr CharType to_char_type(std::uint8_t x) noexcept
    {
        return *reinterpret_cast<char*>(&x);
    }
    template < typename C = CharType,
               enable_if_t < std::is_signed<C>::value && std::is_unsigned<char>::value > * = nullptr >
    static CharType to_char_type(std::uint8_t x) noexcept
    {
#ifdef JSON_HAS_CPP_26
        static_assert(std::is_trivially_copyable<CharType>::value, "CharType must be trivially copyable");
        static_assert(std::is_trivially_default_constructible<CharType>::value, "CharType must be trivially default constructible");
#else
        static_assert(std::is_trivial<CharType>::value, "CharType must be trivial");
#endif
        static_assert(sizeof(std::uint8_t) == sizeof(CharType), "size of CharType must be equal to std::uint8_t");
        CharType result;
        std::memcpy(&result, &x, sizeof(x));
        return result;
    }
    template<typename C = CharType,
             enable_if_t<std::is_unsigned<C>::value>* = nullptr>
    static constexpr CharType to_char_type(std::uint8_t x) noexcept
    {
        return x;
    }
    template < typename InputCharType, typename C = CharType,
               enable_if_t <
                   std::is_signed<C>::value &&
                   std::is_signed<char>::value &&
                   std::is_same<char, typename std::remove_cv<InputCharType>::type>::value
                   > * = nullptr >
    static constexpr CharType to_char_type(InputCharType x) noexcept
    {
        return x;
    }
  private:
    const bool is_little_endian = little_endianness();
    OutputSinkType oa;
};
}  
NLOHMANN_JSON_NAMESPACE_END
#include <algorithm> 
#include <array> 
#include <clocale> 
#include <cmath> 
#include <cstddef> 
#include <cstdint> 
#include <cstdio> 
#include <cstring> 
#include <iterator> 
#include <limits> 
#include <string> 
#include <type_traits> 
#include <vector> 
#include <array> 
#include <cmath>   
#include <cstdint> 
#include <cstring> 
#include <limits> 
#include <type_traits> 
NLOHMANN_JSON_NAMESPACE_BEGIN
namespace detail
{
namespace dtoa_impl
{
template<typename Target, typename Source>
Target reinterpret_bits(const Source source)
{
    static_assert(sizeof(Target) == sizeof(Source), "size mismatch");
    Target target;
    std::memcpy(&target, &source, sizeof(Source));
    return target;
}
struct diyfp 
{
    static constexpr int kPrecision = 64; 
    std::uint64_t f = 0;
    int e = 0;
    constexpr diyfp(std::uint64_t f_, int e_) noexcept : f(f_), e(e_) {}
    static diyfp sub(const diyfp& x, const diyfp& y) noexcept
    {
        JSON_ASSERT(x.e == y.e);
        JSON_ASSERT(x.f >= y.f);
        return {x.f - y.f, x.e};
    }
    static diyfp mul(const diyfp& x, const diyfp& y) noexcept
    {
        static_assert(kPrecision == 64, "internal error");
        const std::uint64_t u_lo = x.f & 0xFFFFFFFFu;
        const std::uint64_t u_hi = x.f >> 32u;
        const std::uint64_t v_lo = y.f & 0xFFFFFFFFu;
        const std::uint64_t v_hi = y.f >> 32u;
        const std::uint64_t p0 = u_lo * v_lo;
        const std::uint64_t p1 = u_lo * v_hi;
        const std::uint64_t p2 = u_hi * v_lo;
        const std::uint64_t p3 = u_hi * v_hi;
        const std::uint64_t p0_hi = p0 >> 32u;
        const std::uint64_t p1_lo = p1 & 0xFFFFFFFFu;
        const std::uint64_t p1_hi = p1 >> 32u;
        const std::uint64_t p2_lo = p2 & 0xFFFFFFFFu;
        const std::uint64_t p2_hi = p2 >> 32u;
        std::uint64_t Q = p0_hi + p1_lo + p2_lo;
        Q += std::uint64_t{1} << (64u - 32u - 1u); 
        const std::uint64_t h = p3 + p2_hi + p1_hi + (Q >> 32u);
        return {h, x.e + y.e + 64};
    }
    static diyfp normalize(diyfp x) noexcept
    {
        JSON_ASSERT(x.f != 0);
        while ((x.f >> 63u) == 0)
        {
            x.f <<= 1u;
            x.e--;
        }
        return x;
    }
    static diyfp normalize_to(const diyfp& x, const int target_exponent) noexcept
    {
        const int delta = x.e - target_exponent;
        JSON_ASSERT(delta >= 0);
        JSON_ASSERT(((x.f << delta) >> delta) == x.f);
        return {x.f << delta, target_exponent};
    }
};
struct boundaries
{
    diyfp w;
    diyfp minus;
    diyfp plus;
};
template<typename FloatType>
boundaries compute_boundaries(FloatType value)
{
    JSON_ASSERT(std::isfinite(value));
    JSON_ASSERT(value > 0);
    static_assert(std::numeric_limits<FloatType>::is_iec559,
                  "internal error: dtoa_short requires an IEEE-754 floating-point implementation");
    constexpr int      kPrecision = std::numeric_limits<FloatType>::digits; 
    constexpr int      kBias      = std::numeric_limits<FloatType>::max_exponent - 1 + (kPrecision - 1);
    constexpr int      kMinExp    = 1 - kBias;
    constexpr std::uint64_t kHiddenBit = std::uint64_t{1} << (kPrecision - 1); 
    using bits_type = typename std::conditional<kPrecision == 24, std::uint32_t, std::uint64_t >::type;
    const auto bits = static_cast<std::uint64_t>(reinterpret_bits<bits_type>(value));
    const std::uint64_t E = bits >> (kPrecision - 1);
    const std::uint64_t F = bits & (kHiddenBit - 1);
    const bool is_denormal = E == 0;
    const diyfp v = is_denormal
                    ? diyfp(F, kMinExp)
                    : diyfp(F + kHiddenBit, static_cast<int>(E) - kBias);
    const bool lower_boundary_is_closer = F == 0 && E > 1;
    const diyfp m_plus = diyfp((2 * v.f) + 1, v.e - 1);
    const diyfp m_minus = lower_boundary_is_closer
                          ? diyfp((4 * v.f) - 1, v.e - 2)  
                          : diyfp((2 * v.f) - 1, v.e - 1); 
    const diyfp w_plus = diyfp::normalize(m_plus);
    const diyfp w_minus = diyfp::normalize_to(m_minus, w_plus.e);
    return {diyfp::normalize(v), w_minus, w_plus};
}
constexpr int kAlpha = -60;
constexpr int kGamma = -32;
struct cached_power 
{
    std::uint64_t f;
    int e;
    int k;
};
inline cached_power get_cached_power_for_binary_exponent(int e)
{
    constexpr int kCachedPowersMinDecExp = -300;
    constexpr int kCachedPowersDecStep = 8;
    static constexpr std::array<cached_power, 79> kCachedPowers =
    {
        {
            { 0xAB70FE17C79AC6CA, -1060, -300 },
            { 0xFF77B1FCBEBCDC4F, -1034, -292 },
            { 0xBE5691EF416BD60C, -1007, -284 },
            { 0x8DD01FAD907FFC3C,  -980, -276 },
            { 0xD3515C2831559A83,  -954, -268 },
            { 0x9D71AC8FADA6C9B5,  -927, -260 },
            { 0xEA9C227723EE8BCB,  -901, -252 },
            { 0xAECC49914078536D,  -874, -244 },
            { 0x823C12795DB6CE57,  -847, -236 },
            { 0xC21094364DFB5637,  -821, -228 },
            { 0x9096EA6F3848984F,  -794, -220 },
            { 0xD77485CB25823AC7,  -768, -212 },
            { 0xA086CFCD97BF97F4,  -741, -204 },
            { 0xEF340A98172AACE5,  -715, -196 },
            { 0xB23867FB2A35B28E,  -688, -188 },
            { 0x84C8D4DFD2C63F3B,  -661, -180 },
            { 0xC5DD44271AD3CDBA,  -635, -172 },
            { 0x936B9FCEBB25C996,  -608, -164 },
            { 0xDBAC6C247D62A584,  -582, -156 },
            { 0xA3AB66580D5FDAF6,  -555, -148 },
            { 0xF3E2F893DEC3F126,  -529, -140 },
            { 0xB5B5ADA8AAFF80B8,  -502, -132 },
            { 0x87625F056C7C4A8B,  -475, -124 },
            { 0xC9BCFF6034C13053,  -449, -116 },
            { 0x964E858C91BA2655,  -422, -108 },
            { 0xDFF9772470297EBD,  -396, -100 },
            { 0xA6DFBD9FB8E5B88F,  -369,  -92 },
            { 0xF8A95FCF88747D94,  -343,  -84 },
            { 0xB94470938FA89BCF,  -316,  -76 },
            { 0x8A08F0F8BF0F156B,  -289,  -68 },
            { 0xCDB02555653131B6,  -263,  -60 },
            { 0x993FE2C6D07B7FAC,  -236,  -52 },
            { 0xE45C10C42A2B3B06,  -210,  -44 },
            { 0xAA242499697392D3,  -183,  -36 },
            { 0xFD87B5F28300CA0E,  -157,  -28 },
            { 0xBCE5086492111AEB,  -130,  -20 },
            { 0x8CBCCC096F5088CC,  -103,  -12 },
            { 0xD1B71758E219652C,   -77,   -4 },
            { 0x9C40000000000000,   -50,    4 },
            { 0xE8D4A51000000000,   -24,   12 },
            { 0xAD78EBC5AC620000,     3,   20 },
            { 0x813F3978F8940984,    30,   28 },
            { 0xC097CE7BC90715B3,    56,   36 },
            { 0x8F7E32CE7BEA5C70,    83,   44 },
            { 0xD5D238A4ABE98068,   109,   52 },
            { 0x9F4F2726179A2245,   136,   60 },
            { 0xED63A231D4C4FB27,   162,   68 },
            { 0xB0DE65388CC8ADA8,   189,   76 },
            { 0x83C7088E1AAB65DB,   216,   84 },
            { 0xC45D1DF942711D9A,   242,   92 },
            { 0x924D692CA61BE758,   269,  100 },
            { 0xDA01EE641A708DEA,   295,  108 },
            { 0xA26DA3999AEF774A,   322,  116 },
            { 0xF209787BB47D6B85,   348,  124 },
            { 0xB454E4A179DD1877,   375,  132 },
            { 0x865B86925B9BC5C2,   402,  140 },
            { 0xC83553C5C8965D3D,   428,  148 },
            { 0x952AB45CFA97A0B3,   455,  156 },
            { 0xDE469FBD99A05FE3,   481,  164 },
            { 0xA59BC234DB398C25,   508,  172 },
            { 0xF6C69A72A3989F5C,   534,  180 },
            { 0xB7DCBF5354E9BECE,   561,  188 },
            { 0x88FCF317F22241E2,   588,  196 },
            { 0xCC20CE9BD35C78A5,   614,  204 },
            { 0x98165AF37B2153DF,   641,  212 },
            { 0xE2A0B5DC971F303A,   667,  220 },
            { 0xA8D9D1535CE3B396,   694,  228 },
            { 0xFB9B7CD9A4A7443C,   720,  236 },
            { 0xBB764C4CA7A44410,   747,  244 },
            { 0x8BAB8EEFB6409C1A,   774,  252 },
            { 0xD01FEF10A657842C,   800,  260 },
            { 0x9B10A4E5E9913129,   827,  268 },
            { 0xE7109BFBA19C0C9D,   853,  276 },
            { 0xAC2820D9623BF429,   880,  284 },
            { 0x80444B5E7AA7CF85,   907,  292 },
            { 0xBF21E44003ACDD2D,   933,  300 },
            { 0x8E679C2F5E44FF8F,   960,  308 },
            { 0xD433179D9C8CB841,   986,  316 },
            { 0x9E19DB92B4E31BA9,  1013,  324 },
        }
    };
    JSON_ASSERT(e >= -1500);
    JSON_ASSERT(e <=  1500);
    const int f = kAlpha - e - 1;
    const int k = ((f * 78913) / (1 << 18)) + static_cast<int>(f > 0);
    const int index = (-kCachedPowersMinDecExp + k + (kCachedPowersDecStep - 1)) / kCachedPowersDecStep;
    JSON_ASSERT(index >= 0);
    JSON_ASSERT(static_cast<std::size_t>(index) < kCachedPowers.size());
    const cached_power cached = kCachedPowers[static_cast<std::size_t>(index)];
    JSON_ASSERT(kAlpha <= cached.e + e + 64);
    JSON_ASSERT(kGamma >= cached.e + e + 64);
    return cached;
}
inline int find_largest_pow10(const std::uint32_t n, std::uint32_t& pow10)
{
    if (n >= 1000000000)
    {
        pow10 = 1000000000;
        return 10;
    }
    if (n >= 100000000)
    {
        pow10 = 100000000;
        return  9;
    }
    if (n >= 10000000)
    {
        pow10 = 10000000;
        return  8;
    }
    if (n >= 1000000)
    {
        pow10 = 1000000;
        return  7;
    }
    if (n >= 100000)
    {
        pow10 = 100000;
        return  6;
    }
    if (n >= 10000)
    {
        pow10 = 10000;
        return  5;
    }
    if (n >= 1000)
    {
        pow10 = 1000;
        return  4;
    }
    if (n >= 100)
    {
        pow10 = 100;
        return  3;
    }
    if (n >= 10)
    {
        pow10 = 10;
        return  2;
    }
    pow10 = 1;
    return 1;
}
inline void grisu2_round(char* buf, int len, std::uint64_t dist, std::uint64_t delta,
                         std::uint64_t rest, std::uint64_t ten_k)
{
    JSON_ASSERT(len >= 1);
    JSON_ASSERT(dist <= delta);
    JSON_ASSERT(rest <= delta);
    JSON_ASSERT(ten_k > 0);
    while (rest < dist
            && delta - rest >= ten_k
            && (rest + ten_k < dist || dist - rest > rest + ten_k - dist))
    {
        JSON_ASSERT(buf[len - 1] != '0');
        buf[len - 1]--;
        rest += ten_k;
    }
}
inline void grisu2_digit_gen(char* buffer, int& length, int& decimal_exponent,
                             diyfp M_minus, diyfp w, diyfp M_plus)
{
    static_assert(kAlpha >= -60, "internal error");
    static_assert(kGamma <= -32, "internal error");
    JSON_ASSERT(M_plus.e >= kAlpha);
    JSON_ASSERT(M_plus.e <= kGamma);
    std::uint64_t delta = diyfp::sub(M_plus, M_minus).f; 
    std::uint64_t dist  = diyfp::sub(M_plus, w      ).f; 
    const diyfp one(std::uint64_t{1} << -M_plus.e, M_plus.e);
    auto p1 = static_cast<std::uint32_t>(M_plus.f >> -one.e); 
    std::uint64_t p2 = M_plus.f & (one.f - 1);                    
    JSON_ASSERT(p1 > 0);
    std::uint32_t pow10{};
    const int k = find_largest_pow10(p1, pow10);
    int n = k;
    while (n > 0)
    {
        const std::uint32_t d = p1 / pow10;  
        const std::uint32_t r = p1 % pow10;  
        JSON_ASSERT(d <= 9);
        buffer[length++] = static_cast<char>('0' + d); 
        p1 = r;
        n--;
        const std::uint64_t rest = (std::uint64_t{p1} << -one.e) + p2;
        if (rest <= delta)
        {
            decimal_exponent += n;
            const std::uint64_t ten_n = std::uint64_t{pow10} << -one.e;
            grisu2_round(buffer, length, dist, delta, rest, ten_n);
            return;
        }
        pow10 /= 10;
    }
    JSON_ASSERT(p2 > delta);
    int m = 0;
    for (;;)
    {
        JSON_ASSERT(p2 <= (std::numeric_limits<std::uint64_t>::max)() / 10);
        p2 *= 10;
        const std::uint64_t d = p2 >> -one.e;     
        const std::uint64_t r = p2 & (one.f - 1); 
        JSON_ASSERT(d <= 9);
        buffer[length++] = static_cast<char>('0' + d); 
        p2 = r;
        m++;
        delta *= 10;
        dist  *= 10;
        if (p2 <= delta)
        {
            break;
        }
    }
    decimal_exponent -= m;
    const std::uint64_t ten_m = one.f;
    grisu2_round(buffer, length, dist, delta, p2, ten_m);
}
JSON_HEDLEY_NON_NULL(1)
inline void grisu2(char* buf, int& len, int& decimal_exponent,
                   diyfp m_minus, diyfp v, diyfp m_plus)
{
    JSON_ASSERT(m_plus.e == m_minus.e);
    JSON_ASSERT(m_plus.e == v.e);
    const cached_power cached = get_cached_power_for_binary_exponent(m_plus.e);
    const diyfp c_minus_k(cached.f, cached.e); 
    const diyfp w       = diyfp::mul(v,       c_minus_k);
    const diyfp w_minus = diyfp::mul(m_minus, c_minus_k);
    const diyfp w_plus  = diyfp::mul(m_plus,  c_minus_k);
    const diyfp M_minus(w_minus.f + 1, w_minus.e);
    const diyfp M_plus (w_plus.f  - 1, w_plus.e );
    decimal_exponent = -cached.k; 
    grisu2_digit_gen(buf, len, decimal_exponent, M_minus, w, M_plus);
}
template<typename FloatType>
JSON_HEDLEY_NON_NULL(1)
void grisu2(char* buf, int& len, int& decimal_exponent, FloatType value)
{
    static_assert(diyfp::kPrecision >= std::numeric_limits<FloatType>::digits + 3,
                  "internal error: not enough precision");
    JSON_ASSERT(std::isfinite(value));
    JSON_ASSERT(value > 0);
#if 0 
    const boundaries w = compute_boundaries(static_cast<double>(value));
#else
    const boundaries w = compute_boundaries(value);
#endif
    grisu2(buf, len, decimal_exponent, w.minus, w.w, w.plus);
}
JSON_HEDLEY_NON_NULL(1)
JSON_HEDLEY_RETURNS_NON_NULL
inline char* append_exponent(char* buf, int e)
{
    JSON_ASSERT(e > -1000);
    JSON_ASSERT(e <  1000);
    if (e < 0)
    {
        e = -e;
        *buf++ = '-';
    }
    else
    {
        *buf++ = '+';
    }
    auto k = static_cast<std::uint32_t>(e);
    if (k < 10)
    {
        *buf++ = '0';
        *buf++ = static_cast<char>('0' + k);
    }
    else if (k < 100)
    {
        *buf++ = static_cast<char>('0' + (k / 10));
        k %= 10;
        *buf++ = static_cast<char>('0' + k);
    }
    else
    {
        *buf++ = static_cast<char>('0' + (k / 100));
        k %= 100;
        *buf++ = static_cast<char>('0' + (k / 10));
        k %= 10;
        *buf++ = static_cast<char>('0' + k);
    }
    return buf;
}
JSON_HEDLEY_NON_NULL(1)
JSON_HEDLEY_RETURNS_NON_NULL
inline char* format_buffer(char* buf, int len, int decimal_exponent,
                           int min_exp, int max_exp)
{
    JSON_ASSERT(min_exp < 0);
    JSON_ASSERT(max_exp > 0);
    const int k = len;
    const int n = len + decimal_exponent;
    if (k <= n && n <= max_exp)
    {
        std::memset(buf + k, '0', static_cast<size_t>(n) - static_cast<size_t>(k));
        buf[n + 0] = '.';
        buf[n + 1] = '0';
        return buf + (static_cast<size_t>(n) + 2);
    }
    if (0 < n && n <= max_exp)
    {
        JSON_ASSERT(k > n);
        std::memmove(buf + (static_cast<size_t>(n) + 1), buf + n, static_cast<size_t>(k) - static_cast<size_t>(n));
        buf[n] = '.';
        return buf + (static_cast<size_t>(k) + 1U);
    }
    if (min_exp < n && n <= 0)
    {
        std::memmove(buf + (2 + static_cast<size_t>(-n)), buf, static_cast<size_t>(k));
        buf[0] = '0';
        buf[1] = '.';
        std::memset(buf + 2, '0', static_cast<size_t>(-n));
        return buf + (2U + static_cast<size_t>(-n) + static_cast<size_t>(k));
    }
    if (k == 1)
    {
        buf += 1;
    }
    else
    {
        std::memmove(buf + 2, buf + 1, static_cast<size_t>(k) - 1);
        buf[1] = '.';
        buf += 1 + static_cast<size_t>(k);
    }
    *buf++ = 'e';
    return append_exponent(buf, n - 1);
}
}  
template<typename FloatType>
JSON_HEDLEY_NON_NULL(1, 2)
JSON_HEDLEY_RETURNS_NON_NULL
char* to_chars(char* first, const char* last, FloatType value)
{
    static_cast<void>(last); 
    JSON_ASSERT(std::isfinite(value));
    if (std::signbit(value))
    {
        value = -value;
        *first++ = '-';
    }
#ifdef __GNUC__
    JSON_HEDLEY_DIAGNOSTIC_PUSH
    JSON_HEDLEY_PRAGMA(GCC diagnostic ignored "-Wfloat-equal")
#endif
    if (value == 0) 
    {
        *first++ = '0';
        *first++ = '.';
        *first++ = '0';
        return first;
    }
#ifdef __GNUC__
    JSON_HEDLEY_DIAGNOSTIC_POP
#endif
    JSON_ASSERT(last - first >= std::numeric_limits<FloatType>::max_digits10);
    int len = 0;
    int decimal_exponent = 0;
    dtoa_impl::grisu2(first, len, decimal_exponent, value);
    JSON_ASSERT(len <= std::numeric_limits<FloatType>::max_digits10);
    constexpr int kMinExp = -4;
    constexpr int kMaxExp = std::numeric_limits<FloatType>::digits10;
    JSON_ASSERT(last - first >= kMaxExp + 2);
    JSON_ASSERT(last - first >= 2 + (-kMinExp - 1) + std::numeric_limits<FloatType>::max_digits10);
    JSON_ASSERT(last - first >= std::numeric_limits<FloatType>::max_digits10 + 6);
    return dtoa_impl::format_buffer(first, len, decimal_exponent, kMinExp, kMaxExp);
}
}  
NLOHMANN_JSON_NAMESPACE_END
NLOHMANN_JSON_NAMESPACE_BEGIN
namespace detail
{
enum class error_handler_t
{
    strict,  
    replace, 
    ignore   
};
template<typename BasicJsonType>
class serializer
{
    using string_t = typename BasicJsonType::string_t;
    using number_float_t = typename BasicJsonType::number_float_t;
    using number_integer_t = typename BasicJsonType::number_integer_t;
    using number_unsigned_t = typename BasicJsonType::number_unsigned_t;
    using binary_char_t = typename BasicJsonType::binary_t::value_type;
  public:
    serializer(output_adapter_protocol<char>& s, const char ichar,
               const bool pretty_print_ = false,
               const bool ensure_ascii_ = false,
               const std::size_t indent_step_ = 0,
               error_handler_t error_handler_ = error_handler_t::strict)
        : o(&s)
        , indent_char(ichar)
        , pretty_print(pretty_print_)
        , ensure_ascii(ensure_ascii_)
        , indent_step(indent_step_)
        , error_handler(error_handler_)
    {}
    serializer(const serializer&) = delete;
    serializer& operator=(const serializer&) = delete;
    serializer(serializer&&) = delete;
    serializer& operator=(serializer&&) = delete;
    ~serializer() = default;
    void dump(const BasicJsonType& val,
              const std::size_t current_indent = 0)
    {
        dump_internal(val, current_indent);
        flush();
    }
  JSON_PRIVATE_UNLESS_TESTED:
    void dump_internal(const BasicJsonType& val,
                       const std::size_t current_indent = 0,
                       const std::size_t depth = 0)
    {
        switch (val.m_data.m_type)
        {
            case value_t::object:
            {
                if (JSON_HEDLEY_UNLIKELY(depth >= recursion_depth_limit()))
                {
                    dump_iteratively(val, current_indent);
                    return;
                }
                if (val.m_data.m_value.object->empty())
                {
                    put_literal("{}");
                    return;
                }
                if (pretty_print)
                {
                    put_literal("{\n");
                    const auto new_indent = next_indent(current_indent, indent_step);
                    auto i = val.m_data.m_value.object->cbegin();
                    for (std::size_t cnt = 0; cnt < val.m_data.m_value.object->size() - 1; ++cnt, ++i)
                    {
                        put_indent(new_indent);
                        put_char('"');
                        dump_escaped(i->first);
                        put_literal("\": ");
                        dump_internal(i->second, new_indent, depth + 1);
                        put_literal(",\n");
                    }
                    JSON_ASSERT(i != val.m_data.m_value.object->cend());
                    JSON_ASSERT(std::next(i) == val.m_data.m_value.object->cend());
                    put_indent(new_indent);
                    put_char('"');
                    dump_escaped(i->first);
                    put_literal("\": ");
                    dump_internal(i->second, new_indent, depth + 1);
                    put_char('\n');
                    put_indent(current_indent);
                    put_char('}');
                }
                else
                {
                    put_char('{');
                    auto i = val.m_data.m_value.object->cbegin();
                    for (std::size_t cnt = 0; cnt < val.m_data.m_value.object->size() - 1; ++cnt, ++i)
                    {
                        put_char('"');
                        dump_escaped(i->first);
                        put_literal("\":");
                        dump_internal(i->second, current_indent, depth + 1);
                        put_char(',');
                    }
                    JSON_ASSERT(i != val.m_data.m_value.object->cend());
                    JSON_ASSERT(std::next(i) == val.m_data.m_value.object->cend());
                    put_char('"');
                    dump_escaped(i->first);
                    put_literal("\":");
                    dump_internal(i->second, current_indent, depth + 1);
                    put_char('}');
                }
                return;
            }
            case value_t::array:
            {
                if (JSON_HEDLEY_UNLIKELY(depth >= recursion_depth_limit()))
                {
                    dump_iteratively(val, current_indent);
                    return;
                }
                if (val.m_data.m_value.array->empty())
                {
                    put_literal("[]");
                    return;
                }
                if (pretty_print)
                {
                    put_literal("[\n");
                    const auto new_indent = next_indent(current_indent, indent_step);
                    for (auto i = val.m_data.m_value.array->cbegin();
                            i != val.m_data.m_value.array->cend() - 1; ++i)
                    {
                        put_indent(new_indent);
                        dump_internal(*i, new_indent, depth + 1);
                        put_literal(",\n");
                    }
                    JSON_ASSERT(!val.m_data.m_value.array->empty());
                    put_indent(new_indent);
                    dump_internal(val.m_data.m_value.array->back(), new_indent, depth + 1);
                    put_char('\n');
                    put_indent(current_indent);
                    put_char(']');
                }
                else
                {
                    put_char('[');
                    for (auto i = val.m_data.m_value.array->cbegin();
                            i != val.m_data.m_value.array->cend() - 1; ++i)
                    {
                        dump_internal(*i, current_indent, depth + 1);
                        put_char(',');
                    }
                    JSON_ASSERT(!val.m_data.m_value.array->empty());
                    dump_internal(val.m_data.m_value.array->back(), current_indent, depth + 1);
                    put_char(']');
                }
                return;
            }
            case value_t::string:
            case value_t::binary:
            case value_t::boolean:
            case value_t::number_integer:
            case value_t::number_unsigned:
            case value_t::number_float:
            case value_t::discarded:
            case value_t::null:
            default:
                dump_scalar(val, current_indent);
                return;
        }
    }
  private:
    void dump_iteratively(const BasicJsonType& val,
                          const std::size_t current_indent = 0)
    {
        std::vector<dump_frame> stack;
        dump_value(val, current_indent, stack);
        while (!stack.empty())
        {
            dump_frame& frame = stack.back();
            if (frame.value->m_data.m_type == value_t::object)
            {
                const auto* object = frame.value->m_data.m_value.object;
                if (frame.object_it == object->cend())
                {
                    if (pretty_print)
                    {
                        put_char('\n');
                        put_indent(frame.current_indent);
                    }
                    put_char('}');
                    stack.pop_back();
                    continue;
                }
                if (frame.object_it != object->cbegin())
                {
                    if (pretty_print)
                    {
                        put_literal(",\n");
                    }
                    else
                    {
                        put_char(',');
                    }
                }
                if (pretty_print)
                {
                    put_indent(frame.child_indent);
                }
                put_char('"');
                dump_escaped(frame.object_it->first);
                if (pretty_print)
                {
                    put_literal("\": ");
                }
                else
                {
                    put_literal("\":");
                }
                const BasicJsonType& element = frame.object_it->second;
                ++frame.object_it;
                const std::size_t element_indent = frame.child_indent;
                dump_value(element, element_indent, stack);
            }
            else
            {
                const auto* array = frame.value->m_data.m_value.array;
                if (frame.array_it == array->cend())
                {
                    if (pretty_print)
                    {
                        put_char('\n');
                        put_indent(frame.current_indent);
                    }
                    put_char(']');
                    stack.pop_back();
                    continue;
                }
                if (frame.array_it != array->cbegin())
                {
                    if (pretty_print)
                    {
                        put_literal(",\n");
                    }
                    else
                    {
                        put_char(',');
                    }
                }
                if (pretty_print)
                {
                    put_indent(frame.child_indent);
                }
                const BasicJsonType& element = *frame.array_it;
                ++frame.array_it;
                const std::size_t element_indent = frame.child_indent;
                dump_value(element, element_indent, stack);
            }
        }
    }
  private:
    struct dump_frame
    {
        dump_frame(const BasicJsonType* value_, const std::size_t current_indent_,
                   const std::size_t child_indent_) noexcept
            : value(value_)
            , current_indent(current_indent_)
            , child_indent(child_indent_)
        {}
        const BasicJsonType* value;
        typename BasicJsonType::object_t::const_iterator object_it{};
        typename BasicJsonType::array_t::const_iterator array_it{};
        std::size_t current_indent;
        std::size_t child_indent;
    };
    void dump_value(const BasicJsonType& val,
                    const std::size_t current_indent,
                    std::vector<dump_frame>& stack)
    {
        switch (val.m_data.m_type)
        {
            case value_t::object:
            {
                if (val.m_data.m_value.object->empty())
                {
                    put_literal("{}");
                    return;
                }
                std::size_t child_indent = current_indent;
                if (pretty_print)
                {
                    put_literal("{\n");
                    child_indent = next_indent(current_indent, indent_step);
                }
                else
                {
                    put_char('{');
                }
                stack.emplace_back(&val, current_indent, child_indent);
                stack.back().object_it = val.m_data.m_value.object->cbegin();
                return;
            }
            case value_t::array:
            {
                if (val.m_data.m_value.array->empty())
                {
                    put_literal("[]");
                    return;
                }
                std::size_t child_indent = current_indent;
                if (pretty_print)
                {
                    put_literal("[\n");
                    child_indent = next_indent(current_indent, indent_step);
                }
                else
                {
                    put_char('[');
                }
                stack.emplace_back(&val, current_indent, child_indent);
                stack.back().array_it = val.m_data.m_value.array->cbegin();
                return;
            }
            case value_t::string:
            case value_t::binary:
            case value_t::boolean:
            case value_t::number_integer:
            case value_t::number_unsigned:
            case value_t::number_float:
            case value_t::discarded:
            case value_t::null:
            default:
                dump_scalar(val, current_indent);
                return;
        }
    }
    void dump_scalar(const BasicJsonType& val, const std::size_t current_indent)
    {
        switch (val.m_data.m_type)
        {
            case value_t::string:
            {
                put_char('"');
                dump_escaped(*val.m_data.m_value.string);
                put_char('"');
                return;
            }
            case value_t::binary:
            {
                if (pretty_print)
                {
                    put_literal("{\n");
                    const auto new_indent = next_indent(current_indent, indent_step);
                    put_indent(new_indent);
                    put_literal("\"bytes\": [");
                    if (!val.m_data.m_value.binary->empty())
                    {
                        for (auto i = val.m_data.m_value.binary->cbegin();
                                i != val.m_data.m_value.binary->cend() - 1; ++i)
                        {
                            dump_byte(*i);
                            put_literal(", ");
                        }
                        dump_byte(val.m_data.m_value.binary->back());
                    }
                    put_literal("],\n");
                    put_indent(new_indent);
                    put_literal("\"subtype\": ");
                    if (val.m_data.m_value.binary->has_subtype())
                    {
                        dump_integer(val.m_data.m_value.binary->subtype());
                    }
                    else
                    {
                        put_literal("null");
                    }
                    put_char('\n');
                    put_indent(current_indent);
                    put_char('}');
                }
                else
                {
                    put_literal("{\"bytes\":[");
                    if (!val.m_data.m_value.binary->empty())
                    {
                        for (auto i = val.m_data.m_value.binary->cbegin();
                                i != val.m_data.m_value.binary->cend() - 1; ++i)
                        {
                            dump_byte(*i);
                            put_char(',');
                        }
                        dump_byte(val.m_data.m_value.binary->back());
                    }
                    put_literal("],\"subtype\":");
                    if (val.m_data.m_value.binary->has_subtype())
                    {
                        dump_integer(val.m_data.m_value.binary->subtype());
                        put_char('}');
                    }
                    else
                    {
                        put_literal("null}");
                    }
                }
                return;
            }
            case value_t::boolean:
            {
                if (val.m_data.m_value.boolean)
                {
                    put_literal("true");
                }
                else
                {
                    put_literal("false");
                }
                return;
            }
            case value_t::number_integer:
            {
                dump_integer(val.m_data.m_value.number_integer);
                return;
            }
            case value_t::number_unsigned:
            {
                dump_integer(val.m_data.m_value.number_unsigned);
                return;
            }
            case value_t::number_float:
            {
                dump_float(val.m_data.m_value.number_float);
                return;
            }
            case value_t::discarded:
            {
                put_literal("<discarded>");
                return;
            }
            case value_t::null:
            {
                put_literal("null");
                return;
            }
            case value_t::object: 
            case value_t::array:  
            default:            
                JSON_ASSERT(false); 
        }
    }
    static std::size_t next_indent(const std::size_t current_indent, const std::size_t indent_step)
    {
        const std::size_t new_indent = current_indent + indent_step;
        JSON_ASSERT(new_indent >= current_indent);
        return new_indent;
    }
  JSON_PRIVATE_UNLESS_TESTED:
    void dump_escaped(const string_t& s)
    {
        if (ensure_ascii)
        {
            dump_escaped_impl<true>(s);
        }
        else
        {
            dump_escaped_impl<false>(s);
        }
    }
    template<bool EnsureAscii>
    void dump_escaped_impl(const string_t& s)
    {
        std::uint32_t codepoint{};
        std::uint8_t state = UTF8_ACCEPT;
        std::size_t bytes = 0;  
        std::size_t bytes_after_last_accept = 0;
        std::size_t undumped_chars = 0;
        for (std::size_t i = 0; i < s.size(); ++i)
        {
            if (state == UTF8_ACCEPT)
            {
                const auto* const data = reinterpret_cast<const unsigned char*>(s.data());
                std::size_t run = 0;
                if (!EnsureAscii)
                {
                    run = string_bulk_run(data + i, s.size() - i);
                }
                else if (is_ascii_copyable(data[i]))
                {
                    run = find_ascii_copyable_run(data + i, s.size() - i);
                }
                if (run != 0)
                {
                    if (bytes != 0)
                    {
                        put_buffer(string_buffer, bytes);
                        bytes = 0;
                    }
                    put_string(s, i, i + run);
                    bytes_after_last_accept = 0;
                    undumped_chars = 0;
                    i += run;
                    if (i >= s.size())
                    {
                        break;
                    }
                }
            }
            const auto byte = static_cast<std::uint8_t>(s[i]);
            switch (decode(state, codepoint, byte))
            {
                case UTF8_ACCEPT:  
                {
                    switch (codepoint)
                    {
                        case 0x08: 
                        {
                            string_buffer[bytes++] = '\\';
                            string_buffer[bytes++] = 'b';
                            break;
                        }
                        case 0x09: 
                        {
                            string_buffer[bytes++] = '\\';
                            string_buffer[bytes++] = 't';
                            break;
                        }
                        case 0x0A: 
                        {
                            string_buffer[bytes++] = '\\';
                            string_buffer[bytes++] = 'n';
                            break;
                        }
                        case 0x0C: 
                        {
                            string_buffer[bytes++] = '\\';
                            string_buffer[bytes++] = 'f';
                            break;
                        }
                        case 0x0D: 
                        {
                            string_buffer[bytes++] = '\\';
                            string_buffer[bytes++] = 'r';
                            break;
                        }
                        case 0x22: 
                        {
                            string_buffer[bytes++] = '\\';
                            string_buffer[bytes++] = '"';
                            break;
                        }
                        case 0x5C: 
                        {
                            string_buffer[bytes++] = '\\';
                            string_buffer[bytes++] = '\\';
                            break;
                        }
                        default:
                        {
                            if ((codepoint <= 0x1F) || (EnsureAscii && (codepoint >= 0x7F)))
                            {
                                if (codepoint <= 0xFFFF)
                                {
                                    write_u_escape(bytes, static_cast<std::uint16_t>(codepoint));
                                }
                                else
                                {
                                    write_u_escape(bytes, static_cast<std::uint16_t>(0xD7C0u + (codepoint >> 10u)));
                                    write_u_escape(bytes, static_cast<std::uint16_t>(0xDC00u + (codepoint & 0x3FFu)));
                                }
                            }
                            else
                            {
                                string_buffer[bytes++] = s[i];
                            }
                            break;
                        }
                    }
                    if (string_buffer.size() - bytes < 13)
                    {
                        put_buffer(string_buffer, bytes);
                        bytes = 0;
                    }
                    bytes_after_last_accept = bytes;
                    undumped_chars = 0;
                    break;
                }
                case UTF8_REJECT:  
                {
                    switch (error_handler)
                    {
                        case error_handler_t::strict:
                        {
                            JSON_THROW(type_error::create(316, concat("invalid UTF-8 byte at index ", std::to_string(i), ": 0x", detail::hex_byte(byte)), nullptr));
                        }
                        case error_handler_t::ignore:
                        case error_handler_t::replace:
                        {
                            if (undumped_chars > 0)
                            {
                                --i;
                            }
                            bytes = bytes_after_last_accept;
                            if (error_handler == error_handler_t::replace)
                            {
                                if (EnsureAscii)
                                {
                                    string_buffer[bytes++] = '\\';
                                    string_buffer[bytes++] = 'u';
                                    string_buffer[bytes++] = 'f';
                                    string_buffer[bytes++] = 'f';
                                    string_buffer[bytes++] = 'f';
                                    string_buffer[bytes++] = 'd';
                                }
                                else
                                {
                                    string_buffer[bytes++] = '\xEF';
                                    string_buffer[bytes++] = '\xBF';
                                    string_buffer[bytes++] = '\xBD';
                                }
                                if (string_buffer.size() - bytes < 13)
                                {
                                    put_buffer(string_buffer, bytes);
                                    bytes = 0;
                                }
                                bytes_after_last_accept = bytes;
                            }
                            undumped_chars = 0;
                            state = UTF8_ACCEPT;
                            break;
                        }
                        default:            
                            JSON_ASSERT(false); 
                    }
                    break;
                }
                default:  
                {
                    if (!EnsureAscii)
                    {
                        string_buffer[bytes++] = s[i];
                    }
                    ++undumped_chars;
                    break;
                }
            }
        }
        if (JSON_HEDLEY_LIKELY(state == UTF8_ACCEPT))
        {
            if (bytes > 0)
            {
                put_buffer(string_buffer, bytes);
            }
        }
        else
        {
            switch (error_handler)
            {
                case error_handler_t::strict:
                {
                    JSON_THROW(type_error::create(316, concat("incomplete UTF-8 string; last byte: 0x", detail::hex_byte(static_cast<std::uint8_t>(s[s.size() - 1]))), nullptr));
                }
                case error_handler_t::ignore:
                {
                    put_buffer(string_buffer, bytes_after_last_accept);
                    break;
                }
                case error_handler_t::replace:
                {
                    put_buffer(string_buffer, bytes_after_last_accept);
                    if (EnsureAscii)
                    {
                        put_literal("\\ufffd");
                    }
                    else
                    {
                        put_literal("\xEF\xBF\xBD");
                    }
                    break;
                }
                default:            
                    JSON_ASSERT(false); 
            }
        }
    }
  private:
    void put_char(char c)
    {
        if (JSON_HEDLEY_UNLIKELY(write_buffer_pos == write_buffer.size()))
        {
            flush();
        }
        write_buffer[write_buffer_pos++] = c;
    }
    void put_indent(std::size_t indent)
    {
        if (indent == 0)
        {
            return;
        }
        const std::size_t capacity = write_buffer.size();
        const std::size_t head = (std::min)(indent, capacity - write_buffer_pos);
        std::memset(write_buffer.data() + write_buffer_pos, indent_char, head);
        write_buffer_pos += head;
        indent -= head;
        if (JSON_HEDLEY_LIKELY(indent == 0))
        {
            return;
        }
        flush();
        std::memset(write_buffer.data(), indent_char, capacity);
        while (indent >= capacity)
        {
            write_buffer_pos = capacity;
            flush();
            indent -= capacity;
        }
        write_buffer_pos = indent;
    }
    template<std::size_t N>
    void put_literal(const char (&s)[N]) 
    {
        static_assert(N >= 2, "put_literal expects a non-empty string literal");
        constexpr std::size_t length = N - 1;
        static_assert(length < write_buffer_size, "string literal must fit into the write buffer");
        if (JSON_HEDLEY_UNLIKELY(write_buffer_pos + length > write_buffer.size()))
        {
            flush();
        }
        std::memcpy(write_buffer.data() + write_buffer_pos, s, length);
        write_buffer_pos += length;
    }
    template<typename StringType>
    void put_string(const StringType& str, std::size_t start, std::size_t end)
    {
        JSON_ASSERT(start <= end);
        JSON_ASSERT(end <= str.size());
        const char* const s = str.data() + start;
        const std::size_t length = end - start;
        if (JSON_HEDLEY_UNLIKELY(length >= write_buffer.size()))
        {
            flush();
            o->write_characters(s, length);
            return;
        }
        if (JSON_HEDLEY_UNLIKELY(write_buffer_pos + length > write_buffer.size()))
        {
            flush();
        }
        std::memcpy(write_buffer.data() + write_buffer_pos, s, length);
        write_buffer_pos += length;
    }
    template<std::size_t N>
    void put_buffer(const std::array<char, N>& buffer, std::size_t length)
    {
        put_string(buffer, 0, length);
    }
  JSON_PRIVATE_UNLESS_TESTED:
    void flush()
    {
        o->write_characters(write_buffer.data(), write_buffer_pos);
        write_buffer_pos = 0;
    }
  private:
    unsigned int count_digits(number_unsigned_t x) noexcept
    {
        unsigned int n_digits = 1;
        for (;;)
        {
            if (x < 10)
            {
                return n_digits;
            }
            if (x < 100)
            {
                return n_digits + 1;
            }
            if (x < 1000)
            {
                return n_digits + 2;
            }
            if (x < 10000)
            {
                return n_digits + 3;
            }
            x = x / 10000u;
            n_digits += 4;
        }
    }
    void write_u_escape(std::size_t& pos, std::uint16_t codeunit) noexcept
    {
        JSON_ASSERT(string_buffer.size() - pos >= 6);
        constexpr const char* nibble_to_hex = "0123456789abcdef";
        string_buffer[pos + 0] = '\\';
        string_buffer[pos + 1] = 'u';
        string_buffer[pos + 2] = nibble_to_hex[(codeunit >> 12u) & 0x0Fu];
        string_buffer[pos + 3] = nibble_to_hex[(codeunit >> 8u) & 0x0Fu];
        string_buffer[pos + 4] = nibble_to_hex[(codeunit >> 4u) & 0x0Fu];
        string_buffer[pos + 5] = nibble_to_hex[codeunit & 0x0Fu];
        pos += 6;
    }
    static std::uint8_t to_byte_value(binary_char_t x) noexcept
    {
        return static_cast<std::uint8_t>(x);
    }
    template <typename NumberType, enable_if_t<std::is_signed<NumberType>::value, int> = 0>
    bool is_negative_number(NumberType x)
    {
        return x < 0;
    }
    template < typename NumberType, enable_if_t <std::is_unsigned<NumberType>::value, int > = 0 >
    bool is_negative_number(NumberType )
    {
        return false;
    }
    template<typename ByteType>
    void dump_byte(const ByteType value)
    {
        dump_byte(value, std::integral_constant < bool,
                  std::is_unsigned<ByteType>::value && sizeof(ByteType) == 1
                  && !std::is_same<ByteType, bool>::value > {});
    }
    template<typename ByteType>
    void dump_byte(const ByteType value, std::false_type )
    {
        dump_integer(to_byte_value(value));
    }
    template<typename ByteType>
    void dump_byte(const ByteType value, std::true_type )
    {
        if (JSON_HEDLEY_UNLIKELY(write_buffer_pos + 3 > write_buffer.size()))
        {
            flush();
        }
        const auto byte = static_cast<unsigned>(value);
        std::size_t pos = write_buffer_pos;
        if (byte >= 100)
        {
            write_buffer[pos++] = static_cast<char>('0' + (byte / 100));
            write_buffer[pos++] = static_cast<char>('0' + ((byte / 10) % 10));
        }
        else if (byte >= 10)
        {
            write_buffer[pos++] = static_cast<char>('0' + (byte / 10));
        }
        write_buffer[pos++] = static_cast<char>('0' + (byte % 10));
        write_buffer_pos = pos;
    }
    template < typename NumberType, detail::enable_if_t <
                   std::is_integral<NumberType>::value ||
                   std::is_same<NumberType, number_unsigned_t>::value ||
                   std::is_same<NumberType, number_integer_t>::value,
                   int > = 0 >
    void dump_integer(NumberType x)
    {
        static constexpr std::array<std::array<char, 2>, 100> digits_to_99
        {
            {
                {{'0', '0'}}, {{'0', '1'}}, {{'0', '2'}}, {{'0', '3'}}, {{'0', '4'}}, {{'0', '5'}}, {{'0', '6'}}, {{'0', '7'}}, {{'0', '8'}}, {{'0', '9'}},
                {{'1', '0'}}, {{'1', '1'}}, {{'1', '2'}}, {{'1', '3'}}, {{'1', '4'}}, {{'1', '5'}}, {{'1', '6'}}, {{'1', '7'}}, {{'1', '8'}}, {{'1', '9'}},
                {{'2', '0'}}, {{'2', '1'}}, {{'2', '2'}}, {{'2', '3'}}, {{'2', '4'}}, {{'2', '5'}}, {{'2', '6'}}, {{'2', '7'}}, {{'2', '8'}}, {{'2', '9'}},
                {{'3', '0'}}, {{'3', '1'}}, {{'3', '2'}}, {{'3', '3'}}, {{'3', '4'}}, {{'3', '5'}}, {{'3', '6'}}, {{'3', '7'}}, {{'3', '8'}}, {{'3', '9'}},
                {{'4', '0'}}, {{'4', '1'}}, {{'4', '2'}}, {{'4', '3'}}, {{'4', '4'}}, {{'4', '5'}}, {{'4', '6'}}, {{'4', '7'}}, {{'4', '8'}}, {{'4', '9'}},
                {{'5', '0'}}, {{'5', '1'}}, {{'5', '2'}}, {{'5', '3'}}, {{'5', '4'}}, {{'5', '5'}}, {{'5', '6'}}, {{'5', '7'}}, {{'5', '8'}}, {{'5', '9'}},
                {{'6', '0'}}, {{'6', '1'}}, {{'6', '2'}}, {{'6', '3'}}, {{'6', '4'}}, {{'6', '5'}}, {{'6', '6'}}, {{'6', '7'}}, {{'6', '8'}}, {{'6', '9'}},
                {{'7', '0'}}, {{'7', '1'}}, {{'7', '2'}}, {{'7', '3'}}, {{'7', '4'}}, {{'7', '5'}}, {{'7', '6'}}, {{'7', '7'}}, {{'7', '8'}}, {{'7', '9'}},
                {{'8', '0'}}, {{'8', '1'}}, {{'8', '2'}}, {{'8', '3'}}, {{'8', '4'}}, {{'8', '5'}}, {{'8', '6'}}, {{'8', '7'}}, {{'8', '8'}}, {{'8', '9'}},
                {{'9', '0'}}, {{'9', '1'}}, {{'9', '2'}}, {{'9', '3'}}, {{'9', '4'}}, {{'9', '5'}}, {{'9', '6'}}, {{'9', '7'}}, {{'9', '8'}}, {{'9', '9'}},
            }
        };
        if (x == 0)
        {
            put_char('0');
            return;
        }
        auto buffer_ptr = number_buffer.begin(); 
        number_unsigned_t abs_value;
        unsigned int n_chars{};
        if (is_negative_number(x))
        {
            *buffer_ptr = '-';
            abs_value = remove_sign(static_cast<number_integer_t>(x));
            n_chars = 1 + count_digits(abs_value);
        }
        else
        {
            abs_value = static_cast<number_unsigned_t>(x);
            n_chars = count_digits(abs_value);
        }
        JSON_ASSERT(n_chars < number_buffer.size() - 1);
        buffer_ptr += static_cast<typename decltype(number_buffer)::difference_type>(n_chars);
        while (abs_value >= 100)
        {
            const auto digits_index = static_cast<unsigned>((abs_value % 100));
            abs_value /= 100;
            *(--buffer_ptr) = digits_to_99[digits_index][1];
            *(--buffer_ptr) = digits_to_99[digits_index][0];
        }
        if (abs_value >= 10)
        {
            const auto digits_index = static_cast<unsigned>(abs_value);
            *(--buffer_ptr) = digits_to_99[digits_index][1];
            *(--buffer_ptr) = digits_to_99[digits_index][0];
        }
        else
        {
            *(--buffer_ptr) = static_cast<char>('0' + abs_value);
        }
        put_buffer(number_buffer, n_chars);
    }
    void dump_float(number_float_t x)
    {
        if (!std::isfinite(x))
        {
            put_literal("null");
            return;
        }
        static constexpr bool is_ieee_single_or_double
            = (std::numeric_limits<number_float_t>::is_iec559 && std::numeric_limits<number_float_t>::digits == 24 && std::numeric_limits<number_float_t>::max_exponent == 128) ||
              (std::numeric_limits<number_float_t>::is_iec559 && std::numeric_limits<number_float_t>::digits == 53 && std::numeric_limits<number_float_t>::max_exponent == 1024);
        dump_float(x, std::integral_constant<bool, is_ieee_single_or_double>());
    }
    void dump_float(number_float_t x, std::true_type )
    {
        auto* begin = number_buffer.data();
        auto* end = ::nlohmann::detail::to_chars(begin, begin + number_buffer.size(), x);
        put_buffer(number_buffer, static_cast<std::size_t>(end - begin));
    }
    JSON_HEDLEY_NON_NULL(1)
    static int snprintf_float(char* buf, std::size_t size, int d, double x)
    {
        return (std::snprintf)(buf, size, "%.*g", d, x);
    }
    JSON_HEDLEY_NON_NULL(1)
    static int snprintf_float(char* buf, std::size_t size, int d, long double x)
    {
        return (std::snprintf)(buf, size, "%.*Lg", d, x);
    }
    void dump_float(number_float_t x, std::false_type )
    {
        static constexpr auto d = std::numeric_limits<number_float_t>::max_digits10;
        std::ptrdiff_t len = snprintf_float(number_buffer.data(), number_buffer.size(), d, x);
        JSON_ASSERT(len > 0);
        JSON_ASSERT(static_cast<std::size_t>(len) < number_buffer.size());
        const auto* loc = std::localeconv();
        JSON_ASSERT(loc != nullptr);
        const char thousands_sep = (loc->thousands_sep == nullptr) ? '\0' : *loc->thousands_sep;
        const char decimal_point = (loc->decimal_point == nullptr) ? '\0' : *loc->decimal_point;
        if (thousands_sep != '\0')
        {
            const auto end = std::remove(number_buffer.begin(), number_buffer.begin() + len, thousands_sep);
            std::fill(end, number_buffer.end(), '\0');
            JSON_ASSERT((end - number_buffer.begin()) <= len);
            len = (end - number_buffer.begin());
        }
        if (decimal_point != '\0' && decimal_point != '.')
        {
            const auto dec_pos = std::find(number_buffer.begin(), number_buffer.end(), decimal_point);
            if (dec_pos != number_buffer.end())
            {
                *dec_pos = '.';
            }
        }
        put_buffer(number_buffer, static_cast<std::size_t>(len));
        const bool value_is_int_like =
            std::none_of(number_buffer.begin(), number_buffer.begin() + len + 1,
                         [](char c)
        {
            return c == '.' || c == 'e';
        });
        if (value_is_int_like)
        {
            put_literal(".0");
        }
    }
    number_unsigned_t remove_sign(number_unsigned_t x)
    {
        JSON_ASSERT(false); 
        return x; 
    }
    number_unsigned_t remove_sign(number_integer_t x) noexcept
    {
        JSON_ASSERT(x < 0);
        return static_cast<number_unsigned_t>(-(x + 1)) + 1;
    }
  private:
    output_adapter_protocol<char>* o = nullptr;
    std::array<char, 64> number_buffer{{}};
    std::array<char, 512> string_buffer{{}};
    const char indent_char;
    const bool pretty_print;
    const bool ensure_ascii;
    const std::size_t indent_step;
    const error_handler_t error_handler;
    static constexpr std::size_t write_buffer_size = 1024;
    std::array<char, write_buffer_size> write_buffer{{}};
    std::size_t write_buffer_pos = 0;
};
}  
NLOHMANN_JSON_NAMESPACE_END
#include <algorithm> 
#include <functional> 
#include <initializer_list> 
#include <iterator> 
#include <memory> 
#include <new> 
#include <stdexcept> 
#include <tuple> 
#include <type_traits> 
#include <utility> 
#include <vector> 
NLOHMANN_JSON_NAMESPACE_BEGIN
template <class Key, class T, class IgnoredLess = std::less<Key>,
          class Allocator = std::allocator<std::pair<const Key, T>>>
              struct ordered_map : std::vector<std::pair<const Key, T>, Allocator>
{
    using key_type = Key;
    using mapped_type = T;
    using Container = std::vector<std::pair<const Key, T>, Allocator>;
    using iterator = typename Container::iterator;
    using const_iterator = typename Container::const_iterator;
    using size_type = typename Container::size_type;
    using value_type = typename Container::value_type;
#ifdef JSON_HAS_CPP_14
    using key_compare = std::equal_to<>;
#else
    using key_compare = std::equal_to<Key>;
#endif
    ordered_map() noexcept(noexcept(Container())) : Container{} {}
    explicit ordered_map(const Allocator& alloc) noexcept(noexcept(Container(alloc))) : Container{alloc} {}
    template <class It>
    ordered_map(It first, It last, const Allocator& alloc = Allocator())
        : Container{first, last, alloc} {}
    ordered_map(std::initializer_list<value_type> init, const Allocator& alloc = Allocator() )
        : Container{init, alloc} {}
    ordered_map(const ordered_map&) = default;
    ordered_map(ordered_map&&) noexcept(std::is_nothrow_move_constructible<Container>::value) = default;
    ~ordered_map() = default;
    ordered_map& operator=(const ordered_map& other)
    {
        if (this != &other)
        {
            ordered_map tmp(other);
            Container::operator=(std::move(static_cast<Container&>(tmp)));
        }
        return *this;
    }
    ordered_map& operator=(ordered_map&& other) noexcept(std::is_nothrow_move_assignable<Container>::value)
    {
        Container::operator=(std::move(static_cast<Container&>(other)));
        return *this;
    }
    std::pair<iterator, bool> emplace(const key_type& key, T&& t)
    {
        for (auto it = this->begin(); it != this->end(); ++it)
        {
            if (m_compare(it->first, key))
            {
                return {it, false};
            }
        }
        append(key, std::forward<T>(t));
        return {std::prev(this->end()), true};
    }
    template<class KeyType, detail::enable_if_t<
                 detail::is_usable_as_key_type<key_compare, key_type, KeyType>::value, int> = 0>
    std::pair<iterator, bool> emplace(KeyType && key, T && t)
    {
        for (auto it = this->begin(); it != this->end(); ++it)
        {
            if (m_compare(it->first, key))
            {
                return {it, false};
            }
        }
        append(std::forward<KeyType>(key), std::forward<T>(t));
        return {std::prev(this->end()), true};
    }
    T& operator[](const key_type& key)
    {
        return emplace(key, T{}).first->second;
    }
    template<class KeyType, detail::enable_if_t<
                 detail::is_usable_as_key_type<key_compare, key_type, KeyType>::value, int> = 0>
    T & operator[](KeyType && key)
    {
        return emplace(std::forward<KeyType>(key), T{}).first->second;
    }
    const T& operator[](const key_type& key) const
    {
        return at(key);
    }
    template<class KeyType, detail::enable_if_t<
                 detail::is_usable_as_key_type<key_compare, key_type, KeyType>::value, int> = 0>
    const T & operator[](KeyType && key) const
    {
        return at(std::forward<KeyType>(key));
    }
    T& at(const key_type& key)
    {
        for (auto it = this->begin(); it != this->end(); ++it)
        {
            if (m_compare(it->first, key))
            {
                return it->second;
            }
        }
        JSON_THROW(std::out_of_range("key not found"));
    }
    template<class KeyType, detail::enable_if_t<
                 detail::is_usable_as_key_type<key_compare, key_type, KeyType>::value, int> = 0>
    T & at(KeyType && key) 
    {
        for (auto it = this->begin(); it != this->end(); ++it)
        {
            if (m_compare(it->first, key))
            {
                return it->second;
            }
        }
        JSON_THROW(std::out_of_range("key not found"));
    }
    const T& at(const key_type& key) const
    {
        for (auto it = this->begin(); it != this->end(); ++it)
        {
            if (m_compare(it->first, key))
            {
                return it->second;
            }
        }
        JSON_THROW(std::out_of_range("key not found"));
    }
    template<class KeyType, detail::enable_if_t<
                 detail::is_usable_as_key_type<key_compare, key_type, KeyType>::value, int> = 0>
    const T & at(KeyType && key) const 
    {
        for (auto it = this->begin(); it != this->end(); ++it)
        {
            if (m_compare(it->first, key))
            {
                return it->second;
            }
        }
        JSON_THROW(std::out_of_range("key not found"));
    }
    size_type erase(const key_type& key)
    {
        for (auto it = this->begin(); it != this->end(); ++it)
        {
            if (m_compare(it->first, key))
            {
                for (auto next = it; ++next != this->end(); ++it)
                {
                    it->~value_type(); 
                    new (&*it) value_type{std::move(*next)};
                }
                Container::pop_back();
                return 1;
            }
        }
        return 0;
    }
    template<class KeyType, detail::enable_if_t<
                 detail::is_usable_as_key_type<key_compare, key_type, KeyType>::value, int> = 0>
    size_type erase(KeyType && key) 
    {
        for (auto it = this->begin(); it != this->end(); ++it)
        {
            if (m_compare(it->first, key))
            {
                for (auto next = it; ++next != this->end(); ++it)
                {
                    it->~value_type(); 
                    new (&*it) value_type{std::move(*next)};
                }
                Container::pop_back();
                return 1;
            }
        }
        return 0;
    }
    iterator erase(iterator pos)
    {
        return erase(pos, std::next(pos));
    }
    iterator erase(iterator first, iterator last)
    {
        if (first == last)
        {
            return first;
        }
        const auto elements_affected = std::distance(first, last);
        const auto offset = std::distance(Container::begin(), first);
        for (auto it = first; std::next(it, elements_affected) != Container::end(); ++it)
        {
            it->~value_type(); 
            new (&*it) value_type{std::move(*std::next(it, elements_affected))}; 
        }
        Container::resize(this->size() - static_cast<size_type>(elements_affected));
        return Container::begin() + offset;
    }
    size_type count(const key_type& key) const
    {
        for (auto it = this->begin(); it != this->end(); ++it)
        {
            if (m_compare(it->first, key))
            {
                return 1;
            }
        }
        return 0;
    }
    template<class KeyType, detail::enable_if_t<
                 detail::is_usable_as_key_type<key_compare, key_type, KeyType>::value, int> = 0>
    size_type count(KeyType && key) const 
    {
        for (auto it = this->begin(); it != this->end(); ++it)
        {
            if (m_compare(it->first, key))
            {
                return 1;
            }
        }
        return 0;
    }
    iterator find(const key_type& key)
    {
        for (auto it = this->begin(); it != this->end(); ++it)
        {
            if (m_compare(it->first, key))
            {
                return it;
            }
        }
        return Container::end();
    }
    template<class KeyType, detail::enable_if_t<
                 detail::is_usable_as_key_type<key_compare, key_type, KeyType>::value, int> = 0>
    iterator find(KeyType && key) 
    {
        for (auto it = this->begin(); it != this->end(); ++it)
        {
            if (m_compare(it->first, key))
            {
                return it;
            }
        }
        return Container::end();
    }
    const_iterator find(const key_type& key) const
    {
        for (auto it = this->begin(); it != this->end(); ++it)
        {
            if (m_compare(it->first, key))
            {
                return it;
            }
        }
        return Container::end();
    }
    template<class KeyType, detail::enable_if_t<
                 detail::is_usable_as_key_type<key_compare, key_type, KeyType>::value, int> = 0>
    const_iterator find(KeyType && key) const 
    {
        for (auto it = this->begin(); it != this->end(); ++it)
        {
            if (m_compare(it->first, key))
            {
                return it;
            }
        }
        return Container::end();
    }
    std::pair<iterator, bool> insert( value_type&& value )
    {
        return emplace(value.first, std::move(value.second));
    }
    std::pair<iterator, bool> insert( const value_type& value )
    {
        for (auto it = this->begin(); it != this->end(); ++it)
        {
            if (m_compare(it->first, value.first))
            {
                return {it, false};
            }
        }
        append(value);
        return {--this->end(), true};
    }
    template<typename InputIt>
    using require_input_iter = typename std::enable_if<std::is_convertible<typename std::iterator_traits<InputIt>::iterator_category,
        std::input_iterator_tag>::value>::type;
    template<typename InputIt, typename = require_input_iter<InputIt>>
    void insert(InputIt first, InputIt last)
    {
        for (auto it = first; it != last; ++it)
        {
            insert(*it);
        }
    }
private:
    template<typename... Args>
    void append(Args&& ... args)
    {
        using move_values = std::integral_constant<bool, detail::conjunction<
                detail::negation<std::is_nothrow_move_constructible<value_type>>,
                std::is_copy_constructible<key_type>,
                detail::is_default_constructible<mapped_type>,
                std::is_nothrow_move_assignable<mapped_type>>::value>;
        append_impl(move_values{}, std::forward<Args>(args)...);
    }
    template<typename... Args>
    void append_impl(std::true_type , Args&& ... args)
    {
        if (this->size() < this->capacity())
        {
            Container::emplace_back(std::forward<Args>(args)...);
            return;
        }
        Container tmp(this->get_allocator()); 
        tmp.reserve((std::min)(this->max_size(), (std::max)(size_type{1}, 2 * this->size())));
        for (const auto& element : *this)
        {
            tmp.emplace_back(std::piecewise_construct, std::forward_as_tuple(element.first), std::forward_as_tuple());
        }
        tmp.emplace_back(std::forward<Args>(args)...);
        auto it = tmp.begin();
        for (auto& element : *this)
        {
            it->second = std::move(element.second);
            ++it;
        }
        Container::swap(tmp);
    }
    template<typename... Args>
    void append_impl(std::false_type , Args&& ... args)
    {
        Container::emplace_back(std::forward<Args>(args)...);
    }
    JSON_NO_UNIQUE_ADDRESS key_compare m_compare = key_compare();
};
NLOHMANN_JSON_NAMESPACE_END
#if defined(JSON_HAS_CPP_17)
    #if JSON_HAS_STATIC_RTTI
        #include <any>
    #endif
    #include <string_view>
#endif
#if JSON_HAS_STD_FORMAT
    #include <format> 
#endif
NLOHMANN_JSON_NAMESPACE_BEGIN
namespace detail
{
template<typename>
struct is_std_optional : std::false_type {};
#ifdef JSON_HAS_CPP_17
template<typename T>
struct is_std_optional<std::optional<T>> : std::true_type {};
#endif
}  
NLOHMANN_BASIC_JSON_TPL_DECLARATION
class basic_json 
    : public ::nlohmann::detail::json_base_class<CustomBaseClass>
{
  private:
    template<detail::value_t> friend struct detail::external_constructor;
    template<typename>
    friend class ::nlohmann::json_pointer;
    template<typename BasicJsonType, typename InputType>
    friend class ::nlohmann::detail::parser;
    friend ::nlohmann::detail::serializer<basic_json>;
    template<typename BasicJsonType>
    friend class ::nlohmann::detail::iter_impl;
    template<typename BasicJsonType, typename CharType, typename OutputSinkType>
    friend class ::nlohmann::detail::binary_writer;
    template<typename BasicJsonType, typename InputType, typename SAX>
    friend class ::nlohmann::detail::binary_reader;
    template<typename BasicJsonType, typename InputAdapterType>
    friend class ::nlohmann::detail::json_sax_dom_parser;
    template<typename BasicJsonType, typename InputAdapterType>
    friend class ::nlohmann::detail::json_sax_dom_callback_parser;
#if JSON_DIAGNOSTIC_POSITIONS
    friend struct ::nlohmann::detail::diagnostic_positions;
#endif
    friend class ::nlohmann::detail::exception;
    using basic_json_t = NLOHMANN_BASIC_JSON_TPL;
    using json_base_class_t = ::nlohmann::detail::json_base_class<CustomBaseClass>;
  JSON_PRIVATE_UNLESS_TESTED:
    using lexer = ::nlohmann::detail::lexer_base<basic_json>;
    template<typename InputAdapterType>
    static ::nlohmann::detail::parser<basic_json, InputAdapterType> parser(
        InputAdapterType adapter,
        detail::parser_callback_t<basic_json>cb = nullptr,
        const bool allow_exceptions = true,
        const bool ignore_comments = false,
        const bool ignore_trailing_commas = false,
        const bool discard_number_values = false
                                 )
    {
        return ::nlohmann::detail::parser<basic_json, InputAdapterType>(std::move(adapter),
            std::move(cb), allow_exceptions, ignore_comments, ignore_trailing_commas, discard_number_values);
    }
  private:
    using primitive_iterator_t = ::nlohmann::detail::primitive_iterator_t;
    template<typename BasicJsonType>
    using internal_iterator = ::nlohmann::detail::internal_iterator<BasicJsonType>;
    template<typename BasicJsonType>
    using iter_impl = ::nlohmann::detail::iter_impl<BasicJsonType>;
    template<typename Iterator>
    using iteration_proxy = ::nlohmann::detail::iteration_proxy<Iterator>;
    template<typename Base> using json_reverse_iterator = ::nlohmann::detail::json_reverse_iterator<Base>;
    template<typename CharType>
    using output_adapter_t = ::nlohmann::detail::output_adapter_t<CharType>;
    template<typename InputType>
    using binary_reader = ::nlohmann::detail::binary_reader<basic_json, InputType>;
    template<typename CharType> using binary_writer = ::nlohmann::detail::binary_writer<basic_json, CharType>;
    template<typename CharType> using vector_binary_writer =
    ::nlohmann::detail::binary_writer<basic_json, CharType, ::nlohmann::detail::output_vector_sink<CharType>>;
    template<typename CharType> static vector_binary_writer<CharType> vector_writer(std::vector<CharType>& v)
    {
        return vector_binary_writer<CharType>(::nlohmann::detail::output_vector_sink<CharType>(v));
    }
  JSON_PRIVATE_UNLESS_TESTED:
    using serializer = ::nlohmann::detail::serializer<basic_json>;
  public:
    using value_t = detail::value_t;
    using json_pointer = ::nlohmann::json_pointer<StringType>;
    template<typename T, typename SFINAE>
    using json_serializer = JSONSerializer<T, SFINAE>;
    using error_handler_t = detail::error_handler_t;
    using cbor_tag_handler_t = detail::cbor_tag_handler_t;
    using bjdata_version_t = detail::bjdata_version_t;
    using initializer_list_t = std::initializer_list<detail::json_ref<basic_json>>;
    using input_format_t = detail::input_format_t;
    using json_sax_t = json_sax<basic_json>;
    using exception = detail::exception;
    using parse_error = detail::parse_error;
    using invalid_iterator = detail::invalid_iterator;
    using type_error = detail::type_error;
    using out_of_range = detail::out_of_range;
    using other_error = detail::other_error;
    using value_type = basic_json;
    using reference = value_type&;
    using const_reference = const value_type&;
    using difference_type = std::ptrdiff_t;
    using size_type = std::size_t;
    using allocator_type = AllocatorType<basic_json>;
    using pointer = typename std::allocator_traits<allocator_type>::pointer;
    using const_pointer = typename std::allocator_traits<allocator_type>::const_pointer;
    using iterator = iter_impl<basic_json>;
    using const_iterator = iter_impl<const basic_json>;
    using reverse_iterator = json_reverse_iterator<typename basic_json::iterator>;
    using const_reverse_iterator = json_reverse_iterator<typename basic_json::const_iterator>;
    static allocator_type get_allocator()
    {
        return allocator_type();
    }
    JSON_HEDLEY_WARN_UNUSED_RESULT
    static basic_json meta()
    {
        basic_json result;
        result["copyright"] = "(C) 2013-2026 Niels Lohmann";
        result["name"] = "JSON for Modern C++";
        result["url"] = "https://github.com/nlohmann/json";
        result["version"]["string"] =
            detail::concat(std::to_string(NLOHMANN_JSON_VERSION_MAJOR), '.',
                           std::to_string(NLOHMANN_JSON_VERSION_MINOR), '.',
                           std::to_string(NLOHMANN_JSON_VERSION_PATCH));
        result["version"]["major"] = NLOHMANN_JSON_VERSION_MAJOR;
        result["version"]["minor"] = NLOHMANN_JSON_VERSION_MINOR;
        result["version"]["patch"] = NLOHMANN_JSON_VERSION_PATCH;
#ifdef _WIN32
        result["platform"] = "win32";
#elif defined __linux__
        result["platform"] = "linux";
#elif defined __APPLE__
        result["platform"] = "apple";
#elif defined __unix__
        result["platform"] = "unix";
#else
        result["platform"] = "unknown";
#endif
#if defined(__ICC) || defined(__INTEL_COMPILER)
        result["compiler"] = {{"family", "icc"}, {"version", __INTEL_COMPILER}};
#elif defined(__clang__)
        result["compiler"] = {{"family", "clang"}, {"version", __clang_version__}};
#elif defined(__GNUC__) || defined(__GNUG__)
        result["compiler"] = {{"family", "gcc"}, {"version", detail::concat(
                    std::to_string(__GNUC__), '.',
                    std::to_string(__GNUC_MINOR__), '.',
                    std::to_string(__GNUC_PATCHLEVEL__))
            }
        };
#elif defined(__HP_cc) || defined(__HP_aCC)
        result["compiler"] = "hp"
#elif defined(__IBMCPP__)
        result["compiler"] = {{"family", "ilecpp"}, {"version", __IBMCPP__}};
#elif defined(_MSC_VER)
        result["compiler"] = {{"family", "msvc"}, {"version", _MSC_VER}};
#elif defined(__PGI)
        result["compiler"] = {{"family", "pgcpp"}, {"version", __PGI}};
#elif defined(__SUNPRO_CC)
        result["compiler"] = {{"family", "sunpro"}, {"version", __SUNPRO_CC}};
#else
        result["compiler"] = {{"family", "unknown"}, {"version", "unknown"}};
#endif
#if defined(_MSVC_LANG)
        result["compiler"]["c++"] = std::to_string(_MSVC_LANG);
#elif defined(__cplusplus)
        result["compiler"]["c++"] = std::to_string(__cplusplus);
#else
        result["compiler"]["c++"] = "unknown";
#endif
        return result;
    }
#if defined(JSON_HAS_CPP_14)
    using default_object_comparator_t = std::less<>;
#else
    using default_object_comparator_t = std::less<StringType>;
#endif
    using object_t = ObjectType<StringType,
          basic_json,
          default_object_comparator_t,
          AllocatorType<std::pair<const StringType,
          basic_json>>>;
    using array_t = ArrayType<basic_json, AllocatorType<basic_json>>;
    using string_t = StringType;
    using boolean_t = BooleanType;
    using number_integer_t = NumberIntegerType;
    using number_unsigned_t = NumberUnsignedType;
    using number_float_t = NumberFloatType;
    using binary_t = nlohmann::byte_container_with_subtype<BinaryType>;
    using object_comparator_t = detail::actual_object_comparator_t<basic_json>;
    static_assert(sizeof(typename BinaryType::value_type) == 1,
                  "BinaryType::value_type must be exactly one byte wide, "
                  "because the binary readers and writers reinterpret the container's storage as raw bytes");
    static_assert(sizeof(NumberUnsignedType) >= sizeof(NumberIntegerType),
                  "NumberUnsignedType must be at least as wide as NumberIntegerType, "
                  "because it has to hold the absolute value of every NumberIntegerType value");
  private:
    template<typename T, typename... Args>
    JSON_HEDLEY_RETURNS_NON_NULL
    static T* create(Args&& ... args)
    {
        AllocatorType<T> alloc;
        using AllocatorTraits = std::allocator_traits<AllocatorType<T>>;
        auto deleter = [&](T * obj)
        {
            AllocatorTraits::deallocate(alloc, obj, 1);
        };
        std::unique_ptr<T, decltype(deleter)> obj(AllocatorTraits::allocate(alloc, 1), deleter);
        AllocatorTraits::construct(alloc, obj.get(), std::forward<Args>(args)...);
        JSON_ASSERT(obj);
        return obj.release();
    }
  JSON_PRIVATE_UNLESS_TESTED:
    union json_value
    {
        object_t* object;
        array_t* array;
        string_t* string;
        binary_t* binary;
        boolean_t boolean;
        number_integer_t number_integer;
        number_unsigned_t number_unsigned;
        number_float_t number_float;
        json_value() = default;
        json_value(boolean_t v) noexcept : boolean(v) {}
        json_value(number_integer_t v) noexcept : number_integer(v) {}
        json_value(number_unsigned_t v) noexcept : number_unsigned(v) {}
        json_value(number_float_t v) noexcept : number_float(v) {}
        json_value(value_t t)
        {
            switch (t)
            {
                case value_t::object:
                {
                    object = create<object_t>();
                    break;
                }
                case value_t::array:
                {
                    array = create<array_t>();
                    break;
                }
                case value_t::string:
                {
                    string = create<string_t>("");
                    break;
                }
                case value_t::binary:
                {
                    binary = create<binary_t>();
                    break;
                }
                case value_t::boolean:
                {
                    boolean = static_cast<boolean_t>(false);
                    break;
                }
                case value_t::number_integer:
                {
                    number_integer = static_cast<number_integer_t>(0);
                    break;
                }
                case value_t::number_unsigned:
                {
                    number_unsigned = static_cast<number_unsigned_t>(0);
                    break;
                }
                case value_t::number_float:
                {
                    number_float = static_cast<number_float_t>(0.0);
                    break;
                }
                case value_t::null:
                {
                    object = nullptr;  
                    break;
                }
                case value_t::discarded:
                default:
                {
                    object = nullptr;  
                    if (JSON_HEDLEY_UNLIKELY(t == value_t::null))
                    {
                        JSON_THROW(other_error::create(500, "961c151d2e87f2686a955a9be24d316f1362bf21 3.12.0", nullptr)); 
                    }
                    break;
                }
            }
        }
        json_value(const string_t& value) : string(create<string_t>(value)) {}
        json_value(string_t&& value) : string(create<string_t>(std::move(value))) {}
        json_value(const object_t& value) : object(create<object_t>(value)) {}
        json_value(object_t&& value) : object(create<object_t>(std::move(value))) {}
        json_value(const array_t& value) : array(create<array_t>(value)) {}
        json_value(array_t&& value) : array(create<array_t>(std::move(value))) {}
        json_value(const typename binary_t::container_type& value) : binary(create<binary_t>(value)) {}
        json_value(typename binary_t::container_type&& value) : binary(create<binary_t>(std::move(value))) {}
        json_value(const binary_t& value) : binary(create<binary_t>(value)) {}
        json_value(binary_t&& value) : binary(create<binary_t>(std::move(value))) {}
        void destroy(value_t t)
        {
            if (
                (t == value_t::object && object == nullptr) ||
                (t == value_t::array && array == nullptr) ||
                (t == value_t::string && string == nullptr) ||
                (t == value_t::binary && binary == nullptr)
            )
            {
                return;
            }
            if (t == value_t::array || t == value_t::object)
            {
                std::vector<basic_json> stack;
                if (t == value_t::array)
                {
                    stack.reserve(array->size());
                    std::move(array->begin(), array->end(), std::back_inserter(stack));
                }
                else
                {
                    stack.reserve(object->size());
                    for (auto&& it : *object)
                    {
                        stack.push_back(std::move(it.second));
                    }
                }
                while (!stack.empty())
                {
                    basic_json current_item(std::move(stack.back()));
                    stack.pop_back();
                    if (current_item.is_array())
                    {
                        std::move(current_item.m_data.m_value.array->begin(), current_item.m_data.m_value.array->end(), std::back_inserter(stack));
                        current_item.m_data.m_value.array->clear();
                    }
                    else if (current_item.is_object())
                    {
                        for (auto&& it : *current_item.m_data.m_value.object)
                        {
                            stack.push_back(std::move(it.second));
                        }
                        current_item.m_data.m_value.object->clear();
                    }
                }
            }
            switch (t)
            {
                case value_t::object:
                {
                    AllocatorType<object_t> alloc;
                    std::allocator_traits<decltype(alloc)>::destroy(alloc, object);
                    std::allocator_traits<decltype(alloc)>::deallocate(alloc, object, 1);
                    break;
                }
                case value_t::array:
                {
                    AllocatorType<array_t> alloc;
                    std::allocator_traits<decltype(alloc)>::destroy(alloc, array);
                    std::allocator_traits<decltype(alloc)>::deallocate(alloc, array, 1);
                    break;
                }
                case value_t::string:
                {
                    AllocatorType<string_t> alloc;
                    std::allocator_traits<decltype(alloc)>::destroy(alloc, string);
                    std::allocator_traits<decltype(alloc)>::deallocate(alloc, string, 1);
                    break;
                }
                case value_t::binary:
                {
                    AllocatorType<binary_t> alloc;
                    std::allocator_traits<decltype(alloc)>::destroy(alloc, binary);
                    std::allocator_traits<decltype(alloc)>::deallocate(alloc, binary, 1);
                    break;
                }
                case value_t::null:
                case value_t::boolean:
                case value_t::number_integer:
                case value_t::number_unsigned:
                case value_t::number_float:
                case value_t::discarded:
                default:
                {
                    break;
                }
            }
        }
    };
  private:
    void assert_invariant(bool check_parents = true) const noexcept
    {
        JSON_ASSERT(m_data.m_type != value_t::object || m_data.m_value.object != nullptr);
        JSON_ASSERT(m_data.m_type != value_t::array || m_data.m_value.array != nullptr);
        JSON_ASSERT(m_data.m_type != value_t::string || m_data.m_value.string != nullptr);
        JSON_ASSERT(m_data.m_type != value_t::binary || m_data.m_value.binary != nullptr);
#if JSON_DIAGNOSTICS
        JSON_TRY
        {
            JSON_ASSERT(!check_parents || !is_structured() || std::all_of(begin(), end(), [this](const basic_json & j)
            {
                return j.m_parent == this;
            }));
        }
        JSON_CATCH(...) {} 
#endif
        static_cast<void>(check_parents);
    }
    void set_parents()
    {
#if JSON_DIAGNOSTICS
        switch (m_data.m_type)
        {
            case value_t::array:
            {
                for (auto& element : *m_data.m_value.array)
                {
                    element.m_parent = this;
                }
                break;
            }
            case value_t::object:
            {
                for (auto& element : *m_data.m_value.object)
                {
                    element.second.m_parent = this;
                }
                break;
            }
            case value_t::null:
            case value_t::string:
            case value_t::boolean:
            case value_t::number_integer:
            case value_t::number_unsigned:
            case value_t::number_float:
            case value_t::binary:
            case value_t::discarded:
            default:
                break;
        }
#endif
    }
    iterator set_parents(iterator it, std::ptrdiff_t count_set_parents)
    {
#if JSON_DIAGNOSTICS
        for (std::ptrdiff_t i = 0; i < count_set_parents; ++i)
        {
            (it + i)->m_parent = this;
        }
#else
        static_cast<void>(count_set_parents);
#endif
        return it;
    }
    template < typename It, detail::enable_if_t <
                   !detail::erase_returns_void<object_t, It>::value, int > = 0 >
    typename object_t::iterator erase_from_object(It pos)
    {
        return m_data.m_value.object->erase(pos);
    }
    template < typename It, detail::enable_if_t <
                   detail::erase_returns_void<object_t, It>::value, int > = 0 >
    typename object_t::iterator erase_from_object(It pos)
    {
        auto next = std::next(pos);
        m_data.m_value.object->erase(pos);
        return next;
    }
#if JSON_DIAGNOSTICS
    template < typename A = array_t, detail::enable_if_t < detail::has_capacity<A>::value, int > = 0 >
    std::size_t array_capacity() const noexcept
    {
        return m_data.m_value.array->capacity();
    }
    template < typename A = array_t, detail::enable_if_t < !detail::has_capacity<A>::value, int > = 0 >
    std::size_t array_capacity() const noexcept
    {
        return detail::unknown_size();
    }
#else
    static constexpr std::size_t array_capacity() noexcept
    {
        return detail::unknown_size();
    }
#endif
    reference set_parent_after_array_insert(reference j, std::size_t old_capacity)
    {
#if JSON_DIAGNOSTICS
        JSON_ASSERT(type() == value_t::array);
        if (JSON_HEDLEY_UNLIKELY(old_capacity == detail::unknown_size()
                                 || array_capacity() != old_capacity))
        {
            set_parents();
            return j;
        }
#else
        static_cast<void>(old_capacity);
#endif
        return set_parent(j);
    }
    reference set_parent(reference j)
    {
#if JSON_DIAGNOSTICS
#ifdef JSON_HEDLEY_MSVC_VERSION
#pragma warning(push )
#pragma warning(disable : 4127) 
#endif
        if (detail::is_ordered_map<object_t>::value)
        {
            set_parents();
            return j;
        }
#ifdef JSON_HEDLEY_MSVC_VERSION
#pragma warning( pop )
#endif
        j.m_parent = this;
#else
        static_cast<void>(j);
#endif
        return j;
    }
#ifndef JSON_NO_THREAD_LOCAL
    static_assert(detail::recursion_depth_limit() < 255, "the nesting depth count must fit in a byte");
    static std::uint8_t& nesting_depth() noexcept
    {
        static thread_local std::uint8_t depth = 0; 
        return depth;
    }
#endif
    static bool nesting_depth_exhausted(bool may_descend = true) noexcept
    {
#ifdef JSON_NO_THREAD_LOCAL
        static_cast<void>(may_descend);
        return true;
#else
        return !may_descend || nesting_depth() >= detail::recursion_depth_limit();
#endif
    }
    class nesting_depth_guard
    {
      public:
        nesting_depth_guard() noexcept
#ifdef JSON_NO_THREAD_LOCAL
            : m_okay(false)
#else
            : m_okay(nesting_depth() < detail::recursion_depth_limit())
#endif
        {
#ifndef JSON_NO_THREAD_LOCAL
            ++nesting_depth();
#endif
        }
        ~nesting_depth_guard()
        {
#ifndef JSON_NO_THREAD_LOCAL
            --nesting_depth();
#endif
        }
        nesting_depth_guard(const nesting_depth_guard&) = delete;
        nesting_depth_guard& operator=(const nesting_depth_guard&) = delete;
        nesting_depth_guard(nesting_depth_guard&&) = delete;
        nesting_depth_guard& operator=(nesting_depth_guard&&) = delete;
        bool okay() const noexcept
        {
            return m_okay;
        }
      private:
        bool m_okay;
    };
    using copy_worklist_t = std::vector<std::pair<const basic_json*, basic_json*>>;
    using copy_scratch_value_t = std::pair<typename object_t::key_type, basic_json>;
    using copy_scratch_t = std::vector<copy_scratch_value_t, AllocatorType<copy_scratch_value_t>>;
    static void copy_metadata(const basic_json& src, basic_json& dst)
    {
        static_cast<json_base_class_t&>(dst) = json_base_class_t(static_cast<const json_base_class_t&>(src));
#if JSON_DIAGNOSTIC_POSITIONS
        dst.start_position = src.start_position;
        dst.end_position = src.end_position;
#endif
    }
    JSON_HEDLEY_ALWAYS_INLINE
    static void copy_leaf_value(const basic_json& src, basic_json& dst)
    {
        switch (src.m_data.m_type)
        {
            case value_t::string:
            {
                dst.m_data.m_value = *src.m_data.m_value.string;
                break;
            }
            case value_t::binary:
            {
                dst.m_data.m_value = *src.m_data.m_value.binary;
                break;
            }
            case value_t::boolean:
            {
                dst.m_data.m_value = src.m_data.m_value.boolean;
                break;
            }
            case value_t::number_integer:
            {
                dst.m_data.m_value = src.m_data.m_value.number_integer;
                break;
            }
            case value_t::number_unsigned:
            {
                dst.m_data.m_value = src.m_data.m_value.number_unsigned;
                break;
            }
            case value_t::number_float:
            {
                dst.m_data.m_value = src.m_data.m_value.number_float;
                break;
            }
            case value_t::object:
            case value_t::array:
            case value_t::null:
            case value_t::discarded:
            default:
                break;
        }
    }
    static void copy_shallow(const basic_json& src, basic_json& dst, copy_worklist_t& worklist)
    {
        copy_metadata(src, dst);
        if (src.m_data.m_type == value_t::object || src.m_data.m_type == value_t::array)
        {
            worklist.emplace_back(&src, &dst);
            return;
        }
        copy_leaf_value(src, dst);
        dst.m_data.m_type = src.m_data.m_type;
    }
    static void copy_array_level(const basic_json& src, basic_json& dst, copy_worklist_t& worklist)
    {
        const array_t& src_array = *src.m_data.m_value.array;
        dst.m_data.m_value.array = create<array_t>();
        dst.m_data.m_type = value_t::array;
        dst.m_data.m_value.array->resize(src_array.size());
        auto dst_it = dst.m_data.m_value.array->begin();
        for (auto src_it = src_array.cbegin(); src_it != src_array.cend(); ++src_it, ++dst_it)
        {
            copy_shallow(*src_it, *dst_it, worklist);
        }
    }
    static void copy_object_level(const basic_json& src, basic_json& dst,
                                  copy_worklist_t& worklist, copy_scratch_t& scratch)
    {
        const object_t& src_object = *src.m_data.m_value.object;
        scratch.clear();
        scratch.reserve(src_object.size());
        for (const auto& element : src_object)
        {
            scratch.emplace_back(element.first, basic_json());
        }
        dst.m_data.m_value.object = create<object_t>(std::make_move_iterator(scratch.begin()),
                                    std::make_move_iterator(scratch.end()));
        dst.m_data.m_type = value_t::object;
        scratch.clear();
        auto src_it = src_object.cbegin();
        for (auto& element : *dst.m_data.m_value.object)
        {
            if (JSON_HEDLEY_LIKELY(src_it != src_object.cend() && src_it->first == element.first))
            {
                copy_shallow(src_it->second, element.second, worklist);
                ++src_it;
            }
            else
            {
                const auto found = src_object.find(element.first);
                JSON_ASSERT(found != src_object.cend());
                copy_shallow(found->second, element.second, worklist);
            }
        }
    }
    void copy_iteratively(const basic_json& src)
    {
        copy_worklist_t worklist;
        copy_scratch_t scratch;
        const basic_json* src_value = &src;
        basic_json* dst_value = this;
        for (;;)
        {
            if (src_value->m_data.m_type == value_t::array)
            {
                copy_array_level(*src_value, *dst_value, worklist);
            }
            else
            {
                copy_object_level(*src_value, *dst_value, worklist, scratch);
            }
            dst_value->set_parents();
            if (worklist.empty())
            {
                break;
            }
            const auto& next = worklist.back();
            src_value = next.first;
            dst_value = next.second;
            worklist.pop_back();
        }
    }
    void copy_level(const basic_json& src)
    {
        if (m_data.m_type == value_t::object)
        {
            m_data.m_value = *src.m_data.m_value.object;
        }
        else
        {
            m_data.m_value = *src.m_data.m_value.array;
        }
        set_parents();
    }
    void copy_structured(const basic_json& src)
    {
        const nesting_depth_guard guard;
        if (JSON_HEDLEY_LIKELY(guard.okay()))
        {
            copy_level(src);
            return;
        }
        copy_iteratively(src);
    }
    template<typename BasicJsonType>
    void convert_leaf(const BasicJsonType& val)
    {
        using other_boolean_t = typename BasicJsonType::boolean_t;
        using other_number_float_t = typename BasicJsonType::number_float_t;
        using other_number_integer_t = typename BasicJsonType::number_integer_t;
        using other_number_unsigned_t = typename BasicJsonType::number_unsigned_t;
        using other_string_t = typename BasicJsonType::string_t;
        using other_binary_t = typename BasicJsonType::binary_t;
        switch (val.type())
        {
            case value_t::boolean:
                JSONSerializer<other_boolean_t>::to_json(*this, val.template get<other_boolean_t>());
                break;
            case value_t::number_float:
                JSONSerializer<other_number_float_t>::to_json(*this, val.template get<other_number_float_t>());
                break;
            case value_t::number_integer:
                JSONSerializer<other_number_integer_t>::to_json(*this, val.template get<other_number_integer_t>());
                break;
            case value_t::number_unsigned:
                JSONSerializer<other_number_unsigned_t>::to_json(*this, val.template get<other_number_unsigned_t>());
                break;
            case value_t::string:
                JSONSerializer<other_string_t>::to_json(*this, val.template get_ref<const other_string_t&>());
                break;
            case value_t::binary:
                JSONSerializer<other_binary_t>::to_json(*this, val.template get_ref<const other_binary_t&>());
                break;
            case value_t::null:
                break;
            case value_t::discarded:
                m_data.m_type = value_t::discarded;
                break;
            case value_t::object: 
            case value_t::array:  
            default:              
                JSON_ASSERT(false); 
        }
    }
    using convert_scratch_t = std::vector<basic_json, AllocatorType<basic_json>>;
    template<typename BasicJsonType>
    void convert_level(const BasicJsonType& val, convert_scratch_t& elements, copy_scratch_t& members)
    {
        if (val.is_object())
        {
            const auto first = members.end() - static_cast<typename copy_scratch_t::difference_type>(val.size());
            m_data.m_value.object = create<object_t>(std::make_move_iterator(first),
                                    std::make_move_iterator(members.end()));
            m_data.m_type = value_t::object;
            members.erase(first, members.end());
        }
        else
        {
            const auto first = elements.end() - static_cast<typename convert_scratch_t::difference_type>(val.size());
            m_data.m_value.array = create<array_t>(std::make_move_iterator(first),
                                                   std::make_move_iterator(elements.end()));
            m_data.m_type = value_t::array;
            elements.erase(first, elements.end());
        }
        set_parents();
    }
    template<typename BasicJsonType>
    void convert_iteratively(const BasicJsonType& val)
    {
        using other_const_iterator = typename BasicJsonType::const_iterator;
        std::vector<std::pair<const BasicJsonType*, other_const_iterator>> pending;
        convert_scratch_t elements;
        copy_scratch_t members;
        pending.emplace_back(&val, val.cbegin());
        for (;;)
        {
            const BasicJsonType& container = *pending.back().first;
            const other_const_iterator next = pending.back().second;
            if (next != container.cend())
            {
                if (next->is_structured())
                {
                    pending.emplace_back(&*next, next->cbegin());
                    continue;
                }
                if (container.is_object())
                {
                    members.emplace_back(next.key(), *next);
                }
                else
                {
                    elements.emplace_back(*next);
                }
                ++pending.back().second;
                continue;
            }
            pending.pop_back();
            if (pending.empty())
            {
                convert_level(container, elements, members);
                return;
            }
            basic_json converted;
            converted.convert_level(container, elements, members);
#if JSON_DIAGNOSTIC_POSITIONS
            converted.start_position = container.start_pos();
            converted.end_position = container.end_pos();
#endif
            if (pending.back().first->is_object())
            {
                members.emplace_back(pending.back().second.key(), std::move(converted));
            }
            else
            {
                elements.push_back(std::move(converted));
            }
            ++pending.back().second;
        }
    }
    template<typename BasicJsonType>
    void convert_structured(const BasicJsonType& val)
    {
        const nesting_depth_guard guard;
        if (JSON_HEDLEY_LIKELY(guard.okay()))
        {
            if (val.is_object())
            {
                using other_object_t = typename BasicJsonType::object_t;
                JSONSerializer<other_object_t>::to_json(*this, val.template get_ref<const other_object_t&>());
            }
            else
            {
                using other_array_t = typename BasicJsonType::array_t;
                JSONSerializer<other_array_t>::to_json(*this, val.template get_ref<const other_array_t&>());
            }
            return;
        }
        convert_iteratively(val);
    }
    enum class compare_result { less, equal, greater, unordered };
#if JSON_HAS_THREE_WAY_COMPARISON
    static std::partial_ordering to_partial_ordering(compare_result result) noexcept 
    {
        switch (result)
        {
            case compare_result::less:
                return std::partial_ordering::less;
            case compare_result::greater:
                return std::partial_ordering::greater;
            case compare_result::equal:
                return std::partial_ordering::equivalent;
            case compare_result::unordered:
            default:
                return std::partial_ordering::unordered;
        }
    }
#endif
    template<bool Ordered>
    static compare_result compare_leaves(const_reference lhs, const_reference rhs) noexcept
    {
        if (lhs == rhs)
        {
            return compare_result::equal;
        }
        return order_leaves(lhs, rhs, std::integral_constant<bool, Ordered> {});
    }
    static compare_result compare_keys(const typename object_t::key_type& lhs,
                                       const typename object_t::key_type& rhs,
                                       std::true_type )
    {
        if (lhs < rhs)
        {
            return compare_result::less;
        }
        if (rhs < lhs)
        {
            return compare_result::greater;
        }
        return compare_result::equal;
    }
    static compare_result compare_keys(const typename object_t::key_type& lhs,
                                       const typename object_t::key_type& rhs,
                                       std::false_type )
    {
        return lhs == rhs ? compare_result::equal : compare_result::unordered;
    }
    static compare_result order_leaves(const_reference lhs, const_reference rhs, std::true_type ) noexcept
    {
        if (lhs < rhs)
        {
            return compare_result::less;
        }
        if (rhs < lhs)
        {
            return compare_result::greater;
        }
        return compare_result::unordered;
    }
    static compare_result order_leaves(const_reference , const_reference , std::false_type ) noexcept
    {
        return compare_result::unordered;
    }
    template<bool Ordered>
    static compare_result compare_iteratively(const_reference lhs, const_reference rhs,
            const bool unordered_compares_equal) noexcept
    {
        struct frame
        {
            const basic_json* lhs_value{nullptr};
            const basic_json* rhs_value{nullptr};
            typename array_t::const_iterator lhs_array_it{};
            typename array_t::const_iterator rhs_array_it{};
            typename object_t::const_iterator lhs_object_it{};
            typename object_t::const_iterator rhs_object_it{};
        };
        std::vector<frame> stack;
        const basic_json* left = &lhs;
        const basic_json* right = &rhs;
        for (;;)
        {
            const auto type = left->m_data.m_type;
            if (type == right->m_data.m_type && (type == value_t::array || type == value_t::object))
            {
                stack.emplace_back();
                frame& pushed = stack.back();
                pushed.lhs_value = left;
                pushed.rhs_value = right;
                if (type == value_t::array)
                {
                    pushed.lhs_array_it = left->m_data.m_value.array->cbegin();
                    pushed.rhs_array_it = right->m_data.m_value.array->cbegin();
                }
                else
                {
                    pushed.lhs_object_it = left->m_data.m_value.object->cbegin();
                    pushed.rhs_object_it = right->m_data.m_value.object->cbegin();
                }
            }
            else
            {
                const compare_result result = compare_leaves<Ordered>(*left, *right);
                if (result != compare_result::equal &&
                        !(unordered_compares_equal && result == compare_result::unordered))
                {
                    return result;
                }
            }
            for (;;)
            {
                if (stack.empty())
                {
                    return compare_result::equal;
                }
                frame& current = stack.back();
                const bool is_object = current.lhs_value->m_data.m_type == value_t::object;
                const bool lhs_done = is_object
                                      ? current.lhs_object_it == current.lhs_value->m_data.m_value.object->cend()
                                      : current.lhs_array_it == current.lhs_value->m_data.m_value.array->cend();
                const bool rhs_done = is_object
                                      ? current.rhs_object_it == current.rhs_value->m_data.m_value.object->cend()
                                      : current.rhs_array_it == current.rhs_value->m_data.m_value.array->cend();
                if (lhs_done || rhs_done)
                {
                    if (lhs_done != rhs_done)
                    {
                        return lhs_done ? compare_result::less : compare_result::greater;
                    }
                    stack.pop_back();
                    continue;
                }
                if (is_object)
                {
                    const compare_result key_result =
                        compare_keys(current.lhs_object_it->first, current.rhs_object_it->first,
                                     std::integral_constant<bool, Ordered> {});
                    left = &(current.lhs_object_it->second);
                    right = &(current.rhs_object_it->second);
                    if (key_result != compare_result::equal)
                    {
                        const auto* rhs_object = current.rhs_value->m_data.m_value.object;
                        const auto found = (!Ordered && !detail::is_ordered_map<object_t>::value)
                                           ? rhs_object->find(current.lhs_object_it->first)
                                           : rhs_object->cend();
                        if (found == rhs_object->cend() || !(found->first == current.lhs_object_it->first))
                        {
                            return key_result;
                        }
                        right = &(found->second);
                    }
                    ++current.lhs_object_it;
                    ++current.rhs_object_it;
                }
                else
                {
                    left = &(*current.lhs_array_it);
                    right = &(*current.rhs_array_it);
                    ++current.lhs_array_it;
                    ++current.rhs_array_it;
                }
                break;
            }
        }
    }
    void set_parents_after_object_erase()
    {
#if JSON_DIAGNOSTICS
#ifdef JSON_HEDLEY_MSVC_VERSION
#pragma warning(push )
#pragma warning(disable : 4127) 
#endif
        if (detail::is_ordered_map<object_t>::value)
        {
            set_parents();
        }
#ifdef JSON_HEDLEY_MSVC_VERSION
#pragma warning( pop )
#endif
#endif
    }
  public:
    using parse_event_t = detail::parse_event_t;
    using parser_callback_t = detail::parser_callback_t<basic_json>;
    basic_json(const value_t v)
        : m_data(v)
    {
        assert_invariant();
    }
    basic_json(std::nullptr_t = nullptr) noexcept 
        : basic_json(value_t::null)
    {
        assert_invariant();
    }
    template < typename CompatibleType,
               typename U = detail::uncvref_t<CompatibleType>,
               detail::enable_if_t <
                   !detail::is_basic_json<U>::value && detail::is_compatible_type<basic_json_t, U>::value
#if JSON_DISABLE_TUPLE_REFERENCE_CONVERSION
                   && !detail::is_basic_json_reference_tuple<basic_json_t, U>::value
#endif
                   , int > = 0 >
    basic_json(CompatibleType && val) noexcept(noexcept( 
            JSONSerializer<U>::to_json(std::declval<basic_json_t&>(),
                                       std::forward<CompatibleType>(val))))
    {
        JSONSerializer<U>::to_json(*this, std::forward<CompatibleType>(val));
        set_parents();
        assert_invariant();
    }
    template < typename BasicJsonType,
               detail::enable_if_t <
                   detail::is_basic_json<BasicJsonType>::value&& !std::is_same<basic_json, BasicJsonType>::value, int > = 0 >
    basic_json(const BasicJsonType& val)
#if JSON_DIAGNOSTIC_POSITIONS
        : start_position(val.start_pos()),
          end_position(val.end_pos())
#endif
    {
        if (val.is_structured())
        {
            convert_structured(val);
        }
        else
        {
            convert_leaf(val);
        }
        JSON_ASSERT(m_data.m_type == val.type());
        set_parents();
        assert_invariant();
    }
    basic_json(initializer_list_t init,
               bool type_deduction = true,
               value_t manual_type = value_t::array)
    {
        bool is_an_object = std::all_of(init.begin(), init.end(),
                                        [](const detail::json_ref<basic_json>& element_ref)
        {
            return element_ref->is_array() && element_ref->size() == 2 && (*element_ref)[static_cast<size_type>(0)].is_string();
        });
        if (!type_deduction)
        {
            if (manual_type == value_t::array)
            {
                is_an_object = false;
            }
            if (JSON_HEDLEY_UNLIKELY(manual_type == value_t::object && !is_an_object))
            {
                JSON_THROW(type_error::create(301, "cannot create object from initializer list", nullptr));
            }
        }
        if (is_an_object)
        {
            m_data.m_type = value_t::object;
            m_data.m_value = value_t::object;
            for (auto& element_ref : init)
            {
                auto element = element_ref.moved_or_copied();
                m_data.m_value.object->emplace(
                    std::move(*((*element.m_data.m_value.array)[0].m_data.m_value.string)),
                    std::move((*element.m_data.m_value.array)[1]));
            }
        }
        else
        {
#if JSON_BRACE_INIT_COPY_SEMANTICS
            if (type_deduction && init.size() == 1)
            {
                *this = init.begin()->moved_or_copied();
                set_parents();
                assert_invariant();
                return;
            }
#endif
            m_data.m_type = value_t::array;
            m_data.m_value.array = create<array_t>(init.begin(), init.end());
        }
        set_parents();
        assert_invariant();
    }
    JSON_HEDLEY_WARN_UNUSED_RESULT
    static basic_json binary(const typename binary_t::container_type& init)
    {
        auto res = basic_json();
        res.m_data.m_type = value_t::binary;
        res.m_data.m_value = init;
        return res;
    }
    JSON_HEDLEY_WARN_UNUSED_RESULT
    static basic_json binary(const typename binary_t::container_type& init, typename binary_t::subtype_type subtype)
    {
        auto res = basic_json();
        res.m_data.m_type = value_t::binary;
        res.m_data.m_value = binary_t(init, subtype);
        return res;
    }
    JSON_HEDLEY_WARN_UNUSED_RESULT
    static basic_json binary(typename binary_t::container_type&& init)
    {
        auto res = basic_json();
        res.m_data.m_type = value_t::binary;
        res.m_data.m_value = std::move(init);
        return res;
    }
    JSON_HEDLEY_WARN_UNUSED_RESULT
    static basic_json binary(typename binary_t::container_type&& init, typename binary_t::subtype_type subtype)
    {
        auto res = basic_json();
        res.m_data.m_type = value_t::binary;
        res.m_data.m_value = binary_t(std::move(init), subtype);
        return res;
    }
    JSON_HEDLEY_WARN_UNUSED_RESULT
    static basic_json array(initializer_list_t init = {})
    {
        return basic_json(init, false, value_t::array);
    }
    JSON_HEDLEY_WARN_UNUSED_RESULT
    static basic_json object(initializer_list_t init = {})
    {
        return basic_json(init, false, value_t::object);
    }
    basic_json(size_type cnt, const basic_json& val):
        m_data{cnt, val}
    {
        set_parents();
        assert_invariant();
    }
    template < class InputIT, typename std::enable_if <
                   std::is_same<InputIT, typename basic_json_t::iterator>::value ||
                   std::is_same<InputIT, typename basic_json_t::const_iterator>::value, int >::type = 0 >
    basic_json(InputIT first, InputIT last) 
    {
        JSON_ASSERT(first.m_object != nullptr);
        JSON_ASSERT(last.m_object != nullptr);
        if (JSON_HEDLEY_UNLIKELY(first.m_object != last.m_object))
        {
            JSON_THROW(invalid_iterator::create(201, "iterators are not compatible", nullptr));
        }
        m_data.m_type = first.m_object->m_data.m_type;
        switch (m_data.m_type)
        {
            case value_t::boolean:
            case value_t::number_float:
            case value_t::number_integer:
            case value_t::number_unsigned:
            case value_t::string:
            case value_t::binary:
            {
                if (JSON_HEDLEY_UNLIKELY(!first.m_it.primitive_iterator.is_begin()
                                         || !last.m_it.primitive_iterator.is_end()))
                {
                    JSON_THROW(invalid_iterator::create(204, "iterators out of range", first.m_object));
                }
                break;
            }
            case value_t::null:
            case value_t::object:
            case value_t::array:
            case value_t::discarded:
            default:
                break;
        }
        switch (m_data.m_type)
        {
            case value_t::number_integer:
            {
                m_data.m_value.number_integer = first.m_object->m_data.m_value.number_integer;
                break;
            }
            case value_t::number_unsigned:
            {
                m_data.m_value.number_unsigned = first.m_object->m_data.m_value.number_unsigned;
                break;
            }
            case value_t::number_float:
            {
                m_data.m_value.number_float = first.m_object->m_data.m_value.number_float;
                break;
            }
            case value_t::boolean:
            {
                m_data.m_value.boolean = first.m_object->m_data.m_value.boolean;
                break;
            }
            case value_t::string:
            {
                m_data.m_value = *first.m_object->m_data.m_value.string;
                break;
            }
            case value_t::object:
            {
                m_data.m_value.object = create<object_t>(first.m_it.object_iterator,
                                        last.m_it.object_iterator);
                break;
            }
            case value_t::array:
            {
                m_data.m_value.array = create<array_t>(first.m_it.array_iterator,
                                                       last.m_it.array_iterator);
                break;
            }
            case value_t::binary:
            {
                m_data.m_value = *first.m_object->m_data.m_value.binary;
                break;
            }
            case value_t::null:
            case value_t::discarded:
            default:
                JSON_THROW(invalid_iterator::create(206, detail::concat("cannot construct with iterators from ", first.m_object->type_name()), first.m_object));
        }
        set_parents();
        assert_invariant();
    }
    template<typename JsonRef,
             detail::enable_if_t<detail::conjunction<detail::is_json_ref<JsonRef>,
                                 std::is_same<typename JsonRef::value_type, basic_json>>::value, int> = 0 >
    basic_json(const JsonRef& ref) : basic_json(ref.moved_or_copied()) {}
    basic_json(const basic_json& other)
        : json_base_class_t(other)
#if JSON_DIAGNOSTIC_POSITIONS
        , start_position(other.start_position)
        , end_position(other.end_position)
#endif
    {
        m_data.m_type = other.m_data.m_type;
        other.assert_invariant();
        if (m_data.m_type == value_t::object || m_data.m_type == value_t::array)
        {
            copy_structured(other);
        }
        else
        {
            copy_leaf_value(other, *this);
        }
        set_parents();
        assert_invariant();
    }
    basic_json(basic_json&& other) noexcept
        : json_base_class_t(std::forward<json_base_class_t>(other)),
          m_data(std::move(other.m_data)) 
#if JSON_DIAGNOSTIC_POSITIONS
        , start_position(other.start_position) 
        , end_position(other.end_position) 
#endif
    {
        other.assert_invariant(false); 
        other.m_data.m_type = value_t::null;
        other.m_data.m_value = {};
#if JSON_DIAGNOSTIC_POSITIONS
        other.start_position = std::string::npos;
        other.end_position = std::string::npos;
#endif
        set_parents();
        assert_invariant();
    }
    basic_json& operator=(basic_json other) noexcept ( 
        std::is_nothrow_move_constructible<value_t>::value&&
        std::is_nothrow_move_assignable<value_t>::value&&
        std::is_nothrow_move_constructible<json_value>::value&&
        std::is_nothrow_move_assignable<json_value>::value&&
        std::is_nothrow_move_assignable<json_base_class_t>::value
    )
    {
        other.assert_invariant();
        using std::swap;
        swap(m_data.m_type, other.m_data.m_type);
        swap(m_data.m_value, other.m_data.m_value);
#if JSON_DIAGNOSTIC_POSITIONS
        swap(start_position, other.start_position);
        swap(end_position, other.end_position);
#endif
        json_base_class_t::operator=(std::move(other));
        set_parents();
        assert_invariant();
        return *this;
    }
    ~basic_json() noexcept
    {
        assert_invariant(false);
    }
  public:
    JSON_HEDLEY_WARN_UNUSED_RESULT
    string_t dump(const int indent = -1,
                  const char indent_char = ' ',
                  const bool ensure_ascii = false,
                  const error_handler_t error_handler = error_handler_t::strict) const
    {
        string_t result;
        detail::output_string_adapter<char, string_t> string_adapter(result);
        if (indent >= 0)
        {
            serializer s(string_adapter, indent_char,
                         true, ensure_ascii, static_cast<std::size_t>(indent), error_handler);
            s.dump(*this);
        }
        else
        {
            serializer s(string_adapter, indent_char,
                         false, ensure_ascii, 0, error_handler);
            s.dump(*this);
        }
        return result;
    }
    JSON_HEDLEY_WARN_UNUSED_RESULT
    constexpr value_t type() const noexcept
    {
        return m_data.m_type;
    }
    JSON_HEDLEY_WARN_UNUSED_RESULT
    constexpr bool is_primitive() const noexcept
    {
        return is_null() || is_string() || is_boolean() || is_number() || is_binary();
    }
    JSON_HEDLEY_WARN_UNUSED_RESULT
    constexpr bool is_structured() const noexcept
    {
        return is_array() || is_object();
    }
    JSON_HEDLEY_WARN_UNUSED_RESULT
    constexpr bool is_null() const noexcept
    {
        return m_data.m_type == value_t::null;
    }
    JSON_HEDLEY_WARN_UNUSED_RESULT
    constexpr bool is_boolean() const noexcept
    {
        return m_data.m_type == value_t::boolean;
    }
    JSON_HEDLEY_WARN_UNUSED_RESULT
    constexpr bool is_number() const noexcept
    {
        return is_number_integer() || is_number_float();
    }
    JSON_HEDLEY_WARN_UNUSED_RESULT
    constexpr bool is_number_integer() const noexcept
    {
        return m_data.m_type == value_t::number_integer || m_data.m_type == value_t::number_unsigned;
    }
    JSON_HEDLEY_WARN_UNUSED_RESULT
    constexpr bool is_number_unsigned() const noexcept
    {
        return m_data.m_type == value_t::number_unsigned;
    }
    JSON_HEDLEY_WARN_UNUSED_RESULT
    constexpr bool is_number_float() const noexcept
    {
        return m_data.m_type == value_t::number_float;
    }
    JSON_HEDLEY_WARN_UNUSED_RESULT
    constexpr bool is_object() const noexcept
    {
        return m_data.m_type == value_t::object;
    }
    JSON_HEDLEY_WARN_UNUSED_RESULT
    constexpr bool is_array() const noexcept
    {
        return m_data.m_type == value_t::array;
    }
    JSON_HEDLEY_WARN_UNUSED_RESULT
    constexpr bool is_string() const noexcept
    {
        return m_data.m_type == value_t::string;
    }
    JSON_HEDLEY_WARN_UNUSED_RESULT
    constexpr bool is_binary() const noexcept
    {
        return m_data.m_type == value_t::binary;
    }
    JSON_HEDLEY_WARN_UNUSED_RESULT
    constexpr bool is_discarded() const noexcept
    {
        return m_data.m_type == value_t::discarded;
    }
    constexpr operator value_t() const noexcept
    {
        return m_data.m_type;
    }
  private:
    object_t* get_impl_ptr(object_t* ) noexcept
    {
        return is_object() ? m_data.m_value.object : nullptr;
    }
    constexpr const object_t* get_impl_ptr(const object_t* ) const noexcept
    {
        return is_object() ? m_data.m_value.object : nullptr;
    }
    array_t* get_impl_ptr(array_t* ) noexcept
    {
        return is_array() ? m_data.m_value.array : nullptr;
    }
    constexpr const array_t* get_impl_ptr(const array_t* ) const noexcept
    {
        return is_array() ? m_data.m_value.array : nullptr;
    }
    string_t* get_impl_ptr(string_t* ) noexcept
    {
        return is_string() ? m_data.m_value.string : nullptr;
    }
    constexpr const string_t* get_impl_ptr(const string_t* ) const noexcept
    {
        return is_string() ? m_data.m_value.string : nullptr;
    }
    boolean_t* get_impl_ptr(boolean_t* ) noexcept
    {
        return is_boolean() ? &m_data.m_value.boolean : nullptr;
    }
    constexpr const boolean_t* get_impl_ptr(const boolean_t* ) const noexcept
    {
        return is_boolean() ? &m_data.m_value.boolean : nullptr;
    }
    number_integer_t* get_impl_ptr(number_integer_t* ) noexcept
    {
        return m_data.m_type == value_t::number_integer ? &m_data.m_value.number_integer : nullptr;
    }
    constexpr const number_integer_t* get_impl_ptr(const number_integer_t* ) const noexcept
    {
        return m_data.m_type == value_t::number_integer ? &m_data.m_value.number_integer : nullptr;
    }
    number_unsigned_t* get_impl_ptr(number_unsigned_t* ) noexcept
    {
        return is_number_unsigned() ? &m_data.m_value.number_unsigned : nullptr;
    }
    constexpr const number_unsigned_t* get_impl_ptr(const number_unsigned_t* ) const noexcept
    {
        return is_number_unsigned() ? &m_data.m_value.number_unsigned : nullptr;
    }
    number_float_t* get_impl_ptr(number_float_t* ) noexcept
    {
        return is_number_float() ? &m_data.m_value.number_float : nullptr;
    }
    constexpr const number_float_t* get_impl_ptr(const number_float_t* ) const noexcept
    {
        return is_number_float() ? &m_data.m_value.number_float : nullptr;
    }
    binary_t* get_impl_ptr(binary_t* ) noexcept
    {
        return is_binary() ? m_data.m_value.binary : nullptr;
    }
    constexpr const binary_t* get_impl_ptr(const binary_t* ) const noexcept
    {
        return is_binary() ? m_data.m_value.binary : nullptr;
    }
    template<typename ReferenceType, typename ThisType>
    static ReferenceType get_ref_impl(ThisType& obj)
    {
        auto* ptr = obj.template get_ptr<typename std::add_pointer<ReferenceType>::type>();
        if (JSON_HEDLEY_LIKELY(ptr != nullptr))
        {
            return *ptr;
        }
        JSON_THROW(type_error::create(303, detail::concat("incompatible ReferenceType for get_ref, actual type is ", obj.type_name()), &obj));
    }
  public:
    template<typename PointerType, typename std::enable_if<
                 std::is_pointer<PointerType>::value, int>::type = 0>
    auto get_ptr() noexcept -> decltype(std::declval<basic_json_t&>().get_impl_ptr(std::declval<PointerType>()))
    {
        return get_impl_ptr(static_cast<PointerType>(nullptr));
    }
    template < typename PointerType, typename std::enable_if <
                   std::is_pointer<PointerType>::value&&
                   std::is_const<typename std::remove_pointer<PointerType>::type>::value, int >::type = 0 >
    constexpr auto get_ptr() const noexcept -> decltype(std::declval<const basic_json_t&>().get_impl_ptr(std::declval<PointerType>()))
    {
        return get_impl_ptr(static_cast<PointerType>(nullptr));
    }
  private:
    template < typename ValueType,
               detail::enable_if_t <
                   detail::is_default_constructible<ValueType>::value&&
                   detail::has_from_json<basic_json_t, ValueType>::value,
                   int > = 0 >
    ValueType get_impl(detail::priority_tag<0> ) const noexcept(noexcept(
            JSONSerializer<ValueType>::from_json(std::declval<const basic_json_t&>(), std::declval<ValueType&>())))
    {
        auto ret = ValueType();
        JSONSerializer<ValueType>::from_json(*this, ret);
        return ret;
    }
    template < typename ValueType,
               detail::enable_if_t <
                   detail::has_non_default_from_json<basic_json_t, ValueType>::value,
                   int > = 0 >
    ValueType get_impl(detail::priority_tag<1> ) const noexcept(noexcept(
            JSONSerializer<ValueType>::from_json(std::declval<const basic_json_t&>())))
    {
        return JSONSerializer<ValueType>::from_json(*this);
    }
    template < typename BasicJsonType,
               detail::enable_if_t <
                   detail::is_basic_json<BasicJsonType>::value,
                   int > = 0 >
    BasicJsonType get_impl(detail::priority_tag<2> ) const
    {
        return *this;
    }
    template<typename BasicJsonType,
             detail::enable_if_t<
                 std::is_same<BasicJsonType, basic_json_t>::value,
                 int> = 0>
    basic_json get_impl(detail::priority_tag<3> ) const
    {
        return *this;
    }
    template<typename PointerType,
             detail::enable_if_t<
                 std::is_pointer<PointerType>::value,
                 int> = 0>
    constexpr auto get_impl(detail::priority_tag<4> ) const noexcept
    -> decltype(std::declval<const basic_json_t&>().template get_ptr<PointerType>())
    {
        return get_ptr<PointerType>();
    }
  public:
    template < typename ValueTypeCV, typename ValueType = detail::uncvref_t<ValueTypeCV>>
#if defined(JSON_HAS_CPP_14)
    constexpr
#endif
    auto get() const noexcept(
    noexcept(std::declval<const basic_json_t&>().template get_impl<ValueType>(detail::priority_tag<4> {})))
    -> decltype(std::declval<const basic_json_t&>().template get_impl<ValueType>(detail::priority_tag<4> {}))
    {
        static_assert(!std::is_reference<ValueTypeCV>::value,
                      "get() cannot be used with reference types, you might want to use get_ref()");
        return get_impl<ValueType>(detail::priority_tag<4> {});
    }
    template<typename PointerType, typename std::enable_if<
                 std::is_pointer<PointerType>::value, int>::type = 0>
    auto get() noexcept -> decltype(std::declval<basic_json_t&>().template get_ptr<PointerType>())
    {
        return get_ptr<PointerType>();
    }
    template < typename ValueType,
               detail::enable_if_t <
                   !detail::is_basic_json<ValueType>::value&&
                   detail::has_from_json<basic_json_t, ValueType>::value,
                   int > = 0 >
    ValueType & get_to(ValueType& v) const noexcept(noexcept(
            JSONSerializer<ValueType>::from_json(std::declval<const basic_json_t&>(), v)))
    {
        static_assert(!std::is_const<ValueType>::value, "get_to() cannot deserialize into a const value");
        JSONSerializer<ValueType>::from_json(*this, v);
        return v;
    }
    template<typename ValueType,
             detail::enable_if_t <
                 detail::is_basic_json<ValueType>::value,
                 int> = 0>
    ValueType & get_to(ValueType& v) const
    {
        v = *this;
        return v;
    }
    template <
        typename T, std::size_t N,
        typename Array = T (&)[N], 
        detail::enable_if_t <
            detail::has_from_json<basic_json_t, Array>::value, int > = 0 >
    Array get_to(T (&v)[N]) const 
    noexcept(noexcept(JSONSerializer<Array>::from_json(
                          std::declval<const basic_json_t&>(), v)))
    {
        static_assert(!std::is_const<T>::value, "get_to() cannot deserialize into a const value");
        JSONSerializer<Array>::from_json(*this, v);
        return v;
    }
    template<typename ReferenceType, typename std::enable_if<
                 std::is_reference<ReferenceType>::value, int>::type = 0>
    ReferenceType get_ref()
    {
        return get_ref_impl<ReferenceType>(*this);
    }
    template < typename ReferenceType, typename std::enable_if <
                   std::is_reference<ReferenceType>::value&&
                   std::is_const<typename std::remove_reference<ReferenceType>::type>::value, int >::type = 0 >
    ReferenceType get_ref() const
    {
        return get_ref_impl<ReferenceType>(*this);
    }
    template < typename ValueType, typename std::enable_if <
                   detail::conjunction <
                       detail::negation<std::is_pointer<ValueType>>,
                       detail::negation<std::is_same<ValueType, std::nullptr_t>>,
                       detail::negation<std::is_same<ValueType, detail::json_ref<basic_json>>>,
                                        detail::negation<std::is_same<ValueType, typename string_t::value_type>>,
                                        detail::negation<detail::is_basic_json<ValueType>>,
                                        detail::negation<std::is_same<ValueType, std::initializer_list<typename string_t::value_type>>>,
#if defined(JSON_HAS_CPP_17) && (defined(__GNUC__) || (defined(_MSC_VER) && _MSC_VER >= 1910 && _MSC_VER <= 1914))
                                                detail::negation<std::is_same<ValueType, std::string_view>>,
#endif
#if defined(JSON_HAS_CPP_17) && JSON_HAS_STATIC_RTTI
                                                detail::negation<std::is_same<ValueType, std::any>>,
#endif
#if defined(JSON_HAS_CPP_17)
                                                detail::negation<detail::is_std_optional<ValueType>>,
#endif
                                                detail::is_detected_lazy<detail::get_template_function, const basic_json_t&, ValueType>
                                                >::value, int >::type = 0 >
                                        JSON_EXPLICIT operator ValueType() const
    {
        return get<ValueType>();
    }
    binary_t& get_binary()
    {
        if (!is_binary())
        {
            JSON_THROW(type_error::create(302, detail::concat("type must be binary, but is ", type_name()), this));
        }
        return *get_ptr<binary_t*>();
    }
    const binary_t& get_binary() const
    {
        if (!is_binary())
        {
            JSON_THROW(type_error::create(302, detail::concat("type must be binary, but is ", type_name()), this));
        }
        return *get_ptr<const binary_t*>();
    }
    reference at(size_type idx)
    {
        if (JSON_HEDLEY_UNLIKELY(!is_array()))
        {
            JSON_THROW(type_error::create(304, detail::concat("cannot use at() with ", type_name()), this));
        }
        if (JSON_HEDLEY_UNLIKELY(idx >= m_data.m_value.array->size()))
        {
            JSON_THROW(out_of_range::create(401, detail::concat("array index ", std::to_string(idx), " is out of range"), this));
        }
        return set_parent((*m_data.m_value.array)[idx]);
    }
    const_reference at(size_type idx) const
    {
        if (JSON_HEDLEY_UNLIKELY(!is_array()))
        {
            JSON_THROW(type_error::create(304, detail::concat("cannot use at() with ", type_name()), this));
        }
        if (JSON_HEDLEY_UNLIKELY(idx >= m_data.m_value.array->size()))
        {
            JSON_THROW(out_of_range::create(401, detail::concat("array index ", std::to_string(idx), " is out of range"), this));
        }
        return (*m_data.m_value.array)[idx];
    }
    reference at(const typename object_t::key_type& key)
    {
        if (JSON_HEDLEY_UNLIKELY(!is_object()))
        {
            JSON_THROW(type_error::create(304, detail::concat("cannot use at() with ", type_name()), this));
        }
        auto it = m_data.m_value.object->find(key);
        if (it == m_data.m_value.object->end())
        {
            JSON_THROW(out_of_range::create(403, detail::concat("key '", key, "' not found"), this));
        }
        return set_parent(it->second);
    }
    template<class KeyType, detail::enable_if_t<
                 detail::is_usable_as_basic_json_key_type<basic_json_t, KeyType>::value, int> = 0>
    reference at(KeyType && key)
    {
        if (JSON_HEDLEY_UNLIKELY(!is_object()))
        {
            JSON_THROW(type_error::create(304, detail::concat("cannot use at() with ", type_name()), this));
        }
        auto it = m_data.m_value.object->find(std::forward<KeyType>(key));
        if (it == m_data.m_value.object->end())
        {
            JSON_THROW(out_of_range::create(403, detail::concat("key '", string_t(std::forward<KeyType>(key)), "' not found"), this));
        }
        return set_parent(it->second);
    }
    const_reference at(const typename object_t::key_type& key) const
    {
        if (JSON_HEDLEY_UNLIKELY(!is_object()))
        {
            JSON_THROW(type_error::create(304, detail::concat("cannot use at() with ", type_name()), this));
        }
        auto it = m_data.m_value.object->find(key);
        if (it == m_data.m_value.object->end())
        {
            JSON_THROW(out_of_range::create(403, detail::concat("key '", key, "' not found"), this));
        }
        return it->second;
    }
    template<class KeyType, detail::enable_if_t<
                 detail::is_usable_as_basic_json_key_type<basic_json_t, KeyType>::value, int> = 0>
    const_reference at(KeyType && key) const
    {
        if (JSON_HEDLEY_UNLIKELY(!is_object()))
        {
            JSON_THROW(type_error::create(304, detail::concat("cannot use at() with ", type_name()), this));
        }
        auto it = m_data.m_value.object->find(std::forward<KeyType>(key));
        if (it == m_data.m_value.object->end())
        {
            JSON_THROW(out_of_range::create(403, detail::concat("key '", string_t(std::forward<KeyType>(key)), "' not found"), this));
        }
        return it->second;
    }
    reference operator[](size_type idx)
    {
        if (is_null())
        {
            m_data.m_type = value_t::array;
            m_data.m_value.array = create<array_t>();
            assert_invariant();
        }
        if (JSON_HEDLEY_LIKELY(is_array()))
        {
            if (idx >= m_data.m_value.array->size())
            {
                if (JSON_HEDLEY_UNLIKELY(idx == (std::numeric_limits<size_type>::max)()))
                {
                    JSON_THROW(std::length_error(detail::concat("array index ", std::to_string(idx), " exceeds size_type")));
                }
#if JSON_DIAGNOSTICS
                const auto old_size = m_data.m_value.array->size();
                const auto old_capacity = array_capacity();
#endif
                m_data.m_value.array->resize(idx + 1);
#if JSON_DIAGNOSTICS
                if (JSON_HEDLEY_UNLIKELY(old_capacity == detail::unknown_size()
                                         || array_capacity() != old_capacity))
                {
                    set_parents();
                }
                else
                {
                    set_parents(begin() + static_cast<typename iterator::difference_type>(old_size), static_cast<typename iterator::difference_type>(idx + 1 - old_size));
                }
#endif
                assert_invariant();
            }
            return m_data.m_value.array->operator[](idx);
        }
        JSON_THROW(type_error::create(305, detail::concat("cannot use operator[] with a numeric argument with ", type_name()), this));
    }
    const_reference operator[](size_type idx) const
    {
        if (JSON_HEDLEY_LIKELY(is_array()))
        {
            return m_data.m_value.array->operator[](idx);
        }
        JSON_THROW(type_error::create(305, detail::concat("cannot use operator[] with a numeric argument with ", type_name()), this));
    }
    reference operator[](typename object_t::key_type key) 
    {
        if (is_null())
        {
            m_data.m_type = value_t::object;
            m_data.m_value.object = create<object_t>();
            assert_invariant();
        }
        if (JSON_HEDLEY_LIKELY(is_object()))
        {
            auto result = m_data.m_value.object->emplace(std::move(key), nullptr);
            return set_parent(result.first->second);
        }
        JSON_THROW(type_error::create(305, detail::concat("cannot use operator[] with a string argument with ", type_name()), this));
    }
    const_reference operator[](const typename object_t::key_type& key) const
    {
        if (JSON_HEDLEY_LIKELY(is_object()))
        {
            auto it = m_data.m_value.object->find(key);
            JSON_ASSERT(it != m_data.m_value.object->end());
            return it->second;
        }
        JSON_THROW(type_error::create(305, detail::concat("cannot use operator[] with a string argument with ", type_name()), this));
    }
    template<typename T>
    reference operator[](T* key)
    {
        return operator[](typename object_t::key_type(key));
    }
    template<typename T>
    const_reference operator[](T* key) const
    {
        return operator[](typename object_t::key_type(key));
    }
    template<class KeyType, detail::enable_if_t<
                 detail::is_usable_as_basic_json_key_type<basic_json_t, KeyType>::value, int > = 0 >
    reference operator[](KeyType && key)
    {
        if (is_null())
        {
            m_data.m_type = value_t::object;
            m_data.m_value.object = create<object_t>();
            assert_invariant();
        }
        if (JSON_HEDLEY_LIKELY(is_object()))
        {
            auto result = m_data.m_value.object->emplace(std::forward<KeyType>(key), nullptr);
            return set_parent(result.first->second);
        }
        JSON_THROW(type_error::create(305, detail::concat("cannot use operator[] with a string argument with ", type_name()), this));
    }
    template<class KeyType, detail::enable_if_t<
                 detail::is_usable_as_basic_json_key_type<basic_json_t, KeyType>::value, int > = 0 >
    const_reference operator[](KeyType && key) const
    {
        if (JSON_HEDLEY_LIKELY(is_object()))
        {
            auto it = m_data.m_value.object->find(std::forward<KeyType>(key));
            JSON_ASSERT(it != m_data.m_value.object->end());
            return it->second;
        }
        JSON_THROW(type_error::create(305, detail::concat("cannot use operator[] with a string argument with ", type_name()), this));
    }
  private:
    template<typename KeyType>
    using is_comparable_with_object_key = detail::is_comparable <
        object_comparator_t, const typename object_t::key_type&, KeyType >;
    template<typename ValueType>
    using value_return_type = std::conditional <
        detail::is_c_string_uncvref<ValueType>::value,
        string_t, typename std::decay<ValueType>::type >;
  public:
    template<typename T, typename ValueType, detail::enable_if_t<std::is_integral<T>::value, int> = 0>
    ValueType value(T, ValueType&&) const = delete;
    template < class ValueType, detail::enable_if_t <
                   !detail::is_transparent<object_comparator_t>::value
                   && detail::is_getable<basic_json_t, ValueType>::value
                   && !std::is_same<value_t, detail::uncvref_t<ValueType>>::value, int > = 0 >
    ValueType value(const typename object_t::key_type& key, const ValueType& default_value) const
    {
        if (JSON_HEDLEY_LIKELY(is_object()))
        {
            const auto it = find(key);
            if (it != end())
            {
                return it->template get<ValueType>();
            }
            return default_value;
        }
        JSON_THROW(type_error::create(306, detail::concat("cannot use value() with ", type_name()), this));
    }
    template < class ValueType, class ReturnType = typename value_return_type<ValueType>::type,
               detail::enable_if_t <
                   !detail::is_transparent<object_comparator_t>::value
                   && detail::is_getable<basic_json_t, ReturnType>::value
                   && !std::is_same<value_t, detail::uncvref_t<ValueType>>::value, int > = 0 >
    ReturnType value(const typename object_t::key_type& key, ValueType && default_value) const
    {
        if (JSON_HEDLEY_LIKELY(is_object()))
        {
            const auto it = find(key);
            if (it != end())
            {
                return it->template get<ReturnType>();
            }
            return std::forward<ValueType>(default_value);
        }
        JSON_THROW(type_error::create(306, detail::concat("cannot use value() with ", type_name()), this));
    }
    template < class ValueType, class KeyType, detail::enable_if_t <
                   detail::is_transparent<object_comparator_t>::value
                   && !detail::is_json_pointer<KeyType>::value
                   && is_comparable_with_object_key<KeyType>::value
                   && detail::is_getable<basic_json_t, ValueType>::value
                   && !std::is_same<value_t, detail::uncvref_t<ValueType>>::value, int > = 0 >
    ValueType value(KeyType && key, const ValueType& default_value) const
    {
        if (JSON_HEDLEY_LIKELY(is_object()))
        {
            const auto it = find(std::forward<KeyType>(key));
            if (it != end())
            {
                return it->template get<ValueType>();
            }
            return default_value;
        }
        JSON_THROW(type_error::create(306, detail::concat("cannot use value() with ", type_name()), this));
    }
    template < class ValueType, class KeyType, class ReturnType = typename value_return_type<ValueType>::type,
               detail::enable_if_t <
                   detail::is_transparent<object_comparator_t>::value
                   && !detail::is_json_pointer<KeyType>::value
                   && is_comparable_with_object_key<KeyType>::value
                   && detail::is_getable<basic_json_t, ReturnType>::value
                   && !std::is_same<value_t, detail::uncvref_t<ValueType>>::value, int > = 0 >
    ReturnType value(KeyType && key, ValueType && default_value) const
    {
        if (JSON_HEDLEY_LIKELY(is_object()))
        {
            const auto it = find(std::forward<KeyType>(key));
            if (it != end())
            {
                return it->template get<ReturnType>();
            }
            return std::forward<ValueType>(default_value);
        }
        JSON_THROW(type_error::create(306, detail::concat("cannot use value() with ", type_name()), this));
    }
    template < class ValueType, detail::enable_if_t <
                   detail::is_getable<basic_json_t, ValueType>::value
                   && !std::is_same<value_t, detail::uncvref_t<ValueType>>::value, int > = 0 >
    ValueType value(const json_pointer& ptr, const ValueType& default_value) const
    {
        if (JSON_HEDLEY_LIKELY(is_structured()))
        {
            const auto* res = ptr.get_checked_or_null(this);
            if (JSON_HEDLEY_LIKELY(res != nullptr))
            {
                return res->template get<ValueType>();
            }
            return default_value;
        }
        JSON_THROW(type_error::create(306, detail::concat("cannot use value() with ", type_name()), this));
    }
    template < class ValueType, class ReturnType = typename value_return_type<ValueType>::type,
               detail::enable_if_t <
                   detail::is_getable<basic_json_t, ReturnType>::value
                   && !std::is_same<value_t, detail::uncvref_t<ValueType>>::value, int > = 0 >
    ReturnType value(const json_pointer& ptr, ValueType && default_value) const
    {
        if (JSON_HEDLEY_LIKELY(is_structured()))
        {
            const auto* res = ptr.get_checked_or_null(this);
            if (JSON_HEDLEY_LIKELY(res != nullptr))
            {
                return res->template get<ReturnType>();
            }
            return std::forward<ValueType>(default_value);
        }
        JSON_THROW(type_error::create(306, detail::concat("cannot use value() with ", type_name()), this));
    }
    template < class ValueType, class BasicJsonType, detail::enable_if_t <
                   detail::is_basic_json<BasicJsonType>::value
                   && detail::is_getable<basic_json_t, ValueType>::value
                   && !std::is_same<value_t, detail::uncvref_t<ValueType>>::value, int > = 0 >
    JSON_HEDLEY_DEPRECATED_FOR(3.11.0, basic_json::json_pointer or nlohmann::json_pointer<basic_json::string_t>) 
    ValueType value(const ::nlohmann::json_pointer<BasicJsonType>& ptr, const ValueType& default_value) const
    {
        return value(ptr.convert(), default_value);
    }
    template < class ValueType, class BasicJsonType, class ReturnType = typename value_return_type<ValueType>::type,
               detail::enable_if_t <
                   detail::is_basic_json<BasicJsonType>::value
                   && detail::is_getable<basic_json_t, ReturnType>::value
                   && !std::is_same<value_t, detail::uncvref_t<ValueType>>::value, int > = 0 >
    JSON_HEDLEY_DEPRECATED_FOR(3.11.0, basic_json::json_pointer or nlohmann::json_pointer<basic_json::string_t>) 
    ReturnType value(const ::nlohmann::json_pointer<BasicJsonType>& ptr, ValueType && default_value) const
    {
        return value(ptr.convert(), std::forward<ValueType>(default_value));
    }
    reference front()
    {
        return *begin();
    }
    const_reference front() const
    {
        return *cbegin();
    }
    reference back()
    {
        auto tmp = end();
        --tmp;
        return *tmp;
    }
    const_reference back() const
    {
        auto tmp = cend();
        --tmp;
        return *tmp;
    }
    template < class IteratorType, detail::enable_if_t <
                   std::is_same<IteratorType, typename basic_json_t::iterator>::value ||
                   std::is_same<IteratorType, typename basic_json_t::const_iterator>::value, int > = 0 >
    IteratorType erase(IteratorType pos) 
    {
        if (JSON_HEDLEY_UNLIKELY(this != pos.m_object))
        {
            JSON_THROW(invalid_iterator::create(202, "iterator does not fit current value", this));
        }
        IteratorType result = end();
        switch (m_data.m_type)
        {
            case value_t::boolean:
            case value_t::number_float:
            case value_t::number_integer:
            case value_t::number_unsigned:
            case value_t::string:
            case value_t::binary:
            {
                if (JSON_HEDLEY_UNLIKELY(!pos.m_it.primitive_iterator.is_begin()))
                {
                    JSON_THROW(invalid_iterator::create(205, "iterator out of range", this));
                }
                if (is_string())
                {
                    AllocatorType<string_t> alloc;
                    std::allocator_traits<decltype(alloc)>::destroy(alloc, m_data.m_value.string);
                    std::allocator_traits<decltype(alloc)>::deallocate(alloc, m_data.m_value.string, 1);
                    m_data.m_value.string = nullptr;
                }
                else if (is_binary())
                {
                    AllocatorType<binary_t> alloc;
                    std::allocator_traits<decltype(alloc)>::destroy(alloc, m_data.m_value.binary);
                    std::allocator_traits<decltype(alloc)>::deallocate(alloc, m_data.m_value.binary, 1);
                    m_data.m_value.binary = nullptr;
                }
                m_data.m_type = value_t::null;
                assert_invariant();
                break;
            }
            case value_t::object:
            {
                result.m_it.object_iterator = erase_from_object(pos.m_it.object_iterator);
                set_parents_after_object_erase();
                break;
            }
            case value_t::array:
            {
                result.m_it.array_iterator = m_data.m_value.array->erase(pos.m_it.array_iterator);
                break;
            }
            case value_t::null:
            case value_t::discarded:
            default:
                JSON_THROW(type_error::create(307, detail::concat("cannot use erase() with ", type_name()), this));
        }
        return result;
    }
    template < class IteratorType, detail::enable_if_t <
                   std::is_same<IteratorType, typename basic_json_t::iterator>::value ||
                   std::is_same<IteratorType, typename basic_json_t::const_iterator>::value, int > = 0 >
    IteratorType erase(IteratorType first, IteratorType last) 
    {
        if (JSON_HEDLEY_UNLIKELY(this != first.m_object || this != last.m_object))
        {
            JSON_THROW(invalid_iterator::create(203, "iterators do not fit current value", this));
        }
        IteratorType result = end();
        switch (m_data.m_type)
        {
            case value_t::boolean:
            case value_t::number_float:
            case value_t::number_integer:
            case value_t::number_unsigned:
            case value_t::string:
            case value_t::binary:
            {
                if (JSON_HEDLEY_LIKELY(!first.m_it.primitive_iterator.is_begin()
                                       || !last.m_it.primitive_iterator.is_end()))
                {
                    JSON_THROW(invalid_iterator::create(204, "iterators out of range", this));
                }
                if (is_string())
                {
                    AllocatorType<string_t> alloc;
                    std::allocator_traits<decltype(alloc)>::destroy(alloc, m_data.m_value.string);
                    std::allocator_traits<decltype(alloc)>::deallocate(alloc, m_data.m_value.string, 1);
                    m_data.m_value.string = nullptr;
                }
                else if (is_binary())
                {
                    AllocatorType<binary_t> alloc;
                    std::allocator_traits<decltype(alloc)>::destroy(alloc, m_data.m_value.binary);
                    std::allocator_traits<decltype(alloc)>::deallocate(alloc, m_data.m_value.binary, 1);
                    m_data.m_value.binary = nullptr;
                }
                m_data.m_type = value_t::null;
                assert_invariant();
                break;
            }
            case value_t::object:
            {
                result.m_it.object_iterator = m_data.m_value.object->erase(first.m_it.object_iterator,
                                              last.m_it.object_iterator);
                set_parents_after_object_erase();
                break;
            }
            case value_t::array:
            {
                result.m_it.array_iterator = m_data.m_value.array->erase(first.m_it.array_iterator,
                                             last.m_it.array_iterator);
                break;
            }
            case value_t::null:
            case value_t::discarded:
            default:
                JSON_THROW(type_error::create(307, detail::concat("cannot use erase() with ", type_name()), this));
        }
        return result;
    }
  private:
    template < typename KeyType, detail::enable_if_t <
                   detail::has_erase_with_key_type<basic_json_t, KeyType>::value, int > = 0 >
    size_type erase_internal(KeyType && key)
    {
        if (JSON_HEDLEY_UNLIKELY(!is_object()))
        {
            JSON_THROW(type_error::create(307, detail::concat("cannot use erase() with ", type_name()), this));
        }
        const auto erased = m_data.m_value.object->erase(std::forward<KeyType>(key));
        set_parents_after_object_erase();
        return erased;
    }
    template < typename KeyType, detail::enable_if_t <
                   !detail::has_erase_with_key_type<basic_json_t, KeyType>::value, int > = 0 >
    size_type erase_internal(KeyType && key)
    {
        if (JSON_HEDLEY_UNLIKELY(!is_object()))
        {
            JSON_THROW(type_error::create(307, detail::concat("cannot use erase() with ", type_name()), this));
        }
        const auto it = m_data.m_value.object->find(std::forward<KeyType>(key));
        if (it != m_data.m_value.object->end())
        {
            m_data.m_value.object->erase(it);
            set_parents_after_object_erase();
            return 1;
        }
        return 0;
    }
  public:
    size_type erase(const typename object_t::key_type& key)
    {
        return erase_internal(key);
    }
    template<class KeyType, detail::enable_if_t<
                 detail::is_usable_as_basic_json_key_type<basic_json_t, KeyType>::value, int> = 0>
    size_type erase(KeyType && key)
    {
        return erase_internal(std::forward<KeyType>(key));
    }
    void erase(const size_type idx)
    {
        if (JSON_HEDLEY_LIKELY(is_array()))
        {
            if (JSON_HEDLEY_UNLIKELY(idx >= size()))
            {
                JSON_THROW(out_of_range::create(401, detail::concat("array index ", std::to_string(idx), " is out of range"), this));
            }
            m_data.m_value.array->erase(m_data.m_value.array->begin() + static_cast<difference_type>(idx));
        }
        else
        {
            JSON_THROW(type_error::create(307, detail::concat("cannot use erase() with ", type_name()), this));
        }
    }
    template<typename T, detail::enable_if_t<std::is_integral<T>::value, int> = 0>
    iterator find(T) = delete;
    template<typename T, detail::enable_if_t<std::is_integral<T>::value, int> = 0>
    const_iterator find(T) const = delete;
    template<typename T, detail::enable_if_t<std::is_integral<T>::value, int> = 0>
    size_type count(T) const = delete;
    template<typename T, detail::enable_if_t<std::is_integral<T>::value, int> = 0>
    bool contains(T) const = delete;
    iterator find(const typename object_t::key_type& key)
    {
        auto result = end();
        if (is_object())
        {
            result.m_it.object_iterator = m_data.m_value.object->find(key);
        }
        return result;
    }
    const_iterator find(const typename object_t::key_type& key) const
    {
        auto result = cend();
        if (is_object())
        {
            result.m_it.object_iterator = m_data.m_value.object->find(key);
        }
        return result;
    }
    template<class KeyType, detail::enable_if_t<
                 detail::is_usable_as_basic_json_key_type<basic_json_t, KeyType>::value, int> = 0>
    iterator find(KeyType && key)
    {
        auto result = end();
        if (is_object())
        {
            result.m_it.object_iterator = m_data.m_value.object->find(std::forward<KeyType>(key));
        }
        return result;
    }
    template<class KeyType, detail::enable_if_t<
                 detail::is_usable_as_basic_json_key_type<basic_json_t, KeyType>::value, int> = 0>
    const_iterator find(KeyType && key) const
    {
        auto result = cend();
        if (is_object())
        {
            result.m_it.object_iterator = m_data.m_value.object->find(std::forward<KeyType>(key));
        }
        return result;
    }
    JSON_HEDLEY_WARN_UNUSED_RESULT
    size_type count(const typename object_t::key_type& key) const
    {
        return is_object() ? m_data.m_value.object->count(key) : 0;
    }
    template<class KeyType, detail::enable_if_t<
                 detail::is_usable_as_basic_json_key_type<basic_json_t, KeyType>::value, int> = 0>
    JSON_HEDLEY_WARN_UNUSED_RESULT
    size_type count(KeyType && key) const
    {
        return is_object() ? m_data.m_value.object->count(std::forward<KeyType>(key)) : 0;
    }
    JSON_HEDLEY_WARN_UNUSED_RESULT
    bool contains(const typename object_t::key_type& key) const
    {
        return is_object() && m_data.m_value.object->find(key) != m_data.m_value.object->end();
    }
    template<class KeyType, detail::enable_if_t<
                 detail::is_usable_as_basic_json_key_type<basic_json_t, KeyType>::value, int> = 0>
    JSON_HEDLEY_WARN_UNUSED_RESULT
    bool contains(KeyType && key) const
    {
        return is_object() && m_data.m_value.object->find(std::forward<KeyType>(key)) != m_data.m_value.object->end();
    }
    JSON_HEDLEY_WARN_UNUSED_RESULT
    bool contains(const json_pointer& ptr) const
    {
        return ptr.contains(this);
    }
    template<typename BasicJsonType, detail::enable_if_t<detail::is_basic_json<BasicJsonType>::value, int> = 0>
    JSON_HEDLEY_WARN_UNUSED_RESULT
    JSON_HEDLEY_DEPRECATED_FOR(3.11.0, basic_json::json_pointer or nlohmann::json_pointer<basic_json::string_t>) 
    bool contains(const typename ::nlohmann::json_pointer<BasicJsonType>& ptr) const
    {
        return ptr.contains(this);
    }
    iterator begin() noexcept
    {
        iterator result(this);
        result.set_begin();
        return result;
    }
    const_iterator begin() const noexcept
    {
        return cbegin();
    }
    const_iterator cbegin() const noexcept
    {
        const_iterator result(this);
        result.set_begin();
        return result;
    }
    iterator end() noexcept
    {
        iterator result(this);
        result.set_end();
        return result;
    }
    const_iterator end() const noexcept
    {
        return cend();
    }
    const_iterator cend() const noexcept
    {
        const_iterator result(this);
        result.set_end();
        return result;
    }
    reverse_iterator rbegin() noexcept
    {
        return reverse_iterator(end());
    }
    const_reverse_iterator rbegin() const noexcept
    {
        return crbegin();
    }
    reverse_iterator rend() noexcept
    {
        return reverse_iterator(begin());
    }
    const_reverse_iterator rend() const noexcept
    {
        return crend();
    }
    const_reverse_iterator crbegin() const noexcept
    {
        return const_reverse_iterator(cend());
    }
    const_reverse_iterator crend() const noexcept
    {
        return const_reverse_iterator(cbegin());
    }
  public:
    JSON_HEDLEY_DEPRECATED_FOR(3.1.0, items())
    static iteration_proxy<iterator> iterator_wrapper(reference ref) noexcept
    {
        return ref.items();
    }
    JSON_HEDLEY_DEPRECATED_FOR(3.1.0, items())
    static iteration_proxy<const_iterator> iterator_wrapper(const_reference ref) noexcept
    {
        return ref.items();
    }
    iteration_proxy<iterator> items() noexcept
    {
        return iteration_proxy<iterator>(*this);
    }
    iteration_proxy<const_iterator> items() const noexcept
    {
        return iteration_proxy<const_iterator>(*this);
    }
    JSON_HEDLEY_WARN_UNUSED_RESULT
    bool empty() const noexcept
    {
        switch (m_data.m_type)
        {
            case value_t::null:
            {
                return true;
            }
            case value_t::array:
            {
                return m_data.m_value.array->empty();
            }
            case value_t::object:
            {
                return m_data.m_value.object->empty();
            }
            case value_t::string:
            case value_t::boolean:
            case value_t::number_integer:
            case value_t::number_unsigned:
            case value_t::number_float:
            case value_t::binary:
            case value_t::discarded:
            default:
            {
                return false;
            }
        }
    }
    JSON_HEDLEY_WARN_UNUSED_RESULT
    size_type size() const noexcept
    {
        switch (m_data.m_type)
        {
            case value_t::null:
            {
                return 0;
            }
            case value_t::array:
            {
                return m_data.m_value.array->size();
            }
            case value_t::object:
            {
                return m_data.m_value.object->size();
            }
            case value_t::string:
            case value_t::boolean:
            case value_t::number_integer:
            case value_t::number_unsigned:
            case value_t::number_float:
            case value_t::binary:
            case value_t::discarded:
            default:
            {
                return 1;
            }
        }
    }
    JSON_HEDLEY_WARN_UNUSED_RESULT
    size_type max_size() const noexcept
    {
        switch (m_data.m_type)
        {
            case value_t::array:
            {
                return m_data.m_value.array->max_size();
            }
            case value_t::object:
            {
                return m_data.m_value.object->max_size();
            }
            case value_t::null:
            case value_t::string:
            case value_t::boolean:
            case value_t::number_integer:
            case value_t::number_unsigned:
            case value_t::number_float:
            case value_t::binary:
            case value_t::discarded:
            default:
            {
                return size();
            }
        }
    }
    void clear() noexcept
    {
        switch (m_data.m_type)
        {
            case value_t::number_integer:
            {
                m_data.m_value.number_integer = 0;
                break;
            }
            case value_t::number_unsigned:
            {
                m_data.m_value.number_unsigned = 0;
                break;
            }
            case value_t::number_float:
            {
                m_data.m_value.number_float = 0.0;
                break;
            }
            case value_t::boolean:
            {
                m_data.m_value.boolean = false;
                break;
            }
            case value_t::string:
            {
                m_data.m_value.string->clear();
                break;
            }
            case value_t::binary:
            {
                m_data.m_value.binary->clear();
                m_data.m_value.binary->clear_subtype();
                break;
            }
            case value_t::array:
            {
                m_data.m_value.array->clear();
                break;
            }
            case value_t::object:
            {
                m_data.m_value.object->clear();
                break;
            }
            case value_t::null:
            case value_t::discarded:
            default:
                break;
        }
    }
    void push_back(basic_json&& val)
    {
        if (JSON_HEDLEY_UNLIKELY(!(is_null() || is_array())))
        {
            JSON_THROW(type_error::create(308, detail::concat("cannot use push_back() with ", type_name()), this));
        }
        if (is_null())
        {
            m_data.m_type = value_t::array;
            m_data.m_value = value_t::array;
            assert_invariant();
        }
        const auto old_capacity = array_capacity();
        m_data.m_value.array->push_back(std::move(val));
        set_parent_after_array_insert(m_data.m_value.array->back(), old_capacity);
    }
    reference operator+=(basic_json&& val)
    {
        push_back(std::move(val));
        return *this;
    }
    void push_back(const basic_json& val)
    {
        if (JSON_HEDLEY_UNLIKELY(!(is_null() || is_array())))
        {
            JSON_THROW(type_error::create(308, detail::concat("cannot use push_back() with ", type_name()), this));
        }
        if (is_null())
        {
            m_data.m_type = value_t::array;
            m_data.m_value = value_t::array;
            assert_invariant();
        }
        const auto old_capacity = array_capacity();
        m_data.m_value.array->push_back(val);
        set_parent_after_array_insert(m_data.m_value.array->back(), old_capacity);
    }
    reference operator+=(const basic_json& val)
    {
        push_back(val);
        return *this;
    }
    void push_back(const typename object_t::value_type& val)
    {
        if (JSON_HEDLEY_UNLIKELY(!(is_null() || is_object())))
        {
            JSON_THROW(type_error::create(308, detail::concat("cannot use push_back() with ", type_name()), this));
        }
        if (is_null())
        {
            m_data.m_type = value_t::object;
            m_data.m_value = value_t::object;
            assert_invariant();
        }
        auto res = m_data.m_value.object->insert(val);
        set_parent(res.first->second);
    }
    reference operator+=(const typename object_t::value_type& val)
    {
        push_back(val);
        return *this;
    }
    void push_back(initializer_list_t init)
    {
        if (is_object() && init.size() == 2 && (*init.begin())->is_string())
        {
            basic_json&& key = init.begin()->moved_or_copied();
            push_back(typename object_t::value_type(
                          std::move(key.get_ref<string_t&>()), (init.begin() + 1)->moved_or_copied()));
        }
        else
        {
            push_back(basic_json(init));
        }
    }
    reference operator+=(initializer_list_t init)
    {
        push_back(init);
        return *this;
    }
    template<class... Args>
    reference emplace_back(Args&& ... args)
    {
        if (JSON_HEDLEY_UNLIKELY(!(is_null() || is_array())))
        {
            JSON_THROW(type_error::create(311, detail::concat("cannot use emplace_back() with ", type_name()), this));
        }
        if (is_null())
        {
            m_data.m_type = value_t::array;
            m_data.m_value = value_t::array;
            assert_invariant();
        }
        const auto old_capacity = array_capacity();
        m_data.m_value.array->emplace_back(std::forward<Args>(args)...);
        return set_parent_after_array_insert(m_data.m_value.array->back(), old_capacity);
    }
    template<class... Args>
    std::pair<iterator, bool> emplace(Args&& ... args)
    {
        if (JSON_HEDLEY_UNLIKELY(!(is_null() || is_object())))
        {
            JSON_THROW(type_error::create(311, detail::concat("cannot use emplace() with ", type_name()), this));
        }
        if (is_null())
        {
            m_data.m_type = value_t::object;
            m_data.m_value = value_t::object;
            assert_invariant();
        }
        auto res = m_data.m_value.object->emplace(std::forward<Args>(args)...);
        set_parent(res.first->second);
        auto it = begin();
        it.m_it.object_iterator = res.first;
        return {it, res.second};
    }
    template<typename... Args>
    iterator insert_iterator(const_iterator pos, Args&& ... args) 
    {
        iterator result(this);
        JSON_ASSERT(m_data.m_value.array != nullptr);
        auto insert_pos = std::distance(m_data.m_value.array->begin(), pos.m_it.array_iterator);
        m_data.m_value.array->insert(pos.m_it.array_iterator, std::forward<Args>(args)...);
        result.m_it.array_iterator = m_data.m_value.array->begin() + insert_pos;
        set_parents();
        return result;
    }
    iterator insert(const_iterator pos, const basic_json& val) 
    {
        if (JSON_HEDLEY_LIKELY(is_array()))
        {
            if (JSON_HEDLEY_UNLIKELY(pos.m_object != this))
            {
                JSON_THROW(invalid_iterator::create(202, "iterator does not fit current value", this));
            }
            return insert_iterator(pos, val);
        }
        JSON_THROW(type_error::create(309, detail::concat("cannot use insert() with ", type_name()), this));
    }
    iterator insert(const_iterator pos, basic_json&& val) 
    {
        return insert(std::move(pos), val);
    }
    iterator insert(const_iterator pos, size_type cnt, const basic_json& val) 
    {
        if (JSON_HEDLEY_LIKELY(is_array()))
        {
            if (JSON_HEDLEY_UNLIKELY(pos.m_object != this))
            {
                JSON_THROW(invalid_iterator::create(202, "iterator does not fit current value", this));
            }
            return insert_iterator(pos, cnt, val);
        }
        JSON_THROW(type_error::create(309, detail::concat("cannot use insert() with ", type_name()), this));
    }
    iterator insert(const_iterator pos, const_iterator first, const_iterator last) 
    {
        if (JSON_HEDLEY_UNLIKELY(!is_array()))
        {
            JSON_THROW(type_error::create(309, detail::concat("cannot use insert() with ", type_name()), this));
        }
        if (JSON_HEDLEY_UNLIKELY(pos.m_object != this))
        {
            JSON_THROW(invalid_iterator::create(202, "iterator does not fit current value", this));
        }
        if (JSON_HEDLEY_UNLIKELY(first.m_object != last.m_object))
        {
            JSON_THROW(invalid_iterator::create(210, "iterators do not fit", this));
        }
        if (JSON_HEDLEY_UNLIKELY(first.m_object == this))
        {
            JSON_THROW(invalid_iterator::create(211, "passed iterators may not belong to container", this));
        }
        if (JSON_HEDLEY_UNLIKELY(!first.m_object->is_array()))
        {
            JSON_THROW(invalid_iterator::create(202, "iterators first and last must point to arrays", this));
        }
        return insert_iterator(pos, first.m_it.array_iterator, last.m_it.array_iterator);
    }
    iterator insert(const_iterator pos, initializer_list_t ilist) 
    {
        if (JSON_HEDLEY_UNLIKELY(!is_array()))
        {
            JSON_THROW(type_error::create(309, detail::concat("cannot use insert() with ", type_name()), this));
        }
        if (JSON_HEDLEY_UNLIKELY(pos.m_object != this))
        {
            JSON_THROW(invalid_iterator::create(202, "iterator does not fit current value", this));
        }
        array_t values;
        detail::reserve_array(values, ilist.size(), detail::priority_tag<1> {});
        for (const auto& element : ilist)
        {
            values.push_back(element.moved_or_copied());
        }
        return insert_iterator(pos, std::make_move_iterator(values.begin()), std::make_move_iterator(values.end()));
    }
    void insert(const_iterator first, const_iterator last) 
    {
        if (JSON_HEDLEY_UNLIKELY(!is_object()))
        {
            JSON_THROW(type_error::create(309, detail::concat("cannot use insert() with ", type_name()), this));
        }
        if (JSON_HEDLEY_UNLIKELY(first.m_object != last.m_object))
        {
            JSON_THROW(invalid_iterator::create(210, "iterators do not fit", this));
        }
        if (JSON_HEDLEY_UNLIKELY(!first.m_object->is_object()))
        {
            JSON_THROW(invalid_iterator::create(202, "iterators first and last must point to objects", this));
        }
        m_data.m_value.object->insert(first.m_it.object_iterator, last.m_it.object_iterator);
        set_parents();
    }
    void update(const_reference j, bool merge_objects = false)
    {
        prepare_update();
        if (JSON_HEDLEY_UNLIKELY(!j.is_object()))
        {
            JSON_THROW(type_error::create(312, detail::concat("cannot use update() with ", j.type_name()), &j));
        }
        basic_json source = j;
        update_from(source, merge_objects);
    }
    void update(const_iterator first, const_iterator last, bool merge_objects = false) 
    {
        prepare_update();
        if (JSON_HEDLEY_UNLIKELY(first.m_object != last.m_object))
        {
            JSON_THROW(invalid_iterator::create(210, "iterators do not fit", this));
        }
        if (JSON_HEDLEY_UNLIKELY(!first.m_object->is_object()))
        {
            JSON_THROW(type_error::create(312, detail::concat("cannot use update() with ", first.m_object->type_name()), first.m_object));
        }
        basic_json source(first, last);
        update_from(source, merge_objects);
    }
  private:
    struct merge_frame
    {
        merge_frame(basic_json* target_, iterator position_, iterator last_) noexcept
            : target(target_), position(std::move(position_)), last(std::move(last_))
        {}
        basic_json* target;
        iterator position;
        iterator last;
    };
    void prepare_update()
    {
        if (is_null())
        {
            m_data.m_value.object = create<object_t>();
            m_data.m_type = value_t::object;
            assert_invariant();
        }
        if (JSON_HEDLEY_UNLIKELY(!is_object()))
        {
            JSON_THROW(type_error::create(312, detail::concat("cannot use update() with ", type_name()), this));
        }
    }
    void update_from(basic_json& source, const bool merge_objects)
    {
        update_members(source.begin(), source.end(), merge_objects, 0);
    }
    void update_members(const iterator& first, const iterator& last, const bool merge_objects, const std::size_t depth)
    {
        if (JSON_HEDLEY_UNLIKELY(depth >= detail::recursion_depth_limit()))
        {
            update_members_iteratively(first, last);
            return;
        }
        for (auto it = first; it != last; ++it)
        {
            if (merge_objects && it.value().is_object())
            {
                const auto it2 = m_data.m_value.object->find(it.key());
                if (it2 != m_data.m_value.object->end() && it2->second.is_object())
                {
                    it2->second.update_members(it.value().begin(), it.value().end(), true, depth + 1);
                    continue;
                }
            }
            set_parent(m_data.m_value.object->operator[](it.key()) = std::move(it.value()));
        }
    }
    void update_members_iteratively(iterator first, iterator last)
    {
        std::vector<merge_frame> stack;
        basic_json* target = this;
        while (true)
        {
            if (first == last)
            {
                if (stack.empty())
                {
                    break;
                }
                target = stack.back().target;
                first = stack.back().position;
                last = stack.back().last;
                stack.pop_back();
                continue;
            }
            if (first.value().is_object())
            {
                const auto it2 = target->m_data.m_value.object->find(first.key());
                if (it2 != target->m_data.m_value.object->end() && it2->second.is_object())
                {
                    basic_json& source = first.value();
                    ++first;
                    stack.emplace_back(target, first, last);
                    target = &it2->second;
                    first = source.begin();
                    last = source.end();
                    continue;
                }
            }
            target->set_parent(target->m_data.m_value.object->operator[](first.key()) = std::move(first.value()));
            ++first;
        }
    }
  public:
    void swap(reference other) noexcept (
        std::is_nothrow_move_constructible<value_t>::value&&
        std::is_nothrow_move_assignable<value_t>::value&&
        std::is_nothrow_move_constructible<json_value>::value&& 
        std::is_nothrow_move_assignable<json_value>::value&&
        std::is_nothrow_move_constructible<json_base_class_t>::value&&
        std::is_nothrow_move_assignable<json_base_class_t>::value
    )
    {
        std::swap(m_data.m_type, other.m_data.m_type);
        std::swap(m_data.m_value, other.m_data.m_value);
        {
            using std::swap;
            swap(static_cast<json_base_class_t&>(*this), static_cast<json_base_class_t&>(other));
        }
#if JSON_DIAGNOSTIC_POSITIONS
        std::swap(start_position, other.start_position);
        std::swap(end_position, other.end_position);
#endif
        set_parents();
        other.set_parents();
        assert_invariant();
    }
    friend void swap(reference left, reference right) noexcept (
        std::is_nothrow_move_constructible<value_t>::value&&
        std::is_nothrow_move_assignable<value_t>::value&&
        std::is_nothrow_move_constructible<json_value>::value&& 
        std::is_nothrow_move_assignable<json_value>::value&&
        std::is_nothrow_move_constructible<json_base_class_t>::value&&
        std::is_nothrow_move_assignable<json_base_class_t>::value
    )
    {
        left.swap(right);
    }
    void swap(array_t& other) 
    {
        if (JSON_HEDLEY_LIKELY(is_array()))
        {
            using std::swap;
            swap(*(m_data.m_value.array), other);
            set_parents();
        }
        else
        {
            JSON_THROW(type_error::create(310, detail::concat("cannot use swap(array_t&) with ", type_name()), this));
        }
    }
    void swap(object_t& other) 
    {
        if (JSON_HEDLEY_LIKELY(is_object()))
        {
            using std::swap;
            swap(*(m_data.m_value.object), other);
            set_parents();
        }
        else
        {
            JSON_THROW(type_error::create(310, detail::concat("cannot use swap(object_t&) with ", type_name()), this));
        }
    }
    void swap(string_t& other) 
    {
        if (JSON_HEDLEY_LIKELY(is_string()))
        {
            using std::swap;
            swap(*(m_data.m_value.string), other);
        }
        else
        {
            JSON_THROW(type_error::create(310, detail::concat("cannot use swap(string_t&) with ", type_name()), this));
        }
    }
    void swap(binary_t& other) 
    {
        if (JSON_HEDLEY_LIKELY(is_binary()))
        {
            using std::swap;
            swap(*(m_data.m_value.binary), other);
        }
        else
        {
            JSON_THROW(type_error::create(310, detail::concat("cannot use swap(binary_t&) with ", type_name()), this));
        }
    }
    void swap(typename binary_t::container_type& other) 
    {
        if (JSON_HEDLEY_LIKELY(is_binary()))
        {
            using std::swap;
            swap(*(m_data.m_value.binary), other);
        }
        else
        {
            JSON_THROW(type_error::create(310, detail::concat("cannot use swap(binary_t::container_type&) with ", type_name()), this));
        }
    }
#define JSON_IMPLEMENT_OPERATOR(op, null_result, unordered_result, default_result, deep_result, may_descend) \
    const auto lhs_type = lhs.type();                                                                    \
    const auto rhs_type = rhs.type();                                                                    \
    \
    if (lhs_type == rhs_type)                                            \
    {                                                                                                    \
        switch (lhs_type)                                                                                \
        {                                                                                                \
            case value_t::array:                                                                         \
            {                                                                                            \
                if (JSON_HEDLEY_UNLIKELY(nesting_depth_exhausted(may_descend)))                        \
                {                                                                                        \
                    return (deep_result);                                                                \
                }                                                                                        \
                const nesting_depth_guard guard;                                                         \
                return (*lhs.m_data.m_value.array) op (*rhs.m_data.m_value.array);                                     \
            }                                                                                            \
            \
            case value_t::object:                                                                        \
            {                                                                                            \
                if (JSON_HEDLEY_UNLIKELY(nesting_depth_exhausted(may_descend)))                        \
                {                                                                                        \
                    return (deep_result);                                                                \
                }                                                                                        \
                const nesting_depth_guard guard;                                                         \
                return (*lhs.m_data.m_value.object) op (*rhs.m_data.m_value.object);                                   \
            }                                                                                            \
            \
            case value_t::null:                                                                          \
                return (null_result);                                                                    \
                \
            case value_t::string:                                                                        \
                return (*lhs.m_data.m_value.string) op (*rhs.m_data.m_value.string);                                   \
                \
            case value_t::boolean:                                                                       \
                return (lhs.m_data.m_value.boolean) op (rhs.m_data.m_value.boolean);                                   \
                \
            case value_t::number_integer:                                                                \
                return (lhs.m_data.m_value.number_integer) op (rhs.m_data.m_value.number_integer);                     \
                \
            case value_t::number_unsigned:                                                               \
                return (lhs.m_data.m_value.number_unsigned) op (rhs.m_data.m_value.number_unsigned);                   \
                \
            case value_t::number_float:                                                                  \
                return (lhs.m_data.m_value.number_float) op (rhs.m_data.m_value.number_float);                         \
                \
            case value_t::binary:                                                                        \
                return (*lhs.m_data.m_value.binary) op (*rhs.m_data.m_value.binary);                                   \
                \
            case value_t::discarded:                                                                     \
            default:                                                                                     \
                return (unordered_result);                                                               \
        }                                                                                                \
    }                                                                                                    \
    else if (lhs_type == value_t::number_integer && rhs_type == value_t::number_float)                   \
    {                                                                                                    \
        return (detail::compare_integer_with_float(lhs.m_data.m_value.number_integer, rhs.m_data.m_value.number_float)) op (static_cast<number_float_t>(0)); \
    }                                                                                                    \
    else if (lhs_type == value_t::number_float && rhs_type == value_t::number_integer)                   \
    {                                                                                                    \
        return (static_cast<number_float_t>(0)) op (detail::compare_integer_with_float(rhs.m_data.m_value.number_integer, lhs.m_data.m_value.number_float)); \
    }                                                                                                    \
    else if (lhs_type == value_t::number_unsigned && rhs_type == value_t::number_float)                  \
    {                                                                                                    \
        return (detail::compare_integer_with_float(lhs.m_data.m_value.number_unsigned, rhs.m_data.m_value.number_float)) op (static_cast<number_float_t>(0)); \
    }                                                                                                    \
    else if (lhs_type == value_t::number_float && rhs_type == value_t::number_unsigned)                  \
    {                                                                                                    \
        return (static_cast<number_float_t>(0)) op (detail::compare_integer_with_float(rhs.m_data.m_value.number_unsigned, lhs.m_data.m_value.number_float)); \
    }                                                                                                    \
    else if (lhs_type == value_t::number_unsigned && rhs_type == value_t::number_integer)                \
    {                                                                                                    \
        return (rhs.m_data.m_value.number_integer < 0)                                                   \
               ? (number_integer_t(1) op number_integer_t(-1))                                           \
               : (lhs.m_data.m_value.number_unsigned op static_cast<number_unsigned_t>(rhs.m_data.m_value.number_integer)); \
    }                                                                                                    \
    else if (lhs_type == value_t::number_integer && rhs_type == value_t::number_unsigned)                \
    {                                                                                                    \
        return (lhs.m_data.m_value.number_integer < 0)                                                   \
               ? (number_integer_t(-1) op number_integer_t(1))                                           \
               : (static_cast<number_unsigned_t>(lhs.m_data.m_value.number_integer) op rhs.m_data.m_value.number_unsigned); \
    }                                                                                             \
    else if(compares_unordered(lhs, rhs))\
    {\
        return (unordered_result);\
    }\
    \
    return (default_result);
  JSON_PRIVATE_UNLESS_TESTED:
    static bool compares_unordered(const_reference lhs, const_reference rhs, bool inverse = false) noexcept
    {
        if ((lhs.is_number_float() && std::isnan(lhs.m_data.m_value.number_float) && rhs.is_number())
                || (rhs.is_number_float() && std::isnan(rhs.m_data.m_value.number_float) && lhs.is_number()))
        {
            return true;
        }
#if JSON_USE_LEGACY_DISCARDED_VALUE_COMPARISON
        return (lhs.is_discarded() || rhs.is_discarded()) && !inverse;
#else
        static_cast<void>(inverse);
        return lhs.is_discarded() || rhs.is_discarded();
#endif
    }
  private:
    bool compares_unordered(const_reference rhs, bool inverse = false) const noexcept
    {
        return compares_unordered(*this, rhs, inverse);
    }
  public:
#if JSON_HAS_THREE_WAY_COMPARISON
    bool operator==(const_reference rhs) const noexcept
    {
#ifdef __GNUC__
        JSON_HEDLEY_DIAGNOSTIC_PUSH
        JSON_HEDLEY_PRAGMA(GCC diagnostic ignored "-Wfloat-equal")
#endif
        const_reference lhs = *this;
        JSON_IMPLEMENT_OPERATOR( ==, true, false, false,
                                 compare_iteratively<false>(lhs, rhs, false) == compare_result::equal, true)
#ifdef __GNUC__
        JSON_HEDLEY_DIAGNOSTIC_POP
#endif
    }
    template<typename ScalarType>
    requires std::is_scalar_v<ScalarType>
    bool operator==(ScalarType rhs) const noexcept(std::is_nothrow_constructible<basic_json, ScalarType>::value)
    {
        return *this == basic_json(rhs);
    }
    std::partial_ordering operator<=>(const_reference rhs) const noexcept 
    {
        const_reference lhs = *this;
        JSON_IMPLEMENT_OPERATOR(<=>, 
                                std::partial_ordering::equivalent,
                                std::partial_ordering::unordered,
                                lhs_type <=> rhs_type, 
                                to_partial_ordering(compare_iteratively<true>(lhs, rhs, false)), true)
    }
    template<typename ScalarType>
    requires std::is_scalar_v<ScalarType>
    std::partial_ordering operator<=>(ScalarType rhs) const noexcept(std::is_nothrow_constructible<basic_json, ScalarType>::value) 
    {
        return *this <=> basic_json(rhs); 
    }
#if JSON_USE_LEGACY_DISCARDED_VALUE_COMPARISON
    JSON_HEDLEY_DEPRECATED_FOR(3.11.0, undef JSON_USE_LEGACY_DISCARDED_VALUE_COMPARISON)
    bool operator<=(const_reference rhs) const noexcept
    {
        if (compares_unordered(rhs, true))
        {
            return false;
        }
        return !(rhs < *this);
    }
    template<typename ScalarType>
    requires std::is_scalar_v<ScalarType>
    bool operator<=(ScalarType rhs) const noexcept(std::is_nothrow_constructible<basic_json, ScalarType>::value)
    {
        return *this <= basic_json(rhs);
    }
    JSON_HEDLEY_DEPRECATED_FOR(3.11.0, undef JSON_USE_LEGACY_DISCARDED_VALUE_COMPARISON)
    bool operator>=(const_reference rhs) const noexcept
    {
        if (compares_unordered(rhs, true))
        {
            return false;
        }
        return !(*this < rhs);
    }
    template<typename ScalarType>
    requires std::is_scalar_v<ScalarType>
    bool operator>=(ScalarType rhs) const noexcept(std::is_nothrow_constructible<basic_json, ScalarType>::value)
    {
        return *this >= basic_json(rhs);
    }
#endif
#else
    friend bool operator==(const_reference lhs, const_reference rhs) noexcept
    {
#ifdef __GNUC__
        JSON_HEDLEY_DIAGNOSTIC_PUSH
        JSON_HEDLEY_PRAGMA(GCC diagnostic ignored "-Wfloat-equal")
#endif
        JSON_IMPLEMENT_OPERATOR( ==, true, false, false,
                                 compare_iteratively<false>(lhs, rhs, false) == compare_result::equal, true)
#ifdef __GNUC__
        JSON_HEDLEY_DIAGNOSTIC_POP
#endif
    }
    template<typename ScalarType, typename std::enable_if<
                 std::is_scalar<ScalarType>::value, int>::type = 0>
    friend bool operator==(const_reference lhs, ScalarType rhs) noexcept(std::is_nothrow_constructible<basic_json, ScalarType>::value)
    {
        return lhs == basic_json(rhs);
    }
    template<typename ScalarType, typename std::enable_if<
                 std::is_scalar<ScalarType>::value, int>::type = 0>
    friend bool operator==(ScalarType lhs, const_reference rhs) noexcept(std::is_nothrow_constructible<basic_json, ScalarType>::value)
    {
        return basic_json(lhs) == rhs;
    }
    friend bool operator!=(const_reference lhs, const_reference rhs) noexcept
    {
        return !(lhs == rhs);
    }
    template<typename ScalarType, typename std::enable_if<
                 std::is_scalar<ScalarType>::value, int>::type = 0>
    friend bool operator!=(const_reference lhs, ScalarType rhs) noexcept(std::is_nothrow_constructible<basic_json, ScalarType>::value)
    {
        return lhs != basic_json(rhs);
    }
    template<typename ScalarType, typename std::enable_if<
                 std::is_scalar<ScalarType>::value, int>::type = 0>
    friend bool operator!=(ScalarType lhs, const_reference rhs) noexcept(std::is_nothrow_constructible<basic_json, ScalarType>::value)
    {
        return basic_json(lhs) != rhs;
    }
    friend bool operator<(const_reference lhs, const_reference rhs) noexcept
    {
        JSON_IMPLEMENT_OPERATOR( <, false, false, operator<(lhs_type, rhs_type),
                                 compare_iteratively<true>(lhs, rhs, true) == compare_result::less, false)
    }
    template<typename ScalarType, typename std::enable_if<
                 std::is_scalar<ScalarType>::value, int>::type = 0>
    friend bool operator<(const_reference lhs, ScalarType rhs) noexcept(std::is_nothrow_constructible<basic_json, ScalarType>::value)
    {
        return lhs < basic_json(rhs);
    }
    template<typename ScalarType, typename std::enable_if<
                 std::is_scalar<ScalarType>::value, int>::type = 0>
    friend bool operator<(ScalarType lhs, const_reference rhs) noexcept(std::is_nothrow_constructible<basic_json, ScalarType>::value)
    {
        return basic_json(lhs) < rhs;
    }
    friend bool operator<=(const_reference lhs, const_reference rhs) noexcept
    {
        if (compares_unordered(lhs, rhs, true))
        {
            return false;
        }
        return !(rhs < lhs);
    }
    template<typename ScalarType, typename std::enable_if<
                 std::is_scalar<ScalarType>::value, int>::type = 0>
    friend bool operator<=(const_reference lhs, ScalarType rhs) noexcept(std::is_nothrow_constructible<basic_json, ScalarType>::value)
    {
        return lhs <= basic_json(rhs);
    }
    template<typename ScalarType, typename std::enable_if<
                 std::is_scalar<ScalarType>::value, int>::type = 0>
    friend bool operator<=(ScalarType lhs, const_reference rhs) noexcept(std::is_nothrow_constructible<basic_json, ScalarType>::value)
    {
        return basic_json(lhs) <= rhs;
    }
    friend bool operator>(const_reference lhs, const_reference rhs) noexcept
    {
        if (compares_unordered(lhs, rhs))
        {
            return false;
        }
        return !(lhs <= rhs);
    }
    template<typename ScalarType, typename std::enable_if<
                 std::is_scalar<ScalarType>::value, int>::type = 0>
    friend bool operator>(const_reference lhs, ScalarType rhs) noexcept(std::is_nothrow_constructible<basic_json, ScalarType>::value)
    {
        return lhs > basic_json(rhs);
    }
    template<typename ScalarType, typename std::enable_if<
                 std::is_scalar<ScalarType>::value, int>::type = 0>
    friend bool operator>(ScalarType lhs, const_reference rhs) noexcept(std::is_nothrow_constructible<basic_json, ScalarType>::value)
    {
        return basic_json(lhs) > rhs;
    }
    friend bool operator>=(const_reference lhs, const_reference rhs) noexcept
    {
        if (compares_unordered(lhs, rhs, true))
        {
            return false;
        }
        return !(lhs < rhs);
    }
    template<typename ScalarType, typename std::enable_if<
                 std::is_scalar<ScalarType>::value, int>::type = 0>
    friend bool operator>=(const_reference lhs, ScalarType rhs) noexcept(std::is_nothrow_constructible<basic_json, ScalarType>::value)
    {
        return lhs >= basic_json(rhs);
    }
    template<typename ScalarType, typename std::enable_if<
                 std::is_scalar<ScalarType>::value, int>::type = 0>
    friend bool operator>=(ScalarType lhs, const_reference rhs) noexcept(std::is_nothrow_constructible<basic_json, ScalarType>::value)
    {
        return basic_json(lhs) >= rhs;
    }
#endif
#undef JSON_IMPLEMENT_OPERATOR
#ifndef JSON_NO_IO
    friend std::ostream& operator<<(std::ostream& o, const basic_json& j)
    {
        const bool pretty_print = o.width() > 0;
        const auto indentation = pretty_print ? o.width() : 0;
        o.width(0);
        detail::output_stream_adapter<char> stream_adapter(o);
        serializer s(stream_adapter, o.fill(),
                     pretty_print, false, static_cast<std::size_t>(indentation));
        s.dump(j);
        return o;
    }
    JSON_HEDLEY_DEPRECATED_FOR(3.0.0, operator<<(std::ostream&, const basic_json&))
    friend std::ostream& operator>>(const basic_json& j, std::ostream& o)
    {
        return o << j;
    }
#endif  
    template<typename InputType>
    JSON_HEDLEY_WARN_UNUSED_RESULT
    static basic_json parse(InputType&& i,
                            parser_callback_t cb = nullptr,
                            const bool allow_exceptions = true,
                            const bool ignore_comments = false,
                            const bool ignore_trailing_commas = false)
    {
        basic_json result;
        parser(detail::input_adapter(std::forward<InputType>(i)), std::move(cb), allow_exceptions, ignore_comments, ignore_trailing_commas).parse(true, result); 
        return result;
    }
    template<typename IteratorType, typename SentinelType = IteratorType,
             detail::enable_if_t<detail::can_compare_ne<IteratorType, SentinelType>::value, int> = 0>
    JSON_HEDLEY_WARN_UNUSED_RESULT
    static basic_json parse(IteratorType first,
                            SentinelType last,
                            parser_callback_t cb = nullptr,
                            const bool allow_exceptions = true,
                            const bool ignore_comments = false,
                            const bool ignore_trailing_commas = false)
    {
        basic_json result;
        parser(detail::input_adapter(std::move(first), std::move(last)), std::move(cb), allow_exceptions, ignore_comments, ignore_trailing_commas).parse(true, result); 
        return result;
    }
    JSON_HEDLEY_WARN_UNUSED_RESULT
    JSON_HEDLEY_DEPRECATED_FOR(3.8.0, parse(ptr, ptr + len))
    static basic_json parse(detail::span_input_adapter&& i,
                            parser_callback_t cb = nullptr,
                            const bool allow_exceptions = true,
                            const bool ignore_comments = false,
                            const bool ignore_trailing_commas = false)
    {
        basic_json result;
        parser(i.get(), std::move(cb), allow_exceptions, ignore_comments, ignore_trailing_commas).parse(true, result); 
        return result;
    }
    template<typename InputType>
    JSON_HEDLEY_WARN_UNUSED_RESULT
    static bool accept(InputType&& i,
                       const bool ignore_comments = false,
                       const bool ignore_trailing_commas = false)
    {
        return parser(detail::input_adapter(std::forward<InputType>(i)), nullptr, false, ignore_comments, ignore_trailing_commas, true).accept(true);
    }
    template<typename IteratorType, typename SentinelType = IteratorType,
             detail::enable_if_t<detail::can_compare_ne<IteratorType, SentinelType>::value, int> = 0>
    JSON_HEDLEY_WARN_UNUSED_RESULT
    static bool accept(IteratorType first, SentinelType last,
                       const bool ignore_comments = false,
                       const bool ignore_trailing_commas = false)
    {
        return parser(detail::input_adapter(std::move(first), std::move(last)), nullptr, false, ignore_comments, ignore_trailing_commas, true).accept(true);
    }
    JSON_HEDLEY_WARN_UNUSED_RESULT
    JSON_HEDLEY_DEPRECATED_FOR(3.8.0, accept(ptr, ptr + len))
    static bool accept(detail::span_input_adapter&& i,
                       const bool ignore_comments = false,
                       const bool ignore_trailing_commas = false)
    {
        return parser(i.get(), nullptr, false, ignore_comments, ignore_trailing_commas, true).accept(true);
    }
    template <typename InputType, typename SAX>
    JSON_HEDLEY_NON_NULL(2)
    static bool sax_parse(InputType&& i, SAX* sax,
                          input_format_t format = input_format_t::json,
                          const bool strict = true,
                          const bool ignore_comments = false,
                          const bool ignore_trailing_commas = false)
    {
        auto ia = detail::input_adapter(std::forward<InputType>(i));
        return format == input_format_t::json
               ? parser(std::move(ia), nullptr, true, ignore_comments, ignore_trailing_commas).sax_parse(sax, strict)
               : detail::binary_reader<basic_json, decltype(ia), SAX>(std::move(ia), format).sax_parse(sax, strict);
    }
    template<class IteratorType, class SAX, class SentinelType = IteratorType,
             detail::enable_if_t<detail::can_compare_ne<IteratorType, SentinelType>::value, int> = 0>
    JSON_HEDLEY_NON_NULL(3)
    static bool sax_parse(IteratorType first, SentinelType last, SAX* sax,
                          input_format_t format = input_format_t::json,
                          const bool strict = true,
                          const bool ignore_comments = false,
                          const bool ignore_trailing_commas = false)
    {
        auto ia = detail::input_adapter(std::move(first), std::move(last));
        return format == input_format_t::json
               ? parser(std::move(ia), nullptr, true, ignore_comments, ignore_trailing_commas).sax_parse(sax, strict)
               : detail::binary_reader<basic_json, decltype(ia), SAX>(std::move(ia), format).sax_parse(sax, strict);
    }
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation-deprecated-sync"
#endif
    template <typename SAX>
    JSON_HEDLEY_DEPRECATED_FOR(3.8.0, sax_parse(ptr, ptr + len, ...))
    JSON_HEDLEY_NON_NULL(2)
    static bool sax_parse(detail::span_input_adapter&& i, SAX* sax,
                          input_format_t format = input_format_t::json,
                          const bool strict = true,
                          const bool ignore_comments = false,
                          const bool ignore_trailing_commas = false)
    {
        auto ia = i.get();
        return format == input_format_t::json
               ? parser(std::move(ia), nullptr, true, ignore_comments, ignore_trailing_commas).sax_parse(sax, strict)
               : detail::binary_reader<basic_json, decltype(ia), SAX>(std::move(ia), format).sax_parse(sax, strict);
    }
#if defined(__clang__)
#pragma clang diagnostic pop
#endif
#ifndef JSON_NO_IO
    JSON_HEDLEY_DEPRECATED_FOR(3.0.0, operator>>(std::istream&, basic_json&))
    friend std::istream& operator<<(basic_json& j, std::istream& i)
    {
        return operator>>(i, j);
    }
    friend std::istream& operator>>(std::istream& i, basic_json& j)
    {
        basic_json result;
        parser(detail::input_adapter(i)).parse(false, result);
        j = std::move(result);
        return i;
    }
#endif  
    JSON_HEDLEY_WARN_UNUSED_RESULT
    JSON_HEDLEY_RETURNS_NON_NULL
    const char* type_name() const noexcept
    {
        switch (m_data.m_type)
        {
            case value_t::null:
                return "null";
            case value_t::object:
                return "object";
            case value_t::array:
                return "array";
            case value_t::string:
                return "string";
            case value_t::boolean:
                return "boolean";
            case value_t::binary:
                return "binary";
            case value_t::discarded:
                return "discarded";
            case value_t::number_integer:
            case value_t::number_unsigned:
            case value_t::number_float:
                return "number";
            default:
                return "invalid";
        }
    }
  JSON_PRIVATE_UNLESS_TESTED:
    struct data
    {
        value_t m_type = value_t::null;
        json_value m_value = {};
        data(const value_t v)
            : m_type(v), m_value(v)
        {
        }
        data(size_type cnt, const basic_json& val)
            : m_type(value_t::array)
        {
            m_value.array = create<array_t>(cnt, val);
        }
        data() noexcept = default;
        data(data&&) noexcept = default;
        data(const data&) noexcept = delete;
        data& operator=(data&&) noexcept = delete;
        data& operator=(const data&) noexcept = delete;
        ~data() noexcept
        {
            m_value.destroy(m_type);
        }
    };
    data m_data = {}; 
#if JSON_DIAGNOSTICS
    basic_json* m_parent = nullptr;
#endif
#if JSON_DIAGNOSTIC_POSITIONS
    std::size_t start_position = std::string::npos;
    std::size_t end_position = std::string::npos;
  public:
    constexpr std::size_t start_pos() const noexcept
    {
        return start_position;
    }
    constexpr std::size_t end_pos() const noexcept
    {
        return end_position;
    }
#endif
  public:
    static std::vector<std::uint8_t> to_cbor(const basic_json& j)
    {
        std::vector<std::uint8_t> result;
        result.reserve(detail::binary_reserve_hint(j));
        vector_writer(result).write_cbor(j);
        return result;
    }
    static void to_cbor(const basic_json& j, detail::output_adapter<std::uint8_t> o)
    {
        binary_writer<std::uint8_t>(o).write_cbor(j);
    }
    static void to_cbor(const basic_json& j, detail::output_adapter<char> o)
    {
        binary_writer<char>(o).write_cbor(j);
    }
    static std::vector<std::uint8_t> to_msgpack(const basic_json& j)
    {
        std::vector<std::uint8_t> result;
        result.reserve(detail::binary_reserve_hint(j));
        vector_writer(result).write_msgpack(j);
        return result;
    }
    static void to_msgpack(const basic_json& j, detail::output_adapter<std::uint8_t> o)
    {
        binary_writer<std::uint8_t>(o).write_msgpack(j);
    }
    static void to_msgpack(const basic_json& j, detail::output_adapter<char> o)
    {
        binary_writer<char>(o).write_msgpack(j);
    }
    static std::vector<std::uint8_t> to_ubjson(const basic_json& j,
            const bool use_size = false,
            const bool use_type = false)
    {
        std::vector<std::uint8_t> result;
        result.reserve(detail::binary_reserve_hint(j));
        vector_writer(result).write_ubjson(j, use_size, use_type);
        return result;
    }
    static void to_ubjson(const basic_json& j, detail::output_adapter<std::uint8_t> o,
                          const bool use_size = false, const bool use_type = false)
    {
        binary_writer<std::uint8_t>(o).write_ubjson(j, use_size, use_type);
    }
    static void to_ubjson(const basic_json& j, detail::output_adapter<char> o,
                          const bool use_size = false, const bool use_type = false)
    {
        binary_writer<char>(o).write_ubjson(j, use_size, use_type);
    }
    static std::vector<std::uint8_t> to_bjdata(const basic_json& j,
            const bool use_size = false,
            const bool use_type = false,
            const bjdata_version_t version = bjdata_version_t::draft2)
    {
        std::vector<std::uint8_t> result;
        result.reserve(detail::binary_reserve_hint(j));
        vector_writer(result).write_ubjson(j, use_size, use_type, true, true, version);
        return result;
    }
    static void to_bjdata(const basic_json& j, detail::output_adapter<std::uint8_t> o,
                          const bool use_size = false, const bool use_type = false,
                          const bjdata_version_t version = bjdata_version_t::draft2)
    {
        binary_writer<std::uint8_t>(o).write_ubjson(j, use_size, use_type, true, true, version);
    }
    static void to_bjdata(const basic_json& j, detail::output_adapter<char> o,
                          const bool use_size = false, const bool use_type = false,
                          const bjdata_version_t version = bjdata_version_t::draft2)
    {
        binary_writer<char>(o).write_ubjson(j, use_size, use_type, true, true, version);
    }
    static std::vector<std::uint8_t> to_bson(const basic_json& j)
    {
        std::vector<std::uint8_t> result;
        result.reserve(detail::binary_reserve_hint(j));
        vector_writer(result).write_bson(j);
        return result;
    }
    static void to_bson(const basic_json& j, detail::output_adapter<std::uint8_t> o)
    {
        binary_writer<std::uint8_t>(o).write_bson(j);
    }
    static void to_bson(const basic_json& j, detail::output_adapter<char> o)
    {
        binary_writer<char>(o).write_bson(j);
    }
    static std::vector<std::uint8_t> to_bon8(const basic_json& j)
    {
        std::vector<std::uint8_t> result;
        result.reserve(detail::binary_reserve_hint(j));
        vector_writer(result).write_bon8(j);
        return result;
    }
    static void to_bon8(const basic_json& j, detail::output_adapter<std::uint8_t> o)
    {
        binary_writer<std::uint8_t>(o).write_bon8(j);
    }
    static void to_bon8(const basic_json& j, detail::output_adapter<char> o)
    {
        binary_writer<char>(o).write_bon8(j);
    }
    template<typename InputType>
    JSON_HEDLEY_WARN_UNUSED_RESULT
    static basic_json from_cbor(InputType&& i,
                                const bool strict = true,
                                const bool allow_exceptions = true,
                                const cbor_tag_handler_t tag_handler = cbor_tag_handler_t::error)
    {
        basic_json result;
        auto ia = detail::input_adapter(std::forward<InputType>(i));
        detail::json_sax_dom_parser<basic_json, decltype(ia)> sdp(result, allow_exceptions);
        if (!binary_reader<decltype(ia)>(std::move(ia), input_format_t::cbor).sax_parse(&sdp, strict, tag_handler)) 
        {
            result = value_t::discarded;
        }
        return result;
    }
    template<typename IteratorType, typename SentinelType = IteratorType,
             detail::enable_if_t<detail::can_compare_ne<IteratorType, SentinelType>::value, int> = 0>
    JSON_HEDLEY_WARN_UNUSED_RESULT
    static basic_json from_cbor(IteratorType first, SentinelType last,
                                const bool strict = true,
                                const bool allow_exceptions = true,
                                const cbor_tag_handler_t tag_handler = cbor_tag_handler_t::error)
    {
        basic_json result;
        auto ia = detail::input_adapter(std::move(first), std::move(last));
        detail::json_sax_dom_parser<basic_json, decltype(ia)> sdp(result, allow_exceptions);
        if (!binary_reader<decltype(ia)>(std::move(ia), input_format_t::cbor).sax_parse(&sdp, strict, tag_handler)) 
        {
            result = value_t::discarded;
        }
        return result;
    }
    template<typename T>
    JSON_HEDLEY_WARN_UNUSED_RESULT
    JSON_HEDLEY_DEPRECATED_FOR(3.8.0, from_cbor(ptr, ptr + len))
    static basic_json from_cbor(const T* ptr, std::size_t len,
                                const bool strict = true,
                                const bool allow_exceptions = true,
                                const cbor_tag_handler_t tag_handler = cbor_tag_handler_t::error)
    {
        return from_cbor(ptr, ptr + len, strict, allow_exceptions, tag_handler);
    }
    JSON_HEDLEY_WARN_UNUSED_RESULT
    JSON_HEDLEY_DEPRECATED_FOR(3.8.0, from_cbor(ptr, ptr + len))
    static basic_json from_cbor(detail::span_input_adapter&& i,
                                const bool strict = true,
                                const bool allow_exceptions = true,
                                const cbor_tag_handler_t tag_handler = cbor_tag_handler_t::error)
    {
        basic_json result;
        auto ia = i.get();
        detail::json_sax_dom_parser<basic_json, decltype(ia)> sdp(result, allow_exceptions);
        if (!binary_reader<decltype(ia)>(std::move(ia), input_format_t::cbor).sax_parse(&sdp, strict, tag_handler)) 
        {
            result = value_t::discarded;
        }
        return result;
    }
    template<typename InputType>
    JSON_HEDLEY_WARN_UNUSED_RESULT
    static basic_json from_msgpack(InputType&& i,
                                   const bool strict = true,
                                   const bool allow_exceptions = true)
    {
        basic_json result;
        auto ia = detail::input_adapter(std::forward<InputType>(i));
        detail::json_sax_dom_parser<basic_json, decltype(ia)> sdp(result, allow_exceptions);
        if (!binary_reader<decltype(ia)>(std::move(ia), input_format_t::msgpack).sax_parse(&sdp, strict)) 
        {
            result = value_t::discarded;
        }
        return result;
    }
    template<typename IteratorType, typename SentinelType = IteratorType,
             detail::enable_if_t<detail::can_compare_ne<IteratorType, SentinelType>::value, int> = 0>
    JSON_HEDLEY_WARN_UNUSED_RESULT
    static basic_json from_msgpack(IteratorType first, SentinelType last,
                                   const bool strict = true,
                                   const bool allow_exceptions = true)
    {
        basic_json result;
        auto ia = detail::input_adapter(std::move(first), std::move(last));
        detail::json_sax_dom_parser<basic_json, decltype(ia)> sdp(result, allow_exceptions);
        if (!binary_reader<decltype(ia)>(std::move(ia), input_format_t::msgpack).sax_parse(&sdp, strict)) 
        {
            result = value_t::discarded;
        }
        return result;
    }
    template<typename T>
    JSON_HEDLEY_WARN_UNUSED_RESULT
    JSON_HEDLEY_DEPRECATED_FOR(3.8.0, from_msgpack(ptr, ptr + len))
    static basic_json from_msgpack(const T* ptr, std::size_t len,
                                   const bool strict = true,
                                   const bool allow_exceptions = true)
    {
        return from_msgpack(ptr, ptr + len, strict, allow_exceptions);
    }
    JSON_HEDLEY_WARN_UNUSED_RESULT
    JSON_HEDLEY_DEPRECATED_FOR(3.8.0, from_msgpack(ptr, ptr + len))
    static basic_json from_msgpack(detail::span_input_adapter&& i,
                                   const bool strict = true,
                                   const bool allow_exceptions = true)
    {
        basic_json result;
        auto ia = i.get();
        detail::json_sax_dom_parser<basic_json, decltype(ia)> sdp(result, allow_exceptions);
        if (!binary_reader<decltype(ia)>(std::move(ia), input_format_t::msgpack).sax_parse(&sdp, strict)) 
        {
            result = value_t::discarded;
        }
        return result;
    }
    template<typename InputType>
    JSON_HEDLEY_WARN_UNUSED_RESULT
    static basic_json from_ubjson(InputType&& i,
                                  const bool strict = true,
                                  const bool allow_exceptions = true)
    {
        basic_json result;
        auto ia = detail::input_adapter(std::forward<InputType>(i));
        detail::json_sax_dom_parser<basic_json, decltype(ia)> sdp(result, allow_exceptions);
        if (!binary_reader<decltype(ia)>(std::move(ia), input_format_t::ubjson).sax_parse(&sdp, strict)) 
        {
            result = value_t::discarded;
        }
        return result;
    }
    template<typename IteratorType, typename SentinelType = IteratorType,
             detail::enable_if_t<detail::can_compare_ne<IteratorType, SentinelType>::value, int> = 0>
    JSON_HEDLEY_WARN_UNUSED_RESULT
    static basic_json from_ubjson(IteratorType first, SentinelType last,
                                  const bool strict = true,
                                  const bool allow_exceptions = true)
    {
        basic_json result;
        auto ia = detail::input_adapter(std::move(first), std::move(last));
        detail::json_sax_dom_parser<basic_json, decltype(ia)> sdp(result, allow_exceptions);
        if (!binary_reader<decltype(ia)>(std::move(ia), input_format_t::ubjson).sax_parse(&sdp, strict)) 
        {
            result = value_t::discarded;
        }
        return result;
    }
    template<typename T>
    JSON_HEDLEY_WARN_UNUSED_RESULT
    JSON_HEDLEY_DEPRECATED_FOR(3.8.0, from_ubjson(ptr, ptr + len))
    static basic_json from_ubjson(const T* ptr, std::size_t len,
                                  const bool strict = true,
                                  const bool allow_exceptions = true)
    {
        return from_ubjson(ptr, ptr + len, strict, allow_exceptions);
    }
    JSON_HEDLEY_WARN_UNUSED_RESULT
    JSON_HEDLEY_DEPRECATED_FOR(3.8.0, from_ubjson(ptr, ptr + len))
    static basic_json from_ubjson(detail::span_input_adapter&& i,
                                  const bool strict = true,
                                  const bool allow_exceptions = true)
    {
        basic_json result;
        auto ia = i.get();
        detail::json_sax_dom_parser<basic_json, decltype(ia)> sdp(result, allow_exceptions);
        if (!binary_reader<decltype(ia)>(std::move(ia), input_format_t::ubjson).sax_parse(&sdp, strict)) 
        {
            result = value_t::discarded;
        }
        return result;
    }
    template<typename InputType>
    JSON_HEDLEY_WARN_UNUSED_RESULT
    static basic_json from_bjdata(InputType&& i,
                                  const bool strict = true,
                                  const bool allow_exceptions = true)
    {
        basic_json result;
        auto ia = detail::input_adapter(std::forward<InputType>(i));
        detail::json_sax_dom_parser<basic_json, decltype(ia)> sdp(result, allow_exceptions);
        if (!binary_reader<decltype(ia)>(std::move(ia), input_format_t::bjdata).sax_parse(&sdp, strict)) 
        {
            result = value_t::discarded;
        }
        return result;
    }
    template<typename IteratorType, typename SentinelType = IteratorType,
             detail::enable_if_t<detail::can_compare_ne<IteratorType, SentinelType>::value, int> = 0>
    JSON_HEDLEY_WARN_UNUSED_RESULT
    static basic_json from_bjdata(IteratorType first, SentinelType last,
                                  const bool strict = true,
                                  const bool allow_exceptions = true)
    {
        basic_json result;
        auto ia = detail::input_adapter(std::move(first), std::move(last));
        detail::json_sax_dom_parser<basic_json, decltype(ia)> sdp(result, allow_exceptions);
        if (!binary_reader<decltype(ia)>(std::move(ia), input_format_t::bjdata).sax_parse(&sdp, strict)) 
        {
            result = value_t::discarded;
        }
        return result;
    }
    template<typename InputType>
    JSON_HEDLEY_WARN_UNUSED_RESULT
    static basic_json from_bon8(InputType&& i,
                                const bool strict = true,
                                const bool allow_exceptions = true)
    {
        basic_json result;
        auto ia = detail::input_adapter(std::forward<InputType>(i));
        detail::json_sax_dom_parser<basic_json, decltype(ia)> sdp(result, allow_exceptions);
        if (!binary_reader<decltype(ia)>(std::move(ia), input_format_t::bon8).sax_parse(&sdp, strict)) 
        {
            result = value_t::discarded;
        }
        return result;
    }
    template<typename IteratorType, typename SentinelType = IteratorType,
             detail::enable_if_t<detail::can_compare_ne<IteratorType, SentinelType>::value, int> = 0>
    JSON_HEDLEY_WARN_UNUSED_RESULT
    static basic_json from_bon8(IteratorType first, SentinelType last,
                                const bool strict = true,
                                const bool allow_exceptions = true)
    {
        basic_json result;
        auto ia = detail::input_adapter(std::move(first), std::move(last));
        detail::json_sax_dom_parser<basic_json, decltype(ia)> sdp(result, allow_exceptions);
        if (!binary_reader<decltype(ia)>(std::move(ia), input_format_t::bon8).sax_parse(&sdp, strict)) 
        {
            result = value_t::discarded;
        }
        return result;
    }
    template<typename InputType>
    JSON_HEDLEY_WARN_UNUSED_RESULT
    static basic_json from_bson(InputType&& i,
                                const bool strict = true,
                                const bool allow_exceptions = true)
    {
        basic_json result;
        auto ia = detail::input_adapter(std::forward<InputType>(i));
        detail::json_sax_dom_parser<basic_json, decltype(ia)> sdp(result, allow_exceptions);
        if (!binary_reader<decltype(ia)>(std::move(ia), input_format_t::bson).sax_parse(&sdp, strict)) 
        {
            result = value_t::discarded;
        }
        return result;
    }
    template<typename IteratorType, typename SentinelType = IteratorType,
             detail::enable_if_t<detail::can_compare_ne<IteratorType, SentinelType>::value, int> = 0>
    JSON_HEDLEY_WARN_UNUSED_RESULT
    static basic_json from_bson(IteratorType first, SentinelType last,
                                const bool strict = true,
                                const bool allow_exceptions = true)
    {
        basic_json result;
        auto ia = detail::input_adapter(std::move(first), std::move(last));
        detail::json_sax_dom_parser<basic_json, decltype(ia)> sdp(result, allow_exceptions);
        if (!binary_reader<decltype(ia)>(std::move(ia), input_format_t::bson).sax_parse(&sdp, strict)) 
        {
            result = value_t::discarded;
        }
        return result;
    }
    template<typename T>
    JSON_HEDLEY_WARN_UNUSED_RESULT
    JSON_HEDLEY_DEPRECATED_FOR(3.8.0, from_bson(ptr, ptr + len))
    static basic_json from_bson(const T* ptr, std::size_t len,
                                const bool strict = true,
                                const bool allow_exceptions = true)
    {
        return from_bson(ptr, ptr + len, strict, allow_exceptions);
    }
    JSON_HEDLEY_WARN_UNUSED_RESULT
    JSON_HEDLEY_DEPRECATED_FOR(3.8.0, from_bson(ptr, ptr + len))
    static basic_json from_bson(detail::span_input_adapter&& i,
                                const bool strict = true,
                                const bool allow_exceptions = true)
    {
        basic_json result;
        auto ia = i.get();
        detail::json_sax_dom_parser<basic_json, decltype(ia)> sdp(result, allow_exceptions);
        if (!binary_reader<decltype(ia)>(std::move(ia), input_format_t::bson).sax_parse(&sdp, strict)) 
        {
            result = value_t::discarded;
        }
        return result;
    }
    reference operator[](const json_pointer& ptr)
    {
        return ptr.get_unchecked(this);
    }
    template<typename BasicJsonType, detail::enable_if_t<detail::is_basic_json<BasicJsonType>::value, int> = 0>
    JSON_HEDLEY_DEPRECATED_FOR(3.11.0, basic_json::json_pointer or nlohmann::json_pointer<basic_json::string_t>) 
    reference operator[](const ::nlohmann::json_pointer<BasicJsonType>& ptr)
    {
        return ptr.get_unchecked(this);
    }
    const_reference operator[](const json_pointer& ptr) const
    {
        return ptr.get_unchecked(this);
    }
    template<typename BasicJsonType, detail::enable_if_t<detail::is_basic_json<BasicJsonType>::value, int> = 0>
    JSON_HEDLEY_DEPRECATED_FOR(3.11.0, basic_json::json_pointer or nlohmann::json_pointer<basic_json::string_t>) 
    const_reference operator[](const ::nlohmann::json_pointer<BasicJsonType>& ptr) const
    {
        return ptr.get_unchecked(this);
    }
    reference at(const json_pointer& ptr)
    {
        return ptr.get_checked(this);
    }
    template<typename BasicJsonType, detail::enable_if_t<detail::is_basic_json<BasicJsonType>::value, int> = 0>
    JSON_HEDLEY_DEPRECATED_FOR(3.11.0, basic_json::json_pointer or nlohmann::json_pointer<basic_json::string_t>) 
    reference at(const ::nlohmann::json_pointer<BasicJsonType>& ptr)
    {
        return ptr.get_checked(this);
    }
    const_reference at(const json_pointer& ptr) const
    {
        return ptr.get_checked(this);
    }
    template<typename BasicJsonType, detail::enable_if_t<detail::is_basic_json<BasicJsonType>::value, int> = 0>
    JSON_HEDLEY_DEPRECATED_FOR(3.11.0, basic_json::json_pointer or nlohmann::json_pointer<basic_json::string_t>) 
    const_reference at(const ::nlohmann::json_pointer<BasicJsonType>& ptr) const
    {
        return ptr.get_checked(this);
    }
    basic_json flatten() const
    {
        basic_json result(value_t::object);
        json_pointer::flatten("", *this, result);
        return result;
    }
    basic_json unflatten() const
    {
        return json_pointer::unflatten(*this);
    }
    void patch_inplace(const basic_json& json_patch)
    {
        basic_json& result = *this;
        enum class patch_operations {add, remove, replace, move, copy, test, invalid};
        const auto get_op = [](const string_t& op)
        {
            if (op == "add")
            {
                return patch_operations::add;
            }
            if (op == "remove")
            {
                return patch_operations::remove;
            }
            if (op == "replace")
            {
                return patch_operations::replace;
            }
            if (op == "move")
            {
                return patch_operations::move;
            }
            if (op == "copy")
            {
                return patch_operations::copy;
            }
            if (op == "test")
            {
                return patch_operations::test;
            }
            return patch_operations::invalid;
        };
        const auto operation_add = [&result](json_pointer & ptr, const basic_json & val)
        {
            if (ptr.empty())
            {
                result = val;
                return;
            }
            json_pointer const top_pointer = ptr.top();
            if (top_pointer != ptr)
            {
                result.at(top_pointer);
            }
            const auto last_path = ptr.back();
            ptr.pop_back();
            basic_json& parent = result.at(ptr);
            switch (parent.m_data.m_type)
            {
                case value_t::null:
                case value_t::object:
                {
                    parent[last_path] = val;
                    break;
                }
                case value_t::array:
                {
                    if (last_path == "-")
                    {
                        parent.push_back(val);
                    }
                    else
                    {
                        const auto idx = json_pointer::template array_index<basic_json_t>(last_path);
                        if (JSON_HEDLEY_UNLIKELY(idx > parent.size()))
                        {
                            JSON_THROW(out_of_range::create(401, detail::concat("array index ", std::to_string(idx), " is out of range"), &parent));
                        }
                        parent.insert(parent.begin() + static_cast<difference_type>(idx), val);
                    }
                    break;
                }
                case value_t::string:
                case value_t::boolean:
                case value_t::number_integer:
                case value_t::number_unsigned:
                case value_t::number_float:
                case value_t::binary:
                case value_t::discarded:
                default:
                    JSON_THROW(out_of_range::create(411, detail::concat("cannot add value: the JSON Patch 'add' target's parent is of type ", parent.type_name(), ", but must be an object or array"), &parent));
            }
        };
        const auto operation_remove = [this, & result](json_pointer & ptr)
        {
            const auto last_path = ptr.back();
            ptr.pop_back();
            basic_json& parent = result.at(ptr);
            if (parent.is_object())
            {
                auto it = parent.find(last_path);
                if (JSON_HEDLEY_LIKELY(it != parent.end()))
                {
                    parent.erase(it);
                }
                else
                {
                    JSON_THROW(out_of_range::create(403, detail::concat("key '", last_path, "' not found"), this));
                }
            }
            else if (parent.is_array())
            {
                parent.erase(json_pointer::template array_index<basic_json_t>(last_path));
            }
            else
            {
                JSON_THROW(out_of_range::create(413, detail::concat("cannot remove value: the JSON Patch 'remove' target's parent is of type ", parent.type_name(), ", but must be an object or array"), &parent));
            }
        };
        const auto is_proper_prefix = [](const json_pointer & from, const json_pointer & to)
        {
            const auto from_size = from.reference_tokens.size();
            if (from_size >= to.reference_tokens.size())
            {
                return false;
            }
            for (std::size_t i = 0; i < from_size; ++i)
            {
                if (!(from.reference_tokens[i] == to.reference_tokens[i]))
                {
                    return false;
                }
            }
            return true;
        };
        if (JSON_HEDLEY_UNLIKELY(!json_patch.is_array()))
        {
            JSON_THROW(parse_error::create(104, 0, "JSON patch must be an array of objects", &json_patch));
        }
        for (const auto& val : json_patch)
        {
            const auto get_value = [&val](const string_t& op,
                                          const string_t& member,
                                          bool string_type) -> basic_json &
            {
                auto it = val.m_data.m_value.object->find(member);
                const auto error_msg = (op == "op") ? "operation" : detail::concat("operation '", op, '\''); 
                if (JSON_HEDLEY_UNLIKELY(it == val.m_data.m_value.object->end()))
                {
                    JSON_THROW(parse_error::create(105, 0, detail::concat(error_msg, " must have member '", member, "'"), &val));
                }
                if (JSON_HEDLEY_UNLIKELY(string_type && !it->second.is_string()))
                {
                    JSON_THROW(parse_error::create(105, 0, detail::concat(error_msg, " must have string member '", member, "'"), &val));
                }
                return it->second;
            };
            if (JSON_HEDLEY_UNLIKELY(!val.is_object()))
            {
                JSON_THROW(parse_error::create(104, 0, "JSON patch must be an array of objects", &val));
            }
            const auto op = get_value("op", "op", true).template get<string_t>();
            const auto path = get_value(op, "path", true).template get<string_t>();
            json_pointer ptr(path);
            switch (get_op(op))
            {
                case patch_operations::add:
                {
                    operation_add(ptr, get_value("add", "value", false));
                    break;
                }
                case patch_operations::remove:
                {
                    operation_remove(ptr);
                    break;
                }
                case patch_operations::replace:
                {
                    result.at(ptr) = get_value("replace", "value", false);
                    break;
                }
                case patch_operations::move:
                {
                    const auto from_path = get_value("move", "from", true).template get<string_t>();
                    json_pointer from_ptr(from_path);
                    if (JSON_HEDLEY_UNLIKELY(is_proper_prefix(from_ptr, ptr)))
                    {
                        JSON_THROW(out_of_range::create(414, detail::concat("cannot move value: 'from' path '", from_path, "' is a proper prefix of 'path' '", path, "'"), &result));
                    }
                    basic_json const v = result.at(from_ptr);
                    operation_remove(from_ptr);
                    operation_add(ptr, v);
                    break;
                }
                case patch_operations::copy:
                {
                    const auto from_path = get_value("copy", "from", true).template get<string_t>();
                    const json_pointer from_ptr(from_path);
                    basic_json const v = result.at(from_ptr);
                    operation_add(ptr, v);
                    break;
                }
                case patch_operations::test:
                {
                    bool success = false;
                    JSON_TRY
                    {
                        success = (result.at(ptr) == get_value("test", "value", false));
                    }
                    JSON_INTERNAL_CATCH (out_of_range&)
                    {
                    }
                    if (JSON_HEDLEY_UNLIKELY(!success))
                    {
                        JSON_THROW(other_error::create(501, detail::concat("unsuccessful: ", val.dump()), &val));
                    }
                    break;
                }
                case patch_operations::invalid:
                default:
                {
                    JSON_THROW(parse_error::create(105, 0, detail::concat("operation value '", op, "' is invalid"), &val));
                }
            }
        }
    }
    basic_json patch(const basic_json& json_patch) const
    {
        basic_json result = *this;
        result.patch_inplace(json_patch);
        return result;
    }
    JSON_HEDLEY_WARN_UNUSED_RESULT
    static basic_json diff(const basic_json& source, const basic_json& target,
                           const string_t& path = "")
    {
        basic_json result(value_t::array);
        diff_recursively(result, source, target, path, 0);
        return result;
    }
  private:
    struct diff_frame
    {
        diff_frame(const basic_json* source_, const basic_json* target_, const std::size_t path_length_) noexcept
            : source(source_), target(target_), path_length(path_length_)
        {}
        diff_frame(const diff_frame&) = default;
        diff_frame(diff_frame&&) = default;
        diff_frame& operator=(const diff_frame&) = default;
        diff_frame& operator=(diff_frame&&) = default;
        ~diff_frame() = default;
        const basic_json* source;
        const basic_json* target;
        std::size_t path_length;
        std::size_t index = 0;
        const_iterator member{}; 
        std::vector<typename object_t::key_type> common_keys{}; 
        std::size_t next_common = 0;
        basic_json added_ops{}; 
    };
    static void diff_replace(basic_json& result, const string_t& path, const basic_json& value)
    {
        result.push_back(
        {
            {"op", "replace"}, {"path", path}, {"value", value}
        });
    }
    static void diff_remove(basic_json& result, const string_t& path)
    {
        result.push_back(object(
        {
            {"op", "remove"}, {"path", path}
        }));
    }
    static void diff_add(basic_json& result, const string_t& path, const basic_json& value)
    {
        result.push_back(
        {
            {"op", "add"}, {"path", path}, {"value", value}
        });
    }
    static void diff_array_tails(basic_json& result, const basic_json& source, const basic_json& target,
                                 const string_t& path, const std::size_t index)
    {
        for (std::size_t j = source.size(); j > index; --j)
        {
            diff_remove(result, detail::concat<string_t>(path, '/', detail::to_string<string_t>(j - 1)));
        }
        for (std::size_t i = source.size(); i < target.size(); ++i)
        {
            diff_add(result, detail::concat<string_t>(path, "/-"), target[i]);
        }
    }
    static bool diff_object_keys(basic_json& result, const basic_json& source, const basic_json& target,
                                 const string_t& path, std::vector<typename object_t::key_type>& common_keys,
                                 basic_json& added_ops)
    {
        std::vector<typename object_t::key_type> common_keys_source_order;
        for (auto it = source.cbegin(); it != source.cend(); ++it)
        {
            if (target.find(it.key()) != target.end())
            {
                common_keys_source_order.push_back(it.key());
            }
        }
        std::vector<typename object_t::key_type> common_keys_target_order;
        bool new_keys_form_suffix = true;
        bool seen_new_key = false;
        for (auto it = target.cbegin(); it != target.cend(); ++it)
        {
            if (source.find(it.key()) == source.end())
            {
                seen_new_key = true;
                diff_add(added_ops, detail::concat<string_t>(path, '/', detail::escape(it.key())), it.value());
            }
            else
            {
#ifdef JSON_HEDLEY_MSVC_VERSION
#pragma warning(push )
#pragma warning(disable : 4127) 
#endif
                if (detail::is_ordered_map<object_t>::value)
                {
                    common_keys_target_order.push_back(it.key());
                    if (seen_new_key)
                    {
                        new_keys_form_suffix = false;
                    }
                }
#ifdef JSON_HEDLEY_MSVC_VERSION
#pragma warning( pop )
#endif
            }
        }
#ifdef JSON_HEDLEY_MSVC_VERSION
#pragma warning(push )
#pragma warning(disable : 4127) 
#endif
        if (!detail::is_ordered_map<object_t>::value
                || (common_keys_source_order == common_keys_target_order && new_keys_form_suffix))
        {
            common_keys = std::move(common_keys_source_order);
            return true;
        }
#ifdef JSON_HEDLEY_MSVC_VERSION
#pragma warning( pop )
#endif
        for (auto it = source.cbegin(); it != source.cend(); ++it)
        {
            diff_remove(result, detail::concat<string_t>(path, '/', detail::escape(it.key())));
        }
        for (auto it = target.cbegin(); it != target.cend(); ++it)
        {
            diff_add(result, detail::concat<string_t>(path, '/', detail::escape(it.key())), it.value());
        }
        return false;
    }
    static void diff_recursively(basic_json& result, const basic_json& source, const basic_json& target,
                                 const string_t& path, const std::size_t depth)
    {
        if (source == target)
        {
            return;
        }
        if (JSON_HEDLEY_UNLIKELY(depth >= detail::recursion_depth_limit()))
        {
            diff_iteratively(result, source, target, path);
            return;
        }
        if (source.type() != target.type())
        {
            diff_replace(result, path, target);
            return;
        }
        switch (source.type())
        {
            case value_t::array:
            {
                std::size_t i = 0;
                while (i < source.size() && i < target.size())
                {
                    diff_recursively(result, source[i], target[i], detail::concat<string_t>(path, '/', detail::to_string<string_t>(i)), depth + 1);
                    ++i;
                }
                diff_array_tails(result, source, target, path, i);
                break;
            }
            case value_t::object:
            {
                std::vector<typename object_t::key_type> common_keys;
                basic_json added_ops(value_t::array);
                if (diff_object_keys(result, source, target, path, common_keys, added_ops))
                {
                    auto common_it = common_keys.cbegin();
                    for (auto it = source.cbegin(); it != source.cend(); ++it)
                    {
                        if (common_it != common_keys.cend() && it.key() == *common_it)
                        {
                            diff_recursively(result, it.value(), target[it.key()], detail::concat<string_t>(path, '/', detail::escape(it.key())), depth + 1);
                            ++common_it;
                        }
                        else
                        {
                            diff_remove(result, detail::concat<string_t>(path, '/', detail::escape(it.key())));
                        }
                    }
                    result.insert(result.end(), added_ops.begin(), added_ops.end());
                }
                break;
            }
            case value_t::null:
            case value_t::string:
            case value_t::boolean:
            case value_t::number_integer:
            case value_t::number_unsigned:
            case value_t::number_float:
            case value_t::binary:
            case value_t::discarded:
            default:
            {
                diff_replace(result, path, target);
                break;
            }
        }
    }
    static void diff_iteratively(basic_json& result, const basic_json& source, const basic_json& target,
                                 const string_t& path)
    {
        std::vector<diff_frame> stack;
        string_t current_path = path;
        const auto enter = [&result, &stack, &current_path](const basic_json & s, const basic_json & t)
        {
            if ((!s.is_structured() || !t.is_structured()) && s == t)
            {
                return;
            }
            if (s.type() != t.type())
            {
                diff_replace(result, current_path, t);
                return;
            }
            switch (s.type())
            {
                case value_t::array:
                {
                    stack.emplace_back(&s, &t, current_path.size());
                    return;
                }
                case value_t::object:
                {
                    std::vector<typename object_t::key_type> common_keys;
                    basic_json added_ops(value_t::array);
                    if (diff_object_keys(result, s, t, current_path, common_keys, added_ops))
                    {
                        stack.emplace_back(&s, &t, current_path.size());
                        stack.back().member = s.cbegin();
                        stack.back().common_keys = std::move(common_keys);
                        stack.back().added_ops = std::move(added_ops);
                    }
                    return;
                }
                case value_t::null:
                case value_t::string:
                case value_t::boolean:
                case value_t::number_integer:
                case value_t::number_unsigned:
                case value_t::number_float:
                case value_t::binary:
                case value_t::discarded:
                default:
                {
                    diff_replace(result, current_path, t);
                    return;
                }
            }
        };
        enter(source, target);
        while (!stack.empty())
        {
            const basic_json* const s = stack.back().source;
            const basic_json* const t = stack.back().target;
            const std::size_t path_length = stack.back().path_length;
            const std::size_t depth = stack.size();
            if (s->is_array())
            {
                const auto& source_array = *s->m_data.m_value.array;
                const auto& target_array = *t->m_data.m_value.array;
                const std::size_t i = stack.back().index;
                if (i < source_array.size() && i < target_array.size())
                {
                    ++stack.back().index;
                    detail::concat_into(current_path, '/', detail::to_string<string_t>(i));
                    enter(source_array[i], target_array[i]);
                    if (stack.size() == depth)
                    {
                        current_path.resize(path_length);
                    }
                    continue;
                }
                diff_array_tails(result, *s, *t, current_path, i);
            }
            else
            {
                const const_iterator it = stack.back().member;
                if (it != s->cend())
                {
                    ++stack.back().member;
                    const std::size_t next_common = stack.back().next_common;
                    if (next_common < stack.back().common_keys.size() && it.key() == stack.back().common_keys[next_common])
                    {
                        ++stack.back().next_common;
                        const basic_json& target_value = (*t)[it.key()];
                        detail::concat_into(current_path, '/', detail::escape(it.key()));
                        enter(it.value(), target_value);
                        if (stack.size() == depth)
                        {
                            current_path.resize(path_length);
                        }
                    }
                    else
                    {
                        diff_remove(result, detail::concat<string_t>(current_path, '/', detail::escape(it.key())));
                    }
                    continue;
                }
                result.insert(result.end(), stack.back().added_ops.begin(), stack.back().added_ops.end());
            }
            stack.pop_back();
            if (!stack.empty())
            {
                current_path.resize(stack.back().path_length);
            }
        }
    }
  public:
    void merge_patch(const basic_json& apply_patch)
    {
        basic_json patch = apply_patch;
        apply_merge_patch(patch, 0);
    }
  private:
    void apply_merge_patch(basic_json& apply_patch, const std::size_t depth)
    {
        if (apply_patch.is_object())
        {
            if (JSON_HEDLEY_UNLIKELY(depth >= detail::recursion_depth_limit()))
            {
                merge_patch_iteratively(apply_patch);
                return;
            }
            if (!is_object())
            {
                *this = object();
            }
            for (auto it = apply_patch.begin(); it != apply_patch.end(); ++it)
            {
                if (it.value().is_null())
                {
                    erase(it.key());
                }
                else
                {
                    operator[](it.key()).apply_merge_patch(it.value(), depth + 1);
                }
            }
        }
        else
        {
            *this = std::move(apply_patch);
        }
    }
    void merge_patch_iteratively(basic_json& apply_patch)
    {
        std::vector<merge_frame> stack;
        const auto apply = [&stack](basic_json & target, basic_json & patch)
        {
            if (patch.is_object())
            {
                if (!target.is_object())
                {
                    target = basic_json::object();
                }
                stack.emplace_back(&target, patch.begin(), patch.end());
            }
            else
            {
                target = std::move(patch);
            }
        };
        apply(*this, apply_patch);
        while (!stack.empty())
        {
            const merge_frame frame = stack.back();
            if (frame.position == frame.last)
            {
                stack.pop_back();
                continue;
            }
            const iterator member = frame.position;
            ++stack.back().position;
            if (member.value().is_null())
            {
                frame.target->erase(member.key());
            }
            else
            {
                apply(frame.target->operator[](member.key()), member.value());
            }
        }
    }
  public:
};
NLOHMANN_BASIC_JSON_TPL_DECLARATION
std::string to_string(const NLOHMANN_BASIC_JSON_TPL& j)
{
    return j.dump();
}
NLOHMANN_BASIC_JSON_TPL_DECLARATION
std::string format_as(const NLOHMANN_BASIC_JSON_TPL& j)
{
    return j.dump();
}
NLOHMANN_JSON_NAMESPACE_END
namespace std 
{
NLOHMANN_BASIC_JSON_TPL_DECLARATION
struct hash<nlohmann::NLOHMANN_BASIC_JSON_TPL> 
{
    std::size_t operator()(const nlohmann::NLOHMANN_BASIC_JSON_TPL& j) const
    {
        return nlohmann::detail::hash(j);
    }
};
template<>
struct less< ::nlohmann::detail::value_t> 
{
    bool operator()(::nlohmann::detail::value_t lhs,
                    ::nlohmann::detail::value_t rhs) const noexcept
    {
#if JSON_HAS_THREE_WAY_COMPARISON
        return std::is_lt(lhs <=> rhs); 
#else
        return ::nlohmann::detail::operator<(lhs, rhs);
#endif
    }
};
#ifndef JSON_HAS_CPP_20
NLOHMANN_BASIC_JSON_TPL_DECLARATION
inline void swap(nlohmann::NLOHMANN_BASIC_JSON_TPL& j1, nlohmann::NLOHMANN_BASIC_JSON_TPL& j2) noexcept(  
    is_nothrow_move_constructible<nlohmann::NLOHMANN_BASIC_JSON_TPL>::value&&                          
    is_nothrow_move_assignable<nlohmann::NLOHMANN_BASIC_JSON_TPL>::value)
{
    j1.swap(j2);
}
#endif
#if JSON_HAS_STD_FORMAT
NLOHMANN_BASIC_JSON_TPL_DECLARATION
struct formatter<nlohmann::NLOHMANN_BASIC_JSON_TPL, char> 
{
    int indent = -1;
    char indent_char = ' ';
    constexpr format_parse_context::iterator parse(format_parse_context& ctx)
    {
        format_parse_context::iterator it = ctx.begin();
        const format_parse_context::iterator end = ctx.end();
        constexpr auto is_align = [](char c)
        {
            return c == '<' || c == '>' || c == '^';
        };
        if (it != end && it + 1 != end && is_align(it[1]))
        {
            indent_char = *it;
            it += 2;
        }
        else if (it != end && is_align(*it))
        {
            ++it;
        }
        if (it != end && *it == '#')
        {
            indent = 4;
            ++it;
        }
        if (it != end && *it >= '1' && *it <= '9')
        {
            indent = 0;
            while (it != end && *it >= '0' && *it <= '9')
            {
                indent = (indent * 10) + (*it - '0');
                ++it;
            }
        }
        if (it != end && *it != '}')
        {
            JSON_THROW(format_error("invalid format args for nlohmann::json"));
        }
        return it;
    }
    template<typename FormatContext>
    auto format(const nlohmann::NLOHMANN_BASIC_JSON_TPL& j, FormatContext& ctx) const -> decltype(ctx.out())
    {
        const auto dumped = j.dump(indent, indent_char);
        return std::copy(dumped.begin(), dumped.end(), ctx.out());
    }
};
#endif
}  
#undef JSON_ASSERT
#undef JSON_INTERNAL_CATCH
#undef JSON_THROW
#undef JSON_PRIVATE_UNLESS_TESTED
#undef NLOHMANN_BASIC_JSON_TPL_DECLARATION
#undef NLOHMANN_BASIC_JSON_TPL
#undef JSON_EXPLICIT
#undef NLOHMANN_CAN_CALL_STD_FUNC_IMPL
#undef JSON_INLINE_VARIABLE
#undef JSON_NO_UNIQUE_ADDRESS
#undef JSON_DISABLE_ENUM_SERIALIZATION
#undef JSON_DISABLE_TUPLE_REFERENCE_CONVERSION
#ifndef JSON_TEST_KEEP_MACROS
    #undef JSON_CATCH
    #undef JSON_TRY
    #undef JSON_HAS_CPP_11
    #undef JSON_HAS_CPP_14
    #undef JSON_HAS_CPP_17
    #undef JSON_HAS_CPP_20
    #undef JSON_HAS_CPP_23
    #undef JSON_HAS_CPP_26
    #undef JSON_HAS_FILESYSTEM
    #undef JSON_HAS_EXPERIMENTAL_FILESYSTEM
    #undef JSON_HAS_THREE_WAY_COMPARISON
    #undef JSON_HAS_RANGES
    #undef JSON_HAS_STD_FORMAT
    #undef JSON_HAS_STATIC_RTTI
    #undef JSON_USE_LEGACY_DISCARDED_VALUE_COMPARISON
    #undef JSON_BRACE_INIT_COPY_SEMANTICS
    #undef JSON_PRECISE_STREAM_POSITION
    #undef JSON_STRICT_NUL_HANDLING
#endif
#undef JSON_HEDLEY_ALWAYS_INLINE
#undef JSON_HEDLEY_ARM_VERSION
#undef JSON_HEDLEY_ARM_VERSION_CHECK
#undef JSON_HEDLEY_ARRAY_PARAM
#undef JSON_HEDLEY_ASSUME
#undef JSON_HEDLEY_BEGIN_C_DECLS
#undef JSON_HEDLEY_CLANG_HAS_ATTRIBUTE
#undef JSON_HEDLEY_CLANG_HAS_BUILTIN
#undef JSON_HEDLEY_CLANG_HAS_CPP_ATTRIBUTE
#undef JSON_HEDLEY_CLANG_HAS_DECLSPEC_ATTRIBUTE
#undef JSON_HEDLEY_CLANG_HAS_EXTENSION
#undef JSON_HEDLEY_CLANG_HAS_FEATURE
#undef JSON_HEDLEY_CLANG_HAS_WARNING
#undef JSON_HEDLEY_COMPCERT_VERSION
#undef JSON_HEDLEY_COMPCERT_VERSION_CHECK
#undef JSON_HEDLEY_CONCAT
#undef JSON_HEDLEY_CONCAT3
#undef JSON_HEDLEY_CONCAT3_EX
#undef JSON_HEDLEY_CONCAT_EX
#undef JSON_HEDLEY_CONST
#undef JSON_HEDLEY_CONSTEXPR
#undef JSON_HEDLEY_CONST_CAST
#undef JSON_HEDLEY_CPP_CAST
#undef JSON_HEDLEY_CRAY_VERSION
#undef JSON_HEDLEY_CRAY_VERSION_CHECK
#undef JSON_HEDLEY_C_DECL
#undef JSON_HEDLEY_DEPRECATED
#undef JSON_HEDLEY_DEPRECATED_FOR
#undef JSON_HEDLEY_DIAGNOSTIC_DISABLE_CAST_QUAL
#undef JSON_HEDLEY_DIAGNOSTIC_DISABLE_CPP98_COMPAT_WRAP_
#undef JSON_HEDLEY_DIAGNOSTIC_DISABLE_DEPRECATED
#undef JSON_HEDLEY_DIAGNOSTIC_DISABLE_UNKNOWN_CPP_ATTRIBUTES
#undef JSON_HEDLEY_DIAGNOSTIC_DISABLE_UNKNOWN_PRAGMAS
#undef JSON_HEDLEY_DIAGNOSTIC_DISABLE_UNUSED_FUNCTION
#undef JSON_HEDLEY_DIAGNOSTIC_POP
#undef JSON_HEDLEY_DIAGNOSTIC_PUSH
#undef JSON_HEDLEY_DMC_VERSION
#undef JSON_HEDLEY_DMC_VERSION_CHECK
#undef JSON_HEDLEY_EMPTY_BASES
#undef JSON_HEDLEY_EMSCRIPTEN_VERSION
#undef JSON_HEDLEY_EMSCRIPTEN_VERSION_CHECK
#undef JSON_HEDLEY_END_C_DECLS
#undef JSON_HEDLEY_FLAGS
#undef JSON_HEDLEY_FLAGS_CAST
#undef JSON_HEDLEY_GCC_HAS_ATTRIBUTE
#undef JSON_HEDLEY_GCC_HAS_BUILTIN
#undef JSON_HEDLEY_GCC_HAS_CPP_ATTRIBUTE
#undef JSON_HEDLEY_GCC_HAS_DECLSPEC_ATTRIBUTE
#undef JSON_HEDLEY_GCC_HAS_EXTENSION
#undef JSON_HEDLEY_GCC_HAS_FEATURE
#undef JSON_HEDLEY_GCC_HAS_WARNING
#undef JSON_HEDLEY_GCC_NOT_CLANG_VERSION_CHECK
#undef JSON_HEDLEY_GCC_VERSION
#undef JSON_HEDLEY_GCC_VERSION_CHECK
#undef JSON_HEDLEY_GNUC_HAS_ATTRIBUTE
#undef JSON_HEDLEY_GNUC_HAS_BUILTIN
#undef JSON_HEDLEY_GNUC_HAS_CPP_ATTRIBUTE
#undef JSON_HEDLEY_GNUC_HAS_DECLSPEC_ATTRIBUTE
#undef JSON_HEDLEY_GNUC_HAS_EXTENSION
#undef JSON_HEDLEY_GNUC_HAS_FEATURE
#undef JSON_HEDLEY_GNUC_HAS_WARNING
#undef JSON_HEDLEY_GNUC_VERSION
#undef JSON_HEDLEY_GNUC_VERSION_CHECK
#undef JSON_HEDLEY_HAS_ATTRIBUTE
#undef JSON_HEDLEY_HAS_BUILTIN
#undef JSON_HEDLEY_HAS_CPP_ATTRIBUTE
#undef JSON_HEDLEY_HAS_CPP_ATTRIBUTE_NS
#undef JSON_HEDLEY_HAS_DECLSPEC_ATTRIBUTE
#undef JSON_HEDLEY_HAS_EXTENSION
#undef JSON_HEDLEY_HAS_FEATURE
#undef JSON_HEDLEY_HAS_WARNING
#undef JSON_HEDLEY_IAR_VERSION
#undef JSON_HEDLEY_IAR_VERSION_CHECK
#undef JSON_HEDLEY_IBM_VERSION
#undef JSON_HEDLEY_IBM_VERSION_CHECK
#undef JSON_HEDLEY_IMPORT
#undef JSON_HEDLEY_INLINE
#undef JSON_HEDLEY_INTEL_CL_VERSION
#undef JSON_HEDLEY_INTEL_CL_VERSION_CHECK
#undef JSON_HEDLEY_INTEL_VERSION
#undef JSON_HEDLEY_INTEL_VERSION_CHECK
#undef JSON_HEDLEY_IS_CONSTANT
#undef JSON_HEDLEY_IS_CONSTEXPR_
#undef JSON_HEDLEY_LIKELY
#undef JSON_HEDLEY_MALLOC
#undef JSON_HEDLEY_MCST_LCC_VERSION
#undef JSON_HEDLEY_MCST_LCC_VERSION_CHECK
#undef JSON_HEDLEY_MESSAGE
#undef JSON_HEDLEY_MSVC_VERSION
#undef JSON_HEDLEY_MSVC_VERSION_CHECK
#undef JSON_HEDLEY_NEVER_INLINE
#undef JSON_HEDLEY_NON_NULL
#undef JSON_HEDLEY_NO_ESCAPE
#undef JSON_HEDLEY_NO_RETURN
#undef JSON_HEDLEY_NO_THROW
#undef JSON_HEDLEY_NULL
#undef JSON_HEDLEY_PELLES_VERSION
#undef JSON_HEDLEY_PELLES_VERSION_CHECK
#undef JSON_HEDLEY_PGI_VERSION
#undef JSON_HEDLEY_PGI_VERSION_CHECK
#undef JSON_HEDLEY_PRAGMA
#undef JSON_HEDLEY_PREDICT
#undef JSON_HEDLEY_PREDICT_FALSE
#undef JSON_HEDLEY_PREDICT_TRUE
#undef JSON_HEDLEY_PRINTF_FORMAT
#undef JSON_HEDLEY_PRIVATE
#undef JSON_HEDLEY_PUBLIC
#undef JSON_HEDLEY_PURE
#undef JSON_HEDLEY_REINTERPRET_CAST
#undef JSON_HEDLEY_REQUIRE
#undef JSON_HEDLEY_REQUIRE_CONSTEXPR
#undef JSON_HEDLEY_REQUIRE_MSG
#undef JSON_HEDLEY_RESTRICT
#undef JSON_HEDLEY_RETURNS_NON_NULL
#undef JSON_HEDLEY_SENTINEL
#undef JSON_HEDLEY_STATIC_ASSERT
#undef JSON_HEDLEY_STATIC_CAST
#undef JSON_HEDLEY_STRINGIFY
#undef JSON_HEDLEY_STRINGIFY_EX
#undef JSON_HEDLEY_SUNPRO_VERSION
#undef JSON_HEDLEY_SUNPRO_VERSION_CHECK
#undef JSON_HEDLEY_TINYC_VERSION
#undef JSON_HEDLEY_TINYC_VERSION_CHECK
#undef JSON_HEDLEY_TI_ARMCL_VERSION
#undef JSON_HEDLEY_TI_ARMCL_VERSION_CHECK
#undef JSON_HEDLEY_TI_CL2000_VERSION
#undef JSON_HEDLEY_TI_CL2000_VERSION_CHECK
#undef JSON_HEDLEY_TI_CL430_VERSION
#undef JSON_HEDLEY_TI_CL430_VERSION_CHECK
#undef JSON_HEDLEY_TI_CL6X_VERSION
#undef JSON_HEDLEY_TI_CL6X_VERSION_CHECK
#undef JSON_HEDLEY_TI_CL7X_VERSION
#undef JSON_HEDLEY_TI_CL7X_VERSION_CHECK
#undef JSON_HEDLEY_TI_CLPRU_VERSION
#undef JSON_HEDLEY_TI_CLPRU_VERSION_CHECK
#undef JSON_HEDLEY_TI_VERSION
#undef JSON_HEDLEY_TI_VERSION_CHECK
#undef JSON_HEDLEY_UNAVAILABLE
#undef JSON_HEDLEY_UNLIKELY
#undef JSON_HEDLEY_UNPREDICTABLE
#undef JSON_HEDLEY_UNREACHABLE
#undef JSON_HEDLEY_UNREACHABLE_RETURN
#undef JSON_HEDLEY_VERSION
#undef JSON_HEDLEY_VERSION_DECODE_MAJOR
#undef JSON_HEDLEY_VERSION_DECODE_MINOR
#undef JSON_HEDLEY_VERSION_DECODE_REVISION
#undef JSON_HEDLEY_VERSION_ENCODE
#undef JSON_HEDLEY_WARNING
#undef JSON_HEDLEY_WARN_UNUSED_RESULT
#undef JSON_HEDLEY_WARN_UNUSED_RESULT_MSG
#undef JSON_HEDLEY_FALL_THROUGH
#ifndef JSON_NO_AUTOMATIC_UDLS
#ifndef INCLUDE_NLOHMANN_JSON_LITERALS_HPP_
#define INCLUDE_NLOHMANN_JSON_LITERALS_HPP_
#include <cstddef> 
#include <string> 
#if !defined(__GNUC__) || defined(__clang__) || __GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 9)
    #define NLOHMANN_JSON_LITERAL_OPERATOR(suffix) operator""##suffix
#else
    #define NLOHMANN_JSON_LITERAL_OPERATOR(suffix) operator"" suffix
#endif
NLOHMANN_JSON_NAMESPACE_BEGIN
inline namespace literals
{
inline namespace json_literals
{
inline nlohmann::json NLOHMANN_JSON_LITERAL_OPERATOR(_json)(const char* s, std::size_t n)
{
    return nlohmann::json::parse(s, s + n);
}
#if defined(__cpp_char8_t)
inline nlohmann::json operator""_json(const char8_t* s, std::size_t n)
{
    return nlohmann::json::parse(reinterpret_cast<const char*>(s),
                                 reinterpret_cast<const char*>(s) + n);
}
#endif
inline nlohmann::json::json_pointer NLOHMANN_JSON_LITERAL_OPERATOR(_json_pointer)(const char* s, std::size_t n)
{
    return nlohmann::json::json_pointer(std::string(s, n));
}
#if defined(__cpp_char8_t)
inline nlohmann::json::json_pointer operator""_json_pointer(const char8_t* s, std::size_t n)
{
    return nlohmann::json::json_pointer(std::string(reinterpret_cast<const char*>(s), n));
}
#endif
}  
}  
NLOHMANN_JSON_NAMESPACE_END
#if !defined(JSON_USE_GLOBAL_UDLS) || JSON_USE_GLOBAL_UDLS
    using nlohmann::literals::json_literals::NLOHMANN_JSON_LITERAL_OPERATOR(_json); 
    using nlohmann::literals::json_literals::NLOHMANN_JSON_LITERAL_OPERATOR(_json_pointer); 
#endif
#undef NLOHMANN_JSON_LITERAL_OPERATOR
#endif  
#endif
#endif  
