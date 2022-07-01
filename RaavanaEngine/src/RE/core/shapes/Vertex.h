#pragma once
#include "repch.h"
#include "math/vector.h"
#include "utils/VertexBufferLayout.h"

namespace RE {

	struct Vertex {
		vec3 Position;
		vec4 Color;
		vec2 TexCoord;

		static VertexBufferLayout GetLayout() {

			VertexBufferLayout layout;
			layout.Push<float>(3);
			layout.Push<float>(4);
			layout.Push<float>(2);

			return layout;
		}
	};

}
