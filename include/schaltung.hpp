#pragma once
#include "schnittstelle.hpp"
#include "baustein.hpp"
#include <vector>
class Schaltung : Baustein
{
protected:
    std::vector<Baustein*> bausteine {};
    std::vector<Schnittstelle*> intern {};
};
