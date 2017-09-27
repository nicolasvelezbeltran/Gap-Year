#include "Core.h"
#include "OpenGL.h"

void
Core_RenderFrame(void)
{
    GLClearColor(0.0, 1.0, 0.0, 1.0);
    GLClear(GL_COLOR_BUFFER_BIT);
}
