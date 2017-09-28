#include "OpenGL.h"
#include "System.h"
#include <stdio.h>

void
GL_PrintRendererInfo(void)
{
    printf(
        "OpenGL Renderer: %s\n",
        (const char*)GLGetString(GL_RENDERER));

    printf(
        "OpenGL Vendor:   %s\n",
        (const char*)GLGetString(GL_VENDOR));

    printf(
        "OpenGL Version:  %s\n",
        (const char*)GLGetString(GL_VERSION));

    printf(
        "GLSL Version:    %s\n",
        (const char*)GLGetString(GL_SHADING_LANGUAGE_VERSION));

    printf("\n");
}

void
GL_PrintExtensionInfo(void)
{
    int numExtensions;
    GLGetIntegerv(GL_NUM_EXTENSIONS, &numExtensions);

    printf("There are %d OpenGL extensions available\n", numExtensions);
    printf("\n");

    for(int i = 0; i < numExtensions; i++)
    {
        const char* extName = (const char*)GLGetStringi(GL_EXTENSIONS, i);
        printf("%s\n", extName);
    }

    printf("\n");
}

void
GL_Init(void)
{
    // ==========
    // Windows WGL
    // ==========

    Sys_LoadGLProc((void**)&WGLCreateContextAttribsARB, 0, 0, "wglCreateContextAttribsARB");
    Sys_LoadGLProc((void**)&WGLChoosePixelFormatARB, 0, 0, "wglChoosePixelFormatARB");
    Sys_LoadGLProc((void**)&WGLSwapIntervalEXT, 0, 0, "wglSwapIntervalEXT");

    // ==========
    // OpenGL 1.0
    // ==========

    Sys_LoadGLProc((void**)&GLCullFace, 1, 0, "glCullFace");
    Sys_LoadGLProc((void**)&GLFrontFace, 1, 0, "glFrontFace");
    Sys_LoadGLProc((void**)&GLHint, 1, 0, "glHint");
    Sys_LoadGLProc((void**)&GLLineWidth, 1, 0, "glLineWidth");
    Sys_LoadGLProc((void**)&GLPointSize, 1, 0, "glPointSize");
    Sys_LoadGLProc((void**)&GLPolygonMode, 1, 0, "glPolygonMode");
    Sys_LoadGLProc((void**)&GLScissor, 1, 0, "glScissor");
    Sys_LoadGLProc((void**)&GLTexParameterf, 1, 0, "glTexParameterf");
    Sys_LoadGLProc((void**)&GLTexParameterfv, 1, 0, "glTexParameterfv");
    Sys_LoadGLProc((void**)&GLTexParameteri, 1, 0, "glTexParameteri");
    Sys_LoadGLProc((void**)&GLTexParameteriv, 1, 0, "glTexParameteriv");
    Sys_LoadGLProc((void**)&GLTexImage1D, 1, 0, "glTexImage1D");
    Sys_LoadGLProc((void**)&GLTexImage2D, 1, 0, "glTexImage2D");
    Sys_LoadGLProc((void**)&GLDrawBuffer, 1, 0, "glDrawBuffer");
    Sys_LoadGLProc((void**)&GLClear, 1, 0, "glClear");
    Sys_LoadGLProc((void**)&GLClearColor, 1, 0, "glClearColor");
    Sys_LoadGLProc((void**)&GLClearStencil, 1, 0, "glClearStencil");
    Sys_LoadGLProc((void**)&GLClearDepth, 1, 0, "glClearDepth");
    Sys_LoadGLProc((void**)&GLStencilMask, 1, 0, "glStencilMask");
    Sys_LoadGLProc((void**)&GLColorMask, 1, 0, "glColorMask");
    Sys_LoadGLProc((void**)&GLDepthMask, 1, 0, "glDepthMask");
    Sys_LoadGLProc((void**)&GLDisable, 1, 0, "glDisable");
    Sys_LoadGLProc((void**)&GLEnable, 1, 0, "glEnable");
    Sys_LoadGLProc((void**)&GLFinish, 1, 0, "glFinish");
    Sys_LoadGLProc((void**)&GLFlush, 1, 0, "glFlush");
    Sys_LoadGLProc((void**)&GLBlendFunc, 1, 0, "glBlendFunc");
    Sys_LoadGLProc((void**)&GLLogicOp, 1, 0, "glLogicOp");
    Sys_LoadGLProc((void**)&GLStencilFunc, 1, 0, "glStencilFunc");
    Sys_LoadGLProc((void**)&GLStencilOp, 1, 0, "glStencilOp");
    Sys_LoadGLProc((void**)&GLDepthFunc, 1, 0, "glDepthFunc");
    Sys_LoadGLProc((void**)&GLPixelStoref, 1, 0, "glPixelStoref");
    Sys_LoadGLProc((void**)&GLPixelStorei, 1, 0, "glPixelStorei");
    Sys_LoadGLProc((void**)&GLReadBuffer, 1, 0, "glReadBuffer");
    Sys_LoadGLProc((void**)&GLReadPixels, 1, 0, "glReadPixels");
    Sys_LoadGLProc((void**)&GLGetBooleanv, 1, 0, "glGetBooleanv");
    Sys_LoadGLProc((void**)&GLGetDoublev, 1, 0, "glGetDoublev");
    Sys_LoadGLProc((void**)&GLGetError, 1, 0, "glGetError");
    Sys_LoadGLProc((void**)&GLGetFloatv, 1, 0, "glGetFloatv");
    Sys_LoadGLProc((void**)&GLGetIntegerv, 1, 0, "glGetIntegerv");
    Sys_LoadGLProc((void**)&GLGetString, 1, 0, "glGetString");
    Sys_LoadGLProc((void**)&GLGetTexImage, 1, 0, "glGetTexImage");
    Sys_LoadGLProc((void**)&GLGetTexParameterfv, 1, 0, "glGetTexParameterfv");
    Sys_LoadGLProc((void**)&GLGetTexParameteriv, 1, 0, "glGetTexParameteriv");
    Sys_LoadGLProc((void**)&GLGetTexLevelParameterfv, 1, 0, "glGetTexLevelParameterfv");
    Sys_LoadGLProc((void**)&GLGetTexLevelParameteriv, 1, 0, "glGetTexLevelParameteriv");
    Sys_LoadGLProc((void**)&GLIsEnabled, 1, 0, "glIsEnabled");
    Sys_LoadGLProc((void**)&GLDepthRange, 1, 0, "glDepthRange");
    Sys_LoadGLProc((void**)&GLViewport, 1, 0, "glViewport");
    
    // ==========
    // OpenGL 1.1
    // ==========

    Sys_LoadGLProc((void**)&GLDrawArrays, 1, 1, "glDrawArrays");
    Sys_LoadGLProc((void**)&GLDrawElements, 1, 1, "glDrawElements");
    Sys_LoadGLProc((void**)&GLGetPointerv, 1, 1, "glGetPointerv");
    Sys_LoadGLProc((void**)&GLPolygonOffset, 1, 1, "glPolygonOffset");
    Sys_LoadGLProc((void**)&GLCopyTexImage1D, 1, 1, "glCopyTexImage1D");
    Sys_LoadGLProc((void**)&GLCopyTexImage2D, 1, 1, "glCopyTexImage2D");
    Sys_LoadGLProc((void**)&GLCopyTexSubImage1D, 1, 1, "glCopyTexSubImage1D");
    Sys_LoadGLProc((void**)&GLCopyTexSubImage2D, 1, 1, "glCopyTexSubImage2D");
    Sys_LoadGLProc((void**)&GLTexSubImage1D, 1, 1, "glTexSubImage1D");
    Sys_LoadGLProc((void**)&GLTexSubImage2D, 1, 1, "glTexSubImage2D");
    Sys_LoadGLProc((void**)&GLBindTexture, 1, 1, "glBindTexture");
    Sys_LoadGLProc((void**)&GLDeleteTextures, 1, 1, "glDeleteTextures");
    Sys_LoadGLProc((void**)&GLGenTextures, 1, 1, "glGenTextures");
    Sys_LoadGLProc((void**)&GLIsTexture, 1, 1, "glIsTexture");
    
    // ==========
    // OpenGL 1.2
    // ==========

    Sys_LoadGLProc((void**)&GLDrawRangeElements, 1, 2, "glDrawRangeElements");
    Sys_LoadGLProc((void**)&GLTexImage3D, 1, 2, "glTexImage3D");
    Sys_LoadGLProc((void**)&GLTexSubImage3D, 1, 2, "glTexSubImage3D");
    Sys_LoadGLProc((void**)&GLCopyTexSubImage3D, 1, 2, "glCopyTexSubImage3D");
    
    // ==========
    // OpenGL 1.3
    // ==========
    
    Sys_LoadGLProc((void**)&GLActiveTexture, 1, 3, "glActiveTexture");
    Sys_LoadGLProc((void**)&GLSampleCoverage, 1, 3, "glSampleCoverage");
    Sys_LoadGLProc((void**)&GLCompressedTexImage3D, 1, 3, "glCompressedTexImage3D");
    Sys_LoadGLProc((void**)&GLCompressedTexImage2D, 1, 3, "glCompressedTexImage2D");
    Sys_LoadGLProc((void**)&GLCompressedTexImage1D, 1, 3, "glCompressedTexImage1D");
    Sys_LoadGLProc((void**)&GLCompressedTexSubImage3D, 1, 3, "glCompressedTexSubImage3D");
    Sys_LoadGLProc((void**)&GLCompressedTexSubImage2D, 1, 3, "glCompressedTexSubImage2D");
    Sys_LoadGLProc((void**)&GLCompressedTexSubImage1D, 1, 3, "glCompressedTexSubImage1D");
    Sys_LoadGLProc((void**)&GLGetCompressedTexImage, 1, 3, "glGetCompressedTexImage");

    // ==========
    // OpenGL 1.4
    // ==========

    Sys_LoadGLProc((void**)&GLBlendFuncSeparate, 1, 4, "glBlendFuncSeparate");
    Sys_LoadGLProc((void**)&GLMultiDrawArrays, 1, 4, "glMultiDrawArrays");
    Sys_LoadGLProc((void**)&GLMultiDrawElements, 1, 4, "glMultiDrawElements");
    Sys_LoadGLProc((void**)&GLPointParameterf, 1, 4, "glPointParameterf");
    Sys_LoadGLProc((void**)&GLPointParameterfv, 1, 4, "glPointParameterfv");
    Sys_LoadGLProc((void**)&GLPointParameteri, 1, 4, "glPointParameteri");
    Sys_LoadGLProc((void**)&GLPointParameteriv, 1, 4, "glPointParameteriv");
    Sys_LoadGLProc((void**)&GLBlendColor, 1, 4, "glBlendColor");
    Sys_LoadGLProc((void**)&GLBlendEquation, 1, 4, "glBlendEquation");
    
    // ==========
    // OpenGL 1.5
    // ==========

    Sys_LoadGLProc((void**)&GLGenQueries, 1, 5, "glGenQueries");
    Sys_LoadGLProc((void**)&GLDeleteQueries, 1, 5, "glDeleteQueries");
    Sys_LoadGLProc((void**)&GLIsQuery, 1, 5, "glIsQuery");
    Sys_LoadGLProc((void**)&GLBeginQuery, 1, 5, "glBeginQuery");
    Sys_LoadGLProc((void**)&GLEndQuery, 1, 5, "glEndQuery");
    Sys_LoadGLProc((void**)&GLGetQueryiv, 1, 5, "glGetQueryiv");
    Sys_LoadGLProc((void**)&GLGetQueryObjectiv, 1, 5, "glGetQueryObjectiv");
    Sys_LoadGLProc((void**)&GLGetQueryObjectuiv, 1, 5, "glGetQueryObjectuiv");
    Sys_LoadGLProc((void**)&GLBindBuffer, 1, 5, "glBindBuffer");
    Sys_LoadGLProc((void**)&GLDeleteBuffers, 1, 5, "glDeleteBuffers");
    Sys_LoadGLProc((void**)&GLGenBuffers, 1, 5, "glGenBuffers");
    Sys_LoadGLProc((void**)&GLIsBuffer, 1, 5, "glIsBuffer");
    Sys_LoadGLProc((void**)&GLBufferData, 1, 5, "glBufferData");
    Sys_LoadGLProc((void**)&GLBufferSubData, 1, 5, "glBufferSubData");
    Sys_LoadGLProc((void**)&GLGetBufferSubData, 1, 5, "glGetBufferSubData");
    Sys_LoadGLProc((void**)&GLMapBuffer, 1, 5, "glMapBuffer");
    Sys_LoadGLProc((void**)&GLUnmapBuffer, 1, 5, "glUnmapBuffer");
    Sys_LoadGLProc((void**)&GLGetBufferParameteriv, 1, 5, "glGetBufferParameteriv");
    Sys_LoadGLProc((void**)&GLGetBufferPointerv, 1, 5, "glGetBufferPointerv");
    
    // ==========
    // OpenGL 2.0
    // ==========

    Sys_LoadGLProc((void**)&GLBlendEquationSeparate, 2, 0, "glBlendEquationSeparate");
    Sys_LoadGLProc((void**)&GLDrawBuffers, 2, 0, "glDrawBuffers");
    Sys_LoadGLProc((void**)&GLStencilOpSeparate, 2, 0, "glStencilOpSeparate");
    Sys_LoadGLProc((void**)&GLStencilFuncSeparate, 2, 0, "glStencilFuncSeparate");
    Sys_LoadGLProc((void**)&GLStencilMaskSeparate, 2, 0, "glStencilMaskSeparate");
    Sys_LoadGLProc((void**)&GLAttachShader, 2, 0, "glAttachShader");
    Sys_LoadGLProc((void**)&GLBindAttribLocation, 2, 0, "glBindAttribLocation");
    Sys_LoadGLProc((void**)&GLCompileShader, 2, 0, "glCompileShader");
    Sys_LoadGLProc((void**)&GLCreateProgram, 2, 0, "glCreateProgram");
    Sys_LoadGLProc((void**)&GLCreateShader, 2, 0, "glCreateShader");
    Sys_LoadGLProc((void**)&GLDeleteProgram, 2, 0, "glDeleteProgram");
    Sys_LoadGLProc((void**)&GLDeleteShader, 2, 0, "glDeleteShader");
    Sys_LoadGLProc((void**)&GLDetachShader, 2, 0, "glDetachShader");
    Sys_LoadGLProc((void**)&GLDisableVertexAttribArray, 2, 0, "glDisableVertexAttribArray");
    Sys_LoadGLProc((void**)&GLEnableVertexAttribArray, 2, 0, "glEnableVertexAttribArray");
    Sys_LoadGLProc((void**)&GLGetActiveAttrib, 2, 0, "glGetActiveAttrib");
    Sys_LoadGLProc((void**)&GLGetActiveUniform, 2, 0, "glGetActiveUniform");
    Sys_LoadGLProc((void**)&GLGetAttachedShaders, 2, 0, "glGetAttachedShaders");
    Sys_LoadGLProc((void**)&GLGetAttribLocation, 2, 0, "glGetAttribLocation");
    Sys_LoadGLProc((void**)&GLGetProgramiv, 2, 0, "glGetProgramiv");
    Sys_LoadGLProc((void**)&GLGetProgramInfoLog, 2, 0, "glGetProgramInfoLog");
    Sys_LoadGLProc((void**)&GLGetShaderiv, 2, 0, "glGetShaderiv");
    Sys_LoadGLProc((void**)&GLGetShaderInfoLog, 2, 0, "glGetShaderInfoLog");
    Sys_LoadGLProc((void**)&GLGetShaderSource, 2, 0, "glGetShaderSource");
    Sys_LoadGLProc((void**)&GLGetUniformLocation, 2, 0, "glGetUniformLocation");
    Sys_LoadGLProc((void**)&GLGetUniformfv, 2, 0, "glGetUniformfv");
    Sys_LoadGLProc((void**)&GLGetUniformiv, 2, 0, "glGetUniformiv");
    Sys_LoadGLProc((void**)&GLGetVertexAttribdv, 2, 0, "glGetVertexAttribdv");
    Sys_LoadGLProc((void**)&GLGetVertexAttribfv, 2, 0, "glGetVertexAttribfv");
    Sys_LoadGLProc((void**)&GLGetVertexAttribiv, 2, 0, "glGetVertexAttribiv");
    Sys_LoadGLProc((void**)&GLGetVertexAttribPointerv, 2, 0, "glGetVertexAttribPointerv");
    Sys_LoadGLProc((void**)&GLIsProgram, 2, 0, "glIsProgram");
    Sys_LoadGLProc((void**)&GLIsShader, 2, 0, "glIsShader");
    Sys_LoadGLProc((void**)&GLLinkProgram, 2, 0, "glLinkProgram");
    Sys_LoadGLProc((void**)&GLShaderSource, 2, 0, "glShaderSource");
    Sys_LoadGLProc((void**)&GLUseProgram, 2, 0, "glUseProgram");
    Sys_LoadGLProc((void**)&GLUniform1f, 2, 0, "glUniform1f");
    Sys_LoadGLProc((void**)&GLUniform2f, 2, 0, "glUniform2f");
    Sys_LoadGLProc((void**)&GLUniform3f, 2, 0, "glUniform3f");
    Sys_LoadGLProc((void**)&GLUniform4f, 2, 0, "glUniform4f");
    Sys_LoadGLProc((void**)&GLUniform1i, 2, 0, "glUniform1i");
    Sys_LoadGLProc((void**)&GLUniform2i, 2, 0, "glUniform2i");
    Sys_LoadGLProc((void**)&GLUniform3i, 2, 0, "glUniform3i");
    Sys_LoadGLProc((void**)&GLUniform4i, 2, 0, "glUniform4i");
    Sys_LoadGLProc((void**)&GLUniform1fv, 2, 0, "glUniform1fv");
    Sys_LoadGLProc((void**)&GLUniform2fv, 2, 0, "glUniform2fv");
    Sys_LoadGLProc((void**)&GLUniform3fv, 2, 0, "glUniform3fv");
    Sys_LoadGLProc((void**)&GLUniform4fv, 2, 0, "glUniform4fv");
    Sys_LoadGLProc((void**)&GLUniform1iv, 2, 0, "glUniform1iv");
    Sys_LoadGLProc((void**)&GLUniform2iv, 2, 0, "glUniform2iv");
    Sys_LoadGLProc((void**)&GLUniform3iv, 2, 0, "glUniform3iv");
    Sys_LoadGLProc((void**)&GLUniform4iv, 2, 0, "glUniform4iv");
    Sys_LoadGLProc((void**)&GLUniformMatrix2fv, 2, 0, "glUniformMatrix2fv");
    Sys_LoadGLProc((void**)&GLUniformMatrix3fv, 2, 0, "glUniformMatrix3fv");
    Sys_LoadGLProc((void**)&GLUniformMatrix4fv, 2, 0, "glUniformMatrix4fv");
    Sys_LoadGLProc((void**)&GLValidateProgram, 2, 0, "glValidateProgram");
    Sys_LoadGLProc((void**)&GLVertexAttrib1d, 2, 0, "glVertexAttrib1d");
    Sys_LoadGLProc((void**)&GLVertexAttrib1dv, 2, 0, "glVertexAttrib1dv");
    Sys_LoadGLProc((void**)&GLVertexAttrib1f, 2, 0, "glVertexAttrib1f");
    Sys_LoadGLProc((void**)&GLVertexAttrib1fv, 2, 0, "glVertexAttrib1fv");
    Sys_LoadGLProc((void**)&GLVertexAttrib1s, 2, 0, "glVertexAttrib1s");
    Sys_LoadGLProc((void**)&GLVertexAttrib1sv, 2, 0, "glVertexAttrib1sv");
    Sys_LoadGLProc((void**)&GLVertexAttrib2d, 2, 0, "glVertexAttrib2d");
    Sys_LoadGLProc((void**)&GLVertexAttrib2dv, 2, 0, "glVertexAttrib2dv");
    Sys_LoadGLProc((void**)&GLVertexAttrib2f, 2, 0, "glVertexAttrib2f");
    Sys_LoadGLProc((void**)&GLVertexAttrib2fv, 2, 0, "glVertexAttrib2fv");
    Sys_LoadGLProc((void**)&GLVertexAttrib2s, 2, 0, "glVertexAttrib2s");
    Sys_LoadGLProc((void**)&GLVertexAttrib2sv, 2, 0, "glVertexAttrib2sv");
    Sys_LoadGLProc((void**)&GLVertexAttrib3d, 2, 0, "glVertexAttrib3d");
    Sys_LoadGLProc((void**)&GLVertexAttrib3dv, 2, 0, "glVertexAttrib3dv");
    Sys_LoadGLProc((void**)&GLVertexAttrib3f, 2, 0, "glVertexAttrib3f");
    Sys_LoadGLProc((void**)&GLVertexAttrib3fv, 2, 0, "glVertexAttrib3fv");
    Sys_LoadGLProc((void**)&GLVertexAttrib3s, 2, 0, "glVertexAttrib3s");
    Sys_LoadGLProc((void**)&GLVertexAttrib3sv, 2, 0, "glVertexAttrib3sv");
    Sys_LoadGLProc((void**)&GLVertexAttrib4Nbv, 2, 0, "glVertexAttrib4Nbv");
    Sys_LoadGLProc((void**)&GLVertexAttrib4Niv, 2, 0, "glVertexAttrib4Niv");
    Sys_LoadGLProc((void**)&GLVertexAttrib4Nsv, 2, 0, "glVertexAttrib4Nsv");
    Sys_LoadGLProc((void**)&GLVertexAttrib4Nub, 2, 0, "glVertexAttrib4Nub");
    Sys_LoadGLProc((void**)&GLVertexAttrib4Nubv, 2, 0, "glVertexAttrib4Nubv");
    Sys_LoadGLProc((void**)&GLVertexAttrib4Nuiv, 2, 0, "glVertexAttrib4Nuiv");
    Sys_LoadGLProc((void**)&GLVertexAttrib4Nusv, 2, 0, "glVertexAttrib4Nusv");
    Sys_LoadGLProc((void**)&GLVertexAttrib4bv, 2, 0, "glVertexAttrib4bv");
    Sys_LoadGLProc((void**)&GLVertexAttrib4d, 2, 0, "glVertexAttrib4d");
    Sys_LoadGLProc((void**)&GLVertexAttrib4dv, 2, 0, "glVertexAttrib4dv");
    Sys_LoadGLProc((void**)&GLVertexAttrib4f, 2, 0, "glVertexAttrib4f");
    Sys_LoadGLProc((void**)&GLVertexAttrib4fv, 2, 0, "glVertexAttrib4fv");
    Sys_LoadGLProc((void**)&GLVertexAttrib4iv, 2, 0, "glVertexAttrib4iv");
    Sys_LoadGLProc((void**)&GLVertexAttrib4s, 2, 0, "glVertexAttrib4s");
    Sys_LoadGLProc((void**)&GLVertexAttrib4sv, 2, 0, "glVertexAttrib4sv");
    Sys_LoadGLProc((void**)&GLVertexAttrib4ubv, 2, 0, "glVertexAttrib4ubv");
    Sys_LoadGLProc((void**)&GLVertexAttrib4uiv, 2, 0, "glVertexAttrib4uiv");
    Sys_LoadGLProc((void**)&GLVertexAttrib4usv, 2, 0, "glVertexAttrib4usv");
    Sys_LoadGLProc((void**)&GLVertexAttribPointer, 2, 0, "glVertexAttribPointer");
    
    // ==========
    // OpenGL 2.1
    // ==========

    Sys_LoadGLProc((void**)&GLUniformMatrix2x3fv, 2, 1, "glUniformMatrix2x3fv");
    Sys_LoadGLProc((void**)&GLUniformMatrix3x2fv, 2, 1, "glUniformMatrix3x2fv");
    Sys_LoadGLProc((void**)&GLUniformMatrix2x4fv, 2, 1, "glUniformMatrix2x4fv");
    Sys_LoadGLProc((void**)&GLUniformMatrix4x2fv, 2, 1, "glUniformMatrix4x2fv");
    Sys_LoadGLProc((void**)&GLUniformMatrix3x4fv, 2, 1, "glUniformMatrix3x4fv");
    Sys_LoadGLProc((void**)&GLUniformMatrix4x3fv, 2, 1, "glUniformMatrix4x3fv");
    
    // ==========
    // OpenGL 3.0
    // ==========

    Sys_LoadGLProc((void**)&GLColorMaski, 3, 0, "glColorMaski");
    Sys_LoadGLProc((void**)&GLGetBooleani_v, 3, 0, "glGetBooleani_v");
    Sys_LoadGLProc((void**)&GLGetIntegeri_v, 3, 0, "glGetIntegeri_v");
    Sys_LoadGLProc((void**)&GLEnablei, 3, 0, "glEnablei");
    Sys_LoadGLProc((void**)&GLDisablei, 3, 0, "glDisablei");
    Sys_LoadGLProc((void**)&GLIsEnabledi, 3, 0, "glIsEnabledi");
    Sys_LoadGLProc((void**)&GLBeginTransformFeedback, 3, 0, "glBeginTransformFeedback");
    Sys_LoadGLProc((void**)&GLEndTransformFeedback, 3, 0, "glEndTransformFeedback");
    Sys_LoadGLProc((void**)&GLBindBufferRange, 3, 0, "glBindBufferRange");
    Sys_LoadGLProc((void**)&GLBindBufferBase, 3, 0, "glBindBufferBase");
    Sys_LoadGLProc((void**)&GLTransformFeedbackVaryings, 3, 0, "glTransformFeedbackVaryings");
    Sys_LoadGLProc((void**)&GLGetTransformFeedbackVarying, 3, 0, "glGetTransformFeedbackVarying");
    Sys_LoadGLProc((void**)&GLClampColor, 3, 0, "glClampColor");
    Sys_LoadGLProc((void**)&GLBeginConditionalRender, 3, 0, "glBeginConditionalRender");
    Sys_LoadGLProc((void**)&GLEndConditionalRender, 3, 0, "glEndConditionalRender");
    Sys_LoadGLProc((void**)&GLVertexAttribIPointer, 3, 0, "glVertexAttribIPointer");
    Sys_LoadGLProc((void**)&GLGetVertexAttribIiv, 3, 0, "glGetVertexAttribIiv");
    Sys_LoadGLProc((void**)&GLGetVertexAttribIuiv, 3, 0, "glGetVertexAttribIuiv");
    Sys_LoadGLProc((void**)&GLVertexAttribI1i, 3, 0, "glVertexAttribI1i");
    Sys_LoadGLProc((void**)&GLVertexAttribI2i, 3, 0, "glVertexAttribI2i");
    Sys_LoadGLProc((void**)&GLVertexAttribI3i, 3, 0, "glVertexAttribI3i");
    Sys_LoadGLProc((void**)&GLVertexAttribI4i, 3, 0, "glVertexAttribI4i");
    Sys_LoadGLProc((void**)&GLVertexAttribI1ui, 3, 0, "glVertexAttribI1ui");
    Sys_LoadGLProc((void**)&GLVertexAttribI2ui, 3, 0, "glVertexAttribI2ui");
    Sys_LoadGLProc((void**)&GLVertexAttribI3ui, 3, 0, "glVertexAttribI3ui");
    Sys_LoadGLProc((void**)&GLVertexAttribI4ui, 3, 0, "glVertexAttribI4ui");
    Sys_LoadGLProc((void**)&GLVertexAttribI1iv, 3, 0, "glVertexAttribI1iv");
    Sys_LoadGLProc((void**)&GLVertexAttribI2iv, 3, 0, "glVertexAttribI2iv");
    Sys_LoadGLProc((void**)&GLVertexAttribI3iv, 3, 0, "glVertexAttribI3iv");
    Sys_LoadGLProc((void**)&GLVertexAttribI4iv, 3, 0, "glVertexAttribI4iv");
    Sys_LoadGLProc((void**)&GLVertexAttribI1uiv, 3, 0, "glVertexAttribI1uiv");
    Sys_LoadGLProc((void**)&GLVertexAttribI2uiv, 3, 0, "glVertexAttribI2uiv");
    Sys_LoadGLProc((void**)&GLVertexAttribI3uiv, 3, 0, "glVertexAttribI3uiv");
    Sys_LoadGLProc((void**)&GLVertexAttribI4uiv, 3, 0, "glVertexAttribI4uiv");
    Sys_LoadGLProc((void**)&GLVertexAttribI4bv, 3, 0, "glVertexAttribI4bv");
    Sys_LoadGLProc((void**)&GLVertexAttribI4sv, 3, 0, "glVertexAttribI4sv");
    Sys_LoadGLProc((void**)&GLVertexAttribI4ubv, 3, 0, "glVertexAttribI4ubv");
    Sys_LoadGLProc((void**)&GLVertexAttribI4usv, 3, 0, "glVertexAttribI4usv");
    Sys_LoadGLProc((void**)&GLGetUniformuiv, 3, 0, "glGetUniformuiv");
    Sys_LoadGLProc((void**)&GLBindFragDataLocation, 3, 0, "glBindFragDataLocation");
    Sys_LoadGLProc((void**)&GLGetFragDataLocation, 3, 0, "glGetFragDataLocation");
    Sys_LoadGLProc((void**)&GLUniform1ui, 3, 0, "glUniform1ui");
    Sys_LoadGLProc((void**)&GLUniform2ui, 3, 0, "glUniform2ui");
    Sys_LoadGLProc((void**)&GLUniform3ui, 3, 0, "glUniform3ui");
    Sys_LoadGLProc((void**)&GLUniform4ui, 3, 0, "glUniform4ui");
    Sys_LoadGLProc((void**)&GLUniform1uiv, 3, 0, "glUniform1uiv");
    Sys_LoadGLProc((void**)&GLUniform2uiv, 3, 0, "glUniform2uiv");
    Sys_LoadGLProc((void**)&GLUniform3uiv, 3, 0, "glUniform3uiv");
    Sys_LoadGLProc((void**)&GLUniform4uiv, 3, 0, "glUniform4uiv");
    Sys_LoadGLProc((void**)&GLTexParameterIiv, 3, 0, "glTexParameterIiv");
    Sys_LoadGLProc((void**)&GLTexParameterIuiv, 3, 0, "glTexParameterIuiv");
    Sys_LoadGLProc((void**)&GLGetTexParameterIiv, 3, 0, "glGetTexParameterIiv");
    Sys_LoadGLProc((void**)&GLGetTexParameterIuiv, 3, 0, "glGetTexParameterIuiv");
    Sys_LoadGLProc((void**)&GLClearBufferiv, 3, 0, "glClearBufferiv");
    Sys_LoadGLProc((void**)&GLClearBufferuiv, 3, 0, "glClearBufferuiv");
    Sys_LoadGLProc((void**)&GLClearBufferfv, 3, 0, "glClearBufferfv");
    Sys_LoadGLProc((void**)&GLClearBufferfi, 3, 0, "glClearBufferfi");
    Sys_LoadGLProc((void**)&GLGetStringi, 3, 0, "GLGetStringi");
    Sys_LoadGLProc((void**)&GLIsRenderbuffer, 3, 0, "glIsRenderbuffer");
    Sys_LoadGLProc((void**)&GLBindRenderbuffer, 3, 0, "glBindRenderbuffer");
    Sys_LoadGLProc((void**)&GLDeleteRenderbuffers, 3, 0, "glDeleteRenderbuffers");
    Sys_LoadGLProc((void**)&GLGenRenderbuffers, 3, 0, "glGenRenderbuffers");
    Sys_LoadGLProc((void**)&GLRenderbufferStorage, 3, 0, "glRenderbufferStorage");
    Sys_LoadGLProc((void**)&GLGetRenderbufferParameteriv, 3, 0, "glGetRenderbufferParameteriv");
    Sys_LoadGLProc((void**)&GLIsFramebuffer, 3, 0, "glIsFramebuffer");
    Sys_LoadGLProc((void**)&GLBindFramebuffer, 3, 0, "glBindFramebuffer");
    Sys_LoadGLProc((void**)&GLDeleteFramebuffers, 3, 0, "glDeleteFramebuffers");
    Sys_LoadGLProc((void**)&GLGenFramebuffers, 3, 0, "glGenFramebuffers");
    Sys_LoadGLProc((void**)&GLCheckFramebufferStatus, 3, 0, "glCheckFramebufferStatus");
    Sys_LoadGLProc((void**)&GLFramebufferTexture1D, 3, 0, "glFramebufferTexture1D");
    Sys_LoadGLProc((void**)&GLFramebufferTexture2D, 3, 0, "glFramebufferTexture2D");
    Sys_LoadGLProc((void**)&GLFramebufferTexture3D, 3, 0, "glFramebufferTexture3D");
    Sys_LoadGLProc((void**)&GLFramebufferRenderbuffer, 3, 0, "glFramebufferRenderbuffer");
    Sys_LoadGLProc((void**)&GLGetFramebufferAttachmentParameteriv, 3, 0, "glGetFramebufferAttachmentParameteriv");
    Sys_LoadGLProc((void**)&GLGenerateMipmap, 3, 0, "glGenerateMipmap");
    Sys_LoadGLProc((void**)&GLBlitFramebuffer, 3, 0, "glBlitFramebuffer");
    Sys_LoadGLProc((void**)&GLRenderbufferStorageMultisample, 3, 0, "glRenderbufferStorageMultisample");
    Sys_LoadGLProc((void**)&GLFramebufferTextureLayer, 3, 0, "glFramebufferTextureLayer");
    Sys_LoadGLProc((void**)&GLMapBufferRange, 3, 0, "glMapBufferRange");
    Sys_LoadGLProc((void**)&GLFlushMappedBufferRange, 3, 0, "glFlushMappedBufferRange");
    Sys_LoadGLProc((void**)&GLBindVertexArray, 3, 0, "glBindVertexArray");
    Sys_LoadGLProc((void**)&GLDeleteVertexArrays, 3, 0, "glDeleteVertexArrays");
    Sys_LoadGLProc((void**)&GLGenVertexArrays, 3, 0, "glGenVertexArrays");
    Sys_LoadGLProc((void**)&GLIsVertexArray, 3, 0, "glIsVertexArray");
}

PFNWGLCREATECONTEXTATTRIBSARBPROC WGLCreateContextAttribsARB;
PFNWGLCHOOSEPIXELFORMATARBPROC    WGLChoosePixelFormatARB;
PFNWGLSWAPINTERVALEXTPROC         WGLSwapIntervalEXT;

// ==========
// OpenGL 1.0
// ==========

PFNGLCULLFACEPROC GLCullFace;
PFNGLFRONTFACEPROC GLFrontFace;
PFNGLHINTPROC GLHint;
PFNGLLINEWIDTHPROC GLLineWidth;
PFNGLPOINTSIZEPROC GLPointSize;
PFNGLPOLYGONMODEPROC GLPolygonMode;
PFNGLSCISSORPROC GLScissor;
PFNGLTEXPARAMETERFPROC GLTexParameterf;
PFNGLTEXPARAMETERFVPROC GLTexParameterfv;
PFNGLTEXPARAMETERIPROC GLTexParameteri;
PFNGLTEXPARAMETERIVPROC GLTexParameteriv;
PFNGLTEXIMAGE1DPROC GLTexImage1D;
PFNGLTEXIMAGE2DPROC GLTexImage2D;
PFNGLDRAWBUFFERPROC GLDrawBuffer;
PFNGLCLEARPROC GLClear;
PFNGLCLEARCOLORPROC GLClearColor;
PFNGLCLEARSTENCILPROC GLClearStencil;
PFNGLCLEARDEPTHPROC GLClearDepth;
PFNGLSTENCILMASKPROC GLStencilMask;
PFNGLCOLORMASKPROC GLColorMask;
PFNGLDEPTHMASKPROC GLDepthMask;
PFNGLDISABLEPROC GLDisable;
PFNGLENABLEPROC GLEnable;
PFNGLFINISHPROC GLFinish;
PFNGLFLUSHPROC GLFlush;
PFNGLBLENDFUNCPROC GLBlendFunc;
PFNGLLOGICOPPROC GLLogicOp;
PFNGLSTENCILFUNCPROC GLStencilFunc;
PFNGLSTENCILOPPROC GLStencilOp;
PFNGLDEPTHFUNCPROC GLDepthFunc;
PFNGLPIXELSTOREFPROC GLPixelStoref;
PFNGLPIXELSTOREIPROC GLPixelStorei;
PFNGLREADBUFFERPROC GLReadBuffer;
PFNGLREADPIXELSPROC GLReadPixels;
PFNGLGETBOOLEANVPROC GLGetBooleanv;
PFNGLGETDOUBLEVPROC GLGetDoublev;
PFNGLGETERRORPROC GLGetError;
PFNGLGETFLOATVPROC GLGetFloatv;
PFNGLGETINTEGERVPROC GLGetIntegerv;
PFNGLGETSTRINGPROC GLGetString;
PFNGLGETTEXIMAGEPROC GLGetTexImage;
PFNGLGETTEXPARAMETERFVPROC GLGetTexParameterfv;
PFNGLGETTEXPARAMETERIVPROC GLGetTexParameteriv;
PFNGLGETTEXLEVELPARAMETERFVPROC GLGetTexLevelParameterfv;
PFNGLGETTEXLEVELPARAMETERIVPROC GLGetTexLevelParameteriv;
PFNGLISENABLEDPROC GLIsEnabled;
PFNGLDEPTHRANGEPROC GLDepthRange;
PFNGLVIEWPORTPROC GLViewport;

// ==========
// OpenGL 1.1
// ==========

PFNGLDRAWARRAYSPROC GLDrawArrays;
PFNGLDRAWELEMENTSPROC GLDrawElements;
PFNGLGETPOINTERVPROC GLGetPointerv;
PFNGLPOLYGONOFFSETPROC GLPolygonOffset;
PFNGLCOPYTEXIMAGE1DPROC GLCopyTexImage1D;
PFNGLCOPYTEXIMAGE2DPROC GLCopyTexImage2D;
PFNGLCOPYTEXSUBIMAGE1DPROC GLCopyTexSubImage1D;
PFNGLCOPYTEXSUBIMAGE2DPROC GLCopyTexSubImage2D;
PFNGLTEXSUBIMAGE1DPROC GLTexSubImage1D;
PFNGLTEXSUBIMAGE2DPROC GLTexSubImage2D;
PFNGLBINDTEXTUREPROC GLBindTexture;
PFNGLDELETETEXTURESPROC GLDeleteTextures;
PFNGLGENTEXTURESPROC GLGenTextures;
PFNGLISTEXTUREPROC GLIsTexture;

// ==========
// OpenGL 1.2
// ==========

PFNGLDRAWRANGEELEMENTSPROC GLDrawRangeElements;
PFNGLTEXIMAGE3DPROC GLTexImage3D;
PFNGLTEXSUBIMAGE3DPROC GLTexSubImage3D;
PFNGLCOPYTEXSUBIMAGE3DPROC GLCopyTexSubImage3D;

// ==========
// OpenGL 1.3
// ==========

PFNGLACTIVETEXTUREPROC GLActiveTexture;
PFNGLSAMPLECOVERAGEPROC GLSampleCoverage;
PFNGLCOMPRESSEDTEXIMAGE3DPROC GLCompressedTexImage3D;
PFNGLCOMPRESSEDTEXIMAGE2DPROC GLCompressedTexImage2D;
PFNGLCOMPRESSEDTEXIMAGE1DPROC GLCompressedTexImage1D;
PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC GLCompressedTexSubImage3D;
PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC GLCompressedTexSubImage2D;
PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC GLCompressedTexSubImage1D;
PFNGLGETCOMPRESSEDTEXIMAGEPROC GLGetCompressedTexImage;

// ==========
// OpenGL 1.4
// ==========

PFNGLBLENDFUNCSEPARATEPROC GLBlendFuncSeparate;
PFNGLMULTIDRAWARRAYSPROC GLMultiDrawArrays;
PFNGLMULTIDRAWELEMENTSPROC GLMultiDrawElements;
PFNGLPOINTPARAMETERFPROC GLPointParameterf;
PFNGLPOINTPARAMETERFVPROC GLPointParameterfv;
PFNGLPOINTPARAMETERIPROC GLPointParameteri;
PFNGLPOINTPARAMETERIVPROC GLPointParameteriv;
PFNGLBLENDCOLORPROC GLBlendColor;
PFNGLBLENDEQUATIONPROC GLBlendEquation;

// ==========
// OpenGL 1.5
// ==========

PFNGLGENQUERIESPROC GLGenQueries;
PFNGLDELETEQUERIESPROC GLDeleteQueries;
PFNGLISQUERYPROC GLIsQuery;
PFNGLBEGINQUERYPROC GLBeginQuery;
PFNGLENDQUERYPROC GLEndQuery;
PFNGLGETQUERYIVPROC GLGetQueryiv;
PFNGLGETQUERYOBJECTIVPROC GLGetQueryObjectiv;
PFNGLGETQUERYOBJECTUIVPROC GLGetQueryObjectuiv;
PFNGLBINDBUFFERPROC GLBindBuffer;
PFNGLDELETEBUFFERSPROC GLDeleteBuffers;
PFNGLGENBUFFERSPROC GLGenBuffers;
PFNGLISBUFFERPROC GLIsBuffer;
PFNGLBUFFERDATAPROC GLBufferData;
PFNGLBUFFERSUBDATAPROC GLBufferSubData;
PFNGLGETBUFFERSUBDATAPROC GLGetBufferSubData;
PFNGLMAPBUFFERPROC GLMapBuffer;
PFNGLUNMAPBUFFERPROC GLUnmapBuffer;
PFNGLGETBUFFERPARAMETERIVPROC GLGetBufferParameteriv;
PFNGLGETBUFFERPOINTERVPROC GLGetBufferPointerv;

// ==========
// OpenGL 2.0
// ==========

PFNGLBLENDEQUATIONSEPARATEPROC GLBlendEquationSeparate;
PFNGLDRAWBUFFERSPROC GLDrawBuffers;
PFNGLSTENCILOPSEPARATEPROC GLStencilOpSeparate;
PFNGLSTENCILFUNCSEPARATEPROC GLStencilFuncSeparate;
PFNGLSTENCILMASKSEPARATEPROC GLStencilMaskSeparate;
PFNGLATTACHSHADERPROC GLAttachShader;
PFNGLBINDATTRIBLOCATIONPROC GLBindAttribLocation;
PFNGLCOMPILESHADERPROC GLCompileShader;
PFNGLCREATEPROGRAMPROC GLCreateProgram;
PFNGLCREATESHADERPROC GLCreateShader;
PFNGLDELETEPROGRAMPROC GLDeleteProgram;
PFNGLDELETESHADERPROC GLDeleteShader;
PFNGLDETACHSHADERPROC GLDetachShader;
PFNGLDISABLEVERTEXATTRIBARRAYPROC GLDisableVertexAttribArray;
PFNGLENABLEVERTEXATTRIBARRAYPROC GLEnableVertexAttribArray;
PFNGLGETACTIVEATTRIBPROC GLGetActiveAttrib;
PFNGLGETACTIVEUNIFORMPROC GLGetActiveUniform;
PFNGLGETATTACHEDSHADERSPROC GLGetAttachedShaders;
PFNGLGETATTRIBLOCATIONPROC GLGetAttribLocation;
PFNGLGETPROGRAMIVPROC GLGetProgramiv;
PFNGLGETPROGRAMINFOLOGPROC GLGetProgramInfoLog;
PFNGLGETSHADERIVPROC GLGetShaderiv;
PFNGLGETSHADERINFOLOGPROC GLGetShaderInfoLog;
PFNGLGETSHADERSOURCEPROC GLGetShaderSource;
PFNGLGETUNIFORMLOCATIONPROC GLGetUniformLocation;
PFNGLGETUNIFORMFVPROC GLGetUniformfv;
PFNGLGETUNIFORMIVPROC GLGetUniformiv;
PFNGLGETVERTEXATTRIBDVPROC GLGetVertexAttribdv;
PFNGLGETVERTEXATTRIBFVPROC GLGetVertexAttribfv;
PFNGLGETVERTEXATTRIBIVPROC GLGetVertexAttribiv;
PFNGLGETVERTEXATTRIBPOINTERVPROC GLGetVertexAttribPointerv;
PFNGLISPROGRAMPROC GLIsProgram;
PFNGLISSHADERPROC GLIsShader;
PFNGLLINKPROGRAMPROC GLLinkProgram;
PFNGLSHADERSOURCEPROC GLShaderSource;
PFNGLUSEPROGRAMPROC GLUseProgram;
PFNGLUNIFORM1FPROC GLUniform1f;
PFNGLUNIFORM2FPROC GLUniform2f;
PFNGLUNIFORM3FPROC GLUniform3f;
PFNGLUNIFORM4FPROC GLUniform4f;
PFNGLUNIFORM1IPROC GLUniform1i;
PFNGLUNIFORM2IPROC GLUniform2i;
PFNGLUNIFORM3IPROC GLUniform3i;
PFNGLUNIFORM4IPROC GLUniform4i;
PFNGLUNIFORM1FVPROC GLUniform1fv;
PFNGLUNIFORM2FVPROC GLUniform2fv;
PFNGLUNIFORM3FVPROC GLUniform3fv;
PFNGLUNIFORM4FVPROC GLUniform4fv;
PFNGLUNIFORM1IVPROC GLUniform1iv;
PFNGLUNIFORM2IVPROC GLUniform2iv;
PFNGLUNIFORM3IVPROC GLUniform3iv;
PFNGLUNIFORM4IVPROC GLUniform4iv;
PFNGLUNIFORMMATRIX2FVPROC GLUniformMatrix2fv;
PFNGLUNIFORMMATRIX3FVPROC GLUniformMatrix3fv;
PFNGLUNIFORMMATRIX4FVPROC GLUniformMatrix4fv;
PFNGLVALIDATEPROGRAMPROC GLValidateProgram;
PFNGLVERTEXATTRIB1DPROC GLVertexAttrib1d;
PFNGLVERTEXATTRIB1DVPROC GLVertexAttrib1dv;
PFNGLVERTEXATTRIB1FPROC GLVertexAttrib1f;
PFNGLVERTEXATTRIB1FVPROC GLVertexAttrib1fv;
PFNGLVERTEXATTRIB1SPROC GLVertexAttrib1s;
PFNGLVERTEXATTRIB1SVPROC GLVertexAttrib1sv;
PFNGLVERTEXATTRIB2DPROC GLVertexAttrib2d;
PFNGLVERTEXATTRIB2DVPROC GLVertexAttrib2dv;
PFNGLVERTEXATTRIB2FPROC GLVertexAttrib2f;
PFNGLVERTEXATTRIB2FVPROC GLVertexAttrib2fv;
PFNGLVERTEXATTRIB2SPROC GLVertexAttrib2s;
PFNGLVERTEXATTRIB2SVPROC GLVertexAttrib2sv;
PFNGLVERTEXATTRIB3DPROC GLVertexAttrib3d;
PFNGLVERTEXATTRIB3DVPROC GLVertexAttrib3dv;
PFNGLVERTEXATTRIB3FPROC GLVertexAttrib3f;
PFNGLVERTEXATTRIB3FVPROC GLVertexAttrib3fv;
PFNGLVERTEXATTRIB3SPROC GLVertexAttrib3s;
PFNGLVERTEXATTRIB3SVPROC GLVertexAttrib3sv;
PFNGLVERTEXATTRIB4NBVPROC GLVertexAttrib4Nbv;
PFNGLVERTEXATTRIB4NIVPROC GLVertexAttrib4Niv;
PFNGLVERTEXATTRIB4NSVPROC GLVertexAttrib4Nsv;
PFNGLVERTEXATTRIB4NUBPROC GLVertexAttrib4Nub;
PFNGLVERTEXATTRIB4NUBVPROC GLVertexAttrib4Nubv;
PFNGLVERTEXATTRIB4NUIVPROC GLVertexAttrib4Nuiv;
PFNGLVERTEXATTRIB4NUSVPROC GLVertexAttrib4Nusv;
PFNGLVERTEXATTRIB4BVPROC GLVertexAttrib4bv;
PFNGLVERTEXATTRIB4DPROC GLVertexAttrib4d;
PFNGLVERTEXATTRIB4DVPROC GLVertexAttrib4dv;
PFNGLVERTEXATTRIB4FPROC GLVertexAttrib4f;
PFNGLVERTEXATTRIB4FVPROC GLVertexAttrib4fv;
PFNGLVERTEXATTRIB4IVPROC GLVertexAttrib4iv;
PFNGLVERTEXATTRIB4SPROC GLVertexAttrib4s;
PFNGLVERTEXATTRIB4SVPROC GLVertexAttrib4sv;
PFNGLVERTEXATTRIB4UBVPROC GLVertexAttrib4ubv;
PFNGLVERTEXATTRIB4UIVPROC GLVertexAttrib4uiv;
PFNGLVERTEXATTRIB4USVPROC GLVertexAttrib4usv;
PFNGLVERTEXATTRIBPOINTERPROC GLVertexAttribPointer;

// ==========
// OpenGL 2.1
// ==========

PFNGLUNIFORMMATRIX2X3FVPROC GLUniformMatrix2x3fv;
PFNGLUNIFORMMATRIX3X2FVPROC GLUniformMatrix3x2fv;
PFNGLUNIFORMMATRIX2X4FVPROC GLUniformMatrix2x4fv;
PFNGLUNIFORMMATRIX4X2FVPROC GLUniformMatrix4x2fv;
PFNGLUNIFORMMATRIX3X4FVPROC GLUniformMatrix3x4fv;
PFNGLUNIFORMMATRIX4X3FVPROC GLUniformMatrix4x3fv;

// ==========
// OpenGL 3.0
// ==========

PFNGLCOLORMASKIPROC GLColorMaski;
PFNGLGETBOOLEANI_VPROC GLGetBooleani_v;
PFNGLGETINTEGERI_VPROC GLGetIntegeri_v;
PFNGLENABLEIPROC GLEnablei;
PFNGLDISABLEIPROC GLDisablei;
PFNGLISENABLEDIPROC GLIsEnabledi;
PFNGLBEGINTRANSFORMFEEDBACKPROC GLBeginTransformFeedback;
PFNGLENDTRANSFORMFEEDBACKPROC GLEndTransformFeedback;
PFNGLBINDBUFFERRANGEPROC GLBindBufferRange;
PFNGLBINDBUFFERBASEPROC GLBindBufferBase;
PFNGLTRANSFORMFEEDBACKVARYINGSPROC GLTransformFeedbackVaryings;
PFNGLGETTRANSFORMFEEDBACKVARYINGPROC GLGetTransformFeedbackVarying;
PFNGLCLAMPCOLORPROC GLClampColor;
PFNGLBEGINCONDITIONALRENDERPROC GLBeginConditionalRender;
PFNGLENDCONDITIONALRENDERPROC GLEndConditionalRender;
PFNGLVERTEXATTRIBIPOINTERPROC GLVertexAttribIPointer;
PFNGLGETVERTEXATTRIBIIVPROC GLGetVertexAttribIiv;
PFNGLGETVERTEXATTRIBIUIVPROC GLGetVertexAttribIuiv;
PFNGLVERTEXATTRIBI1IPROC GLVertexAttribI1i;
PFNGLVERTEXATTRIBI2IPROC GLVertexAttribI2i;
PFNGLVERTEXATTRIBI3IPROC GLVertexAttribI3i;
PFNGLVERTEXATTRIBI4IPROC GLVertexAttribI4i;
PFNGLVERTEXATTRIBI1UIPROC GLVertexAttribI1ui;
PFNGLVERTEXATTRIBI2UIPROC GLVertexAttribI2ui;
PFNGLVERTEXATTRIBI3UIPROC GLVertexAttribI3ui;
PFNGLVERTEXATTRIBI4UIPROC GLVertexAttribI4ui;
PFNGLVERTEXATTRIBI1IVPROC GLVertexAttribI1iv;
PFNGLVERTEXATTRIBI2IVPROC GLVertexAttribI2iv;
PFNGLVERTEXATTRIBI3IVPROC GLVertexAttribI3iv;
PFNGLVERTEXATTRIBI4IVPROC GLVertexAttribI4iv;
PFNGLVERTEXATTRIBI1UIVPROC GLVertexAttribI1uiv;
PFNGLVERTEXATTRIBI2UIVPROC GLVertexAttribI2uiv;
PFNGLVERTEXATTRIBI3UIVPROC GLVertexAttribI3uiv;
PFNGLVERTEXATTRIBI4UIVPROC GLVertexAttribI4uiv;
PFNGLVERTEXATTRIBI4BVPROC GLVertexAttribI4bv;
PFNGLVERTEXATTRIBI4SVPROC GLVertexAttribI4sv;
PFNGLVERTEXATTRIBI4UBVPROC GLVertexAttribI4ubv;
PFNGLVERTEXATTRIBI4USVPROC GLVertexAttribI4usv;
PFNGLGETUNIFORMUIVPROC GLGetUniformuiv;
PFNGLBINDFRAGDATALOCATIONPROC GLBindFragDataLocation;
PFNGLGETFRAGDATALOCATIONPROC GLGetFragDataLocation;
PFNGLUNIFORM1UIPROC GLUniform1ui;
PFNGLUNIFORM2UIPROC GLUniform2ui;
PFNGLUNIFORM3UIPROC GLUniform3ui;
PFNGLUNIFORM4UIPROC GLUniform4ui;
PFNGLUNIFORM1UIVPROC GLUniform1uiv;
PFNGLUNIFORM2UIVPROC GLUniform2uiv;
PFNGLUNIFORM3UIVPROC GLUniform3uiv;
PFNGLUNIFORM4UIVPROC GLUniform4uiv;
PFNGLTEXPARAMETERIIVPROC GLTexParameterIiv;
PFNGLTEXPARAMETERIUIVPROC GLTexParameterIuiv;
PFNGLGETTEXPARAMETERIIVPROC GLGetTexParameterIiv;
PFNGLGETTEXPARAMETERIUIVPROC GLGetTexParameterIuiv;
PFNGLCLEARBUFFERIVPROC GLClearBufferiv;
PFNGLCLEARBUFFERUIVPROC GLClearBufferuiv;
PFNGLCLEARBUFFERFVPROC GLClearBufferfv;
PFNGLCLEARBUFFERFIPROC GLClearBufferfi;
PFNGLGETSTRINGIPROC GLGetStringi;
PFNGLISRENDERBUFFERPROC GLIsRenderbuffer;
PFNGLBINDRENDERBUFFERPROC GLBindRenderbuffer;
PFNGLDELETERENDERBUFFERSPROC GLDeleteRenderbuffers;
PFNGLGENRENDERBUFFERSPROC GLGenRenderbuffers;
PFNGLRENDERBUFFERSTORAGEPROC GLRenderbufferStorage;
PFNGLGETRENDERBUFFERPARAMETERIVPROC GLGetRenderbufferParameteriv;
PFNGLISFRAMEBUFFERPROC GLIsFramebuffer;
PFNGLBINDFRAMEBUFFERPROC GLBindFramebuffer;
PFNGLDELETEFRAMEBUFFERSPROC GLDeleteFramebuffers;
PFNGLGENFRAMEBUFFERSPROC GLGenFramebuffers;
PFNGLCHECKFRAMEBUFFERSTATUSPROC GLCheckFramebufferStatus;
PFNGLFRAMEBUFFERTEXTURE1DPROC GLFramebufferTexture1D;
PFNGLFRAMEBUFFERTEXTURE2DPROC GLFramebufferTexture2D;
PFNGLFRAMEBUFFERTEXTURE3DPROC GLFramebufferTexture3D;
PFNGLFRAMEBUFFERRENDERBUFFERPROC GLFramebufferRenderbuffer;
PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC GLGetFramebufferAttachmentParameteriv;
PFNGLGENERATEMIPMAPPROC GLGenerateMipmap;
PFNGLBLITFRAMEBUFFERPROC GLBlitFramebuffer;
PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC GLRenderbufferStorageMultisample;
PFNGLFRAMEBUFFERTEXTURELAYERPROC GLFramebufferTextureLayer;
PFNGLMAPBUFFERRANGEPROC GLMapBufferRange;
PFNGLFLUSHMAPPEDBUFFERRANGEPROC GLFlushMappedBufferRange;
PFNGLBINDVERTEXARRAYPROC GLBindVertexArray;
PFNGLDELETEVERTEXARRAYSPROC GLDeleteVertexArrays;
PFNGLGENVERTEXARRAYSPROC GLGenVertexArrays;
PFNGLISVERTEXARRAYPROC GLIsVertexArray;
