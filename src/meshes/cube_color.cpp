#include <meshes/cube_color.hpp>

CubeColor::CubeColor(const Program& program):
  Cube(program)
{
  // get color attribute from shader
  set_attribute(program);
}

void CubeColor::set_attribute(const Program& program) {
  // color attribute
  GLuint attr_color = program.define_attribute("color");
  glVertexAttribPointer(attr_color, 3, GL_FLOAT, GL_FALSE, 12 * sizeof(float), (void *) (3 * sizeof(float)));
  glEnableVertexAttribArray(attr_color);
}
