//
//  compiler.c
//  clox
//
//  Created by Hormes, Grayden on 2019-11-30.
//  Copyright © 2019 Hormes, Grayden. All rights reserved.
//

#include <stdio.h>

#include "common.h"
#include "compiler.h"
#include "scanner.h"

void compile(const char* source) {
	Scanner scanner;
  initScanner(&scanner, source);
	
	int line = -1;
	 for (;;) {
		 Token token = scanToken(&scanner);
		 if (token.line != line) {
			 printf("%4d ", token.line);
			 line = token.line;
		 } else {
			 printf("   | ");
		 }
		 printf("%2d '%.*s'\n", token.type, token.length, token.start);

		 if (token.type == TOKEN_EOF) break;
	 }
}
