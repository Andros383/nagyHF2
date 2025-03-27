#ifndef WIRE_H
#define WIRE_H
class Wire {
    int input;
    int output;

   public:
    Wire() {};
    // még nem tudom kell-e destructolni
    virtual ~Wire() {};
};
#endif