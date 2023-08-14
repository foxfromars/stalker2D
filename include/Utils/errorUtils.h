#pragma once
#include <iostream>
#include <string>

namespace EngineUtils {
class Error {
public:
  const char *message;
  int code;
  void consoleMessage();
  Error(const char *p_message, int p_code);
};

void throwError(const char *message, int code);
}; // namespace EngineUtils
