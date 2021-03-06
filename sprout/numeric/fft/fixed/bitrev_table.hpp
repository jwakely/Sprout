#ifndef SPROUT_NUMERIC_FFT_FIXED_BITREV_TABLE_HPP
#define SPROUT_NUMERIC_FFT_FIXED_BITREV_TABLE_HPP

#include <cstddef>
#include <type_traits>
#include <sprout/config.hpp>
#include <sprout/index_tuple.hpp>
#include <sprout/container/traits.hpp>
#include <sprout/container/functions.hpp>
#include <sprout/iterator/operation.hpp>
#include <sprout/algorithm/fixed/result_of.hpp>
#include <sprout/integer/bit_reverse.hpp>
#include <sprout/integer/bit_length.hpp>

namespace sprout {
		namespace fixed {
			namespace detail {
			template<typename Container, sprout::index_t... Indexes>
			inline SPROUT_CONSTEXPR typename sprout::fixed::result_of::algorithm<Container>::type bitrev_table_impl(
				Container const& cont,
				sprout::index_tuple<Indexes...>,
				std::size_t bit_length,
				typename sprout::container_traits<Container>::difference_type offset,
				typename sprout::container_traits<Container>::size_type size
				)
			{
				return sprout::remake<Container>(
					cont,
					sprout::size(cont),
					(Indexes >= offset && Indexes < offset + size
						? sprout::bit_reverse_in(
							static_cast<typename sprout::container_traits<Container>::value_type>(Indexes - offset),
							bit_length
							)
						: *sprout::next(sprout::internal_begin(cont), Indexes)
						)...
					);
			}
		}	// namespace detail
		//
		// bitrev_table
		//
		template<typename Container>
		inline SPROUT_CONSTEXPR typename sprout::fixed::result_of::algorithm<Container>::type bitrev_table(
			Container const& cont
			)
		{
			return sprout::fixed::detail::bitrev_table_impl(
				cont,
				sprout::index_range<0, sprout::container_traits<Container>::static_size>::make(),
				sprout::empty(cont)
					? 0
					: sprout::bit_length(sprout::size(cont) - 1)
					,
				sprout::internal_begin_offset(cont),
				sprout::size(cont)
				);
		}
	}	// namespace fixed

	using sprout::fixed::bitrev_table;
}	// namespace sprout

#endif	// #ifndef SPROUT_NUMERIC_FFT_FIXED_BITREV_TABLE_HPP
