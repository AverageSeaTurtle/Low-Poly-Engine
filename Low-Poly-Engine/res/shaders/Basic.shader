#shader vertex
#version 330 core

layout(location = 0) in vec3 vertex_position;
layout(location = 1) in vec3 vertex_color;
layout(location = 2) in vec2 vertex_texcoord;
layout(location = 3) in vec3 vertex_normal;

uniform mat4 transform;

out vec3 vs_position;
out vec3 vs_color;
out vec2 vs_texcoord;
out vec3 vs_normal;

void main()
{
	vs_position = vec3(gl_Position.xyz);
	vs_color = vertex_color;
	vs_texcoord = vertex_texcoord;
	vs_normal = vec3(transform * vec4(vs_normal, 1.f));

	gl_Position = transform * vec4(vertex_position, 1.f);
};

#shader fragment
#version 330 core

out vec4 fs_color;

in vec3 vs_position;
in vec3 vs_color;
in vec2 vs_texcoord;
in vec3 vs_normal;

uniform sampler2D fs_texture;

void main()
{
	fs_color = texture(fs_texture, vs_texcoord);
};
