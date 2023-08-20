#include "../../include/Systems/fontSystem.h"

using namespace EngineSystems;

FontSystem::FontSystem(RenderHelper *renderHelperPointer) {
  renderHelper = renderHelperPointer;
};

void FontSystem::renderText(Text *text) {
  SDL_RenderCopy(renderHelper->getRenderer(), text->getTexture(),
                 text->getCurrentFrame(), text->getCurrentFrame());
};

FontSystem::~FontSystem(){

};
