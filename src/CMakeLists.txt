add_executable(main WIN32
    ${src_dir}/main.cxx
    ${src_dir}/window_manager.cxx
)
target_include_directories(main PRIVATE
    ${src_dir}/include
)