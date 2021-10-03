#ifndef JL_STATUS_H
#define JL_STATUS_H

namespace jl {

class Status {
 public:
  enum class Code { kError, kOk };

  Status(): Status(Code::kOk) {}

  Status(Code code): code_(code) {}

  Code code() const { return code_; }

  bool IsOk() const { return code_ == Code::kOk; }

  static Status Ok() { return Status(Status::Code::kOk); }

 private:
  Code code_;
};

}  // namespace jl

#endif  // JL_STATUS_H
