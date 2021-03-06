//
//  chunk.h
//  clox
//
//  Created by Hormes, Grayden on 2019-11-29.
//  Copyright © 2019 Hormes, Grayden. All rights reserved.
//

#ifndef chunk_h
#define chunk_h

#include "common.h"
#include "value.h"

typedef enum {
  OP_CONSTANT,
  OP_NIL,
  OP_TRUE,
  OP_FALSE,
  OP_EQUAL,
  OP_GREATER,
  OP_LESS,
	OP_ADD,
  OP_SUBTRACT,
  OP_MULTIPLY,
  OP_DIVIDE,
	OP_NOT,
  OP_NEGATE,
	OP_POP,
	OP_DEFINE_GLOBAL,
	OP_GET_GLOBAL,
  OP_SET_GLOBAL,
	OP_GET_LOCAL,
	OP_SET_LOCAL,
	OP_JUMP_IF_FALSE,
	OP_JUMP,
	OP_LOOP,
	OP_PRINT,
  OP_RETURN,
} OpCode;

typedef struct {
  int offset;
  int line;
} LineStart;

typedef struct {
  int count;
  int capacity;
  uint8_t* code;
  ValueArray constants;
  int lineCount;
  int lineCapacity;
  LineStart* lines;
} Chunk;

void initChunk(Chunk* chunk);
void freeChunk(Chunk* chunk);
void writeChunk(Chunk* chunk, uint8_t byte, int line);
int addConstant(Chunk* chunk, Value value);
int getLine(Chunk* chunk, int instruction);

#endif /* chunk_h */
