#define BOOST_TEST_DYN_LINk
#include <Eigen/Dense>
#include <boost/test/unit_test.hpp>
#include "../src/matrixIO.cpp"
#include <array>

using namespace matrixIO;
using namespace Eigen;

struct matrixIOFixture {
    matrixIOFixture()
    {
        filePath = "../data/m3.csv";
        dimension = 3;
        wrong_dimension = 5;
        expected_m3 = MatrixXd(dimension, dimension);
        expected_m3 << 0.680375, 0.59688, -0.329554,
                    -0.211234, 0.823295, 0.536459,
                    0.566198, -0.604897, -0.444451;
    }
    std::string        filePath;
    int                dimension, wrong_dimension;
    MatrixXd           expected_m3;
};

BOOST_FIXTURE_TEST_SUITE(matrixIOTests, matrixIOFixture)

BOOST_AUTO_TEST_CASE(testOpenData)
{
    MatrixXd openData_m3 = openData(filePath, dimension);
    BOOST_CHECK_EQUAL(openData_m3, expected_m3);
    BOOST_CHECK_THROW(openData(filePath, wrong_dimension), std::runtime_error);
}

BOOST_AUTO_TEST_SUITE_END()
