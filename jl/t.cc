#include "status.h"
#include "status_or.h"

int main() {
  jl::Status status;
  jl::StatusOr<int> status_or(5);
  return 0;
}
