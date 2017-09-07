#include "stdafx.h"
#include "Bible.h"

Bible& Bible::getInstance() {
    static Bible instance;
    return instance;
}

Bible::Bible() {

}
