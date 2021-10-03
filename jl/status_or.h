#ifndef JL_STATUS_OR_H
#define JL_STATUS_OR_H

namespace jl {

template <typename T>
class StatusOr {
 public:
  StatusOr(T t): status_(Status::Ok()), t_(new T(t)) {}
  StatusOr(Status::Code code): StatusOr(Status(code)) {}
  StatusOr(Status status): status_(status), t_(nullptr) {
    assert(!status_.IsOk());
  }

  virtual ~StatusOr() {
    if (t_ != nullptr) {
      delete t_;
    }
  }

  const T& operator*() const {
    return *t_;
  }

  bool IsOk() const { return status_.IsOk(); }

  Status status() const { return status_; }

 private:
  Status status_;
  T* t_;
};

}  // namespace jl

#endif  // JL_STATUS_OR_H
