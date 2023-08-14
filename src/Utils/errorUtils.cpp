#include "../../include/Utils/errorUtils.h"
using namespace EngineUtils;

void Error::consoleMessage() {
  std::cout << "Debug Error: " << message << std::endl;
};

Error::Error(const char *p_message, int p_code) {
  message = p_message;
  code = p_code;
};

void throwError(const char *message, int code) {
  Error error = Error(message, code);
  error.consoleMessage();
  throw error;
};
