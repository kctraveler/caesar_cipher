if(EXISTS "/home/runner/Caesar-Cipher-1-comp-339-439-ds-1/decoder-test[1]_tests.cmake")
  include("/home/runner/Caesar-Cipher-1-comp-339-439-ds-1/decoder-test[1]_tests.cmake")
else()
  add_test(decoder-test_NOT_BUILT decoder-test_NOT_BUILT)
endif()