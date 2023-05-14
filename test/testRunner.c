#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

#include "adc.h"
#include "displayDriver.h"
#include "voltage.h"



int main(int argc, char **argv)
{
 ::testing::InitGoogleTest(&argc, argv);
 
 return RUN_ALL_TESTS();
}

//--------------------------------------ADC_LIBRARY_TESTS---------------------------------
class ValidatorFixture : public testing::TestWithParam<std::tuple<int, int>>
{
public:

};

TEST_P(ValidatorFixture, TestInRange)
{
  std::tuple<int, int> tuple = GetParam();

  int expectedValue = std::get<0>(tuple);
  int param = std::get<1>(tuple);

  std::cout << "param = " << param << " expected value = " << expectedValue << '\n';

  int isInside = checkIfVoltageInRange(param);

  ASSERT_EQ(expectedValue, isInside);
}

INSTANTIATE_TEST_CASE_P(InRangeTrue, ValidatorFixture, testing::Values(
  std::make_tuple(1, 5000),
  std::make_tuple(0, 11000),
  std::make_tuple(0, -10500)
));

TEST(ADC_convertToVoltage, for_0_convert_to_mVoltage_should_return_minus8312)
{
  int x = convertToVoltage(0);

  ASSERT_EQ(-8312, x);
}

TEST(ADC_convertToVoltage, for_4095_convert_to_mVoltage_should_return_8395)
{
  int x = convertToVoltage(4095);

  ASSERT_EQ(8395, x);
}

TEST(ADC_convertToVoltage, for_2047_convert_to_mVoltage_should_return_39)
{
  int x = convertToVoltage(2047);

  ASSERT_EQ(39, x);
}

TEST(ADC_convertToVoltage, for_out_of_range_0_to_4095_convert_to_mVoltage_should_return_NJLL)
{
  int x = convertToVoltage(4096);

  ASSERT_EQ(NULL, x);
}

TEST(ADC_convertToVoltage, for_out_of_range_0_to_4095_convert_to_mVoltage_should_return_NJLL_2)
{
  int x = convertToVoltage(-1);

  ASSERT_EQ(NULL, x);
}

//--------------------------------------VOLTAGELIBRARY_TESTS---------------------------------


TEST(VOLTAGE_mean, for_sum_100_number_of_samples_10_shoul_return_10)
{

  unsigned int x = mean(100, 10)

  ASSERT_EQ(10, x);
}

TEST(VOLTAGE_mean, for__number_of_samples_0_shoul_return_0)
{

  unsigned int x = mean(100, 0)

  ASSERT_EQ(0, x);
}