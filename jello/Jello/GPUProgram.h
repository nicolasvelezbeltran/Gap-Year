#ifndef GPUPROGRAM_H
#define GPUPROGRAM_H

#include "OpenGL.h"

struct GPUProgram
{
    unsigned programID;
    unsigned vertexShaderID;
    unsigned fragmentShaderID;
};

typedef struct GPUProgram GPUProgram;

GPUProgram*
GPUProgram_New(
    const char* vertexShaderPath,
    const char* fragmentShaderPath);

#endif
