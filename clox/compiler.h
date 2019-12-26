//
//  compiler.h
//  clox
//
//  Created by Hormes, Grayden on 2019-11-30.
//  Copyright © 2019 Hormes, Grayden. All rights reserved.
//

#ifndef compiler_h
#define compiler_h

#include "vm.h"
#include "object.h"

bool compile(const char* source, Chunk* chunk);

#endif /* compiler_h */
