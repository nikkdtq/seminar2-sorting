#include "one_phase_merge_sort.h"

namespace external_sorting {
    template void onePhaseMergeSort<int>(const std::string&, const std::string&, std::size_t);
    template void onePhaseMergeSort<double>(const std::string&, const std::string&, std::size_t);
}