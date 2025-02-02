#include <Eigen/Dense>
#include <boost/test/unit_test.hpp>
#include "matrixIO.hpp"

using namespace Eigen;
using namespace matrixIO;

struct MatrixIOFixture {
  MatrixIOFixture()
  {
    expectedMatrix = MatrixXd(3, 3);
    expectedMatrix << 0.680375, 0.59688, -0.329554,
      -0.211234, 0.823295, 0.536459,
      0.566198, -0.604897, -0.444451;

  }
  MatrixXd expectedMatrix;
};

BOOST_FIXTURE_TEST_SUITE(MatrixIOTests, MatrixIOFixture, *boost::unit_test::tolerance(1e-6))

BOOST_AUTO_TEST_CASE(Hoho)
{

  MatrixXd resultMatrix = openData("../data/m3.csv", 3);

  BOOST_CHECK_EQUAL(resultMatrix.rows(), expectedMatrix.rows());
  BOOST_CHECK_EQUAL(resultMatrix.cols(), expectedMatrix.cols());
  BOOST_CHECK(resultMatrix.isApprox(expectedMatrix, 1e-6));
}

BOOST_AUTO_TEST_SUITE_END()
