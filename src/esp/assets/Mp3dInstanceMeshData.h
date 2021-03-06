// Copyright (c) Facebook, Inc. and its affiliates.
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#pragma once

#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

#include <Magnum/GL/Buffer.h>
#include <Magnum/GL/Mesh.h>

#include "GenericInstanceMeshData.h"
#include "esp/core/esp.h"

namespace esp {
namespace assets {

/*
 * MP3D object instance segmented mesh
 * Holds a vbo where each vertex is (x, y, z, objectId)
 */
class Mp3dInstanceMeshData : public GenericInstanceMeshData {
 public:
  Mp3dInstanceMeshData()
      : GenericInstanceMeshData(SupportedMeshType::INSTANCE_MESH) {}
  virtual ~Mp3dInstanceMeshData() {}

  //! Loads an MP3D house segmentations PLY file
  bool loadMp3dPLY(const std::string& plyFile);

  //! Saves semantic mesh PLY with object ids per-vertex
  bool saveSemMeshPLY(
      const std::string& plyFile,
      const std::unordered_map<int, int>& segmentIdToObjectIdMap);

 protected:
  std::vector<vec3i> cpu_ibo_;
  std::vector<int> materialIds_;
  std::vector<int> segmentIds_;
  std::vector<int> categoryIds_;
};

}  // namespace assets
}  // namespace esp
