#ifndef MODEL_RENDERER_HPP
#define MODEL_RENDERER_HPP

#include "models/model.hpp"
#include "render/renderer.hpp"

/**
 * Each mesh inside 3D model is rendered separately using `Renderer` class,
 * as vertexes indices start from 0 for all meshes (otherwise they would overwrite)
 */
struct ModelRenderer {
  // used by class `characters/Player`
  std::vector<Renderer> renderers;

  ModelRenderer(const Program& program, const AssimpUtil::Model& model, const std::vector<Attribute>& attributes);
  void draw(const Uniforms& u={}, bool with_outlines=false);
  void set_transform(const Transformation& transformation);
  void free();

private:
  AssimpUtil::Model m_model;
};

#endif // MODEL_RENDERER_HPP
