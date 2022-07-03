#type Vertex

#version 330 core

layout(location = 0) in vec2 aPos;
layout(location = 1) in vec4 aColor;
layout(location = 2) in vec2 aTexCoord;
layout(location = 3) in float aTexID;

uniform mat4 uProj;

out vec4 vColor;
out vec2 vTexCoord;
out float vTexID;

void main() {
	gl_Position = uProj * vec4(aPos.xy, 0.0, 1.0);
	vColor = aColor;
	vTexCoord = aTexCoord;
	vTexID = aTexID;
}



///////////////////////////////////////////

#type Fragment

#version 330 core


out vec4 FragColor;

in vec4 vColor;
in vec2 vTexCoord;
in float vTexID;

uniform sampler2D uTextures[10];

void main() {
	vec4 texColor = texture(uTextures[int(vTexID)], vTexCoord);
	FragColor =  texColor * vColor;
}