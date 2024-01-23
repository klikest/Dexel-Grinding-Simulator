#include "Lines.h"

Lines::Lines(std::vector<glm::vec3> points_, glm::vec4 color_)
{

	/*
	color = color_;
	points = points_;
	size = points.size();
	weight = 1;

	shaderProgram = Shader();
	shaderProgram.Init(
		(char*)"src/App/Cutting Simulation/Render scene/Primitives/lines.vert",
		(char*)"src/App/Cutting Simulation/Render scene/Primitives/lines.frag");

	color_loc = glGetUniformLocation(shaderProgram.ID, "color");
	glUniform4f(color_loc, color.x, color.y, color.z, color.w);

	VAO1 = VAO();
	VAO1.Bind();

	VBO1 = VBO();
	VBO1.Init(points);

	VAO1.LinkVBO(VBO1, 0);
	VAO1.Unbind();
	VBO1.Unbind();

	*/
}

void Lines::Draw()
{
	shaderProgram.Activate();
	VAO1.Bind();
	glUniform4f(color_loc, color.x, color.y, color.z, color.w);

	glLineWidth(3);
	glDrawArrays(GL_LINE_STRIP, 0, size);
}

void Lines::UpdatePosition(std::vector<glm::vec3> points)
{
}

void Lines::UpdateColor(glm::vec4 color_)
{
}

void Lines::Delete()
{
}
