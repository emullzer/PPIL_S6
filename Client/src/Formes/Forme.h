//
// Created by mulle1149u on 07/02/2026.
//

#ifndef FORME_H
#define FORME_H
#include <iostream>
#include <string>


class Forme {
protected:
    std::string color;
public:
    virtual ~Forme() = default;

    virtual void dessiner() const = 0;
    virtual explicit operator std::string() const =0;
};



#endif //FORME_H
