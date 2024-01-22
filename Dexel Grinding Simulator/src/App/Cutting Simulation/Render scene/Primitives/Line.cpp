#include "Line.h"


Line::Line(vec3 p1_, vec3 p2_, vec4 color_)
{
	color = color_;
	p1 = p1_;
	p2 = p2_;
	 
	shaderProgram = Shader();
	shaderProgram.Init(
		(char*)"src/App/Cutting Simulation/Render scene/Primitives/lines.vert",
		(char*)"src/App/Cutting Simulation/Render scene/Primitives/lines.frag");

	color_loc = glGetUniformLocation(shaderProgram.ID, "color");
	glUniform4f(color_loc, color.x, color.y, color.z, color.w);

	VAO1 = VAO();
	VAO1.Bind();

	VBO1 = VBO();
	VBO1.Init({p1.x, p1.y, p1.z, p2.x, p2.y, p2.z }, sizeof(GLfloat) * 6);


	VAO1.LinkVBO(VBO1, 0);
	VAO1.Unbind();
	VBO1.Unbind();
}


void Line::Draw()
{
	shaderProgram.Activate();
	VAO1.Bind();

	glUniform4f(color_loc, color.x, color.y, color.z, color.w);

	glLineWidth(3);
	glDrawArrays(GL_LINES, 0, 2);
}

void Line::UpdatePosition(vec3 p1, vec3 p2)
{
	VBO1.UpdateData({ p1.x, p1.y, p1.z, p2.x, p2.y, p2.z }, sizeof(GLfloat) * 6);
}