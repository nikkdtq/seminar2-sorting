#include "two_phase_merge_sort.h"

namespace external_sorting {
    template void twoPhaseMergeSort<int>(const std::string&, const std::string&, std::size_t);
    template void twoPhaseMergeSort<double>(const std::string&, const std::string&, std::size_t);
}