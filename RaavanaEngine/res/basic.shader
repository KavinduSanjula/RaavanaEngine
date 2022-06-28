#type Vertex

#version 330 core

layout(location = 0) in vec2 aPos;

void main() {
	gl_Position = vec4(aPos.xy, 0.0, 1.0);
}



///////////////////////////////////////////

#type Fragment

#version 330 core

out vec4 FragColor;

void main() {
	FragColor = vec4(1.0,0.5,0.2,1.0);
}