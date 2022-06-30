#type Vertex

#version 330 core

layout(location = 0) in vec2 aPos;
layout(location = 1) in vec4 aColor;

uniform mat4 uProj;

out vec4 vColor;

void main() {
	gl_Position = uProj * vec4(aPos.xy, 0.0, 1.0);
	vColor = aColor;
}



///////////////////////////////////////////

#type Fragment

#version 330 core

out vec4 FragColor;
in vec4 vColor;

void main() {
	FragColor = vColor;
}