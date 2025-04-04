#ifndef COMPONENT_H
#define COMPONENT_H
#include <string>

#include "wire.h"
class Component {
    std::string label;
    Wire** inputs;
    size_t inputs_len;
    Wire* output;

   public:
    Component() {};
    virtual void calculate_output();
    void send_output();
    virtual ~Component() {};
};
#endif