#include "System.h"

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

HMODULE     Sys_OpenGL32DLL;
HWND        Sys_MainWindow;
HDC         Sys_MainDeviceContext;
HGLRC       Sys_MainOpenGLContext;
const char* Sys_WindowTitle;

static HWND DummyWindow;

static
LRESULT
CALLBACK
WindowProc(
    HWND hwnd, 
    UINT msg,
    WPARAM wparam,
    LPARAM lparam)
{
    if(msg == WM_DESTROY)
    {
        PostQuitMessage(0);
        return 0;
    }
    else if(msg == WM_MOUSEMOVE)
    {
        // int x = GET_X_LPARAM(lparam);
        // int y = GET_Y_LPARAM(lparam);
        // printf("You moved the mouse! %d %d\n", x, y);
        return 0;
    }
    else
    {
        return DefWindowProc(hwnd, msg, wparam, lparam);
    }
}

static
void
CreateDummyWindow(void)
{
    WNDCLASS dummyWindowClass;
    memset(&dummyWindowClass, 0, sizeof(WNDCLASS));

    dummyWindowClass.lpfnWndProc   = DefWindowProc;
    dummyWindowClass.hInstance     = GetModuleHandle(NULL);
    dummyWindowClass.lpszClassName = "DummyWindowClass";

    if( ! RegisterClass(&dummyWindowClass) )
    {
        MessageBox(
            NULL,
            "RegisterClass() failed!",
            "ERROR",
            MB_ICONERROR);

        exit(1);
    }

    DummyWindow = CreateWindowEx(
        WS_EX_OVERLAPPEDWINDOW,
        "DummyWindowClass",
        "Dummy Window",
        WS_OVERLAPPEDWINDOW | CS_OWNDC,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        NULL,
        NULL,
        GetModuleHandle(NULL),
        NULL);

    if( DummyWindow == NULL )
    {
        MessageBox(
            NULL,
            "CreateWindowEx() failed!",
            "ERROR",
            MB_ICONERROR);

        exit(1);
    }

    PIXELFORMATDESCRIPTOR pfd;
    memset(&pfd, 0, sizeof(PIXELFORMATDESCRIPTOR));

    pfd.cColorBits   = 32;
    pfd.cRedBits     = 8;
    pfd.cGreenBits   = 8;
    pfd.cBlueBits    = 8;
    pfd.cAlphaBits   = 8;
    pfd.cDepthBits   = 24;
    pfd.cStencilBits = 8;
    pfd.iLayerType   = PFD_MAIN_PLANE;

    HDC dummyHDC = GetDC(DummyWindow);

    int format = ChoosePixelFormat(dummyHDC, &pfd);
    SetPixelFormat(dummyHDC, format, &pfd);

    HGLRC dummyHGLRC = wglCreateContext(dummyHDC);
    wglMakeCurrent(dummyHDC, dummyHGLRC);
}

static
void
CreateMainWindow(void)
{
    WNDCLASS wc;
    memset(&wc, 0, sizeof(WNDCLASS));

    wc.lpfnWndProc    = WindowProc;
    wc.hInstance      = GetModuleHandle(NULL);
    wc.lpszClassName  = "MainWindowClass";
    wc.hIcon          = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor        = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground  = (HBRUSH)GetStockObject(WHITE_BRUSH);

    if( ! RegisterClass(&wc) )
    {
        MessageBox(
            NULL,
            "RegisterClass() failed!",
            "ERROR",
            MB_ICONERROR);

        exit(1);
    }

    Sys_MainWindow = CreateWindowEx(
        WS_EX_OVERLAPPEDWINDOW,
        "MainWindowClass",
        Sys_WindowTitle ? Sys_WindowTitle : "Main Window""Jello Simulation",
        WS_OVERLAPPEDWINDOW | CS_OWNDC,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        NULL,
        NULL,
        GetModuleHandle(NULL),
        NULL);

    if( Sys_MainWindow == NULL )
    {
        MessageBox(
            NULL,
            "CreateWindowEx() failed!",
            "ERROR",
            MB_ICONERROR);

        exit(1);
    }

    Sys_MainDeviceContext = GetDC(Sys_MainWindow);

    const int pixelFormatAttribs[] =
    {
        WGL_DRAW_TO_WINDOW_ARB, GL_TRUE,
        WGL_SUPPORT_OPENGL_ARB, GL_TRUE,
        WGL_DOUBLE_BUFFER_ARB,  GL_TRUE,
        WGL_PIXEL_TYPE_ARB,     WGL_TYPE_RGBA_ARB,
        WGL_COLOR_BITS_ARB,     32,
        WGL_DEPTH_BITS_ARB,     24,
        WGL_STENCIL_BITS_ARB,   8,
        0, 0
    };

    int pixelFormat;
    UINT numFormats;

    PFNWGLCHOOSEPIXELFORMATARBPROC pfnWGLChoosePixelFormatARB;
    Sys_LoadGLProc(
        (void**)&pfnWGLChoosePixelFormatARB,
        0, 0, "wglChoosePixelFormatARB");

    pfnWGLChoosePixelFormatARB(
        Sys_MainDeviceContext,
        pixelFormatAttribs,
        NULL,
        1,
        &pixelFormat,
        &numFormats);

    SetPixelFormat(Sys_MainDeviceContext, pixelFormat, NULL);

    const int contextAttribs[] =
    {
        WGL_CONTEXT_MAJOR_VERSION_ARB, 4,
        WGL_CONTEXT_MINOR_VERSION_ARB, 1,
        WGL_CONTEXT_PROFILE_MASK_ARB,  WGL_CONTEXT_CORE_PROFILE_BIT_ARB,
        0, 0
    };

    PFNWGLCREATECONTEXTATTRIBSARBPROC pfnWGLCreateContextAttribsARB;
    Sys_LoadGLProc(
        (void**)&pfnWGLCreateContextAttribsARB,
        0, 0, "wglCreateContextAttribsARB");

    Sys_MainOpenGLContext = pfnWGLCreateContextAttribsARB(
        Sys_MainDeviceContext,
        NULL,
        contextAttribs);

    wglMakeCurrent(
        Sys_MainDeviceContext,
        Sys_MainOpenGLContext);

    ShowWindow(Sys_MainWindow, SW_SHOW);
}

void
Sys_Init(void)
{
    Sys_OpenGL32DLL = LoadLibrary("opengl32.dll");

    CreateDummyWindow();
    CreateMainWindow();
    DestroyWindow(DummyWindow);
}

void
Sys_OpenConsole(void)
{
    AllocConsole();

    freopen("CONIN$", "r", stdin);
    freopen("CONOUT$", "w", stdout);
    freopen("CONOUT$", "w", stderr);
}

void
Sys_LoadGLProc(void** proc, int major, int minor, const char* name)
{
    bool isWGLExt = (major == 0 && minor == 0);
    bool isOldOpenGL = (major < 1 || (major == 1 && minor <= 1));

    if( isWGLExt )
        *proc = (void*)wglGetProcAddress(name);
    else if( isOldOpenGL )
        *proc = (void*)GetProcAddress(Sys_OpenGL32DLL, name);
    else
        *proc = (void*)wglGetProcAddress(name);
}

void
Sys_Crash(const char* format, ...)
{
    va_list ap;

    va_start(ap, format);
    int msgLength = 1 + vsnprintf(NULL, 0, format, ap);
    va_end(ap);

    char* msg = malloc(msgLength);

    va_start(ap, format);
    vsnprintf(msg, msgLength, format, ap);
    va_end(ap);

    MessageBox(NULL, msg, "ERROR", MB_ICONERROR);
    exit(1);
}

void
Sys_TileWindows(void)
{
    RECT r;
    GetWindowRect(GetDesktopWindow(), &r);

    LONG DesktopWidth = r.right - r.left;
    LONG DesktopHeight = r.bottom - r.top;

    LONG DesktopDimen =
        DesktopWidth < DesktopHeight ? DesktopWidth : DesktopHeight;

    LONG TotalWidth  = (LONG)(DesktopDimen * 0.8);
    LONG TotalHeight = (LONG)(DesktopDimen * 0.8);

    LONG WinWidth = TotalWidth;
    LONG WinHeight = (LONG)(TotalHeight * 0.618);
    LONG WinX = DesktopWidth / 2 - TotalWidth / 2;
    LONG WinY = (LONG)((DesktopHeight - TotalHeight) * (1 - 0.618));

    LONG ConWidth = TotalWidth;
    LONG ConHeight = TotalHeight - WinHeight;
    LONG ConX = WinX;
    LONG ConY = WinY + WinHeight;

    MoveWindow(
        Sys_MainWindow,
        WinX,
        WinY,
        WinWidth,
        WinHeight,
        TRUE);

    if( GetConsoleWindow() )
    {
        MoveWindow(
            GetConsoleWindow(),
            ConX,
            ConY,
            ConWidth,
            ConHeight,
            TRUE);
    }
}
