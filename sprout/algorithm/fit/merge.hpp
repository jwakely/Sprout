#ifndef SPROUT_ALGORITHM_FIT_MERGE_HPP
#define SPROUT_ALGORITHM_FIT_MERGE_HPP

#include <sprout/config.hpp>
#include <sprout/container/traits.hpp>
#include <sprout/container/functions.hpp>
#include <sprout/algorithm/fixed/merge.hpp>
#include <sprout/algorithm/fit/result_of.hpp>
#include <sprout/sub_array.hpp>
#include HDR_ALGORITHM_SSCRISK_CEL_OR_SPROUT
#include HDR_ITERATOR_SSCRISK_CEL_OR_SPROUT

namespace sprout {
	namespace fit {
		namespace detail {
			template<typename InputIterator1, typename InputIterator2, typename Result, typename Compare>
			inline SPROUT_CONSTEXPR typename sprout::fit::result_of::algorithm<Result>::type merge_impl(
				InputIterator1 first1,
				InputIterator1 last1,
				InputIterator2 first2,
				InputIterator2 last2,
				Result const& result,
				Compare comp,
				typename sprout::container_traits<Result>::difference_type offset
				)
			{
				return sprout::sub_copy(
					sprout::get_internal(sprout::fixed::merge(first1, last1, first2, last2, result, comp)),
					offset,
					offset + NS_SSCRISK_CEL_OR_SPROUT::min(
						NS_SSCRISK_CEL_OR_SPROUT::distance(first1, last1) + NS_SSCRISK_CEL_OR_SPROUT::distance(first2, last2),
						sprout::size(result)
						)
					);
			}
		}	// namespace detail
		//
		// merge
		//
		template<typename InputIterator1, typename InputIterator2, typename Result, typename Compare>
		inline SPROUT_CONSTEXPR typename sprout::fit::result_of::algorithm<Result>::type merge(
			InputIterator1 first1,
			InputIterator1 last1,
			InputIterator2 first2,
			InputIterator2 last2,
			Result const& result,
			Compare comp
			)
		{
			return sprout::fit::detail::merge_impl(first1, last1, first2, last2, result, comp, sprout::internal_begin_offset(result));
		}

		namespace detail {
			template<typename InputIterator1, typename InputIterator2, typename Result>
			inline SPROUT_CONSTEXPR typename sprout::fit::result_of::algorithm<Result>::type merge_impl(
				InputIterator1 first1,
				InputIterator1 last1,
				InputIterator2 first2,
				InputIterator2 last2,
				Result const& result,
				typename sprout::container_traits<Result>::difference_type offset
				)
			{
				return sprout::sub_copy(
					sprout::get_internal(sprout::fixed::merge(first1, last1, first2, last2, result)),
					offset,
					offset + NS_SSCRISK_CEL_OR_SPROUT::min(
						NS_SSCRISK_CEL_OR_SPROUT::distance(first1, last1) + NS_SSCRISK_CEL_OR_SPROUT::distance(first2, last2),
						sprout::size(result)
						)
					);
			}
		}	// namespace detail
		//
		// merge
		//
		template<typename InputIterator1, typename InputIterator2, typename Result>
		inline SPROUT_CONSTEXPR typename sprout::fit::result_of::algorithm<Result>::type merge(
			InputIterator1 first1,
			InputIterator1 last1,
			InputIterator2 first2,
			InputIterator2 last2,
			Result const& result
			)
		{
			return sprout::fit::detail::merge_impl(first1, last1, first2, last2, result, sprout::internal_begin_offset(result));
		}
	}	// namespace fit
}	// namespace sprout

#endif	// #ifndef SPROUT_ALGORITHM_FIT_MERGE_HPP
