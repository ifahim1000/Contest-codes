
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>	 
using namespace __gnu_pbds;	
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// order_of_key(x) ->position bair korar jonno (lower_bound er moto onekta)
// *find_by_order(x) -> x position e k ache janar jonno
