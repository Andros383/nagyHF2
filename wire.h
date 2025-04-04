#ifndef WIRE_H
#define WIRE_H
class Wire {
    int input;
    int output;

   public:
    Wire() {};
    // még nem tudom kell-e destructolni
    virtual ~Wire() {};
    int get_input() {
        return input;
    }
    // lehessen felülírni?
    virtual void tick();
    Wire& operator=(const Wire& w);
};
#endif