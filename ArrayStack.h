#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include <string>
#include "Stack.h"

class ArrayStack : public Stack{
private:
	string* array;
	int size;
	int availPos;
public:
	ArrayStack(int);
	virtual bool push(string);
	virtual string pop();
	virtual bool isEmpty();
	string posicion(int);
	void sustitucion(string , int );
	~ArrayStack();
};
#endif
