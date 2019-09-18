#include "dpushbutton.h"


void DPushButton::pushed(){

    emit iChanged(this);
}
