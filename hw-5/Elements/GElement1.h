#ifndef GELEMENT1_H
#define GELEMENT1_H

#include "IGElement.h"

class GElement1 : public IGElement
{
public:
    GElement1();
    ~GElement1();

    void paint() override;
    void erase() override;
    std::string serialize() override;
    void unserialize(const std::string &data) override;
};

#endif // GELEMENT1_H
