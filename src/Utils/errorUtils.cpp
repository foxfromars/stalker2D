#include <iostream>
#include <string>

namespace EngineUtils {
class Error {
public:
  std::string message;
  int code;
  void consoleMessage() {
    std::cout << "Debug Error: " << message << std::endl;
  };

  Error(std::string p_message, int p_code) {
    message = p_message;
    code = p_code;
  };
};

void throwError(std::string message, int code) {
  Error error = Error(message, code);
  error.consoleMessage();
  throw error;
};

void throwError(Error error) { 
  error.consoleMessage();
  throw error;
} 
}; // namespace EngineUtils
