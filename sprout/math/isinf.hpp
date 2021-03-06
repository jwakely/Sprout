#ifndef SPROUT_MATH_ISINF_HPP
#define SPROUT_MATH_ISINF_HPP

#include <limits>
#include <type_traits>
#include <sprout/config.hpp>
#include <sprout/math/detail/config.hpp>
#include <sprout/type_traits/enabler_if.hpp>

namespace sprout {
	namespace math {
		namespace detail {
			template<
				typename FloatType,
				typename sprout::enabler_if<std::is_floating_point<FloatType>::value>::type = sprout::enabler
			>
			inline SPROUT_CONSTEXPR int
			isinf(FloatType x) {
				return x == std::numeric_limits<FloatType>::infinity()
					|| x == -std::numeric_limits<FloatType>::infinity()
					;
			}
		}	// namespace detail

		using NS_SPROUT_MATH_DETAIL::isinf;
	}	// namespace math

	using sprout::math::isinf;
}	// namespace sprout

#endif	// #ifndef SPROUT_MATH_ISINF_HPP
