#ifndef SPROUT_TYPE_OPERATION_PUSH_FRONT_HPP
#define SPROUT_TYPE_OPERATION_PUSH_FRONT_HPP

#include <sprout/config.hpp>
#include <sprout/index_tuple.hpp>
#include <sprout/type/tuple.hpp>
#include <sprout/type/rebind_types.hpp>

namespace sprout {
	namespace types {
		//
		// push_front
		//
		template<typename Tuple, typename... Ts>
		struct push_front {
			static_assert(sizeof...(Ts) >= 1, "sizeof...(Ts) >= 1");
		private:
			template<typename IndexTuple>
			struct apply_impl;
			template<sprout::index_t... Indexes>
			struct apply_impl<sprout::index_tuple<Indexes...> >
				: public sprout::types::rebind_types<
					Tuple
				>::template apply<
					Ts...,
					typename sprout::types::tuple_element<Indexes, Tuple>::type...
				>
			{};
		public:
			typedef typename apply_impl<
				typename sprout::index_range<0, sprout::types::tuple_size<Tuple>::value>::type
			>::type type;
		};
	}	// namespace types
}	// namespace sprout

#endif	// #ifndef SPROUT_TYPE_OPERATION_PUSH_FRONT_HPP
