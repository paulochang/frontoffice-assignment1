#include "Swap.h"


double Swap::price() {

    return this->theReceiver->price() - this->thePayer->price();

}
