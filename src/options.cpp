
#include <RcppParallel.h>

#include <Rinternals.h>

#if RCPP_PARALLEL_USE_TBB // TBB support turned on

#include <string>
#include <exception>

extern "C" SEXP defaultNumThreads() {
   SEXP threadsSEXP = Rf_allocVector(INTSXP, 1);
   INTEGER(threadsSEXP)[0] = tbb::task_scheduler_init::default_num_threads();
   return threadsSEXP;
}

#else // TBB support not turned on

#include <tthread/tinythread.h>

extern "C" SEXP defaultNumThreads() {
   SEXP threadsSEXP = Rf_allocVector(INTSXP, 1);
   INTEGER(threadsSEXP)[0] = tthread::thread::hardware_concurrency();
   return threadsSEXP;
}

#endif
