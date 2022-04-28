#ifndef SCHALTUNG_HPP_
#define SCHALTUNG_HPP_
#include "schnittstelle.hpp"
#include "baustein.hpp"
#include <vector>
class Schaltung : public Baustein
{
protected:
    std::vector<Baustein*> baustein {};
    std::vector<Schnittstelle*> intern {};
};
#endif
