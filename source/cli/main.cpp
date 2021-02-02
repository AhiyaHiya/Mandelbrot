//
//  Created by Jaime Rios on 2021-02-01
//  Copyright © 2021 jaimerios.com. All rights reserved.
//

#include <future>
#include <iostream>
#include <memory>

#include "mandelbrot/mandelbrot.h"

////////////////////////////////////////////////////////////////
void exercise_mandelbrot()
{
  printf("Function: %s\tLine: %d\n", __FUNCTION__, __LINE__);

  const auto width  = 1024.0f * 1.5f;
  const auto height = 768.0f * 1.5f;

  const auto x_min = -2.0;
  const auto x_max = +0.5;
  const auto y_max = +1.0;
  const auto y_min = -1.0;

  auto pixels = jaimerios::create_vec_1d_filled_with_mandelbrot_pixels<uint8_t>(x_max, x_min, y_max, y_min, width, height);
  (void)pixels;
}

////////////////////////////////////////////////////////////////
int main(int, char **)
{
  std::cout << "Hello to shared_ptr examples\n";

  exercise_mandelbrot();
}
