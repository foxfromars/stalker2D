#include "../Entities/text.h"
#include "../Helpers/render.h"
#include <SDL2/SDL.h>
#include "../Utils/errorUtils.h"

namespace EngineSystems {
class FontSystem {
private:
  RenderHelper *renderHelper;

public:
  FontSystem(RenderHelper *renderHelperPointer);
  ~FontSystem();
  void renderText(Text *text);
  void changeTextPosition(Text *text);
  void changeTextSize(Text *text);
  void changeTextContent(Text *text);
};

} // namespace EngineSystems
