#pragma once
#include "schnittstelle.hpp"
#include "baustein.hpp"
#include <vector>
class Schaltung : Baustein
{
protected:
    std::vector<Baustein*> baustein {};
    std::vector<Schnittstelle*> intern {};
};
