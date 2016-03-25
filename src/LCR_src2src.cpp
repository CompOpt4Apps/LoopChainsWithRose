/**
 * HC pragma support from ROSE
 * 
 * author yy8, liao
 * yy8@rice.edu, "Chunhua (Liao) Liao" <liao6@llnl.gov>
 * 
 */
#include "hcpragma.h"
#include <string>

using namespace std;
using namespace SageInterface;
using namespace SageBuilder;
using namespace AstFromString;



/**
 * This is a standard main for a source to source
 * translator -- nothing fancy going on here. The 
 * one thing to take not of is that we have overwritten
 * the visit function
 **/
int main(int argc, char * argv[]) {

  SgProject *project = frontend (argc, argv);
  visitorTraversal myvisitor;
  myvisitor.traverseInputFiles(project,preorder);

  return backend(project);
}
