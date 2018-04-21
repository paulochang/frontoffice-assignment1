#define BOOST_TEST_MODULE test_foo
#include <boost/test/unit_test.hpp>
#include <Foo/foo.h>

BOOST_AUTO_TEST_SUITE(hi_boost)

	BOOST_AUTO_TEST_CASE(hello_world)
	{
		BOOST_TEST_MESSAGE("using tolerances within checks." );

	    double f = 0.1;
	    auto sum = add(f, 10);

	    auto product = f * 10;

	    BOOST_TEST_MESSAGE(" - sum: " << sum);
	    BOOST_TEST_MESSAGE(" - product: " << product);
	    BOOST_TEST_MESSAGE(" - diff " << sum-product); 
	    BOOST_TEST(sum == product, boost::test_tools::tolerance(1e-15));
	}

	BOOST_AUTO_TEST_CASE(hello_world2)
	{
		BOOST_TEST_MESSAGE("using tolerances within checks." );

	    double f = 0.1;
	    auto sum = add(f, 10);

	    auto product = f * 10;

	    BOOST_TEST_MESSAGE(" - sum: " << sum);
	    BOOST_TEST_MESSAGE(" - product: " << product);
	    BOOST_TEST_MESSAGE(" - diff " << sum-product); 
	    BOOST_TEST(sum == product, boost::test_tools::tolerance(1e-15));
	}

BOOST_AUTO_TEST_SUITE_END()
