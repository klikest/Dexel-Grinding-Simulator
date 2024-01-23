#include "Line.h"



Line::Line()
{
	shaderProgram = new Shader((char*)"src/App/Cutting Simulation/Render scene/Primitives/lines.vert",
		(char*)"src/App/Cutting Simulation/Render scene/Primitives/lines.frag");

	color_loc = glGetUniformLocation(shaderProgram->ID, "color");
	glUniform4f(color_loc, color.x, color.y, color.z, color.w);

	VAO1 = VAO();
	VAO1.Bind();

	VBO1 = VBO();
	VBO1.Init({ 0, 0, 0,1, 1, 0 }, sizeof(glm::vec3) * 2);

	VAO1.LinkVBO(VBO1, 0);
	VAO1.Unbind();
	VBO1.Unbind();


	shaderProgram2 = new Shader((char*)"src/App/Cutting Simulation/Render scene/Primitives/lines.vert",
		(char*)"src/App/Cutting Simulation/Render scene/Primitives/lines.frag");

	color_loc2 = glGetUniformLocation(shaderProgram2->ID, "color");
	glUniform4f(color_loc, color.x, color.y, color.z, color.w);

	VAO2 = VAO();
	VAO2.Bind();

	VBO2 = VBO();
	VBO2.Init({ 0, 0, 0 ,-1, 1, 0 }, sizeof(glm::vec3) * 2);

	VAO2.LinkVBO(VBO2, 0);
	VAO2.Unbind();
	VBO2.Unbind();



}

Line::Line(vec3 p1_, vec3 p2_, vec4 color_)
{





}


void Line::Draw()
{
	shaderProgram->Activate();
	VAO1.Bind();
	glUniform4f(color_loc, color.x, color.y, color.z, color.w);
	glLineWidth(3);
	glDrawArrays(GL_LINES, 0, 2);
	VAO1.Unbind();


	shaderProgram2->Activate();
	VAO2.Bind();
	glUniform4f(color_loc, color.x, color.y, color.z, color.w);
	glLineWidth(3);
	glDrawArrays(GL_LINES, 0, 2);
	VAO2.Unbind();
}

void Line::UpdatePosition(vec3 p1, vec3 p2)
{
	VBO1.UpdateData({ p1.x, p1.y, p1.z, p2.x, p2.y, p2.z }, sizeof(GLfloat) * 6);
}

void Line::UpdateColor(vec4 color_)
{
	color = color_;
}

void Line::Delete()
{
	VAO1.Delete();
	VBO1.Delete();
	shaderProgram->Delete();
}
