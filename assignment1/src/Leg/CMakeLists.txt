add_subdirectory(ZeroCurve)
add_subdirectory(tests)
create_library(NAME leg DEPS utils zerocurve)
