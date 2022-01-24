#ifndef MOVINGTFMINIMEASURE_H
#define MOVINGTFMINIMEASURE_H


class MovingTFMiniMeasure{
 public:
    MovingTFMiniMeasure(uint8_t angle, uint16_t distance, uint16_t strength )
    {
        this->angle = angle;
        this->distance = distance;
        this->strength = strength;

    }
    uint8_t get_angle(){
        return this->angle;
    }
    uint16_t get_distance(){
        return this->distance;
    }
    uint16_t get_strenght(){
        return this->strength;
    }

 private:
    uint8_t angle;
    uint16_t distance;
    uint16_t strength;
};
#endif
