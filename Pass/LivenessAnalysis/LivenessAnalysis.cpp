#include "llvm/Pass.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Function.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/IR/Type.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/Instruction.h"
#include "llvm/IR/CFG.h"
#include <string>
#include <fstream>
#include <unordered_map>
#include <set>
#include <queue>

using namespace llvm;
using namespace std;

#define DEBUG_TYPE "LivenessAnalysis"

namespace
{
struct LivenessAnalysis : public FunctionPass
{
  static char ID;
  LivenessAnalysis() : FunctionPass(ID) {}

  bool runOnFunction(Function &F) override
  {
    errs() << "LivenessAnalysis: ";
    errs() << F.getName() << "\n";

    return false;
  }
}; // end of struct LivenessAnalysis
} // end of anonymous namespace

char LivenessAnalysis::ID = 0;
static RegisterPass<LivenessAnalysis> X("LivenessAnalysis", "LivenessAnalysis Pass",
                                      false /* Only looks at CFG */,
                                      false /* Analysis Pass */);
