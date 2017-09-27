#ifndef SYSTEM_H
#define SYSTEM_H

#include <windows.h>
#include <windowsx.h>

#include "OpenGL.h"

extern HMODULE     Sys_OpenGL32DLL;
extern HWND        Sys_MainWindow;
extern HDC         Sys_MainDeviceContext;
extern HGLRC       Sys_MainOpenGLContext;
extern const char* Sys_WindowTitle;

void Sys_Init(void);
void Sys_OpenConsole(void);
void Sys_LoadGLProc(void** proc, int major, int minor, const char* name);
void Sys_TileWindows(void);
void Sys_Crash(const char* format, ...);

#endif
