#include "llvm/Pass.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Function.h"
#include "llvm/Support/raw_ostream.h"
#include <string>
#include <fstream>
#include <unordered_map>
#include <set>
#include <queue>

using namespace llvm;
using namespace std;

#define DEBUG_TYPE "CSElimination"

struct CSElimination : public FunctionPass
{
  static char ID;
  CSElimination() : FunctionPass(ID) {}

  bool runOnFunction(Function &F) override
  {
    
    return true; // Indicate this is a Transform pass
  }
}; // end of struct CSElimination
} // end of anonymous namespace

char CSElimination::ID = 0;
static RegisterPass<CSElimination> X("CSElimination", "CSElimination Pass",
                                      false /* Only looks at CFG */,
                                      true /* Tranform Pass */);
