#ifndef SPROUT_LIBS_RANDOM_TEST_MERSENNE_TWISTER_CPP
#define SPROUT_LIBS_RANDOM_TEST_MERSENNE_TWISTER_CPP

#include <sprout/random/mersenne_twister.hpp>
#include "./engine_generic.hpp"
#include <testspr/tools.hpp>

namespace testspr {
	void random_mersenne_twister_test() {
		using namespace sprout;

		testspr::random_engine_test_generic<sprout::random::mt11213b>();
		//testspr::random_engine_test_generic<sprout::random::mt19937>();
		//testspr::random_engine_test_generic<sprout::random::mt19937_64>();
	}
}	// namespace testspr

#ifndef TESTSPR_CPP_INCLUDE
#	define TESTSPR_TEST_FUNCTION testspr::random_mersenne_twister_test
#	include <testspr/include_main.hpp>
#endif

#endif	// #ifndef SPROUT_LIBS_RANDOM_TEST_MERSENNE_TWISTER_CPP
