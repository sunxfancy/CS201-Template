#include "llvm/Pass.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Function.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/IR/Type.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/Instruction.h"
#include "llvm/IR/CFG.h"
#include <string>

using namespace llvm;
using namespace std;

#define DEBUG_TYPE "HelloPass"

namespace
{
  struct HelloPass : public FunctionPass
  {
    static char ID;
    HelloPass() : FunctionPass(ID) {}

    bool runOnFunction(Function &F) override
    {
      errs() << "HelloPass runOnFunction: ";
      errs() << F.getName() << "\n";

      for (auto &basic_block : F)
      {
        for (auto &inst : basic_block)
        {
          errs() << inst << "\n";
          if (inst.getOpcode() == Instruction::Load)
          {
            errs() << "This is Load"
                   << "\n";
          }
          if (inst.getOpcode() == Instruction::Store)
          {
            errs() << "This is Store"
                   << "\n";
          }
          if (inst.isBinaryOp())
          {
            errs() << "Op Code:" << inst.getOpcodeName() << "\n"; 
            if (inst.getOpcode() == Instruction::Add)
            {
              errs() << "This is Addition"
                     << "\n";
            }
            if (inst.getOpcode() == Instruction::Sub)
            {
              errs() << "This is Subtraction"
                     << "\n";
            }
            if (inst.getOpcode() == Instruction::Mul)
            {
              errs() << "This is Multiplication"
                     << "\n";
            }
            if (inst.getOpcode() == Instruction::SDiv)
            {
              errs() << "This is Division"
                     << "\n";
            }

            // See Other classes, Instruction::Sub, Instruction::UDiv, Instruction::SDiv
            auto *ptr = dyn_cast<User>(&inst);
            for (auto it = ptr->op_begin(); it != ptr->op_end(); ++it)
            {
              errs() << "\t" << *(*it) << "\n";
            }
          }
        }
        errs() << "predecessors:";
        for (auto *pred: predecessors(&basic_block)) {
          // get all predecessors of the current basic block
          errs() << " " << pred->getName();
        }
        errs() << "\n";
        errs() << "successors:";
        for (auto *succ: successors(&basic_block)) {
          // get all successors of the current basic block
          errs() << " " << succ->getName();
        }
        errs() << "\n";
      }
      return false;
    }
  }; // end of Hello pass
} // end of anonymous namespace

char HelloPass::ID = 0;
static RegisterPass<HelloPass> X("Hello", "Hello Pass",
                                 false /* Only looks at CFG */,
                                 false /* Analysis Pass */);