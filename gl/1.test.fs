#version 330 core
out vec4 FragColor;

in vec3 fColor;

void main()
{
   //FragColor = vec4(fColor, 1.0);
   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);
}
