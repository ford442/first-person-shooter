#include <glm/gtc/matrix_transform.hpp>

#include "render/model_renderer.hpp"

// not declared as private members as constants cause class's implicit copy-constructor to be deleted (prevents re-assignment)
// movement constants
const float SPEED = 0.1f;

ModelRenderer::ModelRenderer(const Program& program, const AssimpUtil::Model& model, const std::vector<Attribute>& attributes):
  m_model(model)
{
  // one renderer by mesh (to avoid mixing up meshes indices)
  for (const AssimpUtil::Mesh& mesh : m_model.meshes) {
    VBO vbo_mesh(Geometry(mesh.vertexes, mesh.indices, mesh.positions));
    Renderer renderer(program, vbo_mesh, attributes);
    renderers.push_back(renderer);
  }
}

/**
 * Initial transformation (position) of 3D Object accord. to model matrix
 * as well view & projection matrixes
 */
void ModelRenderer::set_transform(const Transformation& transformation) {
  for (Renderer& renderer : renderers) {
    renderer.set_transform(transformation);
  }
}

/* Rendering of model relies on `Renderer::draw() applied to each mesh */
void ModelRenderer::draw(const Uniforms& u, bool with_outlines) {
  Uniforms uniforms = u;

  for (size_t i_renderer = 0; i_renderer < renderers.size(); ++i_renderer) {
    // retrieve material color from mesh
    AssimpUtil::Mesh mesh = m_model.meshes[i_renderer];
    uniforms["color"] = mesh.color;
    uniforms["texture2d"] = mesh.texture;
    Renderer renderer = renderers[i_renderer];

    if (with_outlines) {
      renderer.draw_with_outlines(uniforms);
    } else {
      renderer.draw(uniforms);
    }
  }
}

void ModelRenderer::free() {
  for (Renderer& renderer : renderers) {
    renderer.free();
  }
}
