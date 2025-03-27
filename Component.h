#ifndef COMPONENT_H
#define COMPONENT_H
class Component {
   public:
    char* label;
    Component() {};
    virtual void store_input() = 0;
    virtual void push_output() = 0;
    virtual ~Component() {};
};
#endif