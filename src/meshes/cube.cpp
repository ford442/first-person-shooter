#include <meshes/cube.hpp>

Cube::Cube(const Program& program):
  Mesh(VERTEXES, N_VERTEXES)
{
  // get position attribute from shader
  set_attribute(program);
}

void Cube::set_attribute(const Program& program) {
  // position attribute (same name as input var in vertex shader)
  GLuint attr_position = program.define_attribute("position");
  glVertexAttribPointer(attr_position, 3, GL_FLOAT, GL_FALSE, 12 * sizeof(float), (void *) 0);
  glEnableVertexAttribArray(attr_position);
}

// coord(x,y,z)        color(r,g,b)      texture(u,v,w)       normal(nx,ny,nz)
const std::vector<float> Cube::VERTEXES = {
  // negative-x (left face)
  -0.5f,  0.5f,  0.5f, 1.0f, 0.0f, 0.0f, -1.0f,  1.0f,  1.0f, -1.0f,  0.0f,  0.0f,
  -0.5f,  0.5f, -0.5f, 1.0f, 0.0f, 0.0f, -1.0f,  1.0f, -1.0f, -1.0f,  0.0f,  0.0f,
  -0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f, -1.0f, -1.0f, -1.0f, -1.0f,  0.0f,  0.0f,
  -0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f, -1.0f, -1.0f, -1.0f, -1.0f,  0.0f,  0.0f,
  -0.5f, -0.5f,  0.5f, 1.0f, 0.0f, 0.0f, -1.0f, -1.0f,  1.0f, -1.0f,  0.0f,  0.0f,
  -0.5f,  0.5f,  0.5f, 1.0f, 0.0f, 0.0f, -1.0f,  1.0f,  1.0f, -1.0f,  0.0f,  0.0f,

   // positive-x (right face)
   0.5f,  0.5f,  0.5f, 1.0f, 0.0f, 0.0f,  1.0f,  1.0f,  1.0f,  1.0f,  0.0f,  0.0f,
   0.5f,  0.5f, -0.5f, 1.0f, 0.0f, 0.0f,  1.0f,  1.0f, -1.0f,  1.0f,  0.0f,  0.0f,
   0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f,  1.0f, -1.0f, -1.0f,  1.0f,  0.0f,  0.0f,
   0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f,  1.0f, -1.0f, -1.0f,  1.0f,  0.0f,  0.0f,
   0.5f, -0.5f,  0.5f, 1.0f, 0.0f, 0.0f,  1.0f, -1.0f,  1.0f,  1.0f,  0.0f,  0.0f,
   0.5f,  0.5f,  0.5f, 1.0f, 0.0f, 0.0f,  1.0f,  1.0f,  1.0f,  1.0f,  0.0f,  0.0f,

   // negative-y (bottom face)
  -0.5f, -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, -1.0f, -1.0f, -1.0f,  0.0f, -1.0f,  0.0f,
   0.5f, -0.5f, -0.5f, 0.0f, 1.0f, 0.0f,  1.0f, -1.0f, -1.0f,  0.0f, -1.0f,  0.0f,
   0.5f, -0.5f,  0.5f, 0.0f, 1.0f, 0.0f,  1.0f, -1.0f,  1.0f,  0.0f, -1.0f,  0.0f,
   0.5f, -0.5f,  0.5f, 0.0f, 1.0f, 0.0f,  1.0f, -1.0f,  1.0f,  0.0f, -1.0f,  0.0f,
  -0.5f, -0.5f,  0.5f, 0.0f, 1.0f, 0.0f, -1.0f, -1.0f,  1.0f,  0.0f, -1.0f,  0.0f,
  -0.5f, -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, -1.0f, -1.0f, -1.0f,  0.0f, -1.0f,  0.0f,

  // positive-y (top face)
  -0.5f,  0.5f, -0.5f, 0.0f, 1.0f, 0.0f, -1.0f,  1.0f, -1.0f,  0.0f,  1.0f,  0.0f,
   0.5f,  0.5f, -0.5f, 0.0f, 1.0f, 0.0f,  1.0f,  1.0f, -1.0f,  0.0f,  1.0f,  0.0f,
   0.5f,  0.5f,  0.5f, 0.0f, 1.0f, 0.0f,  1.0f,  1.0f,  1.0f,  0.0f,  1.0f,  0.0f,
   0.5f,  0.5f,  0.5f, 0.0f, 1.0f, 0.0f,  1.0f,  1.0f,  1.0f,  0.0f,  1.0f,  0.0f,
  -0.5f,  0.5f,  0.5f, 0.0f, 1.0f, 0.0f, -1.0f,  1.0f,  1.0f,  0.0f,  1.0f,  0.0f,
  -0.5f,  0.5f, -0.5f, 0.0f, 1.0f, 0.0f, -1.0f,  1.0f, -1.0f,  0.0f,  1.0f,  0.0f,

  // negative-z (back face)
  -0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, -1.0f, -1.0f, -1.0f,  0.0f,  0.0f, -1.0f,
   0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 1.0f,  1.0f, -1.0f, -1.0f,  0.0f,  0.0f, -1.0f,
   0.5f,  0.5f, -0.5f, 0.0f, 0.0f, 1.0f,  1.0f,  1.0f, -1.0f,  0.0f,  0.0f, -1.0f,
   0.5f,  0.5f, -0.5f, 0.0f, 0.0f, 1.0f,  1.0f,  1.0f, -1.0f,  0.0f,  0.0f, -1.0f, 
  -0.5f,  0.5f, -0.5f, 0.0f, 0.0f, 1.0f, -1.0f,  1.0f, -1.0f,  0.0f,  0.0f, -1.0f,
  -0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, -1.0f, -1.0f, -1.0f,  0.0f,  0.0f, -1.0f,

  // positive-z (front face)
  -0.5f, -0.5f,  0.5f, 0.0f, 0.0f, 1.0f, -1.0f, -1.0f,  1.0f,  0.0f,  0.0f,  1.0f,
   0.5f, -0.5f,  0.5f, 0.0f, 0.0f, 1.0f,  1.0f, -1.0f,  1.0f,  0.0f,  0.0f,  1.0f,
   0.5f,  0.5f,  0.5f, 0.0f, 0.0f, 1.0f,  1.0f,  1.0f,  1.0f,  0.0f,  0.0f,  1.0f,
   0.5f,  0.5f,  0.5f, 0.0f, 0.0f, 1.0f,  1.0f,  1.0f,  1.0f,  0.0f,  0.0f,  1.0f,
  -0.5f,  0.5f,  0.5f, 0.0f, 0.0f, 1.0f, -1.0f,  1.0f,  1.0f,  0.0f,  0.0f,  1.0f,
  -0.5f, -0.5f,  0.5f, 0.0f, 0.0f, 1.0f, -1.0f, -1.0f,  1.0f,  0.0f,  0.0f,  1.0f
};
