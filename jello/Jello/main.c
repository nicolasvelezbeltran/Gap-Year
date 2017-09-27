#include "Core.h"
#include "System.h"
#include "OpenGL.h"
#include "GPUProgram.h"

#include <windows.h>
#include <windowsx.h>

#include <stdbool.h>
#include <stdio.h>

void
ProcessAvailableMessages(void)
{
    while(true)
    {
        MSG msg;
        BOOL messageAvailable = PeekMessage(&msg, NULL, 0, 0, PM_REMOVE);

        if( ! messageAvailable )
            break;

        TranslateMessage(&msg);
        DispatchMessage(&msg);

        if( msg.message == WM_QUIT )
            exit(1);
    }
}

int
CALLBACK
WinMain(
    HINSTANCE appInstance,
    HINSTANCE prevAppInstance,
    LPSTR     commandLien,
    int       showCommand)
{
    Sys_WindowTitle = "Jello Simulation";

    Sys_OpenConsole();
    Sys_Init();
    Sys_TileWindows();

    GL_Init();
    WGLSwapIntervalEXT(1);

    GL_PrintRendererInfo();

    GPUProgram* prog = GPUProgram_New(
        "Jello\\basic.vs",
        "Jello\\basic.fs");

    while(true)
    {
        ProcessAvailableMessages();
        Core_RenderFrame();
        SwapBuffers(Sys_MainDeviceContext);
    }

    return 0;
}
