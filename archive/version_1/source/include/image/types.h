//
//  Created by Jaime Rios
//  Copyright © 2021 jaimerios.com. All rights reserved.
//

#pragma once

#include <cstdint>
#include <vector>

using pixels_wide_t = std::uint32_t;
using pixels_high_t = std::uint32_t;
using point_t = std::uint32_t;

// compilers love 1d vec's for vectorization
template <typename T>
using vec_1d = std::vector<T>;
