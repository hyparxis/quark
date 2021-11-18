# Quark

Quark is intended to be a simple differentiable rigid body dynamics library.
For the time being it is starting out as a ground-up rewrite of RBDL, with some of the following notable changes:

- Quark is a header only library
- Quark is a template library, and explicitly written to support automatic differentiation (https://github.com/autodiff/autodiff is the officially supported autodiff library)
- Quark does not use the google c++ styleguide
- Quark uses modern C++17 features
- Quark uses Bazel as its build system


## TODO
- [ ] Setup CI
- [ ] Write the rest of the library
