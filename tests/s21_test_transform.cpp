#include "s21_test_main.h"

namespace s21 {

TEST(TransformSuite, IncorrectActions) {
  Object* instance = PrototypeFactory::createSkeleton();
  EXPECT_NO_THROW(instance->parse("tests/test_obj/regular.obj"));
  EXPECT_EQ(instance->getVerticesSize(), 10);
  EXPECT_EQ(instance->getFacesSize(), 12);
  EXPECT_DEATH(instance->transformData(ROTATE, ALL, 10.0), "");
  delete instance;
}

TEST(TransformSuite, ShiftActions) {
  Object* instance = PrototypeFactory::createSkeleton();
  EXPECT_NO_THROW(instance->parse("tests/test_obj/regular.obj"));
  EXPECT_EQ(instance->getVerticesSize(), 10);
  EXPECT_EQ(instance->getFacesSize(), 12);
  instance->transformData(SHIFT, Y, +10.0);
  EXPECT_NEAR(instance->getVerticesData()[0].x, -0.068597, EPS);
  EXPECT_NEAR(instance->getVerticesData()[0].y, 12.260834, EPS);
  EXPECT_NEAR(instance->getVerticesData()[0].z, 0.049750, EPS);
  EXPECT_NEAR(instance->getVerticesData()[1].x, -0.068350, EPS);
  EXPECT_NEAR(instance->getVerticesData()[1].y, 12.260834, EPS);
  EXPECT_NEAR(instance->getVerticesData()[1].z, 0.054760, EPS);
  EXPECT_NEAR(instance->getVerticesData()[2].x, -0.043352, EPS);
  EXPECT_NEAR(instance->getVerticesData()[2].y, 12.260834, EPS);
  EXPECT_NEAR(instance->getVerticesData()[2].z, 0.024505, EPS);
  EXPECT_NEAR(instance->getVerticesData()[3].x, -0.038342, EPS);
  EXPECT_NEAR(instance->getVerticesData()[3].y, 12.260834, EPS);
  EXPECT_NEAR(instance->getVerticesData()[3].z, 0.024751, EPS);
  EXPECT_NEAR(instance->getVerticesData()[4].x, -0.063479, EPS);
  EXPECT_NEAR(instance->getVerticesData()[4].y, 12.260834, EPS);
  EXPECT_NEAR(instance->getVerticesData()[4].z, 0.049246, EPS);
  EXPECT_NEAR(instance->getVerticesData()[5].x, -0.062496, EPS);
  EXPECT_NEAR(instance->getVerticesData()[5].y, 12.260834, EPS);
  EXPECT_NEAR(instance->getVerticesData()[5].z, 0.054183, EPS);
  EXPECT_NEAR(instance->getVerticesData()[6].x, -0.058793, EPS);
  EXPECT_NEAR(instance->getVerticesData()[6].y, 12.260834, EPS);
  EXPECT_NEAR(instance->getVerticesData()[6].z, 0.047825, EPS);
  EXPECT_NEAR(instance->getVerticesData()[7].x, -0.056867, EPS);
  EXPECT_NEAR(instance->getVerticesData()[7].y, 12.260834, EPS);
  EXPECT_NEAR(instance->getVerticesData()[7].z, 0.052476, EPS);
  EXPECT_NEAR(instance->getVerticesData()[8].x, -0.054475, EPS);
  EXPECT_NEAR(instance->getVerticesData()[8].y, 12.260834, EPS);
  EXPECT_NEAR(instance->getVerticesData()[8].z, 0.045517, EPS);
  EXPECT_NEAR(instance->getVerticesData()[9].x, -0.051679, EPS);
  EXPECT_NEAR(instance->getVerticesData()[9].y, 12.260834, EPS);
  EXPECT_NEAR(instance->getVerticesData()[9].z, 0.049702, EPS);

  instance->transformData(SHIFT, X, -0.002);
  EXPECT_NEAR(instance->getVerticesData()[0].x, -0.070597, EPS);
  EXPECT_NEAR(instance->getVerticesData()[0].y, 12.260834, EPS);
  EXPECT_NEAR(instance->getVerticesData()[0].z, 0.049750, EPS);
  EXPECT_NEAR(instance->getVerticesData()[1].x, -0.070350, EPS);
  EXPECT_NEAR(instance->getVerticesData()[1].y, 12.260834, EPS);
  EXPECT_NEAR(instance->getVerticesData()[1].z, 0.054760, EPS);
  EXPECT_NEAR(instance->getVerticesData()[2].x, -0.045352, EPS);
  EXPECT_NEAR(instance->getVerticesData()[2].y, 12.260834, EPS);
  EXPECT_NEAR(instance->getVerticesData()[2].z, 0.024505, EPS);
  EXPECT_NEAR(instance->getVerticesData()[3].x, -0.040342, EPS);
  EXPECT_NEAR(instance->getVerticesData()[3].y, 12.260834, EPS);
  EXPECT_NEAR(instance->getVerticesData()[3].z, 0.024751, EPS);
  EXPECT_NEAR(instance->getVerticesData()[4].x, -0.065479, EPS);
  EXPECT_NEAR(instance->getVerticesData()[4].y, 12.260834, EPS);
  EXPECT_NEAR(instance->getVerticesData()[4].z, 0.049246, EPS);
  EXPECT_NEAR(instance->getVerticesData()[5].x, -0.064496, EPS);
  EXPECT_NEAR(instance->getVerticesData()[5].y, 12.260834, EPS);
  EXPECT_NEAR(instance->getVerticesData()[5].z, 0.054183, EPS);
  EXPECT_NEAR(instance->getVerticesData()[6].x, -0.060793, EPS);
  EXPECT_NEAR(instance->getVerticesData()[6].y, 12.260834, EPS);
  EXPECT_NEAR(instance->getVerticesData()[6].z, 0.047825, EPS);
  EXPECT_NEAR(instance->getVerticesData()[7].x, -0.058867, EPS);
  EXPECT_NEAR(instance->getVerticesData()[7].y, 12.260834, EPS);
  EXPECT_NEAR(instance->getVerticesData()[7].z, 0.052476, EPS);
  EXPECT_NEAR(instance->getVerticesData()[8].x, -0.056475, EPS);
  EXPECT_NEAR(instance->getVerticesData()[8].y, 12.260834, EPS);
  EXPECT_NEAR(instance->getVerticesData()[8].z, 0.045517, EPS);
  EXPECT_NEAR(instance->getVerticesData()[9].x, -0.053679, EPS);
  EXPECT_NEAR(instance->getVerticesData()[9].y, 12.260834, EPS);
  EXPECT_NEAR(instance->getVerticesData()[9].z, 0.049702, EPS);

  instance->transformData(SHIFT, Z, 900.213);
  EXPECT_NEAR(instance->getVerticesData()[0].x, -0.070597, EPS);
  EXPECT_NEAR(instance->getVerticesData()[0].y, 12.260834, EPS);
  EXPECT_NEAR(instance->getVerticesData()[0].z, 0.049750 + 900.213, EPS);
  EXPECT_NEAR(instance->getVerticesData()[1].x, -0.070350, EPS);
  EXPECT_NEAR(instance->getVerticesData()[1].y, 12.260834, EPS);
  EXPECT_NEAR(instance->getVerticesData()[1].z, 0.054760 + 900.213, EPS);
  EXPECT_NEAR(instance->getVerticesData()[2].x, -0.045352, EPS);
  EXPECT_NEAR(instance->getVerticesData()[2].y, 12.260834, EPS);
  EXPECT_NEAR(instance->getVerticesData()[2].z, 0.024505 + 900.213, EPS);
  EXPECT_NEAR(instance->getVerticesData()[3].x, -0.040342, EPS);
  EXPECT_NEAR(instance->getVerticesData()[3].y, 12.260834, EPS);
  EXPECT_NEAR(instance->getVerticesData()[3].z, 0.024751 + 900.213, EPS);
  EXPECT_NEAR(instance->getVerticesData()[4].x, -0.065479, EPS);
  EXPECT_NEAR(instance->getVerticesData()[4].y, 12.260834, EPS);
  EXPECT_NEAR(instance->getVerticesData()[4].z, 0.049246 + 900.213, EPS);
  EXPECT_NEAR(instance->getVerticesData()[5].x, -0.064496, EPS);
  EXPECT_NEAR(instance->getVerticesData()[5].y, 12.260834, EPS);
  EXPECT_NEAR(instance->getVerticesData()[5].z, 0.054183 + 900.213, EPS);
  EXPECT_NEAR(instance->getVerticesData()[6].x, -0.060793, EPS);
  EXPECT_NEAR(instance->getVerticesData()[6].y, 12.260834, EPS);
  EXPECT_NEAR(instance->getVerticesData()[6].z, 0.047825 + 900.213, EPS);
  EXPECT_NEAR(instance->getVerticesData()[7].x, -0.058867, EPS);
  EXPECT_NEAR(instance->getVerticesData()[7].y, 12.260834, EPS);
  EXPECT_NEAR(instance->getVerticesData()[7].z, 0.052476 + 900.213, EPS);
  EXPECT_NEAR(instance->getVerticesData()[8].x, -0.056475, EPS);
  EXPECT_NEAR(instance->getVerticesData()[8].y, 12.260834, EPS);
  EXPECT_NEAR(instance->getVerticesData()[8].z, 0.045517 + 900.213, EPS);
  EXPECT_NEAR(instance->getVerticesData()[9].x, -0.053679, EPS);
  EXPECT_NEAR(instance->getVerticesData()[9].y, 12.260834, EPS);
  EXPECT_NEAR(instance->getVerticesData()[9].z, 0.049702 + 900.213, EPS);
  EXPECT_NEAR(instance->getMaxZ(), 0.054760 + 900.213, EPS);
  delete instance;
}

TEST(TransformSuite, Scale1) {
  Object* instance = PrototypeFactory::createSkeleton();
  EXPECT_NO_THROW(instance->parse("tests/test_obj/regular.obj"));
  EXPECT_EQ(instance->getVerticesSize(), 10);
  EXPECT_EQ(instance->getFacesSize(), 12);
  EXPECT_NEAR(instance->getMaxZ(), 0.054760, EPS);
  instance->transformData(SCALE, ALL, 27.0);
  EXPECT_NEAR(instance->getVerticesData()[0].x, -0.068597 * 27.0, EPS);
  EXPECT_NEAR(instance->getVerticesData()[0].y, 2.260834 * 27.0, EPS);
  EXPECT_NEAR(instance->getVerticesData()[0].z, 0.049750 * 27.0, EPS);
  EXPECT_NEAR(instance->getVerticesData()[1].x, -0.068350 * 27.0, EPS);
  EXPECT_NEAR(instance->getVerticesData()[1].y, 2.260834 * 27.0, EPS);
  EXPECT_NEAR(instance->getVerticesData()[1].z, 0.054760 * 27.0, EPS);
  EXPECT_NEAR(instance->getVerticesData()[2].x, -0.043352 * 27.0, EPS);
  EXPECT_NEAR(instance->getVerticesData()[2].y, 2.260834 * 27.0, EPS);
  EXPECT_NEAR(instance->getVerticesData()[2].z, 0.024505 * 27.0, EPS);
  EXPECT_NEAR(instance->getVerticesData()[3].x, -0.038342 * 27.0, EPS);
  EXPECT_NEAR(instance->getVerticesData()[3].y, 2.260834 * 27.0, EPS);
  EXPECT_NEAR(instance->getVerticesData()[3].z, 0.024751 * 27.0, EPS);
  EXPECT_NEAR(instance->getVerticesData()[4].x, -0.063479 * 27.0, EPS);
  EXPECT_NEAR(instance->getVerticesData()[4].y, 2.260834 * 27.0, EPS);
  EXPECT_NEAR(instance->getVerticesData()[4].z, 0.049246 * 27.0, EPS);
  EXPECT_NEAR(instance->getVerticesData()[5].x, -0.062496 * 27.0, EPS);
  EXPECT_NEAR(instance->getVerticesData()[5].y, 2.260834 * 27.0, EPS);
  EXPECT_NEAR(instance->getVerticesData()[5].z, 0.054183 * 27.0, EPS);
  EXPECT_NEAR(instance->getVerticesData()[6].x, -0.058793 * 27.0, EPS);
  EXPECT_NEAR(instance->getVerticesData()[6].y, 2.260834 * 27.0, EPS);
  EXPECT_NEAR(instance->getVerticesData()[6].z, 0.047825 * 27.0, EPS);
  EXPECT_NEAR(instance->getVerticesData()[7].x, -0.056867 * 27.0, EPS);
  EXPECT_NEAR(instance->getVerticesData()[7].y, 2.260834 * 27.0, EPS);
  EXPECT_NEAR(instance->getVerticesData()[7].z, 0.052476 * 27.0, EPS);
  EXPECT_NEAR(instance->getVerticesData()[8].x, -0.054475 * 27.0, EPS);
  EXPECT_NEAR(instance->getVerticesData()[8].y, 2.260834 * 27.0, EPS);
  EXPECT_NEAR(instance->getVerticesData()[8].z, 0.045517 * 27.0, EPS);
  EXPECT_NEAR(instance->getVerticesData()[9].x, -0.051679 * 27.0, EPS);
  EXPECT_NEAR(instance->getVerticesData()[9].y, 2.260834 * 27.0, EPS);
  EXPECT_NEAR(instance->getVerticesData()[9].z, 0.049702 * 27.0, EPS);
  EXPECT_NEAR(instance->getMaxZ(), 0.054760 * 27.0, EPS);

  instance->transformData(SCALE, ALL, 1.0 / 27.0);
  EXPECT_NEAR(instance->getVerticesData()[0].x, -0.068597, EPS);
  EXPECT_NEAR(instance->getVerticesData()[0].y, 2.260834, EPS);
  EXPECT_NEAR(instance->getVerticesData()[0].z, 0.049750, EPS);
  EXPECT_NEAR(instance->getVerticesData()[1].x, -0.068350, EPS);
  EXPECT_NEAR(instance->getVerticesData()[1].y, 2.260834, EPS);
  EXPECT_NEAR(instance->getVerticesData()[1].z, 0.054760, EPS);
  EXPECT_NEAR(instance->getVerticesData()[2].x, -0.043352, EPS);
  EXPECT_NEAR(instance->getVerticesData()[2].y, 2.260834, EPS);
  EXPECT_NEAR(instance->getVerticesData()[2].z, 0.024505, EPS);
  EXPECT_NEAR(instance->getVerticesData()[3].x, -0.038342, EPS);
  EXPECT_NEAR(instance->getVerticesData()[3].y, 2.260834, EPS);
  EXPECT_NEAR(instance->getVerticesData()[3].z, 0.024751, EPS);
  EXPECT_NEAR(instance->getVerticesData()[4].x, -0.063479, EPS);
  EXPECT_NEAR(instance->getVerticesData()[4].y, 2.260834, EPS);
  EXPECT_NEAR(instance->getVerticesData()[4].z, 0.049246, EPS);
  EXPECT_NEAR(instance->getVerticesData()[5].x, -0.062496, EPS);
  EXPECT_NEAR(instance->getVerticesData()[5].y, 2.260834, EPS);
  EXPECT_NEAR(instance->getVerticesData()[5].z, 0.054183, EPS);
  EXPECT_NEAR(instance->getVerticesData()[6].x, -0.058793, EPS);
  EXPECT_NEAR(instance->getVerticesData()[6].y, 2.260834, EPS);
  EXPECT_NEAR(instance->getVerticesData()[6].z, 0.047825, EPS);
  EXPECT_NEAR(instance->getVerticesData()[7].x, -0.056867, EPS);
  EXPECT_NEAR(instance->getVerticesData()[7].y, 2.260834, EPS);
  EXPECT_NEAR(instance->getVerticesData()[7].z, 0.052476, EPS);
  EXPECT_NEAR(instance->getVerticesData()[8].x, -0.054475, EPS);
  EXPECT_NEAR(instance->getVerticesData()[8].y, 2.260834, EPS);
  EXPECT_NEAR(instance->getVerticesData()[8].z, 0.045517, EPS);
  EXPECT_NEAR(instance->getVerticesData()[9].x, -0.051679, EPS);
  EXPECT_NEAR(instance->getVerticesData()[9].y, 2.260834, EPS);
  EXPECT_NEAR(instance->getVerticesData()[9].z, 0.049702, EPS);
  EXPECT_NEAR(instance->getMaxZ(), 0.054760, EPS);

  instance->transformData(SCALE, ALL, -5.27);
  EXPECT_NEAR(instance->getVerticesData()[0].x, -0.068597 * -5.27, EPS);
  EXPECT_NEAR(instance->getVerticesData()[0].y, 2.260834 * -5.27, EPS);
  EXPECT_NEAR(instance->getVerticesData()[0].z, 0.049750 * -5.27, EPS);
  EXPECT_NEAR(instance->getVerticesData()[1].x, -0.068350 * -5.27, EPS);
  EXPECT_NEAR(instance->getVerticesData()[1].y, 2.260834 * -5.27, EPS);
  EXPECT_NEAR(instance->getVerticesData()[1].z, 0.054760 * -5.27, EPS);
  EXPECT_NEAR(instance->getVerticesData()[2].x, -0.043352 * -5.27, EPS);
  EXPECT_NEAR(instance->getVerticesData()[2].y, 2.260834 * -5.27, EPS);
  EXPECT_NEAR(instance->getVerticesData()[2].z, 0.024505 * -5.27, EPS);
  EXPECT_NEAR(instance->getVerticesData()[3].x, -0.038342 * -5.27, EPS);
  EXPECT_NEAR(instance->getVerticesData()[3].y, 2.260834 * -5.27, EPS);
  EXPECT_NEAR(instance->getVerticesData()[3].z, 0.024751 * -5.27, EPS);
  EXPECT_NEAR(instance->getVerticesData()[4].x, -0.063479 * -5.27, EPS);
  EXPECT_NEAR(instance->getVerticesData()[4].y, 2.260834 * -5.27, EPS);
  EXPECT_NEAR(instance->getVerticesData()[4].z, 0.049246 * -5.27, EPS);
  EXPECT_NEAR(instance->getVerticesData()[5].x, -0.062496 * -5.27, EPS);
  EXPECT_NEAR(instance->getVerticesData()[5].y, 2.260834 * -5.27, EPS);
  EXPECT_NEAR(instance->getVerticesData()[5].z, 0.054183 * -5.27, EPS);
  EXPECT_NEAR(instance->getVerticesData()[6].x, -0.058793 * -5.27, EPS);
  EXPECT_NEAR(instance->getVerticesData()[6].y, 2.260834 * -5.27, EPS);
  EXPECT_NEAR(instance->getVerticesData()[6].z, 0.047825 * -5.27, EPS);
  EXPECT_NEAR(instance->getVerticesData()[7].x, -0.056867 * -5.27, EPS);
  EXPECT_NEAR(instance->getVerticesData()[7].y, 2.260834 * -5.27, EPS);
  EXPECT_NEAR(instance->getVerticesData()[7].z, 0.052476 * -5.27, EPS);
  EXPECT_NEAR(instance->getVerticesData()[8].x, -0.054475 * -5.27, EPS);
  EXPECT_NEAR(instance->getVerticesData()[8].y, 2.260834 * -5.27, EPS);
  EXPECT_NEAR(instance->getVerticesData()[8].z, 0.045517 * -5.27, EPS);
  EXPECT_NEAR(instance->getVerticesData()[9].x, -0.051679 * -5.27, EPS);
  EXPECT_NEAR(instance->getVerticesData()[9].y, 2.260834 * -5.27, EPS);
  EXPECT_NEAR(instance->getVerticesData()[9].z, 0.049702 * -5.27, EPS);
  EXPECT_NEAR(instance->getMaxZ(), 0.0, EPS);

  instance->transformData(SCALE, ALL, 0.002);
  EXPECT_NEAR(instance->getVerticesData()[0].x, -0.068597 * -5.27 * 0.002, EPS);
  EXPECT_NEAR(instance->getVerticesData()[0].y, 2.260834 * -5.27 * 0.002, EPS);
  EXPECT_NEAR(instance->getVerticesData()[0].z, 0.049750 * -5.27 * 0.002, EPS);
  EXPECT_NEAR(instance->getVerticesData()[1].x, -0.068350 * -5.27 * 0.002, EPS);
  EXPECT_NEAR(instance->getVerticesData()[1].y, 2.260834 * -5.27 * 0.002, EPS);
  EXPECT_NEAR(instance->getVerticesData()[1].z, 0.054760 * -5.27 * 0.002, EPS);
  EXPECT_NEAR(instance->getVerticesData()[2].x, -0.043352 * -5.27 * 0.002, EPS);
  EXPECT_NEAR(instance->getVerticesData()[2].y, 2.260834 * -5.27 * 0.002, EPS);
  EXPECT_NEAR(instance->getVerticesData()[2].z, 0.024505 * -5.27 * 0.002, EPS);
  EXPECT_NEAR(instance->getVerticesData()[3].x, -0.038342 * -5.27 * 0.002, EPS);
  EXPECT_NEAR(instance->getVerticesData()[3].y, 2.260834 * -5.27 * 0.002, EPS);
  EXPECT_NEAR(instance->getVerticesData()[3].z, 0.024751 * -5.27 * 0.002, EPS);
  EXPECT_NEAR(instance->getVerticesData()[4].x, -0.063479 * -5.27 * 0.002, EPS);
  EXPECT_NEAR(instance->getVerticesData()[4].y, 2.260834 * -5.27 * 0.002, EPS);
  EXPECT_NEAR(instance->getVerticesData()[4].z, 0.049246 * -5.27 * 0.002, EPS);
  EXPECT_NEAR(instance->getVerticesData()[5].x, -0.062496 * -5.27 * 0.002, EPS);
  EXPECT_NEAR(instance->getVerticesData()[5].y, 2.260834 * -5.27 * 0.002, EPS);
  EXPECT_NEAR(instance->getVerticesData()[5].z, 0.054183 * -5.27 * 0.002, EPS);
  EXPECT_NEAR(instance->getVerticesData()[6].x, -0.058793 * -5.27 * 0.002, EPS);
  EXPECT_NEAR(instance->getVerticesData()[6].y, 2.260834 * -5.27 * 0.002, EPS);
  EXPECT_NEAR(instance->getVerticesData()[6].z, 0.047825 * -5.27 * 0.002, EPS);
  EXPECT_NEAR(instance->getVerticesData()[7].x, -0.056867 * -5.27 * 0.002, EPS);
  EXPECT_NEAR(instance->getVerticesData()[7].y, 2.260834 * -5.27 * 0.002, EPS);
  EXPECT_NEAR(instance->getVerticesData()[7].z, 0.052476 * -5.27 * 0.002, EPS);
  EXPECT_NEAR(instance->getVerticesData()[8].x, -0.054475 * -5.27 * 0.002, EPS);
  EXPECT_NEAR(instance->getVerticesData()[8].y, 2.260834 * -5.27 * 0.002, EPS);
  EXPECT_NEAR(instance->getVerticesData()[8].z, 0.045517 * -5.27 * 0.002, EPS);
  EXPECT_NEAR(instance->getVerticesData()[9].x, -0.051679 * -5.27 * 0.002, EPS);
  EXPECT_NEAR(instance->getVerticesData()[9].y, 2.260834 * -5.27 * 0.002, EPS);
  EXPECT_NEAR(instance->getVerticesData()[9].z, 0.049702 * -5.27 * 0.002, EPS);
  EXPECT_NEAR(instance->getMaxZ(), 0.0, EPS);

  instance->transformData(SCALE, ALL, 0.0);
  EXPECT_NEAR(instance->getVerticesData()[0].x, -0.068597 * -5.27 * 0.002, EPS);
  EXPECT_NEAR(instance->getVerticesData()[0].y, 2.260834 * -5.27 * 0.002, EPS);
  EXPECT_NEAR(instance->getVerticesData()[0].z, 0.049750 * -5.27 * 0.002, EPS);
  EXPECT_NEAR(instance->getVerticesData()[1].x, -0.068350 * -5.27 * 0.002, EPS);
  EXPECT_NEAR(instance->getVerticesData()[1].y, 2.260834 * -5.27 * 0.002, EPS);
  EXPECT_NEAR(instance->getVerticesData()[1].z, 0.054760 * -5.27 * 0.002, EPS);
  EXPECT_NEAR(instance->getVerticesData()[2].x, -0.043352 * -5.27 * 0.002, EPS);
  EXPECT_NEAR(instance->getVerticesData()[2].y, 2.260834 * -5.27 * 0.002, EPS);
  EXPECT_NEAR(instance->getVerticesData()[2].z, 0.024505 * -5.27 * 0.002, EPS);
  EXPECT_NEAR(instance->getVerticesData()[3].x, -0.038342 * -5.27 * 0.002, EPS);
  EXPECT_NEAR(instance->getVerticesData()[3].y, 2.260834 * -5.27 * 0.002, EPS);
  EXPECT_NEAR(instance->getVerticesData()[3].z, 0.024751 * -5.27 * 0.002, EPS);
  EXPECT_NEAR(instance->getVerticesData()[4].x, -0.063479 * -5.27 * 0.002, EPS);
  EXPECT_NEAR(instance->getVerticesData()[4].y, 2.260834 * -5.27 * 0.002, EPS);
  EXPECT_NEAR(instance->getVerticesData()[4].z, 0.049246 * -5.27 * 0.002, EPS);
  EXPECT_NEAR(instance->getVerticesData()[5].x, -0.062496 * -5.27 * 0.002, EPS);
  EXPECT_NEAR(instance->getVerticesData()[5].y, 2.260834 * -5.27 * 0.002, EPS);
  EXPECT_NEAR(instance->getVerticesData()[5].z, 0.054183 * -5.27 * 0.002, EPS);
  EXPECT_NEAR(instance->getVerticesData()[6].x, -0.058793 * -5.27 * 0.002, EPS);
  EXPECT_NEAR(instance->getVerticesData()[6].y, 2.260834 * -5.27 * 0.002, EPS);
  EXPECT_NEAR(instance->getVerticesData()[6].z, 0.047825 * -5.27 * 0.002, EPS);
  EXPECT_NEAR(instance->getVerticesData()[7].x, -0.056867 * -5.27 * 0.002, EPS);
  EXPECT_NEAR(instance->getVerticesData()[7].y, 2.260834 * -5.27 * 0.002, EPS);
  EXPECT_NEAR(instance->getVerticesData()[7].z, 0.052476 * -5.27 * 0.002, EPS);
  EXPECT_NEAR(instance->getVerticesData()[8].x, -0.054475 * -5.27 * 0.002, EPS);
  EXPECT_NEAR(instance->getVerticesData()[8].y, 2.260834 * -5.27 * 0.002, EPS);
  EXPECT_NEAR(instance->getVerticesData()[8].z, 0.045517 * -5.27 * 0.002, EPS);
  EXPECT_NEAR(instance->getVerticesData()[9].x, -0.051679 * -5.27 * 0.002, EPS);
  EXPECT_NEAR(instance->getVerticesData()[9].y, 2.260834 * -5.27 * 0.002, EPS);
  EXPECT_NEAR(instance->getVerticesData()[9].z, 0.049702 * -5.27 * 0.002, EPS);
  EXPECT_NEAR(instance->getMaxZ(), 0.0, EPS);
  delete instance;
}

TEST(TransformSuite, Rotate1) {
  Object* instance = PrototypeFactory::createSkeleton();
  EXPECT_NO_THROW(instance->parse("tests/test_obj/regular.obj"));
  EXPECT_EQ(instance->getVerticesSize(), 10);
  EXPECT_EQ(instance->getFacesSize(), 12);
  EXPECT_NEAR(instance->getMaxZ(), 0.054760, EPS);
  instance->transformData(ROTATE, X, 1.25);
  EXPECT_NEAR(instance->getVerticesData()[0].x, -0.068597, EPS);
  EXPECT_NEAR(instance->getVerticesData()[0].y,
              2.260834 * std::cos(1.25) - 0.049750 * std::sin(1.25), EPS);
  EXPECT_NEAR(instance->getVerticesData()[0].z,
              2.260834 * std::sin(1.25) + 0.049750 * std::cos(1.25), EPS);
  EXPECT_NEAR(instance->getVerticesData()[1].x, -0.068350, EPS);
  EXPECT_NEAR(instance->getVerticesData()[1].y,
              2.260834 * std::cos(1.25) - 0.054760 * std::sin(1.25), EPS);
  EXPECT_NEAR(instance->getVerticesData()[1].z,
              2.260834 * std::sin(1.25) + 0.054760 * std::cos(1.25), EPS);
  EXPECT_NEAR(instance->getVerticesData()[2].x, -0.043352, EPS);
  EXPECT_NEAR(instance->getVerticesData()[2].y,
              2.260834 * std::cos(1.25) - 0.024505 * std::sin(1.25), EPS);
  EXPECT_NEAR(instance->getVerticesData()[2].z,
              2.260834 * std::sin(1.25) + 0.024505 * std::cos(1.25), EPS);
  EXPECT_NEAR(instance->getVerticesData()[3].x, -0.038342, EPS);
  EXPECT_NEAR(instance->getVerticesData()[3].y,
              2.260834 * std::cos(1.25) - 0.024751 * std::sin(1.25), EPS);
  EXPECT_NEAR(instance->getVerticesData()[3].z,
              2.260834 * std::sin(1.25) + 0.024751 * std::cos(1.25), EPS);
  EXPECT_NEAR(instance->getVerticesData()[4].x, -0.063479, EPS);
  EXPECT_NEAR(instance->getVerticesData()[4].y,
              2.260834 * std::cos(1.25) - 0.049246 * std::sin(1.25), EPS);
  EXPECT_NEAR(instance->getVerticesData()[4].z,
              2.260834 * std::sin(1.25) + 0.049246 * std::cos(1.25), EPS);
  EXPECT_NEAR(instance->getVerticesData()[5].x, -0.062496, EPS);
  EXPECT_NEAR(instance->getVerticesData()[5].y,
              2.260834 * std::cos(1.25) - 0.054183 * std::sin(1.25), EPS);
  EXPECT_NEAR(instance->getVerticesData()[5].z,
              2.260834 * std::sin(1.25) + 0.054183 * std::cos(1.25), EPS);
  EXPECT_NEAR(instance->getVerticesData()[6].x, -0.058793, EPS);
  EXPECT_NEAR(instance->getVerticesData()[6].y,
              2.260834 * std::cos(1.25) - 0.047825 * std::sin(1.25), EPS);
  EXPECT_NEAR(instance->getVerticesData()[6].z,
              2.260834 * std::sin(1.25) + 0.047825 * std::cos(1.25), EPS);
  EXPECT_NEAR(instance->getVerticesData()[7].x, -0.056867, EPS);
  EXPECT_NEAR(instance->getVerticesData()[7].y,
              2.260834 * std::cos(1.25) - 0.052476 * std::sin(1.25), EPS);
  EXPECT_NEAR(instance->getVerticesData()[7].z,
              2.260834 * std::sin(1.25) + 0.052476 * std::cos(1.25), EPS);
  EXPECT_NEAR(instance->getVerticesData()[8].x, -0.054475, EPS);
  EXPECT_NEAR(instance->getVerticesData()[8].y,
              2.260834 * std::cos(1.25) - 0.045517 * std::sin(1.25), EPS);
  EXPECT_NEAR(instance->getVerticesData()[8].z,
              2.260834 * std::sin(1.25) + 0.045517 * std::cos(1.25), EPS);
  EXPECT_NEAR(instance->getVerticesData()[9].x, -0.051679, EPS);
  EXPECT_NEAR(instance->getVerticesData()[9].y,
              2.260834 * std::cos(1.25) - 0.049702 * std::sin(1.25), EPS);
  EXPECT_NEAR(instance->getVerticesData()[9].z,
              2.260834 * std::sin(1.25) + 0.049702 * std::cos(1.25), EPS);
  delete instance;
}

TEST(TransformSuite, Rotate2) {
  Object* instance = PrototypeFactory::createSkeleton();
  EXPECT_NO_THROW(instance->parse("tests/test_obj/regular.obj"));
  EXPECT_EQ(instance->getVerticesSize(), 10);
  EXPECT_EQ(instance->getFacesSize(), 12);
  EXPECT_NEAR(instance->getMaxZ(), 0.054760, EPS);
  instance->transformData(ROTATE, Y, -1.25);
  EXPECT_NEAR(instance->getVerticesData()[0].x,
              -0.068597 * cos(-1.25) + 0.049750 * sin(-1.25), EPS);
  EXPECT_NEAR(instance->getVerticesData()[0].y, 2.260834, EPS);
  EXPECT_NEAR(instance->getVerticesData()[0].z,
              0.068597 * sin(-1.25) + 0.049750 * cos(-1.25), EPS);
  EXPECT_NEAR(instance->getVerticesData()[1].x,
              -0.068350 * cos(-1.25) + 0.054760 * sin(-1.25), EPS);
  EXPECT_NEAR(instance->getVerticesData()[1].y, 2.260834, EPS);
  EXPECT_NEAR(instance->getVerticesData()[1].z,
              0.068350 * sin(-1.25) + 0.054760 * cos(-1.25), EPS);
  EXPECT_NEAR(instance->getVerticesData()[2].x,
              -0.043352 * cos(-1.25) + 0.024505 * sin(-1.25), EPS);
  EXPECT_NEAR(instance->getVerticesData()[2].y, 2.260834, EPS);
  EXPECT_NEAR(instance->getVerticesData()[2].z,
              0.043352 * sin(-1.25) + 0.024505 * cos(-1.25), EPS);
  EXPECT_NEAR(instance->getVerticesData()[3].x,
              -0.038342 * cos(-1.25) + 0.024751 * sin(-1.25), EPS);
  EXPECT_NEAR(instance->getVerticesData()[3].y, 2.260834, EPS);
  EXPECT_NEAR(instance->getVerticesData()[3].z,
              0.038342 * sin(-1.25) + 0.024751 * cos(-1.25), EPS);
  EXPECT_NEAR(instance->getVerticesData()[4].x,
              -0.063479 * cos(-1.25) + 0.049246 * sin(-1.25), EPS);
  EXPECT_NEAR(instance->getVerticesData()[4].y, 2.260834, EPS);
  EXPECT_NEAR(instance->getVerticesData()[4].z,
              0.063479 * sin(-1.25) + 0.049246 * cos(-1.25), EPS);
  EXPECT_NEAR(instance->getVerticesData()[5].x,
              -0.062496 * cos(-1.25) + 0.054183 * sin(-1.25), EPS);
  EXPECT_NEAR(instance->getVerticesData()[5].y, 2.260834, EPS);
  EXPECT_NEAR(instance->getVerticesData()[5].z,
              0.062496 * sin(-1.25) + 0.054183 * cos(-1.25), EPS);
  EXPECT_NEAR(instance->getVerticesData()[6].x,
              -0.058793 * cos(-1.25) + 0.047825 * sin(-1.25), EPS);
  EXPECT_NEAR(instance->getVerticesData()[6].y, 2.260834, EPS);
  EXPECT_NEAR(instance->getVerticesData()[6].z,
              0.058793 * sin(-1.25) + 0.047825 * cos(-1.25), EPS);
  EXPECT_NEAR(instance->getVerticesData()[7].x,
              -0.056867 * cos(-1.25) + 0.052476 * sin(-1.25), EPS);
  EXPECT_NEAR(instance->getVerticesData()[7].y, 2.260834, EPS);
  EXPECT_NEAR(instance->getVerticesData()[7].z,
              0.056867 * sin(-1.25) + 0.052476 * cos(-1.25), EPS);
  EXPECT_NEAR(instance->getVerticesData()[8].x,
              -0.054475 * cos(-1.25) + 0.045517 * sin(-1.25), EPS);
  EXPECT_NEAR(instance->getVerticesData()[8].y, 2.260834, EPS);
  EXPECT_NEAR(instance->getVerticesData()[8].z,
              0.054475 * sin(-1.25) + 0.045517 * cos(-1.25), EPS);
  EXPECT_NEAR(instance->getVerticesData()[9].x,
              -0.051679 * cos(-1.25) + 0.049702 * sin(-1.25), EPS);
  EXPECT_NEAR(instance->getVerticesData()[9].y, 2.260834, EPS);
  EXPECT_NEAR(instance->getVerticesData()[9].z,
              0.051679 * sin(-1.25) + 0.049702 * cos(-1.25), EPS);
  delete instance;
}

TEST(TransformSuite, Rotate3) {
  Object* instance = PrototypeFactory::createSkeleton();
  EXPECT_NO_THROW(instance->parse("tests/test_obj/regular.obj"));
  EXPECT_EQ(instance->getVerticesSize(), 10);
  EXPECT_EQ(instance->getFacesSize(), 12);
  EXPECT_NEAR(instance->getMaxZ(), 0.054760, EPS);
  instance->transformData(ROTATE, Z, 0.0);
  EXPECT_NEAR(instance->getVerticesData()[0].x, -0.068597, EPS);
  EXPECT_NEAR(instance->getVerticesData()[0].y, 2.260834, EPS);
  EXPECT_NEAR(instance->getVerticesData()[0].z, 0.049750, EPS);
  EXPECT_NEAR(instance->getVerticesData()[1].x, -0.068350, EPS);
  EXPECT_NEAR(instance->getVerticesData()[1].y, 2.260834, EPS);
  EXPECT_NEAR(instance->getVerticesData()[1].z, 0.054760, EPS);
  EXPECT_NEAR(instance->getVerticesData()[2].x, -0.043352, EPS);
  EXPECT_NEAR(instance->getVerticesData()[2].y, 2.260834, EPS);
  EXPECT_NEAR(instance->getVerticesData()[2].z, 0.024505, EPS);
  EXPECT_NEAR(instance->getVerticesData()[3].x, -0.038342, EPS);
  EXPECT_NEAR(instance->getVerticesData()[3].y, 2.260834, EPS);
  EXPECT_NEAR(instance->getVerticesData()[3].z, 0.024751, EPS);
  EXPECT_NEAR(instance->getVerticesData()[4].x, -0.063479, EPS);
  EXPECT_NEAR(instance->getVerticesData()[4].y, 2.260834, EPS);
  EXPECT_NEAR(instance->getVerticesData()[4].z, 0.049246, EPS);
  EXPECT_NEAR(instance->getVerticesData()[5].x, -0.062496, EPS);
  EXPECT_NEAR(instance->getVerticesData()[5].y, 2.260834, EPS);
  EXPECT_NEAR(instance->getVerticesData()[5].z, 0.054183, EPS);
  EXPECT_NEAR(instance->getVerticesData()[6].x, -0.058793, EPS);
  EXPECT_NEAR(instance->getVerticesData()[6].y, 2.260834, EPS);
  EXPECT_NEAR(instance->getVerticesData()[6].z, 0.047825, EPS);
  EXPECT_NEAR(instance->getVerticesData()[7].x, -0.056867, EPS);
  EXPECT_NEAR(instance->getVerticesData()[7].y, 2.260834, EPS);
  EXPECT_NEAR(instance->getVerticesData()[7].z, 0.052476, EPS);
  EXPECT_NEAR(instance->getVerticesData()[8].x, -0.054475, EPS);
  EXPECT_NEAR(instance->getVerticesData()[8].y, 2.260834, EPS);
  EXPECT_NEAR(instance->getVerticesData()[8].z, 0.045517, EPS);
  EXPECT_NEAR(instance->getVerticesData()[9].x, -0.051679, EPS);
  EXPECT_NEAR(instance->getVerticesData()[9].y, 2.260834, EPS);
  EXPECT_NEAR(instance->getVerticesData()[9].z, 0.049702, EPS);
  EXPECT_NEAR(instance->getMaxZ(), 0.054760, EPS);
  delete instance;
}

TEST(TransformSuite, CentralizationNormalization) {
  Object* instance = PrototypeFactory::createSkeleton();
  EXPECT_NO_THROW(instance->parse("tests/test_obj/Cube_test.obj"));
  EXPECT_EQ(instance->getVerticesSize(), 8);
  EXPECT_EQ(instance->getFacesSize(), 24);
  EXPECT_NEAR(instance->getMaxZ(), 0.75, EPS);
  instance->centralizeData();
  EXPECT_NEAR(instance->getVerticesData()[0].x, -0.5, EPS);
  EXPECT_NEAR(instance->getVerticesData()[0].y, -0.5, EPS);
  EXPECT_NEAR(instance->getVerticesData()[0].z, 0.5, EPS);
  EXPECT_NEAR(instance->getVerticesData()[1].x, 0.5, EPS);
  EXPECT_NEAR(instance->getVerticesData()[1].y, -0.5, EPS);
  EXPECT_NEAR(instance->getVerticesData()[1].z, 0.5, EPS);
  EXPECT_NEAR(instance->getVerticesData()[2].x, -0.5, EPS);
  EXPECT_NEAR(instance->getVerticesData()[2].y, 0.5, EPS);
  EXPECT_NEAR(instance->getVerticesData()[2].z, 0.5, EPS);
  EXPECT_NEAR(instance->getVerticesData()[3].x, 0.5, EPS);
  EXPECT_NEAR(instance->getVerticesData()[3].y, 0.5, EPS);
  EXPECT_NEAR(instance->getVerticesData()[3].z, 0.5, EPS);
  EXPECT_NEAR(instance->getVerticesData()[4].x, -0.5, EPS);
  EXPECT_NEAR(instance->getVerticesData()[4].y, 0.5, EPS);
  EXPECT_NEAR(instance->getVerticesData()[4].z, -0.5, EPS);
  EXPECT_NEAR(instance->getVerticesData()[5].x, 0.5, EPS);
  EXPECT_NEAR(instance->getVerticesData()[5].y, 0.5, EPS);
  EXPECT_NEAR(instance->getVerticesData()[5].z, -0.5, EPS);
  EXPECT_NEAR(instance->getVerticesData()[6].x, -0.5, EPS);
  EXPECT_NEAR(instance->getVerticesData()[6].y, -0.5, EPS);
  EXPECT_NEAR(instance->getVerticesData()[6].z, -0.5, EPS);
  EXPECT_NEAR(instance->getVerticesData()[7].x, 0.5, EPS);
  EXPECT_NEAR(instance->getVerticesData()[7].y, -0.5, EPS);
  EXPECT_NEAR(instance->getVerticesData()[7].z, -0.5, EPS);
  EXPECT_NEAR(instance->getMaxZ(), 0.5, EPS);

  instance->normalizeData();
  EXPECT_NEAR(instance->getVerticesData()[0].x, -1, EPS);
  EXPECT_NEAR(instance->getVerticesData()[0].y, -1, EPS);
  EXPECT_NEAR(instance->getVerticesData()[0].z, 1, EPS);
  EXPECT_NEAR(instance->getVerticesData()[1].x, 1, EPS);
  EXPECT_NEAR(instance->getVerticesData()[1].y, -1, EPS);
  EXPECT_NEAR(instance->getVerticesData()[1].z, 1, EPS);
  EXPECT_NEAR(instance->getVerticesData()[2].x, -1, EPS);
  EXPECT_NEAR(instance->getVerticesData()[2].y, 1, EPS);
  EXPECT_NEAR(instance->getVerticesData()[2].z, 1, EPS);
  EXPECT_NEAR(instance->getVerticesData()[3].x, 1, EPS);
  EXPECT_NEAR(instance->getVerticesData()[3].y, 1, EPS);
  EXPECT_NEAR(instance->getVerticesData()[3].z, 1, EPS);
  EXPECT_NEAR(instance->getVerticesData()[4].x, -1, EPS);
  EXPECT_NEAR(instance->getVerticesData()[4].y, 1, EPS);
  EXPECT_NEAR(instance->getVerticesData()[4].z, -1, EPS);
  EXPECT_NEAR(instance->getVerticesData()[5].x, 1, EPS);
  EXPECT_NEAR(instance->getVerticesData()[5].y, 1, EPS);
  EXPECT_NEAR(instance->getVerticesData()[5].z, -1, EPS);
  EXPECT_NEAR(instance->getVerticesData()[6].x, -1, EPS);
  EXPECT_NEAR(instance->getVerticesData()[6].y, -1, EPS);
  EXPECT_NEAR(instance->getVerticesData()[6].z, -1, EPS);
  EXPECT_NEAR(instance->getVerticesData()[7].x, 1, EPS);
  EXPECT_NEAR(instance->getVerticesData()[7].y, -1, EPS);
  EXPECT_NEAR(instance->getVerticesData()[7].z, -1, EPS);
  EXPECT_NEAR(instance->getMaxZ(), 1, EPS);

  instance->normalizeData(4.5);
  EXPECT_NEAR(instance->getVerticesData()[0].x, -4.5, EPS);
  EXPECT_NEAR(instance->getVerticesData()[0].y, -4.5, EPS);
  EXPECT_NEAR(instance->getVerticesData()[0].z, 4.5, EPS);
  EXPECT_NEAR(instance->getVerticesData()[1].x, 4.5, EPS);
  EXPECT_NEAR(instance->getVerticesData()[1].y, -4.5, EPS);
  EXPECT_NEAR(instance->getVerticesData()[1].z, 4.5, EPS);
  EXPECT_NEAR(instance->getVerticesData()[2].x, -4.5, EPS);
  EXPECT_NEAR(instance->getVerticesData()[2].y, 4.5, EPS);
  EXPECT_NEAR(instance->getVerticesData()[2].z, 4.5, EPS);
  EXPECT_NEAR(instance->getVerticesData()[3].x, 4.5, EPS);
  EXPECT_NEAR(instance->getVerticesData()[3].y, 4.5, EPS);
  EXPECT_NEAR(instance->getVerticesData()[3].z, 4.5, EPS);
  EXPECT_NEAR(instance->getVerticesData()[4].x, -4.5, EPS);
  EXPECT_NEAR(instance->getVerticesData()[4].y, 4.5, EPS);
  EXPECT_NEAR(instance->getVerticesData()[4].z, -4.5, EPS);
  EXPECT_NEAR(instance->getVerticesData()[5].x, 4.5, EPS);
  EXPECT_NEAR(instance->getVerticesData()[5].y, 4.5, EPS);
  EXPECT_NEAR(instance->getVerticesData()[5].z, -4.5, EPS);
  EXPECT_NEAR(instance->getVerticesData()[6].x, -4.5, EPS);
  EXPECT_NEAR(instance->getVerticesData()[6].y, -4.5, EPS);
  EXPECT_NEAR(instance->getVerticesData()[6].z, -4.5, EPS);
  EXPECT_NEAR(instance->getVerticesData()[7].x, 4.5, EPS);
  EXPECT_NEAR(instance->getVerticesData()[7].y, -4.5, EPS);
  EXPECT_NEAR(instance->getVerticesData()[7].z, -4.5, EPS);
  EXPECT_NEAR(instance->getMaxZ(), 4.5, EPS);
  delete instance;
}

TEST(TransformSuite, ScaleAxis) {
  Object* instance = PrototypeFactory::createSkeleton();
  EXPECT_NO_THROW(instance->parse("tests/test_obj/regular.obj"));
  EXPECT_EQ(instance->getVerticesSize(), 10);
  EXPECT_EQ(instance->getFacesSize(), 12);
  EXPECT_NEAR(instance->getMaxZ(), 0.054760, EPS);
  instance->transformData(SCALE, Z, 27.0);
  EXPECT_NEAR(instance->getVerticesData()[0].x, -0.068597, EPS);
  EXPECT_NEAR(instance->getVerticesData()[0].y, 2.260834, EPS);
  EXPECT_NEAR(instance->getVerticesData()[0].z, 0.049750 * 27.0, EPS);
  EXPECT_NEAR(instance->getVerticesData()[1].x, -0.068350, EPS);
  EXPECT_NEAR(instance->getVerticesData()[1].y, 2.260834, EPS);
  EXPECT_NEAR(instance->getVerticesData()[1].z, 0.054760 * 27.0, EPS);
  EXPECT_NEAR(instance->getVerticesData()[2].x, -0.043352, EPS);
  EXPECT_NEAR(instance->getVerticesData()[2].y, 2.260834, EPS);
  EXPECT_NEAR(instance->getVerticesData()[2].z, 0.024505 * 27.0, EPS);
  EXPECT_NEAR(instance->getVerticesData()[3].x, -0.038342, EPS);
  EXPECT_NEAR(instance->getVerticesData()[3].y, 2.260834, EPS);
  EXPECT_NEAR(instance->getVerticesData()[3].z, 0.024751 * 27.0, EPS);
  EXPECT_NEAR(instance->getVerticesData()[4].x, -0.063479, EPS);
  EXPECT_NEAR(instance->getVerticesData()[4].y, 2.260834, EPS);
  EXPECT_NEAR(instance->getVerticesData()[4].z, 0.049246 * 27.0, EPS);
  EXPECT_NEAR(instance->getVerticesData()[5].x, -0.062496, EPS);
  EXPECT_NEAR(instance->getVerticesData()[5].y, 2.260834, EPS);
  EXPECT_NEAR(instance->getVerticesData()[5].z, 0.054183 * 27.0, EPS);
  EXPECT_NEAR(instance->getVerticesData()[6].x, -0.058793, EPS);
  EXPECT_NEAR(instance->getVerticesData()[6].y, 2.260834, EPS);
  EXPECT_NEAR(instance->getVerticesData()[6].z, 0.047825 * 27.0, EPS);
  EXPECT_NEAR(instance->getVerticesData()[7].x, -0.056867, EPS);
  EXPECT_NEAR(instance->getVerticesData()[7].y, 2.260834, EPS);
  EXPECT_NEAR(instance->getVerticesData()[7].z, 0.052476 * 27.0, EPS);
  EXPECT_NEAR(instance->getVerticesData()[8].x, -0.054475, EPS);
  EXPECT_NEAR(instance->getVerticesData()[8].y, 2.260834, EPS);
  EXPECT_NEAR(instance->getVerticesData()[8].z, 0.045517 * 27.0, EPS);
  EXPECT_NEAR(instance->getVerticesData()[9].x, -0.051679, EPS);
  EXPECT_NEAR(instance->getVerticesData()[9].y, 2.260834, EPS);
  EXPECT_NEAR(instance->getVerticesData()[9].z, 0.049702 * 27.0, EPS);
  EXPECT_NEAR(instance->getMaxZ(), 0.054760 * 27.0, EPS);

  instance->transformData(SCALE, Y, 1.0 / 27.0);
  EXPECT_NEAR(instance->getVerticesData()[0].x, -0.068597, EPS);
  EXPECT_NEAR(instance->getVerticesData()[0].y, 2.260834 / 27.0, EPS);
  EXPECT_NEAR(instance->getVerticesData()[0].z, 0.049750 * 27.0, EPS);
  EXPECT_NEAR(instance->getVerticesData()[1].x, -0.068350, EPS);
  EXPECT_NEAR(instance->getVerticesData()[1].y, 2.260834 / 27.0, EPS);
  EXPECT_NEAR(instance->getVerticesData()[1].z, 0.054760 * 27.0, EPS);
  EXPECT_NEAR(instance->getVerticesData()[2].x, -0.043352, EPS);
  EXPECT_NEAR(instance->getVerticesData()[2].y, 2.260834 / 27.0, EPS);
  EXPECT_NEAR(instance->getVerticesData()[2].z, 0.024505 * 27.0, EPS);
  EXPECT_NEAR(instance->getVerticesData()[3].x, -0.038342, EPS);
  EXPECT_NEAR(instance->getVerticesData()[3].y, 2.260834 / 27.0, EPS);
  EXPECT_NEAR(instance->getVerticesData()[3].z, 0.024751 * 27.0, EPS);
  EXPECT_NEAR(instance->getVerticesData()[4].x, -0.063479, EPS);
  EXPECT_NEAR(instance->getVerticesData()[4].y, 2.260834 / 27.0, EPS);
  EXPECT_NEAR(instance->getVerticesData()[4].z, 0.049246 * 27.0, EPS);
  EXPECT_NEAR(instance->getVerticesData()[5].x, -0.062496, EPS);
  EXPECT_NEAR(instance->getVerticesData()[5].y, 2.260834 / 27.0, EPS);
  EXPECT_NEAR(instance->getVerticesData()[5].z, 0.054183 * 27.0, EPS);
  EXPECT_NEAR(instance->getVerticesData()[6].x, -0.058793, EPS);
  EXPECT_NEAR(instance->getVerticesData()[6].y, 2.260834 / 27.0, EPS);
  EXPECT_NEAR(instance->getVerticesData()[6].z, 0.047825 * 27.0, EPS);
  EXPECT_NEAR(instance->getVerticesData()[7].x, -0.056867, EPS);
  EXPECT_NEAR(instance->getVerticesData()[7].y, 2.260834 / 27.0, EPS);
  EXPECT_NEAR(instance->getVerticesData()[7].z, 0.052476 * 27.0, EPS);
  EXPECT_NEAR(instance->getVerticesData()[8].x, -0.054475, EPS);
  EXPECT_NEAR(instance->getVerticesData()[8].y, 2.260834 / 27.0, EPS);
  EXPECT_NEAR(instance->getVerticesData()[8].z, 0.045517 * 27.0, EPS);
  EXPECT_NEAR(instance->getVerticesData()[9].x, -0.051679, EPS);
  EXPECT_NEAR(instance->getVerticesData()[9].y, 2.260834 / 27.0, EPS);
  EXPECT_NEAR(instance->getVerticesData()[9].z, 0.049702 * 27.0, EPS);
  EXPECT_NEAR(instance->getMaxZ(), 0.054760 * 27.0, EPS);

  instance->transformData(SCALE, X, -5.27);
  EXPECT_NEAR(instance->getVerticesData()[0].x, -0.068597 * -5.27, EPS);
  EXPECT_NEAR(instance->getVerticesData()[0].y, 2.260834 / 27.0, EPS);
  EXPECT_NEAR(instance->getVerticesData()[0].z, 0.049750 * 27.0, EPS);
  EXPECT_NEAR(instance->getVerticesData()[1].x, -0.068350 * -5.27, EPS);
  EXPECT_NEAR(instance->getVerticesData()[1].y, 2.260834 / 27.0, EPS);
  EXPECT_NEAR(instance->getVerticesData()[1].z, 0.054760 * 27.0, EPS);
  EXPECT_NEAR(instance->getVerticesData()[2].x, -0.043352 * -5.27, EPS);
  EXPECT_NEAR(instance->getVerticesData()[2].y, 2.260834 / 27.0, EPS);
  EXPECT_NEAR(instance->getVerticesData()[2].z, 0.024505 * 27.0, EPS);
  EXPECT_NEAR(instance->getVerticesData()[3].x, -0.038342 * -5.27, EPS);
  EXPECT_NEAR(instance->getVerticesData()[3].y, 2.260834 / 27.0, EPS);
  EXPECT_NEAR(instance->getVerticesData()[3].z, 0.024751 * 27.0, EPS);
  EXPECT_NEAR(instance->getVerticesData()[4].x, -0.063479 * -5.27, EPS);
  EXPECT_NEAR(instance->getVerticesData()[4].y, 2.260834 / 27.0, EPS);
  EXPECT_NEAR(instance->getVerticesData()[4].z, 0.049246 * 27.0, EPS);
  EXPECT_NEAR(instance->getVerticesData()[5].x, -0.062496 * -5.27, EPS);
  EXPECT_NEAR(instance->getVerticesData()[5].y, 2.260834 / 27.0, EPS);
  EXPECT_NEAR(instance->getVerticesData()[5].z, 0.054183 * 27.0, EPS);
  EXPECT_NEAR(instance->getVerticesData()[6].x, -0.058793 * -5.27, EPS);
  EXPECT_NEAR(instance->getVerticesData()[6].y, 2.260834 / 27.0, EPS);
  EXPECT_NEAR(instance->getVerticesData()[6].z, 0.047825 * 27.0, EPS);
  EXPECT_NEAR(instance->getVerticesData()[7].x, -0.056867 * -5.27, EPS);
  EXPECT_NEAR(instance->getVerticesData()[7].y, 2.260834 / 27.0, EPS);
  EXPECT_NEAR(instance->getVerticesData()[7].z, 0.052476 * 27.0, EPS);
  EXPECT_NEAR(instance->getVerticesData()[8].x, -0.054475 * -5.27, EPS);
  EXPECT_NEAR(instance->getVerticesData()[8].y, 2.260834 / 27.0, EPS);
  EXPECT_NEAR(instance->getVerticesData()[8].z, 0.045517 * 27.0, EPS);
  EXPECT_NEAR(instance->getVerticesData()[9].x, -0.051679 * -5.27, EPS);
  EXPECT_NEAR(instance->getVerticesData()[9].y, 2.260834 / 27.0, EPS);
  EXPECT_NEAR(instance->getVerticesData()[9].z, 0.049702 * 27.0, EPS);
  EXPECT_NEAR(instance->getMaxZ(), 0.054760 * 27.0, EPS);
  delete instance;
}

}  // namespace s21
