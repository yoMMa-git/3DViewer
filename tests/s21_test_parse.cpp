#include "s21_test_main.h"

// TEST(ParseSuite, ExampleObject) {
//   Object* instance = PrototypeFactory::createSkeleton();
//   EXPECT_TRUE(instance->parse("tests/test_obj/MAC10_2021.obj"));
//   EXPECT_EQ(instance->getVerticesSize(), 30106);
//   EXPECT_EQ(instance->getFacesSize(), 59068);
//   // EXPECT_EQ(instance->getFacesSize(), 58837);
//   EXPECT_NEAR(instance->getVerticesData()[0].x, -0.068597, EPS);
//   EXPECT_NEAR(instance->getVerticesData()[0].y, 2.260834, EPS);
//   EXPECT_NEAR(instance->getVerticesData()[0].z, 0.049750, EPS);
//   EXPECT_NEAR(instance->getVerticesData()[30105].x, -0.190212, EPS);
//   EXPECT_NEAR(instance->getVerticesData()[30105].y, 1.452225, EPS);
//   EXPECT_NEAR(instance->getVerticesData()[30105].z, -0.004935, EPS);
//   EXPECT_EQ(static_cast<Edge*>(instance->getFacesData())[0].a, 0);
//   EXPECT_EQ(static_cast<Edge*>(instance->getFacesData())[0].b, 1);
//   EXPECT_EQ(static_cast<Edge*>(instance->getFacesData())[59067].a,
//   30104);
//   EXPECT_EQ(static_cast<Edge*>(instance->getFacesData())[59067].b,
//   30105); delete instance;
// }

// TEST(ParseSuite, ExampleObject2) {
//   Object* instance = PrototypeFactory::createSkeleton();
//   EXPECT_TRUE(instance->parse("tests/test_obj/Skull.obj"));
//   delete instance;
// }

// TEST(ParseSuite, GiganticObject) {
//   Object* instance = PrototypeFactory::createSkeleton();
//   EXPECT_TRUE(instance->parse("tests/test_obj/Lion.obj"));
//   delete instance;
// }

// TEST(ParseSuite, HeavyObject) {
//   Object* instance = PrototypeFactory::createSkeleton();
//   EXPECT_TRUE(instance->parse("tests/test_obj/Canon_EOS-1DX.obj"));
//   delete instance;
// }

namespace s21 {
TEST(ParseSuite, CreateObject) {
  Object* instance = PrototypeFactory::createSkeleton();
  // Skeleton instance;
  EXPECT_EQ(instance->getVerticesSize(), 0);
  EXPECT_EQ(instance->getFacesSize(), 0);
  EXPECT_EQ(instance->getCurrentLine(), 0);
  EXPECT_NEAR(instance->getMaxZ(), 0.0, EPS);
  delete instance;
}

TEST(ParseSuite, RegularObject) {
  Object* instance = PrototypeFactory::createSkeleton();
  EXPECT_EQ(instance->getVerticesSize(), 0);
  EXPECT_EQ(instance->getFacesSize(), 0);
  EXPECT_EQ(instance->getCurrentLine(), 0);
  EXPECT_NEAR(instance->getMaxZ(), 0.0, EPS);
  EXPECT_NO_THROW(instance->parse("tests/test_obj/regular.obj"));
  EXPECT_EQ(instance->getVerticesSize(), 10);
  EXPECT_EQ(instance->getFacesSize(), 12);
  EXPECT_EQ(instance->getCurrentLine(), 13);
  EXPECT_NEAR(instance->getMaxZ(), 0.054760, EPS);
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
  instance->compactData();
  EXPECT_EQ(static_cast<Edge*>(instance->getFacesData())[0].a, 0);
  EXPECT_EQ(static_cast<Edge*>(instance->getFacesData())[0].b, 1);
  EXPECT_EQ(static_cast<Edge*>(instance->getFacesData())[1].a, 0);
  EXPECT_EQ(static_cast<Edge*>(instance->getFacesData())[1].b, 3);
  EXPECT_EQ(static_cast<Edge*>(instance->getFacesData())[2].a, 0);
  EXPECT_EQ(static_cast<Edge*>(instance->getFacesData())[2].b, 8);
  EXPECT_EQ(static_cast<Edge*>(instance->getFacesData())[3].a, 0);
  EXPECT_EQ(static_cast<Edge*>(instance->getFacesData())[3].b, 9);
  EXPECT_EQ(static_cast<Edge*>(instance->getFacesData())[4].a, 1);
  EXPECT_EQ(static_cast<Edge*>(instance->getFacesData())[4].b, 2);
  EXPECT_EQ(static_cast<Edge*>(instance->getFacesData())[5].a, 2);
  EXPECT_EQ(static_cast<Edge*>(instance->getFacesData())[5].b, 3);
  EXPECT_EQ(static_cast<Edge*>(instance->getFacesData())[6].a, 4);
  EXPECT_EQ(static_cast<Edge*>(instance->getFacesData())[6].b, 5);
  EXPECT_EQ(static_cast<Edge*>(instance->getFacesData())[7].a, 4);
  EXPECT_EQ(static_cast<Edge*>(instance->getFacesData())[7].b, 8);
  EXPECT_EQ(static_cast<Edge*>(instance->getFacesData())[8].a, 5);
  EXPECT_EQ(static_cast<Edge*>(instance->getFacesData())[8].b, 7);
  EXPECT_EQ(static_cast<Edge*>(instance->getFacesData())[9].a, 6);
  EXPECT_EQ(static_cast<Edge*>(instance->getFacesData())[9].b, 7);
  EXPECT_EQ(static_cast<Edge*>(instance->getFacesData())[10].a, 6);
  EXPECT_EQ(static_cast<Edge*>(instance->getFacesData())[10].b, 8);
  EXPECT_EQ(static_cast<Edge*>(instance->getFacesData())[11].a, 8);
  EXPECT_EQ(static_cast<Edge*>(instance->getFacesData())[11].b, 9);
  delete instance;
}

TEST(ParseSuite, CompactEdges) {
  Object* instance = PrototypeFactory::createSkeleton();
  EXPECT_EQ(instance->getVerticesSize(), 0);
  EXPECT_EQ(instance->getFacesSize(), 0);
  EXPECT_EQ(instance->getCurrentLine(), 0);
  EXPECT_NEAR(instance->getMaxZ(), 0.0, EPS);
  EXPECT_NO_THROW(instance->parse("tests/test_obj/compactor_test.obj"));
  EXPECT_EQ(instance->getVerticesSize(), 10);
  EXPECT_EQ(instance->getFacesSize(), 13);
  EXPECT_EQ(instance->getCurrentLine(), 13);
  EXPECT_NEAR(instance->getMaxZ(), 0.0, EPS);
  EXPECT_NEAR(instance->getVerticesData()[0].x, -0.068597, EPS);
  EXPECT_NEAR(instance->getVerticesData()[0].y, 2.260834, EPS);
  EXPECT_NEAR(instance->getVerticesData()[0].z, -0.049750, EPS);
  EXPECT_NEAR(instance->getVerticesData()[1].x, -0.068350, EPS);
  EXPECT_NEAR(instance->getVerticesData()[1].y, 2.260834, EPS);
  EXPECT_NEAR(instance->getVerticesData()[1].z, -0.054760, EPS);
  EXPECT_NEAR(instance->getVerticesData()[2].x, -0.043352, EPS);
  EXPECT_NEAR(instance->getVerticesData()[2].y, 2.260834, EPS);
  EXPECT_NEAR(instance->getVerticesData()[2].z, -0.024505, EPS);
  EXPECT_NEAR(instance->getVerticesData()[3].x, -0.038342, EPS);
  EXPECT_NEAR(instance->getVerticesData()[3].y, 2.260834, EPS);
  EXPECT_NEAR(instance->getVerticesData()[3].z, -0.024751, EPS);
  EXPECT_NEAR(instance->getVerticesData()[4].x, -0.063479, EPS);
  EXPECT_NEAR(instance->getVerticesData()[4].y, 2.260834, EPS);
  EXPECT_NEAR(instance->getVerticesData()[4].z, -0.049246, EPS);
  EXPECT_NEAR(instance->getVerticesData()[5].x, -0.062496, EPS);
  EXPECT_NEAR(instance->getVerticesData()[5].y, 2.260834, EPS);
  EXPECT_NEAR(instance->getVerticesData()[5].z, -0.054183, EPS);
  EXPECT_NEAR(instance->getVerticesData()[6].x, -0.058793, EPS);
  EXPECT_NEAR(instance->getVerticesData()[6].y, 2.260834, EPS);
  EXPECT_NEAR(instance->getVerticesData()[6].z, -0.047825, EPS);
  EXPECT_NEAR(instance->getVerticesData()[7].x, -0.056867, EPS);
  EXPECT_NEAR(instance->getVerticesData()[7].y, 2.260834, EPS);
  EXPECT_NEAR(instance->getVerticesData()[7].z, -0.052476, EPS);
  EXPECT_NEAR(instance->getVerticesData()[8].x, -0.054475, EPS);
  EXPECT_NEAR(instance->getVerticesData()[8].y, 2.260834, EPS);
  EXPECT_NEAR(instance->getVerticesData()[8].z, -0.045517, EPS);
  EXPECT_NEAR(instance->getVerticesData()[9].x, -0.051679, EPS);
  EXPECT_NEAR(instance->getVerticesData()[9].y, 2.260834, EPS);
  EXPECT_NEAR(instance->getVerticesData()[9].z, -0.049702, EPS);
  EXPECT_EQ(static_cast<Edge*>(instance->getFacesData())[0].a, 0);
  EXPECT_EQ(static_cast<Edge*>(instance->getFacesData())[0].b, 1);
  EXPECT_EQ(static_cast<Edge*>(instance->getFacesData())[1].a, 1);
  EXPECT_EQ(static_cast<Edge*>(instance->getFacesData())[1].b, 2);
  EXPECT_EQ(static_cast<Edge*>(instance->getFacesData())[2].a, 2);
  EXPECT_EQ(static_cast<Edge*>(instance->getFacesData())[2].b, 3);
  EXPECT_EQ(static_cast<Edge*>(instance->getFacesData())[3].a, 0);
  EXPECT_EQ(static_cast<Edge*>(instance->getFacesData())[3].b, 3);
  EXPECT_EQ(static_cast<Edge*>(instance->getFacesData())[4].a, 0);
  EXPECT_EQ(static_cast<Edge*>(instance->getFacesData())[4].b, 1);
  EXPECT_EQ(static_cast<Edge*>(instance->getFacesData())[5].a, 1);
  EXPECT_EQ(static_cast<Edge*>(instance->getFacesData())[5].b, 2);
  EXPECT_EQ(static_cast<Edge*>(instance->getFacesData())[6].a, 0);
  EXPECT_EQ(static_cast<Edge*>(instance->getFacesData())[6].b, 2);
  EXPECT_EQ(static_cast<Edge*>(instance->getFacesData())[7].a, 4);
  EXPECT_EQ(static_cast<Edge*>(instance->getFacesData())[7].b, 8);
  EXPECT_EQ(static_cast<Edge*>(instance->getFacesData())[8].a, 5);
  EXPECT_EQ(static_cast<Edge*>(instance->getFacesData())[8].b, 8);
  EXPECT_EQ(static_cast<Edge*>(instance->getFacesData())[9].a, 5);
  EXPECT_EQ(static_cast<Edge*>(instance->getFacesData())[9].b, 7);
  EXPECT_EQ(static_cast<Edge*>(instance->getFacesData())[10].a, 6);
  EXPECT_EQ(static_cast<Edge*>(instance->getFacesData())[10].b, 7);
  EXPECT_EQ(static_cast<Edge*>(instance->getFacesData())[11].a, 6);
  EXPECT_EQ(static_cast<Edge*>(instance->getFacesData())[11].b, 8);
  EXPECT_EQ(static_cast<Edge*>(instance->getFacesData())[12].a, 4);
  EXPECT_EQ(static_cast<Edge*>(instance->getFacesData())[12].b, 8);
  instance->compactData();
  EXPECT_EQ(instance->getVerticesSize(), 10);
  EXPECT_EQ(instance->getFacesSize(), 10);
  EXPECT_EQ(instance->getCurrentLine(), 13);
  EXPECT_NEAR(instance->getMaxZ(), 0.0, EPS);
  EXPECT_EQ(static_cast<Edge*>(instance->getFacesData())[0].a, 0);
  EXPECT_EQ(static_cast<Edge*>(instance->getFacesData())[0].b, 1);
  EXPECT_EQ(static_cast<Edge*>(instance->getFacesData())[1].a, 0);
  EXPECT_EQ(static_cast<Edge*>(instance->getFacesData())[1].b, 2);
  EXPECT_EQ(static_cast<Edge*>(instance->getFacesData())[2].a, 0);
  EXPECT_EQ(static_cast<Edge*>(instance->getFacesData())[2].b, 3);
  EXPECT_EQ(static_cast<Edge*>(instance->getFacesData())[3].a, 1);
  EXPECT_EQ(static_cast<Edge*>(instance->getFacesData())[3].b, 2);
  EXPECT_EQ(static_cast<Edge*>(instance->getFacesData())[4].a, 2);
  EXPECT_EQ(static_cast<Edge*>(instance->getFacesData())[4].b, 3);
  EXPECT_EQ(static_cast<Edge*>(instance->getFacesData())[5].a, 4);
  EXPECT_EQ(static_cast<Edge*>(instance->getFacesData())[5].b, 8);
  EXPECT_EQ(static_cast<Edge*>(instance->getFacesData())[6].a, 5);
  EXPECT_EQ(static_cast<Edge*>(instance->getFacesData())[6].b, 7);
  EXPECT_EQ(static_cast<Edge*>(instance->getFacesData())[7].a, 5);
  EXPECT_EQ(static_cast<Edge*>(instance->getFacesData())[7].b, 8);
  EXPECT_EQ(static_cast<Edge*>(instance->getFacesData())[8].a, 6);
  EXPECT_EQ(static_cast<Edge*>(instance->getFacesData())[8].b, 7);
  EXPECT_EQ(static_cast<Edge*>(instance->getFacesData())[9].a, 6);
  EXPECT_EQ(static_cast<Edge*>(instance->getFacesData())[9].b, 8);
  delete instance;
}

TEST(ParseSuite, OnlyV) {
  Object* instance = PrototypeFactory::createSkeleton();
  EXPECT_NO_THROW(instance->parse("tests/test_obj/only_v.obj"));
  EXPECT_EQ(instance->getVerticesSize(), 4785);
  EXPECT_EQ(instance->getFacesSize(), 0);
  EXPECT_EQ(instance->getCurrentLine(), 4786);
  EXPECT_NEAR(instance->getMaxZ(), 0.091342, EPS);
  EXPECT_NEAR(instance->getVerticesData()[0].x, -0.068597, EPS);
  EXPECT_NEAR(instance->getVerticesData()[0].y, 2.260834, EPS);
  EXPECT_NEAR(instance->getVerticesData()[0].z, 0.049750, EPS);
  EXPECT_NEAR(instance->getVerticesData()[4784].x, -0.548627, EPS);
  EXPECT_NEAR(instance->getVerticesData()[4784].y, 2.592486, EPS);
  EXPECT_NEAR(instance->getVerticesData()[4784].z, -0.078518, EPS);
  delete instance;
}

TEST(ParseSuite, OnlyF) {
  Object* instance = PrototypeFactory::createSkeleton();
  EXPECT_THROW(instance->parse("tests/test_obj/only_f.obj"),
               std::invalid_argument);
  EXPECT_EQ(instance->getVerticesSize(), 0);
  EXPECT_EQ(instance->getFacesSize(), 0);
  EXPECT_EQ(instance->getCurrentLine(), 0);
  EXPECT_NEAR(instance->getMaxZ(), 0.0, EPS);
  delete instance;
}

TEST(ParseSuite, CorruptedV2) {
  Object* instance = PrototypeFactory::createSkeleton();
  EXPECT_THROW(instance->parse("tests/test_obj/corrupted_v_2.obj"),
               std::invalid_argument);
  EXPECT_EQ(instance->getVerticesSize(), 0);
  EXPECT_EQ(instance->getFacesSize(), 0);
  EXPECT_EQ(instance->getCurrentLine(), 1);
  EXPECT_NEAR(instance->getMaxZ(), 0.0, EPS);
  delete instance;
}

TEST(ParseSuite, CorruptedV1) {
  Object* instance = PrototypeFactory::createSkeleton();
  EXPECT_THROW(instance->parse("tests/test_obj/corrupted_v_1.obj"),
               std::invalid_argument);
  EXPECT_EQ(instance->getVerticesSize(), 0);
  EXPECT_EQ(instance->getFacesSize(), 0);
  EXPECT_EQ(instance->getCurrentLine(), 2);
  EXPECT_NEAR(instance->getMaxZ(), 0.0, EPS);
  delete instance;
}

TEST(ParseSuite, CorruptedF1) {
  Object* instance = PrototypeFactory::createSkeleton();
  EXPECT_THROW(instance->parse("tests/test_obj/corrupted_f_1.obj"),
               std::invalid_argument);
  EXPECT_EQ(instance->getVerticesSize(), 0);
  EXPECT_EQ(instance->getFacesSize(), 0);
  EXPECT_EQ(instance->getCurrentLine(), 10);
  EXPECT_NEAR(instance->getMaxZ(), 0.0, EPS);
  delete instance;
}

TEST(ParseSuite, IncorrectIndices) {
  Object* instance = PrototypeFactory::createSkeleton();
  EXPECT_THROW(instance->parse("tests/test_obj/incorrect_indexes.obj"),
               std::invalid_argument);
  EXPECT_EQ(instance->getVerticesSize(), 0);
  EXPECT_EQ(instance->getFacesSize(), 0);
  EXPECT_EQ(instance->getCurrentLine(), 9);
  EXPECT_NEAR(instance->getMaxZ(), 0.0, EPS);
  delete instance;
}

TEST(ParseSuite, EmptyF) {
  Object* instance = PrototypeFactory::createSkeleton();
  EXPECT_NO_THROW(instance->parse("tests/test_obj/empty_f.obj"));
  EXPECT_EQ(instance->getVerticesSize(), 10);
  EXPECT_EQ(instance->getFacesSize(), 4);
  EXPECT_EQ(instance->getCurrentLine(), 13);
  EXPECT_NEAR(instance->getMaxZ(), 0.054760, EPS);
  delete instance;
}

TEST(ParseSuite, EmptyV) {
  Object* instance = PrototypeFactory::createSkeleton();
  EXPECT_THROW(instance->parse("tests/test_obj/empty_v.obj"),
               std::invalid_argument);
  EXPECT_EQ(instance->getVerticesSize(), 0);
  EXPECT_EQ(instance->getFacesSize(), 0);
  EXPECT_EQ(instance->getCurrentLine(), 5);
  EXPECT_NEAR(instance->getMaxZ(), 0.0, EPS);
  delete instance;
}

TEST(ParseSuite, NoFile) {
  Object* instance = PrototypeFactory::createSkeleton();
  EXPECT_THROW(instance->parse("tests/test_obj/nope.obj"),
               std::invalid_argument);
  EXPECT_EQ(instance->getVerticesSize(), 0);
  EXPECT_EQ(instance->getFacesSize(), 0);
  EXPECT_EQ(instance->getCurrentLine(), 0);
  EXPECT_NEAR(instance->getMaxZ(), 0.0, EPS);
  delete instance;
}

TEST(ParseSuite, EmptyFile) {
  Object* instance = PrototypeFactory::createSkeleton();
  EXPECT_THROW(instance->parse("tests/test_obj/empty.obj"),
               std::invalid_argument);
  EXPECT_EQ(instance->getVerticesSize(), 0);
  EXPECT_EQ(instance->getFacesSize(), 0);
  EXPECT_EQ(instance->getCurrentLine(), 0);
  EXPECT_NEAR(instance->getMaxZ(), 0.0, EPS);
  delete instance;
}

TEST(ParseSuite, NegativeIndices) {
  Object* instance = PrototypeFactory::createSkeleton();
  EXPECT_NO_THROW(instance->parse("tests/test_obj/negative_index.obj"));
  EXPECT_EQ(instance->getVerticesSize(), 10);
  EXPECT_EQ(instance->getFacesSize(), 9);
  EXPECT_EQ(instance->getCurrentLine(), 12);
  EXPECT_NEAR(instance->getMaxZ(), 0.054760, EPS);
  EXPECT_EQ(static_cast<Edge*>(instance->getFacesData())[0].a, 5);
  EXPECT_EQ(static_cast<Edge*>(instance->getFacesData())[0].b, 9);
  EXPECT_EQ(static_cast<Edge*>(instance->getFacesData())[8].a, 0);
  EXPECT_EQ(static_cast<Edge*>(instance->getFacesData())[8].b, 7);
  delete instance;
}

TEST(ParseSuite, ZeroIndex) {
  Object* instance = PrototypeFactory::createSkeleton();
  EXPECT_THROW(instance->parse("tests/test_obj/zero_index.obj"),
               std::invalid_argument);
  EXPECT_EQ(instance->getVerticesSize(), 0);
  EXPECT_EQ(instance->getFacesSize(), 0);
  EXPECT_EQ(instance->getCurrentLine(), 10);
  EXPECT_NEAR(instance->getMaxZ(), 0.0, EPS);
  delete instance;
}

}  // namespace s21