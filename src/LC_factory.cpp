#include "LC_factory.hpp"


void visitorTraversal::visit(SgNode* node)
{
  if (node->variantT() == V_SgPragmaDeclaration) {
//      cout << "Found a pragma!" << endl;

      SgPragma * pragma =  isSgPragmaDeclaration(node)->get_pragma();
      string input_str = pragma->get_pragma();
      AstAttribute* result = NULL;
      result = parse_HC_Pragma (isSgPragmaDeclaration(node));
      HC_PragmaAttribute* hc_att = dynamic_cast <HC_PragmaAttribute*> (result);
      assert (hc_att != NULL);
      cout<<hc_att->toString()<<endl;
  }
}
