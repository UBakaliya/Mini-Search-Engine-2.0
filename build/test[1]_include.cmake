if(EXISTS "/Users/uvaishbakaliya/Documents/Code Base/Mini-Search-Engine/build/test[1]_tests.cmake")
  include("/Users/uvaishbakaliya/Documents/Code Base/Mini-Search-Engine/build/test[1]_tests.cmake")
else()
  add_test(test_NOT_BUILT test_NOT_BUILT)
endif()
