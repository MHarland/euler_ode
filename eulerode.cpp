#include "eulerode.h"

Solver::Solver(State& init_state, const Parameters& parameters, Derivative& f)
{
  params = parameters;
  graph = std::vector<State>(params.n_steps +1);
  graph[0] = State(init_state.argument, init_state.value);
  derivative = &f;
  step_size = (parameters.final_argument - graph[0].argument)/params.n_steps;
}

void Solver::solve()
{
  double arg;
  for (int i=1; i<=params.n_steps; ++i){
    graph[i].argument = graph[i-1].argument + step_size;
    graph[i-1].slope = derivative->evaluate(graph[i-1].argument, graph[i-1].value);
    graph[i-1].slope_set = true; // use setter and getter
    graph[i].value = graph[i-1].value + step_size * graph[i-1].slope;
  }
}

State::State(double& arg, double& val)
{
  argument = arg;
  value = val;
  slope = 0;
  slope_set = false;
}

State::State(double& arg, double& val, double& slp)
{
  argument = arg;
  value = val;
  slope = slp;
  slope_set = true;
}

Parameters::Parameters(int nsteps, double final_arg)
{
  n_steps = nsteps;
  final_argument = final_arg;
}
