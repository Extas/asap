#ifndef UTIL_H
#define UTIL_H

#include <string_view>
#include <fmt/core.h>

class Util {
public:
  static void printToolchainInfo() {
    fmt::println("Compiler: {}", getCompilerName());
    fmt::println("Compiler Version: {}", getCompilerVersion());
    fmt::println("C++ Standard: {}", getCppStandard());
  }

private:
  static constexpr std::string_view getCompilerName() {
#if defined(__clang__)
    return "Clang";
#elif defined(__GNUC__) || defined(__GNUG__)
    return "GCC";
#elif defined(_MSC_VER)
    return "MSVC";
#else
    return "Unknown";
#endif
  }

  static constexpr std::string_view getCompilerVersion() {
#if defined(__clang__)
    return std::string_view{__clang_version__};
#elif defined(__GNUC__) || defined(__GNUG__)
    return std::string_view{__VERSION__};
#elif defined(_MSC_VER)
    return std::to_string(_MSC_VER);
#else
    return "Unknown";
#endif
  }

  static constexpr std::string_view getCppStandard() {
    if constexpr (__cplusplus == 202002L) {
      return "C++20";
    } else if constexpr (__cplusplus == 202300L) {
      return "C++23";
    } else {
      return "pre-C++20";
    }
  }
};

#endif // UTIL_H
