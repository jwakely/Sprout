#ifndef SPROUT_RANGE_NUMERIC_DFT_FIT_IDFT_HPP
#define SPROUT_RANGE_NUMERIC_DFT_FIT_IDFT_HPP

#include <sprout/config.hpp>
#include <sprout/container/traits.hpp>
#include <sprout/container/functions.hpp>
#include <sprout/algorithm/fit/result_of.hpp>
#include <sprout/numeric/dft/fit/idft.hpp>

namespace sprout {
	namespace range {
		namespace fit {
			//
			// idft
			//
			template<typename Input, typename Result>
			inline SPROUT_CONSTEXPR typename sprout::fit::result_of::algorithm<Result>::type idft(
				Input const& input,
				Result const& result
				)
			{
				return sprout::fit::idft(sprout::begin(input), sprout::end(input), result);
			}
		}	// namespace fit
	}	// namespace range
}	// namespace sprout

#endif	// #ifndef SPROUT_RANGE_NUMERIC_DFT_FIT_IDFT_HPP
