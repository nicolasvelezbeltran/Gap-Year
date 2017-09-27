#version 410

in vec3 vertexPosition;
in vec3 vertexNormal;

out vec3 fragmentNormal;

void
main()
{
    gl_Position = vec4(vertexPosition, 1);
    fragmentNormal = vertexNormal;
}
