set(Framework project_Framework)
file(GLOB SRCS_Framework ${PROJECT_SOURCE_DIR}/Framework/*.cpp)
file(GLOB HDRS_Framework ${PROJECT_SOURCE_DIR}/Framework/*.h)

add_library(${Framework} ${SRCS_Framework} ${HDRS_Framework})