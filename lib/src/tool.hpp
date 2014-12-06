#ifndef DILAY_TOOL
#define DILAY_TOOL

#include <QString>
#include "macro.hpp"

class ViewProperties;
class ViewToolMenuParameters;
class QMouseEvent;
class QWheelEvent;

enum class ToolResponse {
  None, Terminate, Redraw
};

class Tool {
  public:
    DECLARE_BIG3_VIRTUAL (Tool, const ViewToolMenuParameters&, const QString&)

    Tool (const ViewToolMenuParameters&);

    friend class ToolUtil;

    const ViewToolMenuParameters& menuParameters       () const;
    ToolResponse                  initialize           ();
    void                          render               ();
    ToolResponse                  mouseMoveEvent       (QMouseEvent&);
    ToolResponse                  mouseReleaseEvent    (QMouseEvent&);
    ToolResponse                  wheelEvent           (QWheelEvent&);
    QString                       message              () const;
    void                          close                ();
    void                          cancel               ();

  protected:
    void                          updateGlWidget       ();
    ViewProperties&               properties           ();

  private:
    IMPLEMENTATION

    virtual ToolResponse runInitialize        ()             { return ToolResponse::None; }
    virtual void         runRender            ()             {}
    virtual ToolResponse runMouseMoveEvent    (QMouseEvent&) { return ToolResponse::None; }
    virtual ToolResponse runMouseReleaseEvent (QMouseEvent&) { return ToolResponse::None; }
    virtual ToolResponse runWheelEvent        (QWheelEvent&) { return ToolResponse::None; }
    virtual QString      runMessage           () const       { return QString (); }
    virtual void         runClose             ()             {}
};

#define DECLARE_TOOL(name,methods)                     \
  class name : public Tool { public:                   \
    DECLARE_BIG3 (name, const ViewToolMenuParameters&) \
    static QString toolName ();                        \
    private: IMPLEMENTATION methods };

#define DECLARE_PARAM_TOOL(name,params,methods)                           \
  class name : public Tool { public:                                      \
    DECLARE_BIG3 (name, const ViewToolMenuParameters&, ESC_PARENS params) \
    static QString toolName params;                                       \
    private: IMPLEMENTATION methods };

#define DECLARE_TOOL_RUN_INITIALIZE          ToolResponse runInitialize        ();
#define DECLARE_TOOL_RUN_RENDER              void         runRender            ();
#define DECLARE_TOOL_RUN_MOUSE_MOVE_EVENT    ToolResponse runMouseMoveEvent    (QMouseEvent&);
#define DECLARE_TOOL_RUN_MOUSE_RELEASE_EVENT ToolResponse runMouseReleaseEvent (QMouseEvent&);
#define DECLARE_TOOL_RUN_MOUSE_WHEEL_EVENT   ToolResponse runWheelEvent        (QWheelEvent&);
#define DECLARE_TOOL_RUN_MESSAGE             QString      runMessage           () const;
#define DECLARE_TOOL_RUN_CLOSE               void         runClose             ();

#define DELEGATE_TOOL(name)\
  DELEGATE_STATIC (QString, name, toolName) \
  DELEGATE_BIG3_BASE ( name, (const ViewToolMenuParameters& p) \
                     , (this), Tool, (p, toolName ()))

#define DELEGATE1_TOOL(name,t1)\
  DELEGATE1_STATIC (QString, name, toolName, t1) \
  DELEGATE_BIG3_BASE ( name, (const ViewToolMenuParameters& p,t1 a1) \
                     , (this,a1), Tool, (p, toolName (a1)))

#define DELEGATE2_TOOL(name,t1,t2)\
  DELEGATE2_STATIC (QString, name, toolName, t1, t2) \
  DELEGATE_BIG3_BASE ( name, (const ViewToolMenuParameters& p,t1 a1,t2 a2) \
                     , (this,a1,a2), Tool, (p, toolName (a1,a2)))

#define DELEGATE3_TOOL(name,t1,t2,t3)\
  DELEGATE3_STATIC (QString, name, toolName, t1, t2, t3) \
  DELEGATE_BIG3_BASE ( name, (const ViewToolMenuParameters& p,t1 a1,t2 a2,t3 a3) \
                     , (this,a1,a2,a3), Tool, (p, toolName (a1,a2,a3)))

#define DELEGATE4_TOOL(name,t1,t2,t3,t4)\
  DELEGATE4_STATIC (QString, name, toolName, t1, t2, t3, t4) \
  DELEGATE_BIG3_BASE ( name, (const ViewToolMenuParameters& p,t1 a1,t2 a2,t3 a3,t4 a4) \
                     , (this,a1,a2,a3,a4), Tool, (p, toolName (a1,a2,a3,a4)))

#define DELEGATE5_TOOL(name,t1,t2,t3,t4,t5)\
  DELEGATE5_STATIC (QString, name, toolName, t1, t2, t3, t4, t5) \
  DELEGATE_BIG3_BASE ( name, (const ViewToolMenuParameters& p,t1 a1,t2 a2,t3 a3,t4 a4,t5 a5) \
                     , (this,a1,a2,a3,a4,a5), Tool, (p, toolName (a1,a2,a3,a4,a5)))

#define DELEGATE_TOOL_RUN_INITIALIZE(n)          DELEGATE       (ToolResponse, n, runInitialize)
#define DELEGATE_TOOL_RUN_RENDER(n)              DELEGATE       (void        , n, runRender)
#define DELEGATE_TOOL_RUN_MOUSE_MOVE_EVENT(n)    DELEGATE1      (ToolResponse, n, runMouseMoveEvent, QMouseEvent&)
#define DELEGATE_TOOL_RUN_MOUSE_RELEASE_EVENT(n) DELEGATE1      (ToolResponse, n, runMouseReleaseEvent, QMouseEvent&)
#define DELEGATE_TOOL_RUN_MOUSE_WHEEL_EVENT(n)   DELEGATE1      (ToolResponse, n, runWheelEvent, QWheelEvent&)
#define DELEGATE_TOOL_RUN_MESSAGE(n)             DELEGATE_CONST (QString     , n, runMessage)
#define DELEGATE_TOOL_RUN_CLOSE(n)               DELEGATE       (void        , n, runClose)

#endif
