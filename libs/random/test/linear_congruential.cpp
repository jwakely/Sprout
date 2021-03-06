#ifndef SPROUT_LIBS_RANDOM_TEST_LINEAR_CONGRUENTIAL_CPP
#define SPROUT_LIBS_RANDOM_TEST_LINEAR_CONGRUENTIAL_CPP

#include <sprout/random/linear_congruential.hpp>
#include "./engine_generic.hpp"
#include <testspr/tools.hpp>

namespace testspr {
	void random_linear_congruential_test() {
		using namespace sprout;

		testspr::random_engine_test_generic<sprout::random::minstd_rand0>();
		testspr::random_engine_test_generic<sprout::random::minstd_rand>();
		testspr::random_engine_test_generic<sprout::random::rand48>();
	}
}	// namespace testspr

#ifndef TESTSPR_CPP_INCLUDE
#	define TESTSPR_TEST_FUNCTION testspr::random_linear_congruential_test
#	include <testspr/include_main.hpp>
#endif

#endif	// #ifndef SPROUT_LIBS_RANDOM_TEST_LINEAR_CONGRUENTIAL_CPP
