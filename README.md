# CS201-Template
Getting started for LLVM pass writing

## Code Explanation 
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
8. Implementation of ``runOnFunction(Function &F)`` looks as following in whole.  
```c++
string func_name = "test";
bool runOnFunction(Function &F) override {
	errs() << "ValueNumbering: ";
	errs() << F.getName() << "\n";
	if (F.getName() != func_name) return false;
	for (auto& basic_block : F)
	{
		for (auto& inst : basic_block)
		{
			errs() << inst << "\n";
			auto* ptr = dyn_cast<User>(&inst);
			for (auto it = ptr->op_begin(); it != ptr->op_end(); ++it) 
			{
				errs() << "\t" << *(*it) << "\n";
			}
		}
	}
	return false;
}
```