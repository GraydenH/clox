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
#include "value.h"

#define STACK_MAX 256

typedef struct {
  Chunk* chunk;
	uint8_t* ip;
  Value stack[STACK_MAX];
  Value* stackTop;
} VM;

typedef enum {
  INTERPRET_OK,
  INTERPRET_COMPILE_ERROR,
  INTERPRET_RUNTIME_ERROR
} InterpretResult;


void initVM(VM* vm);
void freeVM(VM* vm);
void push(VM* vm, Value value);
Value pop(VM* vm);
InterpretResult interpret(VM* vm, Chunk* chunk);

#endif /* vm_h */
