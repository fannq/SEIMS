LINK_DIRECTORIES(${PROJECT_BINARY_DIR})
INCLUDE_DIRECTORIES(../../../base/util ../../../base/module_setting)
SET(SRC_LIST ../../../base/util/SimulationModule.cpp NitrogenFixation.cpp api.cpp)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR})
ADD_LIBRARY(NITFIX SHARED ${SRC_LIST})
#TARGET_LINK_LIBRARIES(NITFIX libutil.a)
TARGET_LINK_LIBRARIES(NITFIX util module_setting)
SET_TARGET_PROPERTIES( NITFIX PROPERTIES COMPILE_FLAGS "/openmp")
SET_PROPERTY(TARGET NITFIX PROPERTY FOLDER "modules/nutrient")