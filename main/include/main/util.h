#ifndef UTIL_H
#define UTIL_H

#include <fmt/core.h>
#include <string>
#include <string_view>

class Util {
public:
  static void printToolchainInfo() {
    auto [name, version] = getCompilerInfo();
    fmt::println("Compiler: {}", name);
    fmt::println("Compiler Version: {}", version);
    fmt::println("C++ Standard: {}", __cplusplus);
  }

private:
  struct CompilerInfo {
    std::string_view name;
    std::string version;
  };

  static constexpr auto getCompilerInfo() -> CompilerInfo {
#if defined(__clang__)
    return CompilerInfo{.name = "Clang", .version = __clang_version__};
#elif defined(__GNUC__) || defined(__GNUG__)
    return CompilerInfo{.name = "GCC", .version = __VERSION__};
#elif defined(_MSC_VER)
    return CompilerInfo{.name = "MSVC", .version = std::to_string(_MSC_VER)};
#else
    return CompilerInfo{.name = "Unknown", .version = "Unknown"};
#endif
  }
};

#endif // UTIL_H
