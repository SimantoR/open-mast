cmake_minimum_required(VERSION 3.0.0)

set(EMCC_FLAGS "--bind")

# Set a memory limit
set(EMCC_FLAGS "${EMCC_FLAGS} -s ENVIRONMENT=web,worker")
set(EMCC_FLAGS "${EMCC_FLAGS} -s FETCH=1")
set(EMCC_FLAGS "${EMCC_FLAGS} -s WASM=1")
set(EMCC_FLAGS "${EMCC_FLAGS} -s EXPORT_NAME='loadfits'")
set(EMCC_FLAGS "${EMCC_FLAGS} -s MODULARIZE=1")

set(EMCC_FLAGS "${EMCC_FLAGS} -s EXPORT_ES6=1")
set(EMCC_FLAGS "${EMCC_FLAGS} -s DEMANGLE_SUPPORT=1")
set(EMCC_FLAGS "${EMCC_FLAGS} -s TOTAL_MEMORY=524288000")
set(EMCC_FLAGS "${EMCC_FLAGS} -s USE_PTHREADS=0")
set(EMCC_FLAGS "${EMCC_FLAGS} -s ALLOW_BLOCKING_ON_MAIN_THREAD=0")

# set(EMCC_FLAGS "${EMCC_FLAGS} -s PROXY_TO_PTHREAD=1")
# set(EMCC_FLAGS "${EMCC_FLAGS} -s PTHREAD_POOL_SIZE=1")
set(EMCC_FLAGS "${EMCC_FLAGS} -s ASSERTIONS=1")
set(EMCC_FLAGS "${EMCC_FLAGS} -s GL_ASSERTIONS=0")
set(EMCC_FLAGS "${EMCC_FLAGS} -s SINGLE_FILE=0")
set(EMCC_FLAGS "${EMCC_FLAGS} -s GL_DEBUG=0")
set(EMCC_FLAGS "${EMCC_FLAGS} -s OFFSCREEN_FRAMEBUFFER=0")
set(EMCC_FLAGS "${EMCC_FLAGS} -s NO_DISABLE_EXCEPTION_CATCHING=0")

# Load assets as a single file for WASM
# set(EMCC_FLAGS "${EMCC_FLAGS} --preload-file ${CMAKE_SOURCE_DIR}/assets@/")
# message(STATUS "Asset path: ${CMAKE_SOURCE_DIR}/assets")

set(EMCC_FLAGS "${EMCC_FLAGS} -O3")


add_executable(fitsjs
    FitsFile.cpp
)
set_target_properties(fitsjs PROPERTIES LINK_FLAGS ${EMCC_FLAGS})
target_compile_options(fitsjs PUBLIC -fexceptions)

target_include_directories(fitsjs PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_include_directories(fitsjs PUBLIC ${PROJECT_SOURCE_DIR}/3rdparty/zlib)

# if(${EMSCRIPTEN})
#     target_compile_options(assimp PUBLIC -fexceptions)
#     target_compile_options(assimp PUBLIC -pthread)
# endif()

target_link_libraries(fitsjs CPPFits)