#ifndef WORLDPOINT_H
#define WORLDPOINT_H

namespace grupp20{

    class WorldPoint{
    public:
        WorldPoint(const float x, const float y) : x(&x), y(&y) {}
        ~WorldPoint();
    private:
        const float* x;
        const float* y;
    };
}

#endif