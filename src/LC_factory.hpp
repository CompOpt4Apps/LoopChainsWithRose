#include <rose.h>


class visitorTraversal : public AstSimpleProcessing{
  protected:
    virtual void visit(SgNode* n);
};

