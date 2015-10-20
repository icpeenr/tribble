set(Engine project_Engine)
file(GLOB SRCS_Engine ${PROJECT_SOURCE_DIR}/Engine/*.cpp)
file(GLOB HDRS_Engine ${PROJECT_SOURCE_DIR}/Engine/*.h)
add_library(${Engine} ${SRCS_Engine} ${HDRS_Engine})

target_link_libraries(${Engine} project_Framework)
