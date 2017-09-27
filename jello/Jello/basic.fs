#version 410

layout(location = 0) out vec4 colorOut;

in vec3 fragmentNormal;

void
main()
{
    colorOut = vec4(1, 1, 1, 0);
}
