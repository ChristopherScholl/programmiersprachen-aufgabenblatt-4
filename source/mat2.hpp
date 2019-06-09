# ifndef MAT2_HPP
# define MAT2_HPP

// Mat2 definition
# include <array >
# include "vec2.hpp"

struct Mat2 
{
  // matrix layout :
  // e_00 e_10
  // e_01 e_11
  float e_00 = 1.0f;
  float e_10 = 0.0f;
  float e_01 = 0.0f;
  float e_11 = 1.0f;

  float det() const;
  Mat2& operator *=(Mat2 const& m);
};

Mat2 operator *(Mat2 const& m1, Mat2 const& m2);
Vec2 operator *(Mat2 const& m, Vec2 const& v);
Vec2 operator *(Vec2 const& v, Mat2 const& m);
Mat2 inverse(Mat2 const& m);
Mat2 transpose(Mat2 const& m);
Mat2 make_rotation_mat2(float phi);

# endif // MAT2_HPP