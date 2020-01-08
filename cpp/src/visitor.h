#ifndef VISITOR_H_
#define VISITOR_H_

class Stipendiato;
class Salariato;
class Reperibile;
class Stagista;

template <typename ReturnType>
class ReturnVisitor;

class Visitor {
public:
	virtual ~Visitor() {}
	virtual void visit (Stipendiato*) = 0;
	virtual void visit (Salariato*) = 0;
	virtual void visit (Reperibile*) = 0;
	virtual void visit (Stagista*) = 0;
};

template <typename ReturnType>
class ReturnVisitor: public Visitor {
public:
	ReturnType const& getValue() { return value; }

protected:
	void setValue(ReturnType const& value) { this->value = value; }

private:
	ReturnType value;
};



#endif /* VISITOR_H_ */
