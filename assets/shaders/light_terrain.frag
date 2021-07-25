#version 130

// different colors for each material & light components
struct Material {
  vec3 ambiant;
  vec3 diffuse;
  vec3 specular;
  float shininess;
};

struct Light {
  vec3 position;
  vec3 ambiant;
  vec3 diffuse;
  vec3 specular;
};

in vec3 normal_vert;
in vec3 position_vert;

uniform Material material;
uniform Light light;
uniform vec3 position_camera;

out vec4 color_out;

/* Functions declarations */
vec4 colormap(in float x);

void main() {
  // ambiant light constant
  // vec3 ambiant = material.ambiant * light.ambiant;
  vec3 ambiant = vec3(colormap(position_vert.y / 10.0)) * light.ambiant;

  // diffuse light depends on light beam & fragment normal
  vec3 normal_vec = normalize(normal_vert);
  vec3 light_vec = normalize(light.position - position_vert);
  float strength_diffuse = max(dot(light_vec, normal_vec), 0.0);
  // vec3 diffuse = (strength_diffuse * material.diffuse) * light.diffuse;
  vec3 diffuse = (strength_diffuse * vec3(colormap(position_vert.y / 10.0))) * light.diffuse;

  // specular light depends on reflected light beam on fragment & camera position
  vec3 camera_vec = normalize(position_camera - position_vert);
  vec3 light_reflect_vec = reflect(-light_vec, normal_vec);
  float strength_specular = pow(max(dot(light_reflect_vec, camera_vec), 0.0), material.shininess);
  vec3 specular = (strength_specular * material.specular) * light.specular;

  // combine material components
  color_out = vec4(ambiant + diffuse + specular, 1.0);
}

/**
 * IDL Level16 colormap
 * https://github.com/kbinani/colormap-shaders/blob/master/shaders/glsl/IDL_16_Level.frag
 * @param x Elevation (y-coord) in [0, 1]
 */
vec4 colormap(in float x) {
    if (x < 0.0) {
        return vec4(0.0, 0.0, 0.0, 1.0);
    } else if (1.0 < x) {
        return vec4(1.0, 1.0, 1.0, 1.0);
    } else if (x < 1.0 / 16.0) {
        return vec4(0.0, 84.0 / 255.0, 0.0, 1.0);
    } else if (x < 2.0 / 16.0) {
        return vec4(0.0, 168.0 / 255.0, 0.0, 1.0);
    } else if (x < 3.0 / 16.0) {
        return vec4(0.0, 1.0, 0.0, 1.0);
    } else if (x < 4.0 / 16.0) {
        return vec4(0.0, 1.0, 84.0 / 255.0, 1.0);
    } else if (x < 5.0 / 16.0) {
        return vec4(0.0, 1.0, 168.0 / 255.0, 1.0);
    } else if (x < 6.0 / 16.0) {
        return vec4(0.0, 1.0, 1.0, 1.0);
    } else if (x < 7.0 / 16.0) {
        return vec4(0.0, 0.0, 1.0, 1.0);
    } else if (x < 8.0 / 16.0) {
        return vec4(128.0 / 255.0, 0.0, 1.0, 1.0);
    } else if (x < 9.0 / 16.0) {
        return vec4(1.0, 0.0, 220.0 / 255.0, 1.0);
    } else if (x < 10.0 / 16.0) {
        return vec4(1.0, 0.0, 180.0 / 255.0, 1.0);
    } else if (x < 11.0 / 16.0) {
        return vec4(1.0, 0.0, 128.0 / 255.0, 1.0);
    } else if (x < 12.0 / 16.0) {
        return vec4(1.0, 0.0, 64.0 / 255.0, 1.0);
    } else if (x < 13.0 / 16.0) {
        return vec4(1.0, 0.0, 0.0, 1.0);
    } else if (x < 14.0 / 16.0) {
        return vec4(220.0 / 255.0, 190.0 / 255.0, 190.0 / 255.0, 1.0);
    } else if (x < 15.0 / 16.0) {
        return vec4(220.0 / 255.0, 220.0 / 255.0, 220.0 / 255.0, 1.0);
    } else {
        return vec4(1.0, 1.0, 1.0, 1.0);
    }
}
