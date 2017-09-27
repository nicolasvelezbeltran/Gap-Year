#include "GPUProgram.h"
#include "System.h"
#include <stdio.h>

static
void
InitShaderFromFile(unsigned shaderID, const char* path)
{
    char exePath[MAX_PATH];
    GetModuleFileName(GetModuleHandle(NULL), exePath, MAX_PATH);

    char fullPath[256];
    fullPath[0] = 0;
    strcat_s(fullPath, sizeof(fullPath), exePath);
    strcat_s(fullPath, sizeof(fullPath), "\\..\\..\\");
    strcat_s(fullPath, sizeof(fullPath), path);

    size_t sourceBuffSize = 1024 * 1024;
    char* source = malloc(sourceBuffSize);

    FILE* file = fopen(fullPath, "r");

    if( ! file )
        Sys_Crash("fopen() failed on \"%s\"", fullPath);

    size_t sourceLength = fread(source, 1, sourceBuffSize - 1, file);
    source[sourceLength] = '\0';

    if( ferror(file) )
        Sys_Crash("fread() failed on \"%s\"\n", fullPath);

    fclose(file);

    printf("%s\n", source);

    GLShaderSource(shaderID, 1, &source, NULL);
    GLCompileShader(shaderID);

    int compileSuccess;
    GLGetShaderiv(shaderID, GL_COMPILE_STATUS, &compileSuccess);

    if( ! compileSuccess )
    {
        int infoLogLength;
        GLGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &infoLogLength);

        char* infoLog = malloc(infoLogLength);
        GLGetShaderInfoLog(shaderID, infoLogLength, NULL, infoLog);

        Sys_Crash(
            "Failed to compile shader\n"
            "\n"
            "Source File: \"%s\"\n"
            "\n"
            "===[ ERROR LOG ]===\n"
            "\n"
            "%s\n",
            path,
            infoLog);
    }
}

GPUProgram*
GPUProgram_New(
    const char* vertexShaderPath,
    const char* fragmentShaderPath)
{
    GPUProgram* prog = malloc(sizeof(GPUProgram));

    prog->programID = GLCreateProgram();

    prog->vertexShaderID = GLCreateShader(GL_VERTEX_SHADER);
    prog->fragmentShaderID = GLCreateShader(GL_FRAGMENT_SHADER);

    InitShaderFromFile(prog->vertexShaderID, vertexShaderPath);
    InitShaderFromFile(prog->fragmentShaderID, fragmentShaderPath);

    return prog;
}
