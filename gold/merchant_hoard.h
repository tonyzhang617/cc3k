#ifndef MERCHANT_HOARD_H
#define MERCHANT_HOARD_H
#include "gold.h"

class MerchantHoard : public Gold{
public:
  MerchantHoard(int x, int y, Grid *grid);
};

#endif
