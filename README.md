# CS201-Template
This template is prepared for all three projects: HelloPass, LivenessAnalysis and Common subexpression elimination.

LLVM folder is used for installing LLVM, and you can read the instructions in its ![Readme](LLVM/README.md).
Pass folder contains all three passes for those 3 projects.
test folder contains the example input/output for those 3 projects. For example, ![1.ll](test/phase2/1.ll) is the input file and ![1.out](test/phase2/1.out) is the output.

In phase2/phase3 test folder, there are two scripts: ![create_input.sh](test/phase2/create_input.sh) and ![test.sh](test/phase2/test.sh). `create_input.sh` can generate new input files from C source code and `test.sh` can easily run your pass using `opt` tool. For example, if you have 1.c as the source code.

```sh
cd test/phase2
sh create_input.sh 1    # this will generate 1.ll for pass input
sh test.sh 1            # this will run LivenessAnalysis pass and generate 1.out as the result (of course you need to implement the pass first)
```


## Pass/HelloPass Code Explanation 
1. The implemented Pass extends from ``FunctionPass`` class and overrides ``runOnFunction(Function &F)`` function.
2. ``runOnFunction(Function &F)`` function gets called the number of times as many number of functions are present in test code. Name of the function is available using following code snippet. 
```c++
bool runOnFunction(Function &F) override {
	F.getName();
}
```
3. We can iterate over basic blocks of the given function as:
```c++
bool runOnFunction(Function &F) override {
	for (auto& basic_block : F)
	{
		...
	}
}
```
4. Next, we can iterate over the instructions in a basic block (BB). **Note:** instructions are in LLVM IR.
```c++
bool runOnFunction(Function &F) override {
	for (auto& basic_block : F)
	{
		for (auto& inst : basic_block)
		{
			...
		}
	}
}
```
5. Once we get an instruction, then we can cast it as ``User`` and iterate over operands of that instruction. 
```c++
auto* ptr = dyn_cast<User>(&inst);
for (auto it = ptr->op_begin(); it != ptr->op_end(); ++it) 
{
...
}
```
6. Use Following API to check whether instruction is a binary operation (Assignment)
```c++
if (inst.isBinaryOp())
{
	...
}
```
7. Use Following APIs to compare and find operator types
```c++
if (inst.isBinaryOp())
{
	inst.getOpcodeName(); //prints OpCode by name such as add, mul etc.
	if(inst.getOpcode() == Instruction::Add)
	{
		errs() << "This is Addition"<<"\n";
	}
	if(inst.getOpcode() == Instruction::Mul)
	{
		errs() << "This is Multiplication"<<"\n";
	}
    // See Other classes Instruction::Sub, Instruction::UDiv, Instruction::SDiv
}
```
8. `predecessors` and `successors` of a basic block can be easily found by calling those APIs:
```c++
bool runOnFunction(Function &F) override {
	for (auto& basic_block : F)
	{
		for (auto *pred: predecessors(&basic_block)) {
		}
		for (auto *succ: successors(&basic_block)) {
		}
	}
	return false;
}
9. 
```