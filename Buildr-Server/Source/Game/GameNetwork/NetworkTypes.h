#pragma once

#include "json.hpp"

namespace NetworkTypes {

    typedef struct {
        float x;
        float y;
        float r;
    } PlayerTransform;

    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(PlayerTransform, x, y, r);

}
