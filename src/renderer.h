#pragma once

class Renderer {
 public:
  virtual void init() {}
  virtual void renderer() {}
  virtual void destroy() {}
  virtual ~Renderer() = default;
};