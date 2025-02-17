#ifndef MODEL_HPP
#define MODEL_HPP

#include <vector>
#include <string>
#include <assimp/scene.h>
#include <assimp/Importer.hpp>

#include "models/mesh.hpp"

/**
 * Wrapper struct around Assimp::aiScene class
 * Serves as parent of all meshes inside scene (i.e. 3D model in *.obj format)
 * Namespace to avoid confusion with `entities/Model`
 */
namespace AssimpUtil {
  struct Model {
    std::vector<AssimpUtil::Mesh> meshes;

    Model(const std::string& path, Assimp::Importer& importer);

  private:
    const aiScene* m_scene;

    /* Path to model to load & directory from it to get texture images */
    std::string m_path;
    std::string m_directory;

    /* Optimization: avoid loading a texture image more than once (as it's quite costly) */
    std::unordered_map<std::string, Texture2D> m_textures_loaded;

    bool load_scene(Assimp::Importer& importer);
    void set_mesh_color(aiMaterial* material, unsigned int index);
    void set_mesh_texture(aiMaterial* material, unsigned int index);
  };
}

#endif // MODEL_HPP
