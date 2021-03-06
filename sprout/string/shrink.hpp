#ifndef SPROUT_STRING_SHRINK_HPP
#define SPROUT_STRING_SHRINK_HPP

#include <cstddef>
#include <sprout/config.hpp>
#include <sprout/index_tuple.hpp>
#include <sprout/string/char_traits.hpp>
#include <sprout/string/string.hpp>
#include <sprout/utility/value_holder.hpp>
#include HDR_ALGORITHM_SSCRISK_CEL_OR_SPROUT

namespace sprout {
	//
	// shrink_string
	//
	template<typename T, std::size_t N, typename Traits = sprout::char_traits<T> >
	class shrink_string {
	public:
		typedef sprout::basic_string<T, N, Traits> string_type;
	private:
		typedef sprout::value_holder<string_type const&> holder_type;
	private:
		template<std::size_t M, sprout::index_t... Indexes>
		static SPROUT_CONSTEXPR sprout::basic_string<T, sizeof...(Indexes), Traits> implicit_conversion_impl(
			T const(& elems)[M],
			std::size_t len,
			sprout::index_tuple<Indexes...>
			)
		{
			return sprout::basic_string<T, sizeof...(Indexes), Traits>{{(Indexes < M - 1 ? elems[Indexes] : T())...}, len};
		}
	private:
		holder_type holder_;
	public:
		shrink_string(shrink_string const&) = default;
		shrink_string(shrink_string&&) = default;
		SPROUT_CONSTEXPR shrink_string(string_type const& s)
			: holder_(s)
		{}
		SPROUT_CONSTEXPR operator string_type const&() const {
			return holder_.get();
		}
		template<std::size_t N2>
		SPROUT_CONSTEXPR operator sprout::basic_string<T, N2, Traits>() const {
			return implicit_conversion_impl(
				holder_.get().elems,
				NS_SSCRISK_CEL_OR_SPROUT::min(N2, holder_.get().len),
				sprout::index_range<0, NS_SSCRISK_CEL_OR_SPROUT::min(N2, N)>::make()
				);
		}
	};

	//
	// shrink
	//
	template<typename T, std::size_t N, typename Traits>
	inline SPROUT_CONSTEXPR sprout::shrink_string<T, N, Traits>
	shrink(sprout::basic_string<T, N, Traits> const& s) {
		return sprout::shrink_string<T, N, Traits>(s);
	}
}	// namespace sprout

#endif	// #ifndef SPROUT_STRING_SHRINK_HPP
