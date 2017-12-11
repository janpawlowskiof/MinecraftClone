#version 130

varying vec2 texCoord0;
flat out int normal0;
out float timer0;
attribute vec3 position;
out vec3 position0;
out vec3 camPosition0;
attribute vec2 texCoord;
attribute int normal;
uniform float timer;

uniform mat4 transform;
uniform vec3 camPosition;

void main()
{
	normal0 = normal;
	timer0 = timer;
	position0 = position;
	camPosition0 = camPosition;
	gl_Position = transform * vec4(position, 1.0);
	texCoord0 = texCoord;
}