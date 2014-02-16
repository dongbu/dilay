#ifndef DILAY_ACTION_IDS
#define DILAY_ACTION_IDS

#include <initializer_list>
#include "macro.hpp"

class WingedMesh;
class WingedFace;
class WingedEdge;
class WingedVertex;
class Id;

class ActionIds {
  public: 
    DECLARE_BIG3 (ActionIds)

    void          reserveIds     (unsigned int);
    void          reserveIndices (unsigned int);
    void          reserve        (unsigned int, unsigned int);
    void          setId          (unsigned int, const Id&);
    void          setIds         (std::initializer_list <Id>, unsigned int = 0);
    void          setIndex       (unsigned int, unsigned int);
    void          setIndices     (std::initializer_list <unsigned int>, unsigned int = 0);
    Id*           getId          (unsigned int);
    unsigned int* getIndex       (unsigned int);
    void          resetId        (unsigned int);
    void          resetIndex     (unsigned int);
    WingedMesh&   getMesh        (unsigned int);
    WingedFace*   getFace        (WingedMesh&, unsigned int);
    WingedEdge*   getEdge        (WingedMesh&, unsigned int);
    WingedVertex* getVertex      (WingedMesh&, unsigned int);
    void          setMesh        (unsigned int, const WingedMesh*);
    void          setFace        (unsigned int, const WingedFace*);
    void          setEdge        (unsigned int, const WingedEdge*);
    void          setVertex      (unsigned int, const WingedVertex*);

    SAFE_REF1 (Id          , getId    , unsigned int)
    SAFE_REF1 (unsigned int, getIndex , unsigned int)
    SAFE_REF2 (WingedFace  , getFace  , WingedMesh&, unsigned int)
    SAFE_REF2 (WingedEdge  , getEdge  , WingedMesh&, unsigned int)
    SAFE_REF2 (WingedVertex, getVertex, WingedMesh&, unsigned int)

  private:
    class Impl;
    Impl* impl;
};
#endif
