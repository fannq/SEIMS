LINK_DIRECTORIES(${PROJECT_BINARY_DIR})
SET(SRC_LIST ${MODULE_SRC} IUH_OL.cpp api.cpp)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR})
ADD_LIBRARY(IUH_OL SHARED ${SRC_LIST})
#TARGET_LINK_LIBRARIES(IUH_OL libutil.a)
TARGET_LINK_LIBRARIES(IUH_OL util module_setting)
SET_TARGET_PROPERTIES( IUH_OL PROPERTIES COMPILE_FLAGS "/openmp")
SET_PROPERTY(TARGET IUH_OL PROPERTY FOLDER "modules/hydrology_longterm")