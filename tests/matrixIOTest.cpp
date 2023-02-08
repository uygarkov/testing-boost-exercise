#define BOOST_TEST_DYN_LINK
#include <Eigen/Dense>
#include <boost/test/unit_test.hpp>
#include "matrixIO.hpp"

using namespace matrixIO;
using namespace Eigen;

struct matrixIOFixture {
  matrixIOFixture()
  {
    filePath    = "../data/m3.csv";
    expected_m3 = MatrixXd(3, 3);
    expected_m3 << 0.680375, 0.59688, -0.329554,
        -0.211234, 0.823295, 0.536459,
        0.566198, -0.604897, -0.444451;
  }
  std::string filePath;
  MatrixXd    expected_m3;
};

BOOST_FIXTURE_TEST_SUITE(MatrixIOTests, matrixIOFixture)

BOOST_AUTO_TEST_CASE(testOpenData)
{
  MatrixXd openData_m3 = openData(filePath, 3);
  BOOST_CHECK_EQUAL(openData_m3, expected_m3);
  BOOST_CHECK_THROW(openData(filePath, 5), std::runtime_error);
}

BOOST_AUTO_TEST_SUITE_END()