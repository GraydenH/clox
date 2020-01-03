//
//  vm.h
//  clox
//
//  Created by Hormes, Grayden on 2019-11-29.
//  Copyright © 2019 Hormes, Grayden. All rights reserved.
//

#ifndef vm_h
#define vm_h

#include "chunk.h"
#include "table.h"
#include "value.h"

#define STACK_MAX 256

typedef struct {
  Chunk* chunk;
	uint8_t* ip;
  Value stack[STACK_MAX];
  Value* stackTop;
  Table strings;
	
  Obj* objects;   
} VM;

extern VM vm;

typedef enum {
  INTERPRET_OK,
  INTERPRET_COMPILE_ERROR,
  INTERPRET_RUNTIME_ERROR
} InterpretResult;


void initVM(void);
void freeVM(void);
void push(Value value);
Value pop(void);
InterpretResult interpret(const char* source);

#endif /* vm_h */
