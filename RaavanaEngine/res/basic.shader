#type Vertex

#version 330 core

layout(location = 0) in vec2 aPos;
layout(location = 1) in vec4 aColor;
layout(location = 2) in vec2 aTexCoord;

uniform mat4 uProj;

out vec4 vColor;
out vec2 vTexCoord;

void main() {
	gl_Position = uProj * vec4(aPos.xy, 0.0, 1.0);
	vColor = aColor;
	vTexCoord = aTexCoord;
}



///////////////////////////////////////////

#type Fragment

#version 330 core


out vec4 FragColor;
in vec4 vColor;
in vec2 vTexCoord;

uniform sampler2D uTexture;

void main() {
	vec4 texColor = texture(uTexture, vTexCoord);
	FragColor = texColor; // vColor;
	//FragColor = vec4(vTexCoord, 0.0, 1.0);//texColor; // vColor;
}