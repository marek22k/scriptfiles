#ifdef ADD
#undef ADD
#endif

template <class A1, class A2, class R>
void ADD(A1 add1, A2 add2, R* result) {
  *result = add1+add2;
}