#ifndef DILAY_ACTION_TRANSLATE
#define DILAY_ACTION_TRANSLATE

#include <glm/fwd.hpp>
#include <list>
#include "action.hpp"
#include "macro.hpp"

class SphereMesh;
class WingedMesh;

class ActionTranslate : public Action {
  public: 
    DECLARE_BIG3 (ActionTranslate)

    void translate (const std::list <SphereMesh*>&, const glm::vec3&);
    void translate (const std::list <WingedMesh*>&, const glm::vec3&);

  private:
    void runUndo ();
    void runRedo ();

    IMPLEMENTATION
};

#endif
