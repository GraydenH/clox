//
//  main.c
//  clox
//
//  Created by Hormes, Grayden on 2019-11-29.
//  Copyright © 2019 Hormes, Grayden. All rights reserved.
//

#include "common.h"
#include "chunk.h"
#include "debug.h"
#include "vm.h"

int main(int argc, const char* argv[]) {
	VM vm;
	initVM(&vm);
	
  Chunk chunk;
  initChunk(&chunk);
  
  int constant = addConstant(&chunk, 1.2);
	writeChunk(&chunk, OP_CONSTANT, 123);
  writeChunk(&chunk, constant, 123);
	
  constant = addConstant(&chunk, 3.4);
  writeChunk(&chunk, OP_CONSTANT, 123);
  writeChunk(&chunk, constant, 123);

  writeChunk(&chunk, OP_ADD, 123);

  constant = addConstant(&chunk, 5.6);
  writeChunk(&chunk, OP_CONSTANT, 123);
  writeChunk(&chunk, constant, 123);

  writeChunk(&chunk, OP_DIVIDE, 123);
	writeChunk(&chunk, OP_NEGATE, 123);

  writeChunk(&chunk, OP_RETURN, 123);
	
	interpret(&vm, &chunk);
	
	freeVM(&vm);
  freeChunk(&chunk); 
  
  return 0;
}
