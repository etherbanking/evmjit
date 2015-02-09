#pragma once
#include "CompilerHelper.h"

namespace dev
{
namespace eth
{
namespace jit
{
class RuntimeManager;

class Stack : public CompilerHelper
{
public:
	Stack(llvm::IRBuilder<>& builder, RuntimeManager& runtimeManager);

	llvm::Value* get(size_t _index);
	void set(size_t _index, llvm::Value* _value);
	void pop(size_t _count);
	void push(llvm::Value* _value);

	static size_t maxStackSize;

private:
	llvm::Function* getPopFunc();
	llvm::Function* getGetFunc();

	RuntimeManager& m_runtimeManager;

	llvm::Function* m_pop = nullptr;
	llvm::Function* m_push;
	llvm::Function* m_get = nullptr;
	llvm::Function* m_set;

	llvm::Value* m_arg;
};


}
}
}


