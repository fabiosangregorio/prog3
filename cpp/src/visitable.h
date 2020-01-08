#ifndef VISITABLE_H_
#define VISITABLE_H_

#include "visitor.h"

class Visitor;

class Visitable {
public:
	virtual ~Visitable() {}
	virtual void accept (Visitor* visitor) = 0;
};

#endif /* VISITABLE_H_ */
