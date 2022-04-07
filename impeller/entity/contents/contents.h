// Copyright 2013 The Flutter Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#pragma once

#include <functional>
#include <memory>
#include <vector>

#include "flutter/fml/macros.h"
#include "impeller/entity/contents/snapshot.h"
#include "impeller/geometry/rect.h"
#include "impeller/renderer/texture.h"

namespace impeller {

class ContentContext;
struct ContentContextOptions;
class Entity;
class Surface;
class RenderPass;

ContentContextOptions OptionsFromPass(const RenderPass& pass);

ContentContextOptions OptionsFromPassAndEntity(const RenderPass& pass,
                                               const Entity& entity);

class Contents {
 public:
  Contents();

  virtual ~Contents();

  virtual bool Render(const ContentContext& renderer,
                      const Entity& entity,
                      RenderPass& pass) const = 0;

  /// @brief Get the screen space bounding rectangle that this contents affects.
  virtual std::optional<Rect> GetCoverage(const Entity& entity) const;

  /// @brief Render this contents to a texture, respecting the entity's
  ///        transform, path, stencil depth, blend mode, etc.
  ///        The result texture size is always the size of
  ///        `GetCoverage(entity)`.
  virtual std::optional<Snapshot> RenderToTexture(
      const ContentContext& renderer,
      const Entity& entity) const;

 protected:

 private:
  FML_DISALLOW_COPY_AND_ASSIGN(Contents);
};

}  // namespace impeller
