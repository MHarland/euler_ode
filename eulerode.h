#include <vector>

class Parameters{
public:
  Parameters()=default;
  Parameters(int nsteps, double final_arg);
  // void read_file(const std::string path);
  double n_steps;
  double final_argument;
};

class State{
public:
  State()=default;
  State(double& arg, double& val);
  State(double& arg, double& val, double& slope);
  double argument;
  double value;
  double slope;
  bool slope_set;
};

class Derivative{
public:
  virtual double evaluate(double arg_domain, double arg_codomain)=0;
};

class Solver{
public:
  Solver(State& init_state, const Parameters& parameters, Derivative& f);
  std::vector<State> graph;
  double step_size;
  Derivative* derivative;
  Parameters params;
  void solve();
};
