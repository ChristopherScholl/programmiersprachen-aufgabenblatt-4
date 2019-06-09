#include "window.hpp"
#include "vec2.hpp"
#include "mat2.hpp"
#include "rectangle.hpp"
#include "rectangle.cpp"
#include "circle.hpp"
#include "circle.cpp"

#include <GLFW/glfw3.h>
#include <utility>
#include <cmath>
#include <iostream>


int main(int argc, char* argv[])
{
  Window win{std::make_pair(500,500)};

  while (!win.should_close()) {
    if (win.get_key(GLFW_KEY_ESCAPE) == GLFW_PRESS) {
      win.close();
    }

    bool left_pressed = win.get_mouse_button(GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS;

    auto t = win.get_time();

    auto mouse_position = win.mouse_position();
    if (left_pressed) {
      win.draw_line(30.0f, 30.0f, // FROM pixel idx with coords (x=30, y=30)
                    mouse_position.first, mouse_position.second, // TO mouse position in pixel coords
                    1.0,0.0,0.0, // color with r,g,b in [0.0, 1.0]
                    1.0);        // line thickness = 1.0 * default thickness
    }

    Vec2 mid{ 250.0,225.0 };
    Color white{ 1.0,1.0,1.0 };
    Color red{ 1.0,0.0,0.0 };
    Color black{ 0.0,0.0,0.0 };

    Vec2 mouse{ mouse_position.first, mouse_position.second };
    Circle2 cir(mid, 200.0, white);
    if (cir.is_inside(mouse)) {
      cir.draw(win, 2.0);
    }
    else {
      cir.draw(win, 1.0);
    }

    //std::cout << t << std::endl;
    int h = (int)t / (60 * 60);
    int m = ((int)t) / 60 - h * 60;
    int s = (int)t - h * 60 * 60 - m * 60;
    h = h % 12;
    m = m % 60;
    s = s % 60;

    std::cout << "Time: " << t << " Hours: " << h << " Minutes: " << m << " Seconds: " << s << std::endl;
    float hr_x = (150.0) * sin(6.28318530718 / 12 * h) + mid.x_;
    float hr_y = (150.0) * -cos(6.28318530718 / 12 * h) + mid.y_;
    win.draw_line(250.0f, 250.0f, hr_x, hr_y + 25.0f, 0.0, 0.0, 0.0, 5.0);

    float min_x = (200.0) * sin(6.28318530718 / 60 * m) + mid.x_;
    float min_y = (200.0) * -cos(6.28318530718 / 60 * m) + mid.y_;
    win.draw_line(250.0f, 250.0f, min_x, min_y + 25.0f, 0.0, 0.0, 0.0, 3.0);

    float sec_x = (200.0) * sin(6.28318530718 / 60 * s) + mid.x_;
    float sec_y = (200.0) * -cos(6.28318530718 / 60 * s) + mid.y_;
    win.draw_line(250.0f, 250.0f, sec_x, sec_y + 25.0f, 1.0, 0.0, 0.0, 1.0);

    win.update();
  }

  return 0;
}
