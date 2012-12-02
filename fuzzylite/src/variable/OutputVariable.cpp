/*
 * OutputVariable.cpp
 *
 *  Created on: 2/12/2012
 *      Author: jcrada
 */

#include "OutputVariable.h"

#include "../term/Cumulative.h"
#include "../defuzzifier/Defuzzifier.h"

#include <sstream>

namespace fl {

OutputVariable::OutputVariable(const std::string& name)
		: Variable(name), _output(new Cumulative("output")) {
}

OutputVariable::~OutputVariable() {
	delete _output;
}

void OutputVariable::setDefaultValue(scalar defaultValue) {
	this->_defaultValue = defaultValue;
}

scalar OutputVariable::getDefaultValue() const {
	return this->_defaultValue;
}

void OutputVariable::setDefuzzifier(Defuzzifier* defuzzifier) {
	this->_defuzzifier = defuzzifier;
}

Defuzzifier* OutputVariable::getDefuzzifier() const{
	return this->_defuzzifier;
}

Cumulative* OutputVariable::output() const{
	return this->_output;
}

scalar OutputVariable::defuzzify() const{
	return this->_defuzzifier->defuzzify(this->_output);
}

std::string OutputVariable::toString() const{
	std::stringstream ss;
	ss << "OutputVariable(" << _name << ")";
	return ss.str();
}

} /* namespace fl */