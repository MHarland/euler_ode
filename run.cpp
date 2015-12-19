/***********************************************
see https://en.wikipedia.org/wiki/Euler_method
where t in arg_domain and y in codomain
************************************************/

#include <iostream>
#include "eulerode.h"

class f: public Derivative{
public:
  f()=default;
  virtual double evaluate(double arg_domain, double arg_codomain){return arg_codomain;};
};

int main(){
  Parameters my_params = Parameters(100, 4);
  State y0 = State();
  f yprime = f();
  y0.value = 1;
  y0.argument = 0;
  Solver my_solver = Solver(y0, my_params, yprime);
  my_solver.solve();
  for (auto& state : my_solver.graph){
    if (state.slope_set){
      std::cout << state.argument << "  " << state.value << "  " << state.slope << std::endl;
    }
    else{
      std::cout << state.argument << "  " << state.value << std::endl;
    }
  }
}
