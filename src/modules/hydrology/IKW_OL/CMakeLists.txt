LINK_DIRECTORIES(${PROJECT_BINARY_DIR})
SET(SRC_LIST ${MODULE_SRC} ImplicitKinematicWave.cpp api.cpp)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR})
ADD_LIBRARY(IKW_OL SHARED ${SRC_LIST})
#TARGET_LINK_LIBRARIES(IKW_OL libutil.so)
TARGET_LINK_LIBRARIES(IKW_OL util module_setting)
SET_TARGET_PROPERTIES( IKW_OL PROPERTIES COMPILE_FLAGS "/openmp")
SET_PROPERTY(TARGET IKW_OL PROPERTY FOLDER "modules/hydrology")